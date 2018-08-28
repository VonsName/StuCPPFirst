#include <iostream>


/**
 * C++引用
 * 1.引用很像一个常量，必须初始化
 * 2.引用像指针一样，占4个字节；
 */
int main041(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a = 10;
	//引用必须要初始化
	int &b = a;//b等于是a的一个别名，
				//b和a相当于是一个，无论修改哪个都会影响另外一个
	printf("b=%d\n", b);
	printf("a=%d\n", a);
	b = 100;
	printf("b=%d\n", b);
	printf("a=%d\n", a);

	a = 200;
	printf("b=%d\n", b);
	printf("a=%d\n", a);
	return 0;
}


void swap01(int *x, int *y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap02(int &x, int &y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

struct T1
{
	char name[64];
	int age;

	int &a;
	int &b;
};
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int x = 10;
	int y = 20;
	swap01(&x, &y);//使用指针交换
	printf("x=%d y=%d\n", x, y);

	swap01(&x, &y);//使用引用交换
	printf("x=%d y=%d\n", x, y);

	printf("sizeof(T1)=%d\n", sizeof(T1));
	return 0;
}