/*******************************************************************************
* Program: erase() String Member Function
* 程序: erase 元素删除与迭代器失效
* Description: Examples of removing characters from a string in C++ using the erase() string member function.
* 描述: 演示 vector 与 string 成员函数 erase 删除单元素或区间的操作及迭代器维护。
* YouTube Lesson: https://www.youtube.com/watch?v=ux1tQ-zyMUs
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  //             0123456789
  string text = "A string with lots of words in it!";
  
  // text.erase(2,7);
  // text.erase(2, 100);
  // text.erase(2);
  // text.erase();
    
  string::iterator iter = text.erase(text.begin() + 2);
  
  cout << *iter << endl;
    
  // text.erase(text.begin(), text.begin() + 9);
  
  // text.erase(text.begin() + 8, text.end());
  
  cout << text << endl;

  return 0;
}