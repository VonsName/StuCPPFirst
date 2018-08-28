#include <iostream>
using namespace std;



int &get1()
{
	int a;
	a = 10;
	return a;
}

int* get2()
{
	int a;
	a = 10;
	return &a;
}

/**
 * 1.函数的返回值为引用的时候,如果返回栈变量,不能成为其他引用的初始值,也不能作为左值使用
 *   返回全局变量或者静态变量则可以做初始值,左值或者右值都可以
 * 2.
 */
int main051(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a1 = 0;
	a1 = get1();
	int &a2 = get1();
	printf("a1=%d\n", a1);//10 这个函数返回一个引用,但是接收的方式不一样
										//a1直接是直接接受一个int型,函数会返回一个a内存里的值(10)的拷贝给a1,所以输出10
	printf("a2=%d\n", a2);//乱码 a2这里接收的方式是用引用接收的,C++返回a的内存空间地址,
										//但是函数结束,a所在的内存空间释放,所以输出乱码

	int *a3 = get2();
	printf("%d\n", *a3);
	return 0;
}




//返回引用的函数可以当左值
int &get3()
{
	static int a = 10;
	a++;
	printf("%d\n", a);
	return a;
}
int get4()
{
	static int b = 10;
	b++;
	return b;
}
int main052(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//get4() = 20;//error 函数返回的是内存的值,不能做左值
	get3() = 50;//函数返回静态变量的引用,可以做左值
	get3();
	return 0;
}
typedef struct T2
{
	int age;
}T2;


/**
 * C语言中的二级指针
 */
int getT(T2 **pt)
{
	T2 *tmp = NULL;
	if (pt==NULL)
	{
		return -1;
	}
	tmp = (T2 *)malloc(sizeof(T2));
	if (tmp==NULL)
	{
		return -2;
	}
	tmp->age = 23;
	*pt = tmp;
	return 0;
}


/**
 * C++中指针的引用
 * 形参使用指针的引用做形参接受实参
 */
int getT2(T2 * &t)
{
	T2 *tmp = NULL;
	
	tmp = (T2 *)malloc(sizeof(T2));
	if (tmp == NULL)
	{
		return -1;
	}
	tmp->age = 25;
	t = tmp;
}

int main055(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	T2 *t = NULL;
	getT(&t);
	printf("%d\n", t->age);
	if (t!=NULL)
	{
		free(t);
		t = NULL;
	}

	T2 *t2 = NULL;
	//指针的引用,C++编译器自动取地址做实参传递到函数的形参中,形参使用指针的引用做形参接受实参
	getT2(t2);
	printf("%d\n", t2->age);
	if (t2!=NULL)
	{
		free(t2);
		t2 = NULL;
	}
	return 0;
}