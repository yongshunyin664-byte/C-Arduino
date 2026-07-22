//#include<stdio.h>
//
//void fun();
//int sum(int num1, int num2);
//
//
//int main()
//{
//	/*
//		函数的注意事项：
//			1. 函数不调用就不执行
//			2. 函数名不能重复
//			3. 函数与函数之间是平级关系，不能嵌套定义
//			4. 自定义函数写在main函数的下面，需要在上方申明
//			5. return下面，不能编写代码，永远执行不到，属于无效的代码
//			6. 函数的返回值类型为void，表示没有返回值，return可以省略不写
//				如果书写了return，后面不能跟具体的数据，仅表示结束函数
//	*/
//	
//	fun();
//	int result = sum(10, 20);
//	printf("%d\n", result);
//	
//	
//	return 0;
//}
//
//
//void fun()
//{
//	printf("fun函数执行了");
//
//	for (int i = 1; i <= 10; i++)
//	{
//		if (i == 3) 
//		{
//			return;//结束函数
//		}
//		printf("%d\n", i);
//	}
//}
//
//int sum(int num1, int num2)
//{
//	printf("sum函数执行了");
//
//	int sum = num1 + num2;
//	return sum;
//}
