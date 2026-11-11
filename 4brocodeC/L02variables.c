#include <stdio.h>
#include <stdbool.h>

int age= 99;                                  //age有过全局变量定义99
char grade;                                   //grade全局变量未定义值其默认值是 0（即空字符 '\0'）。 

int main() {

    // variable = A reusable container for a value.
    //                   Behaves as if it were the value it contains.

    // int = whole numbers (4 bytes in modern systems)
    // float = single-precision decimal number (4 bytes)
    // double = double-precision decimal number (8 bytes)
    // char = single character (1 byte)
    // char[] = array of characters (size varies)
    // bool = true or false (1 byte, requires <stdbool.h>)

    printf("You are %d years old\n", age);    //age有过全局变量定义99

    int age = 21;                             //age重新定义了局部变量21
    int year = 2025;
    int quantity = -1;

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("You have ordered %d x items\n", quantity);
    printf("The year is %+d\n", year);          //%+ The year is +2025

    float gpa = 2.5;
    float price = 19.99;
    float temperature = -10.1;

    printf("The price is $%f\n", price);
    printf("Your gpa is %f\n", gpa);
    printf("The temperature is %f°F\n", temperature); 
    printf("Your gpa is %0.3f\n", gpa);         //%0.3f Your gpa is 2.500


    //double e;     //局部变量（函数内部定义）如果不初始化，其值是未定义的（垃圾值）
    //printf("The value of e is %lf\n", e);   //会报错

    double pi = 3.14159265358979;
    double e = 2.7182818284590;
    printf("The value of pi is %f\n", pi);
    printf("The value of pi is %lf\n", pi);
    printf("The value of pi is %.20lf\n", pi);
    printf("The value of e is %lf\n", e);
    printf("The value of e is %.11lf\n", e);
    printf("The value of pi is %f\n", pi);      //使用非对应占位符f
    printf("The value of pi is %c\n", pi);      //使用非对应占位符c
    printf("The value of pi is %d\n", pi);      //使用非对应占位符d

    /*绝大多数十进制小数无法在二进制中精确表示，只能存储为一个近似值。
    当你用 %.20lf 打印时，printf 会把这个二进制近似值还原为十进制，
    并显示出小数点后 20 位。于是你就看到了实际存储的值：其中 000737 
    这些“额外的”数字并不是“补充”上去的，而是因为存储的二进制值对应的
    十进制真值就是那个样子，它与你写的 3.14159265358979 有一个极小
    的误差（约 7.37e-16）。*/

    printf("Your letter grade is %d\n", grade); //grade全局变量未定义值其默认值是 0（即空字符 '\0'）。输出 0
    printf("Your letter grade is %c\n", grade); //grade全局变量未定义值其默认值是 0（即空字符 '\0'）。输出空字符，看不到任何显示

    char passkey;                               //grade局部变量未定义值    
    printf("The passkey is %c\n", passkey);

    char grade = 'A';                                //char类型是以ASCII码存储的,可以互相转换
    char symbol = '!';
    char currency = '$';

    printf("Your letter grade is %c\n", grade);
    printf("%c is your favorite symbol\n", symbol);
    printf("The currency is in %c\n", currency);
    printf("Your letter grade is %d\n", grade);
    printf("%d is your favorite symbol\n", symbol);
    printf("The currency is in %d\n", currency);
    int mark = 65;                                 //char类型是以ASCII码存储的,可以互相转换
    printf("Your mark is %c\n", mark);

    char name[] = "Bro Code";
    char food[] = "pizza";
    char email[] = "fake123@gmail.com";
   
    printf("Hello %s\n", name);
    printf("Your favorite food is %s\n", food);
    printf("Your email is %s\n", email);

    bool isOnline = true;

    bool isStudent = false;
    bool forSale = true;

    if(isOnline){
        printf("You are online");
    }
    else{
        printf("You are offline");
    }
   
    return 0;
}