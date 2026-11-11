/*******************************************************************************
* Program: Standard Error Stream Example
* 程序: 标准输出 stdout 与标准错误 stderr 分流
* Description: Example of using the standard error stream in C.
* 描述: 演示为何错误信息必须输出到 stderr，以及在控制台中实现正常与错误日志分离重定向。
* YouTube Lesson: https://www.youtube.com/watch?v=bJmsqBDAuXw
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
 
int main(void)
{
  // In C all input and output occurs over streams with 3 built-in streams 
  // provided: stdin, stdout and stderr.  By default the standard input stream
  // stdin will be keyboard input from the terminal, and the standard output
  // stream stdout and the standard error stream stderr will be text output 
  // to the terminal.  Streams are just an abstraction and they can be 
  // re-directed to things like files.
  
  // printf() will output to stdout, whatever it is set to
  printf("Some ouput\n");
  
  // fprintf() works just like printf() except it accepts a stream as its first
  // argument, so we provide stderr to output to the standard error stream.
  fprintf(stderr, "Error code: %d\n", 415);

  return 0;
}

/* 

Assume the above source code is saved as "d.c" and we compile the file to an 
executable named "d".

Then in the below bash terminal example, we show how we can redirect standard 
output and standard error using > and 2> respectively.  So if our program 
outputs error messages to the standard error stream (and possibly warnings 
and/or log information) then we can separate THAT output from the "regular" 
program output.  This can be useful and is a best practice... e.g. a user can
interact with a program on the terminal while error messages are re-directed 
to a file, OR we could pipe the standard output of one program to the standard
input of another and that other program could trust that no error/etc messages
would be present in the input stream (while the user could potentially still 
observe error messages on the terminal).

$ gcc -o d d.c
$ ./d
Some ouput
Error code: 415
$ ./d > output.txt
Error code: 415
$ cat output.txt
Some ouput
$ ./d 2> errors.txt
Some ouput
$ cat errors.txt
Error code: 415
$ ./d 2> errors2.txt > output2.txt
$ cat errors2.txt
Error code: 415
$ cat output2.txt
Some ouput
$ prog1 | prog2

*/