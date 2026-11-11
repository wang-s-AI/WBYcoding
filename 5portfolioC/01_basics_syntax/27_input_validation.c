/*******************************************************************************
* Program: Input Validation Example
* 程序: 基于 do-while 循环的输入合法性校验
* 程序: 用户输入合法性校验
* Description: Example of performing input validation with a do-while loop in C.
* 描述: 演示在控制台交互程序中，如何使用 do-while 结构反复提示直到用户输入合法数据范围。
* 描述: 演示如何验证用户输入的数据是否符合预期并进行异常输入过滤。
* YouTube Lesson: https://www.youtube.com/watch?v=IDIJXsZRqP4
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

int main()
{
  int day = 0;
  
  do
  {
    // ask the user to enter a day between 1-31
    // 提示用户输入一个月中的合法日期（1 到 31）：
    printf("Enter day of the month (1-31): ");
    scanf("%d", &day);
    
    // if the day is out of range, inform the user
    // 如果输入的数值超出合法范围（小于 1 或 大于 31），向用户打印错误警告提示：
    if (day < 1 || day > 31)
      printf("Error day must be between 1-31\n");
  
  // keep asking the user to enter a day until they enter one that is in range
  // 校验循环条件：只要输入的数值依然不合法，就持续循环让用户重新输入，直到输入合法为止！
  } while (day < 1 || day > 31);
  
  // output the day of the month once a valid day has been entered
  // 只有通过了上述严格校验，程序才会向下放行，打印出最终合法的日期数值：
  printf("Day of the month: %d\n", day);
  
  return 0;
}
