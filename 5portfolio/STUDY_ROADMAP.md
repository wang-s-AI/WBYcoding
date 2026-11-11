# 机器人专业（大二 C → C++）分阶段学习路线图（Windows & 跨平台优化版）

本仓库源自 Portfolio Courses C 语言教学示例库，已根据**难度梯度**、**Windows 学习环境**以及**机器人专业 / 后续学习 C++ 的相关性**深度重构为 9 个子目录。每个阶段都列出了**首选必学文件**与**中英文对照解析**，帮你避开海量同质化小题，直击核心底层能力。

---

## 🪟 Windows 学习环境专属指引（必读避坑）

如果孩子在 **Windows 11（VS Code / MinGW-w64 / CLion / Visual Studio）** 环境下学习，需特别注意以下三点底层差异：

1. **64 位数据模型差异（LLP64 vs LP64）**：
   - **Windows 64 位**：`int` 是 4 字节，`long` 也是 **4 字节**！只有 `long long` 和指针才是 8 字节。
   - **Linux 64 位**：`long` 是 8 字节。
   - **避坑建议**：在 Windows 上打印 64 位整数或时间戳（`time_t`）必须使用 `%lld` / `%llu`，或推荐引入 `<stdint.h>` 使用固定位宽类型（如 `int64_t`）。
2. **默认线程栈大小（1 MB 警戒线）**：
   - Windows 默认栈空间仅为 **1 MB**（Linux 默认 8 MB）。
   - **避坑建议**：绝不能在局部变量里声明大数组（例如 `int data[1000000];` 约 3.8 MB，在 Windows 上会瞬间引发 `0xC00000FD` 栈溢出崩溃！）。凡是大于几十 KB 的数据，一律通过 `malloc` 在堆上分配。
3. **系统调用与并发接口（POSIX vs Win32）**：
   - 阶段 `07` 中的部分文件（如 `mkdir.c`、`list_dir_contents.c`、`pthread` 多线程）采用的是标准的 POSIX/Linux 规范。
   - 在 Windows 原生环境下需调用 Windows API（如 `CreateDirectory`、`_findfirst`）或安装支持 POSIX 线程的 MinGW-w64。若在 Windows 上学习 `07`，强烈推荐使用 VS Code 连入远程 Linux 服务器或 WSL2 学习。

---

## 学习优先级总览

| 目录 | 阶段主题 | 核心价值 / Windows 学习指引 | 学习策略 |
| :--- | :--- | :--- | :--- |
| [01_basics_syntax](01_basics_syntax/) | **基础语法与控制流** | 语法基石，全平台通用，包含 `_Bool` 与 C++ 演进 | 1~2 周快速通关，边看双语注释边跑 |
| [02_functions_arrays_math](02_functions_arrays_math/) | **函数、作用域与向量矩阵** | 作用域 + 矩阵运算，机器人算法（Eigen/OpenCV）前置 | 重点掌握二维数组与矩阵旋转、点积 |
| [03_pointers_memory_lowlevel](03_pointers_memory_lowlevel/) | **指针、内存与位运算** ⭐⭐⭐⭐⭐ | **全库第一核心**！堆栈管理、指针算术、位操作（底层寄存器） | **必须精读每一份代码与注释** |
| [04_strings_stdio](04_strings_stdio/) | **字符串本质与报文解析** | `\0` 边界安全、防缓冲区溢出、传感器报文提取 | 掌握 `strtok`/`strtod` 报文解析 |
| [05_structs_enums_files](05_structs_enums_files/) | **结构体、字节对齐与文件 I/O** ⭐⭐⭐⭐⭐ | 串口通信/CAN/ROS2 报文解包基础，内存对齐避坑 | 搞懂字节对齐与二进制读写 |
| [06_modular_preprocessor_dsa](06_modular_preprocessor_dsa/) | **模块化工程、宏与数据结构** ⭐⭐⭐⭐⭐ | 模块分为【工程构建】与【数据结构】两部分，直通 C++ | 掌握头文件防卫与多文件链接 |
| [07_concurrency_timing_system](07_concurrency_timing_system/) | **多线程并发与系统计时** | 对接 Linux / ROS2 实时控制系统与多线程安全 | 建议在远程 Linux 或 WSL2 下运行 |
| [08_practice_exercises](08_practice_exercises/) | 专项巩固刷题库 | 进阶训练题库（近 200 道） | 挑选 10~20 道典型题目手写练手 |
| [09_optional_extras](09_optional_extras/) | 小游戏与冷门技巧 | 算法小游戏、外部库调用（如 curl） | 兴趣拓展，前期可跳过 |

---

## 阶段学习路线与核心必读清单

### 第一梯队：基础夯实（孩子第一阶段核心必学 01 ~ 03）

#### 01. 基础语法与控制流（`01_basics_syntax/`）
* **循序渐进学习顺序（01 ~ 28）**：
  1. `01_hello_world.c`（首个程序）、`02_comments.c`（注释规范）、`03_variables.c`（基本变量类型）
  2. `04_printf.c`（格式化输出）、`05_output_percent_char.c`（输出百分号）、`06_f_vs_lf.c`（%f 与 %lf 辨析）、`07_scanf.c`（键盘输入）
  3. `08_arithmetic.c`（算术运算）、`09_assignment.c`（复合赋值）、`10_prevspost.c`（前置与后置自增）、`11_constants.c`（常量）、`12_typecast.c`（类型转换）
  4. `13_bool.c`（stdbool.h）、`14__Bool.c`（_Bool 原生类型）、`15_relational.c`（关系比较）、`16_logical_operator.c`（逻辑与短路求值）
  5. `17_if.c`（条件分支）、`18_if_statement_best_practice.c`（最佳实践风格）、`19_ternary.c`（三元运算符）、`20_switch.c`（多分支）、`21_switch_menu.c`（菜单实战）
  6. `22_while.c`（while 循环）、`23_dowhile.c`（do-while 循环）、`24_for.c`（for 循环）、`25_convert_for_to_while.c`（循环等价转换）、`26_breakcontinue.c`（跳转控制）
  7. `27_input_validation.c`（输入合法性校验实战）、`28_main_return.c`（main 返回值与操作系统退出码）
* **Windows 学习提示**：`scanf` 在部分 Windows 编译器（如 MSVC）下会提示 `scanf_s` 不安全警告，建议使用标准 `scanf` 并加入 `#define _CRT_SECURE_NO_WARNINGS`。

#### 02. 函数、作用域与向量矩阵（`02_functions_arrays_math/`）
* **函数与作用域（01 ~ 09）**：`01_functions.c`、`02_parameters_vs_arguments.c`、`03_void_functions.c`、`04_void_function_return.c`、`05_legal_ways_to_call_void_functions.c`、`06_local_vs_global_variables.c`、`07_variable_scope.c`、`08_static_local_variables.c`、`09_register.c`
* **一维数组（10 ~ 14）**：`10_array_basics.c`、`11_print_array.c`、`12_array_pass.c`、`13_designated_initializers.c`、`14_init_array_user_input.c`
* **二维数组与矩阵（15 ~ 22，机器人前置）**：`15_twod_array.c`、`16_print_2d_array.c`、`17_init_2darray_user_input.c`、`18_matrix_addition.c`、`19_matrix_subtraction.c`、`20_matrix_transpose.c`、`21_matrix_equality.c`、`22_matrix_multiplication.c`
* **数学库、向量与随机数（23 ~ 36）**：`23_absolute_value.c`、`24_sqrt.c`、`25_pow.c`、`26_div.c`、`27_fmod.c`、`28_modf.c`、`29_round_functions.c`、`30_round_double.c`、`31_vector_add.c`、`32_dot_product.c`、`33_stdev.c`、`34_random.c`、`35_random_double.c`、`36_random_bool.c`

#### 03. 指针、内存管理与底层表示（`03_pointers_memory_lowlevel/`）
* **指针与地址核心（01 ~ 09）**：`01_pointers.c`、`02_null_pointer.c`、`03_pointer_notation.c`、`04_pass_by_reference.c`、`05_swap_pointers.c`、`06_const_pointer_vs_pointer_to_const.c`、`07_void_pointers.c`、`08_function_pointers.c`（状态机/中断回调原型）、`09_function_vs_&function.c`
* **堆内存管理与动态数组（10 ~ 24）**：`10_dynamicmem.c`、`11_malloc_vs_calloc.c`、`12_realloc.c`、`13_realloc_fail.c`、`14_memory_leaks.c`、`15_dangling_pointers.c`、`16_resize_an_array.c`、`17_array_copy.c`、`18_array_concat.c`、`19_return_an_array.c`、`20_return_more_than_one.c`、`21_return_multiple_dynamic.c`、`22_dynamic_2d_array.c`、`23_increase_size_dynamic_2d_array.c`、`24_return_dynamic_2d_array.c`
* **底层内存块操作（25 ~ 30）**：`25_memset.c`、`26_memcpy.c`、`27_own_memcpy.c`、`28_memmove.c`、`29_memchr.c`、`30_memccpy.c`
* **底层位运算与表示（31 ~ 36）**：`31_sizeof.c`、`32_size_t.c`、`33_bitwise_operators.c`、`34_xor_swap.c`、`35_floating_point_classification.c`（防 NaN/Inf 控制崩溃）、`36_heap_inspection.c`

---

### 第二梯队：工程实战与协议解析（04 ~ 07）

#### 04. 字符串本质与输入输出安全（`04_strings_stdio/`）
* **字符串与字符集基础（01 ~ 14）**：`01_string_basics.c`、`02_null_terminator.c`、`03_multiline_string_literal.c`、`04_puts.c`、`<ctype.h>` 字符判断系列（`05_ctype.c` ~ `14_tolower.c`）
* **字符串操作与报文解析（15 ~ 28，机器人通讯核心）**：`15_strnlen.c`、`16_strcmp.c`、`17_strcpy_strncpy.c`、`18_strcat_strncat.c`、`19_string_append.c`、`20_strchr.c`、`21_strrchr.c`、`22_strstr.c`、`23_strspn.c`、`24_strcspn.c`、`25_strpbrk.c`、`26_strtok.c`（分词解析传感器/CSV）、`27_strtod.c`（字符串转浮点）、`28_sprintf.c`（构造通信报文）
* **缓冲区安全与健壮输入（29 ~ 36）**：`29_string_safety.c`、`30_gets.c`（废除分析）、`31_string_input.c`（fgets 规范）、`32_remove_fgets_trailing_newline.c`、`33_clear_input_buffer.c`、`34_integer_input.c`、`35_infinite_buffer.c`、`36_infinite_number_user_input_buffer.c`
* **动态字符串与指针数组（37 ~ 42）**：`37_append_char_to_dynamically_allocated_string.c`、`38_resize_string_dynamically_allocated.c`、`39_dynamic_string_truncate.c`、`40_return_a_string.c`、`41_dynamic_array_of_strings.c`、`42_convert_string.c`

#### 05. 结构体、字节对齐与文件 I/O（`05_structs_enums_files/`）
* **结构体、对齐与状态机（01 ~ 06）**：`01_struct.c`、`02_typedef.c`、`03_arrow_operator.c`、`04_structure_padding.c`（**通信协议封包核心**：内存对齐与填充）、`05_enum.c`（状态机）、`06_dynamic_array_of_structs.c`
* **文本文件读写基础（07 ~ 17）**：`07_fileio.c`、`08_char_bug.c`（为何 fgetc 返回 int）、`09_feof.c`、`10_display_file_contents.c`、`11_read_line.c`、`12_read_file.c`、`13_fputs.c`、`14_write_input_to_file.c`、`15_append_input_to_file.c`、`16_copy_file.c`、`17_merge_files.c`
* **文件随机寻址与维护（18 ~ 25）**：`18_fseek.c`、`19_rewind.c`、`20_ungetc.c`、`21_truncate.c`、`22_remove.c`、`23_rename.c`、`24_tmpfile.c`、`25_tmpnam.c`
* **文件数据内存结构化加载（26 ~ 30）**：`26_file_lines_to_string_array.c`、`27_files_lines_to_dynamic_array.c`、`28_file_to_dynamic_string_suboptimal.c`、`29_file_to_dynamic_string_optimized.c`、`30_readfile_into_2d_array.c`
* **结构化 CSV 与二进制存储（31 ~ 33）**：`31_array_of_structs_to_csv.c`、`32_csv_to_struct_array.c`、`33_struct_array_binary_file.c`（fread/fwrite 高速二进制持久化）

#### 06. 模块化工程、宏与经典数据结构（`06_modular_preprocessor_dsa/`）
* **宏与条件编译（01 ~ 09）**：`01_function_like_macros.c`、`02_do_while_0_macro_pattern.c`（do-while-0 防御）、`03_token_pasting_operator.c`、`04_predefined_macros.c`、`05_activate_debug_output.c`、`06_if_elif_else.c`、`07_if_0_technique.c`、`08_line_directive.c`、`09_stdarg_demo.c`（可变参数函数）
* **递归算法思维（10 ~ 17）**：`10_recursion.c`、`11_factorial_loop.c`、`12_factorial_recursion.c`、`13_fib.c`、`14_head_vs_tail_recursion.c`（尾调用优化）、`15_direct_vs_indirect_recursion.c`、`16_single_vs_multiple_recursion.c`、`17_stack_overflow.c`（栈溢出成因剖析）
* **基础数据结构（18 ~ 19）**：`18_stack.c`（栈）、`19_sets.c`（集合）
* **经典查找与排序算法（20 ~ 28）**：`20_middle_index.c`（防溢出）、`21_binary_search.c`（二分查找）、`22_bubble_sort.c`、`23_selection_sort.c`、`24_insertion_sort.c`、`25_merge_sort.c`、`26_quicksort.c`（快速排序）、`27_qsort.c`（标准库比较器）、`28_sorting_strings.c`

#### 07. 多线程并发与系统计时（`07_concurrency_timing_system/`）
* **进程控制与退出管理（01 ~ 10）**：`01_cmdargs.c`、`02_getenv.c`、`03_system.c`、`04_exit.c`、`05_exit_statuses.c`、`06_atexit.c`、`07_abort.c`、`08_assert.c`、`09_print_debugging.c`、`10_stderr.c`
* **文件系统与路径操作（11 ~ 14）**：`11__getcwd.c`、`12__chdir.c`、`13__mkdir.c`、`14__rmdir.c`
* **高精度计时与延时（15 ~ 18）**：`15_seed.c`、`16_sleep.c`、`17_countdown_timer.c`、`18_measure_execution_time.c`（clock() 测定执行耗时）
* **多线程并发基础（19）**：`19_thread_intro.c`（POSIX 多线程 pthread_create / pthread_join 入门）
