#include"game.h"
enum play
{
	tuichu,
	wanyouxi,
};
void menu()
{
	printf("********************\n");
	printf("**** 1    ����Ϸ****\n");
	printf("**** 0    �˳�******\n");
	printf("********************\n");
}
void game()
{
	char ret;
	char arr[ROW][COL] = { 0 };
	InitBoard(arr, ROW, COL);    //��ʼ������
	DisplayBoard(arr, ROW, COL); //��ӡ����
	while (1)
	{
		PalyerMove(arr, ROW, COL); //����ƶ�
	    ret = Is_Win(arr, ROW, COL);//�ж���Ӯ
		if (ret == 'x')
		{
			printf("���ʤ����\n");
			break;
		}
		else if (ret == '0')
		{
			printf("����Ӯ��\n");
			break;
		}
		else if (ret == '1')
		{
			printf("ƽ��\n");
			break;
		}
	   ComputerMove(arr, ROW, COL); //������
       ret = Is_Win(arr, ROW, COL); //�ж���Ӯ
		if (ret == 'x')
		{
			printf("���ʤ����\n");
			break;
		}
		else if (ret == '0')
		{
			printf("����Ӯ��\n");
			break;
		}
		else if (ret == '1')
		{
			printf("ƽ��\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case wanyouxi:
			game();
			break;
		case tuichu:printf("�˳���Ϸ��\n"); break;
		default:printf("ѡ�����������ѡ��\n");
		}
	} while (input);

}
int main()
{
	test();
	system("pause");
	return 0;
}