int CurserPos = 0;
unsigned int ButtonNum = 4;

void MainMenuSection();

void FadeOut(){
    float fade = 0.0f;
    for(i = 0; i < 10; i++){
        if(WindowShouldClose()){
            ExitGame();
        }
        if(MusicOn == true){
            UpdateMusicStream(MenuMusic);
        }
        BeginDrawing();
            ClearBKG();
            BeginTextureMode(target);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade += 0.11f;
    }
}

void ClearSaveFile(){
    CurrentLevel = 0;
    Timer[0] = Timer[1] = Timer[2] = Timer[3] = 0;
    Deaths = 0;
    BestTime[0] = BestTime[1] = BestTime[2] = BestTime[3] = 0;
    TotalPlayTime[0] = TotalPlayTime[1] = TotalPlayTime[2] = TotalPlayTime[3] = 0;
    TotalDeaths = 0;
    TotalPlays = 0;
    WorstTime[0] = WorstTime[1] = WorstTime[2] = WorstTime[3] = 0;
    LeastDeathsInPlayThough = 0;
    MostDeathsInPlayThough = 0;
    HardModeBeaten = 0;
    TotalFinnished = 0;
    SaveSave();
}

void ModeSelectFade(){
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
                DrawMainMenu();
                DrawText("Maze", 160, 50, 180, MenuTextColour);
                DrawText("Walker", 90, 190, 180, MenuTextColour);
                DrawText("Walk Your Way To Freedom", 50, 350, 50, MenuTextColour);
                DrawRectangle(300, 435, 200, 35, WHITE);
                DrawText("Normal", 315, 435, 35, MenuTextColour);
                DrawRectangle(300, 480, 200, 35, WHITE);
                DrawText("Hard", 315, 480, 35, MenuTextColour);
                DrawRectangle(300, 525, 200, 35, WHITE);
                DrawText("Back", 315, 525, 35, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade -= 0.1f;
    }
}

void FadeOptionsMenu(){
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
                DrawMainMenu();
                DrawText("Options", 50, 45, 180, MenuTextColour);
                DrawRectangle(550, 635, 200, 35, WHITE);
                DrawRectangle(300, 635, 200, 35, WHITE);
                DrawRectangle(50, 300, 250, 50, WHITE);
                if(MusicOn == true){
                    DrawText("Music: On", 55, 300, 50, MenuTextColour);
                }else{
                    DrawText("Music: Off", 55, 300, 50, MenuTextColour);
                }
                DrawRectangle(50, 370, 500, 50, WHITE);
                DrawRectangle(50, 440, 500, 50, WHITE);
                if(TileSetChoice == 0){
                    DrawText("TileSet: Original", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 1){
                    DrawText("TileSet: Gameboy", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 2){
                    DrawText("TileSet: Modern", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 3){
                    DrawText("TileSet: P5", 55, 440, 50, MenuTextColour);
                }
                if(SoundEffectsOn == true){
                    DrawText("Sound Effects: On", 55, 370, 50, MenuTextColour);
                }else{
                    DrawText("Sound Effects: Off", 55, 370, 50, MenuTextColour);
                }
                DrawRectangle(50, 510, 450, 50, WHITE);
                if(IsWindowFullscreen()){
                    DrawText("FullScreen: On", 55, 515, 50, MenuTextColour);
                }else{
                    DrawText("FullScreen: Off", 55, 515, 50, MenuTextColour);
                }
                DrawText("Back", 565, 635, 35, MenuTextColour);
                DrawText("Stats", 305, 635, 35, MenuTextColour);
                DrawRectangle(50, 235, 400, 50, WHITE);
                if(BoardersOn == true){
                    DrawText("Boarders: On", 55, 240, 50, MenuTextColour);
                }else{
                    DrawText("Boarders: Off", 55, 240, 50, MenuTextColour);
                }
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade -= 0.1f;
    }
}

void FadeStatsMenu(){
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
                DrawMainMenu();
                DrawText("StatsMenu", 50, 50, 100, MenuTextColour);
                DrawRectangle(300, 635, 200, 35, WHITE);
                DrawRectangle(550, 635, 200, 35, WHITE);
                DrawText(FormatText("Total Time Played: %02i:%02i.%02i", TotalPlayTime[3], TotalPlayTime[2], TotalPlayTime[1]), 50, 150, 40, MenuTextColour);
                DrawText(FormatText("Total Deaths: %02i", TotalDeaths), 50, 200, 40, MenuTextColour);
                DrawText(FormatText("Total Plays: %02i", TotalPlays), 50, 250, 40, MenuTextColour);
                DrawText(FormatText("Total Game Completions: %02i", TotalFinnished), 50, 300, 40, MenuTextColour);
                DrawText(FormatText("Worst Time: %02i:%02i.%02i", WorstTime[3], WorstTime[2], WorstTime[1]), 50, 350, 40, MenuTextColour);
                DrawText(FormatText("Least Amount Of Deaths: %02i", LeastDeathsInPlayThough), 50, 400, 40, MenuTextColour);
                DrawText(FormatText("Most Deaths In Game Compleion: %02i", MostDeathsInPlayThough), 50, 450, 40, MenuTextColour);
                if(HardModeBeaten == true){
                    DrawText("Game Beaten Of Hard Mode: Yes", 50, 500, 40, MenuTextColour);
                }else{
                    DrawText("Game Beaten Of Hard Mode: No", 50, 500, 40, MenuTextColour);
                }
                DrawText(FormatText("Best Time: %02i:%02i.%02i", BestTime[3], BestTime[2], BestTime[1]), 50, 550, 40, MenuTextColour);
                DrawText("Back", 565, 635, 35, MenuTextColour);
                DrawText("Clear Save", 305, 635, 35, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
            DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK, fade));
        EndDrawing();
        fade -= 0.1f;
    }
}

void StatsMenu(){
	if(IsGamepadAvailable(1)){
		MenuControllerMode = true;
	}
    bool OptionsMenuFlag = false;
    SaveSave();
    ButtonNum = 2;
	CurserPos = 0;
    FadeOut();
    FadeStatsMenu();
    while(1){
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
        virtualMouse = ClampValue(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ gameScreenWidth, gameScreenHeight });
        if(MenuControllerMode == false){
            if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
                MenuControllerMode = true;
                CurserPos = ButtonNum;
            }
            if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
                MenuControllerMode = true;
                CurserPos = ButtonNum;
            }
        }
        if(MenuControllerMode == true){
            if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)||IsGamepadButtonPressed(GAMEPAD_PLAYER1,GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
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
            if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
                MenuControllerMode = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                if(CurserPos + 1 <= ButtonNum - 1){
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
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
            OptionsMenuFlag = true;
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
        ClearBKG();
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("StatsMenu", 50, 50, 100, MenuTextColour);
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 0){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 0;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ClearSaveFile();
                    }
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ClearSaveFile();
                    }
                }else{
                    if(CurserPos == 0){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(300, 635, 200, 35, WHITE);
                }
                if(((int)virtualMouse.x > 550) && ((int)virtualMouse.x < 750) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 1){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 1;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        OptionsMenuFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        OptionsMenuFlag = true;
                    }
                }else{
                    if(CurserPos == 1){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(550, 635, 200, 35, WHITE);
                }
                DrawText(FormatText("Total Time Played: %02i:%02i.%02i", TotalPlayTime[3], TotalPlayTime[2], TotalPlayTime[1]), 50, 150, 40, MenuTextColour);
                DrawText(FormatText("Total Deaths: %02i", TotalDeaths), 50, 200, 40, MenuTextColour);
                DrawText(FormatText("Total Plays: %02i", TotalPlays), 50, 250, 40, MenuTextColour);
                DrawText(FormatText("Total Game Completions: %02i", TotalFinnished), 50, 300, 40, MenuTextColour);
                DrawText(FormatText("Worst Time: %02i:%02i.%02i", WorstTime[3], WorstTime[2], WorstTime[1]), 50, 350, 40, MenuTextColour);
                DrawText(FormatText("Least Amount Of Deaths: %02i", LeastDeathsInPlayThough), 50, 400, 40, MenuTextColour);
                DrawText(FormatText("Most Deaths In Game Compleion: %02i", MostDeathsInPlayThough), 50, 450, 40, MenuTextColour);
                if(HardModeBeaten == true){
                    DrawText("Game Beaten Of Hard Mode: Yes", 50, 500, 40, MenuTextColour);
                }else{
                    DrawText("Game Beaten Of Hard Mode: No", 50, 500, 40, MenuTextColour);
                }
                DrawText(FormatText("Best Time: %02i:%02i.%02i", BestTime[3], BestTime[2], BestTime[1]), 50, 550, 40, MenuTextColour);
                DrawText("Back", 565, 635, 35, MenuTextColour);
                DrawText("Clear Save", 305, 635, 35, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        if(OptionsMenuFlag == true){
            OptionsMenuFlag = false;
            ButtonNum = 7;
            break;
        }
    }
}

void ModeSelect(){
    bool MainMenuFlag = false;
    bool NormalModeFlag = false;
    bool HardModeFlag = false;
    ButtonNum = 3;
	CurserPos = 0;
    StartGame = false;
    FadeOut();
    ModeSelectFade();
    while(1){
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
        virtualMouse = ClampValue(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ gameScreenWidth, gameScreenHeight });
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
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                if(CurserPos > 0){
                    CurserPos-=1;
                }else{
                    CurserPos = ButtonNum-1;
                }
            }else if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                if(CurserPos + 1 <= ButtonNum - 1){
                    CurserPos+=1;
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
			ClearBKG();
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("Maze", 160, 50, 180, MenuTextColour);
                DrawText("Walker", 90, 190, 180, MenuTextColour);
                DrawText("Walk Your Way To Freedom", 50, 350, 50, MenuTextColour);
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 435) && ((int)virtualMouse.y < 470)){
                    if(CurserPos != 0){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 0;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 430, 210, 45, BLACK);
                    DrawRectangle(300, 435, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        NormalModeFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(295, 430, 210, 45, BLACK);
                    DrawRectangle(300, 435, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        NormalModeFlag = true;
                    }
                }else{
                    if(CurserPos == 0){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(300, 435, 200, 35, WHITE);
                }
                DrawText("Normal", 315, 435, 35, MenuTextColour);
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 480) && ((int)virtualMouse.y < 515)){
                    if(CurserPos != 1){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 1;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 475, 210, 45, BLACK);
                    DrawRectangle(300, 480, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        HardModeFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(295, 475, 210, 45, BLACK);
                    DrawRectangle(300, 480, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        HardModeFlag = true;
                    }
                }else{
					if(CurserPos == 1){
						CurserPos = ButtonNum;
					}
                    DrawRectangle(300, 480, 200, 35, WHITE);
                }
                DrawText("Hard", 315, 480, 35, MenuTextColour);
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 525) && ((int)virtualMouse.y < 560)){
                    if(CurserPos != 2){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 2;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 520, 210, 45, BLACK);
                    DrawRectangle(300, 525, 200, 35, WHITE);
                    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MainMenuFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 2){
                    DrawRectangle(295, 520, 210, 45, BLACK);
                    DrawRectangle(300, 525, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MainMenuFlag = true;
                    }
                }else{
                    if(CurserPos == 2){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(300, 525, 200, 35, WHITE);
                } 
                DrawText("Back", 315, 525, 35, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
            MainMenuFlag = true;
        }
        if(MainMenuFlag == true){
            MainMenuFlag = false;
            break;
        }
        if(NormalModeFlag == true){
            NormalModeFlag = false;
            CurrentLevel = StartingLevel;
            Deaths = 0;
            Timer[0] = 0;
            Timer[1] = 0;
            Timer[2] = 0;
            Timer[3] = 0;
            SaveSave();
            HardMode = false;
            TotalPlays++;
            Game();
        }
        if(HardModeFlag == true){
            HardModeFlag = false;
            CurrentLevel = StartingLevel;
            Deaths = 0;
            Timer[0] = 0;
            Timer[1] = 0;
            Timer[2] = 0;
            Timer[3] = 0;
            SaveSave();
            HardMode = true;
            TotalPlays++;
            Game();
        }
    }
}

void OptionMenu(){
    bool MainMenuFlag = false;
    bool StatsMenuFlag = false;
    ButtonNum = 7;
    FadeOut();
    FadeOptionsMenu();
    while(1){
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
        virtualMouse = ClampValue(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ gameScreenWidth, gameScreenHeight });
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
			if(CurserPos == 6){
				if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)||IsGamepadButtonPressed(GAMEPAD_PLAYER1,GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
					CurserPos--;
				}
			}
			if(CurserPos == 5){
				if(IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)||IsGamepadButtonPressed(GAMEPAD_PLAYER1,GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
					CurserPos++;
				}
			}
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
        ClearBKG();
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("Options", 50, 45, 180, MenuTextColour);
				//Stats menu
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 5){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 5;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        StatsMenuFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 5){
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        StatsMenuFlag = true;
                    }
                }else{
                    if(CurserPos == 5){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(300, 635, 200, 35, WHITE);
                } 
				//Boarders
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<450)&&((int)virtualMouse.y>235)&&((int)virtualMouse.y<285)){
                    if(CurserPos != 0){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 0;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        BoardersOn=!BoardersOn;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 234, 410, 60, BLACK);
                    DrawRectangle(50, 240, 400, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(45, 235, 410, 60, BLACK);
                    DrawRectangle(50, 240, 400, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        BoardersOn=!BoardersOn;
                    }
                }else{
                    if(CurserPos == 0){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(50, 235, 400, 50, WHITE);
                }
                if(BoardersOn == true){
                    DrawText("Boarders: On", 55, 240, 50, MenuTextColour);
                }else{
                    DrawText("Boarders: Off", 55, 240, 50, MenuTextColour);
                }
				//Back
                if(((int)virtualMouse.x > 550) && ((int)virtualMouse.x < 750) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 6){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 6;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MainMenuFlag = true;
                    }
                }else if(MenuControllerMode == true && CurserPos == 6){
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MainMenuFlag = true;
                    }
                }else{
                    if(CurserPos == 6){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(550, 635, 200, 35, WHITE);
                } 
				//Music on/ off
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<300)&&((int)virtualMouse.y>300)&&((int)virtualMouse.y<350)){
                    if(CurserPos != 1){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 1;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MusicOn=!MusicOn;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 295, 260, 60, BLACK);
                    DrawRectangle(50, 300, 250, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(45, 295, 260, 60, BLACK);
                    DrawRectangle(50, 300, 250, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        MusicOn=!MusicOn;
                    }
                }else{
                    if(CurserPos == 1){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(50, 300, 250, 50, WHITE);
                }
                if(MusicOn == true){
                    DrawText("Music: On", 55, 300, 50, MenuTextColour);
                }else{
                    DrawText("Music: Off", 55, 300, 50, MenuTextColour);
                }
				//Sound effects on/ off
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<550)&&((int)virtualMouse.y>370)&&((int)virtualMouse.y<410)){
                    if(CurserPos != 2){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 2;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        SoundEffectsOn=!SoundEffectsOn;
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }                
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 365, 510, 60, BLACK);
                    DrawRectangle(50, 370, 500, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 2){
                    DrawRectangle(45, 365, 510, 60, BLACK);
                    DrawRectangle(50, 370, 500, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        SoundEffectsOn=!SoundEffectsOn;
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }     
                    }
                }else{
                    if(CurserPos == 2){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(50, 370, 500, 50, WHITE);
                }
				//Tileset
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<550)&&((int)virtualMouse.y>440)&&((int)virtualMouse.y<490)){
                    if(CurserPos != 3){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 3;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        TileSetChoice++;
                        if(TileSetChoice > 3){
                            TileSetChoice = 0;
                        }
                        intTextures();
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }                
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 435, 510, 60, BLACK);
                    DrawRectangle(50, 440, 500, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 3){
                    DrawRectangle(45, 435, 510, 60, BLACK);
                    DrawRectangle(50, 440, 500, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        TileSetChoice++;
                        if(TileSetChoice > 3){
                            TileSetChoice = 0;
                        }
                        intTextures();
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }     
                    }
                }else{
                    if(CurserPos == 3){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(50, 440, 500, 50, WHITE);
                }
                if(TileSetChoice == 0){
                    DrawText("TileSet: Original", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 1){
                    DrawText("TileSet: Gameboy", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 2){
                    DrawText("TileSet: Modern", 55, 440, 50, MenuTextColour);
                }else if(TileSetChoice == 3){
                    DrawText("TileSet: P5", 55, 440, 50, MenuTextColour);
                }
                if(SoundEffectsOn == true){
                    DrawText("Sound Effects: On", 55, 370, 50, MenuTextColour);
                }else{
                    DrawText("Sound Effects: Off", 55, 370, 50, MenuTextColour);
                }
				//Fullscreen
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<500)&&((int)virtualMouse.y>510)&&((int)virtualMouse.y<560)){
                    if(CurserPos != 4){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 4;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
						if(!IsWindowFullscreen()){
							SetWindowSize(GetScreenWidth(),GetScreenHeight());
						}
                        ToggleFullscreen();
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 505, 460, 60, BLACK);
                    DrawRectangle(50, 510, 450, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 4){
                    DrawRectangle(45, 505, 460, 60, BLACK);
                    DrawRectangle(50, 510, 450, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ToggleFullscreen();
                    }
                }else{
                    if(CurserPos == 4){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(50, 510, 450, 50, WHITE);
                }
                if(IsWindowFullscreen()){
                    DrawText("FullScreen: On", 55, 515, 50, MenuTextColour);
                }else{
                    DrawText("FullScreen: Off", 55, 515, 50, MenuTextColour);
                }
                DrawText("Back", 565, 635, 35, MenuTextColour);
                DrawText("Stats", 305, 635, 35, MenuTextColour);
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
            MainMenuFlag = true;
        }
        if(StatsMenuFlag == true){
            StatsMenuFlag = false;
            ButtonNum = 2;
            StatsMenu();
            FadeOut();
            FadeOptionsMenu();
        }
        if(MainMenuFlag == true){
            MainMenuFlag = false;
			SaveSave();
            break;
        }
    }
}

void MainMenu(){
    bool ModeSelectFlag = false;
    bool OptionsMenuFlag = false;
    bool ExitFlag = false;
    ButtonNum = 4;
    Vector2 mouse = GetMousePosition();
    Vector2 virtualMouse = { 0 };
    virtualMouse.x = (mouse.x - (GetScreenWidth() - (gameScreenWidth*scale))*0.5f)/scale;
    virtualMouse.y = (mouse.y - (GetScreenHeight() - (gameScreenHeight*scale))*0.5f)/scale;
    virtualMouse = ClampValue(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ gameScreenWidth, gameScreenHeight });
    bool ContinueExists = false;
    if(FileExists("storage.data")){
        CurrentLevel = LoadStorageValue(0);
        if(CurrentLevel == 0){
            ButtonNum = 3;
            ContinueExists = false;
        }else{
            ContinueExists = true;
            ButtonNum = 4;
        }        
    }else{
        ButtonNum = 3;
    }
    if(MenuControllerMode == false){
        if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP)){
            MenuControllerMode = true;CurserPos = ButtonNum;
        }
        if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
            MenuControllerMode = true;CurserPos = ButtonNum;
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
    DrawMainMenu();
    DrawText("Maze", 160, 50, 180, MenuTextColour);
    DrawText("Walker", 90, 190, 180, MenuTextColour);
    DrawText("Walk Your Way To Freedom", 50, 350, 50, MenuTextColour);
    if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 435) && ((int)virtualMouse.y < 470)){
        if(CurserPos != 0){
            if(SoundEffectsOn == true){
                PlaySound(MenuChange);
            }
            CurserPos = 0;
        }
        MenuControllerMode = false;
        DrawRectangle(295, 430, 210, 45, BLACK);
        DrawRectangle(300, 435, 200, 35, WHITE);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            if(SoundEffectsOn == true){
                PlaySound(MenuSelect);
            }
            ModeSelectFlag = true;
        }
    }else if(MenuControllerMode == true && CurserPos == 0){
        DrawRectangle(295, 430, 210, 45, BLACK);
        DrawRectangle(300, 435, 200, 35, WHITE);
        if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
            if(SoundEffectsOn == true){
                PlaySound(MenuSelect);
            }
            ModeSelectFlag = true;
        }
    }else{
        if(CurserPos == 0){
            CurserPos = ButtonNum;
        }
        DrawRectangle(300, 435, 200, 35, WHITE);
    }
    DrawText("New Game", 315, 435, 35, MenuTextColour);
    if(ContinueExists == true){
        if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 475) && ((int)virtualMouse.y < 510)){
            MenuControllerMode = false;
            if(CurserPos != 1){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 1;
            }
            DrawRectangle(295, 470, 210, 45, BLACK);
            DrawRectangle(300, 475, 200, 35, WHITE);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                StartGame = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
            }
        }else if(MenuControllerMode == true && CurserPos == 1){
            DrawRectangle(295, 470, 210, 45, BLACK);
            DrawRectangle(300, 475, 200, 35, WHITE);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                StartGame = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
            }
        }else{
            if(CurserPos == 1){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300, 475, 200, 35, WHITE);
        } 
        if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 515) && ((int)virtualMouse.y < 550)){
            MenuControllerMode = false;
            if(CurserPos != 2){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 2;
            }
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                OptionsMenuFlag = true;
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ButtonNum = 6;
                CurserPos = 0;
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                OptionsMenuFlag = true;
            }
        }else{
            if(CurserPos == 2){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300, 515, 200, 35, WHITE);
        } 
        if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 555) && ((int)virtualMouse.y < 590)){
            MenuControllerMode = false;
            if(CurserPos != 3){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 3;
            }
            DrawRectangle(295, 550, 210, 45, BLACK);
            DrawRectangle(300, 555, 200, 35, WHITE);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                ExitFlag = true;
            }
        }else if(MenuControllerMode == true && CurserPos == 3){
            DrawRectangle(295, 550, 210, 45, BLACK);
            DrawRectangle(300, 555, 200, 35, WHITE);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                ExitFlag = true;
            }
        }else{
            if(CurserPos == 3){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300, 555, 200, 35, WHITE);
        } 
        DrawText("Continue", 315, 475, 35, MenuTextColour);
        DrawText("Options", 315, 515, 35, MenuTextColour);
        DrawText("Exit Game", 315, 555, 35, MenuTextColour);
    }else{
        if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 475) && ((int)virtualMouse.y < 510)){
            MenuControllerMode = false;
            if(CurserPos != 1){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 1;
            }
            DrawRectangle(295, 470, 210, 45, BLACK);
            DrawRectangle(300, 475, 200, 35, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                OptionsMenuFlag = true;
            }
        }else if(MenuControllerMode == true && CurserPos == 1){
            DrawRectangle(295, 470, 210, 45, BLACK);
            DrawRectangle(300, 475, 200, 35, WHITE);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                OptionsMenuFlag = true;
            }
        }else{
            if(CurserPos == 1){
            CurserPos = ButtonNum;
            }
            DrawRectangle(300, 475, 200, 35, WHITE);
        } 
        if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 515) && ((int)virtualMouse.y < 550)){
            MenuControllerMode = false;
            if(CurserPos != 2){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                ButtonNum = 6;
                CurserPos = 2;
            }
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                ExitFlag = true;
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ExitFlag = true;
            }
        }else{
            if(CurserPos == 2){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300, 515, 200, 35, WHITE);
        } 
        DrawText("Options", 315, 475, 35, MenuTextColour);
        DrawText("ExitGame", 315, 515, 35, MenuTextColour);
    }
    DrawText("v", 45, 655, 25, BLACK);
    DrawText(VersionNum, 60, 655, 25, BLACK);
    DrawText("Made by THATGUYtm", 600, 660, 15, BLACK);
    if(OptionsMenuFlag == true){
        OptionsMenuFlag = false;
        ButtonNum = 7;
        CurserPos = 0;
        OptionMenu();
        FadeOut();
        BeginGame();
    }
    if(ModeSelectFlag == true){
        ModeSelectFlag = false;
		ButtonNum = 3;
		CurserPos = 0;
        ModeSelect();
        FadeOut();
        BeginGame();
    }
    if(ExitFlag == true){
        ExitFlag = false;
        ExitGame();
    }
}
