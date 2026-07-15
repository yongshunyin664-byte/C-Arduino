# C语言学习清单

- [ ] 学习一维数组：定义、赋值、下标访问
- [ ] 用 for 循环遍历数组
- [ ] 了解二维数组
- [ ] 理解字符串本质：字符数组 + \0
- [ ] 学习 strlen、strcpy、strcmp
- [ ] 理解函数是什么、为什么用函数
- [ ] 学习函数定义和调用
- [ ] 学习函数参数
- [ ] 学习函数返回值 return
- [ ] 学习函数声明
- [ ] 区分局部变量和全局变量

## 1. 一维数组

数组是**相同类型**数据的集合，在内存中**连续存放**，通过下标访问。

```c
int arr[5] = {10, 20, 30, 40, 50};  // 定义并初始化
arr[0] = 100;                        // 下标从 0 开始，修改第一个元素
int x = arr[2];                      // 访问第三个元素，x = 30
```

- `int arr[5]`：定义 5 个 int 元素的数组
- 下标范围：`0` ~ `4`（共 5 个）
- ⚠ 下标越界不会报错，但会破坏其他数据，是常见 bug

## 2. for 循环遍历数组

用 for 循环配合下标遍历数组是最常用的模式。

```c
int arr[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```

## 3. 二维数组

二维数组可以理解为一个**表格**，有行和列。

```c
int matrix[2][3] = {            // 2 行 3 列
    {1, 2, 3},                  // 第 0 行
    {4, 5, 6}                   // 第 1 行
};
int val = matrix[1][2];         // 第 1 行第 2 列 → 6

// 双重 for 循环遍历
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```

- 内存中按行存放：第 0 行 → 第 1 行，依次连续

## 4. 字符串：字符数组 + \0

C 语言没有专门的字符串类型，字符串本质上是**字符数组**，以 `'\0'`（空字符）结尾。

```c
char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};   // 手动写法
char str2[] = "Hello";                               // 等价简写，编译器自动加 \0
```

- `\0` 是字符串结束标志，printf 遇到 `\0` 就停止输出
- 数组长度至少比字符串长度多 1（留给 `\0`）
- 没有 `\0` 会导致越界读取，输出乱码

## 5. strlen、strcpy、strcmp

这三个函数在 `<string.h>` 中定义，用于操作字符串。

```c
#include <string.h>

char s1[] = "Hello";
char s2[20];

int len = strlen(s1);               // 获取字符串长度（不含 \0），返回 5

strcpy(s2, s1);                     // 将 s1 复制到 s2（s2 要足够大）
                                    // 等价于：s2 = "Hello"

int result = strcmp(s1, s2);        // 比较两个字符串
                                    // 相等返回 0，s1<s2 返回负数，s1>s2 返回正数
```

- `strlen()` 计算的是字符个数，不包含 `\0`
- `strcpy()` 不会检查目标数组大小，容易溢出（可用 `strncpy`）
- `strcmp()` 按字典序逐字符比较
- ⚠ 不能用 `==` 比较字符串（那是比较地址）

## 6. 函数是什么、为什么用函数

**函数**是一段有名字的代码块，可以反复调用。

**为什么用函数：**
- 避免重复代码（DRY 原则）
- 代码分块，逻辑清晰，便于维护
- 便于多人协作，各写各的函数

```c
// 没有函数：重复代码
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");

// 有了函数：调用即可
void sayHello() {
    printf("Hello\n");
}
sayHello();
sayHello();
sayHello();
```

## 7. 函数定义和调用

```c
#include <stdio.h>

// 函数定义：告诉编译器这个函数做什么
void greet() {                      // void 表示无返回值
    printf("Hello, Arduino!\n");
}

int main() {
    greet();                        // 函数调用：执行 greet 函数
    greet();                        // 可以反复调用
    return 0;
}
```

## 8. 函数参数

参数让函数可以接收外部数据，更灵活。

```c
void blink(int times, int delayMs) {        // 两个参数：次数 和 间隔毫秒
    for (int i = 0; i < times; i++) {
        printf("LED ON\n");
        // delay(delayMs);                  // Arduino 中用 delay()
        printf("LED OFF\n");
    }
}

int main() {
    blink(3, 500);   // 闪烁 3 次，间隔 500ms
    blink(5, 200);   // 闪烁 5 次，间隔 200ms
    return 0;
}
```

- 形参（times, delayMs）：定义时的变量名
- 实参（3, 500）：调用时传入的具体值

## 9. 函数返回值 return

函数可以**返回计算结果**给调用者。

```c
int add(int a, int b) {             // int 表示返回值类型
    return a + b;                   // return 结束函数，返回后面的值
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int sum = add(3, 5);            // sum = 8
    int big = max(10, 20);          // big = 20
    printf("sum=%d, max=%d\n", sum, big);
    return 0;
}
```

- 返回类型写在函数名前（int、float、void 等）
- `return` 会立即结束函数，后面的代码不会执行
- 返回类型与 return 的值类型要匹配

## 10. 函数声明

如果函数定义在调用之后，需要**先声明**（告诉编译器有这个函数）。

```c
#include <stdio.h>

// 函数声明（函数原型）：只写头部，以分号结尾
int add(int a, int b);
void greet();

int main() {
    int result = add(3, 5);         // 现在可以调用了
    greet();
    return 0;
}

// 函数定义（完整实现）：放在后面
int add(int a, int b) {
    return a + b;
}

void greet() {
    printf("Hello\n");
}
```

- 声明 = 返回值类型 + 函数名 + 参数列表 + `;`
- 定义 = 声明 + 函数体 `{...}`
- Arduino 的 `setup()` 和 `loop()` 调用的是库内部声明好的函数

## 11. 局部变量和全局变量

```c
int globalVar = 100;                // 全局变量：在所有函数外面定义
                                    // 整个文件的所有函数都能访问

void test() {
    int localVar = 10;              // 局部变量：在函数内部定义
                                    // 只有这个函数能访问，函数结束自动销毁
    printf("global=%d, local=%d\n", globalVar, localVar);
}

void another() {
    printf("global=%d\n", globalVar);   // ✓ 可以访问
    // printf("%d\n", localVar);        // ✗ 报错：不认识 localVar
}

int main() {
    test();
    another();
    return 0;
}
```

| 对比 | 全局变量 | 局部变量 |
|------|---------|---------|
| 定义位置 | 所有函数外面 | 函数内部 |
| 作用范围 | 整个文件 | 当前函数 |
| 生命周期 | 程序运行全程 | 函数执行期间 |
| 初始值 | 自动初始化为 0 | 不确定（垃圾值） |
