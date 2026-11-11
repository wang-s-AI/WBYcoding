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
  // Does not print '90%' because % is a special character for printf() normally
  // used for placeholders to output things such as ints with %d or 
  // floating-point numbers with %f.
  printf("average: 90%\n");

  // But if we have %% then printf() will output a % character and we will have
  // that '90%' is output!
  printf("average: 90%%\n");
  
  return 0;
}