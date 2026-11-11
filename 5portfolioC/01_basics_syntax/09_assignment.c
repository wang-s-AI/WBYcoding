/*******************************************************************************
* Program: Assignment operator examples
* 程序: 赋值运算符与复合赋值运算符
* Description: Examples of how to use assignment operators in C.
* 描述: C 语言基础赋值运算符 (=) 以及算术复合赋值运算符 (+=, -=, *=, /=, %=) 的使用示例。
* YouTube Lesson: https://www.youtube.com/watch?v=a2cbw2jkyMA
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a;

  // standard assignmen operator assigns 5 to a
  a = 5;
  printf("a: %d\n", a);
 
  // adds 2 to a
  a += 2;
  printf("a: %d\n", a);
  
  // subtracts 2 from a
  a -= 2;
  printf("a: %d\n", a);

  // multiples a by 2
  a *= 2;
  printf("a: %d\n", a);
  
  // divides a by 2
  a /= 2;
  printf("a: %d\n", a);

  // sets a to the remainder of a divided by 2
  a %= 2;
  printf("a: %d\n", a);

  return 0;
}
