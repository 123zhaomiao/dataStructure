#include"BitMap.h"

void Test()
{
	BitMap bit;
	//³õÊ¼»¯±ÈÌØÎ»
	InitBitMap(&bit,100);
	//ÖÃ1
	SetBitMap(&bit, 9);
	SetBitMap(&bit, 32);
	SetBitMap(&bit, 22);
	SetBitMap(&bit, 89);
	SetBitMap(&bit, 78);
	SetBitMap(&bit, 99);
	if (TestSetMap(&bit, 32))
	{
		printf("32 bit is 1\n");
	}
	else
	{
		printf("32 bit is 0\n");
	}

	//ÖÃ0
	ResetBitMap(&bit, 32);
	ResetBitMap(&bit, 22);
	ResetBitMap(&bit, 12);
    printf("Size=%d\n", SizeBitMap(&bit));
	if (TestSetMap(&bit,32))
	{
		printf("32 bit is 1\n");
	}
	else
	{
		printf("32 bit is 0\n");
	}

}

int main()
{
	Test();
	system("pause");
	return 0;
}
