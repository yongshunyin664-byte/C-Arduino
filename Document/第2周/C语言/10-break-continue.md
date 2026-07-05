# break 和 continue

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

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。

