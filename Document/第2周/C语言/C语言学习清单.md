# C语言学习清单

- [ ] 学习关系运算符 `> < >= <= == !=`
- [ ] 学习逻辑运算符 `&& || !`
- [ ] 学习 `if` 单分支判断
- [ ] 学习 `if...else` 双分支
- [ ] 学习 `if...else if...else` 多分支
- [ ] 学习 `switch...case`
- [ ] 学习 `while` 循环
- [ ] 学习 `do...while` 循环
- [ ] 学习 `for` 循环
- [ ] 学习 `break` 和 `continue`
- [ ] 学习循环嵌套

## 1. 关系运算符

关系运算符用于比较两个值，结果为 `0`（假）或 `1`（真）。

- `>` 大于
- `<` 小于
- `>=` 大于等于
- `<=` 小于等于
- `==` 等于
- `!=` 不等于

示例：

```c
int a = 5, b = 3;
int equal = (a == b);      // 0
int greater = (a > b);     // 1
int notEqual = (a != b);   // 1
```

## 2. 逻辑运算符

逻辑运算符用于组合布尔条件。

- `&&` 逻辑与：两个条件都为真时才为真
- `||` 逻辑或：任一条件为真时为真
- `!` 逻辑非：取反

示例：

```c
int x = 10;
int result = (x > 0 && x < 20); // 1
int result2 = (x < 0 || x > 5); // 1
int result3 = !(x == 10);       // 0
```

## 3. if 单分支判断

`if` 用于在条件满足时执行一段代码。

```c
int score = 75;
if (score >= 60) {
    printf("及格\n");
}
```

## 4. if...else 双分支

`if...else` 在条件为真时执行一段代码，否则执行另一段。

```c
int score = 55;
if (score >= 60) {
    printf("及格\n");
} else {
    printf("不及格\n");
}
```

## 5. if...else if...else 多分支

多分支可处理多个条件。

```c
int score = 85;
if (score >= 90) {
    printf("优秀\n");
} else if (score >= 75) {
    printf("良好\n");
} else if (score >= 60) {
    printf("及格\n");
} else {
    printf("不及格\n");
}
```

## 6. switch...case

`swtich` 用于多路分支选择，适合离散整数值。

```c
int grade = 2;
switch (grade) {
    case 1:
        printf("A\n");
        break;
    case 2:
        printf("B\n");
        break;
    case 3:
        printf("C\n");
        break;
    default:
        printf("未知等级\n");
}
```

## 7. while 循环

`while` 先判断条件，条件为真则执行循环体。

```c
int i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

## 8. do...while 循环

`do...while` 先执行循环体，再判断条件，因此至少执行一次。

```c
int i = 1;
do {
    printf("%d\n", i);
    i++;
} while (i <= 5);
```

## 9. for 循环

`for` 循环适合已知循环次数。

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

## 10. break 和 continue

- `break` 结束当前循环
- `continue` 跳过本次循环，进入下一次迭代

示例：

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break; // 终止整个循环
    }
    printf("%d ", i);
}

for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue; // 跳过 3
    }
    printf("%d ", i);
}
```

## 11. 循环嵌套

一个循环体内部还可以包含另一个循环。

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 2; j++) {
        printf("i=%d, j=%d\n", i, j);
    }
}
```
