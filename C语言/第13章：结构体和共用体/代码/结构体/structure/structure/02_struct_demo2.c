//#include<stdio.h>
//
//
//struct Student
//{
//	char name[100];
//	int age;
//};
//
//
//int main()
//{
//	// 1.定义三个学生， 同时并进行赋值
//	struct Student stu1 = { "zhangsan",23 };
//	struct Student stu2 = { "lisi",24 };
//	struct Student stu3 = { "wangwu",25 };
//
//	// 2.把三个学生放入到数组当中
//	struct Student stuArr[3] = { stu1 ,stu2, stu3};
//
//	// 3.遍历数组得到每一个元素
//	for (int i = 0; i < 3; i++)
//	{
//		struct Student temp = stuArr[i];
//		printf("学生的信息为：姓名%s, 年龄%d\n", temp.name,temp.age);
//	}
//
//
//
//
//
//	return 0;
//}