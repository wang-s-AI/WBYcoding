/*******************************************************************************
* Program: Variable scope
* 程序: 变量作用域（文件/全局、函数/局部、块级作用域）教程
* 程序: 变量作用域详解
* Description: Examples of variable scope in C.
* 描述: C 语言中全局文件作用域、函数级局部作用域、块级作用域以及同名遮蔽（Shadowing）机制示例。
* 描述: 演示块级作用域 ({})、文件作用域以及内部变量对外部同名变量的遮蔽。
* YouTube Lesson: https://www.youtube.com/watch?v=IVJoByfBcZs
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

void func(int a);

// global variables aka "file scope", these variables have the scope of the file
// 全局变量（又称“文件作用域 file scope”）：
// 定义在所有函数体外部的变量，其可见范围涵盖整个文件内的所有函数：
int y = 3;
int x = 2;

int main(void)
{
  // x is a local variable, aka "function scope", it has the scope of the main 
  // function
  // main 函数内部的局部变量 x（函数作用域）：
  int x = 5;

  // the local variable x will take precedence over the global variable x and 
  // we will print x: 5 and not x: 2 
  // 【作用域遮蔽原则（Variable Shadowing）】：
  // 当局部变量与全局变量同名时，局部变量拥有更高优先级，会“遮蔽（隐藏）”全局同名变量！
  // 因此此处打印的是局部变量的 5，而不是全局的 2：
  printf("x: %d\n", x);

  // we can access global variable y inside the main function, to use it or 
  // modify it too
  // 在 main 内部未被同名遮蔽的全局变量 y 可以被自由访问和修改：
  printf("y: %d\n", y);
  y++;

  func(10);

  // x will have "block scope", the scope in-between the curly braces below
  // 【块级作用域（Block Scope）】：一对花括号 { } 内部声明的变量，生命周期仅限于该代码块内：
  {
    int z = 2;
    printf("z: %d\n", z);
  }
  
  // we see block scope used for for-loop counter variables like i very often
  // 最常见的块级作用域：在 for 循环头部声明的计数器变量 i，其作用域仅在循环体内有效：
  for (int i = 0; i < 10; i++)
  {
    printf("i: %d\n", i);
  }

  // we cannot access i outside of the above block
  // 超出循环代码块后，变量 i 已经不复存在，如果尝试访问会直接报编译错误：
  // printf("i: %d\n", i);

  return 0;
}

void func(int a)
{
  // functions besides main can have their own local variables
  // 其他普通函数也可以拥有属于自己的同名独立局部变量：
  int x = 8;
 
  // functions besides main can access global variables
  // 任何函数都可以直接读取或修改全局变量 y：
  y++;

  // again because we have a local variable x it takes precedence over the 
  // global variable x and we print out x: 8 instead of x: 2
  // 在 func 内部，其局部的 x (8) 再次遮蔽了全局的 x (2)：
  printf("x: %d\n", x);

  // we can access the global variable y in our functions as well
  printf("y: %d\n", y);

  // a function parameter a is effectively a local variable!
  // 函数形参 a 在技术本质上就是属于该函数的一个局部变量！
  a++;
  printf("a: %d\n", a);
}
