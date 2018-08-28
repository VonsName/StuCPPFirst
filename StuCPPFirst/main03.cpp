#include <iostream>


/**
 * const和#define：const是由编译器处理的，提供类型检查和作用域检查
 *				   #define是由预处理处理的	
 */
int main031(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	//C++中const修饰的常量编译器引入一张符号表，这个时候没有分配内存空间
	//只有当使用&取地址的时候或者当const修饰的变量为全局变量的时候才会分配内存空间
	const int a = 10;
//	a = 20;//error 常量不能修改
	int *p = NULL;
	//p = &a; //error const修饰的变量(常量)不能取地址给指针变量p
	p = (int *)&a;
	*p = 1000; //const修饰的变量a不能被修改；但是C语言中可以这样修改
			//这里C++单独的开辟了一块内存空间，修改的是该内存空间的值；
	printf("%d\n", a);//还是输出10，

	const int *p1 = NULL;
	p1 = &a;//C++只能使用const修饰的指针变量（常量指针）指向const修饰的变量（常量）
			//常量指针（常量的指针），指向常量的指针
	//*p1 = 100;//error 不能修改
	return 0;
}


void fun1()
{
	#define  M 10;

}

void fun2()
{
	//printf("%d\n", M);//ERROR
}

int main032(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	fun1();
	fun2();
	return 0;
}