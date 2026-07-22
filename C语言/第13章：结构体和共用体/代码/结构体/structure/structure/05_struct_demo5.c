//#include<stdio.h>
//#include<string.h>
//
//struct Message
//{
//	char phone[12];
//	char mail[100];
//};
//
//struct Student
//{
//	char name[100];
//	int age;
//	char gender;
//	double height;
//	struct Message msg;
//};
//
//
//
//int main()
//{
//	/*
//		定义一个结构体表示学生Student
//		Student成员如下：
//		名字、年龄、性别、身高、联系方式
//		
//		联系方式Message也是一个结构体，成员如下：
//		手机号、电子邮箱
//	*/
//
//	// 1. 定义学生类型的变量
//	struct Student stu;
//
//	// 2.给里面的每一个成员进行赋值
//	strcpy(stu.name, "zhangsan");
//	stu.age = 23;
//	stu.gender = 'M';
//	stu.height = 1.78;
//
//	strcpy(stu.msg.phone, "13112345678");
//	strcpy(stu.msg.mail, "12345678@qq.com");
//
//	// 3.输出打印
//	printf("学生的信息为：\n");
//	printf("姓名为：%s\n", stu.name);
//	printf("年龄为：%d\n", stu.age);
//	printf("性别为：%c\n", stu.gender);
//	printf("身高为：%lf\n", stu.height);
//
//	printf("手机号为：%s\n", stu.msg.phone);
//	printf("邮箱为：%s\n", stu.msg.mail);
//
//
//	printf("---------------------------\n");
//
//	// 批量进行赋值
//	struct Student stu2 = { "lisi", 24, 'F', 1.65, {"13112347890","5678@qq.com"}};
//
//	// 3.输出打印
//	printf("学生的信息为：\n");
//	printf("姓名为：%s\n", stu2.name);
//	printf("年龄为：%d\n", stu2.age);
//	printf("性别为：%c\n", stu2.gender);
//	printf("身高为：%lf\n", stu2.height);
//
//	printf("手机号为：%s\n", stu2.msg.phone);
//	printf("邮箱为：%s\n", stu2.msg.mail);
//
//
//
//
//	return 0;
//}