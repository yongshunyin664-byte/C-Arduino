//#include<stdio.h>
//
//void getMaxAndMin(int arr[], int len, int* max, int* min);
//
//int main()
//{
//	/*
//		指针的作用二：
//			函数返回多个值
//		练习：
//			定义一个函数，求数组的最大值和最小值，并进行返回
//	*/
//
//	// 1.定义数组
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int len = sizeof(arr) / sizeof(int);
//
//	// 2.调用getMaxAndMin函数求最大值和最小值
//	int max = arr[0];
//	int min = arr[0];
//
//
//	getMaxAndMin(arr, len, &max, &min);
//
//	printf("数组的最大值为：%d\n", max);
//	printf("数组的最小值为：%d\n", min);
//
//
//	return 0;
//}
//
//void getMaxAndMin(int arr[], int len, int* max, int* min)
//{
//	// 求数组的最大值
//	*max = arr[0];
//
//	for (int i = 1; i < len; i++)
//	{
//		if (arr[i] > *max)
//		{
//			*max = arr[i];
//		}
//	}
//
//	// 求数组的最小值
//	*min = arr[0];
//	for (int i = 1; i < len; i++)
//	{
//		if (arr[i] < *min)
//		{
//			*min = arr[i];
//		}
//	}
//}
