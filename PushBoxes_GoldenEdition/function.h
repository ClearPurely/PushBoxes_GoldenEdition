#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ege.h>
#include <graphics.h>



#include <mmsystem.h>
#include<string>
#pragma comment(lib,"winmm.lib")

#define maps_num 35

typedef struct Map {
	char map[50][50];
	int level;
	int h;

	int character;

	int x;
	int y;

	int aim_count;
	int aimx[50];
	int aimy[50];
}Map;



void mainloop();
int gameloop(int level,int character);

void main_interface0_1();
void main_interface0_2();

void main_interface1_1();
void main_interface1_2();
void main_interface1_3();
void main_interface1_4();
void select_hero0();
void select_hero1();
void select_hero2();

void selectLevel(int level);
//void LoadMap(int level, char(*map)[50]);

Map* LoadMap(int level);

