/*******************************************************************************
* Program: strcspn Demo
* 程序: strcspn 不匹配字符前缀跨度检索
* Description: Example of using the strcspn function in C.
* 描述: 演示使用 strcspn() 检索字符串开头不包含指定字符集中任何字符的最大长度。
* YouTube Lesson: https://www.youtube.com/watch?v=AQPsGkRgVBE
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char s[] = "ADSFASFAS42312321";
  char num[] = "0123894567";
  
  // finds the number of chars in the initial segment of s that are not found 
  // in num
  int init = strcspn(s, num);
  printf("init: %d\n", init);

  // we can use this information to help us manipulate/process the string, for 
  // example to obtain a pointer (effectively a substring) to the portion of 
  // the string after this initial segment
  char *numcode = s + init;
  printf("%s\n", numcode);

  return 0;
}
