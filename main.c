#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test07();

//̫����ϸ�ڣ���ôѧϰ�����ݾͻ�ܶ࣬ʱ�����ޣ��Ժ��ĵ�Ϊ��

//�����ռ�����ϰ�ͻ��ˣ�
//1.clion�������ã����룩
//2.ָ��Ļ����÷�
//3.����ָ���ָ������

//ָ����һά��ά����Ĺ�ϵ
//1.�����ά���飬����ʡ���е�ǰ��
    //ֻ�ж�ȫ��Ԫ�ظ���ֵʱ����ô��һά�ĳ��Ȳſ��Բ��������������Ǵ��

void test01() {
    printf("ָ��ڶ�����ϰ-һά������ָ��\n");
    printf("ֻҪŪ����ָ�룬�����ľͺ�����\n");

    //�����ָ��:����ʼ��ָ�븳ֵΪNULL
    int *ptr_i = NULL;

    //��ʱ����ʹ��*ptr_i��ϵͳ�ᱨ��
//    printf("ptr_i=%p\n",*ptr_i);    //exit code -1073741819 (0xC0000005)
    printf("===========================\n");

    //����ͨ�õ�ָ��
//    void *ptr_v =

    char c;
    short s;
    int n;

    //���� int char short ���͵�ָ��
    char *ptr_c = &c;
    short *ptr_s = &s;
    int *ptr_n = &n;

    //���������ʽ��������
    //ptr_n=000000000061FDBC
    //ptr_c=000000000061FDBB
    //ptr_s=000000000061FDB8

    //ptr_c=000000000061FDBF    ===>�����shortռ2���ֽ�
    //ptr_s=000000000061FDBC    ===>�����intռ4���ֽ�
    //ptr_n=000000000061FDB8
    printf("ptr_c=%p\n",ptr_c);
    printf("ptr_s=%p\n",ptr_s);
    printf("ptr_n=%p\n",ptr_n);
    printf("=====================\n");

    void *ptr_v = ptr_n;
    //��һ������ָ��ת������һ��ͨ��ָ�룬��ַ����ı䣬����������Ϣ��ʧ
    printf("ptr_v=%p\n",ptr_v);
    //ת��ȥ �ֿ���ʹ����
    int *ptr_n_i = (int*)ptr_v;
    printf("ptr_n_i=%p\n",ptr_n_i);

    //ptr_vת������һ��ָ����ڵ�����
//    double *ptr_d = (double*)ptr_v;
    //�﷨��ȷ������������󣬱���������ͬ�ı��������ֵ�������ܲ�ͬ���޷�ʶ��
//    printf("ptr_d=%p\n",ptr_d);
}

void test02() {

    int n = 10;
    char c = 'a';
    short s = 11;

    //���� int char short ���͵�ָ��
    int *ptr_n = &n;
    char *ptr_c = &c;
    short *ptr_s = &s;

    printf("ptr_n=%p\n",ptr_n);
    printf("ptr_c=%p\n",ptr_c);
    printf("ptr_s=%p\n",ptr_s);

}

void test03() {
    printf("ָ�����������\n");
    printf("ֻ����+��-��++��--��+=��-=��������Ҫһ��\n");
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

    //void�ĳ���1
    printf("sizeof(void)=%d\n",sizeof(void));
}

void test04() {

    printf("ָ����һά����\n");
    int array[] = {1,2,3,4,5};
    printf("������������ֵ����ʼ��ַ��Ҳ���ǵ�һ��Ԫ�صĵ�ַ\n");
    printf("����������һ������ָ��\n");

    printf("������=%p\n",array);

    int *ptr_array = array;
    printf("ptr_array=%p\n",ptr_array);

    printf("===========================================\n");
    printf("*���������������һ��Ԫ��\n");
    printf("*array = %d\n",*array);
    printf("===========================================\n");
    printf("�鿴��һ��Ԫ�صĵ�ֵַ\n");
    printf("&array[0] = %p\n",&array[0]);
    printf("===========================================\n");
    printf("�ı�ڶ���Ԫ�ص�ַ����Ӧ��ֵ\n");
    ptr_array[2] = 100;
    printf("array[2] = %d\n",array[2]);
    printf("===========================================\n");
    printf("�鿴���ĸ�Ԫ�ص�ֵ\n");
    *(ptr_array + 3) = 300;
    printf("array[3] = %d\n",array[3]);
    printf("*(array + 3) = %d\n",*(array + 3));
    printf("*&array[3] = %d\n",*&array[3]);

    printf("*(ptr_array+3) = %d\n",*(ptr_array+3));
    printf("ptr_array[3]=%d\n",ptr_array[3]);
    printf("*&(ptr_array[3])=%d\n",*&(ptr_array[3]));

    printf("===========================================\n");
    printf("�鿴���ĸ�Ԫ�صĵ�ֵַ\n");
    printf("&(ptr_array[3])=%p\n",&(ptr_array[3]));
    printf("&ptr_array[3]=%p\n",&ptr_array[3]);
    printf("ptr_array + 3 =%p\n",ptr_array + 3);
    printf("array + 3 = %p\n",array + 3);
    printf("&array[3] = %p\n",&array[3]);
}

//ָ�����������ָ�������https://www.cnblogs.com/mq0036/p/3382732.html
//�����Եط����鿴

//1.()��[]��*�������ȼ�ǰ����ߣ�*���
//2.����ָ��ֻ��һ��ָ���������ռ���ڴ���һ��ָ��Ĵ洢�ռ䣻ָ�������Ƕ��ָ�������ռ�ж��ָ��Ĵ洢�ռ䣻
//3.����ָ�루Ҳ����ָ�룩
//���� int (*p)[n];
//p+1ʱ��pҪ���n���������ݵĳ���(��һ��Ƚ���Ҫ)
//4.ָ������
//���� int *p[n];
//p+1ʱ����pָ����һ������Ԫ��(��һ��Ƚ���Ҫ)
//5.����ϸ�ڣ����Ϸ���������
//�ʼ����� �� ����ָ���ָ����������� ����

void test05() {
    printf("����ָ���ָ������\n");
    int array[] = {1,2,3,4,5};
    int *ptr_array = array;

    printf("����ĳ�ʼ��ַ���������һ��Ԫ�صĵ�ַ\n");
    printf("array    =%p\n",array);
    printf("&array   =%p\n",&array);
    printf("&array[0]=%p\n",&array[0]);
    printf("ptr_array=%p\n",ptr_array);

    //* [] ():�������ȼ��𽥱��
    // int (*ptr_array)[5] ����ָ��
    // int *ptr_arr[5]  ָ������
    printf("===============================\n");
    printf("array + 1  = %p\n",array + 1);          //�����е�2��Ԫ�صĵ�ַ
    printf("&array[1]  = %p\n",&array[1]);
    printf("===============================\n");
    printf("&array + 1 = %p\n",&array + 1);         //���5���������ݵĳ���
}

void test06() {

    int array[] = {1,2,3,4,5};
    printf("array  = %p\n",array);
    printf("&array = %p\n",&array);

    printf("===========================\n");

    //todo ���о�������  ʹ���ı��༭�� �ᷢ����������clionȴû��
    //int *ptr_array = &array;
//    printf("ptr_array = %p\n",ptr_array);

    printf("array     = %p\n",array);
    printf("array + 1 = %p\n",array + 1);
    printf("===========================\n");

    //��������ָ��
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
//����2��ĳɼ��ڿ���̨δ��������������룬ԭ����
void test07() {

    float zu1[5],zu2[10];
    int i;
    printf("�������1���ѧ���ɼ�:\n");
    for(i = 0;i<=4;i++){
        scanf("%f",&zu1[i]);
    }
    printf("�������2���ѧ���ɼ�:\n");
    for(i = 0;i<=9;i++){
        scanf("%f",zu2[i]);
    }

    printf("��1��ƽ������%f\n",aver(zu1,5));
    printf("��2��ƽ������%f\n",aver(zu2,10));
}

//ָ����һά��ά����֮��Ĺ�ϵ
void test08(){
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);     //ptr��δ֪�ģ�ֻ֪����ַ��λ��
    printf("%d,%d",*(a + 1),*(ptr - 1));    //a[1] = 2��a[4] = 5
}

void test09(){
    char *color[] = {"red","green","blue"};     //ָ�����鱣������ַ�����ַ
    //������
    //�Ƿ����д��
    //��ƽ̨���  ������ܻ᲻ͬ  �仯�Ĳ�����ȷ��
    for(int i = 0;i < 3;i++){
        puts(color[i]);
        printf("color[%d]=%p\n",i,&color[i]);
        color[i] = "color";
        printf("color[%d]=%p\n",i,&color[i]);
    }

    //ָ��ָ���ά������б���

}

//ָ�����ָ���ά������б���

//ָ���ָ�루����ָ�룩��http://c.biancheng.net/view/2016.html
//����ָ���������⣺https://blog.csdn.net/majianfei1023/article/details/46629065?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-9.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-9.control
//�ô���
//eg�����ҵĺ���
//

void test11(){
    int i = 100;
    int *pInt = &i;
    int **ppInt = &pInt;       //ָ���ָ��
    printf("i       = %d\n",i);
    printf("*pInt   = %d\n",*pInt);
    printf("**ppInt = %d\n",**ppInt);
}

//https://blog.csdn.net/daimous/article/details/71436825
//�ñ���a��������Ķ���
//a) һ��������
//int a;
//b) һ��ָ����������ָ��
//int *a;
//c) һ��ָ��ָ��ĵ�ָ�룬��ָ���ָ����ָ��һ��������
//int **a;
//d) һ����10��������������
//int a[10];
//e) һ��ָ����10�������������ָ��
//int (*a��[10];
//f) һ����10��ָ������飬��ָ����ָ��һ����������
//int *a[10];
//g).ָ�뺯��
//int *p��int i��:����ֵΪָ�����͵ĺ���;
//h).����ָ��
//int��*p����int i��:��ָ��һ������ֵΪint�͵�ָ��;

//ָ�뺯���뺯��ָ��:https://blog.csdn.net/ameyume/article/details/8220832
//ָ�뺯�����Ƿ���һ����ַ�������ߣ�������Ҫ��ַ�����

int max(int a,int b){
    return a > b ? a : b;
}

//��������ָ��,����ķ���ֵ��int���ͣ�����ֵ������ָ��
int (*f)(int,int);
//����ָ��ĵ���
void test12() {
    printf("ʹ�ú���ָ�룺�������ֵ\n");
    f = max;
    int c = (*f)(1,2);
    printf("max = %d\n",c);
}

//�����Ļص�
int call(int x,int y){
    return x + y;
}
//�����������Ǻ���ָ��
int test13(int i1,int i2,int (*callback)(int,int)){
    return callback(i1,i2);
}

void test14(int array[]){
    printf("��������ֱ����Ϊ�������ݵ����:\n");
    printf("sizeof = %d\n", sizeof(array));
}

//ָ�����ָ���ά�������
void test15(){
    float fenshu[3][4] = {{65,67,70,60},{65,67,70,60},{65,67,70,60}};
    float (*ptr)[4] = fenshu;   //ָ��ָ���ά�������
    //������ά�����ÿһ��Ԫ��
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            //ptr + i����i��
            //*(ptr + i):��i�е�һ��Ԫ��
            //*(ptr + i) + j:��i�е�j��Ԫ�صĵ�ַ
            //*(*(ptr + i) + j):��i�е�j��Ԫ�ص�ֵ
            printf("��%d�У���%d�У�ֵΪ��%f\n",(i+1),(j+1),*(*(ptr + i) + j));
        }
    }
}

//�ַ�����������ַ�ʽ
//�ַ��� ƴ��    todo

void test18(){
    //C���Ե��ַ����������ַ�����
    //C�����ַ������ַ������ʾ

    printf("�ַ��������ֶ��巽ʽ\n");

    //������ַ�����(�ַ���)
    char str[10] = {'h','e','l','l','o','\0'};

    //'\0'����ʡ��
    char str1[10] = "hello";

    //ָ��str2����ջ�У�"hello"���ڳ����أ����ַ�ʽ������ַ���ֻ�ܶ���ͬ����2�ֵ�����
    char *str2 = "hello";

    //��ӡ�鿴Ч��
    printf("str =%s\n",str);
    printf("str1=%s\n",str1);
    printf("str2=%s\n",str2);
}

void test19(){
    //todo ����һ���ַ���

}

void test20(){
    //���ַ����鸳ֵ

    char str[10] = "abc";

//    int i;
//    for(i= 0; i < 10; i++){
//        str[i] = 'i';
//    }

    printf("str=%s\n",str);

    printf("sizeof(str)=%d\n", sizeof(str));
    printf("strlen(str)=%d\n", strlen(str));

}

//����ָ�룺ָ��ĵ�ַ���Ըı䣬����ָ��ָ���ֵ�����Ըı�
//ָ�볣����ָ����ָ��ĵ�ַ�����Ըı�

//�ṹ��
//�ṹ���ʼ��
//�ṹ��ķ���
//�ṹ��������ָ�룺
    //1.ָ�� -> ��Ա����
    //2.(*ָ��).��Ա����

//�����嶨��
//������ķ���
//ָ����ʽ ͬ��
//������ͽṹ�峤�ȵļ��㣬ʹ��sizeof����(���ٻ�������ȥ�ֶ��������С������˹�����[����]��ʱ����ȥ�˽�)
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































//=======================================================ָ����ϰ1========================================
//coding:ָ��Ļ�������������ϰ

//1.ָ����һ������ı�����������һ�������ĵ�ַ
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
//    /*����������ڴ�ռ䣬������һ��ָ������ָ�롣*/
//    ptr_i = (int*)malloc(sizeof(int));    //ʹ��malloc�����ڶ��Ϸ�����һ���ڴ��ptr_i
//    printf("%p\n",&ptr_i);
//    printf("========================\n");
//    /*����������ڴ�ռ䣬������һ��ָ������ָ�롣*/
//    ptr_j = (int*)calloc(8,sizeof(int));    //Ҫ�������Ԫ�ظ���,Ԫ�صĴ�С
//    printf("%p\n",&ptr_j);
//    printf("========================\n");
//    /* ������ڴ���� */
//    ptr_k = (int*)malloc(sizeof(int));
//    /* ���µ���֮ǰ���� malloc �� calloc ������� ptr(��һ������) ��ָ����ڴ��Ĵ�С�� */
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
////x��y��ָ�����
//void swap1(int* x,int* y){
//    printf("333: x= %p,y = %p\n",x,y);
//    printf("333: x= %d,y = %d\n",*x,*y);    //���ڷ���ָ����ָ��ĵ�ַ��ֵ
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
//    ptr_i = (int*)malloc(sizeof(int));    //ʹ��malloc�����ڶ��Ϸ�����һ���ڴ��ptr_i
//    printf("%p\n",&ptr_i);
//    printf("%p\n",ptr_i);
////    printf("========================\n");
////    printf("%d\n",*ptr_i);
//    printf("========================\n");
//    free(ptr_i);        //��ֻ����free����������ptr_i��ֵΪNULL����ptr_iΪ����ָ�룬��Ұָ����һ����Σ�գ��������
//    ptr_i = NULL;       //0��ַ��һ�㲻�ܱ�����
//    printf("%p\n",ptr_i);
//}
//
//void test021() {
//    int i = 111;
//    int j = 333;
//
//    int *ptr_i = &i;        //����һ��ָ��ȡi�ĵ�ַ
//    printf("%p\n",ptr_i);   //i�ĵ�ַ
//    printf("%p\n",&ptr_i);  //ptr_i�Լ��ĵ�ַ
//    printf("%p\n",&i);      //i�ĵ�ַ
//    printf("%p\n",&j);      //j�ĵ�ַ
//
//    printf("ȡptr_iָ�������Ӧ��ַ��ֵ\n");
//
//    printf("%d\n",*ptr_i);      //*��һ�����Ѱַ�������ڷ���ָ����ָ��ĵ�ַ��ֵ
//}
//
////�鿴ָ��ĵ�ֵַ
////ָ����32λ��64λ����ϵͳ��ռ�õ��ֽڳ���:����32��ϵͳ,ָ��ռ4���ֽ�,64λ��ռ8���ֽ�
//void test01() {
//    int i =100;
//    int *ptr_i = &i;                                //����ָ��
//
//    printf("%p\n",ptr_i);                   //%p�Ǵ�ӡ��ַ��,��ʾ����16����������������Ĳ���8λ��߲�0
//    printf("i address = %p\n",&i);
//    printf("ptr_i address = %p\n",&ptr_i);  //ȡptr_iָ��ĵ�ַ
//    printf("*ptr_i value = %d\n",*ptr_i);   //*d�������������������
//    printf("int* size =%d\n", sizeof(int*));                //int*
//    printf("char* size =%d\n", sizeof(char*));              //char*
//    printf("long* size =%d\n", sizeof(long*));              //long*
//    printf("long long* size =%d\n", sizeof(long long*));    //long long*
//    printf("void* size =%d\n", sizeof(void*));              //void* ��һ�������ָ�룬�������͵�ָ�붼���Ը�ֵ��void*
//
//    void *ptr_v = ptr_i;
//    printf("ptr_v=%p\n", ptr_v);
//}

//������ȫ��������main���·�