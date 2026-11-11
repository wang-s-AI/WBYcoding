/*******************************************************************************
* Program: Prefix vs postfix increment
* 程序: 前置自增与后置自增深入辨析
* Description: Example of prefix vs postfix increment in C.
* 描述: 深入对比前置递增 (++i) 与后置递增 (i++) 在赋值与表达式计算中的执行时序差异。
* YouTube Lesson: https://www.youtube.com/watch?v=VWxWYm9Noww
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int i = 0;
  int result = 0;

  // Try flipping i++ to ++i and see the difference! ++i will first increment i
  // and THEN use it in the expression, where as i++ will first use i with its 
  // existing value in the expression and THEN increment it.  This difference 
  // is confusing... developers forget how it works, so you're actually
  // generally better off just not using either an expression like this!
  result = i++ * 10;

  printf("result: %d\n", result);
  printf("i: %d\n", i);
  
  return 0;
}
