//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	/*
//		malloc	申请空间（连续）		  掌握
//		free	释放空间               掌握
//
//		calloc	申请空间 + 数据初始化   了解
//		realloc	修改空间大小			  了解
//
//		7，free释放完空间之后，空间中数据叫做脏数据，可能被清空，可能被修改为其他值
//		8，calloc就是在malloc的基础上多一个初始化的动作
//	*/
//
//	// 1.申请一片连续的空间存储10个int类型的整数
//	int* p = malloc(10 * sizeof(int));
//	int size = 10;
//
//	// 2.给这片空间赋值
//	for (int i = 0; i < size; i++)
//	{
//		*(p + i) = (i + 1) * 10;
//	}
//
//	// 10 20 30 .... 100
//
//	// 3.遍历
//	printf("遍历空间中的数据为：\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//	// 4.释放空间
//	free(p);
//
//	// 5.释放之后再次遍历
//	printf("释放之后再次遍历数据为：\n");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//
//
//
//
//
//
//
//	return 0;
//}
