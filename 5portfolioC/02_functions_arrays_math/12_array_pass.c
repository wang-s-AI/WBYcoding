/*******************************************************************************
* Program: Passing an array to a function
* 程序: 数组作为函数参数传递（数组退化为指针核心机制）
* 程序: 数组作为函数参数传递
* Description: Example of passing an array to a function in C.
* 描述: 深入剖析普通变量的值传递 vs 数组传参时的“数组名退化为首地址指针”机制，以及为何能在函数内直接修改原数组。
* 描述: 演示一维数组作为形参传递时的指针退化机制及通过形参修改原数组元素。
* YouTube Lesson: https://www.youtube.com/watch?v=oe2bZKjiWrg
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>

void add(int x);
void array_add(int array[]);
void array_add_ptr(int *array);

int main(void)
{
  // When we pass a regular variable to a function, what's happening is that 
  // the *value* of that variable is being passed to the function as an 
  // argument, and so the function actually has no access to the variable 
  // in the calling environment, such as 'a' in this case!  We call this 
  // behaviour pass-by-value.
  // 【对比 1：普通变量传参是“值传递（Pass-by-value）”】
  // 传递普通变量 a 时，函数接收到的只是 a 的一份拷贝副本（5）。
  // 子函数 add 无论在内部怎么折腾 x，main 函数里的 a 绝对不会受任何影响！
  int a = 5;
  add(a);

  // 'a' will be left unchanged despite the fact that the function increments 
  // the parameter x
  // 打印显示 a 的值依然保持为 5，未被改变：
  printf("a: %d\n", a);

  // declare an array so that we can pass it to the function
  // 声明一个测试数组：
  int myarray[5] = {1,2,3,4,5};
  
  // Either function call will have the same effect, with myarray[0] beign 
  // incremented by 1 to 2.  When we pass an array to a function, what is 
  // being passed is not all the values of the array, instead of what is being 
  // passed is the memory address of the array.  We say that the array "decays 
  // to a pointer" (pointers store memory addresses).  Because the function 
  // is given a pointer/addres to the array, when it modifies the array, it 
  // will modify it in the calling environment.  We call this pass-by-reference,
  // or more accurately we can call it pass-by-pointer.
  // 【对比 2：数组传参是“地址传递 / 数组退化为指针（Array Decay to Pointer）”】
  // 当把数组 myarray 传给函数时，C 语言【绝对不会】傻傻地把整个数组的元素全部拷贝一份！
  // 而是将数组名自动“退化”为其第一个元素在内存中的起始地址（指针）传递给函数。
  // 因为子函数拿到了真实的内存地址，所以在子函数内对数组的任何修改，
  // 都会直接真实地改变 main 函数里原数组的内容！
  array_add_ptr(myarray);
  // array_add(myarray);
  
  // notice thay myarray[0] will be incremented by 1!
  // 观察打印：myarray[0] 已经被子函数真正修改为了 2！
  printf("myarray[0]: %d\n", myarray[0]);

  // when we use the array name like this, without an index such as myarray[0], 
  // we say it "decays to a pointer" (i.e. a memory address) and so what we 
  // print out here is the memory address that myarray is stored at
  // 打印裸数组名：打印出的就是该数组在内存中的物理地址：
  printf("myarray: %p\n", myarray);

  return 0;
}

// Adds 1 to x, but because the parameter is "pass by value", it will have 
// no effect on a in the calling environment.  All that happens is that a 
// variable called x that is local to the function is set to a a value (5),
// we increment that variable x to 6, and the function is done.  The 'a' 
// variable in main has no relationship to x, it remains unchanged.
void add(int x)
{
  printf("x: %d\n", x);
  x = x + 1;
}

// This function accepts an array as a parameter.  When we pass an array to 
// the function, what will *really* be passed is not the values of the array 
// but the memory address of the array.  This allows the function to modify 
// myarray in main... we call this "pass by reference" (or more accurately 
// pass-by-pointer).
// 形式一：形参写成 int array[]
void array_add(int array[])
{
  // When we output array (without any index like array[0]), it decays to a 
  // pointer (i.e. memory address), and we'll see that the memory address is 
  // the same as the memory address of myarray in main!  When we access this 
  // array with array[0], we are using "array notation" to modify the myarray 
  // in the main function!  In essence array in array_add and myarray in 
  // the main function are the same array. 
  // 打印显示接收到的地址，与 main 函数中的 myarray 地址完全相同！
  printf("array: %p\n", array);

  array[0] = array[0] + 1;
}

// This function is equivalent to the above!  We just use pointer notation to 
// specify the parameter this time. int array[] is the equivalent of int *array!
// Because remember that arrays "decay to pointers" when we don't access them 
// with an index, and so ultimately when we pass the array to a function, we're 
// really passing a pointer (memory address) to the function!
// 形式二：形参写成 int *array
// 【黄金核心重点】：在 C 语言函数形参列表中，int array[] 与 int *array 完全等价！
// 编译器会把参数里的数组语法自动等价转换为指针！
void array_add_ptr(int *array)
{
  printf("array: %p\n", array);
  array[0] = array[0] + 1;
}
