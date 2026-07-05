# C语言 scanf 输入笔记

## 1. scanf 是什么
- scanf 用来从键盘读取输入。
- 它和 printf 相反：
  - printf：输出
  - scanf：输入

## 2. 基本用法
```c
#include <stdio.h>

int main(void)
{
    int age;
    scanf("%d", &age);
    printf("%d\n", age);
    return 0;
}
```

## 3. 它从哪里读取
- scanf 读取的是键盘输入。
- 也就是说，你在运行程序时，在控制台里输入的内容，会被 scanf 读取。
- 比如这段

```c
int age;
scanf("%d", &age);
```
- 意思是：
- 程序会等待你在键盘上输入一个整数
- 输入完成后，这个整数就会被存到 age 里面
- 例如你在运行程序时输入：

```c
18
```

- 那么 age 就等于 18。
- 可以把它理解成：
- printf 是“把东西输出出去”
- scanf 是“从外面接收输入”

## 4. 常见格式符号
- `%d`：读取整数
- `%f`：读取小数
- `%c`：读取字符

## 5. 记住一个重点
- 读取数据时，通常要写 `&变量名`。
- 例如：`scanf("%d", &age);`

## 6. 记忆口诀
- scanf 读输入
- printf 打输出
- `%d` 读整数
- `%f` 读小数
- `%c` 读字符
