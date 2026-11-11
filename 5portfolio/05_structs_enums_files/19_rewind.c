/*******************************************************************************
* Program: rewind() function
* 程序: rewind 快速重置文件指针
* Description: Example of using the rewind() function in C.
* 描述: 演示使用 rewind() 将文件流指针极速复位到文件开头并清除错误标志。
* YouTube Lesson: https://www.youtube.com/watch?v=btq2nirO6f8
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main()
{
  FILE *file;

  // open the file data.txt for reading
  file = fopen("data.txt", "r");
  
  // if there was a problem opening the file, tell the user and exit 
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // read and output all file content until the file pointer reaches the 
  // end of the file
  char c;
  while ( (c = fgetc(file)) != EOF)
    printf("%c", c);
  printf("\n");

  // rewind the file pointer back to the beginning of the file!
  rewind(file);
  
  // we can now read and output the file contents again
  while ( (c = fgetc(file)) != EOF)
    printf("%c", c);
  printf("\n");
  
  // close the file pointer
  fclose(file);
 
  return 0;
}
