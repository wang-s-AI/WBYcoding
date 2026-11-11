/*******************************************************************************
* Program: Function basics tutorial
* 程序: 函数基础全面教程
* 程序: 函数基础教程
* Description: Examples illustrating the basics of using functions in C.
* 描述: C 语言函数的声明（原型）、定义、带返回值调用与无返回值 void 函数示例。
* 描述: 演示 C 语言中函数的原型声明、定义、参数传递与返回值机制。
* YouTube Lesson: https://www.youtube.com/watch?v=NGQoKF2Ggt8
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// function declarations that tell the compiler these functions will be defined
// 函数前向声明（函数原型）：提前告知编译器这些函数的存在、参数类型与返回值类型，
// 以便 main 函数在看到具体实现前就可以合法调用它们：
int add(int a, int b);
int mult(int x, int y);
void print_int(int a);

int main(void)
{
  // using printf is a type of function call!
  // 调用标准库的 printf 本质上也是在执行一次函数调用！
  printf("Hello, World!\n");
  printf("Another printf statements!\n");

  /// we call the add function with arguments 4 and 5, it returns an int value
  // that we initialize output to... it's as if the return value of add(4, 5)
  // (in this case 9) takes the place of add(4, 5)
  // 我们传入实参 4 和 5 调用 add 函数，它计算后返回一个整数（9），
  // 这个返回值就像替换了 add(4, 5) 表达式本身一样，赋给变量 output：
  int output = add(4, 5);
  printf("Output: %d\n", output);

  // we call the mult function with arguments 9 and 7, it returns an int value
  // 传入实参 9 和 7 调用乘法函数 mult，接收其计算返回值：
  int multoutput = mult(9,7);
  printf("Mult output: %d\n", multoutput);

  // we can call a function with no return value (a void function)
  // 调用一个无返回值的函数（void 函数）：仅执行打印动作，不产生返回值
  print_int(5);

  return 0;
}

// the add function accepts two int parameters a and b, adds them together, and 
// returns the resulting int 
// 函数定义：add 函数接收两个整型形参 a 和 b，将它们相加，并通过 return 返回计算结果
int add(int a, int b)
{
  int result = a + b;
  return result;
}

// the mult function accepts two int parameters x and y, and uses the add 
// function defined above repeatedly to perform multiplication.
// mult 函数接收形参 x 和 y，通过反复循环累加调用上面定义的 add 函数来实现乘法（展示函数的模块化复用）
int mult(int x, int y)
{
  int result = 0;
  for (int i = 0; i < x; i++)
    result = add(result, y);
  return result;
}

// An example of a void function which has no return value!
// void 函数示例：函数返回类型为 void，说明该函数不返回任何数据
void print_int(int a)
{
  printf("INT: %d\n", a);
}
