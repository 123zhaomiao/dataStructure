

#include"quickSort.h"


void TestquickSort()
{
	int array[] = {2,5,4,9,3,6,8,7,1,0};
	int *temp = (int *)malloc(sizeof(array) / sizeof(array[0])*sizeof(int));
	if (temp == NULL)
	{
		return;
	}
	//��ӡ
	printf("����ǰ: ");
	Print(array, sizeof(array) / sizeof(array[0]));
	//��������1
	//quickSort(array,0, sizeof(array) / sizeof(array[0]));
	//quickSortNor(array, sizeof(array) / sizeof(array[0]));
	memcpy(temp, array, sizeof(array) / sizeof(array[0])*sizeof(int));

	//Merge_sort(array, 0, sizeof(array) / sizeof(array[0])-1, temp);
	Merge_sortNor(array, sizeof(array) / sizeof(array[0]) - 1, temp);
	printf("�����: ");
	Print(array, sizeof(array) / sizeof(array[0]));

}
int main()
{
	TestquickSort();
	system("pause");
	return 0;
}