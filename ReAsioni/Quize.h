#pragma once

#include <DxLib.h>
#include "MessageData.h"
#include "Basic.h"

class Quize {
public:
	int White = GetColor(255, 255, 255);

	int Quiztimer;//��������
	bool QuizCheck1;//�e�N�C�Y�̏I��
	bool QuizCheck2;
	bool QuizCheck3;
	bool QuizCheck4;
	bool QuizCheck5;
	bool Correct;//����
	bool Incorrect;//�s����
	int WaitTime;//���̖��ւ̑҂�����
	bool Ing;//�N�C�Y�C�x���g�����ۂ�
	bool CountUpCheck;//�N�C�Y�C�x���g���I�����Ă悢��
	int CoreSound, IncoreSound;//���ʉ�
	int mob[4];//���u�L�����̉摜
	bool Quizstart;//�N�C�Y�C�x���g���n�܂������ǂ���
	bool QuizFailure;//�N�C�Y�ŕs������������
	int sb[1];//�Ŕ�
	bool q;//�܂��N�C�Y�C�x���g���n�܂��Ă��Ȃ��Ȃ�true
	bool ch;//�҂����Ԓ��ɓ��͂��󂯕t���Ȃ����߂Ɏg�p
	int px, py;//�v���C���[�̍��W

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
		CoreSound = LoadSoundMem("sound/correct.mp3");//������
		IncoreSound = LoadSoundMem("sound/incorrect.mp3");//�s������
		LoadDivGraph("img/Mob.png", 4, 1, 4, 32, 48, mob);
		Quizstart = true;
		QuizFailure = false;
		LoadDivGraph("img/signboard.png", 1, 1, 1, 32, 32, sb);
		q = true;
		ch = true;
	}
	void Correcting() {//���������Ƃ�
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Corrects);
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Next);
		if (WaitTime == 1)PlaySoundMem(CoreSound, DX_PLAYTYPE_BACK, TRUE);
	}
	void Incorrecting() {//�s���������Ƃ�
		DrawFormatString(MESSAGE_X, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, White, "%s\n", Incorrects);
		if (WaitTime == 1)PlaySoundMem(IncoreSound, DX_PLAYTYPE_BACK, TRUE);
		QuizFailure = true;
	}
	void NextCount(Player* pl) {//�N�C�Y�C�x���g�̏I��
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
	void NextQuize() {//���̃N�C�Y�ւ̏���
		WaitTime = 0;
		Quiztimer = 0;
		Correct = false;
		Incorrect = false;
		ch = true;
	}
	void Quizing(Player* pl, int scene, Basic* basic) {//�N�C�Y�C�x���g�������Ȃ�����
		if (Ing) {
			if (Quizstart) {//�N�C�Y�C�x���g���͂��܂����u�Ԃ̃v���C���[�̈ʒu���o����
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
			//�N�C�Y�C�x���g���v���C���[�̈ʒu���Œ�
			pl->x = px;
			pl->y = py;
			pl->targetX = px;
			pl->targetY = py;
		}
		if (Count == 9, scene == 3) {//�C�x���g�̃g���K�[��ݒu
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
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//����
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
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//����
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
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {//����
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
			if (CheckHitKey(KEY_INPUT_LEFT) && ch) {//����
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
			if (CheckHitKey(KEY_INPUT_RIGHT) && ch) {//����
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