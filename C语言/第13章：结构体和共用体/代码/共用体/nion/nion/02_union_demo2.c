#include<stdio.h>


union MoneyType
{
	int moneyi; 
	double moneyd;   
	char moneystr[100];
};   

int main()
{
	/*
		共用体的特点：
			1. 共用体，也叫联合体，共同体
			2. 所有的变量都使用同一个内存空间
			3. 每次只能给一个变量进行赋值，因为第二次赋值时会覆盖原有的数据
				细节：怎么存的，怎么取出来
			4. 所占的内存大小 = 最大成员的长度（也受内存对齐影响）
				细节：以最大的单个成员的长度为准
					  总大小一定是最大单个成员的整数倍
	*/

	// 1.利用共同体定义钱的变量
	union MoneyType money;


	// 2.获取内存地址
	//printf("%p\n", &(money.moneyi));
	//printf("%p\n", &(money.moneyd));
	//printf("%p\n", &(money.moneystr));
	//
	//printf("%zu\n", sizeof(money.moneyi));// 4
	//printf("%zu\n", sizeof(money.moneyd));// 8
	//printf("%zu\n", sizeof(money.moneystr));// 100
	//printf("%zu\n", sizeof(money));// 104 （后面会补4个空白字节）


	money.moneyi = 99;
	money.moneyd = 1.23;
	printf("%lf\n", money.moneyd);
	



	return 0;
}