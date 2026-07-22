//#include<stdio.h>
//
//int order(int arr[], int len, int num);
//
//int main()
//{
//	/*
//		需求：数组的基本查找/顺序查找
//		核心思路：就是从数组的0索引开始，依次往后查找
//				如果找到了，就会返回数据对应的索引
//				如果没有找到，就会返回-1
//	*/
//
//	// 1.定义数组
//	int arr[] = {11,22,55,77,44};
//	int len = sizeof(arr) / sizeof(int);
//
//	// 2.定义一个变量表示要查找的数据
//	int num = 33;
//	
//	// 3.调用函数查找数据
//	int index = order(arr,len, num);
//
//	// 4.输出索引
//	printf("%d\n", index);
//
//	return 0;
//}
//
//
//// 作用：查找数组中的数据
//// 返回值：数据所在的索引
//int order(int arr[], int len, int num)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == num)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
