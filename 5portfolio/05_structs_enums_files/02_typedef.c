/*******************************************************************************
* Program: typedef tutorial
* 程序: typedef 别名定义简化结构体
* Description: Example of using typedef in C.
* 描述: 演示使用 typedef 为结构体创建语义清晰的类型别名，避免重复编写 struct 关键字。
* YouTube Lesson: https://www.youtube.com/watch?v=dTFpT-zuG0Q
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// typdef creates an 'alias' kilometer for int... meaning kilometer can be used 
// anywhere int can be used
typedef int kilometer;

int main(void)
{
  // we use kilometer to declare these variables because we want to represent 
  // the distance in kilometers to each of these cities
  kilometer newyork, chicago, miami;

  newyork = 300;
  chicago = 500;
  miami = 1900;

  // kilometer type variables are still really just ints though, so we still 
  // use the %d placeholder as we would with any int for example
  printf("new york: %d\n", newyork);
  printf("chicago: %d\n", chicago);
  printf("miami: %d\n", miami);

  return 0;
}
