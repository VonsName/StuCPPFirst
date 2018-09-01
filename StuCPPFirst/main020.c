#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testp()
{
	printf("hello\n");
}

/**
 * 函数指针
 */
int main0201(int argc,char *argv[])
{

	typedef void(IMyFunType)();//定义一个函数类型
	IMyFunType *m = NULL;
	m =	&testp;
	m();


	typedef void(*PIMyFunType)();//定义一个函数指针类型
	PIMyFunType pm = NULL;
	pm = testp;
	pm();

	void(*FunPointer)();//直接声明一个函数指针变量
	FunPointer = testp;
	FunPointer();
	return 0;
}






typedef void(*PIMyFunType)();//定义一个函数指针类型

void mainFun(PIMyFunType ptype)
{
	ptype();
}


//直接声明一个函数指针变量做形参
void mainFun1(void(*pointerMyFunType)())
{
	pointerMyFunType();
}

/**
 * 函数指针类型,把函数参数和返回值类型提前做了约定
 */
int main(int argc, char *argv[])
{
	mainFun(testp);//函数指针做函数参数

	mainFun1(testp);
	return 0;
}
