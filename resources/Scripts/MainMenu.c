int CurserPos = 0;
unsigned int ButtonNum = 4;

void MainMenuSection();

void StatsMenu(){
    SaveSave();
    ButtonNum = 1;
    for(int i = 0; i < 1; i++){
        BeginDrawing();
        ClearBackground(MenuTextColour);
        EndDrawing();
    }
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
        if(IsKeyPressed(KEY_ESCAPE) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
            ButtonNum = 5;
            break;
        }
        scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);
        BeginDrawing();
        ClearBackground(BLACK);
            BeginTextureMode(target);
                DrawMainMenu();
                DrawText("StatsMenu", 50, 50, 100, MenuTextColour);
                if(((int)virtualMouse.x > 550) && ((int)virtualMouse.x < 750) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 0){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 0;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ButtonNum = 5;
                        break;
                    }
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ButtonNum = 5;
                        break;
                    }
                }else{
                    if(CurserPos == 0){
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
            EndTextureMode();
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },(Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,(float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
}

void ModeSelect(){
    ButtonNum = 3;
    StartGame = false;
    for(int i = 0; i < 1; i++){
        BeginDrawing();
        ClearBackground(MenuTextColour);
        EndDrawing();
    }
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
                        CurrentLevel = StartingLevel;
                        Timer[0] = 0;
                        Timer[1] = 0;
                        Timer[2] = 0;
                        Timer[3] = 0;
                        SaveSave();
                        HardMode = false;
                        Game();
                    }
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(295, 430, 210, 45, BLACK);
                    DrawRectangle(300, 435, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        CurrentLevel = StartingLevel;
                        Timer[0] = 0;
                        Timer[1] = 0;
                        Timer[2] = 0;
                        Timer[3] = 0;
                        SaveSave();
                        HardMode = false;
                        Game();
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
                        CurrentLevel = StartingLevel;
                        Timer[0] = 0;
                        Timer[1] = 0;
                        Timer[2] = 0;
                        Timer[3] = 0;
                        SaveSave();
                        HardMode = true;
                        Game();
                    }
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(295, 475, 210, 45, BLACK);
                    DrawRectangle(300, 480, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        CurrentLevel = StartingLevel;
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
                        BeginDrawing();
                            ClearBackground(BLACK);
                        EndDrawing();
                        MainMenuSection();
                        Game();
                    }
                }else if(MenuControllerMode == true && CurserPos == 2){
                    DrawRectangle(295, 520, 210, 45, BLACK);
                    DrawRectangle(300, 525, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        BeginDrawing();
                            ClearBackground(MenuTextColour);
                        EndDrawing();
                        MainMenuSection();
                        Game();
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
            BeginDrawing();
                ClearBackground(MenuTextColour);
            EndDrawing();
            MainMenuSection();
            Game();
        }
    }
}

void OptionMenu(){
    ButtonNum = 6;
    BeginDrawing();
        ClearBackground(BLACK);
    EndDrawing();
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
                DrawMainMenu();
                DrawText("Options", 50, 50, 180, MenuTextColour);
                if(((int)virtualMouse.x > 550) && ((int)virtualMouse.x < 750) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 5){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 5;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        break;
                    }
                }else if(MenuControllerMode == true && CurserPos == 5){
                    DrawRectangle(545, 630, 210, 45, BLACK);
                    DrawRectangle(550, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        break;
                    }
                }else{
                    if(CurserPos == 5){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(550, 635, 200, 35, WHITE);
                } 
                if(((int)virtualMouse.x > 300) && ((int)virtualMouse.x < 500) && ((int)virtualMouse.y > 635) && ((int)virtualMouse.y < 670)){
                    if(CurserPos != 4){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 4;
                    }
                    MenuControllerMode = false;
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        StatsMenu();
                    }
                }else if(MenuControllerMode == true && CurserPos == 4){
                    DrawRectangle(295, 630, 210, 45, BLACK);
                    DrawRectangle(300, 635, 200, 35, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        StatsMenu();
                    }
                }else{
                    if(CurserPos == 4){
                        CurserPos = ButtonNum;
                    }
                    DrawRectangle(300, 635, 200, 35, WHITE);
                } 
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<300)&&((int)virtualMouse.y>300)&&((int)virtualMouse.y<350)){
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
                    DrawRectangle(45, 295, 260, 60, BLACK);
                    DrawRectangle(50, 300, 250, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 0){
                    DrawRectangle(45, 295, 260, 60, BLACK);
                    DrawRectangle(50, 300, 250, 50, WHITE);
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
                    DrawRectangle(50, 300, 250, 50, WHITE);
                }
                if(MusicOn == true){
                    DrawText("Music: On", 55, 300, 50, MenuTextColour);
                }else{
                    DrawText("Music: Off", 55, 300, 50, MenuTextColour);
                }
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<550)&&((int)virtualMouse.y>370)&&((int)virtualMouse.y<410)){
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
                    DrawRectangle(45, 365, 510, 60, BLACK);
                    DrawRectangle(50, 370, 500, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 1){
                    DrawRectangle(45, 365, 510, 60, BLACK);
                    DrawRectangle(50, 370, 500, 50, WHITE);
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
                    DrawRectangle(50, 370, 500, 50, WHITE);
                }
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<550)&&((int)virtualMouse.y>440)&&((int)virtualMouse.y<490)){
                    if(CurserPos != 2){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 2;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        TileSetChoice++;
                        if(TileSetChoice > 2){
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
                }else if(MenuControllerMode == true && CurserPos == 2){
                    DrawRectangle(45, 435, 510, 60, BLACK);
                    DrawRectangle(50, 440, 500, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        TileSetChoice++;
                        if(TileSetChoice > 2){
                            TileSetChoice = 0;
                        }
                        intTextures();
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }     
                    }
                }else{
                    if(CurserPos == 2){
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
                }
                if(SoundEffectsOn == true){
                    DrawText("Sound Effects: On", 55, 370, 50, MenuTextColour);
                }else{
                    DrawText("Sound Effects: Off", 55, 370, 50, MenuTextColour);
                }
                if(((int)virtualMouse.x>50)&&((int)virtualMouse.x<500)&&((int)virtualMouse.y>510)&&((int)virtualMouse.y<560)){
                    if(CurserPos != 3){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuChange);
                        }
                        CurserPos = 3;
                    }
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ToggleFullscreen();
                    }
                    MenuControllerMode = false;
                    DrawRectangle(45, 505, 460, 60, BLACK);
                    DrawRectangle(50, 510, 450, 50, WHITE);
                }else if(MenuControllerMode == true && CurserPos == 3){
                    DrawRectangle(45, 505, 460, 60, BLACK);
                    DrawRectangle(50, 510, 450, 50, WHITE);
                    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        if(SoundEffectsOn == true){
                            PlaySound(MenuSelect);
                        }
                        ToggleFullscreen();
                    }
                }else{
                    if(CurserPos == 3){
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
            break;
        }
    }
}

void MainMenu(){
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
            ModeSelect();
            ClearBackground(BLACK);
        }
    }else if(MenuControllerMode == true && CurserPos == 0){
        DrawRectangle(295, 430, 210, 45, BLACK);
        DrawRectangle(300, 435, 200, 35, WHITE);
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
                OptionMenu();
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ButtonNum = 6;
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
                ExitGame();
            }
        }else if(MenuControllerMode == true && CurserPos == 3){
            DrawRectangle(295, 550, 210, 45, BLACK);
            DrawRectangle(300, 555, 200, 35, WHITE);
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
                OptionMenu();
            }
        }else if(MenuControllerMode == true && CurserPos == 1){
            DrawRectangle(295, 470, 210, 45, BLACK);
            DrawRectangle(300, 475, 200, 35, WHITE);
            if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ButtonNum = 6;
                CurserPos = 0;
                OptionMenu();
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
                ExitGame();
            }
        }else if(MenuControllerMode == true && CurserPos == 2){
            DrawRectangle(295, 510, 210, 45, BLACK);
            DrawRectangle(300, 515, 200, 35, WHITE);
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_MIDDLE_RIGHT) || IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                ExitGame();
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
}
