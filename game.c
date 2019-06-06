#include"game.h"
//��ʼ������
void InitBoard(char arr[ROWS][COLS], int rows, int cols,char sz)
{
	memset(arr, sz, rows*cols*sizeof(arr[0][0]));
}
//����
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int i=0;                          //����
	while (i < Easy_Count)
	{
		int x = rand() % row + 1;     //rand()%row��������0~row-1֮�����
		int y = rand() % col + 1;     
		if (mine[x][y] == '0')        //��ֹ�ظ�����
		{
			mine[x][y] = '1';
			i++;
		}
	}
}
//��ӡ
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)           //��ӡ�б�---------0~9�������û�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);               //��ӡ�б�---------1~9
		for (j = 1; j <= col; j++)      //ѭ����ӡԪ��
		{
			printf("%c ", arr[i][j]);   
		}
		printf("\n");
	}
}
//�����׵�����
static int CountMine(char mine[ROWS][COLS], int x, int y)
{
	int count;//������Χ7���ط�   �ַ�1-�ַ�0=����1��
	count = (mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y] + 
		mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x + 1][y] + mine[x+1][y - 1] + mine[x + 1][y + 1]) - 8 * '0';
	return count;
}
//չ������
static void open_board(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i, j;
	if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))  //����Ϸ�
	{
		if (CountMine(mine, x, y) == 0)                //������Χû����
		{
			show[x][y] = '0';                         
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')             //�������ط�û��չ������ݹ�չ��
						open_board(mine, show, i, j);
				}
			}
		}
		else
			show[x][y] = CountMine(mine, x, y) + '0';
	}
}
//ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int i = 1;              
	int t;
	int m;
	while (1)
	{
		printf("���������꣺>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))      //����Ϸ�
		{
			if (mine[x][y] == '1')
			{
				if (i > 0)                          //��һ�����ף�Ų���ף�����ը��
				{ 
					    int count = 0;
						mine[x][y] = '0';           
						t = rand() % row + 1;       //��-------x����  
						m = rand() % col + 1;       //��-------y���� 
						if (mine[t][m] == '0')
						{
							mine[t][m] = '1';       //���¸�����λ��   
						}  
						open_board(mine, show, x, y);//չ��
						DisplayBoard(show, ROW, COL);//չʾ
						i--;                          //i��Ϊ0���Ժ�Ҫ�������ף���ִ����һ����ֱ��ը��
				}
				else
				{
					printf("���ź����㱻ը���ˣ�\n");
					break;
				}
			}
			else if (mine[x][y] == '0'&&show[x][y] == '*')   //ͳ����Χ�׵ĸ�������ֹһ��λ��count++����
			{
				
				win++;
				open_board(mine, show, x, y);   
				DisplayBoard(show, ROW, COL);
				if (win == row*col - Easy_Count)
				{
					printf("��ϲ�㣬���سɹ�!\n");
					break;
				}
				i--;
			}
			else
				printf("�����ظ����룬���������룺\n");
		}
		else
		{
			printf("�����������Ч�����������룡\n");
		}
	}
}