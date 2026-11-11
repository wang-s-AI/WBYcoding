# 6PortfolioCPP: C++ Programming Example Code & Study Guide

本代码库对应 YouTube 著名计算机编程教学频道 [Portfolio Courses](https://www.youtube.com/c/PortfolioCourses) 的官方 C++ 教学系列教程代码，涵盖初学者入门、面向对象机制、继承与多态、泛型模板与 STL 容器算法、现代 String 与文件流持久化、设计模式与实用算法。

为了提供系统化、阶梯式的学习体验，本项目已完成深度规范化梳理：
- **按知识进阶分类**：划分为 7 大英文主题模块，层层递进。
- **推荐学习顺序编号**：每个模块内部所有文件均以两位数序号（`01_...` ~ `30_...`）前缀命名。
- **紧凑双语题注**：所有代码保留原始英文注释，题注区域补充中文程序名与知识点描述。
- **问题全面审计与修复**：已完成全部 138 个源码文件的缺陷修复与编译验证，支持 `g++ -std=c++17` 100% 编译通过。

---

## 📂 目录结构与模块说明

| 模块目录 | 知识主题 | 源码数量 | 核心技术关键词 |
| :--- | :--- | :---: | :--- |
| [`01_basics_syntax/`](01_basics_syntax/) | 基础语法与流输入输出 | 20 | `std::cin` / `cout`、布尔逻辑、区间 for 循环、分支跳转 |
| [`02_functions_references/`](02_functions_references/) | 函数进阶与引用语义 | 13 | 函数重载、默认参数、引用传递、`new` / `delete`、递归 |
| [`03_classes_objects/`](03_classes_objects/) | 面向对象核心与运算符重载 | 23 | 封装性、构造与析构、初始化列表、`this` 链式调用、运算符重载、深拷贝 |
| [`04_inheritance_polymorphism/`](04_inheritance_polymorphism/) | 继承、多态与抽象接口 | 13 | 单继承、虚函数 `virtual`、虚析构函数、纯虚函数与接口类 |
| [`05_templates_stl/`](05_templates_stl/) | 泛型编程与 STL 容器算法 | 21 | 函数/类模板、`vector`/`stack`/`queue`、`<algorithm>` 标准算法 |
| [`06_file_io_streams/`](06_file_io_streams/) | 字符串与文件流 I/O | 30 | `<iomanip>` 格式化、`std::string` 进阶、`<fstream>` 文件读写 |
| [`07_advanced_patterns_practice/`](07_advanced_patterns_practice/) | 异常、设计模式与综合演练 | 18 | `try-catch` 异常、命名空间、单例模式 (`Singleton`)、经典算法实战 |

---

## 📖 核心文档索引

1. **[STUDY_ROADMAP.md (C++ 核心编程进阶学习路线图)](STUDY_ROADMAP.md)**：包含全景流程图、详细知识点对照表与工程思考，专为系统学习者量身定制。
2. **[ISSUES_TO_REVIEW.md (代码审计与修正报告)](ISSUES_TO_REVIEW.md)**：记录了库中原始代码的语法笔误、缺失头文件、同名遮蔽修复以及故意报错反例的隔离说明。

---

## 🛠️ 编译与自检

在 Linux / Ubuntu 或 Windows (MSYS2 UCRT64) 终端中，可直接使用以下命令进行全库编译自检：

```bash
# 单文件编译示例
g++ -std=c++17 -Wall -Wextra 6PortfolioCPP/01_basics_syntax/01_hello_world.cpp -o hello && ./hello

# 全库 138 个 C++ 源码批量快速验证
python3 -c '
import glob, subprocess, os
files = sorted(glob.glob("6PortfolioCPP/*/*.cpp") + glob.glob("6PortfolioCPP/*/*/*.cpp"))
for f in files:
    subprocess.check_call(["g++", "-std=c++17", "-c", f, f"-I{os.path.dirname(f)}", "-o", "/dev/null", "-lm"])
print(f"Verified {len(files)} C++ files: ALL PASSED!")
'
```

---

## 🔗 原作者致谢与视频课程

- **频道主页**：[Portfolio Courses YouTube Channel](https://www.youtube.com/c/PortfolioCourses)
- **C++ 教学播放列表**：[C++ Tutorials Playlist](https://www.youtube.com/playlist?list=PLA1FTfKBAEX6BdpNaWp2uw-YspHwY7qwW)
- **C++ 示例演练列表**：[C++ Examples Playlist](https://www.youtube.com/playlist?list=PLA1FTfKBAEX5gcjcrTga2ld_jA-9Ww4s0)
