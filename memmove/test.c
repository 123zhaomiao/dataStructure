//任意内存的拷贝
#include<stdio.h>
#include<stdlib.h>
void *my_memmove(void * dest, const void *src, size_t count)
{
	char *ret = (char *)dest;
	if (src < dest)
	{
		////从后往前
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	else
	{
		//从前往后
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}
int main()
{
	//int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char a[] = "abcdefghi";
	int i; 
	my_memmove(a + 2, a + 3, 4);
	/*for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}*/
	printf("%s ", a);
	system("pause");
	return 0;
}
