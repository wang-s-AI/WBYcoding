/*******************************************************************************
* Program: Constants tutorial
* 程序: 常量定义教程
* Description: Examples of constants in C.
* 描述: 演示并对比 C 语言中使用 const 关键字与 #define 预处理宏定义常量的区别。
* YouTube Lesson: https://www.youtube.com/watch?v=r0OuA1Q8jOo
*******************************************************************************/
#include <stdio.h>

void print_array(int *array, int size);

// we can use the preprocessor statement define to create a constant
#define LENGTH 10

// we can create a global constant variable, but it must be initialized to 
// a value like this...
// const int len = 4;
// so the below will not work...
// int x = 5;
// const int len = x;

int main(void)
{
  // we can use the constant LENGTH whever we can use the value 10
  int a[LENGTH] = {0,1,2,3,4,5,6,7,8,9};
  print_array(a, 10);

  printf("\n");
  int b[] = {0,1,2,3,4,5,6,7,8,9,10};
  print_array(b, 11);

  // test that we can use a global constant variable len
  // printf("len: %d\n", len);

  return 0;
}

void print_array(int *array, int size)
{
  // we use const to declare a constant variable... it will be just like a 
  // regular variable, including properties such as scope, in this case the 
  // scope of the function, BUT we can only initialize once when we first 
  // declare it and cannot alter it later as it is a constant!
  const int length = size;
  for (int i = 0; i < length; i++)
    printf("array[%d]=%d\n",i,array[i]);
}