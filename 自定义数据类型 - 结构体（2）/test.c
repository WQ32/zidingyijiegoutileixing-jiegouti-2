#include <stdio.h>

//�ṹ���ڴ����
//����ṹ��Ĵ�С


////1.��һ����Ա���ڽṹ�����ƫ����Ϊ0�ĵ�ַ��
////2.����������������������������ĵ�ַ����������=������Ĭ�ϵ�һ����������ó�Ա��С�Ľ�Сֵ��
////3.vsĬ����8
////4.�ṹ���СΪ����������������
////5.gccû��Ĭ�϶�����
////6.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ���������������������
//    �ṹ���С��������������������Ƕ�׽ṹ��Ķ���������������
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
//	//c1 : 1  a : 3+4��ռ��3���˷ѿռ䣩  c2 : 1      1+7+1  != 4�ı��������ں���ռ3���ռ�
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//	//c1 : 1  c2 : 1  a : 2+4(ռ��2���˷ѿռ�)        1+1+6  == 4�ı������������˷ѿռ�
//	return 0;
//}

////����1��
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
//	// 8 + 1 + (3+4) = 16  16��8�ı���
//	return 0;
//}
//
////����2��
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
//	// 1 + ��7+16��+ 8  = 32  32��8�ı���
//	return 0;
//}

//Ϊʲô�����ڴ����   -   �ÿռ任ʱ��
//1.ƽ̨ԭ��
//2.����ԭ�򣺲��������2�Σ��������1��


//�������ƽṹ���ʱ�򣬼�Ҫ������룬��Ҫ��ʡ�ռ�
//��ռ�ÿռ�С�ĳ�Ա����������һ��


////�޸�Ĭ�϶�����
//// #pragma ���Ԥ����ָ����Ը���Ĭ�϶�����
// һ��Ϊ 2 4  8 16��2��η���
//
////����Ĭ�϶�����
//#pragma pack(4)
//struct S
//{
//	char a;
//	// 1 + 3
//	double b;
//	// 8
//	//4 + 8  ��4�ı���
//	//���12
//	//����Ϊ1�������Ϊ 9 
//};
//#pragma pack()
////ȡ�����õ�Ĭ�϶�����
//
//
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//	return 0;
//}


//// offsetof���ʵ��  - ����ṹ����ĳ����������׵�ַ��ƫ����
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

//�ṹ�崫��
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

//��һ����ֵ  -������tmp���ܵ��ǽṹ��Ĵ�С������ṹ���С������ռ�ռ�Ĵ�С����
//               ����ѹջ��ϵͳ�����Ƚϴ󣬾ͻᵼ��ϵͳ�������½�
void Print1(struct S tmp)
{
	printf("%c %d %lf", tmp.a, tmp.b, tmp.c);
}

//��������ַ   -�����ã���Ϊ������һ����ַ��ֻ��4���ֽ�,��ṹ���С�޹�
void Print2(const struct S* ptmp)    //��const����֤���ݲ����޸ģ���ȫ��
{
	printf("%c %d %lf", ptmp->a, ptmp->b, ptmp->c);
}

int main()
{
	struct S s = { 0 };
	Init(&s);
	//����ַ�����޸�
	//��ֵ�������޸�
	Print1(s);
	Print2(&s);
	return 0;
}