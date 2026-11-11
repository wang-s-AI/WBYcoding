/*******************************************************************************
* Program: Swap Two Variables Using Pointers
* 程序: 使用指针交换两个变量的值
* Description: Swap the values of two variables using pointers in C.
* 描述: 演示经典通过指针形参接收变量地址，并在函数内部交换两变量实际存储值的经典算法。
* YouTube Lesson: https://www.youtube.com/watch?v=ow5BZ0pZaUY
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// Swap the int values pointed to by p1 and p2
void swap(int *p1, int *p2)
{
  // temp variable to help complete the swap
  int temp;
  
  // store the value pointed to by p1 into temp
  temp = *p1;

  // overwrite the value pointed to by p1 with the value pointed to by p2
  *p1 = *p2;

  // store the old value pointed to by p1 (now stored in temp) into the 
  // place in memory pointed to by p2
  *p2 = temp;
}

int main(void)
{
  // variables to swap
  int x = 5;
  int y = 7;

  // test the swap function
  swap(&x, &y); 

  // output the results
  printf("x: %d\n", x);
  printf("y: %d\n", y);

  return 0;
}