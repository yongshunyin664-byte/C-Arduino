//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//
//int main()
//{
//
//	/*
//		需求：生成10个1~100之间的随机数存入数组
//		1）求出所有数据的和
//	*/
//
//	// 1. 定义数组
//	int arr[10] = {0};
//	int len = sizeof(arr) / sizeof(int);
//
//	// 2.生成10个1~100之间的随机数存入数组
//	// 设置种子
//	srand(time(NULL));
//	// 生成随机数
//	for (int i = 0; i < len; i++)
//	{
//		int num = rand() % 100 + 1;
//		// 把随机数存入到数组
//		arr[i] = num;
//	}
//
//	// 3.利用累加思想求数组中所有数据的和
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		sum = sum + arr[i];
//	}
//
//	// 4.输出
//	printf("%d\n", sum);
//
//
//	return 0;
//}