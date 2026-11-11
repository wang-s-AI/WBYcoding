/*******************************************************************************
* Program: Using remove()
* 程序: remove 删除磁盘文件
* Description: Example of using the remove() function to delete a file in C.
* 描述: 演示使用 remove() 函数根据文件路径从磁盘上删除指定文件。
* YouTube Lesson: https://www.youtube.com/watch?v=jFlyXUskBSI
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
  // stores the filename to delete
  char filename[100];
  
  // ask the user for the filename to delete
  printf("File: ");
  scanf("%s", filename);
  
  // call remove with the filename string as the argument to delete the file, it
  // will return 0 if it is successful
  if (remove(filename) != 0)
  {
    // if there was an error, output the error number and message
    fprintf(stderr, "Errno: %d\n", errno);
    perror("Error msg");

  // if the delete was successful, inform the user the file was deleted
  } else printf("%s deleted.\n", filename);

  return 0;
}