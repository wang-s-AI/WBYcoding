/*******************************************************************************
* Program: strtod() Tutorial
* 程序: strtod 字符串转浮点数
* Description: Example of how to use the strtod() function in C.
* 描述: 演示使用 strtod() 安全解析字符串中的浮点数并获取剩余未解析子串指针。
* YouTube Lesson: https://www.youtube.com/watch?v=Kc5V2Hq4Fmc
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char s[] = "978.45 Some text after the double value!";
  double result;
  char *ptr;
  
  // converts the string in s to a double and returns it, and via 
  // pass-by-pointer also "returns" a pointer to the portion of the string 
  // after the double in this case " Some text..."
  result = strtod(s, &ptr);
  
  printf("result: %f\n", result);
  printf("string: |%s|\n", ptr);
 
  return 0;
}