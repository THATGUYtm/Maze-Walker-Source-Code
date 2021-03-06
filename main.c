#include "raylib.h"
#include "resources/Scripts/Levels.c"
#define DeadZone 0.3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define FrameRate 60
#define StartingLevel 54
#define NumOfLevels 53
#define VersionNum "0.6"
#define RayLibLogoToggle true

Music GameMusicOne;
Music GameMusicTwo;
Music GameMusicThree;
Music GameMusicFour;
Music GameMusicFive;
Music EndingMusic;
Music MenuMusic;
Sound KeySoundEffect;
Sound LockSoundEffect;
Sound BoxPushSoundEffect;
Sound SpikeSoundEffect;
Sound EnimeSoundEffect;
Sound LevelFinnishSoundEffect;
Sound MenuChange;
Sound MenuSelect;
Sound WalkingSoundEffect;

Color FontColor = WHITE;

RenderTexture2D target;
Rectangle PlayerTilePos = (Rectangle){1680.0f, 80.0f, 40.0f, 40.0f};
Vector2 ClampValue(Vector2 value, Vector2 min, Vector2 max){
    Vector2 result = value;
    result.x = (result.x > max.x)? max.x : result.x;
    result.x = (result.x < min.x)? min.x : result.x;
    result.y = (result.y > max.y)? max.y : result.y;
    result.y = (result.y < min.y)? min.y : result.y;
    return result;
}

unsigned int TotalDeaths;
unsigned int TotalPlays;
unsigned int TotalFinnished;
unsigned int LeastDeathsInPlayThough; 
unsigned int MostDeathsInPlayThough;
unsigned int CurrentLevel = 1;
unsigned int NumberOFLevels = NumOfLevels;
unsigned int Deaths = 0;
unsigned int ButtonsPressed = 0;
unsigned int KeysNeeded = 1;
unsigned int KeysInHand = 0;
unsigned int DoorLocation = 0;
int i;
int gameScreenWidth = 800;
int gameScreenHeight = 720;
int FontSize = 30;
int DX = 5;
int DY = 5;
int Temp = 0;

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
unsigned int SpikeNum = 0;

float scale;

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
bool BoardersOn = true;
bool DisplayLogo = RayLibLogoToggle;
bool DebugMode = false;

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
void ResumeFunct(){Resume = true;}

#include "resources/Scripts/MainMenu.c"

void RayLibLogo(){
    const int screenWidth = 800,screenHeight = 720;
    int logoPositionX=screenWidth/2-128,logoPositionY=screenHeight/2-128,framesCounter=0,lettersCount=0,topSideRecWidth=16,leftSideRecHeight=16,bottomSideRecWidth=16,rightSideRecHeight=16,state=0;
    float alpha = 1.0f;
    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_ENTER) || GetKeyPressed() > 0 || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){break;}
        if(state == 0){
            framesCounter++;
            if(framesCounter == 120){
                state = 1;
                framesCounter = 0;
            }
        }else if(state == 1){
            topSideRecWidth += 4;
            leftSideRecHeight += 4;
            if(topSideRecWidth == 256) state = 2;
        }else if(state == 2){
            bottomSideRecWidth += 4;
            rightSideRecHeight += 4;
            if(bottomSideRecWidth == 256) state = 3;
        }else if(state == 3){
            framesCounter++;
            if(framesCounter/12){
                lettersCount++;
                framesCounter = 0;
            }
            if(lettersCount >= 10){
                alpha -= 0.02f;
                if(alpha <= 0.0f){
                    alpha = 0.0f;
                    state = 4;
                }
            }
        }else if(state == 4){
            if (IsKeyPressed('R')){
                framesCounter = 0;
                lettersCount = 0;
                topSideRecWidth = 16;
                leftSideRecHeight = 16;
                bottomSideRecWidth = 16;
                rightSideRecHeight = 16;
                alpha = 1.0f;
                state = 0;
            }
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginTextureMode(target);
                ClearBackground(RAYWHITE);
                if (state == 0){
                    if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
                }else if (state == 1){
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
                }else if (state == 2){
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
                    DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
                    DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
                }else if (state == 3){
                    DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
                    DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));
                    DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
                    DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));
                    DrawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, Fade(RAYWHITE, alpha));
                    DrawText(TextSubtext("raylib", 0, lettersCount), screenWidth/2 - 44, screenHeight/2 + 48, 50, Fade(BLACK, alpha));
                }else if (state == 4){break;}
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
	float fade = 0.0f;
	for(i = 0; i < 10; i++){
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade += 0.1f;
    }
}

void IntMusicAndSoundEffects(){
    InitAudioDevice(); 
	SetMasterVolume(0.1f);
	GameMusicOne = LoadMusicStream("resources/Music/LevelThemeOne.mp3");
    GameMusicTwo = LoadMusicStream("resources/Music/LevelThemeTwo.mp3");
    GameMusicThree = LoadMusicStream("resources/Music/LevelThemeThree.mp3");
    GameMusicFour = LoadMusicStream("resources/Music/LevelThemeFour.mp3");
    GameMusicFive = LoadMusicStream("resources/Music/LevelThemeFive.mp3");
    MenuMusic = LoadMusicStream("resources/Music/MenuMusic.mp3");
    EndingMusic = LoadMusicStream("resources/Music/EndingMusic.mp3");
	PlayMusicStream(MenuMusic);
    WalkingSoundEffect = LoadSound("resources/SoundEffects/WalkingSoundEffect.wav");
    KeySoundEffect = LoadSound("resources/SoundEffects/KeySoundEffect.wav");
    LockSoundEffect = LoadSound("resources/SoundEffects/LockSoundEffect.wav");
    BoxPushSoundEffect = LoadSound("resources/SoundEffects/BoxPushSoundEffect.wav");
    SpikeSoundEffect = LoadSound("resources/SoundEffects/SpikeSoundEffect.wav");
    EnimeSoundEffect = LoadSound("resources/SoundEffects/EnimeMovingSoundEffect.wav"); 
    LevelFinnishSoundEffect = LoadSound("resources/SoundEffects/LevelFinnishSoundEffect.wav"); 
    MenuSelect = LoadSound("resources/SoundEffects/MenuSelectSoundEffect.wav"); 
    MenuChange = LoadSound("resources/SoundEffects/MenuChangeSoundEffect.wav"); 
    SetSoundVolume(BoxPushSoundEffect, 0.4f);
    SetSoundVolume(KeySoundEffect, 0.4f);
    SetSoundVolume(SpikeSoundEffect, 0.4f);
    SetSoundVolume(MenuSelect, 0.6f);
    SetSoundVolume(MenuChange, 0.3f);
    SetSoundVolume(WalkingSoundEffect, 0.5f);
}

#include "resources/Scripts/Music.c"

void IntWindow(){
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Maze Walker");
	SetWindowPosition(3,31);
    SetWindowMinSize(200, 180);
    Image Icon = LoadImage("resources/Graphics/Player/Tile06.png");
    SetWindowIcon(Icon);
    SetTargetFPS(FrameRate);
    SetExitKey(KEY_DELETE);
    target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, FILTER_BILINEAR);
	ToggleFullscreen();
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
	FPSON = LoadStorageValue(24);
	BoardersOn = LoadStorageValue(25);
	MusicOn = LoadStorageValue(26);
	TileSetChoice = LoadStorageValue(27);
	intTextures();
	SoundEffectsOn = LoadStorageValue(28);
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
	SaveStorageValue(24, FPSON);
	SaveStorageValue(25, BoardersOn);
	SaveStorageValue(26, MusicOn);
	SaveStorageValue(27, TileSetChoice);
	SaveStorageValue(28, SoundEffectsOn);
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
    if(Deaths < LeastDeathsInPlayThough && TotalFinnished > 0){
		LeastDeathsInPlayThough = Deaths;
    }
    if(Deaths > MostDeathsInPlayThough && TotalFinnished > 0){
        MostDeathsInPlayThough = Deaths;
    }
}

void ExitGame(){
    SaveSave();
    UnloadTextures();
}

int main(void){
    IntWindow();
    intTextures();
    IntMusicAndSoundEffects();
    LoadSave();
    if(DisplayLogo == true){
        RayLibLogo();
    }
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
        if(WindowShouldClose()){
            ExitGame();
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                MainMenu();
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    } 
}

void BeginGame(){
    SaveSave();
	if(IsGamepadAvailable(1)){
		MenuControllerMode = true;
	}
    float fade = 1.0f;
    for(i = 0; i < 10; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                MainMenu();
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade -= 0.1f;
    }
    MainMenuSection();
    Game();
}

void Game(){
    if(!WindowShouldClose()){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(SoundEffectsOn==true){
            PlaySound(LevelFinnishSoundEffect);
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        SwitchLevel();
    }
    while(!WindowShouldClose()){
		if(IsWindowHidden() || IsWindowMinimized()){
            PauseMenu();
        }
        if(MusicOn == true){
            PlayInGameMusic();
        } 
		Input();
        Update();
        PostionCheck();
        Draw();
		if((Player[0]%40)==0){Player[0]/=40;Player[0]*=40;}
		if((Player[1]%40)==0){Player[1]/=40;Player[1]*=40;}
    }
    ExitGame();
}

bool CanWalk(int Dir){
    switch(Dir){
        case 0:
            switch(Map[(((Player[1]/40)-1)*20)+(Player[0]/40)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
            break;
        case 1:
            switch(Map[(((Player[1]/40)+1)*20)+(Player[0]/40)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
            break;
        case 2:
            switch(Map[(((Player[1]/40))*20)+((Player[0]/40)-1)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:
                    return true;
                    break;
                default:
                    return false;
                    break;
                }
                break;
        case 3:
            switch(Map[((Player[1]/40)*20)+((Player[0]/40)+1)]){
                case 0x00:case 0x01:case 0x03:case 0x04:case 0x13:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1A:case 0x46:
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
            break;
        default:
            return false;
            break;
    }
    return false;
}

void PlayerUpdate(){
    if(IsWindowHidden() || IsWindowMinimized()){
        PauseMenu();
    }
    if(MusicOn == true){
        PlayInGameMusic();
    } 
    if(SoundEffectsOn == true && (TotalPlayTime[0]%8)==0){
        PlaySound(WalkingSoundEffect);
    }
    Update();
    Draw();
}

void DrawDebug();

void Input(){
    ButtonsPressed = 0;
    if((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) < -DeadZone) && (!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_D))){
        if(Map[((Player[1]/40)*20)+((Player[0]/40)-1)] != 0x05){
            if(CanWalk(2) == true){
                ButtonsPressed++;
                Player[2] = 0;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){
                        Player[0]-=4;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 4; i++){
                        Player[0]-=10;
                        PlayerUpdate();
                    }
                }
            }
        }else{
            if(Map[((Player[1]/40)*20)+((Player[0]/40)-2)] == 0x00){
                ButtonsPressed++;
                Player[2] = 0;
                Map[(((Player[1]/40))*20)+(Player[0]/40)-1] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0]-40;
                Rock[2] = Player[1];
                if(SoundEffectsOn==true){
                    PlaySound(BoxPushSoundEffect);
                }
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 20; i++){
                        Rock[1]-=2;
                        Player[0]-=2;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 8; i++){
                        PlayerUpdate();
                        Player[0]-=5;
                        Rock[1]-=5;
                    }
                }
                Map[(((Player[1]/40))*20)+(Player[0]/40)-1] = 0x05;
                Rock[0] = 0;
            }
        }
        PostionCheck();
    }
    if((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 2) < -DeadZone) && (!IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_S))){
        if(Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] != 0x05){
            if(CanWalk(0) == true){
                ButtonsPressed++;
                Player[2] = 1;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){
                        Player[1]-=4;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 4; i++){
                        Player[1]-=10;
                        PlayerUpdate();
                    }
                }
            } 
        }else{
            if(Map[(((Player[1]/40)-2)*20)+(Player[0]/40)] == 0x00){
                ButtonsPressed++;
                Player[2] = 1;
                Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0];
                Rock[2] = Player[1]-40;
                if(SoundEffectsOn==true){
                    PlaySound(BoxPushSoundEffect);
                }
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 20; i++){
                        Rock[2]-=2;
                        Player[1]-=2;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 8; i++){
                        Rock[2]-=5;
                        Player[1]-=5;
                        PlayerUpdate();
                    }
                }
                Map[(((Player[1]/40)-1)*20)+(Player[0]/40)] = 0x05;
                Rock[0] = 0;
            }
        }
        PostionCheck();
    }
    if((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) > DeadZone) && (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_A))){
        if(Map[((Player[1]/40)*20)+((Player[0]/40)+1)] != 0x05){
            if(CanWalk(3) == true){
                ButtonsPressed++;
                Player[2] = 2;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){
                        Player[0]+=4;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 4; i++){
                        Player[0]+=10;
                        PlayerUpdate();
                    }
                }
            }
        }else if(Map[((Player[1]/40)*20)+((Player[0]/40)+2)] == 0x00){
            ButtonsPressed++;
            Player[2] = 2;
            Map[(((Player[1]/40))*20)+(Player[0]/40)+1] = 0x00;
            Rock[0] = 1;
            Rock[1] = Player[0]+40;
            Rock[2] = Player[1];
            if(SoundEffectsOn==true){
                PlaySound(BoxPushSoundEffect);
            }
            if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                for(i = 0; i < 20; i++){
                    Rock[1]+=2;
                    Player[0]+=2;
                    PlayerUpdate();
                }
            }else{
                for(i = 0; i < 8; i++){
                    Rock[1]+=5;
                    Player[0]+=5;
                    PlayerUpdate();
                }
            }
            Map[(((Player[1]/40))*20)+(Player[0]/40)+1] = 0x05;
            Rock[0] = 0;
        }
        PostionCheck();        
    }
    if((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || GetGamepadAxisMovement(GAMEPAD_PLAYER1, 2) > DeadZone) && (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_W))){
        if(Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] != 0x05){
            if(CanWalk(1) == true){
                ButtonsPressed++;
                Player[2] = 3;
                Player[5] = 1;
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    for(i = 0; i < 10; i++){
                        Player[1] += 4;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 4; i++){
                        Player[1] += 10;
                        PlayerUpdate();
                    }
                }
            } 
        }else if(Map[(((Player[1]/40)+2)*20)+(Player[0]/40)] == 0x00){
            ButtonsPressed++;
                Player[2] = 3;
                Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] = 0x00;
                Rock[0] = 1;
                Rock[1] = Player[0];
                Rock[2] = Player[1]+40;
                if(SoundEffectsOn==true){
                    PlaySound(BoxPushSoundEffect);
                }
                if(IsKeyDown(KEY_SPACE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){ 
                    for(i = 0; i < 20; i++){
                        Rock[2] += 2;
                        Player[1] += 2;
                        PlayerUpdate();
                    }
                }else{
                    for(i = 0; i < 8; i++){
                        Rock[2] += 5;
                        Player[1] += 5;
                        PlayerUpdate();
                    }
                }
                Map[(((Player[1]/40)+1)*20)+(Player[0]/40)] = 0x05;
                Rock[0] = 0;
        }
        PostionCheck();
    }
    PostionCheck();
    if(ButtonsPressed == 0){
        Player[5] = 0;
    }
    if(IsKeyPressed(KEY_ENTER) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_UP)){
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
    if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT)){
        PauseMenu();
    }
    if((IsKeyPressed(KEY_F) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_UP)) && DebugMode == true){
        FPSON=!FPSON;
    }
	if(IsKeyPressed(KEY_P) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)){
        DebugMode=!DebugMode;
		DrawDebug();
		int j = 10;
		if(Temp > j){j = Temp;}
		if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){
			while(1){if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){FontSize--;}else{break;}}
		}else{
			while(1){if(DY+((FontSize*14)+(j*FontSize))+FontSize <= GetScreenHeight()){FontSize++;}else{break;}}
		}
    }
}

void PostionCheck(){
    switch(Map[((Player[1]/40)*20)+(Player[0]/40)]){
        case 0x01:
            if(SoundEffectsOn==true){
                PlaySound(LevelFinnishSoundEffect);
            }
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
                for(i = 0; i < 5; i++){
                    Draw();
                }
                SwitchLevel();
            }
            break;
        case 0x04:
            if(SoundEffectsOn==true){
                PlaySound(KeySoundEffect);
            }
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
            if(SoundEffectsOn==true){
                PlaySound(LockSoundEffect);
            }
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
                if(SoundEffectsOn==true){
                    PlaySound(KeySoundEffect);
                }
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
        default:
            OnTeleport = false;
            break;
    }
}

void Update(){
    if(IsFileDropped() && DebugMode == true){
        int count = 0;
        char **droppedFiles = GetDroppedFiles(&count);
        if(count == 1){
            if (IsFileExtension(droppedFiles[0], ".png")){
                UnloadTexture(TileSet);
                TileSet = LoadTexture(droppedFiles[0]);
            }
        }
        ClearDroppedFiles();
    }
    if(HasEnimes == true){
        Enimes[0]++;
        if(Enimes[0] >= 45 && Rock[0] != 1){
            if(SoundEffectsOn==true){
                PlaySound(EnimeSoundEffect);
            }
            Enimes[0] = 0;
            for(int i = 2; i < Enimes[1] + 2; i++){
                switch(Map[Enimes[i]]){
                    case 0x17:					
                        if(Map[Enimes[i]-1] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]-1] = 0x17;
                            Enimes[i] -= 1;
                        }else{
                            Map[Enimes[i]] = 0x19;
                        }
                        break;
                    case 0x18:
                        if(Map[Enimes[i]-20] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]-20] = 0x18;
                            Enimes[i] -= 20;
                        }else{
                            Map[Enimes[i]] = 0x1A;
                        }
                        break;
                    case 0x19:
                        if(Map[Enimes[i]+1] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]+1] = 0x19;
                            Enimes[i] += 1;
                        }else{
                            Map[Enimes[i]] = 0x17;
                        }
                        break;
                    case 0x1A:
                        if(Map[Enimes[i]+20] == 0x00){
                            Map[Enimes[i]] = 0x00;
                            Map[Enimes[i]+20] = 0x1A;
                            Enimes[i] += 20;
                        }else{
                            Map[Enimes[i]] = 0x18;
                        }
                        break;
                }
            }
        }
    }
    if(HasSpikes == true){
        if(Spikes[0] == 160){
            if(SoundEffectsOn==true){
                PlaySound(SpikeSoundEffect);
            }
            Spikes[0] = 0;
			SpikeNum = 0;
            for(int i = 0; i < 360; i++){
                switch(Map[i]){
                    case 0x15:
						SpikeNum++;
                        Map[i] = 0x16;
                        break;
                    case 0x16:
						SpikeNum++;
                        Map[i] = 0x15;
                        break;
                }
            }
        }
        Spikes[0]++;
    }else{
		SpikeNum = 0;
	}
    if(Player[5] == 1){
        Player[4]++;
        if(Player[2] == 0){
            if(Player[4] >= 34){
               Player[4] = 0;
               PlayerTilePos = (Rectangle){0.0f, 80.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 30){
               PlayerTilePos = (Rectangle){400.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 17){
               PlayerTilePos = (Rectangle){440.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 13){
               PlayerTilePos = (Rectangle){400.0f, 40.0f, 40.0f, 40.0f};
            }else{
                PlayerTilePos = (Rectangle){0.0f, 80.0f, 40.0f, 40.0f};
            }
        }else if(Player[2] == 1){
            if(Player[4] >= 34){
               Player[4] = 0;
               PlayerTilePos = (Rectangle){240.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 30){
               PlayerTilePos = (Rectangle){160.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 17){
               PlayerTilePos = (Rectangle){200.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 13){
               PlayerTilePos = (Rectangle){160.0f, 40.0f, 40.0f, 40.0f};
            }else{
                PlayerTilePos = (Rectangle){240.0f, 40.0f, 40.0f, 40.0f};
            }
        }else if(Player[2] == 2){
            if(Player[4] >= 34){
               Player[4] = 0;
               PlayerTilePos = (Rectangle){120.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 30){
               PlayerTilePos = (Rectangle){40.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 17){
               PlayerTilePos = (Rectangle){80.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 13){
               PlayerTilePos = (Rectangle){40.0f, 40.0f, 40.0f, 40.0f};
            }else{
                PlayerTilePos = (Rectangle){120.0f, 40.0f, 40.0f, 40.0f};
            }
        }else if(Player[2] == 3){
            if(Player[4] >= 34){
               Player[4] = 0;
               PlayerTilePos = (Rectangle){360.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 30){
               PlayerTilePos = (Rectangle){280.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 17){
               PlayerTilePos = (Rectangle){320.0f, 40.0f, 40.0f, 40.0f};
            }else if(Player[4] >= 13){
               PlayerTilePos = (Rectangle){280.0f, 40.0f, 40.0f, 40.0f};
            }else{
                PlayerTilePos = (Rectangle){360.0f, 40.0f, 40.0f, 40.0f};
            }
        }
    }else{
        switch(Player[2]){
            case 0:
                PlayerTilePos = (Rectangle){400.0f, 40.0f, 40.0f, 40.0f};
                break;
            case 1:
                PlayerTilePos = (Rectangle){160.0f, 40.0f, 40.0f, 40.0f};
                break;
            case 2:
                PlayerTilePos = (Rectangle){40.0f, 40.0f, 40.0f, 40.0f};
                break;
            case 3:
                PlayerTilePos = (Rectangle){280.0f, 40.0f, 40.0f, 40.0f};
                break;
        }
    }
}

void DrawDebug(){
	DrawText(FormatText("Enime Time: %i",Enimes[0]),DX,DY,FontSize,FontColor);
	DrawText(FormatText("Spike Time: %i",Spikes[0]),DX,DY+FontSize,FontSize,FontColor);
	DrawText(FormatText("PlayerX: %i",Player[0]),DX,DY+(FontSize*2),FontSize,FontColor);
	DrawText(FormatText("PlayerY: %i",Player[1]),DX,DY+(FontSize*3),FontSize,FontColor);
	switch(Player[2]){
		case 0:DrawText("Player Dir: Left",DX,DY+(FontSize*4),FontSize,FontColor);break;
		case 1:DrawText("Player Dir: Up",DX,DY+(FontSize*4),FontSize,FontColor);break;
		case 2:DrawText("Player Dir: Right",DX,DY+(FontSize*4),FontSize,FontColor);break;
		case 3:DrawText("Player Dir: Down",DX,DY+(FontSize*4),FontSize,FontColor);break;
	}
	DrawText(FormatText("Player Anim: %i",Player[4]),DX,DY+(FontSize*5),FontSize,FontColor);
	DrawText(FormatText("Player Walk: %i",Player[5]),DX,DY+(FontSize*6),FontSize,FontColor);
	DrawText(FormatText("FPS: %d",GetFPS()),DX,DY+(FontSize*7),FontSize,FontColor);
	DrawText(FormatText("Spike num: %d",SpikeNum),DX,DY+(FontSize*8),FontSize,FontColor);
	DrawText(FormatText("Time %02ih:%02im:%02is",Timer[3], Timer[2], Timer[1]), DX, DY+(FontSize*9), FontSize, FontColor);
	DrawText(FormatText("Deaths: %d",Deaths),DX,DY+(FontSize*10),FontSize,FontColor);
	DrawText(FormatText("Level: %d",CurrentLevel),DX,DY+(FontSize*11),FontSize,FontColor);
	DrawText(FormatText("Keys: %d",KeysInHand),DX,DY+(FontSize*12),FontSize,FontColor);
	DrawText(FormatText("Keys Needed: %d",KeysNeeded),DX,DY+(FontSize*13),FontSize,FontColor);
	DrawText(FormatText("Enime num: %d",Enimes[1]),DX,DY+(FontSize*14),FontSize,FontColor);
	DrawText("Enime Pos:",(GetScreenWidth()-6*FontSize),DY+(FontSize*0),FontSize,FontColor);
	Temp = 2;
	for(int i = 0; i < Enimes[1]; i++){
		DrawText(FormatText("-%d: %d",(Temp - 1),Enimes[Temp]),(GetScreenWidth()-6*FontSize+(FontSize/4)),DY+((FontSize*0)+((Temp - 1)*FontSize)),FontSize,FontColor);
		Temp++;
	}
	if(IsWindowResized()){
		int j = 10;
		if(Temp > j){j = Temp;}
		if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){
			while(1){if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){FontSize--;}else{break;}}
		}else{
			while(1){if(DY+((FontSize*15)+(j*FontSize))+FontSize <= GetScreenHeight()){FontSize++;}else{break;}}
		}
	}
}

void Draw(){
    Timer[0] += 1;
    if(Timer[0] > 59){
        Timer[1]++;
        Timer[0] = 0;
    }
    if(Timer[1] > 59){
        Timer[2]++;
        Timer[1] = 0;
    }
    if(Timer[2] > 59){
        Timer[3]++;
        Timer[2] = 0;
    }
    TotalPlayTime[0]++;
    if(TotalPlayTime[0] > 59){
        TotalPlayTime[1]++;
        TotalPlayTime[0] = 0;
    }
    if(TotalPlayTime[1] > 59){
        TotalPlayTime[2]++;
        TotalPlayTime[1] = 0;
    }
    if(TotalPlayTime[2] > 59){
        TotalPlayTime[3]++;
        TotalPlayTime[2] = 0;
    }
    scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
    Vector2 mouse = GetMousePosition();
    Vector2 virtualMouse = { 0 };
    virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
    virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
    virtualMouse = ClampValue(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ gameScreenWidth, gameScreenHeight });
    BeginDrawing();
        ClearBKG();
        BeginTextureMode(target);
            DrawBKG();
            DrawTextureRec(TileSet, PlayerTilePos, (Vector2){Player[0], Player[1]}, WHITE);
            if(Rock[0]==1){
                DrawTextureRec(TileSet,(Rectangle){160.0f,0.0f,40.0f,40.0f},(Vector2){Rock[1],Rock[2]},WHITE);
            }
            if(FPSON == true){
                DrawFPS(10,10);
            }
        EndTextureMode();
        DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
		if(DebugMode == true){
			DrawDebug();
		}
	EndDrawing();
}

void ChangeOverLevels(const unsigned char Level[]){
    if(WindowShouldClose()){
        ExitGame();
    }
    for(i = 0; i < 360; i++){
        Map[i] = Level[i];
    }
	for(int i = 0; i < 360; i++){
		switch(Map[i]){
			case 0x15:
			case 0x16:
				SpikeNum++;
				break;
		}
	}
	DrawDebug();
	int j = 10;
	if(Temp > j){j = Temp;}
	if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){
		while(1){if(DY+((FontSize*15)+(j*FontSize))+FontSize >= GetScreenHeight()){FontSize--;}else{break;}}
	}else{
		while(1){if(DY+((FontSize*15)+(j*FontSize))+FontSize <= GetScreenHeight()){FontSize++;}else{break;}}
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
	Enimes[1] = 0;
    Player[0] = 40;
    Player[1] = 40;
    Update();
}

void EndTransistionScreen(){
    float fade = 1.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){
            UnloadTextures();
            ExitGame();
        }
        if(MusicOn == true){
            PlayInGameMusic();
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                DrawBKG();
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){Player[0], Player[1]}, WHITE);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginTextureMode(target);
                DrawRectangle(0,0,800,720,Fade(BLACK, fade));
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340, 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400, 340, 50, Fade(WHITE, fade));
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
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
            PlayInGameMusic();
        } 
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade)); 
            BeginTextureMode(target);
                DrawRectangle(0,0,800,720,Fade(BLACK, fade)); 
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340, 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400, 340, 50, Fade(WHITE, fade));
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        fade += 0.05f;
    }
    for(i = 0; i < 80; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            PlayInGameMusic();
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginTextureMode(target);
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){340, 340}, WHITE);
                DrawText(FormatText("%02i", CurrentLevel), 400, 340, 50, WHITE);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
}

void PauseMenu(){
    ButtonNum = 3;
    float fade = 0.0f;
    for(i = 0; i < 40; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        } 
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginTextureMode(target);
                DrawRectangle(0,0,800,720,Fade(BLACK, fade));
                DrawText("PAUSE", 150, 100, 150, Fade(WHITE, fade));
                DrawRectangle(230, 380, 300, 50, Fade(WHITE, fade));
                DrawText("Resume", 235, 385, 45, Fade(BLACK, fade));
                DrawRectangle(230, 440, 300, 50, Fade(WHITE, fade));
                DrawText("Main Menu", 235, 445, 45, Fade(BLACK, fade));
                DrawRectangle(230, 500, 300, 50, Fade(WHITE, fade));
                DrawText("Exit", 235, 505, 45, Fade(BLACK, fade));
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        fade += 0.025f;
    }
    while(1){
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
        if(MenuControllerMode == false){
            if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP)){
                MenuControllerMode = true;
                CurserPos = ButtonNum;
            }
            if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
                MenuControllerMode = true;
                CurserPos = ButtonNum;
            }
        }
        if(MenuControllerMode == true){
            if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP)||IsGamepadButtonPressed(GAMEPAD_PLAYER1,GAMEPAD_BUTTON_LEFT_FACE_UP)){
                MenuControllerMode = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                if(CurserPos > 0){
                    CurserPos--;
                }else{
                    CurserPos = ButtonNum-1;
                }
            }
            if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
                MenuControllerMode = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                if(CurserPos + 1 <= ButtonNum-1){
                    CurserPos++;
                }else{
                    CurserPos = 0;
                }
            }
        }
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginTextureMode(target);
                ClearBackground(BLACK);
                DrawText("PAUSE", 150, 100, 150, WHITE);
                if(((int)virtualMouse.x > 230) && ((int)virtualMouse.x < 530) && ((int)virtualMouse.y > 380) && ((int)virtualMouse.y < 430)){
                    if(CurserPos != 0){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 0;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(225, 375, 310, 60, GRAY);
                    DrawRectangle(230, 380, 300, 50, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        break;
                    }
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(225, 375, 310, 60, GRAY);
                    DrawRectangle(230, 380, 300, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        break;
                    }
                }else{
                    if(CurserPos == 0){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(230, 380, 300, 50, WHITE);
                }
                DrawText("Resume", 235, 385, 45, MenuTextColour);
                if(((int)virtualMouse.x > 230) && ((int)virtualMouse.x < 530) && ((int)virtualMouse.y > 440) && ((int)virtualMouse.y < 490)){
                    if(CurserPos != 1){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 1;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(225, 435, 310, 60, GRAY);
                    DrawRectangle(230, 440, 300, 50, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        BeginGame();
                    }
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(225, 435, 310, 60, GRAY);
                    DrawRectangle(230, 440, 300, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        BeginGame();
                    }
                }else{
                    if(CurserPos == 1){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(230, 440, 300, 50, WHITE);
                }
                DrawText("Main Menu", 235, 445, 45, MenuTextColour);
                if(((int)virtualMouse.x > 230) && ((int)virtualMouse.x < 530) && ((int)virtualMouse.y > 500) && ((int)virtualMouse.y < 550)){
                    if(CurserPos != 2){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 2;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(225, 495, 310, 60, GRAY);
                    DrawRectangle(230, 500, 300, 50, WHITE);
                    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        ExitGame();
                    }
                }else if(MenuControllerMode == true && CurserPos == 2){
                    DrawRectangle(225, 495, 310, 60, GRAY);
                    DrawRectangle(230, 500, 300, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        ExitGame();
                    }
                }else{
                    if(CurserPos == 2){
                        CurserPos = ButtonNum;
                    }
                DrawRectangle(230, 500, 300, 50, WHITE);} 
                DrawText("Exit", 235, 505, 45, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
            break;
        }
    }
    fade = 1.0f;
    for(i = 0; i < 40; i++){
        if(WindowShouldClose()){
            UnloadTextures();
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                DrawBKG();
                DrawTextureRec(TileSet, (Rectangle){280.0f, 40.0f, 40.0f, 40.0f}, (Vector2){Player[0], Player[1]}, WHITE);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginTextureMode(target);
                DrawRectangle(0,0,800,720,Fade(BLACK, fade));
                DrawText("PAUSE", 150, 100, 150, Fade(WHITE, fade));
                DrawRectangle(230, 380, 300, 50, Fade(WHITE, fade));
                DrawText("Resume", 235, 385, 45, Fade(BLACK, fade));
                DrawRectangle(230, 440, 300, 50, Fade(WHITE, fade));
                DrawText("Main Menu", 235, 445, 45, Fade(BLACK, fade));
                DrawRectangle(230, 500, 300, 50, Fade(WHITE, fade));
                DrawText("Exit", 235, 505, 45, Fade(BLACK, fade));
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        fade -= 0.025f;
    }
}

void EndScreen(){
	TotalFinnished++;
    GameCompleted();
    PlayMusicStream(EndingMusic);
    if(HardMode == true){
        HardModeBeaten = true;
    }
    CurrentLevel = 0;
    float fade = 1.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("You", 50, 50, 180, BLACK);
                DrawText("Excaped!", 50, 200, 150, BLACK);
                DrawText(FormatText("Time %02ih:%02im:%02is",Timer[3], Timer[2], Timer[1]), 50, 390, 50, WHITE);
                DrawText(FormatText("Deaths %02i", Deaths), 50, 440, 50, WHITE);
                if((BestTime[1]+(BestTime[2]*60)+(BestTime[3]*360)) > 0){
                    DrawText(FormatText("Best Time %02ih:%02im:%02is",BestTime[3], BestTime[2], BestTime[1]), 50, 490, 50, WHITE);
                }
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade -= 0.05f;
    }
    while(!WindowShouldClose() && !IsKeyDown(KEY_ESCAPE) && !IsKeyDown(KEY_ENTER) && !IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT)){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(EndingMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("You", 50, 50, 180, BLACK);
                DrawText("Excaped!", 50, 200, 150, BLACK);
                DrawText(FormatText("Time %02ih:%02im:%02is",Timer[3], Timer[2], Timer[1]), 50, 390, 50, WHITE);
                DrawText(FormatText("Deaths %02i", Deaths), 50, 440, 50, WHITE);
                if((BestTime[1]+(BestTime[2]*60)+(BestTime[3]*360)) > 0){
                    DrawText(FormatText("Best Time %02ih:%02im:%02is",BestTime[3], BestTime[2], BestTime[1]), 50, 490, 50, WHITE);
                }
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
    Deaths = 0;
    Timer[0] = 0;
    Timer[1] = 0;
    Timer[2] = 0;
    Timer[3] = 0;
    fade = 0.0f;
    for(i = 0; i < 20; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
            BeginTextureMode(target);
                DrawRectangle(0,0,800,760,Fade(BLACK, fade));
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        fade += 0.05f;
    }
    BeginGame();
}

#include "resources/Scripts/LevelTrans.c"