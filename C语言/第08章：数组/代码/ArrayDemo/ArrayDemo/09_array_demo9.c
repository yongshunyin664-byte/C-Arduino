//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//int contains(int arr[], int len, int num);
//
//int main()
//{
//
//	/*
//		需求：生成10个1~100之间的随机数存入数组，要求数据不能重复
//		1）求出所有数据的和
//		2）求所有数据的平均数
//		3）统计有多少个数据比平均值小
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
//
//	for (int i = 0; i < len; )
//	{
//		int num = rand() % 10 + 1;
//		// 存入之前，先做一个判断，如果不存在，再进行添加
//		int flag = contains(arr, len, num);
//		if (!flag)
//		{
//			arr[i] = num;
//			i++;
//		}
//	}
//
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//
//	
//	// 3.利用累加思想求数组中所有数据的和
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		sum = sum + arr[i];
//	}
//
//	// 4.求平均数
//	int avg = sum / len;
//
//	// 5.统计有多少个数字比平均数要小
//	int count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] < avg)
//		{
//			count++;
//		}
//	}
//
//	// 6.输出
//	printf("平均数为:%d\n", avg);
//	printf("%d\n" , count);
//
//
//	
//
//	return 0;
//}
//
//// 判断num在函数当中，是否存在
//// 存在，返回1
//// 不存在，返回0
//int contains(int arr[], int len, int num)
//{
//	for (int i = 0; i < len; i++)
//	{
//		// i：依次表示数组里面的每一个索引
//		// arr[i]:依次表示数组里面的每一个数据
//		if (arr[i] == num)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}