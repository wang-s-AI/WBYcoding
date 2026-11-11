/*******************************************************************************
* Program: Hello world example
* 程序: Hello World 入门程序
* Description: A "hello world" program in C.
* 描述: 标准的 C 语言入门第一个程序，演示终端文本输出。
* YouTube Lesson: https://www.youtube.com/watch?v=WXY-r9s0_Rg
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
// standard library that includes functions for input and output (like printf)
#include <stdio.h>

// the main function is where execution of statements will begin
int main(void)
{
  // Outputs the text Hello, World! to the terminal (technically this is what
  // we'll call standard output), the " " characters define what's called a 
  // string literal, and the \n is a newline character.  C statements like 
  // this end with a ; character.
  printf("Hello, World!\n");

  // the main function returns an int, and we return 0, which tells the OS 
  // running the program that it has exited successfully
  return 0;
}