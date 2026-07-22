//#include<stdio.h>
//#include<string.h>
//
//typedef union MoneyType
//{
//	int moneyi;
//	double moneyd;
//	char moneystr[100];
//} MT;
//
//
//
//int main()
//{
//	/*
//		需求：
//			金融项目中，钱有可能是整数，小数，字符串，请定义对应的共同体
//		
//	*/
//
//	// 1.利用共同体定义钱的变量
//	//union MoneyType money;
//	MT money;
//
//	// 2.赋值
//	// 整数moneyi、小数moneyd、字符串moneystr
//	// 而且每次只能赋一个值
//	//money.moneyi = 99999;
//	//money.moneyd = 123.32;
//	strcpy(money.moneystr, "100万");
//
//
//	// 3.输出打印
//	// 上面赋值给哪个类型，下面就从哪个类型取出来
//	//printf("%d\n", money.moneyi);
//	//printf("%lf\n", money.moneyd);
//	printf("%s\n", money.moneystr);
//
//
//	return 0;
//}