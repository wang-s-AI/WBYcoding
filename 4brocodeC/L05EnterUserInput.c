#include <stdio.h>
#include <string.h>

int main() 
{

    int age = 0;                   // %d表示十进制输出    
    float gpa = 0.0f;              // %f表示浮点型输出
    char grade = '\0';             // %c表示字符型输出
    char name[50] = "";            // %s表示字符串输出

    printf("Enter your age: ");
    scanf("%d", &age);             // & 表示取地址
    

    printf("Enter your gpa: ");
 
    scanf("%f", &gpa);                  //%f表示浮点型输出
  
    printf("Enter your grade: ");

    scanf(" %c", &grade);               //%c表示字符型输出

    getchar();                          //清空缓冲区
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);   //fgets表示读取一行 
    name[strlen(name) - 1] = '\0';      //strlen表示字符串长度

    printf("Name: %s\n", &name);        //%s表示字符串输出
    printf("Age: %d\n", &age);          //%d表示十进制输出
    printf("GPA: %.2f\n", &gpa);        //%f表示浮点型输出
    printf("Grade: %c\n", &grade);      //%c表示字符型输出

    return 0;
}