# C++ 教学代码库问题审计与修正报告 (ISSUES_TO_REVIEW.md)

> **环境与测试标准**：
> - 编译器：`g++ (Ubuntu 13.3.0-6ubuntu2~24.04)` / MSYS2 UCRT64 GCC 14+
> - 语言标准：`-std=c++17 -Wall -Wextra`
> - 测试范围：全库 138 个 C++ 源码文件（包括子工程模块）
> - 状态：**已全量完成代码修正与排查，全库 138 个文件 100% 编译通过（0 Errors）！**

---

## 一、真实 Bug 与语法缺失（已彻底修复）

| 序号 | 所在模块与文件 | 原代码问题描述 | 修复与改进说明 |
| :--- | :--- | :--- | :--- |
| **01** | `06_file_io_streams/17_append_text_to_file.cpp` | 缺少 `#include <fstream>` 头文件，直接声明 `ofstream outFile;` 导致报聚合类型不完整错误 (`aggregate 'std::ofstream outFile' has incomplete type`)。 | 补齐 `#include <fstream>`。 |
| **02** | `06_file_io_streams/04_clear_input_buffer.cpp` | 使用了 `numeric_limits<streamsize>::max()`，但缺少 `<limits>` 头文件，导致报未声明标识符错误 (`'numeric_limits' was not declared in this scope`)。 | 补齐 `#include <limits>`。 |
| **03** | `02_functions_references/03_default_arguments.cpp` | 包含 `using namespace std;` 并在 `main()` 中调用 `cout`，但漏写了 `#include <iostream>`。 | 补齐 `#include <iostream>`。 |
| **04** | `01_basics_syntax/16_range_based_for_loop.cpp` | 在第 34 行局部变量中定义了普通数组 `int array[] = {1,2,3,4,5};`，导致后续调用 STL 容器 `array<int, 50> stl_array;` 时被局部变量同名遮蔽（Name Shadowing），报语法解析错误。 | 将模板容器显式限定为 `std::array<int, 50>`，消除作用域同名遮蔽。 |
| **05** | `03_classes_objects/22_rectangle_perimeter.cpp` | 原作者由 `rectangle_area.cpp` 拷贝修改时疏忽，第 67 行打印输出周长处误写为 `cout << "Perimeter: " << area << endl;`，变量 `area` 未声明报错。 | 更正为 `cout << "Perimeter: " << perimeter << endl;`。 |
| **06** | `06_file_io_streams/06_string_concatenation.cpp` | 第 41 行拼写笔误：定义了字符变量 `char c1 = 'D';`，但在拼接测试中误写为 `s1 + D`（直接使用了字面字符标识符而非变量名）。 | 更正为 `s1 + c1`。 |
| **07** | `01_basics_syntax/02_comments.cpp` | 中文注释中写入了嵌套块注释符号 `/* ... */`，导致外部的块注释被提前意外闭合，引发语法解析错乱与非非法字符报错。 | 规范调整为非闭合形式 `/* ... * /`，避免任何块注释意外闭合。 |
| **08** | `03_classes_objects/11_static_member_functions.cpp` | 头部 Program 注释属于拷贝粘贴遗留的空白/cin 描述，与代码主题不相符。 | 纠正为 `Static Member Functions` / `静态成员函数`。 |

---

## 二、教学中故意演示报错的代码（已注释隔离并附教学说明）

在 C++ 面向对象、权限控制与命名空间进阶中，原作者写了几处专门用于给学员演示**“编译器为何会报错”**的教学反例。若保持开启会阻碍整个工程自动化构建，已通过注释安全隔离，并保留清晰的双语解释：

| 序号 | 所在模块与文件 | 教学意图与原报错现象 | 隔离与注释说明 |
| :--- | :--- | :--- | :--- |
| **01** | `02_functions_references/06_const_array_parameters.cpp` | 演示 `const int array[]` 常量数组参数具备只读保护，在函数体内试图修改 `array[2] = 99;` 会被编译器拒绝。 | 将修改语句注释：`// array[2] = 99;`，并附上只读保护验证说明。 |
| **02** | `03_classes_objects/16_deleted_functions.cpp` | 演示 C++11 现代特性 `= delete`（禁止拷贝赋值与构造）。原代码在测试赋值 `unique3 = unique1;` 时未声明 `unique3`，本身存在语法漏洞。 | 补齐 `Unique unique3;` 对象声明，同时将拷贝赋值语句注释隔离：`// unique3 = unique1;`，供学员按需解开测试编译器拦截效果。 |
| **03** | `07_advanced_patterns_practice/using_namespace_std/demo.cpp` | 演示在大型工程头文件中写入 `using namespace std;` 产生的全局污染与重名二义性（`func1()` 与 `min(4,5)` 冲突）。 | 将触发二义性报错的两行调用注释，附带命名空间污染教学分析。 |

---

## 三、验证结果与建议

- 全工程现支持通过以下单行命令全量快速编译自检：
  ```bash
  python3 -c '
  import glob, subprocess, os
  files = sorted(glob.glob("6PortfolioCPP/*/*.cpp") + glob.glob("6PortfolioCPP/*/*/*.cpp"))
  for f in files:
      subprocess.check_call(["g++", "-std=c++17", "-c", f, f"-I{os.path.dirname(f)}", "-o", "/dev/null", "-lm"])
  print(f"Verified {len(files)} files: ALL PASSED!")
  '
  ```
- 建议学习时若想观察编译器报错机制，可对照本报告中的第二部分，逐一解开对应的注释行进行反向验证。
