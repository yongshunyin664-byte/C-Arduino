//#include <stdio.h>  
//
//int main() {
//
//    /*
//         打开文件：fopen
//
//         读取数据：fgetc 一次读一个字符，读不到返回-1
//                  fgets 一次读一行，读不到返回null
//                  fread 一次读多个
//
//         关闭文件：fclose
//
//        C:\\Users\\1\\Desktop\\a.txt
//
//    */
//
//    // 1.打开文件：fopen
//    FILE* file = fopen("C:\\Users\\1\\Desktop\\a.txt", "r");
//
//    // 2.读取数据
//    // fgets 细节：
//    //  每次读取一行数据，以换行符为准
//    //  如果读不到了，返回null
//    char arr[1024];
//    char* str;
//    while ((str = fgets(arr, 1024, file)) != NULL)
//    {
//        printf("%s", str);
//    }
//
//    // 3.关闭文件
//    fclose(file);
//
//
//
//    return 0;
//}
