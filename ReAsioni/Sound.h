#pragma once
#include "DxLib.h"

class Walk {
public:
    int grass;
    int floor;
    int concrete;

    Walk() {
        grass = LoadSoundMem("sound/grass.mp3");
        floor = LoadSoundMem("sound/floor.mp3");
        concrete = LoadSoundMem("sound/concrete.mp3");
    }
    void Grass() {
        if (CheckSoundMem(grass) == 0)PlaySoundMem(grass, DX_PLAYTYPE_BACK, TRUE);
    }
    void StopGrass() {
        StopSoundMem(grass);
    }
    void Floor() {
        if (CheckSoundMem(floor) == 0)PlaySoundMem(floor, DX_PLAYTYPE_BACK, TRUE);
    }
    void StopFloor() {
        StopSoundMem(floor);

    }
    void Concrete() {
        if (CheckSoundMem(concrete) == 0)PlaySoundMem(concrete, DX_PLAYTYPE_BACK, TRUE);
    }
    void StopConcrete() {
        StopSoundMem(concrete);
    }
    void Stop() {
        StopConcrete();
        StopFloor();
        StopGrass();
    }
};

class OniVoice {
public:
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int s6;
    int s7;
    int s8;
    int s9;
    int s10;
    int s11;
    int s12;
    int Bgm;
    int word;
    int R;
    bool a, b;
    int timer;

    OniVoice() {
        s1 = LoadSoundMem("sound/AChase/gyoe.mp3");
        s2 = LoadSoundMem("sound/AChase/hasiruna.mp3");
        s3 = LoadSoundMem("sound/AChase/mate.mp3");
        s4 = LoadSoundMem("sound/AChase/rakutan.mp3");
        s5 = LoadSoundMem("sound/AChase/tabe1.mp3");
        s6 = LoadSoundMem("sound/AChase/tabe2.mp3");
        s7 = LoadSoundMem("sound/AChase/tabe3.mp3");
        s8 = LoadSoundMem("sound/AChase/tairyou.mp3");
        s9 = LoadSoundMem("sound/AChase/tomare.mp3");
        s10 = LoadSoundMem("sound/AHosyoku/hensin.mp3");
        s11 = LoadSoundMem("sound/AHosyoku/hosiika.mp3");
        s12 = LoadSoundMem("sound/AHosyoku/osiete.mp3");
        R = 0;
        Bgm = LoadSoundMem("sound/AChase/bgm.mp3");
        a = true;
        b = false;
        timer = 0;
    }
    void RandamVoice() {
        R = GetRand(8) + 1;
        if (a) {
            switch (R) {
            case 1:
                word = s1;
                a = false;
                break;
            case 2:
                word = s2;
                a = false;
                break;
            case 3:
                word = s3;
                a = false;
                break;
            case 4:
                word = s4;
                a = false;
                break;
            case 5:
                word = s5;
                a = false;
                break;
            case 6:
                word = s6;
                a = false;
                break;
            case 7:
                word = s7;
                a = false;
                break;
            case 8:
                word = s8;
                a = false;
                break;
            case 9:
                word = s9;
                a = false;
                break;
            default:
                break;
            }
        }
    }
    void PlaySou() {
        timer++;

        if ((timer % 240 == 0 || timer == 10) && CheckSoundMem(word) == 0) {
            PlaySoundMem(word, DX_PLAYTYPE_BACK, TRUE);
            a = true;
            b = false;
        }
        if (timer == 490)timer = 0;
    }
    void PlayBGM() {
        if (CheckMusic() == 0)PlayMusic("sound/AChase/bgm.mp3", DX_PLAYTYPE_BACK);
    }
    void All() {
        RandamVoice();
        PlaySou();
        PlayBGM();
    }
};