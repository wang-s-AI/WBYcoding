/*******************************************************************************
* Program: "Return" More Than One Value
* 程序: 函数返回多个计算结果
* Description: Examples of "returning" more than one value from a function in C using pass-by-reference (i.e. pass-by-pointer).
* 描述: 演示在 C 语言中通过传入多个指针形参（输出参数）让函数间接返回多个计算结果。
* YouTube Lesson: https://www.youtube.com/watch?v=R8IogBSLXV0
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

void rect(int length, int width, int *area, int *perimeter);

int main()
{
  int area_result = 0;
  int perimeter_result = 0;

  // pass the memory addresses of area_result and perimeter result 
  rect(10,5, &area_result, &perimeter_result );
  
  printf("area: %d\n", area_result);
  printf("perimeter: %d\n", perimeter_result);
  
  return 0;
}

// computes the area and perimeter of a rectangle with the provided length and 
// width and stores the value into the variables located at the memory addresses
// provided to area and rectangle
void rect(int length, int width, int *area, int *perimeter)
{
  // the * operator "de-references the pointer", in other words, it accesses 
  // the memory address stored by area and perimeter and below... i.e. the 
  // variables area_result and perimeter_result in main!
  *area = length * width;
  *perimeter = 2 * (length + width);
}

