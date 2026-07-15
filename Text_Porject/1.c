#include <stdio.h>
int main() {
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};   // 手动写法
    char str2[7] = "Hello";  
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    return 0;
}