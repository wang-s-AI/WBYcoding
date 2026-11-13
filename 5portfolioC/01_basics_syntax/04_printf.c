/*******************************************************************************
* Program: printf tutorial
* 程序: printf 格式化输出详解
* Description: Examples of using printf.
* 描述: 演示 printf 函数中常用格式占位符 (%d, %f, %c, %s 等) 的用法。
* YouTube Lesson: https://www.youtube.com/watch?v=ycKZKDCMMzM
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

// Printf placeholder structure (simplified):
// %[flags][width][.precision][length]specifier
// Wikipedia article gives full coverage of all possibilities (pretty 
// extensive): https://w.wiki/3VtV
//

int main(void)
{
  // Basic examples of printf with special characters for newline, tab, etc.
  printf("Hello, World! \n");
  printf("\tAnother line of text!\n"); // \t is a tab character
  //在操作系统控制台（CMD、PowerShell、Linux Terminal 等）的历史标准中，默认制表
  //位（Tab Stop）通常是 8 个字符。\t 不是“固定输出空格”，而是“跳到下一个制表位”终
  //端的屏幕在横向上被预设了固定间隔的网格点（通常为第 0、8、16、24...列）

  printf("double quote: \" \n");       // \" is a double quote character
  printf("single quote: \' \n");       // \' is a single quote character
  printf("backslash: \\ \n");          // \\ is a backslash character

  // using %d placeholders to output ints (placeholders占位符%d, %f, %c, %s)
  //一个小细节： 在 printf 中，float 类型的参数会被自动隐式转换为 double，因此输
  //出 float 和 double 都可以直接使用 %f（使用 %lf 也是兼容的标准写法）。但在后
  //续学到接收输入的 scanf 时，float 必须用 %f，而 double 必须严格使用 %lf。
  int x = 5;
  printf("x: %d \n", x );
  printf("%d, %d, %d \n", x, x+1, x+2 );

  // examples for char, double, float and strings
  char c = 'Q';
  printf("c: %c\n", c);        //单个字符 (char)

  double y = 4.56;
  printf("y: %f \n", y);       //浮点数 (float / double)

  float z = 2.5;
  printf("z: %f \n", z);       //浮点数 (float / double)

  char str[] = "A string to output!\n";
  printf("str: %s", str);     //字符串 (char[] / char*)
  // examples of using width, precision, etc, placeholder fields to alter output 
  printf("|||%-10d|||\n", 5);
  printf("|||%-8.3f|||\n", y);
//length长度修饰符）默认的占位符（如 %d）默认对应标准大小的数据（通常是 32 位的普通 int）。
//但有些类型占用的内存更大（比如 64 位整数）或有特殊类型，这时就必须用 length 修饰符来告
//诉 printf “请按多大的内存长度去读取这个变量”。修饰符ll，l，z	完整写法%lld，%ld，%zu
// 例如：
  long long int mybigint = 1234567890123456789; 
  printf("%lld\n", mybigint);
  long long big_number = 9876543210123LL;
  printf("大数字: %lld\n", big_number);

// 打印变量或类型占用的字节数（sizeof 返回 size_t 类型）
  printf("int 占用的，字节数: %zu\n", sizeof(int));
  printf("double 占用的字节数: %zu\n", sizeof(double));
  printf("The size of a float in bytes %zu\n", sizeof(float));
  printf("The size of a char in bytes %zu\n", sizeof(char));
  printf("The size of a long long in bytes %zu\n", sizeof(long long));

  return 0;
}
