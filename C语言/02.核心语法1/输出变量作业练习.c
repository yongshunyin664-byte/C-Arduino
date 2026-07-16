#include <stdio.h>

int main(){
    int math_score = 140;
    int english_score = 140;
    int chinese_score = 140;
    int total_score;
    printf("数学成绩：%d\n", math_score);
    printf("英语成绩：%d\n", english_score);
    printf("语文成绩：%d\n", chinese_score);
    printf("总成绩：%d\n", total_score = math_score + english_score + chinese_score);
    return 0;
}