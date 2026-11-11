/*******************************************************************************
* Program: 2D array examples
* 程序: 二维数组与矩阵乘法实战教程
* 程序: 二维数组概念与操作
* Description: Examples of working with 2D arrays in C.
* 描述: 二维数组声明、行列双重循环输入输出、多维数组作为函数形参传递以及矩阵相乘 (Matrix Multiplication) 算法。
* 描述: 演示 C 语言中二维数组的声明、内存连续存储特性与按行列索引访问。
* YouTube Lesson: https://www.youtube.com/watch?v=ZUPfWzTlPbE
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// we can use constants to define the size of 2D arrays, this can help us to 
// write code (e.g. loops) that will still work if we need to change the size 
// of the 2D array later
// 使用宏定义矩阵的行与列维度，后续如果矩阵规模变动，只需改动这几行常数即可：
#define ROWS 3
#define COLS 3

// dimensions of our matrices
// 矩阵相乘的三个维度：A 为 M x N，B 为 N x P，乘积 C 为 M x P
#define M 3
#define N 4
#define P 5

// We specify the dimensions of the 2D arrays in our parameters... in this case
// we specify BOTH the row and column, there are a few other ways we can pass 
// 2D arrays to functions but this is a common way.
// 二维数组作为形参时，必须指定第二维（列数）的大小，以便编译器能够正确计算寻址步长：
void matrix_mult(int c[M][P], int a[M][N], int b[N][P]);

int main(void)
{
  // delcare the array
  // 声明一个 3 行 3 列的二维整型数组
  int a[ROWS][COLS];

  // use scanf to accept user input to initialize the array elements
  // 双重嵌套 for 循环：外层遍历行 (i)，内层遍历列 (j)，提示用户逐个元素输入：
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
    {
      printf("Enter a[%d][%d]=",i,j);
      scanf("%d", &a[i][j]);
    }

  // print out all elements of the array
  // 双重嵌套循环遍历打印二维数组内容：
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      printf("a[%d][%d]=%d\n",i,j,a[i][j]);

  // initialize 2D arrays representing matrices to be multiplied
  // 初始化两个测试矩阵 A (3x4) 和 B (4x5)：
  int A[M][N] = { {1,2,3,4},
                  {4,5,6,7},
                  {8,9,10,11} };

  int B[N][P] = { {1,1,1,1,1},
                  {1,1,1,1,1},
                  {1,1,1,1,1},
                  {1,1,1,1,1} };

  int C[M][P] = { {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0} };

  // perform the matrix multiplication
  // 执行矩阵乘法计算：C = A * B
  matrix_mult(C,A,B);

  // print out the result matrix C
  // 打印输出最终结果矩阵 C (3x5)：
  printf("\n\n\n");
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      printf("C[%d][%d]=%d\n",i,j,C[i][j]);

  return 0;
}

// Performs a matrix multiplication of a and b, stores result into c
// 矩阵相乘核心实现函数：
void matrix_mult(int c[M][P], int a[M][N], int b[N][P])
{
  // Our code below depends on c[i][j] being 0, so initialize it to 0 
  // just to be sure (this could actually be done *in* the below loops too, 
  // which would be more efficient!)
  // 首先将结果矩阵清零：
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      c[i][j] = 0;
  
  // perform the matrix multiplication
  // 经典三重循环算法：
  // i 循环遍历 A 的每一行
  // j 循环遍历 B 的每一列
  // k 循环计算 A 第 i 行与 B 第 j 列的点积累加：c[i][j] += a[i][k] * b[k][j]
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      for (int k = 0; k < N; k++)
        c[i][j] += a[i][k] * b[k][j];
}
