/*******************************************************************************
* Program: Matrix Addition
* 程序: 矩阵加法运算实现
* 程序: 矩阵加法算法
* Description: Implementation of matrix addition in C.
* 描述: C 语言实现两个同型矩阵对应位置元素相加（线性代数与机器人齐次变换计算基础）。
* 描述: 演示使用嵌套循环对两个同阶二维数组（矩阵）进行对应元素相加。
* YouTube Lesson: https://www.youtube.com/watch?v=Jtn_NXLvbAQ
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// number of rows and columns in our matrices
// 宏定义测试矩阵的行数 (3) 与列数 (4)
#define ROWS 3
#define COLS 4

void matrix_addition(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]);

int main(void)
{
  // test matrices
  // 两个同维度的测试矩阵 A 和 B (3行4列)：
  int A[ROWS][COLS] =
  { {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
 
  int B[ROWS][COLS] =
  { {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2}
  };
  
  // We'll add together A and B and store the result into C
  // 声明结果矩阵 C，用于接收计算结果：C = A + B
  int C[ROWS][COLS];
  
  matrix_addition(A,B,C);
  
  // output C so we can see if the result is correct
  // 双重循环网格化打印相加后的矩阵 C：
  for (int i = 0; i < ROWS; i++)
  {
    // outputs a row of values in C, followed by a newline to put the next row 
    // on the next line
    // 逐行输出元素，每行结束打印一个换行符 \n：
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

// adds matrices A and B and stores the result into C
// 矩阵相加实现函数：
void matrix_addition(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
  // add together each corresponding value in A and B and store the result into 
  // the corresponding value in C
  // 遍历矩阵的每一行 (i) 与每一列 (j)，将 A 和 B 对应位置的元素相加并存入 C[i][j]：
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}