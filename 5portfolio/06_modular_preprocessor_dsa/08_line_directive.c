/*******************************************************************************
* Program: #line Preprocessor Directive
* 程序: #line 预处理行号重置指令
* Description: Example of using the line preprocessor directive in C to alter the __FILE__ and __LINE__ predefined macros.
* 描述: 演示使用 #line 修改编译器报错输出时引用的代码行号与源文件名。
* YouTube Lesson: https://www.youtube.com/watch?v=m3d5XIv3Fr4
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // __FILE__ and __LINE__ are predefined macros that will be set to the 
  // current source code filename and linenumber be default.
  
  // This will modify __FILE__ to be "origin.c" and __LINE__ to be 51
  #line 51 "origin.c" 
  printf("error @ %s:%d\n", __FILE__, __LINE__);
  
  printf("again @ %s:%d\n", __FILE__, __LINE__);  
  
  // __LINE__ will continue to "increment" from the line where it is 
  // altered, so the second call to printf will output a line 2 more than 
  // the first call to printf() above it!

  return 0;
}

// We typically use __LINE__ and __FILE__ to output error messages, they 
// allow us to associate an error with where it takes place in the source
// code.  But sometimes we write C programs that actually generate other
// C programs, in which case we may want to associate the error message 
// with the original C program and not the generated program.
//
// Maybe origin.c generates file.c, and the error on line 9 of file.c 
// should *really* be associated with line 51 of origin.c  We can use the
// #line directive to make this association.
//
//  origin.c   ->   file.c   
//
//  line 51    ->   line 9 code
