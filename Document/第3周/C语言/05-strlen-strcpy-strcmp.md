# strlen、strcpy、strcmp

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

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。
