/*******************************************************************************
* Program: strrchr demo
* 程序: strrchr 字符末现反向搜索
* Description: A demonstration of how to use the strrchr function in C.
* 描述: 演示使用 strrchr() 从后向前搜索字符在字符串中最后一次出现的位置。
* YouTube Lesson: https://www.youtube.com/watch?v=cCmHLaL4nag
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char s[] = "some,data,in,commas";
  
  // the function will return a pointer to the last char that matches ',' in s
  char *comma = strrchr(s, ',');

  // this effectively gives us a substring of s from the last matching char 
  // to the end of the string
  printf("%s\n", comma);
  
  // if no matching char is found, the function will return NULL
  char *fail = strrchr(s, '@');
  if (fail == NULL) printf("Could not find @!\n");

  return 0;
}
