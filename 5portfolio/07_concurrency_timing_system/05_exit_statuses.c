/*******************************************************************************
* Program: Exit status demonstration
* 程序: EXIT_SUCCESS 与 EXIT_FAILURE 退出状态码
* Description: Demonstrates basics of exit statuses.
* 描述: 演示使用跨平台标准宏 EXIT_SUCCESS (0) 与 EXIT_FAILURE 向父进程报告运行状态。
* YouTube Lesson: https://www.youtube.com/watch?v=_Q6G9FP8tQ8
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void func()
{
  // The exit() function that's built-in to stdlib.h can be called ANYWHERE
  // to exit the program.  EXIT_SUCCESS is a portable way of exiting the program
  // with a status of success.
  exit(EXIT_SUCCESS);
}

int main(void)
{
  func();

  // The return value of the main function will also exit the program with the 
  // status provided as a return value.  The EXIT_STATUS macro is a portable way
  // of exiting the program with a failure/error status.  The EXIT_SUCCESS and 
  // EXIT_FAILURE macros are provided in stdlib.h.
  return EXIT_FAILURE;
}