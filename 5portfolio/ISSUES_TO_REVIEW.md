# 全库待纠正问题汇总（待交叉确认后动手修改）

> **说明**：本仓库已按学习阶段整理为 `01_*` ~ `09_*` 共 9 个子目录。所有被检测出 Bug、C23/Windows 编译失败、未定义行为（UB）、注释张冠李戴、后缀错误或缺失依赖的文件，均已**原样保留未改动**，分别移入各自阶段下的 `to_review/` 子目录，并在各 `to_review/待纠正_说明.md` 中写了详细位置与修改方案。
>
> 检查环境：Windows 64 位 + `gcc.exe (MSYS2 UCRT64) 16.2.0`（默认 C23）。

---

## 一、🔴 真实 Bug / 意外编译报错 / Windows 运行崩溃（优先纠正）

| 阶段 | 文件/目录 | 核心问题 | 修改建议摘要 |
| :--- | :--- | :--- | :--- |
| 01 | [scanf.c](01_basics_syntax/to_review/scanf.c) | 第 28 行 `printf("n: %d\n", &n);` 把地址 `&n` 当值打印，严重误导新手 | 改为 `printf("n: %d\n", n);` |
| 03 | [segmentation_fault.c](03_pointers_memory_lowlevel/to_review/segmentation_fault.c) | 第 39 行 `printf("%d\n", data[2];)` 括号内多出 `;` 导致无法编译 | 改为 `printf("%d\n", data[2]);` |
| 05 | [binary/](05_structs_enums_files/to_review/binary/) | 3 个文件均在栈上声明 `int data[1000000];`（约 3.81 MB），Windows 默认栈（1~2 MB）下极易栈溢出崩溃 | 改为 `malloc`/`calloc` 堆分配，并把 `sizeof(data)` 改为 `sizeof(int) * 1000000` |
| 06 | [queue_linked_list.c](06_modular_preprocessor_dsa/to_review/queue_linked_list.c) | 第 194/250 行 `int peek()` / `int dequeue()` 中 `return NULL;` 在 GCC 16 (C23) 直接编译报错 | 改为 `return 0;`（已通过 `*status = false` 表示失败）；检查 `malloc` 空指针 |
| 07 | [detached_threads.c](07_concurrency_timing_system/to_review/detached_threads.c) | 第 30/78 行 `void *logger()` 缺 `void *arg` 参数，在 C23 下 `pthread_create` 报错；且 `incidents` 无锁竞争、`log_file` 缺 `fflush` | 改为 `void *logger(void *arg)`；注释提示加互斥锁与 `fflush` |
| 07 | [time.h](07_concurrency_timing_system/to_review/time.h) | `.c` 源码误命名为 `.h`（可能遮蔽 `<time.h>`）；`time_t` 用 `%ld` 打印；第 91 行变量命名 `strlen` 遮蔽标准函数 | 重命名为 `time_demo.c`；`time_t` 强转 `(long long)` 用 `%lld`；变量改名 `len` |
| 08 | [count_array_positive_negative_zeros.c](08_practice_exercises/to_review/count_array_positive_negative_zeros.c) | 第 37 行多了一个字符 `1`：`int negative_count = 0;1` | 删除多余的 `1` |
| 08 | [count_spaces.c](08_practice_exercises/to_review/count_spaces.c) | 第 28 行缺少结尾分号 `;` | 行末补 `;` |

---

## 二、🟠 未定义行为（UB）/ 标签错误 / 64位与跨平台陷阱

| 阶段 | 文件 | 核心问题 | 修改建议摘要 |
| :--- | :--- | :--- | :--- |
| 02 | [find_array_length.c](02_functions_arrays_math/to_review/find_array_length.c) | 头部 `Description` 误写为 `abort()`；5 处 `sizeof` 用 `%d`；宏未加外括号 | 修正注释描述；宏加括号；`%d` 改 `%zu` |
| 03 | [array_vs_&array.c](03_pointers_memory_lowlevel/to_review/array_vs_&array.c) | 指针及 `int` 解引用结果全用 `%zu` 打印（`-Wformat` 警告 13 处） | 指针十进制改 `(size_t)(uintptr_t)`，`int` 值改回 `%d` |
| 03 | [realloc_vulnerability.c](03_pointers_memory_lowlevel/to_review/realloc_vulnerability.c) | 64 位指针强转 32 位 `(int)` 打印发生地址截断；标题拼写 `vulnernability` | 改用 `%p` 或 `(uintptr_t)`；修正拼写 |
| 04 | [char_array_vs_string_literal_pointer.c](04_strings_stdio/to_review/char_array_vs_string_literal_pointer.c) | 第 83–84 行 `sizeof` 使用 `%d` 打印 | 改为 `%zu` |
| 04 | [iterate_string_pointer.c](04_strings_stdio/to_review/iterate_string_pointer.c) | 第 71 行打印标签写 `"&string[1]"` 实际传 `&string[4]`；指针用 `%zu` | 修正标签为 `&string[4]`；指针改 `(uintptr_t)` 或 `%p` |
| 05 | [unions.c](05_structs_enums_files/to_review/unions.c) | 第 79/80/86 行 `sizeof` 用 `%d` 打印 | 改为 `%zu` |
| 05 | [fprintf.c](05_structs_enums_files/to_review/fprintf.c) | 第 135 行 `unsigned long ul = 123456789012345;` 在 Windows 64 位（32 位 `long`）溢出 | 改为 `unsigned long long` + `%llu`，或改小常量 |
| 05 | [replace_line.c](05_structs_enums_files/to_review/replace_line.c)、[write_specific.c](05_structs_enums_files/to_review/write_specific.c) | 使用标准 C 未定义行为 `fflush(stdin);` 清空输入缓冲区 | 改为 `while ((c = getchar()) != '\n' && c != EOF) {}` |
| 06 | [ifdef_ifndef.c](06_modular_preprocessor_dsa/to_review/ifdef_ifndef.c) | 第 60 行 `sizeof(buffer)` 用 `%lu` 打印 | 改为 `%zu` |
| 07 | [time_null.c](07_concurrency_timing_system/to_review/time_null.c) | 第 37 行用 `%ld` 打印 `time_t`（Windows 64 位下为 64 位 `long long`） | 强转 `(long long)` 并使用 `%lld` |
| 07 | [list_dir_contents.c](07_concurrency_timing_system/to_review/list_dir_contents.c) | 使用 MinGW `<dirent.h>` 不存在的 `d_type`/`DT_REG`/`DT_DIR` | 改用 `stat()` + `S_ISREG` / `S_ISDIR` 或标注仅限 Linux |
| 07 | [mkdir.c](07_concurrency_timing_system/to_review/mkdir.c) | POSIX 2 参数 `mkdir` 在 Windows MinGW 报错；手写 `extern int errno;` 冲突 | 删除 `extern int errno;`；用 `#ifdef _WIN32` 区分或标注仅限 Linux |
| 07 | [errno.c](07_concurrency_timing_system/to_review/errno.c) | 第 18 行多余的 `extern int errno;` 与 MinGW CRT `_errno` 属性冲突 | 删除该行（仅保留 `#include <errno.h>`） |
| 08 | [check_if_all_chars_unique.c](08_practice_exercises/to_review/check_if_all_chars_unique.c) 等 5 个文件 | 直接拿有符号 `char` 当作数组下标（非 ASCII/中文 UTF-8 下标为负越界 UB） | 下标强转为 `(unsigned char)` |

---

## 三、🟡 故意报错演示未注释 / 缺失外部文件（影响直接编译）

| 阶段 | 文件/目录 | 情况说明 | 修改建议摘要 |
| :--- | :--- | :--- | :--- |
| 02 | [int_main_void_difference.c](02_functions_arrays_math/to_review/int_main_void_difference.c) | 第 52 行故意写了 `main("abc");` 演示报错，但未注释 | 注释第 52 行并保留说明 |
| 02 | [init_array_include.c](02_functions_arrays_math/to_review/init_array_include.c) | `#include "data.txt"` 缺少配套 `data.txt` | 补建示例 `data.txt` |
| 03 | [declare_multiple_pointers.c](03_pointers_memory_lowlevel/to_review/declare_multiple_pointers.c) | 第 45/62 行故意报错未注释 + 第 50–57 行 `sizeof` 用 `%d` | 注释报错演示行；`%d` 改 `%zu` |
| 03 | [lvalues_ravlues.c](03_pointers_memory_lowlevel/to_review/lvalues_ravlues.c) | 文件名拼写错 + 第 43 行 C89 隐式 `int`（`const y = 20;`）+ 多处故意报错未注释 | 重命名 `lvalues_rvalues.c`；补 `int`；注释报错行 |
| 06 | [error.c](06_modular_preprocessor_dsa/to_review/error.c) | 第 21/30 行故意写 `#error` 未加条件屏蔽 | 用 `#if 0` 或注释提示如何测试 `#error` |
| 09 | [libcurl_examples/](09_optional_extras/to_review/libcurl_examples/) | 需要外部 `libcurl` 库与 `-lcurl` 链接 | 补充编译命令说明或配置 MSYS2 `libcurl` 后使用 |

---

## 四、🟢 扩展名、注释张冠李戴、重复文件与清理项

| 阶段 | 文件/目录 | 问题 | 处理建议摘要 |
| :--- | :--- | :--- | :--- |
| 05 | [clearerr.cpp](05_structs_enums_files/to_review/clearerr.cpp) | 纯 C 教学代码却保存为 `.cpp` 扩展名 | 重命名为 `clearerr.c` |
| 08 | [count_digits.c](08_practice_exercises/to_review/count_digits.c) | 头部注释误拷贝自 `stdev.c`（标准差） | 更正头部注释描述 |
| 08 | [multiplication_table.c](08_practice_exercises/to_review/multiplication_table.c) | 头部注释误拷贝自 `savings_calculator.c` | 更正头部注释描述 |
| 08 | [count_digits_integer.c](08_practice_exercises/to_review/count_digits_integer.c) | 与正常目录中 `count_integer_digits.c` 完全重复 | 确认后可删去重复副本 |
| 08 | [ouput_row_2D_array.c](08_practice_exercises/to_review/ouput_row_2D_array.c)、[remove_chat_at_pos.c](08_practice_exercises/to_review/remove_chat_at_pos.c) | 文件名拼写笔误（`ouput` / `chat`） | 重命名为 `output_row_2D_array.c`、`remove_char_at_pos.c` |
| 09 | `abort.exe`、`constants.exe`、`_chdir.exe`、`_mkdir.exe`、`test/` | 4 个旧编译产物 `.exe` 及 1 个空目录 | 确认后可删除 |
