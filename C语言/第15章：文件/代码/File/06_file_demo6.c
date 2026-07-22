//#include <stdio.h>  
//
//int main() {
//
//    /*
//         打开文件：fopen
//
//         写出数据：fputc 一次写一个字符，返回写出的字符
//                  fputs 一次写一个字符串，写出成功返回非负数，一般忽略返回值
//                  fwrite 一次读多个，返回写出的个数
//
//         关闭文件：fclose
//
//        C:\\Users\\1\\Desktop\\a.txt
//    */
//
//    // 1.打开文件
//    FILE* file = fopen("C:\\Users\\1\\Desktop\\a.txt", "w");
//
//    // 2.写出数据
//    //fputc 一次写一个字符，返回写出的字符
//    // a --- 97
//    int c = fputc(97, file);
//    printf("%c\n", c);
//
//    //fputs 一次写一个字符串，写出成功返回非负数，一般忽略返回值
//    //细节：因为如果写出失败，那么就会有一个EOF的错误
//    int n = fputs("你好你好", file);
//    printf("%d\n", n);
//
//    //fwrite 一次读多个，返回写出的字节个数
//    char arr[] = {97, 98 , 99 , 100 , 101};
//    int n2 = fwrite(arr, 1, 5, file);
//    printf("%d\n", n2);
//
//    // 3.关闭文件
//    fclose(file);
//
//
//    return 0;
//}