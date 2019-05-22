#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define N 10
char arr[N][N];
struct Pos
{
	int xpos; //��ƫ����
	int ypos; //��ƫ����
}p[3] = { { -1, -1 }, { 0 ,-1 }, {1,-1 } };
//��ʼ������
void Init()
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int j = 0;
		for (j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
			//�߿�����Ϊ#
			arr[0][j] = '#';       
			arr[N - 1][j] = '#';
			arr[i][0] = '#';
			arr[i][N - 1] = '#';
		}
	}
}
//չʾ����
void Show()
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int j = 0;
		for (j = 0; j < N; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
//����Ƿ���԰ڷ�
int check_put( int row, int col)
{
	int i;
	int ret = 1;
	int nr = row;
	int nc = col;
	for (i = 0; ret&&i < 3; i++)   //��Ҫ�ж������Խ����Լ��Ϸ��Ƿ��лʺ�
	{
		nr = row;
		nc = col;
		while ((arr[nr][nc] != '#')&&ret) //ѭ������Ե��ֹ
		{
			if (arr[nr][nc] == ' ')      //�ж����λ���Ƿ��лʺ�
			{
				nr = nr + p[i].ypos;     
				nc = nc + p[i].xpos;
			}
			else
				ret = 0;
		}	
	}
	return ret;
}
//�ڻʺ�
void Find(int row)
{
	int j = 0;
	static int count = 0;   //���ڼ���ڻʺ��ж��������
	if (row > N - 2)        //����1-8�к��ӡ
	{
		Show();
		count++;
		printf("count=%d\n", count);
	}
	else
	{
		for (j = 1; j < N - 1; j++)
		{
			if (check_put(row, j))  //�ж��Ƿ���ԷŻʺ�������Է���1��
			{
				arr[row][j] = '*';  //����λ�÷��ϻʺ�
				Find( row + 1);     //�ݹ����һ��
				arr[row][j] = ' ';
			}
		}
	}
}
int main()
{
	//��ʼ������  
	Init();
	//�ڻʺ�
	Find(1);
	system("pause");
	return 0;
}