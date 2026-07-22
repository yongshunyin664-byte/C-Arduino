//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//
//	/*
//		生成1-100之间的随机数
//		使用键盘录入去猜，猜中为止
//			
//	*/
//
//
//	// 1.生成1-100之间的随机数
//	srand(time(NULL));
//
//	int number = rand() % 100 + 1; 
//
//
//	// 2.利用循环 + 键盘录入去猜
//	// 随机数：50
//	// 键盘录入：50 中了 程序停止
//	//		    40 小了
//	//			60 大了
//	
//	// 猜的数字
//	int guess;
//	
//	while (1)
//	{
//		printf("请输入您要猜的数字：\n");
//		scanf("%d", &guess);
//
//		// 拿着guess跟随机数进行比较
//		if (guess < number)
//		{
//			printf("小了\n");
//		}
//		else if (guess > number)
//		{
//			printf("大了\n");
//		}
//		else
//		{
//			printf("中了\n");
//			break;
//		}
//	}
//
//	
//	
//
//
//
//	return 0;
//}
