/*******************************************************************************
* Program: system() function demo
* 程序: system() 函数执行操作系统 Shell 命令
* Description: Examples of using the system() function in C to run shell commands.
* 描述: 演示使用 system() 在子进程中调用执行操作系统命令行指令并获取退出状态。
* YouTube Lesson: https://www.youtube.com/watch?v=rVFpdKtS5jA
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // run an ls command to list files in the current directory
  system("ls");

  // run commands to create a file called test.txt and fill it with some 
  // content and then output that content
  system("echo 'some content' > test.txt");
  system("cat test.txt");
  
  // if there is an error with the command system will return a non-zero value
  if (system("abc") != 0)
    printf("\nError executing command.\n");

  return 0;
}