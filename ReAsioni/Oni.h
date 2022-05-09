#include "DxLib.h"
#include "Basic.h"
#include "Sound.h"
#include "Player.h"

class Oni {
public:
    int gh[12];//鬼のグラフィック
    int width, height;//鬼の幅、高さ
    int walkVec;//向ている方向
    int animCount;//アニメーションで使用
    bool walkFlag;//止まっているか進んでいるか
    int targetX, targetY;//鬼の進む座標
    int x, y;//鬼の座標
    float speed;//鬼のスピード
    int X, Y;//プレイヤーの座標
    int timer;//時間
    int ChaseTime;//追いかけてくる時間
    bool Chasing;//追いかけ中か否か
    bool XYSet;//座標設定を一度だけにするために使用
    bool OK;//鬼が出てきてよいか
    float Xdis; //鬼とプレイヤーの距離
    float Ydis; //
    bool outside; //プレイヤーが画面外に行けばtrue
    bool a; //階段の踊り場での鬼の座標を設定するのに使用
    int Black = GetColor(0, 0, 0);

    Oni() {
        LoadDivGraph("img/Oni.png", 12, 3, 4, 100, 200, gh);
        walkVec = 2;
        walkFlag = false;
        animCount = 0;
        x = 32;
        y = 32;
        speed = 2.1;
        targetX = 32;//
        targetY = 32;//
        timer = 0;
        ChaseTime = 60;
        Chasing = false;
        XYSet = true;
        OK = false;
        Xdis = 0;
        Ydis = 0;
        outside = false;
        a = true;
        for (int i = 0; i < 12; i++) {
            GraphFilter(gh[i], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_GREATER, 180, TRUE, GetColor(0, 0, 0), 0);
        }
    }
    void Move(Player* pl) {
        walkFlag = false;
        X = pl->x;
        Y = pl->y;
        if (targetX == x && targetY == y) {
            if (x < X) {
                walkVec = 6;
                targetX += CELL;
            }
            else if (x > X) {
                walkVec = 4;
                targetX -= CELL;
            }
            else if (y > Y) {
                walkVec = 8;
                targetY -= CELL;
            }
            else if (y < Y) {
                walkVec = 2;
                targetY += CELL;
            }
        }
        else {
            walkFlag = true;
        }

        //上に行くのと左に行くのがなぜかスピードがはやい
        if (x > targetX)x -= speed / 2;
        if (y < targetY)y += speed;
        if (y > targetY)y -= speed / 2;
        if (x < targetX)x += speed;

        if (OK && Y > MAX_DOWN) {
            y = MAX_UP - CELL * 3;
            targetY = y;
        }
        if (OK && Y < MAX_UP) {
            y = MAX_DOWN + CELL * 3;
            targetY = y;
        }
        if (OK && X > MAX_RIGHT) {
            x = MAX_LEFT - CELL * 3;
            targetX = x;
        }
        if (OK && X < MAX_LEFT) {
            x = MAX_RIGHT + CELL * 3;
            targetX = x;
        }

        //プレイヤーとの距離を補正するプログラム
        Xdis = X - x;
        Ydis = Y - y;
        if (Xdis < 0)Xdis *= -1;
        if (Ydis < 0)Ydis  *= -1;
        if (Xdis < 3 && x != X && walkVec != pl->walkVec) {
            x = X;
            targetX = X;
        }
        if (Ydis < 3 && y != Y && walkVec != pl->walkVec) {
            y = Y;
            targetY = y;
        }

        if (X > MAX_RIGHT || X < MAX_LEFT || Y > MAX_DOWN || Y < MAX_UP) outside = true;
        else outside = false;
    }
    void AnimationView(int animState, int firstNum) {
        if (animState == 0)DrawExtendGraph(x - 15, y - CELL - 10 ,  x + CELL + 15, y + CELL - 10 , gh[firstNum], TRUE);
        if (animState == 1)DrawExtendGraph(x - 15, y - CELL - 10 ,  x + CELL + 15, y + CELL - 10 , gh[firstNum + 1], TRUE);
        if (animState == 2)DrawExtendGraph(x - 15, y - CELL - 10 ,  x + CELL + 15, y + CELL - 10 , gh[firstNum + 2], TRUE);
        if (animState == 3)DrawExtendGraph(x - 15, y - CELL - 10 ,  x + CELL + 15, y + CELL - 10 , gh[firstNum + 1], TRUE);
    }
    void View() {
        int animState = animCount / WALKTIME;
        if (animState == 4) {
            animCount = 0;
            animState = 0;
        }
        if (walkFlag) {
            if (walkVec == 2)AnimationView(animState, 0);
            if (walkVec == 4)AnimationView(animState, 3);
            if (walkVec == 6)AnimationView(animState, 6);
            if (walkVec == 8)AnimationView(animState, 9);
            animCount++;
        }
        else {
            if (walkVec == 2)DrawExtendGraph(x - 10, y - CELL - 10, x + CELL + 15, y + CELL - 10, gh[1], TRUE);
            if (walkVec == 4)DrawExtendGraph(x - 10, y - CELL - 10, x + CELL + 15, y + CELL - 10, gh[4], TRUE);
            if (walkVec == 6)DrawExtendGraph(x - 10, y - CELL - 10, x + CELL + 15, y + CELL - 10, gh[7], TRUE);
            if (walkVec == 8)DrawExtendGraph(x - 10, y - CELL - 10, x + CELL + 15, y + CELL - 10, gh[10], TRUE);
        }
    }
    void CountControl() {
        if (XYSet) {
            switch (Count) {//ここで何秒間追いかけるかと出現する座標を決定
            case 3:
                x = 320;
                targetX = 320;
                y = 224;
                targetY = 224;
                ChaseTime = 1500;
                break;
            case 7:
                x = 192;
                targetX = 192;
                y = 192;
                targetY = 192;
                ChaseTime = 1800;
                break;
            case 11:
                x = 384;
                targetX = 384;
                y = 192;
                targetY = 192;
                ChaseTime = 2200;
                break;
            case 14:
                x = 192;
                targetX = 192;
                y = 64;
                targetY = 64;
                ChaseTime = 2600;
                break;
            default:
                break;
            }
            XYSet = false;
        }
        if (timer >= ChaseTime && outside) {
            Count++;
        }
    }
    void SpeedControl() {
        if (timer < ChaseTime) {
            if (timer > 1000 && timer < 1500)speed = 2.4;
            if (timer > 1500 && timer < 2000)speed = 2.8;
            if (timer > 2000 && timer < 2500)speed = 3.2;
            if (timer > 2500)speed = 3.6;
        }
    }
    void OrderCheck(int scene) {
        if (Count == 3 && scene == 20) {
            OK = true;
        }
        else if (Count == 7 && scene == 4) {
            OK = true;
        }
        else if (Count == 11 && scene == 8) {//***********************************************************************************
            OK = true;
        }
        else if (Count == 14 && scene == 7) {
            OK = true;
        }
        if (!(Count == 3 || Count == 7 || Count == 11 || Count == 14)) {
            OK = false;
        }
        if (a && OK) {
            if (scene == 18 || scene == 22) {
                x = 256;
                targetX = 256;
                y = 352;
                targetY = 352;
                a = false;
            }
            else {
                a = true;
            }
        }
    }
    void BGM(OniVoice* voice) {
        if (OK) {
            voice->All();
        }
    }
    void Test() {
        DrawCircle(x, y, 2, Black, 1);//左上
        DrawCircle(x, y + 32, 2, Black, 1);//左下
        DrawCircle(x + 32, y + 32, 2, Black, 1);//右下
        DrawCircle(x + 32, y, 2, Black, 1);//右上
        DrawFormatString(10, 10, GetColor(100,200,200), "%d", timer);
    }
    void All(Player * pl, OniVoice* voice, int scene) {
        OrderCheck(scene);
        if (OK) {
            timer++;
            View();
            Move(pl);
            CountControl();
            SpeedControl();
            BGM(voice);
        }
        else {
            timer = 0;
            XYSet = true;
            StopMusic();
        }
    }
    void Reset() {
        walkVec = 2;
        walkFlag = false;
        animCount = 0;
        x = 32;
        y = 32;
        speed = 2.1;
        targetX = 32;//
        targetY = 32;//
        timer = 0;
        ChaseTime = 60;
        Chasing = false;
        XYSet = true;
        OK = false;
        Xdis = 0;
        Ydis = 0;
        outside = false;
        a = true;
    }
};

class MobEvent {
public:
    int x1, y1, x2, y2; //キャラ1,キャラ2の座標
    int gh[4]; //キャラの画像
    int Ogh; //鬼の画像
    int Etime; //イベント時間
    bool h1, h2; //フェーズ１，２
    bool XYSet; //座標の設定を重複させないために使用
    int timer; //timer
    bool blad; //血の画像を表示
    bool OK; //
    int sound1; //悲鳴
    int sound2; //芦鬼ボイス
    int sound3; //芦鬼ボイス
    int SoundA; //どの芦鬼ボイスを使うのかの判断に使用

    MobEvent() {
        LoadDivGraph("img/Mob.png", 4, 1, 4, 32, 48, gh);
        Ogh = LoadGraph("img/OniEvent.png");
        x1 = 560;
        x2 = 600;
        y1 = 80;
        y2 = 80;
        Etime = 0;
        h1 = true;
        h2 = true;
        XYSet = true;
        timer = 0;
        blad = false;
        OK = false;
        sound1 = LoadSoundMem("sound/AHosyoku/hensin.mp3");
        sound2 = LoadSoundMem("sound/AHosyoku/hosiika.mp3");
        sound3 = LoadSoundMem("sound/AHosyoku/osiete.mp3");
        SoundA = 0;
    }
    void View() {
        DrawGraph(x1, y1, gh[2], TRUE);
        DrawGraph(x2, y1, gh[1], TRUE);
        DrawExtendGraph(x1, y1 - 80, x1 + 60, y1, Ogh, TRUE);
    }
    void Start() {
        if (Etime < 420) {
            Etime++;
            View();
        }
        if (Etime > 120 && Etime < 420) {
            if (h1) {
                PlaySoundMem(SoundA, DX_PLAYTYPE_NORMAL, TRUE);
                PlaySoundFile("sound/himei.mp3", DX_PLAYTYPE_NORMAL);
            }
            h1 = false;
            DrawBox(x1 - 5, y1 - 80, x1 + 70, y1 + 50, GetColor(0, 0, 0), TRUE);
        }
        if (Etime > 200 && Etime < 420) {
            if (h2)PlaySoundFile("sound/lunchTime.mp3", DX_PLAYTYPE_NORMAL);
            h2 = false;
            blad = true;
        }
        if (Etime > 420)blad = true;
    }
    void Blad(int scene) {
        if (blad) {
            switch (scene) {
            case 23:
                if (Count == 2 || Count == 3 || Count == 4)LoadGraphScreen(x1 - 10, y1, "img/blad.png", TRUE);
                break;
            case 13:
                if (Count == 6 || Count == 7 || Count == 8 || Count == 9 || Count == 10 || Count == 11 || Count == 12)LoadGraphScreen(x1 - 10, y1, "img/blad.png", TRUE);
                break;
            case 7:
                if (Count == 14 || Count == 15)LoadGraphScreen(x1 - 10, y1, "img/blad.png", TRUE);
                break;
            default:
                break;
            }
        }
    }
    void Set(int scene) {
        if (XYSet) {
            switch (scene) {
            case 23:
                x1 = 125;
                y1 = 244;
                x2 = 165;
                SoundA = sound1;
                break;
            case 13:
                x1 = 381;
                y1 = 212;
                x2 = 421;
                SoundA = sound2;
                break;
            case 7:
                x1 = 189;
                y1 = 84;
                x2 = 229;
                SoundA = sound3;
                break;
            default:
                break;
            }
            XYSet = false;
        }
    }
    void OrderCheck(int scene) {
        if (Count == 1 && scene == 23) {
            OK = true;
        }
        else if (Count == 5 && scene == 13) {
            OK = true;
        }
        else if (Count == 13 && scene == 7) {
            OK = true;
        }
        else {
            OK = false;
        }
    }
    void NextCount() {
        if (timer > 240 && timer < 242) {
            Count++;
        }
    }
    void All(int scene) {
        OrderCheck(scene);
        if (OK) {
            timer++;
            Set(scene);
            Start();
            NextCount();
        }
        else {
            XYSet = true;
            timer = 0;
            Etime = 0;
            h1 = true;
            h2 = true;
        }
        Blad(scene);
    }
    void Reset() {
        x1 = 560;
        x2 = 600;
        y1 = 80;
        y2 = 80;
        Etime = 0;
        h1 = true;
        h2 = true;
        XYSet = true;
        timer = 0;
        blad = false;
        OK = false;
        SoundA = 0;
    }
};