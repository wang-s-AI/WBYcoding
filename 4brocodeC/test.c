#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // 锟街凤拷锟斤拷锟斤拷
    printf("char 锟斤拷小: %zu bytes,", sizeof(char));
    printf("锟斤拷围: %d 锟斤拷 %d\n", CHAR_MIN, CHAR_MAX); // %d 锟斤拷锟斤拷锟斤拷锟斤拷锟街�
    printf("unsigned char 锟斤拷小: %zu bytes,", sizeof(unsigned char));
    printf("锟斤拷围: 0 锟斤拷 %d\n\n",  UCHAR_MAX);
    char uchar= 300;
    printf("%c\n", uchar);

    // 锟斤拷锟斤拷锟斤拷锟斤拷
    printf("short 锟斤拷小: %zu bytes\n", sizeof(short));
    printf("short 锟斤拷围: %d 锟斤拷 %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short 锟斤拷锟街�: %u\n\n", USHRT_MAX);
    printf("int 锟斤拷围: %d 锟斤拷 %d\n", INT_MIN, INT_MAX);
    printf("unsigned int 锟斤拷锟街�: %u\n\n", UINT_MAX);



    printf("long 锟斤拷围: %ld 锟斤拷 %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long 锟斤拷锟街�: %lu\n\n", ULONG_MAX);

    printf("long long 锟斤拷围: %lld 锟斤拷 %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long 锟斤拷锟街�: %llu\n\n", ULLONG_MAX);



    // 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
    printf("float 锟斤拷围: %.6e 锟斤拷 %.6e\n", FLT_MIN, FLT_MAX);
    printf("double 锟斤拷围: %.6e 锟斤拷 %.6e\n", DBL_MIN, DBL_MAX);
    printf("long double 锟斤拷围: %.6Le 锟斤拷 %.6Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}