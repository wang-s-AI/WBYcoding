/*******************************************************************************
* Program: Array basics tutorial
* 程序: 一维数组基础全面教程
* 程序: 数组基础教程
* Description: Examples illustrating the basics of using arrays in C.
* 描述: C 语言数组的声明、初始化、下标索引、内存连续布局模型以及使用循环遍历计算均值。
* 描述: 演示 C 语言中一维数组的声明、内存布局、初始化与下标索引访问。
* YouTube Lesson: https://www.youtube.com/watch?v=SqOphaInWOs
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// grade array...
// 数组内存模型示意：
//
// Index (下标):   0     1     2     3     4
//
// Value (元素值): 91    82    73    64    55
//
// This is what the grade array looks like in memory, with each value (element)
// accessible via an index starting from 0 up until 4.
// 数组在内存中占据一段连续紧密排列的地址空间。
// 数组下标严格从 0 开始计数，长度为 5 的数组，合法索引为 0 到 4。
//

int main(void)
{
  // we can declare and initialize an array like this 
  // 方式一：声明并由编译器自动推断长度进行初始化：
  int grade[] = {91, 82, 73, 64, 55};

  // ...or like this...
  // 方式二：显式指定数组长度 [5]：
  // int grade[5] = {91, 82, 73, 64, 55};

  // we could also set individual values like this...
  // 方式三：通过下标逐个元素赋值：
  // grade[0] = 91;
  // grade[1] = 82;
  // grade[2] = 73;
  // grade[3] = 64;
  // grade[4] = 55;

  // We can use variables to access array elements, allowing for concise clear 
  // code such as the below to print all array elements... this would scale to 
  // any number of array elements simply by modifying the value 5 (which itself
  // could be a variable or constant value).  
  // 数组最强大的地方在于可以使用循环变量 i 作为下标：
  // 只需一行循环即可遍历任意长度的数组，无论是 5 个还是 500 万个元素逻辑完全一致：
  for (int i = 0; i < 5; i++)
    printf("grade[%d] = %d\n", i, grade[i]);

  // compute the array average print it out
  // 遍历数组累加求和，并计算平均分：
  int total = 0;
  for (int i = 0; i < 5; i++)
    total = total + grade[i];
  int average = total / 5;

  printf("average: %d\n", average);

  return 0;
}
