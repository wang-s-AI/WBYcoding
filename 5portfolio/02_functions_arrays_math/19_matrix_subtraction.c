/*******************************************************************************
* Program: Matrix Subtraction
* 程序: 矩阵减法运算实现
* 程序: 矩阵减法算法
* Description: Implementation of matrix substraction in C.
* 描述: C 语言实现两个同型矩阵对应位置元素相减：C = A - B。
* 描述: 演示使用二维数组实现两个同维度矩阵对应元素相减的计算。
* YouTube Lesson: https://www.youtube.com/watch?v=rPxe7t3fmeo
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// number of rows and columns in our matrices
// 宏定义矩阵的行数 (3) 与列数 (4)
#define ROWS 3
#define COLS 4

void matrix_subtraction(int A[ROWS][COLS],
                        int B[ROWS][COLS],
                        int C[ROWS][COLS]);

int main(void)
{
  // test matrices
  // 两个同维度的测试矩阵 A 和 B (3行4列)：
  int A[ROWS][COLS] =
  { {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2}
  };
  
  int B[ROWS][COLS] =
  { {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
  
  int C[ROWS][COLS];
  
  // We'll perform A - B and store the result into C
  // 执行矩阵减法：C = A - B
  matrix_subtraction(A,B,C);
  
  // output C so we can see if the result is correct
  // 打印输出减法结果矩阵 C：
  for (int i = 0; i < ROWS; i++)
  {
    // outputs a row of values in C, followed by a newline to put the next row 
    // on the next line    
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

// subtracts matrices A and B and stores the result into C
// 矩阵减法实现函数：
void matrix_subtraction(int A[ROWS][COLS],
                        int B[ROWS][COLS],
                        int C[ROWS][COLS])
{
  // subtract each corresponding value in A and B and store the result into 
  // the corresponding value in C
  // 遍历矩阵的每一行 (i) 与每一列 (j)，将 A[i][j] 减去 B[i][j] 的差存入 C[i][j]：
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}
