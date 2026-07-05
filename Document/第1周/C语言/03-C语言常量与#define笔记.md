# C语言常量与 #define 笔记

## 1. 什么是常量
- 常量就是“值不变”的量。
- 例如：
  - 10
  - 3.14
  - 'A'

## 2. 什么是 #define
- `#define` 用来定义一个常量的名称。
- 它的作用是：给一个固定值起一个名字。

## 3. 基本写法
```c
#include <stdio.h>

#define PI 3.14

int main(void)
{
    printf("%f\n", PI);
    return 0;
}
```

## 4. 它的作用
- 让代码更容易看懂
- 以后修改值时，只需要改一处

## 5. 例子：定义最大值
```c
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a = MAX;
    printf("%d\n", a);
    return 0;
}
```

## 6. 记忆口诀
- 常量：值不变
- `#define`：给常量起名字
- `MAX`、`PI` 这类名字，表示固定值
