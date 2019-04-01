#include"function.h"

void game_face(int level, int step_num, int restep_num);
void pause();
void lastlevel();
void passlevel(int step_num);

int gameloop(int level,int character,int keys)
{
	mciSendString(TEXT("open Boxmove.wav alias tusi"), NULL, 0, NULL);

//定义音乐对象
	MUSIC mus;
	mus.OpenFile("resources\\music\\Boxmove.wav"); 
	MUSIC mus1;
	mus1.OpenFile("resources\\music\\Tusi.mp3");

	PIMAGE pimg_wall = newimage();
	PIMAGE pimg_land = newimage();
	PIMAGE pimg_BG = newimage();

	PIMAGE pimg_box0 = newimage();
	PIMAGE pimg_aim0 = newimage();
	PIMAGE pimg_Uaim0 = newimage();
	PIMAGE pimg_ManUP0 = newimage();
	PIMAGE pimg_ManDOWN0 = newimage();
	PIMAGE pimg_ManRIGHT0 = newimage();
	PIMAGE pimg_ManLEFT0 = newimage();

	PIMAGE pimg_box1 = newimage();
	PIMAGE pimg_aim1 = newimage();
	PIMAGE pimg_Uaim1 = newimage();
	PIMAGE pimg_ManUP1 = newimage();
	PIMAGE pimg_ManDOWN1 = newimage();
	PIMAGE pimg_ManRIGHT1 = newimage();
	PIMAGE pimg_ManLEFT1 = newimage();

	PIMAGE pimg_box2 = newimage();
	PIMAGE pimg_aim2 = newimage();
	PIMAGE pimg_Uaim2 = newimage();
	PIMAGE pimg_ManUP2 = newimage();
	PIMAGE pimg_ManDOWN2 = newimage();
	PIMAGE pimg_ManRIGHT2 = newimage();
	PIMAGE pimg_ManLEFT2 = newimage();


	PIMAGE pimg_black = newimage();

	getimage(pimg_wall, "resources\\image\\menu\\wall.jpg", 0, 0);
	getimage(pimg_land, "resources\\image\\menu\\land.jpg", 0, 0);
	getimage(pimg_BG, "resources\\image\\menu\\BG.jpg",0,0);

	getimage(pimg_box0, "resources\\image\\human\\O0.jpg", 0, 0);
	getimage(pimg_aim0, "resources\\image\\human\\Q0.jpg", 0, 0);
	getimage(pimg_Uaim0, "resources\\image\\human\\X0.jpg", 0, 0);
	getimage(pimg_ManUP0, "resources\\image\\human\\W0.jpg", 0, 0);
	getimage(pimg_ManDOWN0, "resources\\image\\human\\S0.jpg", 0, 0);
	getimage(pimg_ManRIGHT0, "resources\\image\\human\\D0.jpg", 0, 0);
	getimage(pimg_ManLEFT0, "resources\\image\\human\\A0.jpg", 0, 0);

	getimage(pimg_box1, "resources\\image\\WXZ\\O1.jpg", 0, 0);
	getimage(pimg_aim1, "resources\\image\\WXZ\\Q1.jpg", 0, 0);
	getimage(pimg_Uaim1, "resources\\image\\WXZ\\X1.jpg", 0, 0);
	getimage(pimg_ManUP1, "resources\\image\\WXZ\\W1.jpg", 0, 0);
	getimage(pimg_ManDOWN1, "resources\\image\\WXZ\\S1.jpg", 0, 0);
	getimage(pimg_ManRIGHT1, "resources\\image\\WXZ\\D1.jpg", 0, 0);
	getimage(pimg_ManLEFT1, "resources\\image\\WXZ\\A1.jpg", 0, 0);

	getimage(pimg_box2, "resources\\image\\spider\\O2.jpg", 0, 0);
	getimage(pimg_aim2, "resources\\image\\spider\\Q2.jpg", 0, 0);
	getimage(pimg_Uaim2, "resources\\image\\spider\\X2.jpg", 0, 0);
	getimage(pimg_ManUP2, "resources\\image\\spider\\W2.jpg", 0, 0);
	getimage(pimg_ManDOWN2, "resources\\image\\spider\\S2.jpg", 0, 0);
	getimage(pimg_ManRIGHT2, "resources\\image\\spider\\D2.jpg", 0, 0);
	getimage(pimg_ManLEFT2, "resources\\image\\spider\\A2.jpg", 0, 0);

	getimage(pimg_black, "resources\\image\\menu\\BG1.jpg", 0, 0);

	int x, y;
	char option;
	int scenes;
	int isEnd;
	int reValue;

	int step_num;
	int restep_num;

	int re_x[1000], re_y[1000];
	int a = 0;
	int re_boxx[1000], re_boxy[1000];
	int box_x[1000], box_y[1000];
	int b = 0;
	int pd[1000];

	step_num = 0;
	restep_num = 10;
	scenes = 0;
	reValue = 0;
	isEnd = 0;
	option = NULL;

//定义人物角色
//	int character;
//	character = 0;
	int food;
	food = 0;

	Map *map;
	map = LoadMap(level);
	x = map->x;
	y = map->y;

	while (is_run())
	{
//界面打印
	switch (scenes) {
//游戏界面		
		case 0:
			game_face(level, step_num, restep_num);
			if (character == 0) {
				for (int i = 0; i <= 17; i++)
				{
					for (int t = 0; t < strlen(map->map[0]); t++)
					{
						if (map->map[i][t] == '|' || map->map[i][t] == '=')
							putimage(t * 50,  i * 50, pimg_BG);
						if (map->map[i][t] == ' ')
							putimage(t * 50 ,  i * 50, pimg_land);
						if (map->map[i][t] == 'O')
							putimage(t * 50,  i * 50, pimg_box0);
						if (map->map[i][t] == 'Q')
							putimage(t * 50,  i * 50, pimg_aim0);
						if (map->map[i][t] == '#')
							putimage( t * 50,  i * 50  , pimg_wall);
						if (map->map[i][t] == 'X')
							putimage( t * 50  ,  i * 50  , pimg_Uaim0);
						if (map->map[i][t] == '@') {
							if (option == 'd' || option == 'D')
								putimage( t * 50,  i * 50, pimg_ManRIGHT0);
							else if (option == 'a' || option == 'A')
								putimage( t * 50,  i * 50, pimg_ManLEFT0);
							else if (option == 'w' || option == 'W')
								putimage( t * 50,  i * 50, pimg_ManUP0);
							else
								putimage( t * 50,  i * 50, pimg_ManDOWN0);
						}
					}
					if (map->map[i][1] == '|')
						break;
				}
				break;
			}
			else if (character == 1) {
				for (int i = 0; i <= 17; i++)
				{
					for (int t = 0; t < strlen(map->map[0]); t++)
					{
						if (map->map[i][t] == '|' || map->map[i][t] == '=')
							putimage(t * 50,  i * 50, pimg_BG);
						if (map->map[i][t] == ' ')
							putimage(t * 50 ,  i * 50, pimg_land);
						if (map->map[i][t] == 'O')
							putimage(t * 50,  i * 50, pimg_box1);
						if (map->map[i][t] == 'Q')
							putimage(t * 50,  i * 50, pimg_aim1);
						if (map->map[i][t] == '#')
							putimage( t * 50,  i * 50  , pimg_wall);
						if (map->map[i][t] == 'X')
							putimage( t * 50  ,  i * 50  , pimg_Uaim1);
						if (map->map[i][t] == '@') {
							if (option == 'd' || option == 'D')
								putimage( t * 50,  i * 50, pimg_ManRIGHT1);
							else if (option == 'a' || option == 'A')
								putimage( t * 50,  i * 50, pimg_ManLEFT1);
							else if (option == 'w' || option == 'W')
								putimage( t * 50,  i * 50, pimg_ManUP1);
							else 
								putimage( t * 50,  i * 50, pimg_ManDOWN1);
						}
					}
					if (map->map[i][1] == '|')
						break;
				}
				break;
			}
			else if (character == 2) {
				for (int i = 0; i <= 17; i++)
				{
					for (int t = 0; t < strlen(map->map[0]); t++)
					{
						if (map->map[i][t] == '|' || map->map[i][t] == '=')
							putimage(t * 50,  i * 50, pimg_BG);
						if (map->map[i][t] == ' ')
							putimage(t * 50 ,  i * 50, pimg_land);
						if (map->map[i][t] == 'O')
							putimage(t * 50,  i * 50, pimg_box2);
						if (map->map[i][t] == 'Q')
							putimage(t * 50,  i * 50, pimg_aim2);
						if (map->map[i][t] == '#')
							putimage( t * 50,  i * 50  , pimg_wall);
						if (map->map[i][t] == 'X')
							putimage( t * 50  ,  i * 50  , pimg_Uaim2);
						if (map->map[i][t] == '@') {
							if (option == 'd' || option == 'D')
								putimage( t * 50,  i * 50, pimg_ManRIGHT2);
							else if (option == 'a' || option == 'A')
								putimage( t * 50,  i * 50, pimg_ManLEFT2);
							else if (option == 'w' || option == 'W')
								putimage( t * 50,  i * 50, pimg_ManUP2);
							else
								putimage( t * 50,  i * 50, pimg_ManDOWN2);
						}
					}
					if (map->map[i][1] == '|')
						break;
				}
				break;
			}			
//暂停界面
		case 1:
			pause();
			break;
		case 2:
//过关界面
			if (level == maps_num - 1)
				lastlevel();
			else
				passlevel(step_num);
			break;
		default:
			break;
}

	option = getch();

		switch (scenes)
		{
//游戏界面操作事件判定
		case 0:
			switch (option)
			{
				re_x[a] = x;
				re_y[a] = y;
				pd[a] = 0;
			case 'W':
			case 'w':
				switch (map->map[y - 1][x])
				{
				case ' ':
				case 'X':
					map->map[y - 1][x] = '@';
					map->map[y][x] = ' ';

					a++;
					pd[a] = 0;
					re_x[a] = x;
					re_y[a] = y;
					step_num++;
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y - 2][x] != '#'&&map->map[y - 2][x] != 'O'&&map->map[y - 2][x] != 'Q') {
						if (map->map[y - 2][x] == 'X') {
							map->map[y - 2][x] = 'Q';
							b++;
							box_x[b] = x;
							box_y[b] = y - 2;
							re_boxx[b] = x;
							re_boxy[b] = y - 1;
						}
						else {
							map->map[y - 2][x] = 'O';
							b++;
							box_x[b] = x;
							box_y[b] = y - 2;
							re_boxx[b] = x;
							re_boxy[b] = y - 1;
						}
						map->map[y - 1][x] = '@';
						map->map[y][x] = ' ';
						a++;
						pd[a] = 1;
						re_x[a] = x;
						re_y[a] = y;
						step_num++;
						y = y - 1;

						mus.Play(0);
					}
					break;
				default:
					break;
				}
				break;
			case 'S':
			case 's':
				switch (map->map[y + 1][x])
				{
				case ' ':
				case 'X':
					map->map[y + 1][x] = '@';
					map->map[y][x] = ' ';
					a++;
					pd[a] = 0;
					re_x[a] = x;
					re_y[a] = y;
					step_num++;
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y + 2][x] != '#'&&map->map[y + 2][x] != 'O'&&map->map[y + 2][x] != 'Q') {
						if (map->map[y + 2][x] == 'X') {
							map->map[y + 2][x] = 'Q';
							b++;
							box_x[b] = x;
							box_y[b] = y + 2;
							re_boxx[b] = x;
							re_boxy[b] = y + 1;
						}
						else {
							map->map[y + 2][x] = 'O';
							b++;
							box_x[b] = x;
							box_y[b] = y + 2;
							re_boxx[b] = x;
							re_boxy[b] = y + 1;
						}
						map->map[y + 1][x] = '@';
						map->map[y][x] = ' ';
						a++;
						pd[a] = 1;
						re_x[a] = x;
						re_y[a] = y;
						step_num++;
						y = y + 1;

						mus.Play(0);
					}
					break;
				default:
					break;
				}
				break;
			case 'A':
			case 'a':
				switch (map->map[y][x - 1])
				{
				case ' ':
				case 'X':
					map->map[y][x - 1] = '@';
					map->map[y][x] = ' ';
					a++;
					pd[a] = 0;
					re_x[a] = x;
					re_y[a] = y;
					step_num++;
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x - 2] != '#'&&map->map[y][x - 2] != 'O'&&map->map[y][x - 2] != 'Q') {
						if (map->map[y][x - 2] == 'X') {
							map->map[y][x - 2] = 'Q';
							b++;
							box_x[b] = x - 2;
							box_y[b] = y;
							re_boxx[b] = x - 1;
							re_boxy[b] = y;
						}
						else {
							map->map[y][x - 2] = 'O';
							b++;
							box_x[b] = x - 2;
							box_y[b] = y;
							re_boxx[b] = x - 1;
							re_boxy[b] = y;
						}
						map->map[y][x - 1] = '@';
						map->map[y][x] = ' ';
						a++;
						pd[a] = 1;
						re_x[a] = x;
						re_y[a] = y;
						step_num++;
						x = x - 1;

						mus.Play(0);
					}
					break;
				default:
					break;
				}
				break;
			case 'D':
			case 'd':
				switch (map->map[y][x + 1])
				{
				case ' ':
				case 'X':
					map->map[y][x + 1] = '@';
					map->map[y][x] = ' ';
					a++;
					pd[a] = 0;
					re_x[a] = x;
					re_y[a] = y;
					step_num++;
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x + 2] != '#'&&map->map[y][x + 2] != 'O'&&map->map[y][x + 2] != 'Q') {
						if (map->map[y][x + 2] == 'X') {
							map->map[y][x + 2] = 'Q';
							b++;
							box_x[b] = x + 2;
							box_y[b] = y;
							re_boxx[b] = x + 1;
							re_boxy[b] = y;
						}
						else {
							map->map[y][x + 2] = 'O';
							b++;
							box_x[b] = x + 2;
							box_y[b] = y;
							re_boxx[b] = x + 1;
							re_boxy[b] = y;
						}
						map->map[y][x + 1] = '@';
						map->map[y][x] = ' ';
						a++;
						pd[a] = 1;
						re_x[a] = x;
						re_y[a] = y;
						step_num++;
						x = x + 1;

						mus.Play(0);
					}
					break;
				default:
					break;
				}
				break;
//超能力
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//按键III
			case'i':
			case'I':
//王校长的能力
				if (character == 1) {
					switch (map->map[y - 1][x]) {
					case'O':
					case'Q':
						if (food == 0) {
							map->map[y - 1][x] = ' ';
							food = 1;
						}
						break;
					case' ':
						if (food == 1) {
							map->map[y - 1][x] = 'O';
							food = 0;
						}
						break;
					case'X':
						if (food == 1) {
							map->map[y - 1][x] = 'Q';
							food = 0;
						}
						break;
					default:
						break;
					}
				}
//蜘蛛侠的能力
				if (character == 2) {
					for (int dis = 1;; dis++) {
						if ((map->map[y - dis - 1][x] == 'Q' || map->map[y - dis - 1][x] == 'O') && map->map[y - dis][x] == ' ') {
							mus1.Play(0);
							map->map[y - dis][x] = 'O';
							map->map[y - dis - 1][x] = ' ';
							break;
						}
						else if (map->map[y - 1][x] == 'Q' || map->map[y - 1][x] == 'O' || map->map[y - 1][x] == '#')
							break;
					}
				}
				break;
//按键KKKKK
			case'k':
			case'K':
//王校长的能力
				if (character == 1) {
					switch (map->map[y + 1][x]) {
					case'O':
					case'Q':
						if ( food == 0) {
							map->map[y + 1][x] = ' ';
							food = 1;
						}
						break;
					case' ':
						if ( food == 1) {
							map->map[y + 1][x] = 'O';
							food = 0;
						}
						break;
					case'X':
						if ( food == 1) {
							map->map[y + 1][x] = 'Q';
							food = 0;
						}
						break;
					default:
						break;
					}
				}
//蜘蛛侠的能力
				if (character == 2){
					for (int dis = 1;; dis++) {
						if ((map->map[y + dis + 1][x] == 'Q' || map->map[y + dis + 1][x] == 'O') &&  map->map[y + dis][x] == ' ') {
							mus1.Play(0);
							map->map[y + dis][x] = 'O';
							map->map[y + dis + 1][x] = ' ';
							break;
						}
						else if (map->map[y + 1][x] == 'Q' || map->map[y + 1][x] == 'O' || map->map[y + 1][x] == '#')
							break;
					}
				}
				break;
//按键JJJ
			case'J':
			case'j':
//王校长的能力
				if (character == 1) {
					switch (map->map[y][x - 1]) {
					case'O':
					case'Q':
						if (food == 0) {
							map->map[y][x - 1] = ' ';
							food = 1;
						}
						break;
					case' ':
						if ( food == 1) {
							map->map[y][x - 1] = 'O';
							food = 0;
						}
						break;
					case'X':
						if (food == 1) {
							map->map[y][x - 1] = 'Q';
							food = 0;
						}
						break;
					default:
						break;
					}
				}
//蜘蛛侠的能力
				if (character == 2) {
					for (int dis = 1;; dis++) {
						if ((map->map[y][x - dis - 1] == 'Q' || map->map[y][x - dis - 1] == 'O') && map->map[y][x - dis] == ' ') {
							mus1.Play(0);
							map->map[y][x - dis] = 'O';
							map->map[y][x - dis - 1] = ' ';
							break;
						}
						else if (map->map[y][x - 1] == 'Q' || map->map[y][x - 1] == 'O' || map->map[y][x - 1] == '#')
							break;
					}
				}
				break;
//按键LLL
			case'L':
			case'l':
//王校长的能力
				if (character == 1) {
					switch (map->map[y][x + 1]) {
					case'O':
					case'Q':
						if (food == 0) {
							map->map[y][x + 1] = ' ';
							food = 1;
						}
						break;
					case' ':
						if (food == 1) {
							map->map[y][x + 1] = 'O';
							food = 0;
						}
						break;
					case'X':
						if (food == 1) {
							map->map[y][x + 1] = 'Q';
							food = 0;
						}
						break;

					default:
						break;
					}
				}
//蜘蛛侠的能力
				if (character == 2 ) {
					for (int dis = 1;; dis++) {
						if ((map->map[y][x + dis + 1] == 'Q' || map->map[y][x + dis + 1] == 'O') && map->map[y][x + dis] == ' ') {
							mus1.Play(0);
							map->map[y][x + dis] = 'O';
							map->map[y][x + dis + 1] = ' ';
							break;
						}
						else if (map->map[y][x + 1] == 'Q' || map->map[y][x + 1] == 'O' || map->map[y][x + 1] == '#')
							break;
					}
				}
				break;
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//无限撤消
			case 'U':
			case 'u':
				if(character == 0) {
					if (a > 0 && restep_num) {
						map->map[y][x] = ' ';
						map->map[re_y[a]][re_x[a]] = '@';
						x = re_x[a];
						y = re_y[a];
						if (b > 0 && pd[a] == 1) {
							map->map[box_y[b]][box_x[b]] = ' ';
							map->map[re_boxy[b]][re_boxx[b]] = 'O';
							for (int i = 0; i < map->aim_count; i++) {
								if (re_boxy[b] == map->aimy[i] && re_boxx[b] == map->aimx[i])
									map->map[re_boxy[b]][re_boxx[b]] = 'Q';
							}
							b--;
						}
						step_num--;
						restep_num--;
						a--;
					}
				}
				break;

			case 'R':					//重玩（R）
			case'r':
				isEnd = 1;
				reValue = 4;
				break;
//打开暂停菜单（ESC）
			case 27:					
				mciSendString("close bgm2", NULL, 0, NULL);
				scenes = 1;
				break;
			default:
				break;
			}
			break;
//暂停菜单事件判定
		case 1:
			switch (option)
			{
			case'R':					//继续（R）
			case'27':
				scenes = 0;
				break;
			case'X':					//选关(X)
			case'x':
				mciSendString("close bgm2", NULL, 0, NULL);
				reValue = 2;
				isEnd = 1;
				break;
			case'Q':					//重玩(Q)
			case'q':
				isEnd = 1;
				reValue = 4;
				break;
			case'N':					//下一关(N)
			case'n':
				if (level != maps_num - 1)
				{
					reValue = 5;
					isEnd = 1;
				}
				break;
			case'm':					//主菜单(M)
			case'M':
				reValue = 1;
				isEnd = 1;
			default:
				break;
			}
			break;
//过关界面事件判定
		case 2:

			switch (option)
			{
			case'X':				//选关(X)
			case'x':
				reValue = 2;
				isEnd = 1;
				break;
			case'q':				//重玩(Q)
			case'Q':
				reValue = 4;
				isEnd = 1;
				break;
			case'N':				//下一关(N)
			case'n':
				if (map->level != maps_num - 1)
				{
					reValue = 5;
					isEnd = 1;
				}
				break;
			case'm':				//主菜单(M)
			case'M':
				reValue = 1;
				isEnd = 1;
				break;
			}

			break;
		default:
			break;
		}
//逻辑更新
		int isOver = 1;
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver) {
// 关卡锁
//				if (pd1[level]) {
					keys = keys + 1;
					FILE *fp2;//用于打开关卡文件的文件指针
					fp2 = fopen("resources\\data\\key.txt", "w");//以只
					if (keys < maps_num)
						fprintf(fp2, "%d", keys);
					fclose(fp2);
//				}

				scenes = 2;
			}
			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] == ' ')
					map->map[map->aimy[i]][map->aimx[i]] = 'X';
			}

			break;
		case 1:

			break;
		default:
			break;
		}

		if (isEnd)
			break;
	}

	delimage(pimg_wall);
	delimage(pimg_land);
	delimage(pimg_BG);

	delimage(pimg_box0);
	delimage(pimg_aim0);
	delimage(pimg_Uaim0);
	delimage(pimg_ManDOWN0);
	delimage(pimg_ManRIGHT0);
	delimage(pimg_ManUP0);
	delimage(pimg_ManLEFT0);

	delimage(pimg_box1);
	delimage(pimg_aim1);
	delimage(pimg_Uaim1);
	delimage(pimg_ManUP1);
	delimage(pimg_ManLEFT1);
	delimage(pimg_ManDOWN1);
	delimage(pimg_ManRIGHT1);

	delimage(pimg_box2);
	delimage(pimg_aim2);
	delimage(pimg_Uaim2);
	delimage(pimg_ManDOWN2);
	delimage(pimg_ManRIGHT2);
	delimage(pimg_ManUP2);
	delimage(pimg_ManLEFT2);

	mus.Close();
	mus1.Close();
//	mus2.Close();
//	mus3.Close();

	return reValue;
}

//打印地图
Map* LoadMap(int level)
{
	Map *temp = (Map*)malloc(sizeof(Map));
	char buffer[256];

	FILE *fp;
	sprintf(buffer, "resources/Map/%d.txt", level);
	fp = fopen(buffer, "r");

	temp->level = level;
	temp->aim_count = 0;

	for (int i = 0;; i++) {    //循环读取文件内容，直到达到退出条件
		fgets(temp->map[i], 256, fp);   //读取一行字符串
		temp->map[i][strlen(temp->map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'
		for (int j = 0; temp->map[i][j] != '\0'; j++) {
			switch (temp->map[i][j]) {
			case '@':
				temp->x = j;
				temp->y = i;
				break;
			case 'X':
			case 'Q':
				temp->aimx[temp->aim_count] = j;
				temp->aimy[temp->aim_count] = i;
				temp->aim_count++;
				break;
			}
		}
		if (temp->map[i][1] == '|') {//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
			temp->map[i][1] = '=';//将该位字符设置为'='
			temp->h = i + 1;
			break;//跳出循环
		}
	}
	fclose(fp);
	return temp;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

void game_face(int level, int step_num, int restep_num)
{
	cleardevice();

	mciSendString("open resources\\music\\BGM2.mp3 alias bgm2", NULL, 0, NULL);
	mciSendString("play bgm2 repeat", NULL, 0, NULL);

	PIMAGE pimg_BG1 = newimage();
	getimage(pimg_BG1, "resources\\image\\menu\\BG1.jpg", 0, 0);
	putimage( 0,0, pimg_BG1);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(1075, 0, 1080, 720);

	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	char str[20];
	sprintf(str, "第%d关", level);
	outtextxy(1100, 100, str);
	setfont(24, 0, "楷体");
	sprintf(str, "步数：%d", step_num);
	outtextxy(1080, 250, str);

	sprintf(str, "剩余撤销次数：%d", restep_num);
	outtextxy(1080, 300, str);

	outtextxy(1080, 350, "重玩本关(R)");
	outtextxy(1080, 400, "撤销(U)");
	outtextxy(1080, 450, "暂停(ESC)");
}

void pause()
{
	cleardevice();

	PIMAGE pimg_BG2 = newimage();
	getimage(pimg_BG2, "resources\\image\\menu\\BG2.jpg", 0, 0);
	putimage(0, 0, pimg_BG2);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(400, 200, "继续(R)");

	setfont(40, 0, "楷体");
	outtextxy(140, 300, "选关(X)");
	outtextxy(320, 300, "重玩(Q)");
	outtextxy(480, 300, "下一关(N)");
	outtextxy(700, 300, "主菜单(M)");

	setfont(30, 0, "楷体");
	outtextxy(140, 400, "不同角色有不同超能力");
	outtextxy(140, 450, "普通小人可以无限撤消");
	outtextxy(140, 500, "王校长可以吞箱子");
	outtextxy(140, 550, "蜘蛛侠可以拉箱子");
	outtextxy(140, 600, "I、J、K、L向不同方向使用能力");
	outtextxy(140, 650, "按Q、E切换人物");

	delimage(pimg_BG2);
}

void passlevel(int step_num)
{
	cleardevice();

	PIMAGE pimg_BG3 = newimage();
	getimage(pimg_BG3, "resources\\image\\menu\\BG3.jpg", 0, 0);
	putimage(0, 0, pimg_BG3);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(60, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(420, 150, "过关！");

	setfont(40, 0, "楷体");
	char str[20];
	sprintf(str, "本关总计步数:%d", step_num);
	outtextxy(350, 250, str);

	setfont(40, 0, "楷体");
	outtextxy(140, 350, "选关(X)");
	outtextxy(320, 350, "重玩(Q)");
	outtextxy(480, 350, "下一关(N)");
	outtextxy(700, 350, "菜单(M)");
}

void lastlevel()
{
	cleardevice();

	PIMAGE pimg_BG4 = newimage();
	getimage(pimg_BG4, "resources\\image\\menu\\BG4.jpg", 0, 0);
	putimage(0, 0, pimg_BG4);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(420, 150, "这已经是最后一关了！");

	setfont(40, 0, "楷体");
	outtextxy(140, 350, "选关(X)");
	outtextxy(320, 350, "重玩(Q)");
	outtextxy(480, 350, "下一关(N)");
	outtextxy(700, 350, "菜单(M)");
}


