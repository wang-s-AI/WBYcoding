/*******************************************************************************
* Program: strstr demo
* 程序: strstr 子串搜索函数
* Description: Example of using the strstr function in C.
* 描述: 演示使用 strstr() 在主串中快速搜索子字符串的起始位置。
* YouTube Lesson: https://www.youtube.com/watch?v=V32VSYVd1Ro
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char haystack[] = "This is the way.";
  char needle[] = "the";

  // strstr will return a pointer to the first occurrence of needle in the 
  // haystack, effectively giving us a substring of the original string 
  // from the matching string to the end of the string  
  char *the = strstr(haystack, needle);
  printf("the: %s\n" , the);
  
  // if strstr cannot find a match, it will return NULL
  char now[] = "now";
  char *fail = strstr(haystack, now);
  if (fail == NULL) printf("failed to find string!\n");

  return 0;
}
