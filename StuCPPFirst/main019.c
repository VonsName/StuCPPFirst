#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main0191(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	int a[10];

	typedef int(TypeArray)[10];//定义数组数据类型 int a[10];

	TypeArray arr;
	arr[0] = 10;
	printf("%d\n", arr[0]);
	printf("%d\n", *arr);

	TypeArray *parr = NULL;
	parr = &arr;
	printf("%d\n", **parr);

	typedef int(*PTypeArray)[10];//定义一个数组指针数据类型

	PTypeArray pa=NULL;
	pa = &a;
	**pa = 20;
	printf("%d\n", *a);

	int(*MPointer)[10];//直接定义一个指向数组类型的数组指针变量
	MPointer = &a;
	(*MPointer)[1] = 30;
	printf("%d\n", *(a+1));
	return 0;
}
