//#include<stdio.h>
//
//void printArr(int arr[], int len);
//
//int main()
//{
//	/*
//		1. 数组作为函数的参数，要注意什么？
//			实际上传递是数组的首地址，如果要在函数中对数组进行遍历的话，记得一定要把数组的长度一起传递过去
//			定义处：arr表示的就是完整的数组
//			函数中的arr：只是一个变量，用来记录数组的首地址
//			
//	
//		2. 数组的索引越界
//			最小索引：0
//			最大索引：长度 - 1
//
//	*/
//	
//	// 1. 定义数组
//	int arr[] = {1,2,3,4,5};
//	//printf("%zu\n", sizeof(arr));
//
//	//int len = sizeof(arr) / sizeof(int);
//
//
//	// 2. 调用函数遍历数组
//	//printArr(arr, len);
//
//	printf("%d\n", arr[10]);
//	
//
//	return 0;
//}
//
//void printArr(int arr[], int len)
//{
//	//printf("%zu\n", sizeof(arr));//8 64位的操作系统当中，是以64个二进制表示内存地址值
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d\n",arr[i]);
//	}
//}
//
//
//
