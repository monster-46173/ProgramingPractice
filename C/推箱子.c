#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ROW 8
#define RANGE 6
int count_1();
int count_2();

int up();
int down();
int left();
int right();
int outPut();
int find();

int G_point_x, G_point_y;
int G_map[ROW][RANGE] = { 0 };

int main(void)
{
	/*�������Ϸ����ģ��*/
	int map[ROW][RANGE] = {
		{ 0, 1, 1, 1, 1, 0 },
		{ 1, 1, 0, 0, 1, 0 },
		{ 1, 3, 2, 0, 1, 0 },
		{ 1, 1, 2, 0, 1, 1 },
		{ 1, 1, 0, 2, 0, 1 },
		{ 1, 4, 2, 0, 0, 1 },
		{ 1, 4, 4, 5, 4, 1 },
		{ 1, 1, 1, 1, 1, 1 }
	};  /*0�ǿհ� 1��ǽ 2������ 3���� 4��Ŀ�� 5��Ŀ���ϵ�����*/
	system("title ������2.0");
	memcpy(G_map, map, sizeof(map));
	printf("***���������ʼ��Ϸ***\n");
	_getch();

	for (; ; )
	{
		system("cls");
		outPut();
		find();
		switch (getch())
		{
		case 'w':
		case 72:
		{
			up();
			break;
		}
		case 's':
		case 80:
		{
			down();
			break;
		}
		case 'a':
		case 75:
		{
			left();
			break;
		}
		case 'd':
		case 77:
		{
			right();
			break;
		}
		case 'r':/*���¿�ʼ��Ϸ*/
		{
			memcpy(G_map, map, sizeof(map));
			break;
		}
		}
		if (count_1() == count_2())
		{
			system("cls");
			outPut();
			printf("\n��Ϸʤ������������˳�\n");
			system("pause");
			return 0;
		}
	}
	system("cls");
	outPut();
	system("pause");
	return 0;
}
/*����Ļ���������ͼ�Σ�����������ǽ�����ѡ������ˡ��������������ӡ��������Ŀ��㡢
����������հ�������˿��ߵ����򡢡����ʾ�Ѿ���Ŀ����ϵ����ӡ����񡱱�ʾ��Ŀ����ϵ���*/
int outPut(void)
{
	for (G_point_x = 0; G_point_x < ROW; G_point_x++)
	{
		for (G_point_y = 0; G_point_y < RANGE; G_point_y++)
		{
			if (G_map[G_point_x][G_point_y] == 0)
				printf("��"); /*����հ�*/
			if (G_map[G_point_x][G_point_y] == 1)
				printf("��"); /*���ǽ*/
			if (G_map[G_point_x][G_point_y] == 2)
				printf("��"); /*�������*/
			if (G_map[G_point_x][G_point_y] == 3)
				printf("��"); /*����˵�λ��*/
			if (G_map[G_point_x][G_point_y] == 4)
				printf("��"); /*���Ŀ���*/
			if (G_map[G_point_x][G_point_y] == 5)
				printf("��"); /*���������Ŀ�����*/
			if (G_map[G_point_x][G_point_y] == 6)
				printf("��"); /*�������Ŀ�����*/
		}
		printf("\n");
	}
	return 0;
}
/*����Ŀ���ĸ������������ӻ�����Ŀ����ϣ�*/
int count_1(void)
{
	int i = 0;
	for (G_point_x = 0; G_point_x < ROW; G_point_x++)
		for (G_point_y = 0; G_point_y < RANGE; G_point_y++)
		{
			if (G_map[G_point_x][G_point_y] == 4 ||
				G_map[G_point_x][G_point_y] == 5 ||
				G_map[G_point_x][G_point_y] == 6)
				i++;
		}
	return i;
}
/*������Ŀ����ϵ����ӵĸ���*/
int count_2(void)
{
	int i = 0;
	for (G_point_x = 0; G_point_x < ROW; G_point_x++)
		for (G_point_y = 0; G_point_y < RANGE; G_point_y++)
		{
			if (G_map[G_point_x][G_point_y] == 5)
				i++;
		}
	return i;
}
/*�ҵ��Լ���λ��*/
int find(void)
{
	for (G_point_x = 0; G_point_x < ROW; G_point_x++)
		for (G_point_y = 0; G_point_y < RANGE; G_point_y++)
		{
			if (G_map[G_point_x][G_point_y] == 3 || G_map[G_point_x][G_point_y] == 6)
				return 0;
		}
	return 0;
}
/*��w��ʱ���������*/
int up(void)
{
	if (G_map[G_point_x][G_point_y] == 3 ||
		G_map[G_point_x][G_point_y] == 6) /*ȷ�����Լ���λ��*/
	{
		switch (G_map[G_point_x - 1][G_point_y])
		{
		case 0: /*����һ�������ǿյ�*/
		{
			G_map[G_point_x - 1][G_point_y] = 3;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 4: /*����һ��������Ŀ���*/
		{
			G_map[G_point_x - 1][G_point_y] = 6;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 2: /*����һ������������*/
		{
			if (G_map[G_point_x - 2][G_point_y] == 0)
			{
				G_map[G_point_x - 2][G_point_y] = 2;
				G_map[G_point_x - 1][G_point_y] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x - 2][G_point_y] == 4)
			{
				G_map[G_point_x - 2][G_point_y] = 5;
				G_map[G_point_x - 1][G_point_y] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		case 5: /*����һ��������Ŀ����ϵ�����*/
		{
			if (G_map[G_point_x - 2][G_point_y] == 0)
			{
				G_map[G_point_x - 2][G_point_y] = 2;
				G_map[G_point_x - 1][G_point_y] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x - 2][G_point_y] == 4)
			{
				G_map[G_point_x - 2][G_point_y] = 5;
				G_map[G_point_x - 1][G_point_y] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		}
	}
	return 0;
}
/*��s��ʱ���������*/
int down(void)
{
	if (G_map[G_point_x][G_point_y] == 3 ||
		G_map[G_point_x][G_point_y] == 6) /*ȷ�����Լ���λ��*/
	{
		switch (G_map[G_point_x + 1][G_point_y])
		{
		case 0: /*����һ�������ǿյ�*/
		{
			G_map[G_point_x + 1][G_point_y] = 3;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 4: /*����һ��������Ŀ���*/
		{
			G_map[G_point_x + 1][G_point_y] = 6;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 2: /*����һ������������*/
		{
			if (G_map[G_point_x + 2][G_point_y] == 0)
			{
				G_map[G_point_x + 2][G_point_y] = 2;
				G_map[G_point_x + 1][G_point_y] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x + 2][G_point_y] == 4)
			{
				G_map[G_point_x + 2][G_point_y] = 5;
				G_map[G_point_x + 1][G_point_y] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		case 5: /*����һ��������Ŀ����ϵ�����*/
		{
			if (G_map[G_point_x + 2][G_point_y] == 0)
			{
				G_map[G_point_x + 2][G_point_y] = 2;
				G_map[G_point_x + 1][G_point_y] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x + 2][G_point_y] == 4)
			{
				G_map[G_point_x + 2][G_point_y] = 5;
				G_map[G_point_x + 1][G_point_y] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		}
	}
	return 0;
}
/*��a��ʱ���������*/
int left(void)
{
	if (G_map[G_point_x][G_point_y] == 3 ||
		G_map[G_point_x][G_point_y] == 6) /*ȷ�����Լ���λ��*/
	{
		switch (G_map[G_point_x][G_point_y - 1])
		{
		case 0: /*����һ�������ǿյ�*/
		{
			G_map[G_point_x][G_point_y - 1] = 3;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 4: /*����һ��������Ŀ���*/
		{
			G_map[G_point_x][G_point_y - 1] = 6;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 2: /*����һ������������*/
		{
			if (G_map[G_point_x][G_point_y - 2] == 0)
			{
				G_map[G_point_x][G_point_y - 2] = 2;
				G_map[G_point_x][G_point_y - 1] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x][G_point_y - 2] == 4)
			{
				G_map[G_point_x][G_point_y - 2] = 5;
				G_map[G_point_x][G_point_y - 1] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		case 5: /*����һ��������Ŀ����ϵ�����*/
		{
			if (G_map[G_point_x][G_point_y - 2] == 0)
			{
				G_map[G_point_x][G_point_y - 2] = 2;
				G_map[G_point_x][G_point_y - 1] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x][G_point_y - 2] == 4)
			{
				G_map[G_point_x][G_point_y - 2] = 5;
				G_map[G_point_x][G_point_y - 1] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		}
	}
	return 0;
}
/*��d��ʱ���������*/
int right(void)
{
	if (G_map[G_point_x][G_point_y] == 3 ||
		G_map[G_point_x][G_point_y] == 6) /*ȷ�����Լ���λ��*/
	{
		switch (G_map[G_point_x][G_point_y + 1])
		{
		case 0: /*����һ�������ǿյ�*/
		{
			G_map[G_point_x][G_point_y + 1] = 3;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 4: /*����һ��������Ŀ���*/
		{
			G_map[G_point_x][G_point_y + 1] = 6;
			if (G_map[G_point_x][G_point_y] == 3)
				G_map[G_point_x][G_point_y] = 0;
			else
				G_map[G_point_x][G_point_y] = 4;
			break;
		}
		case 2: /*����һ������������*/
		{
			if (G_map[G_point_x][G_point_y + 2] == 0)
			{
				G_map[G_point_x][G_point_y + 2] = 2;
				G_map[G_point_x][G_point_y + 1] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x][G_point_y + 2] == 4)
			{
				G_map[G_point_x][G_point_y + 2] = 5;
				G_map[G_point_x][G_point_y + 1] = 3;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		case 5: /*����һ��������Ŀ����ϵ�����*/
		{
			if (G_map[G_point_x][G_point_y + 2] == 0)
			{
				G_map[G_point_x][G_point_y + 2] = 2;
				G_map[G_point_x][G_point_y + 1] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			else if (G_map[G_point_x][G_point_y + 2] == 4)
			{
				G_map[G_point_x][G_point_y + 2] = 5;
				G_map[G_point_x][G_point_y + 1] = 6;
				if (G_map[G_point_x][G_point_y] == 3)
					G_map[G_point_x][G_point_y] = 0;
				else
					G_map[G_point_x][G_point_y] = 4;
			}
			break;
		}
		}
	}
	return 0;
}
