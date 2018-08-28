#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * 结构体的大小一般为结构体中的成员最大类型大小的整数倍
 * 根据偏移量计算，计算所有结构体成员的大小之后会整体再向后继续偏移一位；
 * 然后再计算结构体的大小，知道计算到该结构体中成员最大类型的大小的整数倍；
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
	printf("name的偏移量为：%d\n", offsetof(MyStruct, name));
	printf("y的偏移量为：%d\n", offsetof(MyStruct, y));
	printf("z的偏移量为：%d\n", offsetof(MyStruct, z));
	printf("x的偏移量为：%d\n", offsetof(MyStruct, x));
	printf("b的偏移量为：%d\n", offsetof(MyStruct, b));
	printf("c的偏移量为：%d\n", offsetof(MyStruct, c));
	printf("d的偏移量为：%d\n", offsetof(MyStruct, d));
	register int x;//C语言编译器：register修饰的变量存储在寄存器上面；
//	int *p = &x; //error 寄存器变量上的& 被register修饰的变量不能取地址


	int i = 10, j = 20;
	//(i > j ? i : j) = 30;error //C语言中表达式不能做左值
					//表达式的返回值是一个值，即10或者20；所以不能做左值

	//*(i > j ? &i : &j) = 30;//ok 实现C++一样的效果

	printf("j=%d\n", j);
	return 0;
}
