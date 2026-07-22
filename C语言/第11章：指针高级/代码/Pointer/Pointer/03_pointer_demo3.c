//#include<stdio.h>
//
//
//int* method();
//
//int main()
//{
//   // 调用method函数，并使用该函数中的变量a
//    int*p = method();
//
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//    printf("拖点时间\n");
//
//    printf("%d\n", *p);// 不能打印的，因为method函数结束之后，那么该函数里面所有的变量也会随之消失
//
//     return 0;
//}
//
//
//int* method()
//{
//    static int a = 10;// 此时变量一直保存到程序结束
//    return &a;
//}
//
//
//
