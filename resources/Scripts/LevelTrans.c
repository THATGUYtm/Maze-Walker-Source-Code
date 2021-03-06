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
        case 33:
            ChangeOverLevels(LevelThirtythree);
            Player[0] = 40;
            Player[1] = 80;
            KeysNeeded = 2;
            Fence[0] = 2;
            Fence[1] = 213;
            Fence[2] = 214;
            Lock[0] = 289;
            Lock[1] = 336;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 14;
            Enimes[2] = 46;
            Enimes[3] = 84;
			Enimes[4] = 89;
            Enimes[5] = 112;
            Enimes[6] = 118;
            Enimes[7] = 155;
            Enimes[8] = 169;
            Enimes[9] = 183;
            Enimes[10] = 257;
            Enimes[11] = 283;
            Enimes[12] = 291;
            Enimes[13] = 293;
            Enimes[14] = 298;
            Enimes[15] = 333;
            break;
        case 34:
            ChangeOverLevels(LevelThirtyfour);
            KeysNeeded = 23;
            Fence[0] = 2;
            Fence[1] = 177;
            Fence[2] = 301;
            Lock[0] = 81;
            Lock[1] = 298;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 10;
            Enimes[2] = 181;
            Enimes[3] = 202;
			Enimes[4] = 223;
            Enimes[5] = 244;
            Enimes[6] = 265;
            Enimes[7] = 286;
            Enimes[8] = 267;
            Enimes[9] = 248;
            Enimes[10] = 229;
            Enimes[11] = 210;
            break;
        case 35:
            ChangeOverLevels(LevelThirtyfive);
            KeysNeeded = 4;
            HasSpikes = true;
            break;
        case 36:
            ChangeOverLevels(LevelThirtysix);
            KeysNeeded = 2;
            HasEnimes = true;
            Enimes[1] = 55;
            Enimes[2] = 22;
            Enimes[3] = 28;
			Enimes[4] = 34;
            Enimes[5] = 41;
            Enimes[6] = 43;
            Enimes[7] = 47;
            Enimes[8] = 49;
            Enimes[9] = 53;
            Enimes[10] = 55;
            Enimes[11] = 62;
            Enimes[12] = 64;
            Enimes[13] = 66;
            Enimes[14] = 70;
            Enimes[15] = 72;
            Enimes[16] = 76;
            Enimes[17] = 78;
            Enimes[18] = 83;
            Enimes[19] = 85;
            Enimes[20] = 91;
            Enimes[21] = 97;
            Enimes[22] = 104;
            Enimes[23] = 125;
            Enimes[24] = 133;
            Enimes[25] = 144;
            Enimes[26] = 146;
            Enimes[27] = 152;
            Enimes[28] = 154;
            Enimes[29] = 163;
            Enimes[30] = 167;
            Enimes[31] = 171;
            Enimes[32] = 175;
            Enimes[33] = 182;
            Enimes[34] = 188;
            Enimes[35] = 190;
            Enimes[36] = 196;
            Enimes[37] = 201;
            Enimes[38] = 209;
            Enimes[39] = 217;
            Enimes[40] = 222;
            Enimes[41] = 238;
            Enimes[42] = 243;
            Enimes[43] = 237;
            Enimes[44] = 264;
            Enimes[45] = 270;
            Enimes[46] = 276;
            Enimes[47] = 285;
            Enimes[48] = 289;
            Enimes[49] = 291;
            Enimes[50] = 295;
            Enimes[51] = 306;
            Enimes[52] = 308;
            Enimes[53] = 312;
            Enimes[54] = 314;
            Enimes[55] = 327;
            Enimes[56] = 333;
            break;
        case 37:
            ChangeOverLevels(LevelThirtyseven);
            Player[0] = 40;
            Player[1] = 640;
            KeysNeeded = 54;
            Fence[0] = 2;
            Fence[1] = 161;
            Fence[2] = 98;
            Lock[0] = 105;
            Lock[1] = 238;
            HasSpikes = true;
            HasEnimes = true;
            Enimes[1] = 18;
            Enimes[2] = 101;
            Enimes[3] = 122;
			Enimes[4] = 143;
            Enimes[5] = 104;
            Enimes[6] = 125;
            Enimes[7] = 146;
            Enimes[8] = 107;
            Enimes[9] = 128;
            Enimes[10] = 149;
            Enimes[11] = 110;
            Enimes[12] = 131;
            Enimes[13] = 152;
            Enimes[14] = 113;
            Enimes[15] = 134;
            Enimes[16] = 155;
            Enimes[17] = 116;
            Enimes[18] = 137;
            Enimes[19] = 158;
            break;
        case 38:
            ChangeOverLevels(LevelThirtyeight);
            KeysNeeded = 6;
            HasEnimes = true;
            Enimes[1] = 7;
            Enimes[2] = 141;
            Enimes[3] = 171;
			Enimes[4] = 37;
            Enimes[5] = 58;
            Enimes[6] = 77;
            Enimes[7] = 98;
            Enimes[8] = 117;
            break;
        case 39:
            ChangeOverLevels(LevelThirtynine);
            break;
        case 40:
            ChangeOverLevels(LevelFourty);
            KeysNeeded = 2;
            Fence[0] = 3;
            Fence[1] = 26;
            Fence[2] = 273;
            Fence[3] = 93;
            Lock[0] = 290;
            Lock[1] = 107;
            Lock[2] = 298;
            break;
		case 41:
            ChangeOverLevels(LevelFourtyone);
            KeysNeeded = 2;
            Fence[0] = 2;
            Fence[1] = 169;
            Fence[2] = 170;
            Lock[0] = 28;
            Lock[1] = 161;
			HasEnimes = true;
            Enimes[1] = 64;
            Enimes[2] = 24;
            Enimes[3] = 26;
			Enimes[4] = 48;
            Enimes[5] = 61;
            Enimes[6] = 64;
			Enimes[7] = 338;
            Enimes[8] = 87;
            Enimes[9] = 102;
			Enimes[10] = 126;
			Enimes[11] = 143;
			Enimes[12] = 165;
			Enimes[13] = 201;
			Enimes[14] = 203;
			Enimes[15] = 205;
			Enimes[16] = 207;
			Enimes[17] = 209;
			Enimes[18] = 211;
			Enimes[19] = 213;
			Enimes[20] = 215;
			Enimes[21] = 217;
			Enimes[22] = 221;
			Enimes[23] = 223;
			Enimes[24] = 225;
			Enimes[25] = 227;
			Enimes[26] = 229;
			Enimes[27] = 231;
			Enimes[28] = 233;
			Enimes[29] = 235;
			Enimes[30] = 237;
			Enimes[31] = 242;
			Enimes[32] = 244;
			Enimes[33] = 246;
			Enimes[34] = 248;
			Enimes[35] = 250;
			Enimes[36] = 252;
			Enimes[37] = 254;
			Enimes[38] = 256;
			Enimes[39] = 258;
			Enimes[40] = 281;
			Enimes[41] = 283;
			Enimes[42] = 285;
			Enimes[43] = 287;
			Enimes[44] = 289;
			Enimes[45] = 291;
			Enimes[46] = 293;
			Enimes[47] = 295;
			Enimes[48] = 297;
			Enimes[49] = 302;
			Enimes[50] = 304;
			Enimes[51] = 306;
			Enimes[52] = 308;
			Enimes[53] = 310;
			Enimes[54] = 312;
			Enimes[55] = 314;
			Enimes[56] = 316;
			Enimes[57] = 318;
			Enimes[58] = 322;
			Enimes[59] = 324;
			Enimes[60] = 326;
			Enimes[61] = 328;
			Enimes[62] = 330;
			Enimes[63] = 332;
			Enimes[64] = 334;
			Enimes[65] = 336;
            break;
		case 42:
            ChangeOverLevels(LevelFourtytwo);
			Player[0] = 80;
            Player[1] = 40;
			KeysNeeded = 6;
			HasSpikes = true;
			HasEnimes = true;
			Enimes[1] = 40;
			Enimes[41] = 21;
			Enimes[2] = 42;
			Enimes[3] = 63;
			Enimes[4] = 84;
			Enimes[5] = 105;
			Enimes[6] = 29;
			Enimes[7] = 50;
			Enimes[8] = 69;
			Enimes[9] = 90;
			Enimes[10] = 109;
			Enimes[11] = 38;
			Enimes[12] = 57;
			Enimes[13] = 76;
			Enimes[14] = 95;
			Enimes[15] = 114;
			Enimes[16] = 161;
			Enimes[17] = 163;
			Enimes[18] = 165;
			Enimes[19] = 182;
			Enimes[20] = 184;
			Enimes[21] = 174;
			Enimes[22] = 176;
			Enimes[23] = 178;
			Enimes[24] = 195;
			Enimes[25] = 197;
			Enimes[26] = 321;
			Enimes[27] = 302;
			Enimes[28] = 283;
			Enimes[29] = 264;
			Enimes[30] = 245;
			Enimes[31] = 249;
			Enimes[32] = 270;
			Enimes[33] = 289;
			Enimes[34] = 310;
			Enimes[35] = 329;
			Enimes[36] = 254;
			Enimes[37] = 275;
			Enimes[38] = 296;
			Enimes[39] = 317;
			Enimes[40] = 338;
            break;
		case 43:
            ChangeOverLevels(LevelFourtythree);
            KeysNeeded = 5;
            Fence[0] = 2;
            Fence[1] = 201;
            Fence[2] = 118;
            Lock[0] = 23;
            Lock[1] = 38;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 4;
            Enimes[2] = 163;
            Enimes[3] = 165;
            Enimes[4] = 185;
            Enimes[5] = 187;
            break;
		case 44:
            ChangeOverLevels(LevelFourtyfour);
            KeysNeeded = 4;
            break;
		case 45:
            ChangeOverLevels(LevelFourtyfive);
            KeysNeeded = 6;
			Player[1] = 320;
            Fence[0] = 2;
            Fence[1] = 202;
            Fence[2] = 157;
            Lock[1] = 198;
            Lock[0] = 121;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 4;
            Enimes[2] = 77;
            Enimes[3] = 138;
            Enimes[4] = 221;
            Enimes[5] = 282;
            break;
		case 46:
            ChangeOverLevels(LevelFourtysix);
            KeysNeeded = 5;
			HasEnimes = true;
            Enimes[1] = 4;
            Enimes[2] = 44;
            Enimes[3] = 129;
            Enimes[4] = 303;
            Enimes[5] = 323;
            break;
		case 47:
            ChangeOverLevels(LevelFourtyseven);
			Player[1] = 640;
            KeysNeeded = 4;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 3;
            Enimes[2] = 36;
            Enimes[3] = 38;
            Enimes[4] = 151;
            break;
		case 48:
            ChangeOverLevels(LevelFourtyeight);
            KeysNeeded = 6;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 16;
            Enimes[2] = 42;
            Enimes[3] = 58;
            Enimes[4] = 270;
			Enimes[5] = 298;
			Enimes[6] = 309;
			Enimes[7] = 316;
			Enimes[8] = 93;
			Enimes[9] = 114;
			Enimes[10] = 132;
			Enimes[11] = 155;
			Enimes[12] = 173;
			Enimes[13] = 194;
			Enimes[14] = 215;
			Enimes[15] = 234;
			Enimes[16] = 255;
            break;
		case 49:
            ChangeOverLevels(LevelFourtynine);
			Player[0] = 720;
			Player[1] = 200;
            KeysNeeded = 4;
			Fence[0] = 1;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 24;
            Enimes[2] = 44;
            Enimes[3] = 46;
            Enimes[4] = 65;
			Enimes[5] = 67;
			Enimes[6] = 55;
			Enimes[7] = 144;
			Enimes[8] = 145;
			Enimes[9] = 146;
			Enimes[10] = 164;
			Enimes[11] = 165;
			Enimes[12] = 166;
			Enimes[13] = 184;
			Enimes[14] = 185;
			Enimes[15] = 186;
			Enimes[16] = 153;
			Enimes[17] = 154;
			Enimes[18] = 155;
			Enimes[19] = 173;
			Enimes[20] = 174;
			Enimes[21] = 175;
			Enimes[22] = 193;
			Enimes[23] = 194;
			Enimes[24] = 195;
            break;
		case 50:
            ChangeOverLevels(LevelFifty);
			Fence[0] = 1;
            break;
		case 51:
            ChangeOverLevels(LevelFiftyone);
			HasSpikes = true;
            break;
		case 52:
            ChangeOverLevels(LevelFiftytwo);
			Player[1] = 320;
            KeysNeeded = 4;
			HasEnimes = true;
            Enimes[1] = 14;
            Enimes[2] = 323;
            Enimes[3] = 325;
            Enimes[4] = 327;
			Enimes[5] = 309;
			Enimes[6] = 331;
			Enimes[7] = 333;
			Enimes[8] = 315;
			Enimes[9] = 117;
			Enimes[10] = 218;
			Enimes[11] = 277;
			Enimes[12] = 317;
			Enimes[13] = 318;
			Enimes[14] = 337;
			Enimes[15] = 338;
            break;
		case 53:
            ChangeOverLevels(LevelFiftythree);
            KeysNeeded = 6;
			HasEnimes = true;
            Enimes[1] = 6;
            Enimes[2] = 222;
            Enimes[3] = 188;
            Enimes[4] = 276;
			Enimes[5] = 117;
			Enimes[6] = 137;
			Enimes[7] = 138;
			break;
		case 90:
            ChangeOverLevels(LevelNinty);
			Player[0] = 120;
			Player[1] = 160;
            KeysNeeded = 2;
			Fence[0] = 3;
            Fence[1] = 71;
            Fence[2] = 278;
			Fence[3] = 169;
            Lock[0] = 163;
            Lock[1] = 338;
			Lock[2] = 321;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 16;
            Enimes[2] = 25;
            Enimes[3] = 32;
            Enimes[4] = 116;
			Enimes[5] = 118;
			Enimes[6] = 127;
			Enimes[7] = 133;
			Enimes[8] = 136;
			Enimes[9] = 165;
			Enimes[10] = 172;
			Enimes[11] = 218;
			Enimes[12] = 256;
			Enimes[13] = 270;
			Enimes[14] = 281;
			Enimes[15] = 302;
			Enimes[16] = 316;
			Enimes[17] = 330;
            break;
		case 91:
            ChangeOverLevels(LevelNintyone);
			Player[0] = 720;
			Player[1] = 640;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 25;
            Enimes[2] = 45;
            Enimes[3] = 66;
            Enimes[4] = 125;
			Enimes[5] = 186;
			Enimes[6] = 245;
			Enimes[7] = 306;
			Enimes[8] = 49;
			Enimes[9] = 88;
			Enimes[10] = 129;
			Enimes[11] = 169;
			Enimes[12] = 209;
			Enimes[13] = 248;
			Enimes[14] = 289;
			Enimes[15] = 52;
			Enimes[16] = 171;
			Enimes[17] = 291;
			Enimes[18] = 311;
			Enimes[19] = 155;
			Enimes[20] = 195;
			Enimes[21] = 137;
			Enimes[22] = 178;
			Enimes[23] = 217;
			Enimes[24] = 257;
			Enimes[25] = 298;
			Enimes[26] = 278;
            break;
		case 92:
            ChangeOverLevels(LevelNintytwo);
			Player[0] = 80;
            KeysNeeded = 4;
			Fence[0] = 4;
            Fence[1] = 30;
            Fence[2] = 177;
			Fence[3] = 289;
			Fence[4] = 184;
            Lock[0] = 109;
            Lock[1] = 118;
			Lock[2] = 275;
			Lock[3] = 247;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 33;
            Enimes[2] = 111;
            Enimes[3] = 92;
            Enimes[4] = 73;
			Enimes[5] = 54;
			Enimes[6] = 35;
			Enimes[7] = 95;
			Enimes[8] = 98;
			Enimes[9] = 117;
			Enimes[10] = 134;
			Enimes[11] = 136;
			Enimes[12] = 158;
			Enimes[13] = 194;
			Enimes[14] = 195;
			Enimes[15] = 196;
			Enimes[16] = 198;
			Enimes[17] = 253;
			Enimes[18] = 272;
			Enimes[19] = 290;
			Enimes[20] = 293;
			Enimes[21] = 297;
			Enimes[22] = 311;
			Enimes[23] = 332;
			Enimes[24] = 335;
			Enimes[25] = 202;
			Enimes[26] = 224;
			Enimes[27] = 242;
			Enimes[28] = 264;
			Enimes[29] = 282;
			Enimes[30] = 266;
			Enimes[31] = 268;
			Enimes[32] = 150;
			Enimes[33] = 169;
			Enimes[34] = 172;
            break;
		case 93:
            ChangeOverLevels(LevelNintythree);
			Player[0] = 80;
			Player[1] = 600;
            KeysNeeded = 6;
			Fence[0] = 9;
            Fence[1] = 193;
            Fence[2] = 213;
			Fence[3] = 233;
			Fence[4] = 253;
			Fence[5] = 273;
			Fence[6] = 293;
			Fence[7] = 314;
			Fence[8] = 315;
			Fence[9] = 316;
            Lock[0] = 303;
            Lock[1] = 304;
			Lock[2] = 305;
			Lock[3] = 286;
			Lock[4] = 266;
			Lock[5] = 246;
			Lock[6] = 226;
			Lock[7] = 206;
			Lock[8] = 186;
			HasEnimes = true;
			HasSpikes = true;
            Enimes[1] = 26;
            Enimes[2] = 21;
            Enimes[3] = 29;
            Enimes[4] = 37;
			Enimes[5] = 42;
			Enimes[6] = 48;
			Enimes[7] = 50;
			Enimes[8] = 56;
			Enimes[9] = 58;
			Enimes[10] = 63;
			Enimes[11] = 67;
			Enimes[12] = 71;
			Enimes[13] = 75;
			Enimes[14] = 84;
			Enimes[15] = 86;
			Enimes[16] = 92;
			Enimes[17] = 94;
			Enimes[18] = 103;
			Enimes[19] = 105;
			Enimes[20] = 113;
			Enimes[21] = 115;
			Enimes[22] = 162;
			Enimes[23] = 145;
			Enimes[24] = 168;
			Enimes[25] = 151;
			Enimes[26] = 174;
			Enimes[27] = 157;
            break;
        default:
            EndScreen();
            break;
    }
    EndTransistionScreen();
}