/*******************************************************************************
* Program: Multiline String Literal Demonstration
* 程序: 多行字符串字面量书写技巧
* Description: Example of defining a multiline string literal in C.
* 描述: 演示 C 语言中利用连续引号自动拼接长字符串字面量的方法。
* YouTube Lesson: https://www.youtube.com/watch?v=Z8-DUjAKBYQ
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{ 
  // A string literal defined across multiple lines.  Note that each "line" 
  // will not result in a newline character in the string itself, unless we 
  // manually put \n newline characters into the string as we have done here.
  // Try removing the \n characters to see the difference!
  char b[] = "A simple string. \n" 
             "Another sentence in the string. \n"
             "A third sentence. \n"
             "A fourth sentence. \n";

  printf("%s\n\n", b);
   
  return 0;
}
