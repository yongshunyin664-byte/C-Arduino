//#include<stdio.h>
//#include<string.h>
//
//
//int main()
//{
//	/*
//		需求：已知正确的用户名和密码，请用程序实现模拟用户登录。
//            总共给三次机会，登录之后，给出相应的提示
//	*/
//
//	// 1.定义两个变量表示正确的用户名和密码
//	char* rightUsername = "zhangsan";
//	char* rightPassword = "1234qwer";
//
//	// 2.键盘录入两个字符串，表示用户输入的用户名和密码
//	
//
//	// 3.比较
//	for (int i = 1; i <= 3; i++)
//	{
//		printf("请输入用户名\n");
//		char username[100];
//		scanf("%s", username);
//
//		printf("请输入密码\n");
//		char password[100];
//		scanf("%s", password);
//
//		printf("%s\n", username);
//		printf("%s\n", password);
//
//		if (!strcmp(username, rightUsername) && !strcmp(password, rightPassword))
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			if (i == 3)
//			{
//				printf("用户%s被锁定，请联系黑马程序员官方账号", username);
//			}
//			else
//			{
//				printf("登陆失败,还剩下%d次机会\n", 3 - i);
//			}
//		}
//	}
//	
//
//
//	
//}