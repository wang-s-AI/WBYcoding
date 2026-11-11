/*******************************************************************************
* Program: Function Examples
* 程序: 函数基础与原型声明
* Description: Examples covering an introduction to functions in C++.
* 描述: 演示 C++ 中函数的前置声明、定义、参数传递与返回值机制。
* YouTube Lesson: https://www.youtube.com/watch?v=_N3G5L6k_rI
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <iostream>

using namespace std;
  
double travelTime(double, double);
void printErrorMessage();
void addOne(int number);

int main()
{   
  //  f(x) : x + 1
  //  f(2) = 2 + 1 = 3 
  //
  double tripTime1 = travelTime(200, 40); 
  cout << "Trip 1 (h): " << tripTime1 << endl;  

  double tripTime2 = travelTime(100,20);
  cout << "Trip 2 (h): " << tripTime2 << endl;  
 
  double d = 150;
  double s = 55;

  double tripTime3 = travelTime(d,s); 
  cout << "Trip 3 (h): " << tripTime3 << endl;   

  int number = 10;
  addOne(number);

  cout << "number: " << number << endl; 
  
  return 0;
}

void addOne(int number)
{
  number = number + 1;
}

void printErrorMessage()
{
  cout << "Error: cannot divide by zero" << endl;
}

double travelTime(double distance, double speed)
{
  if (speed == 0)
  {
    printErrorMessage(); 
    return -1;
  }
  else 
  {
    return distance / speed; 
  }
}