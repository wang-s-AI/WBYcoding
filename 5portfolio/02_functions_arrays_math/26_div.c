/*******************************************************************************
* Program: div function demo
* 程序: div 整数除法函数
* Description: Example of us the div function in C.
* 描述: 演示 stdlib.h 中的 div() 函数，一次性同时计算并返回商与余数。
* YouTube Lesson: https://www.youtube.com/watch?v=HwIFm7rKxCk
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  int num = 10;
  int den = 3;
  
  // we could calculate the quotient and remainder seperately with the division 
  // and modulus operations
  // int quot = num / den;
  // int rem = num % den;
  
  // or we can use div to calculate both at once
  div_t result = div(num, den);

  // div returns a struct of type div_t with members quot and rem for the 
  // quotient and remainder values
  printf("quot: %d\n", result.quot);
  printf("rem: %d\n", result.rem);

  // variations of the div function exist for long and other integer values:
  // https://en.cppreference.com/w/c/numeric/math/div
 
  return 0;
}
