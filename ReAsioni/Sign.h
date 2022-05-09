#include "DxLib.h"

//ここでマップ上のオブジェクトを表示
//Guide.hでそれを開いた時の処理をプログラム

class Sign {
public:
	bool tizu; //地図
	bool tizu15; //シーン１５の地図
	bool tirasi; //チラシ
	int White; //色
	int Black;
	int Blue;
	int x, y; //ポスターの座標

	Sign() {
		tizu = false;
		tizu15 = false;
		tirasi = false;
		White = GetColor(255, 255, 255);
		Black = GetColor(45, 45, 45);
		Blue = GetColor(0, 237, 237);
		x = 0;
		y = 0;
	}
	void SceneCheck(int scene) {
		switch (scene) {
		case 15:
			tizu15 = true;
			tirasi = false;
			break;
		case 19:
			tizu = true;
			tirasi = false;
			break;
		case 23:
			tizu = true;
			tirasi = false;
			break;
		case 14:
			tirasi = true;
			break;
		case 16:
			tirasi = true;
			tizu15 = false;
			break;
		case 22:
			tirasi = true;
			tizu = false;
			break;
		case 33:
			tirasi = true;
			tizu = false;
			break;
		default:
			tizu = false;
			tizu15 = false;
			tirasi = false;
			break;
		}
		if (tirasi) {
			switch (scene) {
			case 14:
				x = 488;
				y = 3;
				break;
			case 16:
				x = 392;
				y = 255;
				break;
			case 22:
				x = 72;
				y = 321;
				break;
			case 33:
				x = 424;
				y = 311;
				break;
			default:
				break;
			}
		}
	}
	void View() {
		if (tizu15) {
			DrawBox(170, 255, 190, 270, White, TRUE);
			DrawBox(175, 259, 185, 266, Black, FALSE);
		}
		if (tizu) {
			DrawBox(330, 194, 350, 209, White, TRUE);
			DrawBox(335, 198, 345, 205, Black, FALSE);
		}
		if (tirasi) {
			DrawBox(x, y, x + 14, y + 18, Blue, TRUE);
		}
	}
	void All(int scene) {
		SceneCheck(scene);
		View();
	}
	void Reset() {
		tizu = false;
		tizu15 = false;
		tirasi = false;
	}
};