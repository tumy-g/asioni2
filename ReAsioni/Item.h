#include <DxLib.h>
#include "Basic.h"

bool can = true;
int sumDrink = 3;//5
int sumCoin = 100;//100
int sumTanni = 0;//0
int sumRope = 3;//3
int White = GetColor(255, 255, 255);


class Item {
public:
	int kr[3]; //キラキラの画像
	int ec; //キラキラエフェクトに使用
	int ItemX; //アイテムの座標
	int ItemY; //
	int push; //単位を順番通りに取らせるカウント
	int X, Y; //プレイヤーの座標
	bool a; //１フレームだけ処理をするのに使用
	int picksound; //効果音
	int timer; //メッセージウィンドウを表示する時間

	Item() { //単位
		LoadDivGraph("img/effect.png", 3, 3, 1, 32, 32, kr);
		GraphFilter(kr[0], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		GraphFilter(kr[1], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		GraphFilter(kr[2], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		ec = 0;
		ItemX = -50;
		ItemY = -50;
		push = 0;
		a = true;
		picksound = LoadSoundMem("sound/tanni.mp3");
		timer = 0;
	}
	void Flame(int timer) {
		ec = timer / 10;
		ec %= 6;
	}
	void PickTanni(int p) {
		if (a) {
			timer = 0;
			sumTanni++;
			Count++;
			PlaySoundMem(picksound, DX_PLAYTYPE_BACK, TRUE);
			push = p;
		}
		a = false;
	}
	void PickMes(Basic* basic) {
			timer++;
			if (timer < 90 && push > 0) {
				basic->MessageWindow();
				basic->open = false;
				DrawString(MESSAGE_X, MESSAGE_Y, "単位を手に入れた", White);
			}
	}
	void Set(Player* pl, int scene, Basic* basic) {
		X = pl->x;
		Y = pl->y;
		if (CheckHitKey(KEY_INPUT_RETURN) && X < ItemX && ItemX < X + 32 && Y < ItemY && ItemY < Y + 32) {
			switch (push) {
			case 0:
				if (Count == 2)PickTanni(1);
				break;
			case 1:
				if (Count == 4)PickTanni(2);
				break;
			case 2:
				if (Count == 6)PickTanni(3);
				break;
			case 3:
				if (Count == 8)PickTanni(4);
				break;
			case 4:
				if (Count == 10)PickTanni(5);
				break;
			case 5:
				if (Count == 12)PickTanni(6);
				break;
			case 6:
				if (Count == 15)PickTanni(7);
				break;
			default:
				a = true;
				break;
			}
		}
		if (!(X < ItemX && ItemX < X + 32 && Y < ItemY && ItemY < Y + 32))a = true;
		switch (Count) {
		case 2:
			ItemX = 257;
			ItemY = 193;
			if (push == 0 && scene == 33)View();
			break;
		case 4:
			ItemX = 449;
			ItemY = 417;
			if (push == 1 && scene == 17)View();
			break;
		case 6:
			ItemX = 385;
			ItemY = 225;
			if (push == 2 && scene == 13)View();
			break;
		case 8:
			ItemX = 193;
			ItemY = 321;
			if (push == 3 && scene == 9)View();
			break;
		case 10:
			ItemX = 97;
			ItemY = 225;
			if (push == 4 && scene == 11)View();
			break;
		case 12:
			ItemX = 65;
			ItemY = 129;
			if (push == 5 && scene == 1)View();
			break;
		case 15:
			ItemX = 193;
			ItemY = 321;
			if (push == 6 && scene == 32)View();
			break;
		}
	}
	void View() {
		if (ec == 0)DrawGraph(ItemX, ItemY, kr[0], TRUE);
		if (ec == 1)DrawGraph(ItemX, ItemY, kr[1], TRUE);
		if (ec == 2)DrawGraph(ItemX, ItemY, kr[2], TRUE);
		if (ec == 4)DrawGraph(ItemX, ItemY, kr[2], TRUE);
		if (ec == 5)DrawGraph(ItemX, ItemY, kr[1], TRUE);
	}
	void All(int timer, Player* pl, int scene, Basic* basic) {
		Set(pl, scene, basic);
		Flame(timer);
		PickMes(basic);
	}
	void Reset() {
		can = true;
		sumDrink = 3;//5
		sumCoin = 100;//100
		sumTanni = 0;//0
		sumRope = 3;//3
		ItemX = -50;
		ItemY = -50;
		push = 0;
		a = true;
		timer = 0;
	}
};

class MobItem {
public:
	int kr[3]; //下記も単位と同じく
	int ec;
	int ItemX;
	int ItemY;
	int X, Y;
	bool a;
	int picksound;
	int timer;
	bool Item1, Item2, Item3, Item4, Item5, Item6, Item7, Item8;//アイテムが残っているか(拾われていないか)
	bool mes; //メッセージウィンドウを表示
	int S; //アイテムの個数
	int W; //アイテムの種類

	MobItem() {
		LoadDivGraph("img/effect.png", 3, 3, 1, 32, 32, kr);
		GraphFilter(kr[0], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		GraphFilter(kr[1], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		GraphFilter(kr[2], DX_GRAPH_FILTER_BRIGHT_CLIP, DX_CMP_LESS, 50, TRUE, GetColor(0, 0, 0), 0);
		ec = 0;
		ItemX = -50;
		ItemY = -50;
		a = true;
		Item1 = true;
		Item2 = true;
		Item3 = true;
		Item4 = true;
		Item5 = true;
		Item6 = true;
		Item7 = true;
		Item8 = true;
		picksound = LoadSoundMem("sound/pick.mp3");
		timer = 0;
		mes = false;
		S = 0;
		W = 0;
	}
	void Flame(int timer) {
		ec = timer / 10;
		ec %= 6;
	}
	void PickMes(int some, Basic* basic, int what) {
		timer++;
		if (timer < 90&& some != 0) {
			basic->MessageWindow();
			basic->open = false;
			switch (what) {//何を拾ったか
			case 1:
				DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "罠を%d個拾った", some);
				break;
			case 2:
					DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "ドリンクを%d本拾った", some);
				break;
			case 3:
					DrawFormatString(MESSAGE_X, MESSAGE_Y, White, "コインを%d枚拾った", some);
				break;
			default:
				break;
			}
		}
	}
	void PickCoin(int some) {
		S = some;
		W = 3;
		if (a){
			timer = 0;
			sumCoin += some;
			PlaySoundMem(picksound, DX_PLAYTYPE_BACK, TRUE);
		}
		a = false;
	}
	void PickDrink(int some) {
		S = some;
		W = 2;
		if (a) {
			timer = 0;
			sumDrink += some;
			PlaySoundMem(picksound, DX_PLAYTYPE_BACK, TRUE);
		}
		a = false;
	}
	void PickRope(int some) {
		S = some;
		W = 1;
		if (a) {
			timer = 0;
			sumRope += some;
			PlaySoundMem(picksound, DX_PLAYTYPE_BACK, TRUE);
		}
		a = false;
	}
	void Set(Player* pl, int scene) {
		X = pl->x;
		Y = pl->y;
		if (CheckHitKey(KEY_INPUT_RETURN) && X < ItemX && ItemX < X + 32 && Y < ItemY && ItemY < Y + 32) {
			switch (scene){
			case 5:
				if(Item1)PickCoin(40);
				Item1 = false;
				break;
			case 11:
				if (Item8)PickDrink(5);
				Item8 = false;
				break;
			case 14:
				if (Item2)PickCoin(35);
				Item2 = false;
				break;
			case 15:
				if (Item3)PickDrink(6);
				Item3 = false;
				break;
			case 21:
				if (Item4)PickDrink(6);
				Item4 = false;
				break;
			case 23:
				if (Item7)PickRope(7);
				Item7 = false;
				break;
			case 34:
				if (Item5)PickDrink(5);
				Item5 = false;
				break;
			case 35:
				if (Item6)PickCoin(100);
				Item6 = false;
				break;
			}
		}
		if (!(X < ItemX && ItemX < X + 32 && Y < ItemY && ItemY < Y + 32))a = true;
		switch (scene){
		case 5:
			ItemX = 97;
			ItemY = 1;
			if (Item1)View();
			break;
		case 11:
			ItemX = 1;
			ItemY = 417;
			if (Item8)View();
			break;
		case 14:
			ItemX = 385;
			ItemY = 289;
			if (Item2)View();
			break;
		case 15:
			ItemX = 161;
			ItemY = 417;
			if (Item3)View();
			break;
		case 21:
			ItemX = 417;
			ItemY = 289;
			if (Item4)View();
			break;
		case 23:
			ItemX = 1;
			ItemY = 257;
			if (Item7)View();
			break;
		case 34:
			ItemX = 385;
			ItemY = 225;
			if (Item5)View();
			break;
		case 35:
			ItemX = 33;
			ItemY = 289;
			if (Item6)View();
			break;
		default:
			break;
		}
	}
	void View() {
		if (ec == 0)DrawGraph(ItemX, ItemY, kr[0], TRUE);
		if (ec == 1)DrawGraph(ItemX, ItemY, kr[1], TRUE);
		if (ec == 2)DrawGraph(ItemX, ItemY, kr[2], TRUE);
		if (ec == 4)DrawGraph(ItemX, ItemY, kr[2], TRUE);
		if (ec == 5)DrawGraph(ItemX, ItemY, kr[1], TRUE);
	}
	void All(int timer, Player* pl, int scene, Basic* basic) {
		Set(pl, scene);
		Flame(timer);
		PickMes(S, basic, W);
	}
	void Reset() {
		ec = 0;
		ItemX = -50;
		ItemY = -50;
		a = true;
		Item1 = true;
		Item2 = true;
		Item3 = true;
		Item4 = true;
		Item5 = true;
		Item6 = true;
		Item7 = true;
		Item8 = true;
		timer = 0;
		mes = false;
		S = 0;
		W = 0;
	}
};

class HaveItem {
public:
	int drink; //各画像を入れる
	int coin;
	int tanni;
	int rope;
	int x, y; //アイテム欄の座標
	bool shoping; //コンビニに入る

	HaveItem() {
		drink = LoadGraph("img/Drink.png");
		coin = LoadGraph("img/Coin.png");
		tanni = LoadGraph("img/tanni.png");
		rope = LoadGraph("img/rope.png");
		x = 430;
		y = 10;
		shoping = false;
	}
	void View(Basic* basic) {
		if (basic->open || shoping) {
			DrawBox(x, y - 5, 640, y + 40, GetColor(0,0,0), TRUE);

			DrawGraph(x, y, coin, TRUE);
			DrawFormatString(x + 28, y, White, "*%d", sumCoin);

			DrawGraph(x + 50, y, drink, TRUE);
			DrawFormatString(x + 72, y, White, "*%d", sumDrink);

			DrawGraph(x + 100, y, tanni, TRUE);
			DrawFormatString(x + 132, y, White, "*%d", sumTanni);

			DrawGraph(x + 150, y, rope, TRUE);
			DrawFormatString(x + 182, y, White, "*%d", sumRope);
		}
	}
	void All(Basic* basic) {
		View(basic);
	}
	void Reset() {
		shoping = false;
	}
};

class ItemShop {
public:
	int x1, y1; //カーソルの座標
	bool a, check; //1フレームだけ処理をするのに使用
	bool open;
	int X, Y; //プレイヤーの座標
	int buy;
	bool UP; //上キーを押したか
	bool DOWN; //したキーを押したか
	bool keycheck; //キーを押したか
	int select; //効果音

	ItemShop() {
		x1 = MESSAGE_X;
		y1 = 397;
		a = true;
		open = false;
		check = false;
		buy = LoadSoundMem("sound/buy.mp3");
		UP = false;
		DOWN = true;
		keycheck = true;
		select = LoadSoundMem("sound/select.mp3");
	}
	void View(HaveItem* havI) {
		if (CheckHitKey(KEY_INPUT_RETURN)) {
			open = true;
			can = false;
			havI->shoping = true;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			open = false;
			can = true;
			havI->shoping = false;;
		}
	}
	void Choose(Basic* basic) {
		if (open) {
			basic->MessageWindow();
			basic->open = false;
			if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_DOWN)) {
				if (CheckHitKey(KEY_INPUT_DOWN) && DOWN && keycheck) {
					PlaySoundMem(select, DX_PLAYTYPE_BACK, TRUE);
					y1 = 397;
					UP = true;
					DOWN = false;
					keycheck = false;
				}
				else if (CheckHitKey(KEY_INPUT_DOWN) && UP && keycheck) {
					PlaySoundMem(select, DX_PLAYTYPE_BACK, TRUE);
					y1 = 377;
					UP = false;
					DOWN = true;
					keycheck = false;
				}
				else if (CheckHitKey(KEY_INPUT_UP) && DOWN && keycheck) {
					PlaySoundMem(select, DX_PLAYTYPE_BACK, TRUE);
					y1 = 397;
					UP = true;
					DOWN = false;
					keycheck = false;
				}
				else if (CheckHitKey(KEY_INPUT_UP) && UP && keycheck) {
					PlaySoundMem(select, DX_PLAYTYPE_BACK, TRUE);
					y1 = 377;
					UP = false;
					DOWN = true;
					keycheck = false;
				}
			}
			else keycheck = true;
			DrawTriangle(x1, y1 + 10, x1, y1 + 20, x1 + 7, y1 + 15, White, TRUE);
			DrawString(MESSAGE_X - 5, MESSAGE_Y, "どれを購入しますか？(C：左←  B：右→)", White);
			DrawString(MESSAGE_X + 15, MESSAGE_Y + MESSAGE_HI, "速度アップ薬(スピードUP) ￥15", White);
			DrawString(MESSAGE_X + 15, MESSAGE_Y + MESSAGE_HI + MESSAGE_HI, "罠(足止め) ￥10", White);
		}
	}
	void Buy() {
		if (open){
			if (MESSAGE_Y + 10 < y1 + 10 && y1 + 10 < MESSAGE_Y + 30 && CheckHitKey(KEY_INPUT_RIGHT) && sumCoin >= 15){
				if (check == false) {
					sumDrink++;
					sumCoin -= 15;
					PlaySoundMem(buy, DX_PLAYTYPE_BACK, TRUE);
					check = true;
				}
			}
			else if (MESSAGE_Y + 35 < y1 + 10 && y1 + 10 < MESSAGE_Y + 53 && CheckHitKey(KEY_INPUT_RIGHT) && sumCoin >= 10)
			{
				if (check == false) {
					sumRope++;
					sumCoin -= 10;
					PlaySoundMem(buy, DX_PLAYTYPE_BACK, TRUE);
					check = true;
				}
			}
			else check = false;
		}
	}
	void All(Basic* basic, Player* pl, int scene, HaveItem* havI) {
		X = pl->x;
		Y = pl->y;
		if (scene == 2 && 320 >= X && X >= 288 && Y == 224) {
			View(havI);
			Choose(basic);
			Buy();
		}
	}
	void Reset() {
		x1 = MESSAGE_X;
		y1 = 397;
		a = true;
		open = false;
		check = false;
		UP = false;
		DOWN = true;
		keycheck = true;
	}
};

class UseItem {
public:
	int rx, ry; //罠の座標
	int ro[1]; //罠の画像
	int DrinkTime; //ドリンクの効果時間
	int sound; //効果音
	int sound2; //
	int RopeTime; //罠の効果時間
	bool RopeView; //罠が設置されているか
	bool RopeCheck; //使用キーを押したか
	int BRopeTime; //大罠の効果時間
	bool BRopeView; //大罠が設置されているか
	bool BRopeCheck; //使用キーを押したか
	bool DrinkCheck; //
	bool In; //鬼が罠の中に入ったか
	bool BIn; //
	int X, Y; //鬼の座標
	UseItem() {
		LoadDivGraph("img/rope.png", 1, 1, 1, 32, 32, ro);
		rx = 1024;
		ry = 1024;
		DrinkTime = 501;
		RopeTime = 0;
		RopeView = false;
		RopeCheck = true;
		DrinkCheck = true;
		BRopeTime = 0;
		BRopeView = false;
		BRopeCheck = true;
		In = false;
		BIn = false;
		sound = LoadSoundMem("sound/drinking.mp3");
		sound2 = LoadSoundMem("sound/rope.mp3");
	}
	void Rope(Player* pl) {
		if (pl->walkFlag == false && sumRope > 0 && CheckHitKey(KEY_INPUT_2) && RopeView == false) {
			if (RopeCheck) {
				rx = pl->x;
				ry = pl->y - 15;
				sumRope--;
				RopeView = true;
				RopeTime = 0;
			}
			RopeCheck = false;
		}
		else RopeCheck = true;
		if (pl->x < -3 || pl->x > 605 || pl->y < -44 || pl->y > 436) {
			RopeView = false;
			In = false;
		}
		if (RopeTime == 1)PlaySoundMem(sound2, DX_PLAYTYPE_BACK, TRUE);
	}
	void View(Oni* oni) {
		X = oni->x;
		Y = oni->y - 15;
		if (RopeView) {
			RopeTime++;
			DrawGraph(rx, ry, ro[0], TRUE);
			if (X <= rx && rx <= X + 32 && Y <= ry && ry <= Y + 32) {
				In = true;
			}
			if (RopeTime > 180)In = false;
			if (RopeTime > 181)RopeView = false;
		}
		if (In) {
			oni->x = rx;
			oni->y = ry;
			oni->targetX = rx;
			oni->targetY = ry;
		}
	}
	void Drink(Player* pl) {
		if (pl->walkFlag == false && sumDrink > 0 && CheckHitKey(KEY_INPUT_1)) {
			if (DrinkCheck) {
				DrinkTime = 0;
				sumDrink--;
				pl->speed = 4;
			}
			DrinkCheck = false;
		}
		else DrinkCheck = true;
		DrinkTime++;
		if (DrinkTime == 1) {
			PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
		}
		if (DrinkTime > 500) {
			pl->speed = 2;
		}
	}
	void BigRope(Player* pl) {
		if (pl->walkFlag == false && sumRope > 2 && CheckHitKey(KEY_INPUT_3) && BRopeView == false) {
			if (BRopeCheck) {
				rx = pl->x;
				ry = pl->y - 15;
				sumRope -= 3;
				BRopeView = true;
				BRopeTime = 0;
			}
			BRopeCheck = false;
		}
		else BRopeCheck = true;
		if (pl->x < -3 || pl->x > 605 || pl->y < -44 || pl->y > 436) {
			BRopeView = false;
			BIn = false;
		}
		if (BRopeTime == 1)PlaySoundMem(sound2, DX_PLAYTYPE_BACK, TRUE);
	}
	void BigView(Oni* oni) {
		X = oni->x;
		Y = oni->y - 15;
		if (BRopeView) {
			BRopeTime++;
			DrawGraph(rx, ry, ro[0], TRUE);
			if (X <= rx && rx <= X + 32 && Y <= ry && ry <= Y + 32) {
				BIn = true;
			}
			if (BRopeTime > 420)BIn = false;
			if (BRopeTime > 421)BRopeView = false;
		}
		if (BIn) {
			oni->x = rx;
			oni->y = ry + 15;
			oni->targetX = rx;
			oni->targetY = ry + 15;
		}
	}
	void All(Player* pl, Oni* oni) {
		Rope(pl);
		View(oni);
		Drink(pl);
		BigRope(pl);
		BigView(oni);
	}
	void Reset() {
		rx = 1024;
		ry = 1024;
		DrinkTime = 501;
		RopeTime = 0;
		RopeView = false;
		RopeCheck = true;
		DrinkCheck = true;
		BRopeTime = 0;
		BRopeView = false;
		BRopeCheck = true;
		In = false;
		BIn = false;
	}
};