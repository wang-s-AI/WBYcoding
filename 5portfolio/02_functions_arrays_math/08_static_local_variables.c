/*******************************************************************************
* Program: Static Local Variables
* 程序: 静态局部变量 (static local variable) 核心机制
* 程序: static 静态局部变量
* Description: Examples of using a static local variable in C.
* 描述: 演示 static 局部变量如何突破普通局部变量的生命周期限制（仅初始化一次，在函数调用间保持数值持久记忆）。
* 描述: 演示 static 局部变量在函数调用之间持久保持数值的特性与作用域规则。
* YouTube Lesson: https://www.youtube.com/watch?v=Hm5Jc7ajZsk
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

void f();
void log_message(char *message);

int main()
{
  // notice how the value of the variable calls persists across function calls
  // 观察函数 f() 被连续调用三次时，内部静态变量 calls 的数值是如何跨调用持久保存递增的：
  f();
  f();
  f();
  
  // notice how the log messages have a unique, incrementing log message number
  // 实战应用：日志系统中使用静态局部变量自动生成自增唯一的日志序列号：
  log_message("read data");
  log_message("update data");
  log_message("data error");

  return 0;
}

// appends a log message to a file log.txt on a newline with a unique log number
// 将日志信息以独一无二的自增序号追加写入 log.txt 文件
void log_message(char *message)
{
  // Creates a static local variable total to keep track of the number of log 
  // messages, the variable is initialized to 0 only the FIRST time the function
  // is called.  The variable and its value will otherwise persist across all 
  // log_message() function calls!
  // 【静态局部变量的核心特性】：
  // 1. static 局部变量 total 只在整个程序运行期间第一次进入该函数时被初始化一次！
  // 2. 它虽然语法上写在函数体内（作用域受限，外部不可见），但它并不存储在栈（Stack）上，
  //    而是存储在静态数据区（Data Section）中；
  // 3. 因此即使函数执行结束返回，total 的值也不会丢失，下次再调用该函数时，
  //    能直接读到上次保留下来的最新计数值！
  static int total = 0;
  total++;
  
  // open up log.txt and append a line with the log message, using total for 
  // the log message number
  // 打开 log.txt，写入带自增行号的日志记录：
  FILE *logfile = fopen("log.txt", "a");
  if (logfile != NULL)
  {
    fprintf(logfile, "log %d: %s\n", total, message);
    fclose(logfile);
  }
}

void f()
{
  // the static local variable calls will only be initialized to 0 the first 
  // time the function f() is called, on all subsequent calls to f the variable
  // calls and its value will be maintained... notice the results of calling 
  // f() three times in main to see the effect
  // 计数器演示：每次调用 f()，calls 的值都会在上一轮的基础上 +1 并打印：
  static int calls = 0;
  calls++;
  printf("calls: %d\n", calls);
}