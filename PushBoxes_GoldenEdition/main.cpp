//==========================
//1�������˽ṹ�塣
//2������ѡ���ɫ�����ó�������
//3���������޳�����
//==========================
#include"function.h"

//���ڳߴ�
#define Win_L 1280
#define Win_H 720

int main(void)
{
	ege::setinitmode(ege::INIT_ANIMATION);
	// ͼ�γ�ʼ��
	ege::initgraph(Win_L, Win_H);

	setcaption("�����ӻƽ��");	   //�޸Ĵ�������

	ege::randomize();		  	  // �������ʼ���������Ҫʹ��������Ļ�

	mainloop();					 // ������ѭ��

	ege::closegraph();			 // �رջ�ͼ�豸

	return 0;
}

