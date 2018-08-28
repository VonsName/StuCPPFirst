#include <iostream>


/**
 * C++引用
 * 1.引用很像一个常量，必须初始化
 * 2.引用像指针一样，所有类型的引用都只占4个字节；
 * 3.引用在C++中的实现是一个常指针 int* const d;
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

/**
 * 指针交换
 */
void swap0(int *x, int *y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * 引用交换
 */
void swap02(int &x, int &y)//C++编译器->void swap2(int *const x, int *const y)
{
	int tmp = 0;
	tmp = x; //C++编译器->tmp = *x;
	x = y;	//C++编译器->*x = *y;
	y = tmp; //C++编译器->*y tmp
}




struct T1
{
	char name[64];
	int age;

	int &a;
	//int &b;
	double &b;
};
int main045(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int x = 10;
	int y = 20;

	swap0(&x, &y);//使用指针交换
	printf("x=%d y=%d\n", x, y);

	swap02(x, y);//使用引用交换 C++编译器-> swap02(&x,&y);
	printf("x=%d y=%d\n", x, y);

	printf("sizeof(T1)=%d\n", sizeof(T1));
	return 0;
}