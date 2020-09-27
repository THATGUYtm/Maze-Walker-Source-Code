unsigned int CurserPos = 0;
unsigned int ButtonNum = 4;

void MainMenuSection();

void StatsMenu(){
    SaveSave();
    ButtonNum = 1;
    for(int i = 0; i < 1; i++){
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    while(1){
        UpdateCameraCenter();
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
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawTextureRec(TileSet, (Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){0 + GameScreenStart[0],0}, WHITE);
                DrawText("StatsMenu", 50 + GameScreenStart[0], 50 + GameScreenStart[1], 100, BLACK);
            EndMode2D();
            if((GetMouseX() > 550 + GameScreenStart[0]) && (GetMouseX() < 750 + GameScreenStart[0]) && (GetMouseY() > 635) && (GetMouseY() < 670)){
                if(CurserPos != 0){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 0;
                }
                MenuControllerMode = false;
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, GREEN);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    break;
                }
            }else if(MenuControllerMode == true && CurserPos == 0){
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, GREEN);
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
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, WHITE);
            }
            DrawText(FormatText("Total Time Played: %02i:%02i.%02i", TotalPlayTime[3], TotalPlayTime[2], TotalPlayTime[1]), 70 + GameScreenStart[0], 150, 35, BLACK);
            DrawText(FormatText("Total Deaths: %02i", TotalDeaths), 70 + GameScreenStart[0], 200, 35, BLACK);
            DrawText(FormatText("Total Plays: %02i", TotalPlays), 70 + GameScreenStart[0], 250, 35, BLACK);
            DrawText(FormatText("Total Game Completions: %02i", TotalFinnished), 70 + GameScreenStart[0], 300, 35, BLACK);
            DrawText(FormatText("Worst Time: %02i:%02i.%02i", WorstTime[3], WorstTime[2], WorstTime[1]), 70 + GameScreenStart[0], 350, 35, BLACK);
            DrawText(FormatText("Least Amount Of Deaths: %02i", LeastDeathsInPlayThough), 70 + GameScreenStart[0], 400, 35, BLACK);
            DrawText(FormatText("Most Deaths In Game Compleion: %02i", MostDeathsInPlayThough), 70 + GameScreenStart[0], 450, 35, BLACK);
            if(HardModeBeaten == true){DrawText("Game Beaten Of Hard Mode: Yes", 70 + GameScreenStart[0], 500, 35, BLACK);
            }else{DrawText("Game Beaten Of Hard Mode: No", 70 + GameScreenStart[0], 500, 35, BLACK);}
            DrawText(FormatText("Best Time: %02i:%02i.%02i", BestTime[3], BestTime[2], BestTime[1]), 70 + GameScreenStart[0], 550, 35, BLACK);
            DrawText("Back", 565 + GameScreenStart[0], 635, 35, BLACK);
        EndDrawing();
    }
}

void ModeSelect(){
    ButtonNum = 3;
    StartGame = false;
    for(int i = 0; i < 1; i++){
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    while(1){
        UpdateCameraCenter();
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
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawTextureRec(TileSet, (Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){0 + GameScreenStart[0],0}, WHITE);
                DrawText("Maze", 160 + GameScreenStart[0], 50, 180, BLACK);
                DrawText("Walker", 90 + GameScreenStart[0], 190, 180, BLACK);
                DrawText("Walk Your Way To Freedom", 50 + GameScreenStart[0], 350, 50, BLACK);
            EndMode2D();
            if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 435) && (GetMouseY() < 470)){
                if(CurserPos != 0){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 0;
                }
                MenuControllerMode = false;
                DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, GREEN);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){PlaySound(MenuSelect);}
                    CurrentLevel = 1;
                    Timer[0] = 0;
                    Timer[1] = 0;
                    Timer[2] = 0;
                    Timer[3] = 0;
                    SaveSave();
                    HardMode = false;
                    Game();
                }
            }else if(MenuControllerMode == true && CurserPos == 0){
                DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){PlaySound(MenuSelect);}
                    CurrentLevel = 1;
                    Timer[0] = 0;
                    Timer[1] = 0;
                    Timer[2] = 0;
                    Timer[3] = 0;
                    SaveSave();
                    HardMode = false;
                    Game();
                }
            }else{
                if(CurserPos == 0){CurserPos = ButtonNum;}
                DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, WHITE);
            }
            DrawText("Normal", 315 + GameScreenStart[0], 435, 35, BLACK);
            if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 480) && (GetMouseY() < 515)){
                if(CurserPos != 1){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 1;
                }
                MenuControllerMode = false;
                DrawRectangle(300 + GameScreenStart[0], 480, 200, 35, GREEN);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){PlaySound(MenuSelect);}
                    CurrentLevel = 1;
                    Timer[0] = 0;
                    Timer[1] = 0;
                    Timer[2] = 0;
                    Timer[3] = 0;
                    SaveSave();
                    HardMode = true;
                    Game();
                }
            }else if(MenuControllerMode == true && CurserPos == 1){
                DrawRectangle(300 + GameScreenStart[0], 480, 200, 35, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){PlaySound(MenuSelect);}
                    CurrentLevel = 1;
                    Timer[0] = 0;
                    Timer[1] = 0;
                    Timer[2] = 0;
                    Timer[3] = 0;
                    SaveSave();
                    HardMode = true;
                    Game();
                }
            }else{
                if(CurserPos == 1){CurserPos = ButtonNum;}
                DrawRectangle(300 + GameScreenStart[0], 480, 200, 35, WHITE);
            }
            DrawText("Hard", 315 + GameScreenStart[0], 480, 35, BLACK);
            if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 525) && (GetMouseY() < 560)){
                if(CurserPos != 2){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 2;
                }
                MenuControllerMode = false;
                DrawRectangle(300 + GameScreenStart[0], 525, 200, 35, GREEN);
                if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    BeginDrawing();
                        ClearBackground(BLACK);
                    EndDrawing();
                    MainMenuSection();
                    Game();
                }
            }else if(MenuControllerMode == true && CurserPos == 2){
                DrawRectangle(300 + GameScreenStart[0], 525, 200, 35, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    BeginDrawing();
                        ClearBackground(BLACK);
                    EndDrawing();
                    MainMenuSection();
                    Game();
                }
            }else{
                if(CurserPos == 2){
                    CurserPos = ButtonNum;
                }
                DrawRectangle(300 + GameScreenStart[0], 525, 200, 35, WHITE);
            } 
            DrawText("Back", 315 + GameScreenStart[0], 525, 35, BLACK);
        EndDrawing();
    }
}

void OptionMenu(){
    ButtonNum = 4;
    for(int i = 0; i < 1; i++){
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    while(1){
        UpdateCameraCenter();
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
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawTextureRec(TileSet, (Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){0 + GameScreenStart[0],0}, WHITE);
                DrawText("Options", 50 + GameScreenStart[0], 50 + GameScreenStart[1], 180, BLACK);
            EndMode2D();
            if((GetMouseX() > 550 + GameScreenStart[0]) && (GetMouseX() < 750 + GameScreenStart[0]) && (GetMouseY() > 635) && (GetMouseY() < 670)){
                if(CurserPos != 3){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 3;
                }
                MenuControllerMode = false;
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, GREEN);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    break;
                }
            }else if(MenuControllerMode == true && CurserPos == 3){
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    break;
                }
            }else{
                if(CurserPos == 3){
                    CurserPos = ButtonNum;
                }
                DrawRectangle(550 + GameScreenStart[0], 635, 200, 35, WHITE);
            } 
            if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 635) && (GetMouseY() < 670)){
                if(CurserPos != 2){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 2;
                }
                MenuControllerMode = false;
                DrawRectangle(300 + GameScreenStart[0], 635, 200, 35, GREEN);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    StatsMenu();
                }
            }else if(MenuControllerMode == true && CurserPos == 2){
                DrawRectangle(300 + GameScreenStart[0], 635, 200, 35, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    StatsMenu();
                }
            }else{
                if(CurserPos == 2){
                    CurserPos = ButtonNum;
                }
                DrawRectangle(300 + GameScreenStart[0], 635, 200, 35, WHITE);
            } 
            if((GetMouseX()>50 + GameScreenStart[0])&&(GetMouseX()<300 + GameScreenStart[0])&&(GetMouseY()>300)&&(GetMouseY()<350)){
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
                    MusicOn=!MusicOn;
                }
                MenuControllerMode = false;
                DrawRectangle(50 + GameScreenStart[0], 300, 250, 50, GREEN);
            }else if(MenuControllerMode == true && CurserPos == 0){
                DrawRectangle(50 + GameScreenStart[0], 300, 250, 50, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }
                    MusicOn=!MusicOn;
                }
            }else{
                if(CurserPos == 0){
                    CurserPos = ButtonNum;
                }
                DrawRectangle(50 + GameScreenStart[0], 300, 250, 50, WHITE);
            }
            if(MusicOn == true){
                DrawText("Music: On", 55 + GameScreenStart[0], 300, 50, BLACK);
            }else{
                DrawText("Music: Off", 55 + GameScreenStart[0], 300, 50, BLACK);
            }
            if((GetMouseX()>50)&&(GetMouseX()<850)&&(GetMouseY()>370)&&(GetMouseY()<410)){
                if(CurserPos != 1){
                    if(SoundEffectsOn == true){
                        PlaySound(MenuChange);
                    }
                    CurserPos = 1;
                }
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    SoundEffectsOn=!SoundEffectsOn;
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }                
                }
                MenuControllerMode = false;
                DrawRectangle(50 + GameScreenStart[0], 370, 500, 50, GREEN);
            }else if(MenuControllerMode == true && CurserPos == 1){
                DrawRectangle(50 + GameScreenStart[0], 370, 500, 50, GREEN);
                if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                    SoundEffectsOn=!SoundEffectsOn;
                    if(SoundEffectsOn == true){
                        PlaySound(MenuSelect);
                    }     
                }
            }else{
                if(CurserPos == 1){
                    CurserPos = ButtonNum;
                }
                DrawRectangle(50 + GameScreenStart[0], 370, 500, 50, WHITE);
            }
            if(SoundEffectsOn == true){
                DrawText("Sound Effects: On", 55 + GameScreenStart[0], 370, 50, BLACK);
            }else{
                DrawText("Sound Effects: Off", 55 + GameScreenStart[0], 370, 50, BLACK);
            }
            DrawText("Back", 565 + GameScreenStart[0], 635, 35, BLACK);
            DrawText("Stats", 305 + GameScreenStart[0], 635, 35, BLACK);
        EndDrawing();
    }
}

void MainMenu(){
    ButtonNum = 4;
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
    ClearBackground(BLACK);
    BeginMode2D(camera);
        DrawTextureRec(TileSet, (Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){0 + GameScreenStart[0],0}, WHITE);
        DrawText("Maze", 160 + GameScreenStart[0], 50, 180, BLACK);
        DrawText("Walker", 90 + GameScreenStart[0], 190, 180, BLACK);
        DrawText("Walk Your Way To Freedom", 50 + GameScreenStart[0], 350, 50, BLACK);
    EndMode2D();
    bool ContinueExists = false;
    if(FileExists("storage.data")){
        ContinueExists = true;
        ButtonNum = 4;
    }else{
        ButtonNum = 3;
    }
    if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 435) && (GetMouseY() < 470)){
        if(CurserPos != 0){
            if(SoundEffectsOn == true){
                PlaySound(MenuChange);
            }
            CurserPos = 0;
        }
        MenuControllerMode = false;
        DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, GREEN);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            if(SoundEffectsOn == true){
                PlaySound(MenuSelect);
            }
            ModeSelect();
            ClearBackground(BLACK);
        }
    }else if(MenuControllerMode == true && CurserPos == 0){
        DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, GREEN);
        if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
            if(SoundEffectsOn == true){
                PlaySound(MenuSelect);
            }
            ModeSelect();
            ClearBackground(BLACK);
        }
    }else{
        if(CurserPos == 0){
            CurserPos = ButtonNum;
        }
        DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, WHITE);
    }
    DrawText("New Game", 315 + GameScreenStart[0], 435, 35, BLACK);
    if(ContinueExists == true){
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 475) && (GetMouseY() < 510)){
            MenuControllerMode = false;
            if(CurserPos != 1){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 1;
            }
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                StartGame = true;
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
            }
        }else if(MenuControllerMode == true && CurserPos == 1){
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
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
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, WHITE);
        } 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 515) && (GetMouseY() < 550)){
            MenuControllerMode = false;
            if(CurserPos != 2){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 2;
            }
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                OptionMenu();
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ButtonNum = 3;
                CurserPos = 0;
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                OptionMenu();
            }
        }else{
            if(CurserPos == 2){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, WHITE);
        } 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 555) && (GetMouseY() < 590)){
            MenuControllerMode = false;
            if(CurserPos != 3){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 3;
            }
            DrawRectangle(300 + GameScreenStart[0], 555, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                ExitGame();
            }
        }else if(MenuControllerMode == true && CurserPos == 3){
            DrawRectangle(300 + GameScreenStart[0], 555, 200, 35, GREEN);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                if(SoundEffectsOn == true){
                    PlaySound(MenuSelect);
                }
                ExitGame();
            }
        }else{
            if(CurserPos == 3){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300 + GameScreenStart[0], 555, 200, 35, WHITE);
        } 
        DrawText("Continue", 315 + GameScreenStart[0], 475, 35, BLACK);
        DrawText("Options", 315 + GameScreenStart[0], 515, 35, BLACK);
        DrawText("Exit Game", 315 + GameScreenStart[0], 555, 35, BLACK);
    }else{
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 475) && (GetMouseY() < 510)){
            MenuControllerMode = false;
            if(CurserPos != 1){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 1;
            }
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                OptionMenu();
            }
        }else if(MenuControllerMode == true && CurserPos == 1){
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ButtonNum = 3;
                CurserPos = 0;
                OptionMenu();
            }
        }else{
            if(CurserPos == 1){
            CurserPos = ButtonNum;
            }
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, WHITE);
        } 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 515) && (GetMouseY() < 550)){
            MenuControllerMode = false;
            if(CurserPos != 2){
                if(SoundEffectsOn == true){
                    PlaySound(MenuChange);
                }
                CurserPos = 2;
            }
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                ExitGame();
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ExitGame();
            }
        }else{
            if(CurserPos == 2){
                CurserPos = ButtonNum;
            }
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, WHITE);
        } 
        DrawText("Options", 315 + GameScreenStart[0], 475, 35, BLACK);
        DrawText("ExitGame", 315 + GameScreenStart[0], 515, 35, BLACK);
    }
}
