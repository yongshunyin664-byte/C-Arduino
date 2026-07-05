# C语言 printf 格式输出笔记

## 1. printf 是什么
- printf 用来把内容输出到屏幕上。
- 它的作用类似“打印”。

## 2. printf 的基本写法
```c
printf("要输出的内容");
```

## 3. %d 的意思
- `%d` 表示输出一个整数。
- 例如：

```c
int age = 18;
printf("%d\n", age);
```

输出结果：
```c
18
```

## 4. `\n` 的意思
- `\n` 表示换行。
- 也就是说，输出完后会自动到下一行。

## 5. 常见格式符号
- `%d`：整数
- `%f`：浮点数
- `%lf`：double 类型的小数
- `%c`：字符

## 6. 一个简单例子
```c
#include <stdio.h>

int main(void)
{
    int a = 10;
    float b = 3.14f;
    double c = 3.1415926;
    char d = 'C';

    printf("%d\n", a);
    printf("%f\n", b);
    printf("%lf\n", c);
    printf("%c\n", d);

    return 0;
}
```

## 7. 记忆口诀
- `%d` 记整数
- `%f` / `%lf` 记小数
- `%c` 记字符
- `\n` 记换行
