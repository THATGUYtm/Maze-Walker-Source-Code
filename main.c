#include "raylib.h"
#include "resources/Scripts/Levels.c"
#define DeadZone 0.3f
#define FrameRate 60

Music GameMusic;
Music MenuMusic;
Music EndingMusic;
Sound KeySoundEffect;
Sound LockSoundEffect;
Sound BoxPushSoundEffect;
Sound SpikeSoundEffect;
Sound EnimeSoundEffect;
Sound LevelFinnishSoundEffect;
Sound MenuChange;
Sound MenuSelect;

Camera2D camera = { 0 };
Rectangle PlayerTilePos = (Rectangle){1680.0f, 80.0f, 40.0f, 40.0f};

unsigned int TotalDeaths;
unsigned int TotalPlays;
unsigned int TotalFinnished;
unsigned int LeastDeathsInPlayThough; 
unsigned int MostDeathsInPlayThough;
unsigned int CurrentLevel = 1;
unsigned int NumberOFLevels = 32;
unsigned int Deaths = 0;
unsigned int ButtonsPressed = 0;
unsigned int KeysNeeded = 1;
unsigned int KeysInHand = 0;
unsigned int DoorLocation = 0;
int i;

unsigned int Fence[10];
unsigned int Lock[10];
unsigned int Enimes[120];
unsigned int WorstTime[4];
unsigned int TotalPlayTime[4];

unsigned int Spikes[] = {0};
unsigned int Timer[] = {0, 0, 0, 0};
unsigned int BestTime[] = {0, 0, 0, 0};
unsigned int Rock[] = {0, 0, 0};
unsigned int PlayerSpawn[] = {1, 1};
unsigned int Player[] = {80, 40, 3, 0, 0, 0};

bool HasEnimes = false;
bool OnTeleport = false;
bool HasSpikes = false;
bool StartGame = false;
bool MusicOn = true;
bool SoundEffectsOn = true;
bool Resume = false;
bool MenuControllerMode = false;
bool HardMode = false;
bool HardModeBeaten;
bool FPSON = false;

#include "resources/Scripts/BGBKG.c"

void ExitGame();
void SaveSave();
void LoadSave();
void PostionCheck();
void OptionMenu();
void MainMenu();
void PauseMenu();
void TransistionScreen();
void Input();
void Update();
void Draw();
void ChangeOverLevels();
void SwitchLevel();
void BeginGame();
void Game();
void UpdateCameraCenter();
void ResumeFunct(){Resume = true;}

void DrawMainMenu(){
    for(int i = 0; i < 800; i += 40){
        for(int j = 0; j < 720; j += 40){
            switch(MainMenuMap[((j/40)*20)+(i/40)]){
                case 0x30:DrawTextureRec(TileSet, (Rectangle){440.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x26:DrawTextureRec(TileSet, (Rectangle){40.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x2F:DrawTextureRec(TileSet, (Rectangle){400.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x28:DrawTextureRec(TileSet, (Rectangle){120.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x25:DrawTextureRec(TileSet, (Rectangle){440.0f,200.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x24:DrawTextureRec(TileSet, (Rectangle){440.0f,80.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x31:DrawTextureRec(TileSet, (Rectangle){0.0f,160.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x27:DrawTextureRec(TileSet, (Rectangle){80.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
                case 0x32:DrawTextureRec(TileSet, (Rectangle){40.0f,160.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);break;
            }
        }
    }
}

void DrawButton(char* Text, int X, int Y, int Width, int Height, void Function(), Color color, Color TextColor, Color SelectionColor){
    if((GetMouseX() > X + GameScreenStart[0]) && (GetMouseX() < X+Width + GameScreenStart[0]) && (GetMouseY() > Y) && (GetMouseY() < Y+Height)){
        DrawRectangle(X-5 + GameScreenStart[0], Y-5, Width+10, Height+10, GRAY);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){Function();}
    }DrawRectangle(X + GameScreenStart[0], Y, Width, Height, color); 
    DrawText(FormatText(Text), X+10 + GameScreenStart[0], Y+5, Height-5, TextColor);
}

#include "resources/Scripts/MainMenu.c"

void IntMusicAndSoundEffects(){
    InitAudioDevice(); 
	SetMasterVolume(0.1f);
	GameMusic = LoadMusicStream("resources/Music/LevelTheme.mp3");
    MenuMusic = LoadMusicStream("resources/Music/MenuMusic.mp3");
    EndingMusic = LoadMusicStream("resources/Music/EndingMusic.mp3");
	PlayMusicStream(MenuMusic);
    KeySoundEffect = LoadSound("resources/SoundEffects/KeySoundEffect.wav");
    LockSoundEffect = LoadSound("resources/SoundEffects/LockSoundEffect.wav");
    BoxPushSoundEffect = LoadSound("resources/SoundEffects/BoxPushSoundEffect.wav");
    SpikeSoundEffect = LoadSound("resources/SoundEffects/SpikeSoundEffect.wav");
    EnimeSoundEffect = LoadSound("resources/SoundEffects/EnimeMovingSoundEffect.wav"); 
    LevelFinnishSoundEffect = LoadSound("resources/SoundEffects/LevelFinnishSoundEffect.wav"); 
    MenuSelect = LoadSound("resources/SoundEffects/MenuSelectSoundEffect.wav"); 
    MenuChange = LoadSound("resources/SoundEffects/MenuChangeSoundEffect.wav"); 
}

void IntWindow(){
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 720, "Maze Walker");
    SetWindowMinSize(800, 720);
    Image Icon = LoadImage("resources/Graphics/Player/Tile06.png");
    SetWindowIcon(Icon);
    SetTargetFPS(FrameRate);
    SetExitKey(KEY_DELETE);
}

void UpdateCameraCenter(){
    GameScreenStart[0] = (((GetScreenWidth())/2)-400);
    camera.zoom = ((float)GetScreenHeight()/720);
}

void LoadSave(){
    CurrentLevel = LoadStorageValue(0);
    Timer[0] = LoadStorageValue(1);
    Timer[1] = LoadStorageValue(2);
    Timer[2] = LoadStorageValue(3);
    Timer[3] = LoadStorageValue(4);
    Deaths = LoadStorageValue(5);
    BestTime[0] = LoadStorageValue(6);
    BestTime[1] = LoadStorageValue(7);
    BestTime[2] = LoadStorageValue(8);
    BestTime[3] = LoadStorageValue(9);
    if(CurrentLevel == 0){CurrentLevel = 1;}
    TotalPlayTime[0] = LoadStorageValue(10);
    TotalPlayTime[1] = LoadStorageValue(11);
    TotalPlayTime[2] = LoadStorageValue(12);
    TotalPlayTime[3] = LoadStorageValue(13);
    TotalDeaths = LoadStorageValue(14);
    TotalPlays = LoadStorageValue(15);
    WorstTime[0] = LoadStorageValue(16);
    WorstTime[1] = LoadStorageValue(17);
    WorstTime[2] = LoadStorageValue(18);
    WorstTime[3] = LoadStorageValue(19);
    LeastDeathsInPlayThough = LoadStorageValue(20);
    MostDeathsInPlayThough = LoadStorageValue(21);
    HardModeBeaten = LoadStorageValue(22);
    TotalFinnished = LoadStorageValue(23);
}

void SaveSave(){
    SaveStorageValue(0, CurrentLevel);
    SaveStorageValue(1, Timer[0]);
    SaveStorageValue(2, Timer[1]);
    SaveStorageValue(3, Timer[2]);
    SaveStorageValue(4, Timer[3]);
    SaveStorageValue(5, Deaths);
    SaveStorageValue(6, BestTime[0]);
    SaveStorageValue(7, BestTime[1]);
    SaveStorageValue(8, BestTime[2]);
    SaveStorageValue(9, BestTime[3]);
    SaveStorageValue(10, TotalPlayTime[0]);
    SaveStorageValue(11, TotalPlayTime[1]);
    SaveStorageValue(12, TotalPlayTime[2]);
    SaveStorageValue(13, TotalPlayTime[3]);
    SaveStorageValue(14, TotalDeaths);
    SaveStorageValue(15, TotalPlays);
    SaveStorageValue(16, WorstTime[0]);
    SaveStorageValue(17, WorstTime[1]);
    SaveStorageValue(18, WorstTime[2]);
    SaveStorageValue(19, WorstTime[3]);
    SaveStorageValue(20, LeastDeathsInPlayThough);
    SaveStorageValue(21, MostDeathsInPlayThough);
    SaveStorageValue(22, HardModeBeaten);
    SaveStorageValue(23, TotalFinnished);
}

void GameCompleted(){
    int CalcTime[]={(Timer[1]+(Timer[2]*60)+(Timer[3]*360)),(BestTime[1]+(BestTime[2]*60)+(BestTime[3]*360)), (WorstTime[1]+(WorstTime[2]*60)+(WorstTime[3]*360))};
    if(CalcTime[1] != 0){
        if(CalcTime[0]<CalcTime[1]){
            BestTime[0] = Timer[0];
            BestTime[1] = Timer[1];
            BestTime[2] = Timer[2];
            BestTime[3] = Timer[3];
        }
        if(CalcTime[0] > CalcTime[2]){
            WorstTime[0] = Timer[0];
            WorstTime[1] = Timer[1];
            WorstTime[2] = Timer[2];
            WorstTime[3] = Timer[3];
        }
    }else{
        BestTime[0] = Timer[0];
        BestTime[1] = Timer[1];
        BestTime[2] = Timer[2];
        BestTime[3] = Timer[3];
        WorstTime[0] = Timer[0];
        WorstTime[1] = Timer[1];
        WorstTime[2] = Timer[2];
        WorstTime[3] = Timer[3];
    }
    if(Deaths < LeastDeathsInPlayThough && LeastDeathsInPlayThough != 0){LeastDeathsInPlayThough = Deaths;}else{LeastDeathsInPlayThough = Deaths;}
    if(Deaths > MostDeathsInPlayThough && MostDeathsInPlayThough != 0){MostDeathsInPlayThough = Deaths;}else{MostDeathsInPlayThough = Deaths;}
}

void ExitGame(){
    SaveSave();
    UnloadTextures();
}

int main(void){
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = (float)GetScreenHeight()/720;
    IntWindow();
    intTextures();
    IntMusicAndSoundEffects();
    LoadSave();
    BeginGame();
    return 0;
}

void MainMenuSection(){
    CurserPos = 0;
    StartGame = false;
    while(StartGame == false){
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        UpdateCameraCenter();
        if(WindowShouldClose()){
            ExitGame();
        }
        BeginDrawing();
            MainMenu();
        EndDrawing();
    } 
}

void BeginGame(){
    SaveSave();
    BeginDrawing();
        ClearBackground(BLACK);
    EndDrawing();
    float fade = 1.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){ExitGame();}
        UpdateCameraCenter();
        if(MusicOn == true){UpdateMusicStream(MenuMusic);}
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                MainMenu();
                DrawRectangle(0,0,800 + GameScreenStart[0],760 + GameScreenStart[1],Fade(BLACK, fade));
            EndMode2D();
        EndDrawing();
        fade -= 0.05f;
    }
    MainMenuSection();
    Game();
}

void Game(){
    TotalPlays++;
    if(!WindowShouldClose()){
        if(WindowShouldClose()){ExitGame();}
        if(SoundEffectsOn==true){PlaySound(LevelFinnishSoundEffect);}
        if(MusicOn == true){UpdateMusicStream(MenuMusic);}
        SwitchLevel();
        PlayMusicStream(GameMusic);
    }
    while(!WindowShouldClose()){
		UpdateCameraCenter();
		if(IsWindowHidden() || IsWindowMinimized()){
            PauseMenu();
        }
        if(MusicOn == true){
            UpdateMusicStream(GameMusic);
        } 
        Input();
        if((Player[0]%40)!=0){
            Player[0] /= 40;
            Player[0] *= 40;
        }
        if((Player[1]%40)!=0){
            Player[1] /= 40;
            Player[1] *= 40;
        }
        Update();
        PostionCheck();
        Draw();
    }
    ExitGame();
}

bool CanWalk(int Dir){
    switch(Dir){
        case 0:
            switch(Map[(((Player[1]/40)-1)*20)+(Player[0]/40)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:return true;break;
                default:return false;break;
            }break;
        case 1:
            switch(Map[(((Player[1]/40)+1)*20)+(Player[0]/40)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:return true;break;
                default:return false;break;
            }break;
        case 2:
            switch(Map[(((Player[1]/40))*20)+((Player[0]/40)-1)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:return true;break;
                default:return false;break;
                }break;
        case 3:
            switch(Map[((Player[1]/40)*20)+((Player[0]/40)+1)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:return true;break;
                default:return false;break;
            }break;
        default:return false;break;
    }return false;
}

void PlayerUpdate(){
    UpdateCameraCenter();
    if(IsWindowHidden() || IsWindowMinimized()){PauseMenu();}
    if(MusicOn == true){UpdateMusicStream(GameMusic);} 
    Update();
    Draw();
}

void Input(){
    ButtonsPressed = 0;
    if((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) < -DeadZone) && (!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_D))){
        if(Map[((Player[1]/40)*20)+((Player[0]/40)-1)] != 0x05){
            if(CanWalk(2) == true){
                ButtonsPressed++;
                Player[2] = 0;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){Player[0]-=4;PlayerUpdate();}
                }else{for(i = 0; i < 4; i++){Player[0]-=10;PlayerUpdate();}}
            }
        }else{
            if(Map[((Player[1]/40)*20)+((Player[0]/40)-2)] == 0x00){
                ButtonsPressed++;
                Player[2] = 0;
                Map[(((Player[1]/40))*20)+(Player[0]/40)-1] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0]-40;
                Rock[2] = Player[1];
                if(SoundEffectsOn==true){PlaySound(BoxPushSoundEffect);}
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 20; i++){Rock[1]-=2;Player[0]-=2;PlayerUpdate();}
                }else{for(i = 0; i < 8; i++){PlayerUpdate();Player[0]-=5;Rock[1]-=5;}}
                Map[(((Player[1]/40))*20)+(Player[0]/40)-1] = 0x05;
                Rock[0] = 0;
            }
        }PostionCheck();
    }
    if((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 2) < -DeadZone) && (!IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_S))){
        if(Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] != 0x05){
            if(CanWalk(0) == true){
                ButtonsPressed++;
                Player[2] = 1;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){Player[1]-=4;PlayerUpdate();}
                }else{for(i = 0; i < 4; i++){Player[1]-=10;PlayerUpdate();}}
            } 
        }else{
            if(Map[(((Player[1]/40)-2)*20)+(Player[0]/40)] == 0x00){
                ButtonsPressed++;
                Player[2] = 1;
                Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0];
                Rock[2] = Player[1]-40;
                if(SoundEffectsOn==true){PlaySound(BoxPushSoundEffect);}
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 20; i++){Rock[2]-=2;Player[1]-=2;PlayerUpdate();}
                }else{for(i = 0; i < 8; i++){Rock[2]-=5;Player[1]-=5;PlayerUpdate();}}
                Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] = 0x05;
                Rock[0] = 0;
            }
        }PostionCheck();
    }
    if((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) > DeadZone) && (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_A))){
        if(Map[((Player[1]/40)*20)+((Player[0]/40)+1)] != 0x05){
            if(CanWalk(3) == true){
                ButtonsPressed++;
                Player[2] = 3;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){Player[0]+=4;PlayerUpdate();}
                }else{for(i = 0; i < 4; i++){Player[0]+=10;PlayerUpdate();}}
            }
        }else if(Map[((Player[1]/40)*20)+((Player[0]/40)+2)] == 0x00){
            ButtonsPressed++;
            Player[2] = 2;
            Map[(((Player[1]/40))*20)+(Player[0]/40)+1] = 0x00;
            Rock[0] = 1;
            Rock[1] = Player[0]+40;
            Rock[2] = Player[1];
            if(SoundEffectsOn==true){PlaySound(BoxPushSoundEffect);}
            if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                for(i = 0; i < 20; i++){ Rock[1]+=2;Player[0]+=2;PlayerUpdate();}
            }else{for(i = 0; i < 8; i++){Rock[1]+=5;Player[0]+=5;PlayerUpdate();}}
            Map[(((Player[1]/40))*20)+(Player[0]/40)+1] = 0x05;
            Rock[0] = 0;
        }PostionCheck();        
    }
    if((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 2) > DeadZone) && (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_W))){
        if(Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] != 0x05){
            if(CanWalk(1) == true){
                ButtonsPressed++;
                Player[2] = 3;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){Player[1] += 4;PlayerUpdate();}}
                    else{for(i = 0; i < 4; i++){Player[1] += 10;PlayerUpdate();}}
            } 
        }else if(Map[(((Player[1]/40)+2)*20)+(Player[0]/40)] == 0x00){
            ButtonsPressed++;
                Player[2] = 3;
                Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0];
                Rock[2] = Player[1]+40;
                if(SoundEffectsOn==true){PlaySound(BoxPushSoundEffect);}
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){ 
                    for(i = 0; i < 20; i++){Rock[2] += 2;Player[1] += 2;PlayerUpdate();}
                    }else{for(i = 0; i < 8; i++){Rock[2] += 5;Player[1] += 5;PlayerUpdate();}}
                Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] = 0x05;
                Rock[0] = 0;
        }PostionCheck();
    }
    PostionCheck();
    if(ButtonsPressed == 0){Player[5] = 0;}
    if(IsKeyPressed(KEY_ENTER) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_LEFT)){
        if(HardMode == true){
            CurrentLevel = 0;
            Deaths = 0;
            Timer[0] = 0;
            Timer[1] = 0;
            Timer[2] = 0;
            Timer[3] = 0;
            TotalDeaths++;
            BeginGame();
        }else{
            Deaths++;
            TotalDeaths++;
            SwitchLevel(); 
        }        
    }
    if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT)){PauseMenu();}
    if(IsKeyPressed(KEY_F)){FPSON=!FPSON;}
}

void PostionCheck(){
    switch(Map[((Player[1]/40)*20)+(Player[0]/40)]){
        case 0x01:
            if(SoundEffectsOn==true){PlaySound(LevelFinnishSoundEffect);}
            Draw();
            CurrentLevel++;
            SwitchLevel();
            break;
        case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:
            if(HardMode == true){
                for(i = 0; i < 5; i++){
                    Draw();
                }
                CurrentLevel = 0;
                Deaths = 0;
                TotalDeaths++;
                Timer[0] = 0;
                Timer[1] = 0;
                Timer[2] = 0;
                Timer[3] = 0;
                BeginGame();
            }else{
                Deaths++;
                TotalDeaths++;
                for(i = 0; i < 5; i++){Draw();}
                SwitchLevel();
            }
            break;
        case 0x04:
            if(SoundEffectsOn==true){PlaySound(KeySoundEffect);}
            KeysInHand++;
            Map[((Player[1]/40)*20)+(Player[0]/40)] = 0x00;
            if(KeysInHand == KeysNeeded){
                for(i = 0; i < 360; i++){
                    if(Map[i] == 0x03){
                        Map[i] = 0x01;
                        break;
                    }
                }
            }
            break;
        case 0x13:
            if(SoundEffectsOn==true){PlaySound(LockSoundEffect);}
            if(Fence[0] != 0){
                if(Fence[0] == 1){
                    Map[((Player[1]/40)*20)+(Player[0]/40)] = 0x00;
                    for(i = 0; i < 360; i++){
                        if(Map[i] == 0x12 || Map[i] == 0x14){
                            Map[i] = 0x00;
                            break;
                        }
                    }
                }else{
                    for(i = 0; i < Fence[0]; i++){
                        if(((Player[1]/40)*20)+(Player[0]/40) == Lock[i]){
                            Map[Lock[i]] = 0x00;
                            Map[Fence[i+1]] = 0x00;
                        }
                    }
                }
            }
            break;
        case 0x46:
            if(OnTeleport == false){
                OnTeleport = true;
                if(SoundEffectsOn==true){PlaySound(KeySoundEffect);}
                for(i = 0; i < 360; i++){
                    if(i != ((Player[1]/40)*20)+(Player[0]/40)){
                        if(Map[i] == 0x46){
                            Player[0] = (i%20)*40;
                            Player[1] = (i/20)*40;
                            Draw();
                            break;
                        }
                    }
                }
            }
            break;
        default:OnTeleport = false;break;
    }
}

void Update(){
    //DevFeature
    if(IsFileDropped()){
        int count = 0;
        char **droppedFiles = GetDroppedFiles(&count);
        if(count == 1){
            if (IsFileExtension(droppedFiles[0], ".png")){
                UnloadTexture(TileSet);
                TileSet = LoadTexture(droppedFiles[0]);
            }
        }ClearDroppedFiles();
    }
    if(HasEnimes == true){
        Enimes[0]++;
        if(Enimes[0] >= 45 && Rock[0] != 1){
            if(SoundEffectsOn==true){PlaySound(EnimeSoundEffect);}
            Enimes[0] = 0;
            for(int i = 2; i < Enimes[1] + 2; i++){
                switch(Map[Enimes[i]]){
                    case 0x17:					
                        if(Map[Enimes[i]-1] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]-1] = 0x17;
                            Enimes[i] -= 1;
                        }
                        else{
                            Map[Enimes[i]] = 0x19;
                        }
                        break;
                    case 0x18:
                        if(Map[Enimes[i]-20] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]-20] = 0x18;
                            Enimes[i] -= 20;
                        }
                        else{
                            Map[Enimes[i]] = 0x1A;
                        }
                        break;
                    case 0x19:
                        if(Map[Enimes[i]+1] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]+1] = 0x19;
                            Enimes[i] += 1;
                        }
                        else{
                            Map[Enimes[i]] = 0x17;
                        }
                        break;
                    case 0x1A:
                        if(Map[Enimes[i]+20] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]+20] = 0x1A;
                            Enimes[i] += 20;
                        }
                        else{
                            Map[Enimes[i]] = 0x18;
                        }
                        break;
                }
            }
        }
    }
    if(HasSpikes == true){
        if(Spikes[0] == 160){
            if(SoundEffectsOn==true){PlaySound(SpikeSoundEffect);}
            Spikes[0] = 0;
            for(int i = 0; i < 360; i++){
                switch(Map[i]){
                    case 0x15:
                        Map[i] = 0x16;
                        break;
                    case 0x16:
                        Map[i] = 0x15;
                        break;
                }
            }
        }
        Spikes[0]++;
    }
    if(Player[5] == 1){
        Player[4]++;
        if(Player[2] == 0){
           if(Player[4] == 30){Player[4] = 0;PlayerTilePos = (Rectangle){440.0f, 40.0f, 40.0f, 40.0f};}
           else if(Player[4] <= 15){PlayerTilePos = (Rectangle){0.0f, 80.0f, 40.0f, 40.0f};}
           else{PlayerTilePos = (Rectangle){440.0f, 40.0f, 40.0f, 40.0f};} 
        }else if(Player[2] == 1){
           if(Player[4] == 30){Player[4] = 0;PlayerTilePos = (Rectangle){200.0f, 40.0f, 40.0f, 40.0f};}
            else if(Player[4] <= 15){PlayerTilePos = (Rectangle){240.0f, 40.0f, 40.0f, 40.0f};}
            else{PlayerTilePos = (Rectangle){200.0f, 40.0f, 40.0f, 40.0f};}
        }else if(Player[2] == 2){
            if(Player[4] == 30){Player[4] = 0;PlayerTilePos = (Rectangle){80.0f, 40.0f, 40.0f, 40.0f};}
            else if(Player[4] <= 15){PlayerTilePos = (Rectangle){120.0f, 40.0f, 40.0f, 40.0f};}
            else{PlayerTilePos = (Rectangle){80.0f, 40.0f, 40.0f, 40.0f};}
        }else if(Player[2] == 3){
            if(Player[4] == 30){Player[4] = 0;PlayerTilePos = (Rectangle){320.0f, 40.0f, 40.0f, 40.0f};}
            else if(Player[4] <= 15){PlayerTilePos = (Rectangle){360.0f, 40.0f, 40.0f, 40.0f};}
            else{PlayerTilePos = (Rectangle){320.0f, 40.0f, 40.0f, 40.0f};}
        }
    }else{
        switch(Player[2]){
            case 0:PlayerTilePos = (Rectangle){400.0f, 40.0f, 40.0f, 40.0f};break;
            case 1:PlayerTilePos = (Rectangle){160.0f, 40.0f, 40.0f, 40.0f};break;
            case 2:PlayerTilePos = (Rectangle){40.0f, 40.0f, 40.0f, 40.0f};break;
            case 3:PlayerTilePos = (Rectangle){280.0f, 40.0f, 40.0f, 40.0f};break;
        }
    }
}

void Draw(){
    UpdateCameraCenter();
    BeginDrawing();
        BeginMode2D(camera);
            Timer[0] += 1;
            if(Timer[0] > 59){Timer[1]++;Timer[0] = 0;}
            if(Timer[1] > 59){Timer[2]++;Timer[1] = 0;}
            if(Timer[2] > 59){Timer[3]++;Timer[2] = 0;}
            TotalPlayTime[0]++;
            if(TotalPlayTime[0] > 59){TotalPlayTime[1]++;TotalPlayTime[0] = 0;}
            if(TotalPlayTime[1] > 59){TotalPlayTime[2]++;TotalPlayTime[1] = 0;}
            if(TotalPlayTime[2] > 59){TotalPlayTime[3]++;TotalPlayTime[2] = 0;}
            DrawBKG();
            DrawTextureRec(TileSet, PlayerTilePos, (Vector2){Player[0] + GameScreenStart[0], Player[1]}, WHITE);
            if(Rock[0]==1){DrawTextureRec(TileSet,(Rectangle){160.0f,0.0f,40.0f,40.0f},(Vector2){Rock[1]+GameScreenStart[0],Rock[2]},WHITE);}
        EndMode2D();
        if(FPSON == true){DrawFPS(10,10);}
    EndDrawing();
}

void ChangeOverLevels(const unsigned char Level[]){
    if(WindowShouldClose()){ExitGame();}
    for(i = 0; i < 360; i++){
        Map[i] = Level[i];
    }
    KeysInHand = 0;
    Player[2] = 3;
    Player[3] = 0;
    Player[4] = 0;
    Player[5] = 0;
    KeysNeeded = 1;
    Fence[0] = 0;
    HasSpikes = false;
    HasEnimes = false;
    Spikes[0] = 0;
    Enimes[0] = 0;
    Player[0] = 40;
    Player[1] = 40;
    Update();
}

void EndTransistionScreen(){
    float fade = 1.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){UnloadTextures();ExitGame();}
        if(MusicOn == true){UpdateMusicStream(GameMusic);} ;
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawBKG();
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){Player[0] + GameScreenStart[0], Player[1]}, WHITE);
			EndMode2D();
                DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
			BeginMode2D(camera);
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340 + GameScreenStart[0], 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400 + GameScreenStart[0], 340 + GameScreenStart[1], 50, Fade(WHITE, fade));
            EndMode2D();
        EndDrawing();
        fade -= 0.05f;
    }
}

void TransistionScreen(){
    float fade = 0.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(GameMusic);
        } 
        BeginDrawing();
			DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginMode2D(camera);  
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340 + GameScreenStart[0], 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400 + GameScreenStart[0], 340 + GameScreenStart[1], 50, Fade(WHITE, fade));
            EndMode2D();
        EndDrawing();
        fade += 0.05f;
    }
    for(i = 0; i < 80; i++){
        if(WindowShouldClose()){ExitGame();}
        if(MusicOn == true){UpdateMusicStream(GameMusic);} ; 
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340 + GameScreenStart[0], 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400 + GameScreenStart[0], 340 + GameScreenStart[1], 50, WHITE);
            EndMode2D();
        EndDrawing();
    }
}

void PauseMenuContent(){
    if(WindowShouldClose()){ExitGame();}
    if(IsWindowResized()){
        camera.zoom = (float)GetScreenHeight()/720;
        GameScreenStart[0] = (GetScreenWidth()-800)/2;
    }
    if(MusicOn == true){UpdateMusicStream(GameMusic);} ; 
    BeginDrawing();
        BeginMode2D(camera);
            ClearBackground(BLACK);
            DrawText("PAUSE", 150 + GameScreenStart[0], 100 + GameScreenStart[1], 150, WHITE);
            DrawButton("Resume", 230, 380, 300, 50, ResumeFunct, WHITE, BLACK, GREEN);
            DrawButton("MainMenu", 230, 440, 300, 50, BeginGame, WHITE, BLACK, GREEN);
            DrawButton("Exit", 230, 500, 300, 50, ExitGame, WHITE, BLACK, GREEN);
        EndMode2D();
    EndDrawing();
}

void PauseMenu(){
    float fade = 0.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){UnloadTextures();ExitGame();}
        if(MusicOn == true){UpdateMusicStream(GameMusic);} ;
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawBKG();
                DrawTextureRec(TileSet, (Rectangle){1680.0f, 80.0f, 40.0f, 40.0f}, (Vector2){Player[0] + GameScreenStart[0], Player[1]}, WHITE);
            EndMode2D();
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginMode2D(camera);
                DrawText("PAUSE", 150 + GameScreenStart[0], 100 + GameScreenStart[1], 150, Fade(WHITE, fade));
                DrawButton("Resume", 230, 380, 300, 50, ResumeFunct, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
                DrawButton("MainMenu", 230, 440, 300, 50, BeginGame, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
                DrawButton("Exit", 230, 500, 300, 50, ExitGame, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
            EndMode2D();
        EndDrawing();
        fade += 0.05f;
    }
    Resume = false;
    PauseMusicStream(GameMusic);
    while(IsKeyDown(KEY_ESCAPE)){PauseMenuContent();}
    while(Resume == false){
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT)){break;}
        if(WindowShouldClose()){ExitGame();}
        if(IsWindowResized()){
            camera.zoom = (float)GetScreenHeight()/720;
            GameScreenStart[0] = (GetScreenWidth()-800)/2;
        }
        if(MusicOn == true){UpdateMusicStream(GameMusic);} ; 
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawText("PAUSE", 150 + GameScreenStart[0], 100 + GameScreenStart[1], 150, WHITE);
                DrawButton("Resume", 230, 380, 300, 50, ResumeFunct, WHITE, BLACK, GREEN);
                DrawButton("MainMenu", 230, 440, 300, 50, BeginGame, WHITE, BLACK, GREEN);
                DrawButton("Exit", 230, 500, 300, 50, ExitGame, WHITE, BLACK, GREEN);
            EndMode2D();
        EndDrawing();
        }
    ResumeMusicStream(GameMusic);
    fade = 1.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){ExitGame();}
        if(MusicOn == true){UpdateMusicStream(GameMusic);} ; 
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawBKG();
                DrawTextureRec(TileSet, (Rectangle){1680.0f, 80.0f, 40.0f, 40.0f}, (Vector2){Player[0] + GameScreenStart[0], Player[1]}, WHITE);
            EndMode2D();
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginMode2D(camera);
                DrawText("PAUSE", 150 + GameScreenStart[0], 100 + GameScreenStart[1], 150, Fade(WHITE, fade));
                DrawButton("Resume", 230, 380, 300, 50, ResumeFunct, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
                DrawButton("MainMenu", 230, 440, 300, 50, BeginGame, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
                DrawButton("Exit", 230, 500, 300, 50, ExitGame, Fade(WHITE, fade),Fade(BLACK, fade),Fade(GREEN, fade));
            EndMode2D();
        EndDrawing();
        fade -= 0.05f;
    }
}

void EndScreen(){
    GameCompleted();
    PauseMusicStream(GameMusic);
    PlayMusicStream(EndingMusic);
    if(HardMode == true){HardModeBeaten = true;}
    CurrentLevel = 0;
    TotalFinnished++;
    while(!WindowShouldClose() && !IsKeyDown(KEY_ESCAPE) && !IsKeyDown(KEY_ENTER) && !IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT)){
        if(WindowShouldClose()){ExitGame();}
        UpdateCameraCenter();
        if(MusicOn == true){UpdateMusicStream(EndingMusic);} ;
        BeginDrawing();
            ClearBackground(BLACK);
            DrawMainMenu();
            DrawText("You", 50 + GameScreenStart[0], 50 + GameScreenStart[1], 180, BLACK);
            DrawText("Excaped!", 50 + GameScreenStart[0], 200 + GameScreenStart[1], 150, BLACK);
            DrawText(FormatText("Time %02ih:%02im:%02is",Timer[3], Timer[2], Timer[1]), 50 + GameScreenStart[0], 390 + GameScreenStart[1], 50, WHITE);
            DrawText(FormatText("Deaths %02i", Deaths), 50 + GameScreenStart[0], 440 + GameScreenStart[1], 50, WHITE);
            if((BestTime[1]+(BestTime[2]*60)+(BestTime[3]*360)) > 0){DrawText(FormatText("Best Time %02ih:%02im:%02is",BestTime[3], BestTime[2], BestTime[1]), 50 + GameScreenStart[0], 490 + GameScreenStart[1], 50, WHITE);}
        EndDrawing();
    }
    Deaths = 0;
    Timer[0] = 0;
    Timer[1] = 0;
    Timer[2] = 0;
    Timer[3] = 0;
    BeginGame();
}

void SwitchLevel(){
    if(CurrentLevel <= NumberOFLevels){
        TransistionScreen();
    }
    switch(CurrentLevel){
        case 1:
            ChangeOverLevels(LevelOne);
            break;
        case 2:
            ChangeOverLevels(LevelTwo);
            break;
        case 3:
            ChangeOverLevels(LevelThree);
            break;
        case 4:
            ChangeOverLevels(LevelFour);
            Fence[0] = 1;
            break;
        case 5:
            ChangeOverLevels(LevelFive);
            Fence[0] = 1;
            break;
        case 6:
            ChangeOverLevels(LevelSix);
            Fence[0] = 1;
            break;
        case 7:
            ChangeOverLevels(LevelSeven);
            KeysNeeded = 2;
            Fence[0] = 1;
            break;
        case 8:
            ChangeOverLevels(LevelEight);
            Fence[0] = 1;
            break;
        case 9:
            ChangeOverLevels(LevelNine);
            KeysNeeded = 3;
            Fence[0] = 1;
            HasSpikes = true;
            break;
        case 10:
            ChangeOverLevels(LevelTen);
            Player[0] = 360;
            Player[1] = 640;
            KeysNeeded = 3;
            Fence[0] = 2;
            Fence[1] = 281;
            Fence[2] = 250;
            Lock[0] = 72;
            Lock[1] = 148;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 4;
            Enimes[2] = 232;
			Enimes[3] = 258;
			Enimes[4] = 272;
			Enimes[5] = 298;
            break;
        case 11:
            ChangeOverLevels(LevelEleven);
            Player[0] = 400;
            Player[1] = 80;
            KeysNeeded = 3;
            Fence[0] = 3;
            Fence[1] = 81;
            Fence[2] = 332;
            Fence[3] = 28;
            Lock[0] = 35;
            Lock[1] = 301;
            Lock[2] = 328;
            HasEnimes = true;
            Enimes[1] = 7;
            Enimes[2] = 324;
            Enimes[3] = 25;
			Enimes[4] = 227;
			Enimes[5] = 272;
			Enimes[6] = 37;
            Enimes[7] = 277;
            Enimes[8] = 338;
            break;
        case 12:
            ChangeOverLevels(LevelTwelve);
            Player[0] = 440;
            KeysNeeded = 3;
            Fence[0] = 2;
            Fence[1] = 22;
            Fence[2] = 23;
            Lock[0] = 38;
            Lock[1] = 328;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 4;
            Enimes[2] = 24;
            Enimes[3] = 325;
			Enimes[4] = 267;
			Enimes[5] = 108;
            break;
        case 13:
            ChangeOverLevels(LevelThirteen);
            Player[0] = 200;
            Player[1] = 200;
            KeysNeeded = 2;
            Fence[0] = 3;
            Fence[1] = 178;
            Fence[2] = 249;
            Fence[3] = 43;
            Lock[0] = 152;
            Lock[1] = 48;
            Lock[2] = 282;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 12;
            Enimes[2] = 37;
            Enimes[3] = 52;
			Enimes[4] = 82;
			Enimes[5] = 110;
            Enimes[6] = 114;
            Enimes[7] = 116;
            Enimes[8] = 189;
            Enimes[9] = 191;
            Enimes[10] = 193;
            Enimes[11] = 195;
            Enimes[12] = 243;
            Enimes[13] = 112;
            break;
        case 14:
            ChangeOverLevels(LevelFourteen);
            Player[0] = 400;
            Player[1] = 360;
            KeysNeeded = 1;
            Fence[0] = 1;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 3;
            Enimes[2] = 302;
            Enimes[3] = 308;
			Enimes[4] = 314;
            break;
        case 15:
            ChangeOverLevels(LevelFifteen);
            Player[0] = 480;
            Player[1] = 520;
            KeysNeeded = 2;
            Fence[0] = 2;
            Fence[1] = 147;
            Fence[2] = 278;
            Lock[0] = 217;
            Lock[1] = 37;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 10;
            Enimes[2] = 27;
            Enimes[3] = 121;
			Enimes[4] = 124;
            Enimes[5] = 190;
            Enimes[6] = 194;
            Enimes[7] = 301;
            Enimes[8] = 309;
            Enimes[9] = 323;
            Enimes[10] = 332;
            Enimes[11] = 337;
            break;
        case 16:
            ChangeOverLevels(LevelSixteen);
            Player[0] = 80;
            Player[1] = 320;
            KeysNeeded = 1;
            Fence[0] = 4;
            Fence[1] = 158;
            Fence[2] = 198;
            Fence[3] = 212;
            Fence[4] = 326;
            Lock[0] = 177;
            Lock[1] = 125;
            Lock[2] = 333;
            Lock[3] = 207;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 9;
            Enimes[2] = 33;
            Enimes[3] = 37;
			Enimes[4] = 121;
            Enimes[5] = 133;
            Enimes[6] = 137;
            Enimes[7] = 161;
            Enimes[8] = 234;
            Enimes[9] = 317;
            Enimes[10] = 338;
            break;
        case 17:
            ChangeOverLevels(LevelSeventeen);
            Player[0] = 720;
            Player[1] = 320;
            KeysNeeded = 1;
            HasEnimes = true;
            Enimes[1] = 41;
			Enimes[2] = 26;
			Enimes[3] = 27;
			Enimes[4] = 48;
			Enimes[5] = 69;
			Enimes[6] = 70;
            Enimes[7] = 51;
            Enimes[8] = 32;
            Enimes[9] = 33;
            Enimes[10] = 34;
            Enimes[11] = 35;
            Enimes[12] = 36;
            Enimes[13] = 57;
            Enimes[14] = 77;
            Enimes[15] = 98;
            Enimes[16] = 118;
            Enimes[17] = 138;
            Enimes[18] = 158;
            Enimes[19] = 197;
            Enimes[20] = 216;
            Enimes[21] = 235;
            Enimes[22] = 254;
            Enimes[23] = 273;
            Enimes[24] = 292;
            Enimes[25] = 311;
            Enimes[26] = 330;
            Enimes[27] = 329;
            Enimes[28] = 308;
            Enimes[29] = 287;
            Enimes[30] = 266;
            Enimes[31] = 245;
            Enimes[32] = 224;
            Enimes[33] = 203;
            Enimes[34] = 161;
            Enimes[35] = 141;
            Enimes[36] = 121;
            Enimes[37] = 101;
            Enimes[38] = 81;
            Enimes[39] = 62;
            Enimes[40] = 42;
            Enimes[41] = 24;
			Enimes[42] = 25;
            break;
        case 18:
            ChangeOverLevels(LevelEighteen);
            Player[0] = 720;
            Player[1] = 600;
            break;
        case 19:
            ChangeOverLevels(LevelNineteen);
            KeysNeeded = 1;
            Fence[0] = 3;
            Fence[1] = 35;
            Fence[2] = 326;
            Fence[3] = 337;
            Lock[0] = 123;
            Lock[1] = 98;
            Lock[2] = 28;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 15;
            Enimes[2] = 169;
            Enimes[3] = 191;
			Enimes[4] = 208;
            Enimes[5] = 230;
            Enimes[6] = 312;
            Enimes[7] = 117;
            Enimes[8] = 136;
            Enimes[9] = 155;
            Enimes[10] = 174;
            Enimes[11] = 193;
            Enimes[12] = 213;
            Enimes[13] = 234;
            Enimes[14] = 255;
            Enimes[15] = 276;
            Enimes[16] = 297;
            break;
        case 20:
            ChangeOverLevels(LevelTwenty);
            KeysNeeded = 1;
            Fence[0] = 8;
            Fence[1] = 307;
            Fence[2] = 309;
            Fence[3] = 311;
            Fence[4] = 313;
            Fence[5] = 315;
            Fence[6] = 56;
            Fence[7] = 303;
            Fence[8] = 305;
            Lock[0] = 27;
            Lock[1] = 268;
            Lock[2] = 182;
            Lock[3] = 187;
            Lock[4] = 196;
            Lock[5] = 317;
            Lock[6] = 113;
            Lock[7] = 118;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 14;
            Enimes[2] = 91;
            Enimes[3] = 115;
			Enimes[4] = 129;
            Enimes[5] = 149;
            Enimes[6] = 153;
            Enimes[7] = 158;
            Enimes[8] = 170;
            Enimes[9] = 233;
            Enimes[10] = 238;
            Enimes[11] = 270;
            Enimes[12] = 272;
            Enimes[13] = 274;
            Enimes[14] = 276;
            Enimes[15] = 278;
            break;
        case 21:
            ChangeOverLevels(LevelTwentyone);
            Player[1] = 640;
            KeysNeeded = 4;
            Fence[0] = 2;
            Fence[1] = 258;
            Fence[2] = 297;
            Lock[0] = 64;
            Lock[1] = 77;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 11;
            Enimes[2] = 30;
            Enimes[3] = 48;
			Enimes[4] = 52;
            Enimes[5] = 141;
            Enimes[6] = 146;
            Enimes[7] = 156;
            Enimes[8] = 158;
            Enimes[9] = 181;
            Enimes[10] = 187;
            Enimes[11] = 193;
            Enimes[12] = 198;
            break;
        case 22:
            ChangeOverLevels(LevelTwentytwo);
            Player[0] = 720;
            KeysNeeded = 4;
            Fence[0] = 3;
            Fence[1] = 323;
            Fence[2] = 336;
            Fence[3] = 122;
            Lock[0] = 235;
            Lock[1] = 141;
            Lock[2] = 277;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 19;
            Enimes[2] = 82;
            Enimes[3] = 162;
			Enimes[4] = 106;
            Enimes[5] = 146;
            Enimes[6] = 186;
            Enimes[7] = 226;
            Enimes[8] = 29;
            Enimes[9] = 50;
            Enimes[10] = 69;
            Enimes[11] = 270;
            Enimes[12] = 289;
            Enimes[13] = 310;
            Enimes[14] = 329;
            Enimes[15] = 112;
            Enimes[16] = 152;
            Enimes[17] = 232;
            Enimes[18] = 157;
            Enimes[19] = 177;
            Enimes[20] = 172;
            break;
        case 23:
            ChangeOverLevels(LevelTwentythree);
            Player[0] = 240;
            Player[1] = 480;
            KeysNeeded = 3;
            Fence[0] = 1;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 22;
            Enimes[2] = 141;
            Enimes[3] = 122;
			Enimes[4] = 103;
            Enimes[5] = 84;
            Enimes[6] = 65;
            Enimes[7] = 46;
            Enimes[8] = 27;
            Enimes[9] = 48;
            Enimes[10] = 69;
            Enimes[11] = 90;
            Enimes[12] = 111;
            Enimes[13] = 132;
            Enimes[14] = 153;
            Enimes[15] = 174;
            Enimes[16] = 195;
            Enimes[17] = 216;
            Enimes[18] = 237;
            Enimes[19] = 258;
            Enimes[20] = 277;
            Enimes[21] = 296;
            Enimes[22] = 315;
            Enimes[23] = 334;
            break;
        case 24:
            ChangeOverLevels(LevelTwentyfour);
            KeysNeeded = 4;
            Fence[0] = 2;
            Fence[1] = 325;
            Fence[2] = 318;
            Lock[0] = 231;
            Lock[1] = 189;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 34;
            Enimes[2] = 33;
            Enimes[3] = 201;
			Enimes[4] = 241;
            Enimes[5] = 321;
            Enimes[6] = 38;
            Enimes[7] = 58;
            Enimes[8] = 78;
            Enimes[9] = 98;
            Enimes[10] = 118;
            Enimes[11] = 138;
            Enimes[12] = 158;
            Enimes[13] = 178;
            Enimes[14] = 198;
            Enimes[15] = 218;
            Enimes[16] = 238;
            Enimes[17] = 258;
            Enimes[18] = 278;
            Enimes[19] = 298;
            Enimes[20] = 53;
            Enimes[21] = 73;
            Enimes[22] = 93;
            Enimes[23] = 113;
            Enimes[24] = 133;
            Enimes[25] = 153;
            Enimes[26] = 173;
            Enimes[27] = 193;
            Enimes[28] = 213;
            Enimes[29] = 233;
            Enimes[30] = 253;
            Enimes[31] = 273;
            Enimes[32] = 293;
            Enimes[33] = 313;
            Enimes[34] = 333;
            Enimes[35] = 41;
            break;
        case 25:
            ChangeOverLevels(LevelTwentyfive);
            KeysNeeded = 4;
            Fence[0] = 1;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 13;
            Enimes[2] = 48;
            Enimes[3] = 50;
			Enimes[4] = 129;
            Enimes[5] = 149;
            Enimes[6] = 236;
            Enimes[7] = 237;
            Enimes[8] = 238;
            Enimes[9] = 241;
            Enimes[10] = 261;
            Enimes[11] = 285;
            Enimes[12] = 303;
            Enimes[13] = 304;
            Enimes[14] = 306;
            break;
        case 26:
            ChangeOverLevels(LevelTwentysix);
            HasEnimes = true;
            Enimes[1] = 27;
            Enimes[2] = 23;
            Enimes[3] = 25;
			Enimes[4] = 27;
            Enimes[5] = 29;
            Enimes[6] = 31;
            Enimes[7] = 33;
            Enimes[8] = 35;
            Enimes[9] = 37;
            Enimes[10] = 41;
            Enimes[11] = 58;
            Enimes[12] = 81;
            Enimes[13] = 98;
            Enimes[14] = 121;
            Enimes[15] = 138;
            Enimes[16] = 161;
            Enimes[17] = 178;
            Enimes[18] = 201;
            Enimes[19] = 218;
            Enimes[20] = 242;
            Enimes[21] = 244;
            Enimes[22] = 246;
            Enimes[23] = 248;
            Enimes[24] = 250;
            Enimes[25] = 252;
            Enimes[26] = 254;
            Enimes[27] = 256;
            Enimes[28] = 258;
            break;
        case 27:
            ChangeOverLevels(LevelTwentyseven);
            Player[0] = 80;
            Player[1] = 640;
            KeysNeeded = 20;
            Fence[0] = 4;
            Fence[1] = 70;
            Fence[2] = 282;
            Fence[3] = 295;
            Fence[4] = 61;
            Lock[0] = 130;
            Lock[1] = 55;
            Lock[2] = 166;
            Lock[3] = 192;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 9;
            Enimes[2] = 121;
            Enimes[3] = 318;
			Enimes[4] = 338;
            Enimes[5] = 161;
            Enimes[6] = 182;
            Enimes[7] = 203;
            Enimes[8] = 224;
            Enimes[9] = 245;
            Enimes[10] = 266;
            break;
        case 28:
            ChangeOverLevels(LevelTwentyeight);
            Player[0] = 400;
            Player[1] = 320;
            KeysNeeded = 6;
            Fence[0] = 3;
            Fence[1] = 97;
            Fence[2] = 213;
            Fence[3] = 313;
            Lock[0] = 27;
            Lock[1] = 104;
            Lock[2] = 107;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 5;
            Enimes[2] = 30;
            Enimes[3] = 161;
			Enimes[4] = 201;
            Enimes[5] = 241;
            Enimes[6] = 281;
            break;
        case 29:
            ChangeOverLevels(LevelTwentynine);
            KeysNeeded = 3;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 11;
            Enimes[2] = 42;
            Enimes[3] = 63;
			Enimes[4] = 84;
            Enimes[5] = 126;
            Enimes[6] = 147;
            Enimes[7] = 168;
            Enimes[8] = 210;
            Enimes[9] = 231;
            Enimes[10] = 252;
            Enimes[11] = 294;
            Enimes[12] = 315;
            break;
        case 30:
            ChangeOverLevels(LevelThirty);
            KeysNeeded = 13;
            HasEnimes = true;
            Enimes[1] = 6;
            Enimes[2] = 150;
            Enimes[3] = 169;
			Enimes[4] = 207;
            Enimes[5] = 245;
            Enimes[6] = 283;
            Enimes[7] = 321;
            break;
        case 31:
            ChangeOverLevels(LevelThirtyone);
            Player[0] = 520;
            Player[1] = 600;
            KeysNeeded = 3;
            Fence[0] = 2;
            Fence[1] = 270;
            Fence[2] = 257;
            Lock[0] = 201;
            Lock[1] = 197;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 10;
            Enimes[2] = 35;
            Enimes[3] = 43;
			Enimes[4] = 74;
            Enimes[5] = 82;
            Enimes[6] = 113;
            Enimes[7] = 121;
            Enimes[8] = 152;
            Enimes[9] = 161;
            Enimes[10] = 206;
            Enimes[11] = 245;
            break;
        case 32:
            ChangeOverLevels(LevelThirtytwo);
            Player[0] = 360;
            Player[1] = 640;
            KeysNeeded = 3;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 112;
            Enimes[2] = 21;
            Enimes[3] = 22;
			Enimes[4] = 23;
            Enimes[5] = 24;
            Enimes[6] = 25;
            Enimes[7] = 26;
            Enimes[8] = 27;
            Enimes[9] = 42;
            Enimes[10] = 43;
            Enimes[11] = 44;
            Enimes[12] = 45;
            Enimes[13] = 46;
            Enimes[14] = 47;
            Enimes[15] = 63;
            Enimes[16] = 64;
            Enimes[17] = 65;
            Enimes[18] = 66;
            Enimes[19] = 67;
            Enimes[20] = 84;
            Enimes[21] = 85;
            Enimes[22] = 86;
            Enimes[23] = 87;
            Enimes[24] = 105;
            Enimes[25] = 106;
            Enimes[26] = 107;
            Enimes[27] = 126;
            Enimes[28] = 127;
            Enimes[29] = 147;
            Enimes[30] = 32;
            Enimes[31] = 33;
            Enimes[32] = 34;
            Enimes[33] = 35;
            Enimes[34] = 36;
            Enimes[35] = 37;
            Enimes[36] = 38;
            Enimes[37] = 53;
            Enimes[38] = 54;
            Enimes[39] = 55;
            Enimes[40] = 56;
            Enimes[41] = 57;
            Enimes[42] = 58;
            Enimes[43] = 74;
            Enimes[44] = 75;
            Enimes[45] = 76;
            Enimes[46] = 77;
            Enimes[47] = 78;
            Enimes[48] = 95;
            Enimes[49] = 96;
            Enimes[50] = 97;
            Enimes[51] = 98;
            Enimes[52] = 116;
            Enimes[53] = 117;
            Enimes[54] = 118;
            Enimes[55] = 137;
            Enimes[56] = 138;
            Enimes[57] = 158;
            Enimes[58] = 201;
            Enimes[59] = 221;
            Enimes[60] = 222;
            Enimes[61] = 241;
            Enimes[62] = 242;
            Enimes[63] = 243;
            Enimes[64] = 261;
            Enimes[65] = 262;
            Enimes[66] = 263;
            Enimes[67] = 264;
            Enimes[68] = 281;
            Enimes[69] = 282;
            Enimes[70] = 283;
            Enimes[71] = 284;
            Enimes[72] = 285;
            Enimes[73] = 301;
            Enimes[74] = 302;
            Enimes[75] = 303;
            Enimes[76] = 304;
            Enimes[77] = 305;
            Enimes[78] = 306;
            Enimes[79] = 321;
            Enimes[80] = 322;
            Enimes[81] = 323;
            Enimes[82] = 324;
            Enimes[83] = 325;
            Enimes[84] = 326;
            Enimes[85] = 327;
            Enimes[86] = 328;
            Enimes[87] = 212;
            Enimes[88] = 232;
            Enimes[89] = 233;
            Enimes[90] = 252;
            Enimes[91] = 253;
            Enimes[92] = 254;
            Enimes[93] = 272;
            Enimes[94] = 273;
            Enimes[95] = 274;
            Enimes[96] = 275;
            Enimes[97] = 292;
            Enimes[98] = 293;
            Enimes[99] = 294;
            Enimes[100] = 295;
            Enimes[101] = 296;
            Enimes[102] = 312;
            Enimes[103] = 313;
            Enimes[104] = 314;
            Enimes[105] = 315;
            Enimes[106] = 316;
            Enimes[107] = 317;
            Enimes[108] = 332;
            Enimes[109] = 333;
            Enimes[110] = 334;
            Enimes[111] = 335;
            Enimes[112] = 337;
            Enimes[113] = 338;
            break;
        default:
            EndScreen();
            break;
    }
    EndTransistionScreen();
}