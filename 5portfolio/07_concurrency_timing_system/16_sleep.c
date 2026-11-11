/*******************************************************************************
* Program: Sleep
* 程序: 进程休眠延时
* Description: Example of using sleep functions in C.
* 描述: 演示使用 sleep() 让当前执行进程暂停指定秒数。
* YouTube Lesson: https://www.youtube.com/watch?v=SjOPUr7Bkmo
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
  // printf before and after sleep functions to see the sleep time
  printf("before\n");

  // usleep will sleep for the number of microseconds given, a very small unit 
  // of time... the below will sleep for 0.75 seconds
  usleep(750000);

  // will sleep for 5 seconds
  // sleep(5);

  printf("after\n");

  return 0;
}
