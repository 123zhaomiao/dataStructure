#include"game.h"
enum game
{
	tuichu,
	wanyouxi
};
void menu()
{
	printf("*******************\n");
	printf("*****1    ����Ϸ***\n");
	printf("*****0    �˳�*****\n");
	printf("*******************\n");
}
void play()
{
	char mine[ROWS][COLS] = { 0 };      //���ڷ���
	char show[ROWS][COLS] = { 0 };      //����չʾ
	InitBoard(mine, ROWS, COLS,'0');    //��ʼ��  ����mine��ʼ��Ϊ�ַ���0����show��ʼ��Ϊ�ַ���*����
	InitBoard(show, ROWS, COLS,'*');    //show��ʼ��Ϊ�ַ���*��
	SetMine(mine, ROW, COL);            //������
	DisplayBoard(show, ROW, COL);       //��ӡ����show
	FindMine(mine, show, ROW, COL);     //ɨ��
	printf("����\n");
	DisplayBoard(mine, ROW, COL);
}
void test()
{
	int input;                   //ѡ���Ƿ�����Ϸ
	srand((unsigned)time(NULL)); //���������
	do
	{
		menu();
		printf("������ѡ��>"); 
		scanf("%d", &input);
		switch (input)
		{
		case wanyouxi:
			play();             //����Ϸ
			break;
		case tuichu: printf("�˳���Ϸ��\n"); break;
		default:printf("����������������룡\n"); break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}