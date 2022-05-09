#pragma once

#include <DxLib.h>

#define WALKTIME 15
#define CELL 32//一マスあたりの横、縦の大きさ
#define MAX_RIGHT 608//マップの端
#define MAX_LEFT 0
#define MAX_UP 0
#define MAX_DOWN 448

class Player {
public:
	int gh[12];//キャラの画像
    int width, height;//キャラの幅、高さ
    int walkVec;//キャラの向いている方向
    int animCount;//歩きモーションで使用
    bool walkFlag;//歩いているかいないか
    int x, y;//グラフィックを描画する座標
    int targetX, targetY;//プレイヤーが次に向かうべき座標。現在位置の隣のマスのどれか
    int speed;//キャラの歩くスピード
    int Black = GetColor(255, 255, 255);

    Player() {
        LoadDivGraph("img/Chara.png", 12, 3, 4, 20, 28, gh);
        //LoadDivGraph("img/otoko.png", 12, 3, 4, 32, 32, gh);
        GetGraphSize(gh[0], &width, &height);
        walkVec = 2;
        walkFlag = false;
        animCount = 0;
        x = 128;//
        y = 96;//
        speed = 2;
        targetX = 128;//
        targetY = 96;//
    }

    void AnimationView(int animState, int firstNum) {
        if (animState == 0)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[firstNum], TRUE);
        if (animState == 1)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[firstNum + 1], TRUE);
        if (animState == 2)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[firstNum + 2], TRUE);
        if (animState == 3)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[firstNum + 1], TRUE);
       /* if (animState == 0)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[firstNum], TRUE);
        if (animState == 1)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[firstNum + 1], TRUE);
        if (animState == 2)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[firstNum + 2], TRUE);
        if (animState == 3)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[firstNum + 1], TRUE);*/
    }

    void Move() {
        walkFlag = false;
        if (targetX == x && targetY == y) {//移動中でなければ
            if (CheckHitKey(KEY_INPUT_DOWN)) {
                walkFlag = true;
                walkVec = 2;
                targetY += CELL;//targetYを1マス分移動
            }
            else if (CheckHitKey(KEY_INPUT_LEFT)) {
                walkFlag = true;
                walkVec = 4;
                targetX -= CELL;
            }
            else if (CheckHitKey(KEY_INPUT_RIGHT)) {
                walkFlag = true;
                walkVec = 6;
                targetX += CELL;
            }
            else if (CheckHitKey(KEY_INPUT_UP)) {
                walkFlag = true;
                walkVec = 8;
                targetY -= CELL;
            }
            else {
                animCount = 0;//キーが押されておらず、移動が完了していればanimCountをリセット
            }
        }
        else {
            walkFlag = true;
        }

        if (y < MAX_UP)
        {
            y = MAX_DOWN;
            targetY = MAX_DOWN;
        }
        if (y > MAX_DOWN) {
            y = MAX_UP;
            targetY = MAX_UP;
        }
        if (x < MAX_LEFT) {
            x = MAX_RIGHT;
            targetX = MAX_RIGHT;
        }
        if (x > MAX_RIGHT) {
            x = MAX_LEFT;
            targetX = MAX_LEFT;
        }

        if (y < targetY)y += speed;
        if (x > targetX)x -= speed;
        if (x < targetX)x += speed;
        if (y > targetY)y -= speed;
    }

    void View() {
        int animState = animCount / WALKTIME;//animCountがWALKTIMEの公倍数になるたびにanimStateが1増える
        if (animState == 4) {//animStateが4になったらリセット
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
            if (walkVec == 2)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[1], TRUE);
            if (walkVec == 4)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[4], TRUE);
            if (walkVec == 6)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[7], TRUE);
            if (walkVec == 8)DrawExtendGraph(x - 5, y - CELL, x + width + 18, y + height - 5, gh[10], TRUE);
            /*if (walkVec == 2)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[1], TRUE);
            if (walkVec == 4)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[4], TRUE);
            if (walkVec == 6)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[7], TRUE);
            if (walkVec == 8)DrawExtendGraph(x, y - 16, x + width, y + 16, gh[10], TRUE);*/
        }
    }

    void Test() {
        DrawCircle(x, y, 2, Black, 1);//左上
        DrawCircle(x, y + 32, 2, Black, 1);//左下
        DrawCircle(x + 32, y + 32, 2, Black, 1);//右下
        DrawCircle(x + 32, y, 2, Black, 1);//右上

        DrawFormatString(0, 450, Black , "[%d,%d]", x, y);
    }
    void All() {
        Move();
        View();
    }
    void Reset() {
        walkVec = 2;
        walkFlag = false;
        animCount = 0;
        x = 128;//
        y = 96;//
        speed = 2;
        targetX = 128;//
        targetY = 96;//
    }
};