//==========================
//1、运用了结构体。
//2、可以选择角色，运用超能力。
//3、可以无限撤消。
//==========================
#include"function.h"

//窗口尺寸
#define Win_L 1280
#define Win_H 720

int main(void)
{
	ege::setinitmode(ege::INIT_ANIMATION);
	// 图形初始化
	ege::initgraph(Win_L, Win_H);

	setcaption("推箱子黄金版");	   //修改窗口名称

	ege::randomize();		  	  // 随机数初始化，如果需要使用随机数的话

	mainloop();					 // 程序主循环

	ege::closegraph();			 // 关闭绘图设备

	return 0;
}

