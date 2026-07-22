//#include<stdio.h>
//
//int main()
//{
//
//	/*
//		练习：利用指针遍历数组
//	*/
//
//	// 1.定义数组
//	int arr[] = {10,20,30,40,50};
//	int len = sizeof(arr) / sizeof(int);
//
//	// 2.获取数组的指针
//	// 实际上获取的：数组的首地址
//	int* p1 = arr;
//	//int* p2 = &arr[0];
//		
//	// 3.利用循环和指针遍历数组获取里面的每一个元素
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d\n", *p1++);
//	}
//
//
//
//	return 0;
//}