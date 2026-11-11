/*******************************************************************************
* Program: Void Functions
* 程序: void 无返回值函数深度解析
* 程序: void 无返回值函数
* Description: Example of a void function in C.
* 描述: 演示 C 语言中 void 函数的意义、调用方式以及使用 return 提前终止函数执行的技巧。
* 描述: 演示无返回值函数的声明、定义与执行副作用任务（如打印输出）的基本用法。
* YouTube Lesson: https://www.youtube.com/watch?v=jOoiVmVUy-Q
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

void print_array(int array[], int length);
int add(int a, int b);

int main(void)
{
  // A "value-returning function" like add() returns a value that we can use 
  // somehow, like assigning it to a variable.
  // 像 add() 这样的“有返回值函数”，会计算并产生一个结果值，我们可以将其赋给变量或参与后续计算
  int sum = add(10,5);

  // Output the resulting sum
  printf("Sum: %d\n", sum);

  // A test array of numbers to print out
  int numbers[] = {5,6,7,8,9};

  // A void function does not return a value, so we don't assign any 
  // return value to a variable in this case, we simply call the function.
  //
  // Void functions are sometimes called non value returning functions.
  // 
  // One reason we create functions is so that we don't have to repeat 
  // the same code in different places in our program, instead we can 
  // write the code once and execute it by calling the function.  Not all
  // code produces or calculates a value, some code does other work such
  // as outputting values or information.  So a void function that does 
  // not return a value can still be useful this and other reasons why 
  // functions are useful.
  // void 函数不产生任何返回值，因此调用时不能将其赋值给任何变量，只需单独作为一个语句直接调用。
  // void 函数有时被称为“过程（procedure）”或“纯执行函数”。
  // 封装函数的核心目的之一是消除重复代码（DRY 原则）。并非所有代码的任务都是为了“算出一个数值”，
  // 很多代码的工作是“执行某种任务”（如打印输出、硬件引脚置位、发送网络数据等）。
  // 因此即便没有返回值，void 函数在工程中也具有极为广泛的应用价值。
  print_array(numbers, 5);
  
  // The void function does not return a value so we can't store a 
  // return value into a variable like this.
  // void 函数没有返回值，如果尝试像下面这样将调用结果赋给变量，编译器会直接强制报错：
  //
  // int return_value = print_array(numbers, 5);

  // Void functions actually can use return statements to stop the execution
  // of the function, as this function does if the length argument value is
  // less than or equal to 0.
  // void 函数虽然不返回数据，但完全可以使用裸写的 return; 语句来提前终止当前函数的执行：
  print_array(numbers, -5);
  
  return 0;
}

// A void function which prints out the values stored in the array with hte 
// provided length.
//
// The function does not have to have a return statement anywhere, execution
// of the function will simply stop when the end of the function body is 
// reached.  We can optionally include return statements though as in this 
// example, to stop the execution of the function "early".
// 一个 void 函数，用于按给定的长度打印数组中的各个元素：
// void 函数末尾无需强制写 return，执行到达函数体最底部的右大括号 } 时会自动返回。
// 但我们可以根据业务逻辑需要，在条件满足时使用 return; 提前退出函数。
void print_array(int array[], int length)
{
  // An array with a length <= 0 does not make sense so we stop the function
  // using return in this case
  // 防御性编程：如果传入的数组长度 <= 0，毫无打印意义，直接通过 return; 提前结束函数执行
  if (length <= 0) return ;
  
  // Otherwise we use a loop with a counter variable i to go through the 
  // indexes of the array from 0, 1, ..., length-1, and we output each 
  // value in the array separated by a space.  We output a newline after 
  // all the values in the array have been output.
  // 正常情况下，遍历打印从索引 0 到 length-1 的所有元素：
  for (int i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// A value returning function that returns the sum of parameters 'a' and 'b'
// 有返回值函数：返回形参 a 和 b 的加法之和
int add(int a, int b)
{
  return a + b;
}
