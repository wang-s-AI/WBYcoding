# 机器人专业（大二 C → C++）分阶段学习路线图

本仓库源自 Portfolio Courses C 语言教学示例库，已根据**难度梯度**与**机器人专业 / 后续学习 C++ 的相关性**重构为 9 个子目录。每个阶段都列出了**首选必学文件**，帮你避开海量同质化小题，直击核心底层能力。

> **特别提示**：各子目录下若存在 `to_review/` 文件夹，里面放的是存在语法报错、64 位兼容隐患、UB 或注释错误的文件，详情见各目录的 `待纠正_说明.md` 与根目录 [ISSUES_TO_REVIEW.md](ISSUES_TO_REVIEW.md)。

---

## 学习优先级总览

| 目录 | 阶段主题 | 机器人/C++ 相关性 | 学习策略 |
| :--- | :--- | :--- | :--- |
| [01_basics_syntax](01_basics_syntax/) | 语法基础与控制流 | ⭐⭐⭐ | 1~2 周快速过完核心示例 |
| [02_functions_arrays_math](02_functions_arrays_math/) | 函数、作用域与向量矩阵 | ⭐⭐⭐⭐ | 重点看作用域 + 矩阵运算 |
| [03_pointers_memory_lowlevel](03_pointers_memory_lowlevel/) | **指针、内存与位运算** | ⭐⭐⭐⭐⭐（核心） | **精读每一份核心代码** |
| [04_strings_stdio](04_strings_stdio/) | 字符串本质与报文解析 | ⭐⭐⭐⭐ | 理解 `\0`、防溢出与 `strtok`/`strtod` |
| [05_structs_enums_files](05_structs_enums_files/) | **结构体、对齐、联合体与 I/O** | ⭐⭐⭐⭐⭐（核心） | **协议解包与数据记录核心** |
| [06_modular_preprocessor_dsa](06_modular_preprocessor_dsa/) | **多文件工程、宏与数据结构** | ⭐⭐⭐⭐⭐（核心） | **直通 C++ 类/头文件/算法** |
| [07_concurrency_timing_system](07_concurrency_timing_system/) | **多线程、互斥锁与计时** | ⭐⭐⭐⭐⭐（核心） | **对接 Linux / ROS2 并发** |
| [08_practice_exercises](08_practice_exercises/) | 专项巩固刷题库 | ⭐⭐ | 挑 10~20 道练手，不必全刷 |
| [09_optional_extras](09_optional_extras/) | 小游戏、语法冷门技巧与外部库 | ⭐ | 感兴趣再看，可跳过 |

---

## 各阶段首选必学推荐

### 01. 基础语法与控制流（`01_basics_syntax/`）
- **必看推荐**：`hello_world.c`、`variables.c`、`constants.c`、`arithmetic.c`、`assignment.c`、`relational.c`、`logical_operator.c`、`typecast.c`、`if.c`、`if_statement_best_practice.c`、`switch.c`、`for.c`、`while.c`、`dowhile.c`、`breakcontinue.c`、`f_vs_lf.c`、`bool.c`、`_Bool.c`
- **C++ 过渡提示**：`_Bool.c` 中演示了 C 允许 `is_raining++`，但 **C++17 起已完全禁止对 `bool` 做 `++` 运算**；C 语言常用 `<stdbool.h>`，C++ 原生自带 `bool`。

### 02. 函数、作用域与向量矩阵（`02_functions_arrays_math/`）
- **函数与作用域必看**：`functions.c`、`void_functions.c`、`parameters_vs_arguments.c`、`variable_scope.c`、`local_vs_global_variables.c`、`static_local_variables.c`
- **机器人数学直通**：`array_basics.c`、`array_pass.c`、`twod_array.c`、`dot_product.c`、`vector_add.c`、`matrix_addition.c`、`matrix_subtraction.c`、`matrix_multiplication.c`、`matrix_transpose.c`（理解后续 Eigen / OpenCV 矩阵在内存中的原型）

### 03. 指针、内存管理与底层表示（`03_pointers_memory_lowlevel/`）
> **全库最核心目录**，也是从 C 顺利迈向 C++（引用、`const`、智能指针、移动语义）的关键。
- **底层与嵌入式寄存器基石**：`bitwise_operators.c`、`sizeof.c`、`size_t.c`、`floating_point_classification.c`（SLAM/控制律防 `NaN`/`Inf` 必备）、`lvalues_ravlues.c`（见 `to_review/`，理解左值/右值，无缝对接 C++ 右值引用）
- **指针精读**：`pointers.c`、`pointer_notation.c`、`pass_by_reference.c`、`return_more_than_one.c`、`const_pointer_vs_pointer_to_const.c`、`void_pointers.c`、`function_pointers.c`（状态机/中断回调原型）
- **堆内存与安全避坑**：`dynamicmem.c`、`malloc_vs_calloc.c`、`realloc.c`、`realloc_fail.c`、`null_pointer.c`、`dangling_pointers.c`、`memory_leaks.c`、`dynamic_2d_array.c`、`memcpy.c`、`memmove.c`、`memset.c`

### 04. 字符串本质与输入输出安全（`04_strings_stdio/`）
- **必看推荐**：`string_basics.c`、`null_terminator.c`、`string_safety.c`、`gets.c`（重点看为什么绝不能用 `gets()`，理解缓冲区溢出）、`clear_input_buffer.c`、`remove_fgets_trailing_newline.c`
- **报文/串口协议常用**：`sprintf.c`、`strtod.c`、`strtok.c`、`return_a_string.c`（理解为什么局部数组不能返回指针，从而体会 C++ `std::string` 的优越性）

### 05. 结构体、字节对齐与文件 I/O（`05_structs_enums_files/`）
- **嵌入式/传感器协议必看**：`struct.c`、`typedef.c`、`arrow_operator.c`、`enum.c`、`unions.c`（见 `to_review/`，字节流与结构体/浮点互转经典技巧）、`structure_padding.c`（串口/CAN/UDP 收发结构体对齐避坑、`#pragma pack(1)`）
- **传感器日志与配置读写**：`fileio.c`、`fseek.c`、`csv_to_struct_array.c`、`array_of_structs_to_csv.c`、`struct_array_binary_file.c`

### 06. 多文件工程、宏与基础数据结构（`06_modular_preprocessor_dsa/`）
- **大型工程与 C++ 封装前奏（全读）**：
  - `basic_library/`（`.h` 声明与 `.c` 实现分离）
  - `include_guards/`（`#ifndef` 头文件防重复包含）
  - `extern_share_global_variable/`、`static_global_variable/`、`static_functions/`（理解链接属性与信息隐藏——这就是 C++ `private` 的前身）
- **宏与预处理器**：`if_0_technique.c`、`activate_debug_output.c`、`function_like_macros.c`、`do_while_0_macro_pattern.c`
- **算法与数据结构**：`stack.c`、`stack_overflow.c`（单片机 RAM/栈有限，必看）、`binary_search.c`、`quicksort.c`、`qsort.c`（`void *` 泛型回调）、`sets.c`

### 07. 多线程、互斥锁与系统接口（`07_concurrency_timing_system/`）
- **对接 Linux / ROS2 核心**：`thread_intro.c`、`race_condition_example/`、`mutex/`（重点理解临界区与互斥锁，之后学 C++ `std::thread` 与 `std::mutex` 秒懂）
- **控制周期计时与健壮性**：`measure_execution_time.c`、`assert.c`、`stderr.c`、`cmdargs.c`、`exit_statuses.c`

### 08 & 09. 巩固题库与拓展（`08_practice_exercises/`、`09_optional_extras/`）
- `08_practice_exercises/`：包含近 200 个基础数组/字符串/递归/文件练习。刚学指针和数组时挑 10~15 个（如 `reverse.c`、`palindrome.c`、`your_own_strcpy.c`、`own_strcat.c`、`split.c`、`join.c`、`binary_to_decimal.c`、`decimal_to_binary.c`）自己手写一遍即可。
- `09_optional_extras/`：小游戏与冷门技巧（注意 `nested_functions.c` 是 GNU C 非标准扩展，`void_main.c` 是反面教材，`goto.c` 在 C++ 中极少使用）。
