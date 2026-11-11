int main(){
    char a='#';
    char *p=&a;
    printf("\n*** int a=5;int *p=&a;sizeof(a)%d; sizeof(p)%d\n",sizeof(a),sizeof(p));
    printf("1a:变量a的值=%c\n",a);
    printf("2&a:变量a的地址=%p\n",&a);
    printf("3p:指针p的值=%p\n",p);
    printf("4*p:指针p存储的地址指向的值=%c\n",*p);