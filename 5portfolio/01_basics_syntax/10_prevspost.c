/*******************************************************************************
* Program: Prefix vs postfix increment
* 程序: 前置自增 (++i) 与后置自增 (i++) 深度剖析
* 程序: 前置自增与后置自增深入辨析
* Description: Example of prefix vs postfix increment in C.
* 描述: 演示前置 ++i 与后置 i++ 在复合表达式中的运算顺序差异与工程避坑指南。
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
  // 核心机理：
  // 1. 后置 i++ ：先提取 i 当前的旧值 (0) 参与乘法运算 (0 * 10 = 0)，赋值给 result；语句执行完毕后再将 i 自增为 1。
  // 2. 前置 ++i ：先立刻把 i 自增为 1，然后用更新后的值 (1) 参与运算 (1 * 10 = 10)。
  //
  // 【工程最佳实践建议】：
  // 这种混合了自增和算术运算的复合表达式极易令人混淆，在团队协作中属于典型的“易产生 Bug 代码”。
  // 工业级代码规范强烈建议：自增语句单独成行（如直接写 i++;），不要将自增混合进复杂的算术运算中！
  result = i++ * 10;

  printf("result: %d\n", result);
  printf("i: %d\n", i);
  
  return 0;
}
