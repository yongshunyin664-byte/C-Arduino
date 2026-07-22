//#include<stdio.h>
//
//
//
//typedef struct 
//{
//	char name[100];
//	int attack;
//	int defense;
//	int blood;
//} M;
//
//
//int main()
//{
//	/*
//		定义一个结构体表示游戏人物
//			属性有：姓名、攻击力、防御力、血量
//			要求：把三个游戏人物放入到数组当中，并遍历数组
//	*/
//
//	// 1.定义三个奥特曼
//	M taro = {"泰罗", 100, 90, 500};
//	M rem = {" 雷欧", 90, 80, 450};
//	M eddie = {"艾迪", 120, 70, 600};
//
//	// 2.定义数组
//	M arr[3] = { taro,rem,eddie };
//
//	// 3.遍历数组
//	for (int i = 0; i < 3; i++)
//	{
//		M temp = arr[i];
//		printf("奥特曼的名字为%s, 攻击力是%d, 防御力是%d, 血量是%d\n", temp.name, temp.attack, temp.defense, temp.blood);
//	}
//	
//
//
//
//	return 0;
//}