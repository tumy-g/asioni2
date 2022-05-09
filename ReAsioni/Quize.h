#pragma once

#include <DxLib.h>
#include "MessageData.h"
#include "Basic.h"

class Quize {
public:
	int White = GetColor(255, 255, 255);

	int Quiztimer;//制限時間
	bool QuizCheck1;//各クイズの終了
	bool QuizCheck2;
	bool QuizCheck3;
	bool QuizCheck4;
	bool QuizCheck5;
	bool Correct;//正解
	bool Incorrect;//不正解
	int WaitTime;//次の問題への待ち時間
	bool Ing;//クイズイベント中か否か
	bool CountUpCheck;//クイズイベントを終了してよいか
	int CoreSound, IncoreSound;//効果音
	int mob[4];//モブキャラの画像
	bool Quizstart;//クイズイベントが始まったかどうか
	bool QuizFailure;//クイズで不正解をしたか
	int sb[1];//看板
	bool q;//まだクイズイベントが始まっていないならtrue
	bool ch;//待ち時間中に入力を受け付けないために使用
	int px, py;//プレイヤーの座標

	Quize() {
		QuizCheck1 = false;
		QuizCheck2 = false;
		QuizCheck3 = false;
		QuizCheck4 = false;
		QuizCheck5 = false;
		Quiztimer = 300;
		Correct = false;
		Incorrect = false;
		WaitTime = 0;
		Ing = false;
		CountUpCheck = true;
		CoreSound = LoadSoundMem("sound/correct.mp3");//正解音
		IncoreSound = LoadSoundMem("sound/incorrect.mp3");//不正解音
		LoadDivGraph("img/Mob.png", 4, 1, 4, 32, 48, mob);
		Quizstart = true;
		QuizFailure = false;
		LoadDivGraph("img/signboard.png", 1, 1, 1, 32, 32, sb);
		q = true;
		ch = true;
	}
	void Correcting() {//正解したとき
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Corrects);
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Next);
		if (WaitTime == 1)PlaySoundMem(CoreSound, DX_PLAYTYPE_BACK, TRUE);
	}
	void Incorrecting() {//不正解したとき
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Incorrects);
		if (WaitTime == 1)PlaySoundMem(IncoreSound, DX_PLAYTYPE_BACK, TRUE);
		QuizFailure = true;
	}
	void NextCount(Player* pl) {//クイズイベントの終了
		if (CountUpCheck) {
			Count++;
			CountUpCheck = false;
			QuizFailure = false;
			pl->x = 352;
			pl->targetX = 352;
			pl->y = 160;
			pl->targetY = 160;
		}
	}
	void NextQuize() {//次のクイズへの準備
		WaitTime = 0;
		Quiztimer = 0;
		Correct = false;
		Incorrect = false;
		ch = true;
	}
	void Quizing(Player* pl, int scene, Basic* basic) {//クイズイベント中動けなくする
		if (Ing) {
			if (Quizstart) {//クイズイベントがはじまった瞬間のプレイヤーの位置を覚える
				px = pl->x;
				py = pl->y;
				Quizstart = false;
			}
			for (int i = 0; i < 3; i++) {
				DrawExtendGraph(px - 32 + i * 32, py - 48, px + i * 32, py, mob[0], TRUE);
				DrawExtendGraph(px + 64, py + i * 32, px + 96, py + i * 32 + 48, mob[1], TRUE);
				DrawExtendGraph(px - 64, py + i * 32, px - 32, py + i * 32 + 48, mob[2], TRUE);
				DrawExtendGraph(px - 32 + i * 32, py + 96, px + i * 32, py + 144, mob[3], TRUE);
			}
			//クイズイベント中プレイヤーの位置を固定
			pl->x = px;
			pl->y = py;
			pl->targetX = px;
			pl->targetY = py;
		}
		if (Count == 9, scene == 3) {//イベントのトリガーを設置
			DrawGraph(352, 128, sb[0], TRUE);
		}
		if (QuizFailure) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quizfailure);
		}
	}
	void Quizee(Player* pl, Basic* basic) {
		Quiztimer++;
		if (WaitTime == 150)WaitTime = 0;

		if (((q && pl->x == 352 && pl->y == 160) || (QuizFailure && CheckHitKey(KEY_INPUT_RETURN)))) {
			QuizCheck1 = true;
			Ing = true;
			Quizstart = true;
			QuizFailure = false;
			Quiztimer = 301;
			q = false;
		}
		if (QuizCheck1) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quiz1);
			DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI, White, "%s\n", Choice);
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//正解
				Quiztimer = 0;
				Correct = true;
				ch = false;
			}
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {
				Quiztimer = 0;
				Incorrect = true;
				ch = false;
			}
			if (Quiztimer < 300) {
				if (Correct) {
					WaitTime++;
					Correcting();
					if (WaitTime > 120) {
						QuizCheck2 = true;
						NextQuize();
						QuizCheck1 = false;
						Quiztimer = 300;
					}
				}
				if (Incorrect) {
					WaitTime++;
					Incorrecting();
					if (WaitTime > 60) {
						NextQuize();
						QuizCheck1 = false;
					}
				}
			}
		}
		if (QuizCheck2) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quiz2);
			DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI, White, "%s\n", Choice);
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {
				Quiztimer = 0;
				Incorrect = true;
				ch = false;
			}
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//正解
				Quiztimer = 0;
				Correct = true;
				ch = false;
			}
			if (Quiztimer < 300) {
				if (Correct) {
					WaitTime++;
					Correcting();
					if (WaitTime > 120) {
						QuizCheck3 = true;
						NextQuize();
						QuizCheck2 = false;
						Quiztimer = 300;
					}
				}
				if (Incorrect) {
					WaitTime++;
					Incorrecting();
					if (WaitTime > 60) {
						NextQuize();
						QuizCheck2 = false;
					}
				}
			}
		}
		if (QuizCheck3) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quiz3);
			DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI, White, "%s\n", Choice);
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {//正解
				Quiztimer = 0;
				Correct = true;
				ch = false;
			}
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {
				Quiztimer = 0;
				Incorrect = true;
				ch = false;
			}
			if (Quiztimer < 300) {
				if (Correct) {
					Correcting();
					WaitTime++;
					if (WaitTime > 120) {
						QuizCheck4 = true;
						NextQuize();
						QuizCheck3 = false;
						Quiztimer = 300;
					}
				}
				if (Incorrect) {
					Incorrecting();
					WaitTime++;
					if (WaitTime > 60) {
						NextQuize();
						QuizCheck3 = false;
					}
				}
			}
		}
		if (QuizCheck4) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quiz4);
			DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI, White, "%s\n", Choice);
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {
				Quiztimer = 0;
				Incorrect = true;
				ch = false;
			}
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//正解
				Quiztimer = 0;
				Correct = true;
				ch = false;
			}
			if (Quiztimer < 300) {
				if (Correct) {
					Correcting();
					WaitTime++;
					if (WaitTime > 120) {
						QuizCheck5 = true;
						NextQuize();
						QuizCheck4 = false;
						Quiztimer = 300;
					}
				}
				if (Incorrect) {
					Incorrecting();
					WaitTime++;
					if (WaitTime > 60) {
						NextQuize();
						QuizCheck4 = false;
					}
				}
			}
		}
		if (QuizCheck5) {
			basic->MessageWindow();
			DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Quiz5);
			DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI, White, "%s\n", Choice);
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {//正解
				Quiztimer = 0;
				Correct = true;
				ch = false;
			}
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {
				Quiztimer = 0;
				Incorrect = true;
				ch = false;
			}
			if (Quiztimer < 300) {
				if (Correct) {
					DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Corrects);
					DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Clear);
					if (WaitTime == 1)PlaySoundMem(CoreSound, DX_PLAYTYPE_BACK, TRUE);
					WaitTime++;

					if (WaitTime > 120) {
						NextQuize();
						NextCount(pl);
						QuizCheck5 = false;
					}
				}
				if (Incorrect) {
					Incorrecting();
					WaitTime++;
					if (WaitTime > 60) {
						NextQuize();
						QuizCheck5 = false;
					}
				}
			}
		}
	}
	void All(Player* pl, int scene, Basic* basic) {
		if (Count == 9 && scene == 3) {
			Quizee(pl, basic);
			Quizing(pl, scene, basic);
		}
	}
	void Reset() {
		QuizCheck1 = false;
		QuizCheck2 = false;
		QuizCheck3 = false;
		QuizCheck4 = false;
		QuizCheck5 = false;
		Quiztimer = 300;
		Correct = false;
		Incorrect = false;
		WaitTime = 0;
		Ing = false;
		CountUpCheck = true;
		Quizstart = true;
		QuizFailure = false;
		q = true;
		ch = true;
	}
};