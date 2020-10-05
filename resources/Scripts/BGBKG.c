unsigned char Map[360];
unsigned int GameScreenStart[] = {0, 0};
unsigned int TileSetChoice = 0;
Color MenuTextColour = BLACK;

Texture2D TileSet;

void intTextures(){
    switch(TileSetChoice){
        case 0:
            TileSet = LoadTexture("resources/TileSets/Original.png");MenuTextColour = BLACK;
            break;
        case 1:
            TileSet = LoadTexture("resources/TileSets/GameBoy.png");MenuTextColour = BLACK;
            break;
        case 2:
            TileSet = LoadTexture("resources/TileSets/Modern.png");MenuTextColour = BLACK;
            break;
    }
}

void DrawMainMenu(){
    for(int i = 0; i < 800; i += 40){
        for(int j = 0; j < 720; j += 40){
            switch(MainMenuMap[((j/40)*20)+(i/40)]){
                case 0x30:
                    DrawTextureRec(TileSet, (Rectangle){440.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x26:
                    DrawTextureRec(TileSet, (Rectangle){40.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x2F:
                    DrawTextureRec(TileSet, (Rectangle){400.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x28:
                    DrawTextureRec(TileSet, (Rectangle){120.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x25:
                    DrawTextureRec(TileSet, (Rectangle){440.0f,200.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x24:
                    DrawTextureRec(TileSet, (Rectangle){440.0f,80.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x31:
                    DrawTextureRec(TileSet, (Rectangle){0.0f,160.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x27:
                    DrawTextureRec(TileSet, (Rectangle){80.0f,120.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
                case 0x32:
                    DrawTextureRec(TileSet, (Rectangle){40.0f,160.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
                    break;
            }
        }
    }
}

void DrawBKG(){
    ClearBackground(BLACK);
    int j;
    int i;
    for(i = 0; i < 800; i += 40){
        for(j = 0; j < 720; j += 40){
            DrawTextureRec(TileSet, (Rectangle){400.0f,200.0f,40.0f,40.0f}, (Vector2){i + GameScreenStart[0], j}, WHITE);
        }
    }
	for(i = 0; i < 800; i+=40){
        for(j = 0; j < 720; j+=40){
            switch(Map[((j/40)*20)+(i/40)]){
                case 0x01:
                    DrawTextureRec(TileSet,(Rectangle){400.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
				case 0x02:
                    DrawTextureRec(TileSet,(Rectangle){40.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x03:
                    DrawTextureRec(TileSet,(Rectangle){440.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x04:
                    DrawTextureRec(TileSet,(Rectangle){0.0f,40.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x05:
                    DrawTextureRec(TileSet,(Rectangle){160.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x12:
                    DrawTextureRec(TileSet,(Rectangle){200.0f,.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x13:
                    DrawTextureRec(TileSet,(Rectangle){240.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x14:
                    DrawTextureRec(TileSet,(Rectangle){280.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x15:
                    DrawTextureRec(TileSet,(Rectangle){320.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x16:
                    DrawTextureRec(TileSet,(Rectangle){360.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x17:
                    DrawTextureRec(TileSet,(Rectangle){40.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x18:
                    DrawTextureRec(TileSet,(Rectangle){80.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x19:
                    DrawTextureRec(TileSet,(Rectangle){120.0f,00.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x1A:
                    DrawTextureRec(TileSet,(Rectangle){0.0f,0.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
				case 0x1B:
                    DrawTextureRec(TileSet,(Rectangle){80.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x1C:
                    DrawTextureRec(TileSet,(Rectangle){120.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x1D:
                    DrawTextureRec(TileSet,(Rectangle){160.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x1E:
                    DrawTextureRec(TileSet,(Rectangle){200.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x1F:
                    DrawTextureRec(TileSet,(Rectangle){240.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x20:
                    DrawTextureRec(TileSet,(Rectangle){280.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x21:
                    DrawTextureRec(TileSet,(Rectangle){320.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x22:
                    DrawTextureRec(TileSet,(Rectangle){360.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x23:
                    DrawTextureRec(TileSet,(Rectangle){400.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x24:
                    DrawTextureRec(TileSet,(Rectangle){440.0f,80.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x25:
                    DrawTextureRec(TileSet,(Rectangle){0.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x26:
                    DrawTextureRec(TileSet,(Rectangle){40.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x27:
                    DrawTextureRec(TileSet,(Rectangle){80.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x28:
                    DrawTextureRec(TileSet,(Rectangle){120.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x29:
                    DrawTextureRec(TileSet,(Rectangle){160.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2A:
                    DrawTextureRec(TileSet,(Rectangle){200.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2B:
                    DrawTextureRec(TileSet,(Rectangle){240.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2C:
                    DrawTextureRec(TileSet,(Rectangle){280.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2D:
                    DrawTextureRec(TileSet,(Rectangle){320.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2E:
                    DrawTextureRec(TileSet,(Rectangle){360.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x2F:
                    DrawTextureRec(TileSet,(Rectangle){400.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x30:
                    DrawTextureRec(TileSet,(Rectangle){440.0f,120.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x31:
                    DrawTextureRec(TileSet,(Rectangle){0.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x32:
                    DrawTextureRec(TileSet,(Rectangle){40.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x33:
                    DrawTextureRec(TileSet,(Rectangle){80.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x34:
                    DrawTextureRec(TileSet,(Rectangle){120.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x35:
                    DrawTextureRec(TileSet,(Rectangle){160.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x36:
                    DrawTextureRec(TileSet,(Rectangle){200.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x37:
                    DrawTextureRec(TileSet,(Rectangle){240.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x38:
                    DrawTextureRec(TileSet,(Rectangle){280.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x39:
                    DrawTextureRec(TileSet,(Rectangle){320.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3A:
                    DrawTextureRec(TileSet,(Rectangle){360.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3B:
                    DrawTextureRec(TileSet,(Rectangle){400.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3C:
                    DrawTextureRec(TileSet,(Rectangle){440.0f,160.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3D:
                    DrawTextureRec(TileSet,(Rectangle){0.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3E:
                    DrawTextureRec(TileSet,(Rectangle){40.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x3F:
                    DrawTextureRec(TileSet,(Rectangle){80.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
				case 0x40:
                    DrawTextureRec(TileSet,(Rectangle){120.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
				case 0x41:
                    DrawTextureRec(TileSet,(Rectangle){160.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
				case 0x42:
                    DrawTextureRec(TileSet,(Rectangle){200.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x43:
                    DrawTextureRec(TileSet,(Rectangle){240.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x44:
                    DrawTextureRec(TileSet,(Rectangle){280.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x45:
                    DrawTextureRec(TileSet,(Rectangle){320.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
                case 0x46:
                    DrawTextureRec(TileSet,(Rectangle){360.0f,200.0f,40.0f,40.0f},(Vector2){i+GameScreenStart[0],j},WHITE);
                    break;
			}
        }
    }
}

void UnloadTextures(){
    UnloadTexture(TileSet);
    UnloadMusicStream(MenuMusic);
    UnloadMusicStream(GameMusic);
    UnloadMusicStream(EndingMusic);
    UnloadSound(KeySoundEffect);
    UnloadSound(LockSoundEffect);
    UnloadSound(BoxPushSoundEffect);
    UnloadSound(SpikeSoundEffect);
    UnloadSound(EnimeSoundEffect);
    UnloadSound(LevelFinnishSoundEffect);
    UnloadSound(MenuChange);
    UnloadSound(MenuSelect);
    CloseWindow();
}