#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct spot
{
	char name[100];
	int count;
};


int main()
{
	/*
		某班级组织野外郊游，想要在ABCD四个景点选择其中一个。
		现在班上有80名同学进行投票，找出投票数最多的景点

		Ps：
			1，学生投票，用随机数模拟
			2，如果多个景点投票一样的话，A优先B，B优先于C，C优先于D
	*/
	
	// 1.定义数组存储4个spot类型的变量
	struct spot arr[4] = { {"A", 0}, {"B", 0}, {"C", 0}, {"D", 0} };

	// 2.模拟80名同学的投票
	srand(time(NULL));

	for (int i = 0; i < 80; i++)
	{
		// choose 变量有两个含义
		// 含义一：表示用户的投票 0 A    1 B    2 C    3  D
		// 含义二：表示arr中的索引，通过这个索引就可以获取到景点的名字和投票数量
		int choose = rand() % 4; // 0 1 2 3 


		// choose:表示同学的投票，同时也表示数组中的索引
		// arr[choose]：表示获取景点的信息（名字，数量）
		// arr[choose].count：表示这个景点已经投了多少票
		// arr[choose].count++：给这个景点再投一票
		arr[choose].count++;
	}

	// 找最大值
	int max = arr[0].count;
	for (int i = 1; i < 4; i++)
	{
		struct spot temp = arr[i];
		if (temp.count > max)
		{
			max = temp.count;
		}
	}

	// 遍历数组，看谁的票数刚好是最大值
	for (int i = 0; i < 4; i++)
	{
		struct spot temp = arr[i];
		if (temp.count == max)
		{
			printf("投票最多的景点为：%s，共计： %d张票\n", temp.name, temp.count);
			break;
		}
	}
	

	// 遍历
	for (int i = 0; i < 4; i++)
	{
		struct spot temp = arr[i];
		printf("%s %d\n", temp.name, temp.count);
	}




	return 0;
}