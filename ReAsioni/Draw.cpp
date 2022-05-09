#include "DxLib.h"
#include "Developer.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    int timer = 0;

    Map* map          = new Map();
    Player* pl           = new Player();
    Oni* oni             = new Oni();
    Walk* walk         = new Walk();
    OniVoice* voice  = new OniVoice();
    Basic* basic        = new Basic();
    Hint* hint           = new Hint();
    Quize* quize       = new Quize();
    Item* item          = new Item();
    MobItem* mobI  = new MobItem();
    HaveItem* havI  = new HaveItem();
    ItemShop* shop = new ItemShop();
    UseItem* useI    = new UseItem();
    MobEvent* mob  = new MobEvent();
    OPED* oe            = new OPED();
    Guide* guide       = new Guide();
    Sign* sign           = new Sign();
    DevelopTool* de = new DevelopTool();

    while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) {
        int startTime = GetNowCount();

        basic->FullScreen();
        if (timer >= 0 && timer < 10 * 60)oe->OP();
        if (oe->EndOP2 == true)timer++;
        if (timer > 1 && oe->gameover == false) {
            SetDrawBright(255, 255, 255);
            map->All(pl, walk);
            sign->All(scene);
            item->All(timer, pl, scene, basic);
            mobI->All(timer, pl, scene, basic);
            mob->All(scene);
            oni->All(pl, voice, scene);
            useI->All(pl, oni);
            quize->All(pl, scene, basic);
            if (can)pl->All();
            guide->All(scene, pl);
            basic->All();
            havI->All(basic);
            shop->All(basic, pl, scene, havI);
            hint->All(basic);
        }
        if (oni->OK)oe->GameOver(pl, oni);
        if (Count == 16) {
            oe->ED();
            timer = -1;
        }

        //リセット、デベロップツール
        if (CheckHitKey(KEY_INPUT_0)) {
            timer = 0;
            de->Reset(basic, guide, item, havI, mobI, shop, useI, map, oni, mob, oe, pl, quize, sign);
            StopMusic();
        }
        if(Count != 16)DrawFormatString(0, 0, GetColor(200, 200, 200), "%d秒", timer / 60);

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        int endTime = GetNowCount();
        WaitTimer((1000 / 60) - (endTime - startTime));
    }
    InitSoundMem();
    DxLib_End();
    return 0;
}