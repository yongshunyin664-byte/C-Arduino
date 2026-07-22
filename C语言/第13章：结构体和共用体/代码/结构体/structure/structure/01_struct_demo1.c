//#include<stdio.h>
//#include<string.h>
//
///*
//	结构体：
//		自定义的数据类型
//		就是由很多的数据组合成的一个整体
//		每一个数据，都是结构体的成员
//	
//	书写的位置：
//		函数的里面：局部位置，只能再本函数中使用
//		函数的外面：全局位置，在所有的函数中都可以使用
//
//*/
//
//
//struct GirlFriend
//{
//	char name[100];
//	int age;
//	char gender;
//	double height;
//};
//
//
//int main()
//{
//	
//	// 使用结构体，
//	// 定义一个女朋友类型的变量
//	struct GirlFriend gf1;
//	strcpy(gf1.name, "小诗诗");
//	gf1.age = 23;
//	gf1.gender = 'F';
//	gf1.height = 1.63;
//
//	// 输出打印
//	printf("我女朋友的名字为：%s\n", gf1.name);
//	printf("我女朋友的年龄为：%d\n", gf1.age);
//	printf("我女朋友的性别为：%c\n", gf1.gender);
//	printf("我女朋友的身高为：%lf\n", gf1.height);
//
//
//	struct GirlFriend gf2;
//	strcpy(gf2.name, "小丹丹");
//	gf2.age = 24;
//	gf2.gender = 'F';
//	gf2.height = 1.62;
//
//	// 输出打印
//	printf("我女朋友的名字为：%s\n", gf2.name);
//	printf("我女朋友的年龄为：%d\n", gf2.age);
//	printf("我女朋友的性别为：%c\n", gf2.gender);
//	printf("我女朋友的身高为：%lf\n", gf2.height);
//
//
//
//	return 0;
//}
//
