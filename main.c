#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test07();

//太过于细节，那么学习的内容就会很多，时间有限，以核心的为主

//问题收集（练习就会了）
//1.clion环境配置（乱码）
//2.指针的基本用法
//3.数组指针和指针数组

//指针与一维二维数组的关系
//1.定义二维数组，可以省略行的前提
    //只有对全部元素赋初值时，那么第一维的长度才可以不给出，否则定义是错的

void test01() {
    printf("指针第二次练习-一维数组与指针\n");
    printf("只要弄明白指针，其它的就很容易\n");

    //定义空指针:给初始化指针赋值为NULL
    int *ptr_i = NULL;

    //此时，若使用*ptr_i，系统会报错
//    printf("ptr_i=%p\n",*ptr_i);    //exit code -1073741819 (0xC0000005)
    printf("===========================\n");

    //定义通用的指针
//    void *ptr_v =

    char c;
    short s;
    int n;

    //定义 int char short 类型的指针
    char *ptr_c = &c;
    short *ptr_s = &s;
    int *ptr_n = &n;

    //这种输出方式不好推算
    //ptr_n=000000000061FDBC
    //ptr_c=000000000061FDBB
    //ptr_s=000000000061FDB8

    //ptr_c=000000000061FDBF    ===>推算出short占2个字节
    //ptr_s=000000000061FDBC    ===>推算出int占4个字节
    //ptr_n=000000000061FDB8
    printf("ptr_c=%p\n",ptr_c);
    printf("ptr_s=%p\n",ptr_s);
    printf("ptr_n=%p\n",ptr_n);
    printf("=====================\n");

    void *ptr_v = ptr_n;
    //把一个整型指针转化成了一个通用指针，地址不会改变，但是类型信息丢失
    printf("ptr_v=%p\n",ptr_v);
    //转回去 又可以使用了
    int *ptr_n_i = (int*)ptr_v;
    printf("ptr_n_i=%p\n",ptr_n_i);

    //ptr_v转成另外一种指针存在的问题
//    double *ptr_d = (double*)ptr_v;
    //语法正确，存在语义错误，编译器（不同的编译器表现的问题可能不同）无法识别
//    printf("ptr_d=%p\n",ptr_d);
}

void test02() {

    int n = 10;
    char c = 'a';
    short s = 11;

    //定义 int char short 类型的指针
    int *ptr_n = &n;
    char *ptr_c = &c;
    short *ptr_s = &s;

    printf("ptr_n=%p\n",ptr_n);
    printf("ptr_c=%p\n",ptr_c);
    printf("ptr_s=%p\n",ptr_s);

}

void test03() {
    printf("指针的算术运算\n");
    printf("只能做+，-，++，--，+=，-=，类型需要一样\n");
    int i = 100;
    int *ptr_i = &i;
    printf("ptr_i=%p\n",ptr_i);
    printf("ptr_i+1=%p\n",ptr_i + 1);
    printf("ptr_i+2=%p\n",ptr_i + 2);

    printf("===========================\n");

    short c = 100;
    short *ptr_c = &c;
    printf("ptr_c  =%p\n",ptr_c);
    printf("ptr_c+1=%p\n",ptr_c + 1);
    printf("ptr_c+2=%p\n",ptr_c + 2);

    printf("===========================\n");

    //void的长度1
    printf("sizeof(void)=%d\n",sizeof(void));
}

void test04() {

    printf("指针与一维数组\n");
    int array[] = {1,2,3,4,5};
    printf("数组名就是数值的起始地址，也就是第一个元素的地址\n");
    printf("数组名就是一个常量指针\n");

    printf("数组名=%p\n",array);

    int *ptr_array = array;
    printf("ptr_array=%p\n",ptr_array);

    printf("===========================================\n");
    printf("*数组名就是数组第一个元素\n");
    printf("*array = %d\n",*array);
    printf("===========================================\n");
    printf("查看第一个元素的地址值\n");
    printf("&array[0] = %p\n",&array[0]);
    printf("===========================================\n");
    printf("改变第二个元素地址所对应的值\n");
    ptr_array[2] = 100;
    printf("array[2] = %d\n",array[2]);
    printf("===========================================\n");
    printf("查看第四个元素的值\n");
    *(ptr_array + 3) = 300;
    printf("array[3] = %d\n",array[3]);
    printf("*(array + 3) = %d\n",*(array + 3));
    printf("*&array[3] = %d\n",*&array[3]);

    printf("*(ptr_array+3) = %d\n",*(ptr_array+3));
    printf("ptr_array[3]=%d\n",ptr_array[3]);
    printf("*&(ptr_array[3])=%d\n",*&(ptr_array[3]));

    printf("===========================================\n");
    printf("查看第四个元素的地址值\n");
    printf("&(ptr_array[3])=%p\n",&(ptr_array[3]));
    printf("&ptr_array[3]=%p\n",&ptr_array[3]);
    printf("ptr_array + 3 =%p\n",ptr_array + 3);
    printf("array + 3 = %p\n",array + 3);
    printf("&array[3] = %p\n",&array[3]);
}

//指针数组和数组指针的区别：https://www.cnblogs.com/mq0036/p/3382732.html
//经常性地反复查看

//1.()、[]、*三者优先级前者最高，*最低
//2.数组指针只是一个指针变量，它占有内存中一个指针的存储空间；指针数组是多个指针变量，占有多个指针的存储空间；
//3.数组指针（也称行指针）
//定义 int (*p)[n];
//p+1时，p要跨过n个整型数据的长度(这一点比较重要)
//4.指针数组
//定义 int *p[n];
//p+1时，则p指向下一个数组元素(这一点比较重要)
//5.其它细节，见上方博客内容
//笔记中有 对 数组指针和指针数组更简洁的 描述

void test05() {
    printf("数组指针跟指针数组\n");
    int array[] = {1,2,3,4,5};
    int *ptr_array = array;

    printf("数组的初始地址，即数组第一个元素的地址\n");
    printf("array    =%p\n",array);
    printf("&array   =%p\n",&array);
    printf("&array[0]=%p\n",&array[0]);
    printf("ptr_array=%p\n",ptr_array);

    //* [] ():三者优先级逐渐变高
    // int (*ptr_array)[5] 数组指针
    // int *ptr_arr[5]  指针数组
    printf("===============================\n");
    printf("array + 1  = %p\n",array + 1);          //数组中第2个元素的地址
    printf("&array[1]  = %p\n",&array[1]);
    printf("===============================\n");
    printf("&array + 1 = %p\n",&array + 1);         //跨过5个整型数据的长度
}

void test06() {

    int array[] = {1,2,3,4,5};
    printf("array  = %p\n",array);
    printf("&array = %p\n",&array);

    printf("===========================\n");

    //todo 待研究的问题  使用文本编辑器 会发生报错，但是clion却没有
    //int *ptr_array = &array;
//    printf("ptr_array = %p\n",ptr_array);

    printf("array     = %p\n",array);
    printf("array + 1 = %p\n",array + 1);
    printf("===========================\n");

    //定义数组指针
    int (*ptr_array)[5] = &array;
    printf("ptr_array = %p\n",ptr_array);
    printf("===========================\n");        //000000000061FDC0
    printf("ptr_array + 1 = %p\n",ptr_array + 1);   //000000000061FDD4
    printf("===========================\n");

    for (int i = 0;i < 5;i++){
        printf("array[%d]=%d, *(array + %d) = %d\n",i,array[i],i,*(array + i));
        printf("&array[%d]=%p, array+%d=%p\n",i,&array[i],i,array+i);
    }

    printf("===========================\n");

    int *p = NULL;
    for(p = array;p < array + 5;p++){
        printf("p = %p, *p = %d\n",p,*p);
    }

}

float aver(float a[],int n){
    float sum = a[0],pingjunshu;
    int i;
    for(i=1;i<n;i++){
        sum = sum + a[i];
    }
    pingjunshu=sum/n;
    return pingjunshu;
}

float aver(float a[],int n);
//？第2组的成绩在控制台未输完就限制了输入，原因不明
void test07() {

    float zu1[5],zu2[10];
    int i;
    printf("请输入第1组的学生成绩:\n");
    for(i = 0;i<=4;i++){
        scanf("%f",&zu1[i]);
    }
    printf("请输入第2组的学生成绩:\n");
    for(i = 0;i<=9;i++){
        scanf("%f",zu2[i]);
    }

    printf("第1组平均分是%f\n",aver(zu1,5));
    printf("第2组平均分是%f\n",aver(zu2,10));
}

//指针与一维二维数组之间的关系
void test08(){
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);     //ptr是未知的，只知道地址的位置
    printf("%d,%d",*(a + 1),*(ptr - 1));    //a[1] = 2，a[4] = 5
}

void test09(){
    char *color[] = {"red","green","blue"};     //指针数组保存的是字符串地址
    //读内容
    //是否可以写？
    //跟平台相关  结果可能会不同  变化的才是正确的
    for(int i = 0;i < 3;i++){
        puts(color[i]);
        printf("color[%d]=%p\n",i,&color[i]);
        color[i] = "color";
        printf("color[%d]=%p\n",i,&color[i]);
    }

    //指针指向二维数组的行变量

}

//指针变量指向二维数组的行变量

//指针的指针（二级指针）：http://c.biancheng.net/view/2016.html
//二级指针的作用详解：https://blog.csdn.net/majianfei1023/article/details/46629065?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-9.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-9.control
//用处：
//eg：查找的函数
//

void test11(){
    int i = 100;
    int *pInt = &i;
    int **ppInt = &pInt;       //指针的指针
    printf("i       = %d\n",i);
    printf("*pInt   = %d\n",*pInt);
    printf("**ppInt = %d\n",**ppInt);
}

//https://blog.csdn.net/daimous/article/details/71436825
//用变量a给出下面的定义
//a) 一个整型数
//int a;
//b) 一个指向整型数的指针
//int *a;
//c) 一个指向指针的的指针，它指向的指针是指向一个整型数
//int **a;
//d) 一个有10个整型数的数组
//int a[10];
//e) 一个指向有10个整型数数组的指针
//int (*a）[10];
//f) 一个有10个指针的数组，该指针是指向一个整型数的
//int *a[10];
//g).指针函数
//int *p（int i）:返回值为指针类型的函数;
//h).函数指针
//int（*p）（int i）:是指向一个返回值为int型的指针;

//指针函数与函数指针:https://blog.csdn.net/ameyume/article/details/8220832
//指针函数就是返回一个地址给调用者，用于需要地址的情况

int max(int a,int b){
    return a > b ? a : b;
}

//声明函数指针,这里的返回值是int类型，返回值可以是指针
int (*f)(int,int);
//函数指针的调用
void test12() {
    printf("使用函数指针：计算最大值\n");
    f = max;
    int c = (*f)(1,2);
    printf("max = %d\n",c);
}

//函数的回调
int call(int x,int y){
    return x + y;
}
//第三个参数是函数指针
int test13(int i1,int i2,int (*callback)(int,int)){
    return callback(i1,i2);
}

void test14(int array[]){
    printf("将数组名直接作为参数传递的情况:\n");
    printf("sizeof = %d\n", sizeof(array));
}

//指针变量指向二维数组的行
void test15(){
    float fenshu[3][4] = {{65,67,70,60},{65,67,70,60},{65,67,70,60}};
    float (*ptr)[4] = fenshu;   //指针指向二维数组的行
    //遍历二维数组的每一个元素
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            //ptr + i：第i行
            //*(ptr + i):第i行第一个元素
            //*(ptr + i) + j:第i行第j个元素的地址
            //*(*(ptr + i) + j):第i行第j个元素的值
            printf("第%d行，第%d列，值为：%f\n",(i+1),(j+1),*(*(ptr + i) + j));
        }
    }
}

//字符串定义的三种方式
//字符串 拼接    todo

void test18(){
    //C语言的字符串，就是字符数组
    //C语言字符串用字符数组表示

    printf("字符串的三种定义方式\n");

    //特殊的字符数组(字符串)
    char str[10] = {'h','e','l','l','o','\0'};

    //'\0'可以省略
    char str1[10] = "hello";

    //指针str2是在栈中，"hello"是在常量池，该种方式定义的字符串只能读（同上面2种的区别）
    char *str2 = "hello";

    //打印查看效果
    printf("str =%s\n",str);
    printf("str1=%s\n",str1);
    printf("str2=%s\n",str2);
}

void test19(){
    //todo 输入一个字符串

}

void test20(){
    //给字符数组赋值

    char str[10] = "abc";

//    int i;
//    for(i= 0; i < 10; i++){
//        str[i] = 'i';
//    }

    printf("str=%s\n",str);

    printf("sizeof(str)=%d\n", sizeof(str));
    printf("strlen(str)=%d\n", strlen(str));

}

//常量指针：指针的地址可以改变，但是指针指向的值不可以改变
//指针常量：指针所指向的地址不可以改变

//结构体
//结构体初始化
//结构体的访问
//结构体对象定义成指针：
    //1.指针 -> 成员变量
    //2.(*指针).成员变量

//共用体定义
//共用体的访问
//指针形式 同上
//共用体和结构体长度的计算，使用sizeof就行(很少会让我们去手动计算其大小，如何人工计算[对齐]暂时不用去了解)
union Data{
    int i;
    float f;
    char str[20];
};

void test17(){
    union Data data;

}

int main(){
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
//    test09();
//    test11();

    //    test12();
//    printf("result = %d\n",test13(10,20,call));

//    int array[] = {1,2,3,4,5};
//    test14(array);

//    test15();
//    test18();
    test20();

    return 0;
}































//=======================================================指针练习1========================================
//coding:指针的基本操作代码练习

//1.指针是一种特殊的变量，保存另一个变量的地址
//void test01();
//
//void test02();
//
//void test03();
//
//void test04();
//
//void test05();
//
//void main() {
////    test01();
////    test02();
////    test03();
////    test04();
//    test05();
//}
//
//void test05() {
//    int i = 111;
//    int j = 333;
//    int k = 555;
//
//    int *ptr_i = &i;
//    int *ptr_j = &j;
//    int *ptr_k = &k;
//    /*分配所需的内存空间，并返回一个指向它的指针。*/
//    ptr_i = (int*)malloc(sizeof(int));    //使用malloc函数在堆上分配了一块内存给ptr_i
//    printf("%p\n",&ptr_i);
//    printf("========================\n");
//    /*分配所需的内存空间，并返回一个指向它的指针。*/
//    ptr_j = (int*)calloc(8,sizeof(int));    //要被分配的元素个数,元素的大小
//    printf("%p\n",&ptr_j);
//    printf("========================\n");
//    /* 最初的内存分配 */
//    ptr_k = (int*)malloc(sizeof(int));
//    /* 重新调整之前调用 malloc 或 calloc 所分配的 ptr(第一个参数) 所指向的内存块的大小。 */
//    ptr_k = (int*)realloc(ptr_k,15);
//    printf("%p\n",&ptr_k);
//    printf("========================\n");
//}
//
//void swap(int x,int y);
//void swap1(int* x,int* y);
//void test04() {
//    int a = 2,b = 3;
//    printf("666: a= %d, b= %d\n",a,b);
//    swap(a,b);
//    printf("666: a= %d, b= %d\n",a,b);
//
//    printf("========================\n");
//    a = 20,b = 30;
//    printf("888: a= %d, b= %d\n",a,b);
//    printf("888: &a= %p, &b= %p\n",&a,&b);
//    swap1(&a,&b);
//    printf("888: a= %d, b= %d\n",a,b);
//
//}
//
//void swap(int x,int y){
//    printf("111: x= %d, y= %d\n",x,y);
//    int tmp = x;
//    x = y;
//    y = tmp;
//    printf("111: x= %d, y= %d\n",x,y);
//}
//
////x，y是指针变量
//void swap1(int* x,int* y){
//    printf("333: x= %p,y = %p\n",x,y);
//    printf("333: x= %d,y = %d\n",*x,*y);    //用于访问指针所指向的地址的值
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//    printf("555: x= %p,y = %p\n",x,y);
//    printf("555: x= %d,y = %d\n",*x,*y);
//}
//
//void test03() {
//    int i = 111;
//    int j = 333;
//
//    int *ptr_i = &i;
//
//    printf("%p\n",&ptr_i);
//    printf("%p\n",ptr_i);
//    printf("%p\n",&i);
//    printf("%p\n",&j);
//    printf("========================\n");
//
//    ptr_i = (int*)malloc(sizeof(int));    //使用malloc函数在堆上分配了一块内存给ptr_i
//    printf("%p\n",&ptr_i);
//    printf("%p\n",ptr_i);
////    printf("========================\n");
////    printf("%d\n",*ptr_i);
//    printf("========================\n");
//    free(ptr_i);        //若只调用free函数而不将ptr_i赋值为NULL，则ptr_i为悬空指针，跟野指针是一样的危险，必须避免
//    ptr_i = NULL;       //0地址，一般不能被访问
//    printf("%p\n",ptr_i);
//}
//
//void test021() {
//    int i = 111;
//    int j = 333;
//
//    int *ptr_i = &i;        //定义一个指针取i的地址
//    printf("%p\n",ptr_i);   //i的地址
//    printf("%p\n",&ptr_i);  //ptr_i自己的地址
//    printf("%p\n",&i);      //i的地址
//    printf("%p\n",&j);      //j的地址
//
//    printf("取ptr_i指针变量对应地址的值\n");
//
//    printf("%d\n",*ptr_i);      //*是一个间接寻址符，用于访问指针所指向的地址的值
//}
//
////查看指针的地址值
////指针在32位或64位操作系统所占用的字节长度:对于32的系统,指针占4个字节,64位的占8个字节
//void test01() {
//    int i =100;
//    int *ptr_i = &i;                                //定义指针
//
//    printf("%p\n",ptr_i);                   //%p是打印地址的,表示按照16进制输出，如果输出的不够8位左边补0
//    printf("i address = %p\n",&i);
//    printf("ptr_i address = %p\n",&ptr_i);  //取ptr_i指针的地址
//    printf("*ptr_i value = %d\n",*ptr_i);   //*d按照整数类型输出数据
//    printf("int* size =%d\n", sizeof(int*));                //int*
//    printf("char* size =%d\n", sizeof(char*));              //char*
//    printf("long* size =%d\n", sizeof(long*));              //long*
//    printf("long long* size =%d\n", sizeof(long long*));    //long long*
//    printf("void* size =%d\n", sizeof(void*));              //void* 是一种特殊的指针，其他类型的指针都可以赋值给void*
//
//    void *ptr_v = ptr_i;
//    printf("ptr_v=%p\n", ptr_v);
//}

//将函数全部定义下main的下方