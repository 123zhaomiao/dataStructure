//memcpy内存拷贝(仅仅实现不相关的内存拷贝)
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void *my_memcpy(void *dest, const void *src, size_t count)
{
	char *ret= (char *)dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char *)dest + 1;
		src = (char *)src + 1;
	}
	return ret;
}
int main()
{
	int a[10];
	int b[6] = {1,2,3};
	int i = 0;
	my_memcpy(a, b, 12);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}