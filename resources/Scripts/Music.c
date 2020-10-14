unsigned int CurrentTrack = 0;

void PlayMusic(){
    int OldTrack = CurrentTrack;
    while(CurrentTrack == OldTrack){
        CurrentTrack = GetRandomValue(1, 5);
    }
    switch(CurrentTrack){
        case 1:
            PlayMusicStream(GameMusicOne);
            break;
        case 2:
            PlayMusicStream(GameMusicTwo);
            break;
        case 3:
            PlayMusicStream(GameMusicThree);
            break;
        case 4:
            PlayMusicStream(GameMusicFour);
            break;
        case 5:
            PlayMusicStream(GameMusicFive);
            break;
    }
}

void PlayInGameMusic(){
    if(CurrentTrack == 0){
        CurrentTrack = GetRandomValue(1, 5);
        PlayMusic();
    }else{
        switch(CurrentTrack){
            case 1:
                if(GetMusicTimePlayed(GameMusicOne) >= GetMusicTimeLength(GameMusicOne)-0.1f){
                    PlayMusic();
                }else{
                    UpdateMusicStream(GameMusicOne);
                }
                break;
            case 2:
                if(GetMusicTimePlayed(GameMusicTwo) >= GetMusicTimeLength(GameMusicTwo)-0.1f){
                    PlayMusic();
                }else{
                    UpdateMusicStream(GameMusicTwo);
                }
                break;
            case 3:
                if(GetMusicTimePlayed(GameMusicThree) >= GetMusicTimeLength(GameMusicThree)-0.1f){
                    PlayMusic();
                }else{
                    UpdateMusicStream(GameMusicThree);
                }
                break;
            case 4:
                if(GetMusicTimePlayed(GameMusicFour) >= GetMusicTimeLength(GameMusicFour)-0.1f){
                    PlayMusic();
                }else{
                    UpdateMusicStream(GameMusicFour);
                }
                break;
            case 5:
                if(GetMusicTimePlayed(GameMusicFive) >= GetMusicTimeLength(GameMusicFive)-0.1f){
                    PlayMusic();
                }else{
                    UpdateMusicStream(GameMusicFive);
                }
                break;
        }
    }
}