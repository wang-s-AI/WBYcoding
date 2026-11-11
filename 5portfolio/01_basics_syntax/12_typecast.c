/*******************************************************************************
* Program: Type casting
* 程序: 类型转换（强制类型转换与隐式类型提升）
* 程序: 类型转换（强制转换与隐式提升）
* Description: Example of how to use type casting in C.
* 描述: 演示 C 语言中 (double) 显式强转、隐式算术提升（自动由窄到宽转换）与截断赋值行为。
* 描述: 演示 C 语言中变量类型的显式强制转换 (typecast) 与隐式转换规则。
* YouTube Lesson: https://www.youtube.com/watch?v=xKOPZ4mEH3I
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a = 5;
  int b = 2;

  // a is casted (converted) to a double first because type conversion has 
  // higher precedence than division, then b is implicitly "promoted" to a 
  // double for a division with two doubles to occur
  // 显式强制转换：由于类型转换运算符 (double) 的优先级高于除法 /，
  // 变量 a 首先被强制转换为 double（5.0）。随后变量 b 被隐式自动“提升”为 double（2.0），
  // 从而进行两个浮点数的精确除法，得到精确结果 2.500000。
  double c = (double) a / b;
  
  // if both a and b are ints then int division will occur, if as above one of 
  // the operands is a double the other operand will be promoted to a double 
  // 对比：如果 a 和 b 都是普通整数 int，执行的是整数除法，小数部分被无情截断（5 / 2 = 2）：
  printf("%d / %d = %d\n", a, b, a / b);

  // in this case we have division between two doubles and so the result is
  // a double
  // 经过类型转换后的浮点除法输出：
  printf("%d / %d = %f\n", a, b, c);

  // try playing around with the types of x, y and z to see how implicit 
  // promotion of types for operations occurs, including "demotion" when we 
  // assign a double value to an int
  // 尝试调整 x, y, z 的数据类型，观察隐式类型提升以及当把 double 赋给 int 时的“类型降级/精度截断”：
  int x = 2;
  double y = 5;

  // here x gets promoted to a double for the operation to take place, but then 
  // we store the result into an int, and so C will implicitly convert the 
  // value to an int to assign it to z
  // 运算时 x 先被自动提升为 double 进行除法（结果为 2.5）；
  // 但随后赋值给整型变量 z 时，编译器会将 2.5 隐式截断向下取整为 2 存入 z：
  int z = y / x;

  printf("z: %d\n", z);

  return 0;
}
