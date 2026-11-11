/*******************************************************************************
* Program: Read All File Contents Into A String
* 程序: 一次性完整读取整个文件内容
* Description: Example of how to read all the contents of a file into a string with C++.
* 描述: 演示利用 stringstream 或循环一次性将文本文件的全部字符读入内存字符串。
* YouTube Lesson: https://www.youtube.com/watch?v=q97E8rOFWSU
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(void)
{
  // create an ifstream object to open and access the file
  ifstream file;
  
  // open the file
  file.open("file.txt");
  
  // exit with an error message and status if the file fails to open
  if (file.fail())
  {
    cout << "File failed to open." << endl;
    return 1;
  }
  
  // create a stringstream object to help read the file contents
  stringstream buffer;
  
  // reads entire contents of the file into the stringstream buffer
  buffer << file.rdbuf();
  
  // create the string to store the file contents
  string file_contents;
  
  // get the string from the stringstream object, store it into the 
  // file_contents string
  file_contents = buffer.str();
  
  // output the file contents
  cout << file_contents;
  
  // close the file
  file.close();

  return 0;
}