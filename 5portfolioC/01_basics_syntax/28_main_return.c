/*******************************************************************************
* Program: Main return value tutorial
* 程序: main 函数返回值与操作系统退出码
* 程序: main 函数返回值详解
* Description: Examples of main return values in C.
* 描述: 演示 main 函数返回值的意义：return 0 代表成功正常退出，非零代表异常状态码。
* 描述: 讲解 main 函数的退出状态码（0 表示成功，非 0 表示异常）及其在操作系统的含义。
* YouTube Lesson: https://www.youtube.com/watch?v=CBfhcRQVpf8
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int input = 0;
  printf("Enter: ");
  scanf("%d", &input);

  // Returning the value 0 signals to the shell/terminal that the program has 
  // exited successfully, and anything else signals an issue/error.
  // 向外返回数值 0 是向父进程（终端 Shell / 操作系统）发出的约定信号：表示程序成功无误执行完毕。
  // 返回任何非零数值（例如 1）则表示程序运行遭遇了某种错误或非预期分支。
  if (input > 5) return 0;
  else return 1;
}
