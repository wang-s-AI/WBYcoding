/*******************************************************************************
* Program: fmod() function demonstration
* 程序: fmod 浮点数取模函数
* Description: Examples of using the fmod() function in C.
* 描述: 演示 math.h 中 fmod() 函数对浮点数进行求余数运算的用法与特性。
* YouTube Lesson: https://www.youtube.com/watch?v=FebH-34EQ30
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double num = 10.4;
  double denom = 3.9;

  // fmod returns the remainder of num divided by denom, like the % modulus 
  // operator but for double values
  double result = fmod(num, denom);
  printf("result: %f\n", result);

  return 0;
}