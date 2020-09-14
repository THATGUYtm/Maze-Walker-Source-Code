void OptionMenu(){
    while(1){
        if(WindowShouldClose()){ExitGame();}
        if(MusicOn == true){UpdateMusicStream(MenuMusic);}
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
                DrawTextureRec(TileSet,(Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){GameScreenStart[0], 0}, WHITE);
                DrawText("Options", 50 + GameScreenStart[0], 50 + GameScreenStart[1], 180, BLACK);
                if((GetMouseX() > 550) && (GetMouseX() < 750) && (GetMouseY() > 635) && (GetMouseY() < 670)){
                    DrawRectangle(550, 635, 200, 35, GREEN);
                    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){break;}
                }else{DrawRectangle(550, 635, 200, 35, WHITE);} 
                if((GetMouseX()>50)&&(GetMouseX()<300)&&(GetMouseY()>300)&&(GetMouseY()<355)){if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){MusicOn=!MusicOn;}}
                if(MusicOn == true){
                    DrawRectangle(50 + GameScreenStart[0], 300, 250, 50, GREEN);
                    DrawText("Music: On", 55 + GameScreenStart[0], 300, 50, BLACK);
                }else{
                    DrawRectangle(50 + GameScreenStart[0], 300, 250, 50, WHITE);
                    DrawText("Music: Off", 55 + GameScreenStart[0], 300, 50, BLACK);
                }
                if((GetMouseX()>50)&&(GetMouseX()<850)&&(GetMouseY()>370)&&(GetMouseY()<410)){if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){SoundEffectsOn=!SoundEffectsOn;}}
                if(SoundEffectsOn == true){
                    DrawRectangle(50 + GameScreenStart[0], 370, 500, 50, GREEN);
                    DrawText("Sound Effects: On", 55 + GameScreenStart[0], 370, 50, BLACK);
                }else{
                    DrawRectangle(50 + GameScreenStart[0], 370, 500, 50, WHITE);
                    DrawText("Sound Effects: Off", 55 + GameScreenStart[0], 370, 50, BLACK);
                }
                DrawText("Back", 565, 635, 35, BLACK);
            EndMode2D();
        EndDrawing();
    }
}

void MainMenu(){
    ClearBackground(BLACK);
    DrawTextureRec(TileSet,(Rectangle){0.0f,0.0f,800.0f,720.0f}, (Vector2){GameScreenStart[0], 0}, WHITE);
    DrawText("Maze", 160 + GameScreenStart[0], 50, 180, BLACK);
    DrawText("Walker", 90 + GameScreenStart[0], 190, 180, BLACK);
    DrawText("Walk Your Way To Freedom", 50 + GameScreenStart[0], 350, 50, BLACK);
    bool ContinueExists = false;
    if(FileExists("storage.data")){ContinueExists = true;}
    if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 435) && (GetMouseY() < 470)){
        DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, GREEN);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            CurrentLevel = 1;
            Timer[0] = 0;
            Timer[1] = 0;
            Timer[2] = 0;
            Timer[3] = 0;
            SaveSave();
            StartGame = true;
        }
    }else{DrawRectangle(300 + GameScreenStart[0], 435, 200, 35, WHITE);}
    DrawText("New Game", 315 + GameScreenStart[0], 435, 35, BLACK);
    if(ContinueExists == true){
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 475) && (GetMouseY() < 510)){
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){StartGame = true;}
        }else{DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, WHITE);} 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 515) && (GetMouseY() < 550)){
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){OptionMenu();}
        }else{DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, WHITE);} 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 555) && (GetMouseY() < 590)){
            DrawRectangle(300 + GameScreenStart[0], 555, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){ExitGame();}
        }else{DrawRectangle(300 + GameScreenStart[0], 555, 200, 35, WHITE);} 
        DrawText("Continue", 315 + GameScreenStart[0], 475, 35, BLACK);
        DrawText("Options", 315 + GameScreenStart[0], 515, 35, BLACK);
        DrawText("Exit Game", 315 + GameScreenStart[0], 555, 35, BLACK);
    }else{
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 475) && (GetMouseY() < 510)){
            DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){OptionMenu();}
        }else{DrawRectangle(300 + GameScreenStart[0], 475, 200, 35, WHITE);} 
        if((GetMouseX() > 300 + GameScreenStart[0]) && (GetMouseX() < 500 + GameScreenStart[0]) && (GetMouseY() > 515) && (GetMouseY() < 550)){
            DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, GREEN);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){ExitGame();}
        }else{DrawRectangle(300 + GameScreenStart[0], 515, 200, 35, WHITE);} 
        DrawText("Options", 315 + GameScreenStart[0], 475, 35, BLACK);
        DrawText("ExitGame", 315 + GameScreenStart[0], 515, 35, BLACK);
    }
}
