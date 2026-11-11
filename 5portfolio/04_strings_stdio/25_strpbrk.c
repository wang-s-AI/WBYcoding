/*******************************************************************************
* Program: strpbrk Demonstration
* 程序: strpbrk 字符集首次命中搜索
* Description: Example of using strpbrk function in C.
* 描述: 演示使用 strpbrk() 搜索指定字符集中任何一个字符在字符串中的首个命中点。
* YouTube Lesson: https://www.youtube.com/watch?v=xRKReYD-pgw
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char s[] = "AASDFAFS3123123";
  char num[] = "0123456789";

  // the function will return a pointer to the first char in s that matches 
  // the first char in num
  char *match = strpbrk(s, num);
  printf("%s\n", match);

  // when the function cannot find a matching char it will return NULL 
  char punct[] = ",;:";
  char *fail = strpbrk(s, punct);
  if (fail == NULL) printf("Could not find!\n");

  return 0;
}
