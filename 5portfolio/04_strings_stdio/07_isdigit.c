/*******************************************************************************
* Program: isdigit() Demonstration
* 程序: isdigit 数字字符判断函数
* Description: Example of using the isdigit() function in C to check if a char is a digit or not.
* 描述: 演示使用 isdigit() 检查字符是否为 0-9 十进制数字。
* YouTube Lesson: https://www.youtube.com/watch?v=tzwdohXjB_Q
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The characters 0-9 are digits, all other characters are not.
  //
  // Try modifying what the char variable c is set to below and see the effect!

  char c = '7';
  
  if (isdigit(c)) 
  {
    printf("%c is a digit\n", c);
  }
  else
  {
    printf("%c is not a digit\n", c);
  }
  
  return 0;
}