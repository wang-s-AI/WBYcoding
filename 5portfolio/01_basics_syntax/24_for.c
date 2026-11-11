/*******************************************************************************
* Program: for loop tutorial
* 程序: for 循环基础
* Description: Examples of for loops in C.
* 描述: 演示 C 语言中标准计数型 for 循环的语法与控制流程。
* YouTube Lesson: https://www.youtube.com/watch?v=7SAYJiACIvM
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>


int main(void)
{
  
  // Example for loop
  for (int i = 0; i < 5; i++)
  {
    printf("i: %d\n", i);
  }   
  printf("\n");

  // Example of using break in a for loop, which will cause the loop to 
  // terminate when i == 2
  for (int i = 0; i < 5; i++)
  {
    printf("i: %d\n", i);
    if (i == 2) break;
  }   
  printf("\n");
  
  // Example of using continue in a for loop, which will skip over the printf 
  // (and any other remainder of the loop body) when i == 2
  for (int i = 0; i < 5; i++)
  {
    if (i == 2) continue;
    printf("i: %d\n", i);
  }   

  return 0;
}
