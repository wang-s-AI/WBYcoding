/*******************************************************************************
* Program: Comments Examples
* 程序: 注释书写规范
* Description: Examples of using single line and multiline comments in C++.
* 描述: 演示 C++ 中单行注释 (//) 与多行块注释 (/* ... * /) 的书写规范 (注意块注释不可嵌套)。
* YouTube Lesson: https://www.youtube.com/watch?v=dKErkyRxPyE
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
  double x, y, sum; // Declare 3 variables

  // Prompt the user to enter the two numbers
  cout << "Enter two numbers: ";

  /*
   Accept user input for:
   - variable x
   - variable y
   */
  cin >> x >> y;

  // add together x and y
  // to produce the sum
  sum = x + y;

  // sum = y + x;

  cout << x << " + " << y << " = " << sum << endl;

  return 0;
}