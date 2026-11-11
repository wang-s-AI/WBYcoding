/*******************************************************************************
* Program: Dot product
* 程序: 向量点积（内积 / 数量积）计算
* 程序: 向量点积运算
* Description: Example of how to compute a dot product in C.
* 描述: C 语言实现两个向量对应分量相乘累加的点积运算（机器人姿态投影与图形学核心基础）。
* 描述: 演示使用一维数组表示向量，并通过循环累加计算两向量的点积（内积）。
* YouTube Lesson: https://www.youtube.com/watch?v=cJybIb_JvuY
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// dot product example
// 点积计算数学模型：
//  v1 = (2, 5, 4)
//  v2 = (3, 2, 1)
//  r = (2 * 3) + (5 * 2) + (4 * 1) = 6 + 10 + 4 = 20 
//

float dot_product(float v1[], float v2[], int length);

int main(void)
{
  // test the dot product function with some example data
  // 准备两个测试三维向量：
  float v1[] = {2,5,4};
  float v2[] = {3,2,1};
  float result = dot_product(v1,v2,3);
  printf("Result: %f\n", result);

  return 0;
}

// accepts two vectors (arrays) as arguments and a length, computes and returns
// the dot product
// 接收两个向量数组与其维度长度，返回点积计算结果标量
float dot_product(float v1[], float v2[], int length)
{
  // we compute the dot product by multiply the correspdoning elements in each 
  // array and adding them to a sum
  // 遍历两个向量，将对应索引位置的分量相乘并累加到总和 sum 中：
  float sum = 0;
  for (int i = 0; i < length; i++)
    sum += v1[i] * v2[i];
  return sum;
}
