//#include<stdio.h>
//
//int getRemainder(int num1, int num2, int* res);
//
//int main()
//{
//	/*
//		
//		作用3：函数的结果和计算状态分开
//		练习：定义一个函数，将两数相除，获取他们的余数
//	
//	*/
//
//		
//	// 1.定义两个变量
//	int a = 10;
//	int b = 0;
//	int res = 0;
//
//	// 2.调用函数获取余数
//	int flag = getRemainder(a, b, &res);
//
//	// 3.对状态进行判断
//	if (!flag)
//	{
//		printf("获取到的余数为：%d\n", res);
//	}
//
//	return 0;
//}
//
//// 返回值：表示计算的状态 0 正常 1 不正常
//int getRemainder(int num1, int num2, int* res)
//{
//	if (num2 == 0)
//	{
//		// 停止
//		return 1;
//	}
//	*res = num1 % num2;
//	return 0;
//}
//
//
//
