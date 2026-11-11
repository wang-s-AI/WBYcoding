/*******************************************************************************
* Program: strchr demo
* 程序: strchr 字符首现搜索函数
* Description: A demonstration of the strchr() function in C.
* 描述: 演示使用 strchr() 查找目标字符在字符串中的首次出现位置并返回指针。
* YouTube Lesson: https://www.youtube.com/watch?v=uLgdmGVmEUI
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  // An example string
  char tweet[] = "This is my @mention";

  // strchr returns a pointer to the first occurrence of the @ char in tweet, 
  // which effectively gives us a substring of the original string starting 
  // at that character
  char *mention = strchr(tweet, '@');
  printf("mention: %s\n", mention);
  
  // it's important to remember that mention is a substring of the SAME string 
  // in memory, as evidenced by the memory addresses of mention and tweet 
  // shifted over 11 chars
  printf("%p\n", mention);
  printf("%p\n", tweet + 11);

  // so if we modify mention, we will also be modifying tweet as they are really
  // refering to the same string in memory
  mention[0] = '*';
  printf("%s\n", tweet);

  // if a char cannot be found in the string the function returns NULL
  if (strchr(tweet, '#') == NULL)
    printf("strchr returned NULL\n");

  return 0;
}
