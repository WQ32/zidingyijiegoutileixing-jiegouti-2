#include <stdio.h>

//结构体内存对齐
//计算结构体的大小


////1.第一个成员在于结构体变量偏移量为0的地址处
////2.其他变量在自身对齐数的整数倍的地址处（对齐数=编译器默认的一个对齐数与该成员大小的较小值）
////3.vs默认是8
////4.结构体大小为最大对齐数的整数倍
////5.gcc没有默认对齐数
////6.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处
//    结构体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
// 
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));
//	//c1 : 1  a : 3+4（占了3个浪费空间）  c2 : 1      1+7+1  != 4的倍数，再在后面占3个空间
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//	//c1 : 1  c2 : 1  a : 2+4(占了2个浪费空间)        1+1+6  == 4的倍数，不用再浪费空间
//	return 0;
//}

////例题1：
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//int main()
//{
//	struct S3 s3 = { 0 };
//	printf("%d\n", sizeof(s3));
//	// 8 + 1 + (3+4) = 16  16是8的倍数
//	return 0;
//}
//
////例题2：
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	struct S3 s4 = { 0 };
//	printf("%d\n", sizeof(s4));
//	// 1 + （7+16）+ 8  = 32  32是8的倍数
//	return 0;
//}

//为什么存在内存对齐   -   拿空间换时间
//1.平台原因
//2.性能原因：不对齐访问2次，对齐访问1次


//如何在设计结构体的时候，既要满足对齐，又要节省空间
//让占用空间小的成员尽量集中在一起


////修改默认对齐数
//// #pragma 这个预处理指令，可以更改默认对齐数
// 一般为 2 4  8 16，2多次方数
//
////设置默认对齐数
//#pragma pack(4)
//struct S
//{
//	char a;
//	// 1 + 3
//	double b;
//	// 8
//	//4 + 8  是4的倍数
//	//结果12
//	//设置为1，结果就为 9 
//};
//#pragma pack()
////取消设置的默认对齐数
//
//
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//	return 0;
//}


//// offsetof宏的实现  - 计算结构体中某变量相对于首地址的偏移量
//// size_t offsetof(structName, memberName);
//#include <stddef.h>
//
//struct S
//{
//	char a;
//	int b;
//	double c;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, a)); //0
//	printf("%d\n", offsetof(struct S, b)); //4
//	printf("%d\n", offsetof(struct S, c)); //8
//	return 0;
//}

//结构体传参
//

struct S
{
	char a;
	int b;
	double c;
};
void Init(struct S * ps)
{
	ps->a = 'W';
	ps->b = 19;
	ps->c = 3.14;
}

//法一：传值  -》这里tmp接受的是结构体的大小，如果结构体大小过大，所占空间的大小过大
//               参数压栈的系统开销比较大，就会导致系统的性能下降
void Print1(struct S tmp)
{
	printf("%c %d %lf", tmp.a, tmp.b, tmp.c);
}

//法二：传址   -》更好，因为传的是一个地址，只有4个字节,与结构体大小无关
void Print2(const struct S* ptmp)    //加const，保证内容不被修改（安全）
{
	printf("%c %d %lf", ptmp->a, ptmp->b, ptmp->c);
}

int main()
{
	struct S s = { 0 };
	Init(&s);
	//传地址可以修改
	//传值不可以修改
	Print1(s);
	Print2(&s);
	return 0;
}