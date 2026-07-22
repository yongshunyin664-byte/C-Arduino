//#include<stdio.h>
//
//void swap(int* p1, int* p2);
//
//int main()
//{
//	/*
//		定义两个变量，要求交换变量中记录的值
//		注意：交换的代码写在一个新的函数swap中
//	*/
//
//	// 1.定义两个变量
//	int a = 10;
//	int b = 20;
//
//	// 2.调用swap函数
//	printf("调用前：%d，%d", a, b);
//	swap(&a, &b);
//	printf("调用后：%d，%d", a, b);
//
//	return 0;
//}
//
//void swap(int* p1 , int* p2)
//{
//	// 此时交换的是p1指向的变量和p2指向的变量的值
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//
