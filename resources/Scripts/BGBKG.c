unsigned char Map[360];
unsigned int GameScreenStart[] = {0, 0};

Texture2D TileSet;

static void intTextures(){TileSet = LoadTexture("resources/Tileset.png");}

static void DrawBKG(){
    ClearBackground(BLACK);
    DrawTextureRec(TileSet, (Rectangle){800.0f,0.0f,800.0f,720.0f}, (Vector2){0 + GameScreenStart[0], 0}, WHITE);
	for(int i = 0; i < 20; i++){
        for(int j = 0; j < 18; j++){
            Vector2 TilePos = (Vector2){(i * 40) + GameScreenStart[0], (j * 40)};
            switch(Map[(j*20)+(i)]){
                case 0x01:DrawTextureRec(TileSet,(Rectangle){1680.0f,0.0f,40.0f,40.0f},TilePos,WHITE);break;
				case 0x02:DrawTextureRec(TileSet,(Rectangle){1640.0f,120.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x03:DrawTextureRec(TileSet,(Rectangle){1720.0f,0.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x04:DrawTextureRec(TileSet,(Rectangle){1680.0f,400.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x05:DrawTextureRec(TileSet,(Rectangle){1720.0f,480.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x12:DrawTextureRec(TileSet,(Rectangle){1600.0f,560.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x13:DrawTextureRec(TileSet,(Rectangle){1640.0f,560.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x14:DrawTextureRec(TileSet,(Rectangle){1600.0f,280.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x15:DrawTextureRec(TileSet,(Rectangle){1640.0f,280.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x16:DrawTextureRec(TileSet,(Rectangle){1600.0f,40.0f,40.0f,40.0f}, TilePos,WHITE);break;
                case 0x17:DrawTextureRec(TileSet,(Rectangle){1640.0f,520.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x18:DrawTextureRec(TileSet,(Rectangle){1720.0f,120.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x19:DrawTextureRec(TileSet,(Rectangle){1600.0f,0.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x1A:DrawTextureRec(TileSet,(Rectangle){1640.0f,0.0f,40.0f,40.0f},TilePos,WHITE);break;
				case 0x1B:DrawTextureRec(TileSet,(Rectangle){1680.0f,120.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x1C:DrawTextureRec(TileSet,(Rectangle){1600.0f,520.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x1D:DrawTextureRec(TileSet,(Rectangle){1680.0f,520.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x1E:DrawTextureRec(TileSet,(Rectangle){1720.0f,520.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x1F:DrawTextureRec(TileSet,(Rectangle){1600.0f,680.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x20:DrawTextureRec(TileSet,(Rectangle){1640.0f,680.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x21:DrawTextureRec(TileSet,(Rectangle){1600.0f,400.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x22:DrawTextureRec(TileSet,(Rectangle){1640.0f,400.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x23:DrawTextureRec(TileSet,(Rectangle){1600.0f,160.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x24:DrawTextureRec(TileSet,(Rectangle){1640.0f,160.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x25:DrawTextureRec(TileSet,(Rectangle){1680.0f,160.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x26:DrawTextureRec(TileSet,(Rectangle){1720.0f,160.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x27:DrawTextureRec(TileSet,(Rectangle){1680.0f,560.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x28:DrawTextureRec(TileSet,(Rectangle){1680.0f,280.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x29:DrawTextureRec(TileSet,(Rectangle){1720.0f,280.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2A:DrawTextureRec(TileSet,(Rectangle){1680.0f,680.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2B:DrawTextureRec(TileSet,(Rectangle){1600.0f,440.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2C:DrawTextureRec(TileSet,(Rectangle){1640.0f,440.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2D:DrawTextureRec(TileSet,(Rectangle){1600.0f,200.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2E:DrawTextureRec(TileSet,(Rectangle){1640.0f,200.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x2F:DrawTextureRec(TileSet,(Rectangle){1680.0f,200.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x30:DrawTextureRec(TileSet,(Rectangle){1720.0f,200.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x31:DrawTextureRec(TileSet,(Rectangle){1680.0f,600.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x32:DrawTextureRec(TileSet,(Rectangle){1680.0f,320.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x33:DrawTextureRec(TileSet,(Rectangle){1720.0f,320.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x34:DrawTextureRec(TileSet,(Rectangle){1720.0f,400.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x35:DrawTextureRec(TileSet,(Rectangle){1600.0f,480.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x36:DrawTextureRec(TileSet,(Rectangle){1640.0f,480.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x37:DrawTextureRec(TileSet,(Rectangle){1600.0f,240.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x38:DrawTextureRec(TileSet,(Rectangle){1640.0f,240.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x39:DrawTextureRec(TileSet,(Rectangle){1680.0f,240.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3A:DrawTextureRec(TileSet,(Rectangle){1720.0f,240.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3B:DrawTextureRec(TileSet,(Rectangle){1680.0f,640.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3C:DrawTextureRec(TileSet,(Rectangle){1680.0f,360.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3D:DrawTextureRec(TileSet,(Rectangle){1720.0f,360.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3E:DrawTextureRec(TileSet,(Rectangle){1720.0f,440.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x3F:DrawTextureRec(TileSet,(Rectangle){1720.0f,80.0f,40.0f,40.0f},TilePos,WHITE);break;
				case 0x40:DrawTextureRec(TileSet,(Rectangle){1680.0f,480.0f,40.0f,40.0f},TilePos,WHITE);break;
				case 0x41:DrawTextureRec(TileSet,(Rectangle){1720.0f,560.0f,40.0f,40.0f},TilePos,WHITE);break;
				case 0x42:DrawTextureRec(TileSet,(Rectangle){1600.0f,640.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x43:DrawTextureRec(TileSet,(Rectangle){1640.0f,640.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x44:DrawTextureRec(TileSet,(Rectangle){1600.0f,360.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x45:DrawTextureRec(TileSet,(Rectangle){1640.0f,360.0f,40.0f,40.0f},TilePos,WHITE);break;
                case 0x46:DrawTextureRec(TileSet,(Rectangle){1600.0f,120.0f,40.0f,40.0f},TilePos,WHITE);break;
			}
        }
    }
}

static void UnloadTextures(){
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