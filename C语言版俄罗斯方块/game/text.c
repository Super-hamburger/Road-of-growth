#include<stdio.h>
#include<windows.h>//����windows��API����
#include<conio.h>  //���ü��̴�����
#include<time.h>   //�����������
#define width 15   //��ͼ���
#define hight 25   //��ͼ�߶�

int key = 80;		//������Ϣ��ʼ��
int Fivebox = 1;	//������״��ʼ��

int map[width][hight] = { 0 };//��һ����ά���鱣��������Ϸ�ķ�����Ϣ
int (*p)(int, int, int);
int changebox(int x, int y, int choose, int (*p)(int, int, int));//�����ܷ�任�ɸú�������
int movebox(int x, int y, int choose, int (*p)(int, int, int));//�����ܷ��ƶ��ɸú�������
void gotoxy(int x, int y)//���겶����
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
	*����̨���������������
	*��������72
	*��������80
	*��������75
	*��������77
	*/
int appear_1()//����Ƿ����һ�ж��з���������������ñ����㷨
{
	for (int y = 1, a = 0; y < hight - 1; y++, a = 0)
	{
		for (int x = 1; x < width - 1; x++)
		{
			if (map[x][y] == 1)
			{
				a++;
				if (a == width - 2)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int all_0()//���µ��ϼ�⣬��ȡ��һ��ȫû�з�����������㷨ͬ��
{
	for (int y = hight - 2, a = 0; y > 0; y--, a = 0)
	{
		for (int x = 1; x < width - 1; x++)
		{
			if (map[x][y] == 0)
			{
				a++;
				if (a == width - 2)
				{
					return y;
				}
			}
		}
	}
	return 0;
}
int all_1(int hig)//�жϵ�hig���Ƿ�ȫ���з��飬�㷨ͬ��
{
	int a = 0;
	for (int x = 1; x < width - 1; x++)
	{
		if (map[x][hig] == 1)
		{
			a++;
			if (a == width - 2)
			{
				return 1;
			}
		}
	}
	return 0;
}
void drawmap_again()//��Ϸ�����ػ棬��������Χǽ
{
	Sleep(1000);
	int a0 = 0;			//������¼��һ�����顱��������
	int y = hight - 2;	//�ػ����ʼ������Ҳ������ײ�
	int Y = all_0();	//���ò���all_0()
	while (y > Y)
	{
		if (all_1(y)) a0++;
		for (int w = 1; w < width - 1; w++)
		{
			if (y > Y - a0)
			{
				map[w][y] = map[w][y - a0];
				gotoxy(2 * w, y);
				(map[w][y] == 1) ? printf("��") : printf("  ");
			}
			else
			{
				map[w][y] = 0;
				gotoxy(2 * w, y);
				printf("  ");
			}
		}
		y--;
	}
}

int keydown()
{
	if (_kbhit())			//�ж��Ƿ��ɰ�������
	{
		fflush(stdin);		//��֮ǰ�������İ�����Ϣ���
		key = _getch();
		key = _getch();		//�����ȡ���Σ���ԭ�������_getch()���÷�
	}
	switch (key)
	{
	case 72:return 1;
	case 75:return 2;
	case 77:return 3;
	}
	return 0;
}

void begin_drawmap()//��Ϸ��ͼ��ʼ�����ƣ���ʵ���ǻ�Χǽ��
{
	for (int _y = 0; _y < hight; _y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == 0 || _y == 0 || _y == hight - 1 || x == width - 1)
				map[x][_y] = 1;
			gotoxy(2 * x, _y);
			(map[x][_y] == 1) ? printf("��") : printf("  ");
		}
	}
}
//L
void printbox1(int x, int y, int choose, int print)
{
	switch (choose)
	{
	case 1:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 2:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 3:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 4:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	}
}
int enable1(int x, int y, int choose)//�ж϶Է���Ĳ����Ƿ���У����������һ��λ�û�״̬�Ƿ������������غ�
{
	switch (choose)
	{
	case 1:
		switch (key)
		{
		case 75:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y - 1] == 1 || map[(x + 4) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x - 2) / 2][y - 1] == 1 || map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y - 1] == 1 || map[(x + 4) / 2][y + 1] == 1) ? 3 : 2;
		}
	case 2:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 4) / 2][y + 1] == 1) ? 0 : 1;
		case 77:return (map[x / 2][y + 1] == 1 || map[(x + 4) / 2][y] == 1) ? 0 : 1;
		case 72:return (map[(x - 4) / 2][y] == 1 || map[(x - 4) / 2][y + 1] == 1 || map[x / 2][y + 1] == 1 || map[(x + 4) / 2][y] == 1) ? 3 : 2;
		}
	case 3:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y - 1] == 1 || map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y - 1] == 1 || map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[(x - 4) / 2][y - 1] == 1 || map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x + 2) / 2][y - 1] == 1 || map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 3 : 2;
		}
	case 4:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[x / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 4) / 2][y - 1] == 1 || map[(x + 4) / 2][y] == 1) ? 0 : 1;
		case 72:return (map[(x - 4) / 2][y] == 1 || map[x / 2][y - 1] == 1 || map[(x + 4) / 2][y - 1] == 1 || map[(x + 4) / 2][y] == 1) ? 3 : 2;
		}
	}
	return 0;
}
int upbox1(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
		if (map[x / 2][y + 2] == 1 || map[(x + 2) / 2][y + 2] == 1)
		{
			map[x / 2][y] = 1;
			map[x / 2][y - 1] = 1;
			map[x / 2][y + 1] = 1;
			map[(x + 2) / 2][y + 1] = 1;
			printbox1(x, y, choose, 1);
			return 0;
		}
		break;
	case 2:
		if (map[(x - 2) / 2][y + 2] == 1 || map[x / 2][y + 1] == 1 || map[(x + 2) / 2][y + 1] == 1)
		{
			map[x / 2][y] = 1;
			map[(x - 2) / 2][y] = 1;
			map[(x + 2) / 2][y] = 1;
			map[(x - 2) / 2][y + 1] = 1;
			printbox1(x, y, choose, 1);
			return 0;
		}
		break;
	case 3:
		if (map[(x - 2) / 2][y] == 1 || map[x / 2][y + 2] == 1)
		{
			map[x / 2][y] = 1;
			map[(x - 2) / 2][y - 1] = 1;
			map[x / 2][y - 1] = 1;
			map[x / 2][y + 1] = 1;
			printbox1(x, y, choose, 1);
			return 0;
		}
		break;
	case 4:
		if (map[(x - 2) / 2][y] == 1 || map[x / 2][y + 1] == 1 || map[(x + 2) / 2][y] == 1)
		{
			map[x / 2][y] = 1;
			map[(x - 2) / 2][y] = 1;
			map[(x + 2) / 2][y] = 1;
			map[(x + 2) / 2][y - 1] = 1;
			printbox1(x, y, choose, 1);
			return 0;
		}
		break;
	}
	return 1;
}
void Box1()
{
	int x = 10;//����x�����ʼ��
	int y = 2;
	int choose = 1;		//������̬��ʼ��Ϊ��һ��
	int up = 1;
	while (upbox1(x, y, choose))//�����鲻�����ʱ���˳��Է���Ĳ���
	{
		printbox1(x, y, choose, 1);//���ĸ�����Ϊ1ʱ��ʾ�����飬Ϊ0ʱΪɾ������
		Sleep(500);
		printbox1(x, y, choose, 0);
		choose = changebox(x, y, choose, enable1);//ÿ�ַ�����һ��������̬��choose������¼�������̬
		x += movebox(x, y, choose, enable1);
		y += upbox1(x, y, choose);
	}
}
//��
void printbox2(int x, int y, int choose, int print)
{
	switch (choose)
	{
	case 1:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 2:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 3:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 4:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	}
}
int enable2(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 4) / 2][y] == 1 || map[(x + 2) / 2][y - 1] == 1) ? 0 : 1;
		case 72:return (map[x / 2][y + 1] == 1) ? 3 : 2;

		}
	case 2:
		switch (key)
		{
		case 75:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y - 1] == 1 || map[(x + 4) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[(x - 2) / 2][y] == 1) ? 3 : 2;
		}
	case 3:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 4) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[x / 2][y - 1] == 1) ? 3 : 2;

		}
	case 4:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y - 1] == 1 || map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[(x + 2) / 2][y] == 1) ? 3 : 2;
		}
	}
	return 0;
}
int upbox2(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
		if (map[(x - 2) / 2][y + 1] == 1 || map[x / 2][y + 1] == 1 || map[(x + 2) / 2][y + 1] == 1)
		{
			map[(x - 2) / 2][y] = 1;
			map[x / 2][y] = 1;
			map[(x + 2) / 2][y] = 1;
			map[x / 2][y - 1] = 1;
			printbox2(x, y, choose, 1);

			return 0;
		}
		break;
	case 2:
		if (map[x / 2][y + 2] == 1 || map[(x + 2) / 2][y + 1] == 1)
		{
			map[x / 2][y - 1] = 1;
			map[(x + 2) / 2][y] = 1;
			map[x / 2][y] = 1;
			map[x / 2][y + 1] = 1;
			printbox2(x, y, choose, 1);

			return 0;
		}

		break;
	case 3:
		if (map[(x - 2) / 2][y + 1] == 1 || map[x / 2][y + 2] == 1 || map[(x + 2) / 2][y + 1] == 1)
		{
			map[(x - 2) / 2][y] = 1;
			map[x / 2][y] = 1;
			map[(x + 2) / 2][y] = 1;
			map[x / 2][y + 1] = 1;
			printbox2(x, y, choose, 1);

			return 0;
		}

		break;
	case 4:
		if (map[x / 2][y + 2] == 1 || map[(x - 2) / 2][y + 1] == 1)
		{
			map[x / 2][y - 1] = 1;
			map[(x - 2) / 2][y] = 1;
			map[x / 2][y] = 1;
			map[x / 2][y + 1] = 1;
			printbox2(x, y, choose, 1);

			return 0;
		}

		break;
	}
	return 1;
}
void Box2()
{
	int x = 10;
	int y = 2;
	int choose = 1;
	int up = 1;
	while (upbox2(x, y, choose))
	{
		printbox2(x, y, choose, 1);
		Sleep(500);
		printbox2(x, y, choose, 0);
		choose = changebox(x, y, choose, enable2);
		x += movebox(x, y, choose, enable2);
		y += upbox2(x, y, choose);
	}
}
//I
void printbox3(int x, int y, int choose, int print)
{
	switch (choose)
	{
	case 1:
	case 3:
		gotoxy(x, y - 2);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 2:
	case 4:
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 4, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	}
}

int enable3(int x, int y, int choose)
{

	switch (choose)
	{
	case 1:
	case 3:
		switch (key)
		{
		case 75:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y - 1] == 1 || map[(x - 2) / 2][y - 2] == 1 || map[(x - 2) / 2][y + 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y - 1] == 1 || map[(x + 2) / 2][y - 2] == 1 || map[(x + 2) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y - 2] == 1 || map[(x - 2) / 2][y + 1] == 1 || map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y - 2] == 1 || map[(x + 2) / 2][y + 1] == 1 || map[(x + 4) / 2][y] == 1) ? 3 : 2;

		}

	case 2:
	case 4:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1) ? 0 : 1;
		case 77:return (map[(x + 6) / 2][y] == 1) ? 0 : 1;
		case 72:return (map[x / 2][y + 1] == 1) ? 3 : 2;

		}
	}
	return 0;
}
int upbox3(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
	case 3:
		if (map[x / 2][y + 2] == 1)
		{
			map[x / 2][y - 2] = 1;
			map[x / 2][y - 1] = 1;
			map[x / 2][y] = 1;
			map[x / 2][y + 1] = 1;
			printbox3(x, y, choose, 1);
			return 0;
		}
		break;
	case 2:
	case 4:
		if (map[(x - 2) / 2][y + 1] == 1 || map[x / 2][y + 1] == 1 || map[(x + 2) / 2][y + 1] == 1 || map[(x + 4) / 2][y + 1] == 1)
		{
			map[(x - 2) / 2][y] = 1;
			map[x / 2][y] = 1;
			map[(x + 2) / 2][y] = 1;
			map[(x + 4) / 2][y] = 1;
			printbox3(x, y, choose, 1);
			return 0;
		}
		break;
	}
	return 1;
}
void Box3()
{
	int x = 10;
	int y = 3;
	int choose = 1;
	int up = 1;
	while (upbox3(x, y, choose))
	{
		printbox3(x, y, choose, 1);
		Sleep(500);
		printbox3(x, y, choose, 0);
		choose = changebox(x, y, choose, enable3);
		x += movebox(x, y, choose, enable3);
		y += upbox3(x, y, choose);
	}
}
//z
void printbox4(int x, int y, int choose, int print)
{
	switch (choose)
	{
	case 1:
	case 3:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	case 2:
	case 4:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x - 2, y - 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
		break;
	}
}
int enable4(int x, int y, int choose)
{

	switch (choose)
	{
	case 1:
	case 3:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 2)][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y] == 1 || map[(x + 4) / 2][y - 1] == 1) ? 0 : 1;
		case 72:return (map[x / 2][y + 1] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 3 : 2;
		}
	case 2:
	case 4:
		switch (key)
		{
		case 75:return (map[(x - 4) / 2][y] == 1 || map[(x - 4) / 2][y - 1] == 1 || map[(x - 2) / 2][y + 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 2) / 2][y] == 1 || map[(x + 2) / 2][y + 1] == 1 || map[x / 2][y - 1] == 1) ? 0 : 1;
		case 72:return (map[x / 2][y - 1] == 1 || map[(x + 2) / 2][y - 1] == 1) ? 3 : 2;

		}
	}
	return 0;
}
int upbox4(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
	case 3:
		if (map[x / 2][y + 1] || map[(x - 2) / 2][y + 1] == 1 || map[(x + 2) / 2][y] == 1)
		{
			map[x / 2][y] = 1;
			map[(x - 2) / 2][y] = 1;
			map[x / 2][y - 1] = 1;
			map[(x + 2) / 2][y - 1] = 1;
			printbox4(x, y, choose, 1);
			return 0;
		}
		break;
	case 2:
	case 4:
		if (map[x / 2][y + 2] == 1 || map[(x - 2) / 2][y + 1] == 1)
		{
			map[x / 2][y] = 1;
			map[(x - 2) / 2][y] = 1;
			map[(x - 2) / 2][y - 1] = 1;
			map[x / 2][y + 1] = 1;
			printbox4(x, y, choose, 1);

			return 0;
		}
		break;
	}
	return 1;
}
void Box4()
{
	int x = 10;
	int y = 2;
	int choose = 1;
	int up = 1;
	while (upbox4(x, y, choose))
	{
		printbox4(x, y, choose, 1);
		Sleep(500);
		printbox4(x, y, choose, 0);
		choose = changebox(x, y, choose, enable4);
		x += movebox(x, y, choose, enable4);
		y += upbox4(x, y, choose);
	}
}
//��
void printbox5(int x, int y, int choose, int print)
{
	switch (choose)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		gotoxy(x, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(x + 2, y + 1);
		print == 1 ? printf("��") : printf("  ");
		gotoxy(25, 0);
	}
}
int enable5(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		switch (key)
		{
		case 75:return (map[(x - 2) / 2][y] == 1 || map[(x - 2) / 2][y - 1] == 1) ? 0 : 1;
		case 77:return (map[(x + 4) / 2][y] == 1 || map[(x + 4) / 2][y + 1] == 1) ? 0 : 1;
		case 72:return 2;
		}
	}
	return 0;
}
int upbox5(int x, int y, int choose)
{
	switch (choose)
	{
	case 1:
	case 3:
	case 2:
	case 4:
		if (map[x / 2][y + 2] == 1 || map[(x + 2) / 2][y + 2] == 1)
		{
			map[x / 2][y] = 1;
			map[x / 2][y + 1] = 1;
			map[(x + 2) / 2][y] = 1;
			map[(x + 2) / 2][y + 1] = 1;
			printbox5(x, y, choose, 1);
			return 0;
		}
		break;
	}
	return 1;
}
void Box5()
{
	int x = 10;
	int y = 2;
	int choose = 1;
	int up = 1;
	while (upbox5(x, y, choose))
	{
		printbox5(x, y, choose, 1);
		Sleep(500);
		printbox5(x, y, choose, 0);
		choose = changebox(x, y, choose, enable5);
		x += movebox(x, y, choose, enable5);
		y += upbox5(x, y, choose);
	}
}
int creatnum()//����������ַ���
{
	int hisfivebox;
	do
	{
		srand((unsigned int)time(NULL));
		hisfivebox = Fivebox;
		Fivebox = rand() % 5 + 1;
	} while (hisfivebox == Fivebox);
	return Fivebox;
}
int main()
{
	system("mode con cols=40 lines=25");//���ÿ���̨�Ĵ�С
	begin_drawmap();
	while (1)
	{
		int CHOOSE = creatnum();//������Ϸ�����ַ�����״
		switch (CHOOSE)
		{
		case 1:Box1(); if (appear_1() == 1)drawmap_again(); break;
		case 2:Box2(); if (appear_1() == 1)drawmap_again(); break;
		case 3:Box3(); if (appear_1() == 1)drawmap_again(); break;
		case 4:Box4(); if (appear_1() == 1)drawmap_again(); break;
		case 5:Box5(); if (appear_1() == 1)drawmap_again(); break;
		}
	}
	return 0;
}
int changebox(int x, int y, int choose, int (*p)(int, int, int))
{
	if (keydown() == 1 && p(x, y, choose) == 2)
	{
		key = 80;
		choose++;
		if (choose == 5)
			choose = 1;
		return choose;
	}
	return choose;
}
int movebox(int x, int y, int choose, int (*p)(int, int, int))
{

	if (keydown() == 2 && p(x, y, choose) == 1)//��
	{
		key = 80;
		return -2;
	}
	if (keydown() == 3 && p(x, y, choose) == 1)//��
	{
		key = 80;
		return 2;
	}
	return 0;
}