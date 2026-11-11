// This program demonstrates the declaration, initialization, and manipulation of integer variables in C.

#include <stdio.h>

int main()
{
    int sofa_money; // Declare an integer variable named sofa_money
    sofa_money = 100; // Assign the value 100 to the variable sofa_money

    int tv_money = 200; // Declare and initialize an integer variable named tv_money with the value 200
    int closet_money = 0; // Declare and initialize an integer variable named closet_money with the value 0
    int bookshelf_money=tv_money; // Declare an integer variable named bookshelf_money and initialize it with the value of tv_money (200)
    
    sofa_money = sofa_money + 50; // Update sofa_money by adding 50 to its current value
    // %d: Format specifier for integers.
    printf("Sofa money: %d\n", sofa_money); 
    
    printf("TV money: %d\n", tv_money);
    printf("Closet money: %d\n", closet_money); 
    printf("Bookshelf money: %d\n", bookshelf_money); 
    // %zu is the correct format specifier for size_t, but %lu 在一些情况下也适用.
    // %zu and %lu are both used to print the size of data types in bytes, but %zu is the correct format specifier for size_t, which is the type returned by sizeof operator.
    printf("Size of short int: %zu bytes\n", sizeof(short int)); 
    printf("Size of sofa_money: %lu bytes\n", sizeof(sofa_money));

    char letter1='c'; // Declare a char variable named letter1 and initialize it with the character 'c'
    printf("letter1:char %c,=ASCII %d,size %zu\n", letter1, letter1, sizeof(letter1));
    char letter2='B'; // Declare a char variable named letter2 and initialize it with the character 'B'
    printf("letter2:char %c,=ASCII %d,size %zu\n", letter2, letter2, sizeof(letter2));
    
    printf("Size of char: %zu bytes\n", sizeof(char)); // Print the size of the char data type in bytes 

    printf("Size of short int: %zu bytes\n", sizeof(short int)); // Print the size of the short int data type in bytes 
    printf("Size of unsigned short int: %zu bytes\n", sizeof(unsigned short int)); // Print the size of the short int data type in bytes 
    printf("Size of int: %zu bytes\n", sizeof(int)); // Print the size of the short int data type in bytes 
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int)); // Print the size of the short int data type in bytes
    printf("Size of long int: %zu bytes\n", sizeof(long int)); // Print the size of the short int data type in bytes 
    printf("Size of unsigned long int: %zu bytes\n", sizeof(unsigned long int)); // Print the size of the short int data type in bytes
    printf("Size of long long int: %zu bytes\n", sizeof(long long int)); // Print the size of the short int data type in bytes 
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsigned long long int)); // Print the size of the short int data type in bytes 

    printf("Size of size_t: %zu bytes\n", sizeof(size_t)); // Print the size of the short int data type in bytes

    printf("Size of float (unsigned is invalid in C): %zu bytes\n", sizeof(float)); // Print the size of the float data type in bytes
    printf("Size of double: %zu bytes\n", sizeof(double)); // Print the size of the double data type in bytes
    printf("Size of long double: %zu bytes\n", sizeof(long double)); // Print the size of the short int data type in bytes

    return 0;
}