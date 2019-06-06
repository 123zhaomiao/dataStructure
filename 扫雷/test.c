#include"game.h"
enum game
{
	tuichu,
	wanyouxi
};
void menu()
{
	printf("*******************\n");
	printf("*****1    玩游戏***\n");
	printf("*****0    退出*****\n");
	printf("*******************\n");
}
void play()
{
	char mine[ROWS][COLS] = { 0 };      //用于放雷
	char show[ROWS][COLS] = { 0 };      //用于展示
	InitBoard(mine, ROWS, COLS,'0');    //初始化  雷阵mine初始化为字符‘0’，show初始化为字符‘*’；
	InitBoard(show, ROWS, COLS,'*');    //show初始化为字符‘*’
	SetMine(mine, ROW, COL);            //放置雷
	DisplayBoard(show, ROW, COL);       //打印数组show
	FindMine(mine, show, ROW, COL);     //扫雷
	printf("雷阵：\n");
	DisplayBoard(mine, ROW, COL);
}
void test()
{
	int input;                   //选择是否玩游戏
	srand((unsigned)time(NULL)); //生成随机数
	do
	{
		menu();
		printf("请做出选择：>"); 
		scanf("%d", &input);
		switch (input)
		{
		case wanyouxi:
			play();             //玩游戏
			break;
		case tuichu: printf("退出游戏！\n"); break;
		default:printf("输入错误，请重新输入！\n"); break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
