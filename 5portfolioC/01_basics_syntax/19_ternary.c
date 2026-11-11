/*******************************************************************************
* Program: Ternary operator example
* 程序: 三目运算符 (条件运算符 ? : ) 教程
* 程序: 三元条件运算符 (?:)
* Description: Examples of how to use the ternary operator in C.
* 描述: C 语言三目运算符的语法、作为表达式返回值的用法以及与 if-else 语句的等价对比。
* 描述: 演示条件运算符（三元运算符 ? :）简化 if-else 表达式的用法。
* YouTube Lesson: https://www.youtube.com/watch?v=nWvk4fPJu1U
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a = 5;
  int b = 5;
  int c = 0;

  // we could use an if-else to determine what assignment to make
  // if (a == b) c = 10;
  // else c = 5;
  // 常规做法：可以使用 if-else 条件分支来决定给变量赋什么值

  // or we could use a ternary operator, which checks the boolean expression 
  // preceeding the ? and then returns 5 if it is true and 10 if it is false
  // 简练写法：使用三目运算符（条件 ? 表达式1 : 表达式2）
  // 检查 ? 前面的布尔条件 (a == b)：如果为真则返回 5，否则返回 10
  c = ( a == b ) ? 5 : 10;

  printf("c: %d\n", c);

  int result = 0;

  // We can use a ternary operator in the middle of an expression such as this!
  // 三目运算符本质是一个“表达式”，它会产生一个结果值，因此可以直接嵌入到更复杂的数学表达式中计算：
  result = 10 * ((a == c) ? 2 : 1);

  printf("result: %d\n", result);
 
  return 0;
}
