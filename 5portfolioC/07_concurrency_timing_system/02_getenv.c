/*******************************************************************************
* Program: getenv() Function
* 程序: 读取操作系统环境变量
* Description: Example of using the getenv() function in C to get the value of an environment variable, which are often used to configure how programs run.
* 描述: 演示使用 getenv() 获取系统 PATH、HOME 或 USER 环境变量的值。
* YouTube Lesson: https://www.youtube.com/watch?v=bB1PV9Cb98c
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // getenv will return a pointer to a string for the value of the environment 
  // variable called LOG_DIR
  char *log_dir = getenv("LOG_DIR");
 
  // output the string
  printf("LOG_DIR:\n%s\n", log_dir);

  return 0;
}