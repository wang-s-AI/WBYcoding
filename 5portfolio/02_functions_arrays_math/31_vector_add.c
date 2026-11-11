/*******************************************************************************
* Program: Vector addition
* 程序: 向量加法运算实现
* 程序: 向量加法运算
* Description: Example of vector addition implementation in C.
* 描述: C 语言实现两个同维向量对应分量分别相加并输出结果向量（机器人位移与速度合成基础）。
* 描述: 演示使用一维数组实现对应维度的数学向量加法操作。
* YouTube Lesson: https://www.youtube.com/watch?v=Q075ZhB_8Eo
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// vector addition example
// 向量加法数学模型：
//  v1 = (2, 5, 4)
//  v2 = (3, 2, 1)
//  r = v1 + v2 = (2+3, 5+2, 4+1) = (5, 7, 5)
//

void vector_add(float v1[], float v2[], float result[], int length);

int main(void)
{
  // create some test vectors and a result vector
  // 声明两个输入向量以及一个用于接收结果的目标向量数组：
  float v1[] = {2,5,4};
  float v2[] = {3,2,1};
  float result[] = {0,0,0};

  // perform the vector addition
  // 执行向量加法运算：
  vector_add(v1,v2,result,3);

  // print out the result vector
  // 打印加法合成后的结果向量分量：
  for (int i = 0; i < 3; i++)
    printf("result[%d]=%f\n",i,result[i]);

  return 0;
}

// performs vector addition of vectors v1 and v2 of length 'length', stores the 
// result in the 'result' vector
// 向量加法实现函数：
void vector_add(float v1[], float v2[], float result[], int length)
{
  // We use arrays to model vectors/tuples, and add together the corresponding 
  // elements in v1 and v2 and store the result in the corresponding element 
  // of the result array
  // 使用一维数组对数学向量进行建模，循环将 v1 和 v2 对应分量相加并存入 result[i]：
  for (int i = 0; i < length; i++)
    result[i] = v1[i] + v2[i];
}
