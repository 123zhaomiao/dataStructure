#include"CommentConvert.h"
void test()
{
		FILE *pfin = NULL;
		FILE *pfout = NULL;
		pfin = fopen("input.c", "r");  //�Զ�����ʽ��input�ļ�
		if (pfin == NULL)              //���ʧ��
		{
			perror("open file for read");
			system("pause");
			exit();
		}
		pfout = fopen("output.c", "w"); //��д����ʽ��output�ļ�
		if (pfout == NULL)              //���ʧ��
		{
			fclose("input");            //�ر�inout�ļ�
			perror("open file for wirte");
			system("pause");
			exit();
		}
		DoCommentConvert(pfin, pfout);  //��������
		fclose(pfin);                   //����֮�󣬹ر�input��output
		fclose(pfout);
		printf("ת���ɹ���\n");
}
int main()
{
	test();
	system("pause");
	return 0;
}