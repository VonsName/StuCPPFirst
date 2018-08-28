#include <iostream>
using namespace std;



int main061(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	{
		int x = 10;
		//常引用,让变量引用只读属性,不能通过rx修改x的值
		const int &rx = x;//用变量初始化常引用
		//rx = 20;//error,常引用,不能通过常引用修改指向的内存空间
		int y = 90;
		//rx = y;//error,常引用,不能修改常引用的指向,
					//相当于指针的const int *const a;变量本身以及指向的内存空间都不能修改
	}

	{
		//用字面量初始化常引用
		//int &c = 40;//error 
		const int &a = 40;
	}
	{
		//普通引用
		int x = 10;
		int &rx = x;
		printf("%d\n", rx);
		int y = 90;
		rx = y;
		printf("%d\n", rx);
	}
	return 0;
}



#define MYFUNC(a,b) (a < b ? a:b)
//宏和inline不一样,++做参数的时候
inline int myfun(int a, int b)
{
	return (a < b ? a : b);
}
/**
 * 内联函数必须声明和定义写在一块
 * C++编译器直接把内联函数体插入在函数调用的地方
 * 内联函数么有普通函数调用的额外开销(压栈,跳转,返回);
 */
int main062(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a = 1, b = 3;
	int y=MYFUNC(++a, b);// 宏替换并展开->(++a < b ? ++a:b)
	//int y = (++a < b ? ++a : b);//2<3 返回a ,然后++a ->输出3
	printf("%d\n", y);//输出->3

	a= 1; b= 3;
	int x = myfun(++a, b);
	printf("%d\n", x);//输出->2
	return 0;
}


/**
 * 1.C++函数的默认参数,必须是从右至左的规则,右边的必须都有默认参数
 * 2.函数占位参数,函数调用的时候也必须传递
 */

void foo1(int a, int b, int)
{
	cout << "a=" << a << ",b=" << b << endl;
}

void foo(int a, int b, int = 0)
{
	cout << "a=" << a << ",b=" << b << endl;
}
int main063(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	foo1(1, 2,3);//函数占位参数,函数调用的时候也必须传递
	foo(1, 2);//ok
	foo(1, 2, 3);//ok
	return 0;
}



//函数重载
void print_a(int a)
{
	cout << "a=" << a  << endl;
}

void print_a(int a, int b)
{
	cout << "a=" << a << ",b=" << b << endl;
}

void print_a(int a, int b,int c=5)
{
	cout << "a=" << a << ",b=" << b << ",c=" << c <<endl;
}

//函数重载和参数的顺序无关
//void print_a(int c, int a, int b)
//{
//	cout << "a=" << a << ",b=" << b << "c=" << c << endl;
//}

void print_a(double a, double b)
{
	cout << "a=" << a << ",b=" << b << endl;
}

/**
 * 函数的重载:
 * 0.函数名相同
 * 1.参数个数不同;
 * 2.参数的类型不同;
 * 3.与函数的返回值无关
 * 4.函数重载与默认参数在一起的时候,会出现调用的二义性
 */
int main064(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	print_a(1.9, 2.2);
	//double自动进行类型转换为int类型
	print_a(1.9, 2.2,3.3);

	//print_a(10,20); //error 因为有默认参数,编译器匹配的时候出现了二义性,对重载函数的调用不明确

	print_a(5);//ok 只匹配到带一个参数的
	return 0;
}


/**
 * 函数指针
 */

//声明一个函数类型
typedef void(FUN)(int a);


//声明一个函数指针类型
typedef void(*PFUN)(double a,double b);

//直接定义一个函数指针变量
void(*MYFUN)(int a, int b);


int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{


	//定义一个函数指针变量
	FUN *pf = NULL;
	pf = print_a;//把一个函数的入口地址赋值给函数指针变量
	pf(5);
	
	//定义一个函数指针变量
	PFUN pfun = NULL;
	pfun = print_a;//把一个函数的入口地址赋值给函数指针变量
	double i = 8.8,  j = 9.9;
	pfun(i, j);//匹配到了两个int型形参做参数的函数

	//直接定义一个函数指针变量
	void(*MYPFUN)(int a, int b);
	MYPFUN = print_a;//把一个函数的入口地址赋值给函数指针变量
	MYPFUN(1, 2);
	//print_a(5, 7);//error ->函数默认参数和函数重载在一起,直接调用出现二义性,对函数的调用不明确
	return 0;
}