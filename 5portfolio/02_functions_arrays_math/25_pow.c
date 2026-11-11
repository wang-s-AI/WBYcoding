/*******************************************************************************
* Program: pow() function demonstration
* 程序: pow 幂运算函数
* Description: Example of using the pow function in C.
* 描述: 演示 math.h 中 pow() 函数进行底数与指数的幂次方数学计算。
* YouTube Lesson: https://www.youtube.com/watch?v=wmaJ6GYSMcg
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <math.h> // contains the pow function

int main(void) 
{
  double x = 2.5;
  double y = 4.2;
  double result = pow(x, y);
  printf("result: %f\n", result);
  
  // the pow function will also work with int values as C will implicitly  
  // convert the int arguments to double, and implicitly convert the returned 
  // result to an int when assigning it to an int variable
  int a = 2;
  int b = 4;
  int result_int = pow(a, b);
  printf("result_int: %d\n", result_int);

  return 0;
}
