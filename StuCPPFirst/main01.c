#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * �ṹ��Ĵ�Сһ��Ϊ�ṹ���еĳ�Ա������ʹ�С��������
 * ����ƫ�������㣬�������нṹ���Ա�Ĵ�С֮���������������ƫ��һλ��
 * Ȼ���ټ���ṹ��Ĵ�С��֪�����㵽�ýṹ���г�Ա������͵Ĵ�С����������
 */
typedef struct MyStruct
{
	char name[50];
	char b;
	int c;
	double d;
	char x;
	int z;
	float y;
}MyStruct;



int main01(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("%d\n", sizeof(MyStruct));
	printf("%d\n", sizeof(float));
	printf("name��ƫ����Ϊ��%d\n", offsetof(MyStruct, name));
	printf("y��ƫ����Ϊ��%d\n", offsetof(MyStruct, y));
	printf("z��ƫ����Ϊ��%d\n", offsetof(MyStruct, z));
	printf("x��ƫ����Ϊ��%d\n", offsetof(MyStruct, x));
	printf("b��ƫ����Ϊ��%d\n", offsetof(MyStruct, b));
	printf("c��ƫ����Ϊ��%d\n", offsetof(MyStruct, c));
	printf("d��ƫ����Ϊ��%d\n", offsetof(MyStruct, d));
	register int x;//C���Ա�������register���εı����洢�ڼĴ������棻
//	int *p = &x; //error �Ĵ��������ϵ�& ��register���εı�������ȡ��ַ


	int i = 10, j = 20;
	//(i > j ? i : j) = 30;error //C�����б��ʽ��������ֵ
					//���ʽ�ķ���ֵ��һ��ֵ����10����20�����Բ�������ֵ

	//*(i > j ? &i : &j) = 30;//ok ʵ��C++һ����Ч��

	printf("j=%d\n", j);
	return 0;
}
