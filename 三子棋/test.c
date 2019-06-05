#include"game.h"
enum play
{
	tuichu,
	wanyouxi,
};
void menu()
{
	printf("********************\n");
	printf("**** 1    玩游戏****\n");
	printf("**** 0    退出******\n");
	printf("********************\n");
}
void game()
{
	char ret;
	char arr[ROW][COL] = { 0 };
	InitBoard(arr, ROW, COL);    //初始化棋盘
	DisplayBoard(arr, ROW, COL); //打印棋盘
	while (1)
	{
		PalyerMove(arr, ROW, COL); //玩家移动
	    ret = Is_Win(arr, ROW, COL);//判断输赢
		if (ret == 'x')
		{
			printf("玩家胜利！\n");
			break;
		}
		else if (ret == '0')
		{
			printf("电脑赢！\n");
			break;
		}
		else if (ret == '1')
		{
			printf("平局\n");
			break;
		}
	   ComputerMove(arr, ROW, COL); //电脑走
       ret = Is_Win(arr, ROW, COL); //判断输赢
		if (ret == 'x')
		{
			printf("玩家胜利！\n");
			break;
		}
		else if (ret == '0')
		{
			printf("电脑赢！\n");
			break;
		}
		else if (ret == '1')
		{
			printf("平局\n");
			break;
		}	
	}
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case wanyouxi:
			game();
			break;
		case tuichu:printf("退出游戏！\n"); break;
		default:printf("选择错误，请重新选择！\n");
		}
	} while (input);

}
int main()
{
	test();
	system("pause");
	return 0;
}
