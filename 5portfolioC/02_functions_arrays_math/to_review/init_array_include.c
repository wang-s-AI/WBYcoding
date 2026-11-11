/*******************************************************************************
* Program: Initialize Array With #include
* 程序: 通过 #include 预处理指令初始化数组
* Description: Example of how to initialize an array with #include in C.
* 描述: 演示利用预处理器 #include 将外部数据文件内容直接内联注入到数组初始化列表中。
* YouTube Lesson: https://www.youtube.com/watch?v=_rr2AgzB8RI
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main()
{
  // initializes the array with the contents of data.txt, which for testing 
  // purposes was exactly the text:
  // 1,2,3,4,5,6,7,8,9,10
  int a[2][5] = {
    #include "data.txt"
  };

  // verify array 'a' has been initialized with the values from data.txt
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 5; j++)
      printf("a[%d][%d]=%d\n",i,j,a[i][j]);

  return 0;
}