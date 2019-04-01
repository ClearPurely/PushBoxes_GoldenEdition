#include"function.h"

void mainloop()
{
	int a=1;
	int b=1;
	int c = 0;

	int level;
	int level_option;
	int scenes;
	char option;
	int isend;
	int character;

	character = 0;
	level = 1;
	level_option = 1;
	scenes = 0;
	isend = 0;
//关卡锁
	int keys;

	
	while (is_run())
	{
//判断并打印主界面
		switch (scenes)
		{
		case 0:
			if (a == 1)
				main_interface0_1();
			else if (a == 2)
				main_interface0_2();
			break;
		case 1:
			if(b==1)
				main_interface1_1();
			else if(b == 2)
				main_interface1_2();
			else if (b == 3)
				main_interface1_3();
			else if (b == 4)
				main_interface1_4();
			break;
		case 2:
			selectLevel(level_option);
			break; 
		case 7:
			if (c == 0)
				select_hero0();
			else if (c == 1)
				select_hero1();
			else if (c == 2)
				select_hero2();

		default:
			break;
		}

		if (scenes < 3 || scenes==7)
			option = getch();

		switch (scenes)
		{
//第一界面的操作指令
		case 0:
			switch (option)
			{
			case 'W':
			case 'w':
				if (a==2)
					a = 1;
				else if (a == 1)
					a = 2;
					scenes = 0;
					break;
			case's':
			case'S':
				if(a==1)
					a = 2;
				else if (a == 2)
					a = 1;
					scenes = 0;
					break;
			case 13:
			case 32:
				if (a == 1)
					scenes = 1;
				else if (a == 2)
					isend = 1;
				mciSendString("close bgm", NULL, 0, NULL);
				break;
			default:
				break;
			}
			break;
//第二界面的操作指令
		case 1:
			switch (option)
			{
			case 'W':
			case 'w':
				if (b <= 4 && b > 1 )
					b--;
				else if (b == 1)
					b=4;
				scenes = 1;
				break;
			case's':
			case'S':
				if (b == 4)
					b = 1;
				else if ( b < 4 && b>=1)
					b++;
				scenes = 1;
				break;
			case 32:
			case 13:
				if (b == 1)
					scenes = 3;
				else if (b == 2)
					scenes = 2;
				else if (b == 3)
					scenes = 0;
				else if (b == 4)
					scenes = 7;

				mciSendString("close bgm1", NULL, 0, NULL);
				break;
			default:
				break;
			}
			break;
//选关界面操作指令
		case 2: 
//关卡锁
			FILE *fp1;//用于打开关卡文件的文件指针
			fp1 = fopen("resources\\data\\key.txt", "r");//以只
			fscanf(fp1, "%d", &keys);
			fclose(fp1);
/*			int pd1[35] = { 0 };
			for (int i = 0; i <= keys; i++)
			{
				pd1[keys] = 0;
			}
			for (int i = (maps_num-keys); i < 35; i++)
			{
				pd1[keys] = 1;
			}
*/
			switch (option)
			{
			case 'd':
			case 'D':
				if (level_option < keys)
					level_option++;
				break;
			case 'a':
			case 'A':
				if (level_option > 1)
					level_option--;
				break;
			case 32:
			case 13:
				mciSendString("close bgm3", NULL, 0, NULL);
				level = level_option;
				scenes = 4;
				break; 
			case 27:
				mciSendString("close bgm3", NULL, 0, NULL);
				scenes = 1;
				break;
			default:
				break;
			}
			break;
//从头开始，进入游戏
		case 3:
			level = 1;
			scenes = gameloop(level, character,keys);
			break;
//开始所选关卡或进入下一关
		case 4:
			scenes = gameloop(level, character,keys);
			break;
//开始下一关
		case 5:
			level++;
			scenes = 4;
			break;
//通关重置数据
		case 6:
			level = 0;
			scenes = 0;
			break;
//选择角色
		case 7:
			switch (option)
			{
			case 'a':
			case 'A':
				if (c <= 2 && c > 0)
					c--;
				else if (c == 0)
					c = 2;
				scenes = 7;
				break;
			case'D':
			case'd':
				if (c == 2)
					c = 0;
				else if (c < 2 && b >= 0)
					c++;
				scenes = 7;
				break;
			case 32:
			case 13:
				mciSendString("close select", NULL, 0, NULL);
				if (c == 0)
					character = 0;
				else if (c == 1)
					character = 1;
				else if (c == 2)
					character = 2;
				scenes = 1;
				break;
			default:
				break;

			}
		default:
			break;
		}
		if (isend)
		{
			break;
		}
	}
}

void main_interface0_1()
{
	mciSendString("open resources\\music\\BGM.mp3 alias bgm", NULL, 0, NULL);
	mciSendString("play bgm repeat", NULL, 0, NULL);

	PIMAGE menu0_1 = newimage();
	getimage(menu0_1, "resources\\image\\menu\\01.jpg", 0, 0);

//清屏
	cleardevice();

	putimage(0, 0, menu0_1);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(25, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(200, 600, "按W,S选择，回车和空格确认。");

	delimage(menu0_1);
}

void main_interface0_2()
{
	PIMAGE menu0_2 = newimage();
	getimage(menu0_2, "resources\\image\\menu\\02.jpg", 0, 0);



	//清屏
	cleardevice();

	putimage(0, 0, menu0_2);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(25, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(200, 600, "按W,S选择，回车和空格确认。");

	delimage(menu0_2);
}

void main_interface1_1()
{	
	mciSendString("open resources\\music\\BGM1.mp3 alias bgm1", NULL, 0, NULL);
	mciSendString("play bgm1 repeat", NULL, 0, NULL);
	
	PIMAGE pimg_menu1_1 = newimage();
	getimage(pimg_menu1_1, "resources\\image\\menu\\11.jpg", 0, 0);



	//清屏
	cleardevice();

	putimage(0, 0, pimg_menu1_1);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_menu1_1);
}

void main_interface1_2()
{
	PIMAGE pimg_menu1_2 = newimage();
	getimage(pimg_menu1_2, "resources\\image\\menu\\12.jpg", 0, 0);
//清屏
	cleardevice();

	putimage(0, 0, pimg_menu1_2);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_menu1_2);
}

void main_interface1_3()
{
	PIMAGE pimg_menu1_3 = newimage();
	getimage(pimg_menu1_3, "resources\\image\\menu\\13.jpg", 0, 0);
	//清屏
	cleardevice();

	putimage(0, 0, pimg_menu1_3);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_menu1_3);
}

void main_interface1_4()
{
	PIMAGE pimg_menu1_4 = newimage();
	getimage(pimg_menu1_4, "resources\\image\\menu\\14.jpg", 0, 0);
	//清屏
	cleardevice();

	putimage(0, 0, pimg_menu1_4);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_menu1_4);
}

void selectLevel(int level)
{
	mciSendString("open resources\\music\\BGM3.mp3 alias bgm3", NULL, 0, NULL);
	mciSendString("play bgm3 repeat", NULL, 0, NULL);


	PIMAGE pimg_select = newimage();
	getimage(pimg_select, "resources\\image\\menu\\21.jpg", 0, 0);
	//清屏
	cleardevice();

	putimage(0, 0, pimg_select);


	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	setfont(48, 0, "楷体");

	setbkmode(TRANSPARENT);
	outtextxy(670, 60, "按A，D键选关");
	char str[20];
	sprintf(str, "关卡:%d", level);
	outtextxy(820, 130, str);
	outtextxy(900, 250, "返回(ESC)");
}

void select_hero0()
{
	mciSendString("open resources\\music\\SOME.mp3 alias select", NULL, 0, NULL);
	mciSendString("play select repeat", NULL, 0, NULL);

	cleardevice();

	PIMAGE pimg_SH0 = newimage();
	getimage(pimg_SH0, "resources\\image\\menu\\hero0.jpg", 0, 0);
	putimage(0, 0, pimg_SH0);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_SH0);
}

void select_hero1()
{
	mciSendString("open resources\\music\\SOME.mp3 alias select", NULL, 0, NULL);
	mciSendString("play select repeat", NULL, 0, NULL);

	cleardevice();

	PIMAGE pimg_SH1 = newimage();
	getimage(pimg_SH1, "resources\\image\\menu\\hero1.jpg", 0, 0);
	putimage(0, 0, pimg_SH1);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_SH1);
}

void select_hero2()
{
	mciSendString("open resources\\music\\SOME.mp3 alias select", NULL, 0, NULL);
	mciSendString("play select repeat", NULL, 0, NULL);

	cleardevice();

	PIMAGE pimg_SH2 = newimage();
	getimage(pimg_SH2, "resources\\image\\menu\\hero2.jpg", 0, 0);
	putimage(0, 0, pimg_SH2);

	setfillcolor(WHITE);
	bar(0, 715, 1280, 720);
	bar(0, 0, 5, 720);
	bar(1275, 0, 1280, 720);

	delimage(pimg_SH2);
}
