# Windows + VS Code + C/C++ 终端中文乱码终极解决方案

> 本文针对使用 VS Code 在 Windows 环境下开发 C/C++ 程序时，终端运行输出中文呈现“澶ф暟瀛”、“鍗犵敤”等乱码问题进行原理剖析，并提供最优雅、彻底的解决方案。

---

## 一、现象与根本原因剖析

### 1. 常见现象
- 源代码通过 OneDrive / Git 从另一台电脑或 Mac/Linux 同步过来，源码文件格式为 **UTF-8**。
- 代码中有中文字符输出（例如 `printf("大数字: %lld\n", big_number);`）。
- 在另一台电脑上运行输出完全正常，但在当前 Windows 电脑的 VS Code 终端里运行，输出全部是乱码。

### 2. 根本原因：编码链条不匹配
```
[源文件 .c] 采用 UTF-8 编码保存（每个中文字符占用 3 字节）
   ⬇️
[GCC/G++ 编译器] 默认按 UTF-8 编码直接将字符串二进制流写入 .exe 可执行文件
   ⬇️
[Windows 默认终端] 简体中文版 Windows 的控制台默认代码页为 CP936 (GBK，中文字符占 2 字节)
   ⬇️
【乱码产生】终端强行用 2 字节的 GBK 规则去解读 3 字节的 UTF-8 字符流，字节错位拼接导致乱码。
```

### 3. 为什么另一台机器上完全正常？
检查发现，正常的机器通常在全局 PowerShell 启动脚本（`$PROFILE`）中预设了终端编码自动切换机制。只要打开任何终端，系统就已在后台静默将代码页切换为 `65001 (UTF-8)`，因此天然兼容。

---

## 二、终极解决方案：配置 PowerShell 全局 Profile（最推荐）

这是最彻底、体验最好的解法。配置后，**当前电脑上任何时候打开 PowerShell 或在 VS Code 中点击运行代码，终端都会自动保持 UTF-8 环境，一劳永逸。**

### 步骤 1：放行 PowerShell 脚本执行权限
Windows 默认禁止执行任何 ps1 脚本（策略为 `Restricted`）。我们需要为当前用户放行本地脚本权限（**无需管理员权限**）：

在 PowerShell 中执行以下命令：
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
```

### 步骤 2：创建或编辑 Profile 配置文件
在 PowerShell 中运行以下命令，会自动使用记事本打开当前用户的 Profile 脚本：
```powershell
if (!(Test-Path -Path $PROFILE)) { New-Item -ItemType File -Path $PROFILE -Force }
notepad $PROFILE
```
> **默认路径参考**：`C:\Users\<你的用户名>\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1`

### 步骤 3：粘贴全局 UTF-8 配置内容
在打开的记事本文档中，粘贴以下配置并保存退出：

```powershell
# 1. 设置控制台与管道默认编码为 UTF-8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8

# 2. 切换当前终端代码页为 UTF-8 (65001)
chcp 65001 | Out-Null

# 3. 设置文件读写相关默认编码为 UTF-8
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'
$PSDefaultParameterValues['*:Encoding'] = 'utf8'
```

### 步骤 4：生效与验证
1. 打开 VS Code；
2. 如果底部已有打开的终端，**必须点击终端右上角的垃圾桶图标 🗑️（终止终端）**关闭旧会话；
3. 按快捷键 <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>`</kbd> 打开一个新终端，输入：
   ```powershell
   chcp
   ```
   若输出为 `活动代码页: 65001`，说明全局 UTF-8 配置已正式生效！再次运行 C 语言程序，中文即可完美显示。

---

## 三、备选方案（视场景选用）

### 方案 B：在编译阶段转码（修改 `tasks.json`）
如果你不想改动 Windows 系统的全局 PowerShell 设定，可以让 GCC 编译器在把 UTF-8 源码编译为 `.exe` 时，自动把内置的字符串转为 Windows 默认的 GBK 编码输出：

打开项目的 [.vscode/tasks.json](file:///d:/OneDrive/CODING/.vscode/tasks.json)，在 `"args"` 中加入 `"-fexec-charset=GBK"`：

```json
"args": [
    "-fdiagnostics-color=always",
    "-fexec-charset=GBK",
    "-g",
    "${file}",
    "-o",
    "${fileDirname}\\${fileBasenameNoExtension}.exe"
]
```
- **优点**：不需要对终端做任何配置，生成的 `.exe` 可以在任何标准 Windows 电脑的 CMD / PowerShell 下双击或直接运行不乱码。
- **注意**：修改后需要对 `.c` 文件重新保存并触发编译，以生成新编码的 `.exe`。

---

### 方案 C：在 C 语言代码内调用 Windows API 自适应（跨平台推荐）
如果你希望写出来的程序在任何人的 Windows 电脑上运行都能自动显示中文，可以在代码中直接调用系统 API 切换输出代码页：

```c
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    // 强制将当前运行的控制台输出编码动态切为 UTF-8
    SetConsoleOutputCP(65001);
#endif

    printf("大数字: %lld\n", 9876543210123LL);
    printf("int 占用的字节数: %zu\n", sizeof(int));

    return 0;
}
```
- **优点**：代码随仓库同步，任何 Windows 环境下运行都会自愈；`#ifdef _WIN32` 保障了如果代码拿到 Linux / macOS 下编译，Windows 相关代码会被自动剔除，不影响跨平台兼容。

---

## 四、高频踩坑 FAQ

### Q1：为什么在 VS Code 的 `settings.json` 里配置了 `chcp 65001` 依然乱码？
```json
"terminal.integrated.profiles.windows": {
    "PowerShell": {
        "source": "PowerShell",
        "args": ["-NoExit", "-Command", "chcp 65001"]
    }
}
```
**原因**：VS Code 的 `profiles.windows` 中的 `args` 仅对你**手动点击 `+` 号新建交互式终端**时有效。当你点击右上角的 **▶（运行 C/C++ 文件）** 或按 **F5** 时，C/C++ 插件使用的是后台自动化任务执行器（Task Terminal），会直接绕过上述参数，依然继承系统默认代码页。因此配置全局 `$PROFILE` 是唯一的根本解法。

### Q2：启动终端时提示“无法加载文件 ... Microsoft.PowerShell_profile.ps1，因为在此系统上禁止运行脚本”？
**原因**：Windows 系统的脚本执行策略未放行。  
**解决**：在终端运行：
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
```

### Q3：配置完之后重新运行还是乱码？
请按顺序检查以下两点：
1. **是否杀死了旧终端**：已打开的终端窗口不会热更新配置，必须点**垃圾桶 🗑️**关闭后重新运行。
2. **是否重新编译了 `.exe`**：如果只是按了运行但源码没有修改，VS Code 可能会直接执行上一次生成好的旧 `.exe`。在 `.c` 文件中按一下空格并保存（<kbd>Ctrl</kbd> + <kbd>S</kbd>），再点击运行即可。
