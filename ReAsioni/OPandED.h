#include "DxLib.h"
#include "MessageData.h"

char text[] = "テキストテキストテキストテキストテキスト";

class OPED {
public:
    int c, d; //フェードインに使用、エンドロールに使用
    int x, y; //エンドロールの文字の座標
    int White = GetColor(255, 255, 255);
    bool Push; //Enterが押されたか
    int px, py; //プレイヤーの座標
    int ox, oy; //鬼の座標
    bool gameover; //まんま
    int startOP; //op動画
    int title; //op画像
    bool EndOP1, EndOP2; //フェードイン、フェードアウト
    int OPtime; //まんま
    int gh[12]; //鬼の画像
    int x1, x2, x3, x4; //エンドロールで流す画像の座標
    int y1, y2, y3, y4; //
    int a; //EDアニメーションのカウント
    int making1, making2; //メイキング画像

    OPED() {
        c = 0;
        d = 0;
        x = 80;
        y = 450;
        Push = false;
        gameover = false;
        startOP = LoadGraph("img/Openig.mp4");
        title = LoadGraph("img/title.png");
        EndOP1 = false;
        EndOP2 = false;
        OPtime = 0;
        LoadDivGraph("img/Oni.png", 12, 3, 4, 100, 200, gh);
        x1 = 0;
        x2 = 580;
        x3 = 0;
        x4 = 580;
        y1 = 0;
        y2 = 0;
        y3 = 380;
        y4 = 380;
        a = 0;
        making1 = LoadGraph("img/making1.png");
        making2 = LoadGraph("img/making2.png");
    }
    void OP() {//旧FadeIn()
        if (Push == false)DrawExtendGraph(0, 0, 640, 480, title, FALSE);
        if (CheckHitKey(KEY_INPUT_RETURN))Push = true;
        if (Push == true && EndOP1 == false) {
            OPtime++;
            PlayMovieToGraph(startOP);
            if (GetMovieStateToGraph(startOP)) {
                DrawExtendGraph(0, 0, 640, 480, startOP, FALSE);
            }
            if (OPtime > 260) {
                DeleteGraph(startOP);
                EndOP1 = true;
            }
        }
        if (EndOP1 && c < 10 * 80 && Push)
        {
            c += 3;
            if (c > 0 && c < 256)SetDrawBright(c, c, c);
            if (c > 255 && c < 400)SetDrawBright(255, 255, 255);
            if (c >= 400 && c < 400 + 256)SetDrawBright(255 - (c - 400), 255 - (c - 400), 255 - (c - 400));
            if (c >= 700) {
                EndOP2 = true;
            }

            DrawString(60, 100, "この作品はフィクションです。\n実在する団体名および人名には一切関係ないのでご了承ください。\nなお、このゲームを無断でSNS等に拡散するのは禁止していますので、\n許可を取るか、専用のＨＰ等でダウンロードしてお遊びください。", White);

            DrawBox(30, 30, 60, 60, White, TRUE);
        }
    }
    void GameOver(Player* pl, Oni* oni) {
        px = pl->x;
        py = pl->y;
        ox = oni->x;
        oy = oni->y;
        if ((ox <= px && px <= ox + 32 && oy <= py && py <= oy + 20)) {
            gameover = true;
        }
        if (gameover) {
            LoadGraphScreen(0, 0, "img/GameOver.png", FALSE);
        }
    }
    void BGM() {
        if (CheckMusic() == 0)PlayMusic("sound/EDBGM.mp3", DX_PLAYTYPE_BACK);
    }
    void EDAnime() {
        a++;
        if (a > 30)a = 0;
        if (a >= 0 && a <= 15) {
            DrawExtendGraph(x1, y1, x1 + 70, y1 + 90, gh[0], TRUE);
            DrawExtendGraph(x2, y2, x2 + 70, y2 + 90, gh[3], TRUE);
            DrawExtendGraph(x3, y3, x3 + 70, y3 + 90, gh[6], TRUE);
            DrawExtendGraph(x4, y4, x4 + 70, y4 + 90, gh[9], TRUE);
        }
        if (a > 15 && a <= 30) {
            DrawExtendGraph(x1, y1, x1 + 70, y1 + 90, gh[2], TRUE);
            DrawExtendGraph(x2, y2, x2 + 70, y2 + 90, gh[5], TRUE);
            DrawExtendGraph(x3, y3, x3 + 70, y3 + 90, gh[8], TRUE);
            DrawExtendGraph(x4, y4, x4 + 70, y4 + 90, gh[11], TRUE);
        }
    }
    void EDs() {
        if (Push == true) {
            d++;
            DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
            if (d % 2 == 0)y--;
            DrawFormatString(x, y + 50, White, "%s", ed1);
            DrawFormatString(x, y + 100, White, "%s", ed2);
            DrawFormatString(x, y + 150, White, "%s", ed3);
            DrawFormatString(x, y + 200, White, "%s", ed4);
            DrawFormatString(x, y + 250, White, "%s", ed5);
            DrawFormatString(x, y + 300, White, "%s", ed6);
            DrawFormatString(x, y + 350, White, "%s", ed7);
            DrawFormatString(x, y + 400, White, "%s", ed8);
            DrawFormatString(x, y + 450, White, "%s", ed9);


            DrawExtendGraph(x, y + 500, x + 200, y + 700, making1, FALSE);
            DrawExtendGraph(x + 250, y + 770, x + 450, y + 960, making2, FALSE);
            DrawFormatString(x, y + 1000, White, "%s", ed10);

            if (d > 3060) {
                SetFontSize(80);
                SetFontThickness(5);
                DrawString(160, 200, "THE END", White);
            }
        }
    }
    void ED() {
        EDs();
        if (d < 3060)BGM();
        if (d < 3030)EDAnime();
    }
    void Reset() {
        c = 0;
        d = 0;
        x = 80;
        y = 450;
        Push = false;
        gameover = false;
        EndOP1 = false;
        EndOP2 = false;
        OPtime = 0;
        x1 = 0;
        x2 = 580;
        x3 = 0;
        x4 = 580;
        y1 = 0;
        y2 = 0;
        y3 = 380;
        y4 = 380;
        a = 0;
        startOP = LoadGraph("img/Openig.mp4");
        SetFontSize(16);
        SetFontThickness(6);
    }
};