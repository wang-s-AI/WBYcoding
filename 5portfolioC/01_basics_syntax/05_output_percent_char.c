/*******************************************************************************
* Program: Output The % Percent Character With printf()
* 程序: printf 输出百分号字符
* Description: Demonstration of how to output the % percent character in C using printf(), fprintf(), sprintf() and related functions.
* 描述: 演示在 printf 格式化字符串中如何使用 %% 正确输出单个百分号字符 %。
* YouTube Lesson: https://www.youtube.com/watch?v=O8o4M2xYyC0
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // % is a special character for printf() normally used for placeholders to output
  // things such as ints with %d or floating-point numbers with %f. So if we want
  //to output a literal % character, we must use %% in the format string.
  printf("average: 90%\n");

  printf("average: 90%%\n");
  
  return 0;
}

/*在第 16 行 printf("average: 90%\n"); 里的 %，不仅不会起作用，还会引发语法警告并导致百
分号丢失。具体机制如下：
1. printf 误以为它是“占位符的开头”（用于引导诸如 %d、%f、%s 等占位符）。
当 printf 扫描到 90% 的 % 时：它认为你正准备使用某个格式占位符。
它会去读 % 后面的下一个字符，结果读到了换行符 \n。%\n 根本不是一个合法的 C 语言占位符。
2. 实际产生的后果
编译阶段：编译器会抛出（Warning）：unknown conversion type character '\x0a' in format
（注：\x0a 就是换行符 \n 的十六进制 ASCII 码）。
运行阶段（未定义行为）： 在 GCC 等大多数编译器环境下，这个未知的 % 会直接被丢弃（吞掉），
导致实际屏幕输出变成了：average: 90   百分号 % 根本没有打印出来！*/