/*******************************************************************************
* Program: Difference Between int main() vs int main(void)
* 程序: int main() 与 int main(void) 的严格差异
* Description: A program to help understand the difference between int main() and int main(void) function prototypes in C.
* 描述: 深度对比 C 语言中 main()（接受任意参数）与 main(void)（严格不接受参数）的规范区别。
* YouTube Lesson: https://www.youtube.com/watch?v=0DTToSTL02Q
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// func1 has a 'blank' parameter list
void func1()
{
  printf("func1\n");
}

// func2 has void in-place of a parameter list
void func2(void)
{
  printf("func2\n");
}

int main(void)
{
  // if we call func1() or func2() without an argument, both functions will 
  // work fine as expected
  func1();
  func2();

  // If we call func1() WITH an argument we'll get a compiler warning at worst
  // func1("abc");

  // If we call func2() WITH an argument we'll get a compiler ERROR, preventing 
  // the program from even being compiled.  So by using void in-place of a 
  // parameter list we make it very explicit that the function cannot be called
  // with an argument.
  //
  // func2("abc");
  
  // So if we use void in-place of a parameter list in our main function we will
  // also get an error if we then try to call main with an argument.  As a 
  // result as a best-practice we should use void in-place of a parameter list 
  // in our main function prototype (unless of course our program will use 
  // command-line arguments in which case a prototype with the relevant 
  // parameter should be used).
  //
  main("abc");

  return 0;
}