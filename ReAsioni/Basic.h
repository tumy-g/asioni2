#pragma once

#include <DxLib.h>
#include "MessageData.h"
#define MESSAGE_X 25//テキストの最初の位置
#define MESSAGE_Y 365//
#define MESSAGE_HI 20//テキストの高さ

int Count = 1;

class Basic {
public:
	bool click;
	bool open;
	bool a;

	Basic() {
		click = true;
		open = false;
		a = true;
	}
	void MenuSystem() {
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			if (click) {
				if (open) {
					open = false;
					click = false;
				}
				else {
					open = true;
					click = false;
				}
			}
		}
		else {
			click = true;
		}
		if (open)LoadGraphScreen(0, 350, "img/messagewindow.png", FALSE);
	}
	void MessageWindow() {//メッセージウィンドウを表示するだけ。主にイベントで使用
		LoadGraphScreen(0, 350, "img/messagewindow.png", FALSE);
	}
	void CountControll() {
		if (CheckHitKey(KEY_INPUT_Q)) {
			if (a) {
				Count++;
				a = false;
			}
		}
		else {
			a = true;
		}
	}
	void FullScreen() {
		float height = GetSystemMetrics(SM_CYSCREEN);
		float mag = height / 500;
		SetWindowSizeExtendRate(mag);
	}
	void Test() {
		DrawFormatString(0, 430, GetColor(255, 0, 0), "カウント:%d", Count);
	}
	void All() {
		MenuSystem();
		//CountControll();
	}
	void Reset() {
		click = true;
		open = false;
		Count = 1;
	}
};

class Hint {
public:
	int White;

	Hint() {
		White = GetColor(255, 255, 255);
	}

	void Sentence(Basic* basic) {
		if (basic->open) {
			switch (Count){
			case 1:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count1);
				break;
			case 2:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count2);
				break;
			case 3:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count3);
				break;
			case 4:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count4);
				break;
			case 5:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count5);
				break;
			case 6:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count6);
				break;
			case 8:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count8);
				break;
			case 9:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count9);
				break;
			case 10:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count10);
				break;
			case 12:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count12);
				break;
			case 13:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count13);
				break;
			case 14:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count14);
				break;
			case 15:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Count15);
				break;
			default:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "%s\n", Free);
				break;
			}
		}
	}
	void All(Basic* basic) {
		Sentence(basic);
	}
};