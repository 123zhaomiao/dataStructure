#include"BloomFilter.h"





void Test()
{
	BloomFilter  BloomFilter;
	STRTOINT hanshfun[5] = { HashFun1, HashFun2,HashFun3,HashFun4,HashFun5 };
	//³õÊ¼»¯
	InitBloomFilter(&BloomFilter, 100, hanshfun);
	//²åÈë
	InsertBloomFilter(&BloomFilter, "pig");
	InsertBloomFilter(&BloomFilter, "dog");
	InsertBloomFilter(&BloomFilter, "cat");
	InsertBloomFilter(&BloomFilter, "apple");
	InsertBloomFilter(&BloomFilter, "banana");
	printf("Size = %d\n", SizeBloomFilter(&BloomFilter));
	//²éÑ¯
	if (FindBloomFilter(&BloomFilter, "pig"))
	{
		printf("\"pig\" is BloomFilter!\n");
	}
	else
	{
		printf("\"pig\" not is BloomFilter!\n");
	}

	if (FindBloomFilter(&BloomFilter, "orange"))
	{
		printf("\"orange\" is BloomFilter!\n");
	}
	else
	{
		printf("\"orange\" not is BloomFilter!\n");
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}
