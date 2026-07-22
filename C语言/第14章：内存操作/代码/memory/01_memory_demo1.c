//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	/*
//		malloc	申请空间（连续）		  掌握
//		calloc	申请空间 + 数据初始化   了解
//		realloc	修改空间大小			  了解
//		free	释放空间               掌握
//
//		stdlib.h
//	*/
//
//	// 1.利用malloc函数申请一片连续的空间
//	// 需求：申请一片空间，要存储10个int类型的整数
//	// 返回这片空间的首地址
//	int* p = malloc(10 * sizeof(int)); 
//	//int* p = calloc(10, sizeof(int));
//
//	//printf("%p\n", p);
//
//	//// 2.赋值
//	for (int i = 0; i < 10; i++)
//	{
//		// 第一种赋值
//		//*(p + i) = (i + 1) * 10; //10 20 30 40 50 60 70 80 90 100
//		// 第二种赋值
//		p[i] = (i + 1) * 10;
//		//p[i] --->   p + i
//	}
//
//
//	// 4.扩容，20个int类型的整数
//	int* pp = realloc(p, 20 * sizeof(int));
//
//	// 3.遍历
//	for (int i = 0; i < 20; i++)
//	{
//		//printf("%d ", *(p + i));
//		printf("%d ", p[i]);
//	}
//
//	// 5.释放空间
//	// 如果申请的空间不需要再进行使用了，那么记得一定要释放
//	free(pp);
//
//
//
//	return 0;
//}
//
//
