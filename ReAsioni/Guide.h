#include "DxLib.h"

//Sign.h�Ń}�b�v��̃I�u�W�F�N�g��\��
//�����ł�����J�������̏������v���O����

class Guide {
public:
	int x, y; //�`���V�Ȃǂ̍��W
	int gh; //�摜
	bool tizu; //�n�}
	bool tizu15; //�V�[���P�T�̒n�}
	bool tirasi; //�`���V
	int px, py; //�v���C���[�̍��W

	Guide() {
		x = 20;
		y = 50;
		gh = 0;
		tizu = false;
		tizu15 = false;
		tirasi = false;
	}
	void Set(int scene, Player* pl) {
		switch (scene) {
		case 15:
			gh = LoadGraph("img/3-3.png");
			tizu15 = true;
			tizu = false;
			tirasi = false;
			break;
		case 19:
			gh = LoadGraph("img/3-2.png");
			tizu = true;
			tizu15 = false;
			tirasi = false;
			break;
		case 23:
			gh = LoadGraph("img/3-1.png");
			tizu = true;
			tizu15 = false;
			tirasi = false;
			break;
		case 14:
			if (pl->x == 480 && pl->y == 32) {
				gh = LoadGraph("img/ShopAd.png");
				tirasi = true;
			}
			else tirasi = false;
			tizu = false;
			tizu15 = false;
			break;
		case 16:
			if (pl->x == 384 && pl->y == 288) {
				gh = LoadGraph("img/ShopAd.png");
				tirasi = true;
			}
			else tirasi = false;
			tizu = false;
			tizu15 = false;
			break;
		case 22:
			if (pl->x == 64 && pl->y == 352) {
				gh = LoadGraph("img/ShopAd.png");
				tirasi = true;
			}
			else tirasi = false;
			tizu = false;
			tizu15 = false;
			break;
		case 33:
			if (pl->x == 416 && pl->y == 352) {
				gh = LoadGraph("img/ShopAd.png");
				tirasi = true;
			}
			else tirasi = false;
			tizu = false;
			tizu15 = false;
			break;
		default:
			gh = 0;
			tizu = false;
			tizu15 = false;
			tirasi = false;
			break;
		}
	}
	void View(Player* pl) {
		px = pl->x;
		py = pl->y;
		if (gh != 0 && CheckHitKey(KEY_INPUT_RETURN)) {
			if (tizu15 && px == 160 && py == 288)DrawGraph(x, y, gh, FALSE);
			if (tizu && px == 320 && py == 224)DrawGraph(x, y, gh, FALSE);
			if (tirasi)DrawGraph(x, y, gh, FALSE);
		}
	}
	void All(int scene, Player* pl) {
		Set(scene, pl);
		View(pl);
	}
	void Reset() {
		gh = 0;
		tizu = false;
		tizu15 = false;
		tirasi = false;
	}
};