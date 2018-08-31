#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class AA
{
public:
	AA();
	~AA();
public:
	int a;
private:

};

AA::AA()
{
	cout << "基类AA的构造函数" << endl;
}

AA::~AA()
{
}
class BB:virtual public AA //加了virtual AA基类的构造函数只调用一次
{
public:
	BB();
	~BB();
	int b;
	int x;
private:

};

BB::BB()
{
}

BB::~BB()
{
}

class CC:virtual public AA //加了virtual AA基类的构造函数只调用一次
{
public:
	CC();
	~CC();
	int c;
	int x;
private:

};

CC::CC()
{

}


CC::~CC()
{

}
class DD: public CC,public BB
{
public:
	DD();
	~DD();

private:

};

DD::DD()
{

}

DD::~DD()
{

}

//virtual 占用内存
int main0151(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//继承的二义性，在类A中有属性a,类B和类C都继承了类A
//	CC c1;
//	c1.a = 20;
//	BB b1;
//	b1.a = 20;
	DD dd;
//	dd.a = 30; //ERROR a不明确 
	dd.a = 80; //解决办法，虚继承virtual
//	dd.x = 99; //ERROR a不明确 
	return 0;
}