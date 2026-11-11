#include <stdio.h>
#include <string.h>

int main() {

    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[50] = "";

    printf("Enter your age: ");
    scanf("%d", &age);
    //& 是取地址运算符，用于获取变量 age 的内存地址

    printf("Enter your gpa: ");
    //当用户输入 4.1 并按下回车键后，标准输入缓冲区中的原始内容为：4.1\n
    scanf("%f", &gpa);
    //%f 格式说明符会读取并解析一个浮点数（跳过开头的空白字符，但这里开头就是 4）。
    //它依次读取 '4', '.', '1'，将其转换为浮点数 4.1 并存入变量 gpa。
    //最终缓冲区剩余内容\n

    //scanf("%c", &grade)会直接读取上一个缓冲区4.1\n残余的\n
    printf("Enter your grade: ");
    //用户输入字母 A 并按下回车键后，标准输入缓冲区中的内容为：A\n
    scanf(" %c", &grade); // The space before %c is to consume any leftover \n.

    getchar(); // clears \n from input buffer
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0'; //changes last char from \n to \0

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);

    return 0;
}