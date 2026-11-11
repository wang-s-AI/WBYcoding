/*******************************************************************************
* Program: rename() usage
* 程序: rename 重命名与移动文件
* Description: Example of using rename() to rename a file in C.
* 描述: 演示使用 rename() 修改文件名或在同文件系统间移动文件位置。
* YouTube Lesson: https://www.youtube.com/watch?v=j6PtZ614GZc
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
  // will store the original filename and new filename
  char file[100], new[100];

  // ask the user for the filename, store it into file
  printf("File: ");
  scanf("%s", file);
  
  // ask the user for the new filename, store it into new
  printf("New: ");
  scanf("%s", new);
  
  // if rename() fails it will return a non-zero value
  if (rename(file, new) != 0)
  {
    // output the error number and message
    fprintf(stderr, "Errno: %d\n", errno);
    perror("Error msg");
  
  // if the rename was successful indicate so to the user
  } else printf("%s -> %s\n", file, new);

  return 0;
}