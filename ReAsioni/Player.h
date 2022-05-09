#pragma once

#include <DxLib.h>

#define WALKTIME 15
#define CELL 32//��}�X������̉��A�c�̑傫��
#define MAX_RIGHT 608//�}�b�v�̒[
#define MAX_LEFT 0
#define MAX_UP 0
#define MAX_DOWN 448

class Player {
public:
	int gh[12];//�L�����̉摜
    int width, height;//�L�����̕��A����
    int walkVec;//�L�����̌����Ă������
    int animCount;//�������[�V�����Ŏg�p
    bool walkFlag;//�����Ă��邩���Ȃ���
    int x, y;//�O���t�B�b�N��`�悷����W
    int targetX, targetY;//�v���C���[�����Ɍ������ׂ����W�B���݈ʒu�ׂ̗̃}�X�̂ǂꂩ
    int speed;//�L�����̕����X�s�[�h
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
        if (targetX == x && targetY == y) {//�ړ����łȂ����
            if (CheckHitKey(KEY_INPUT_DOWN)) {
                walkFlag = true;
                walkVec = 2;
                targetY += CELL;//targetY��1�}�X���ړ�
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
                animCount = 0;//�L�[��������Ă��炸�A�ړ����������Ă����animCount�����Z�b�g
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
        int animState = animCount / WALKTIME;//animCount��WALKTIME�̌��{���ɂȂ邽�т�animState��1������
        if (animState == 4) {//animState��4�ɂȂ����烊�Z�b�g
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
        DrawCircle(x, y, 2, Black, 1);//����
        DrawCircle(x, y + 32, 2, Black, 1);//����
        DrawCircle(x + 32, y + 32, 2, Black, 1);//�E��
        DrawCircle(x + 32, y, 2, Black, 1);//�E��

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