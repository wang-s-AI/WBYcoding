/*******************************************************************************
* Program: Write All Vector Elements To A File
* 程序: 将 vector 容器元素批量存盘写入文件
* Description: How to write all the elements of a vector to a file in C++.
* 描述: 演示遍历 vector 容器中的元素并逐行格式化写入持久化文本文件。
* YouTube Lesson: https://www.youtube.com/watch?v=7HXElMVtBu8
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(void)
{
  vector<int> test;

  test.push_back(1);
  test.push_back(2);
  test.push_back(3);

  string filename;

  cout << "Filename: ";
  getline(cin, filename); 

  ofstream outFile;

  outFile.open(filename);

  if (outFile.fail())
  {
    cout << "Error opening file." << endl; 
    return 1;
  }
  
  for (auto element : test)
  {
    outFile << element << endl;         
  }
 
  outFile.close();

  return 0;
}