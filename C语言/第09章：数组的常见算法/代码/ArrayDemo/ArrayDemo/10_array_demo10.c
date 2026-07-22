//#include<stdio.h>
//void printArr(int arr[], int len);
//
//int main()
//{
//	/*
//		需求：键盘录入5个数据并存入数组，完成以下需求
//			1）遍历数组
//			2）反转数组
//			3）再次遍历
//	*/
//
//	// 1.定义数组
//	int arr[5] = {0};
//	int len = sizeof(arr) / sizeof(int);
//
//	// 2.键盘录入数据
//	for (int i = 0; i < len; i++)
//	{
//		printf("请录入第%d个元素\n", i + 1);
//		scanf("%d", &arr[i]);
//	}
//
//	// 3.遍历数组
//	printArr(arr,len);
//
//	// 4.反转数组
//	int i = 0;
//	int j = len - 1;
//	while (i < j)
//	{
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//
//		i++;
//		j--;
//	}
//
//	// 5.遍历数组
//	printArr(arr, len);
//
//	return 0;
//}
//
//
//void printArr(int arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}