/*******************************************************************************
* Program: Random number generation
* 程序: 随机数生成 (rand 与 srand)
* Description: Example of generating random numbers in C.
* 描述: 演示使用 rand() 生成伪随机数以及使用 srand(time(NULL)) 设置随机数种子。
* YouTube Lesson: https://www.youtube.com/watch?v=Mp3eGLX-OpY
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
  // seed the random number generator with the current time so the numbers 
  // generated are different each time the program is run
  srand( time(NULL) );

  // generate 6 random numbers between 1-20
  for (int i = 0; i < 6; i++)
  {
    // rand() will produce a random number between 0 and RAND_MAX (a verylarge
    // int value), we modulus the result by 20 to produce a number between 
    // 0-19, and then add 1 to shift the range of random numbers to 1-20
    int random = 1 + (rand() % 20);

    printf("%d\n", random );
  }

  // RAND_MAX is the highest possible random number
  printf("RAND_MAX: %d\n", RAND_MAX);
  
  return 0;
}
