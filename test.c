#include"CommentConvert.h"
void test()
{
		FILE *pfin = NULL;
		FILE *pfout = NULL;
		pfin = fopen("input.c", "r");  //以读的形式打开input文件
		if (pfin == NULL)              //如果失败
		{
			perror("open file for read");
			system("pause");
			exit();
		}
		pfout = fopen("output.c", "w"); //以写的形式打开output文件
		if (pfout == NULL)              //如果失败
		{
			fclose("input");            //关闭inout文件
			perror("open file for wirte");
			system("pause");
			exit();
		}
		DoCommentConvert(pfin, pfout);  //函数调用
		fclose(pfin);                   //调用之后，关闭input，output
		fclose(pfout);
		printf("转化成功！\n");
}
int main()
{
	test();
	system("pause");
	return 0;
}