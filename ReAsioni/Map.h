#include "DxLib.h"
#include "Player.h"
#include "MapData.h"
#include "Sound.h"

int data[300];

class Map {
public:
	int  chipgh[120];//マップチップ
    int X, Y;//プレイヤーのｘ，ｙ
    bool changing;//マップ切り替え中

	Map() {
		LoadDivGraph("img/AsioniMapChip.png", 120, 10, 12, 32, 32, chipgh);
        scene = 33;
        changing = false;
	}
    void PSetX(int px, Player* pl) {//マップ切り替え後のプレイヤーの座標調整
        pl->x = px;
        pl->targetX = px;
    }
    void PSetY(int py, Player* pl) {
        pl->y = py;
        pl->targetY = py;
    }
    void SceneChange(Player* pl) {//どんな条件でシーン切り替えをするか
        X = pl->x;
        Y = pl->y;
        if (changing == false && (scene == 2 && X < MAX_LEFT)) {
            scene = 1;
            changing = true;
        }
        else if (changing == false && (scene == 1 && X > MAX_RIGHT) || (scene == 3 && X < MAX_LEFT)) {
            scene = 2;
            changing = true;
        }
        else if (changing == false && ((scene == 2 && X > MAX_RIGHT) || (scene == 4 && Y > MAX_DOWN) || (scene == 8 && X < MAX_LEFT))) {
            scene = 3;
            changing = true;
        }
        else if (changing == false && ((scene == 3 && Y < MAX_UP))) {
            scene = 4;
            changing = true;
        }
        else if (changing == false && ((scene == 15 && X < MAX_LEFT && (Y == 288 || Y == 320)))) {
            scene = 4;
            PSetX(416, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 8 && Y < MAX_UP))) {
            scene = 5;
            changing = true;
        }
        else if (changing == false && ((scene == 7 && X < MAX_LEFT) || (scene == 9 && Y < MAX_UP))) {
            scene = 6;
            changing = true;
        }
        else if (changing == false && ((scene == 6 && X > MAX_RIGHT) || (scene == 10 && Y < MAX_UP) || (scene == 14 && X < MAX_LEFT) || (scene == 17 && Y > MAX_DOWN))) {
            scene = 7;
            changing = true;
        }
        else if (changing == false && ((scene == 5 && Y > MAX_DOWN) || (scene == 9 && X < MAX_LEFT) || (scene == 3 && X > MAX_RIGHT) || (scene == 11 && Y < MAX_UP))) {
            scene = 8;
            changing = true;
        }
        else if (changing == false && ((scene == 6 && Y > MAX_DOWN) || (scene == 8 && X > MAX_RIGHT) || (scene == 10 && X < MAX_LEFT) || (scene == 12 && Y < MAX_UP))) {
            scene = 9;
            changing = true;
        }
        else if (changing == false && ((scene == 7 && Y > MAX_DOWN) || (scene == 9 && X > MAX_RIGHT) || (scene == 13 && Y < MAX_UP))) {
            scene = 10;
            changing = true;
        }
        else if (changing == false && ((scene == 12 && X < MAX_LEFT) || (scene == 8 && Y > MAX_DOWN))) {
            scene = 11;
            changing = true;
        }
        else if (changing == false && ((scene == 9 && Y > MAX_DOWN) || (scene == 11 && X > MAX_RIGHT) || (scene == 13 && X < MAX_LEFT))) {
            scene = 12;
            changing = true;
        }
        else if (changing == false && ((scene == 10 && Y > MAX_DOWN) || (scene == 12 && X > MAX_RIGHT))) {
            scene = 13;
            changing = true;
        }
        else if (changing == false && ((scene == 7 && X > MAX_RIGHT) || (scene == 17 && Y > MAX_DOWN))) {
            scene = 14;
            changing = true;
        }
        else if (changing == false && ((scene == 4 && X > 416 && (Y == 288|| Y == 320)))) {
            scene = 15;
            PSetX(0, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 16 && X < MAX_LEFT))) {
            scene = 15;
            changing = true;
        }
        else if (changing == false && ((scene == 18 && Y > MAX_DOWN))) {
            scene = 15;
            PSetY(64, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 15 && X > MAX_RIGHT) || (scene == 17 && X < MAX_LEFT))) {
            scene = 16;
            changing = true;
        }
        else if (changing == false && ((scene == 7 && Y < MAX_UP) || (scene == 16 && X > MAX_RIGHT))) {
            scene = 17;
            changing = true;
        }
        else if (changing == false && ((scene == 15 && Y < 52 && 125 >= X && X >= -3))) {
            scene = 18;
            PSetY(416, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 19 && X == 160 && CheckHitKey(KEY_INPUT_LEFT) && Y == 128))) {
            scene = 18;
            PSetX(128, pl);
            PSetY(352, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 18 && X > 128 && Y == 352))) {
            scene = 19;
            PSetX(160, pl);
            PSetY(128, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 20 && X < MAX_LEFT))) {
            scene = 19;
            changing = true;
        }
        else if (changing == false && ((scene == 22 && Y > MAX_DOWN))) {
            scene = 19;
            PSetY(64, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 19 && X > MAX_RIGHT) || (scene == 21 && X < MAX_LEFT) || (scene == 31 && Y > MAX_DOWN))) {
            scene = 20;
            changing = true;
        }
        else if (changing == false && (scene == 31 && Y > MAX_DOWN)) {
            PSetY(192, pl);
            scene = 20;
            PSetX(288, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 20 && X > MAX_RIGHT))) {
            scene = 21;
            changing = true;
        }
        else if (changing == false && ((scene == 32 && Y > MAX_DOWN))) {
            scene = 21;
            PSetY(192, pl);
            PSetX(64, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 19 && Y < 52 && 125 >= X && X >= -3))) {
            scene = 22;
            PSetY(416, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 23 && X == 160 && CheckHitKey(KEY_INPUT_LEFT) && Y == 128))) {
            scene = 22;
            PSetX(128, pl);
            PSetY(352, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 22 && X > 128 && Y == 352))) {
            scene = 23;
            PSetX(160, pl);
            PSetY(128, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 33 && Y > MAX_DOWN))) {
            scene = 23;
            PSetY(192, pl);
            PSetX(384, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 24 && X < MAX_LEFT))) {
            scene = 23;
            changing = true;
        }
        else if (changing == false && ((scene == 23 && X > MAX_RIGHT) || (scene == 25 && X < MAX_LEFT))) {
            scene = 24;
            changing = true;
        }
        else if (changing == false && ((scene == 34 && Y > MAX_DOWN))) {
            scene = 24;
            PSetY(192, pl);
            PSetX(288, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 35 && Y == 96) && CheckHitKey(KEY_INPUT_UP) && (X == 64 || X == 96))) {
            scene = 24;
            PSetY(352, pl);
            PSetX(96, pl);
            changing = true;
        }
        else if (changing == false && ((scene == 24 && X > MAX_RIGHT))) {
            scene = 25;
            changing = true;
        }
        else if (changing == false && (scene == 21 && CheckHitKey(KEY_INPUT_RETURN) && ((96 >= X && X >= 64 && Y == 224) || (544 >= X && X >= 512 && Y == 224)))) {
            scene = 32;
            PSetY(448, pl);
            PlaySoundFile("sound/dore.mp3", DX_PLAYTYPE_NORMAL);
            changing = true;
        }
        else if (changing == false && CheckHitKey(KEY_INPUT_RETURN) && (scene == 23 && 416 >= X && X >= 384 && Y == 224)) {
            scene = 33;
            PSetY(448, pl);
            PlaySoundFile("sound/dore.mp3", DX_PLAYTYPE_NORMAL);
            changing = true;
        }
        else if (changing == false && CheckHitKey(KEY_INPUT_RETURN) && (scene == 24 && 128 >= X && X >= 96 && Y == 224)) {
            scene = 33;
            PSetY(448, pl);
            PlaySoundFile("sound/dore.mp3", DX_PLAYTYPE_NORMAL);
            changing = true;
        }
        else if (changing == false && CheckHitKey(KEY_INPUT_RETURN) && (scene == 24 && ((320 >= X && X >= 288 && Y == 224) || (608 >= X && X >= 576 && Y == 224)))) {
            scene = 34;
            PlaySoundFile("sound/dore.mp3", DX_PLAYTYPE_NORMAL);
            PSetY(448, pl);
            changing = true;
        }
        else if (changing == false && CheckHitKey(KEY_INPUT_RETURN) && (scene == 24 && ((128 >= X && X >= 96 && Y == 352)))) {
            scene = 35;
            PlaySoundFile("sound/dore.mp3", DX_PLAYTYPE_NORMAL);
            PSetX(64, pl);
            PSetY(96, pl);
            changing = true;
        }
        else {
            changing = false;
        }
    }
    void ViewChange() {//シーン切り替え
        switch (scene){
        case 0:
            for (int i = 0; i < 300; i++)data[i] = data0[i];
            break;
        case 1:
            for (int i = 0; i < 300; i++)data[i] = data1[i];
            break;
        case 2:
            for (int i = 0; i < 300; i++)data[i] = data2[i];
            break;
        case 3:
            for (int i = 0; i < 300; i++)data[i] = data3[i];
            break;
        case 4:
            for (int i = 0; i < 300; i++)data[i] = data4[i];
            break;
        case 5:
            for (int i = 0; i < 300; i++)data[i] = data5[i];
            break;
        case 6:
            for (int i = 0; i < 300; i++)data[i] = data6[i];
            break;
        case 7:
            for (int i = 0; i < 300; i++)data[i] = data7[i];
            break;
        case 8:
            for (int i = 0; i < 300; i++)data[i] = data8[i];
            break;
        case 9:
            for (int i = 0; i < 300; i++)data[i] = data9[i];
            break;
        case 10:
            for (int i = 0; i < 300; i++)data[i] = data10[i];
            break;
        case 11:
            for (int i = 0; i < 300; i++)data[i] = data11[i];
            break;
        case 12:
            for (int i = 0; i < 300; i++)data[i] = data12[i];
            break;
        case 13:
            for (int i = 0; i < 300; i++)data[i] = data13[i];
            break;
        case 14:
            for (int i = 0; i < 300; i++)data[i] = data14[i];
            break;
        case 15:
            for (int i = 0; i < 300; i++)data[i] = data15[i];
            break;
        case 16:
            for (int i = 0; i < 300; i++)data[i] = data16[i];
            break;
        case 17:
            for (int i = 0; i < 300; i++)data[i] = data17[i];
            break;
        case 18:
            for (int i = 0; i < 300; i++)data[i] = data18[i];
            break;
        case 19:
            for (int i = 0; i < 300; i++)data[i] = data19[i];
            break;
        case 20:
            for (int i = 0; i < 300; i++)data[i] = data20[i];
            break;
        case 21:
            for (int i = 0; i < 300; i++)data[i] = data21[i];
            break;
        case 22:
            for (int i = 0; i < 300; i++)data[i] = data22[i];
            break;
        case 23:
            for (int i = 0; i < 300; i++)data[i] = data23[i];
            break;
        case 24:
            for (int i = 0; i < 300; i++)data[i] = data24[i];
            break;
        case 25:
            for (int i = 0; i < 300; i++)data[i] = data25[i];
            break;
        case 31:
            for (int i = 0; i < 300; i++)data[i] = data31[i];
            break;
        case 32:
            for (int i = 0; i < 300; i++)data[i] = data32[i];
            break;
        case 33:
            for (int i = 0; i < 300; i++)data[i] = data33[i];
            break;
        case 34:
            for (int i = 0; i < 300; i++)data[i] = data34[i];
            break;
        case 35:
            for (int i = 0; i < 300; i++)data[i] = data35[i];
            break;
        }
    }
    void WalkSound(Walk* walk, Player* pl, int no) {//足音
        switch (no) {
        case 1:
            if (pl->walkFlag) {
                walk->Grass();
                walk->StopConcrete();
                walk->StopFloor();
            }
            break;
        case 2:
            if (pl->walkFlag) {
                walk->Floor();
                walk->StopConcrete();
                walk->StopGrass();
            }
            break;
        case 3:
            if (pl->walkFlag) {
                walk->Concrete();
                walk->StopFloor();
                walk->StopGrass();
            }
            break;
        }
    }
    void View(Walk* walk, Player* pl) {//マップ表示
        if (pl->walkFlag == false)walk->Stop();
        for (int j = 0; j < 15; j++) {
            for (int i = 0; i < 20; i++) {
                int no = data[i + j * 20];
                DrawGraph(i * 32, j * 32, chipgh[no], FALSE);

                if (no == 8 || (no >= 7 && no <= 9) || (no >= 17 && no <= 19) || (no >= 27 && no <= 29) || (no >= 37 && no <= 39) ||
                    (no >= 47 && no <= 49) || no == 100 || no == 101 || (no >= 112 && no <= 114) ){//足音：ゆか
                    if ((X + 32 > i * 32 && X < i * 32 && Y == j * 32) || (X < i * 32 + 32 && X > i * 32 && Y == j * 32) || (Y < j * 32 + 32 && Y > j * 32 && X == i * 32) || (Y + 32 > j * 32 && Y < j * 32 && X == i * 32)) {
                        WalkSound(walk, pl, 2);
                    }
                }
                else if (no == 6 || no == 10 || no == 14 || (no >= 23 && no <= 24) || (no >= 32 && no <= 33) || (no >= 42 && no <= 43) ||
                    (no >= 52 && no <= 56) || no == 59 || (no >= 65 && no <= 66) || no == 69 || (no >= 75 && no <= 79) || (no >= 102 && no <= 103) ||
                    (no >= 110 && no <= 111) || no == 115) {//足音：コンクリ
                    if ((X + 32 > i * 32 && X < i * 32 && Y == j * 32) || (X < i * 32 + 32 && X > i * 32 && Y == j * 32) || (Y < j * 32 + 32 && Y > j * 32 && X == i * 32) || (Y + 32 > j * 32 && Y < j * 32 && X == i * 32)) {
                        WalkSound(walk, pl, 3);
                    }
                }
                else if(scene == 18 || scene == 22 || scene > 30) {
                    if ((X + 32 > i * 32 && X < i * 32 && Y == j * 32) || (X < i * 32 + 32 && X > i * 32 && Y == j * 32) || (Y < j * 32 + 32 && Y > j * 32 && X == i * 32) || (Y + 32 > j * 32 && Y < j * 32 && X == i * 32)) {
                        WalkSound(walk, pl, 2);
                    }
                }
                else {//足音：草
                    if ((X + 32 > i * 32 && X < i * 32 && Y == j * 32) || (X < i * 32 + 32 && X > i * 32 && Y == j * 32) || (Y < j * 32 + 32 && Y > j * 32 && X == i * 32) || (Y + 32 > j * 32 && Y < j * 32 && X == i * 32)) {
                        WalkSound(walk, pl, 1);
                    }
                }
            }
        }
    }
    void WallU(Player* pl) {//UP
        X = pl->x;
        Y = pl->y;
        if (Y < MAX_UP + 1 && changing == false) {
            pl->y = MAX_UP;
            pl->targetY = MAX_UP;
        }
    }
    void WallD(Player* pl) {//DOWN
        X = pl->x;
        Y = pl->y;
        if (Y > MAX_DOWN - 1&& changing == false) {
            pl->y = MAX_DOWN;
            pl->targetY = MAX_DOWN;
        }
    }
    void WallR(Player* pl) {//RIGHT
        X = pl->x;
        Y = pl->y;
        if (X > MAX_RIGHT - 1 && changing == false) {
            pl->x = MAX_RIGHT;
            pl->targetX = MAX_RIGHT;
        }
    }
    void WallL(Player* pl) {//LEFT
        X = pl->x;
        Y = pl->y;
        if (X < MAX_LEFT + 1 && changing == false) {
            pl->x = MAX_LEFT;
            pl->targetX = MAX_LEFT;
        }
    }
    void WalkArea(Player* pl) {//歩けない場所決め
        X = pl->x;
        Y = pl->y;
        for (int j = 0; j < 15; j++) {
            for (int i = 0; i < 20; i++) {
                int no = data[i + j * 20];
                if (no >= 0 && no <= 4 || no >= 10 && no <= 13 || no == 15 || no == 16 || no >= 20 && no <= 22 || no >= 25 && no <= 26 ||
                    no >= 30 && no <= 31 || no >= 34 && no <= 36 || no >= 40 && no <= 41 || no >= 44 && no <= 46 || no >= 50 && no <= 51 ||
                    no >= 57 && no <= 58 || no >= 67 && no <= 68 || no >= 77 && no <= 78 || no == 80 || no == 60 || no == 61 ||
                    no >= 63 && no <= 64 || no == 70 || no == 71 || no >= 73 && no <= 74 || no >= 84 && no <= 89 || no >= 90 && no <= 99 ||
                    no >= 104 && no <= 109 || no == 7 || no == 19 || no == 29 || no == 114) {//ここに歩けないマップチップを保存
                    if (Y + 32 > j * 32 && Y < j * 32 && X == i * 32) {//下
                        pl->y -= pl->speed;
                        pl->targetY = pl->y;
                    }
                    if (Y < j * 32 + 32 && Y > j * 32 && X == i * 32) {//上
                        pl->y += pl->speed;
                        pl->targetY = pl->y;
                    }
                    if (X < i * 32 + 32 && X > i * 32 && Y == j * 32) {//左
                        pl->x += pl->speed;
                        pl->targetX = pl->x;
                    }
                    if (X + 32 > i * 32 && X < i * 32 && Y == j * 32) {//右
                        pl->x -= pl->speed;
                        pl->targetX = pl->x;
                    }
                }
            }
        }

        switch (scene) {
        case 1:
            WallU(pl);
            WallD(pl);
            WallL(pl);
            break;
        case 2:
            WallU(pl);
            WallD(pl);
            break;
        case 3:
            WallD(pl);
            break;
        case 4:
            WallL(pl);
            break;
        case 5:
            WallU(pl);
            WallL(pl);
            break;
        case 10:
            WallR(pl);
            break;
        case 11:
            WallD(pl);
            WallL(pl);
            break;
        case 12:
            WallD(pl);
            break;
        case 13:
            WallD(pl);
            WallR(pl);
            break;
        case 14:
            WallU(pl);
            WallD(pl);
            WallR(pl);
            break;
        case 15:
            WallD(pl);
            WallL(pl);
            break;
        case 16:
            WallD(pl);
            break;
        case 17:
            WallR(pl);
            break;
        case 18:
            WallL(pl);
            break;
        case 19:
            WallL(pl);
            break;
        case 21:
            WallR(pl);
            break;
        case 22:
            WallL(pl);
            break;
        case 23:
            WallU(pl);
            WallL(pl);
            break;
        case 25:
            WallR(pl);
            break;
        case 32:
            WallL(pl);
            WallR(pl);
            break;
        case 33:
            WallL(pl);
            WallR(pl);
            break;
        case 34:
            WallL(pl);
            WallR(pl);
            break;
        case 35:
            WallD(pl);
            WallL(pl);
            WallR(pl);
            break;
        default:
            break;
        }
    }
    void Test() {
        DrawFormatString(10, 30, GetColor(100, 200, 200), "シーン%d", scene);
    }
    void All(Player* pl, Walk* walk) {
        SceneChange(pl);
        ViewChange();
        View(walk, pl);
        WalkArea(pl);
    }
    void Reset() {
        scene = 33;
        changing = false;
    }
};