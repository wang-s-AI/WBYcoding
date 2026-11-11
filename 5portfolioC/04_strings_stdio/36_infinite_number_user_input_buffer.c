/*******************************************************************************
* Program: Store An Unknown "Infinite" Amount Of Numbers From User Input
* 程序: 动态未知长度数据输入缓冲
* Description: Example of storing an unknown "infinite" amount of numbers from user input (i.e. "standard input") into a buffer using C.
* 描述: 演示使用动态内存分配连续接收并存储未知数量的用户输入。
* YouTube Lesson: https://www.youtube.com/watch?v=27KzMEnwsEM
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  // Stores pointer to the dynamically allocated buffer
  double *buffer;

  // Create a buffer with an initial size of 32768 double values
  size_t buffer_size = 32768;

  // Allocate space on the heap for a buffer that can store buffer_size amount
  // of double values... we multiply the size in bytes that it takes to store
  // a double by our desired buffer size to get the desired amount of space.
  buffer = malloc(sizeof(double) * buffer_size);

  // Keeps track of the total amount of numbers accepted from user input
  size_t total = 0;

  // Stores each number input by the user
  double input = 0;

  // Accept numbers from standard input 'indefinitely' until some sentinel value
  // is received (in this case, -1).  A sentinel value is a special value that
  // signifies the end of input.
  while (true)
  {
    // Store the next number from user input
    scanf("%lf", &input);

    // If the sentinel value is received, stop accepting numbers by stopping
    // the loop
    if (input == -1) break;

    // Otherwise store the number into the buffer at the next available index
    buffer[total] = input;

    // Increment total to recogonize that another number has been received
    total++;

    // If the total amount of numbers stored matches the buffer size, increase
    // the size of the buffer using realloc()
    if (total >= buffer_size)
    {
      // increment buffer_size and use realloc() to allocate space for the
      // increased size.... realloc() returns a potentially new pointer
      // as its possible the location of our block of memory may need to
      // change as a result of re-sizing the block of memory.
      buffer_size += 32768;
      buffer = realloc(buffer, buffer_size * sizeof(double));
    }
  }

  // Output the contents of the buffer
  for (size_t i = 0; i < total; i++)
    printf("%f\n", buffer[i]);

  // Free the dynamically allocated memory to prevent a memory leak as we
  // are now done working with it
  free(buffer);

  return 0;
}