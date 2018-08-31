#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Parent
{
public:
	Parent(int x,int c);
	~Parent();
	int b;
	static int j;
public:
	void print_p()
	{
		cout << "parent" << endl;
	}
protected://只能在子类内部访问
	int a;
private:
	int c;
	int x;
};
int Parent::j = 10;//静态成员变量必须显示的初始化
//error LNK2001: 无法解析的外部符号 "public: static int Parent::j" (?j@Parent@@2HA)
Parent::Parent(int x,int c)
{
	this->x = x;
	this->c = c;
	cout << "父类构造函数" << endl;
}

Parent::~Parent()
{
	cout << "父类析构函数" << endl;
}

class Child:public Parent
{
public:
	Child(int x,int c,int y);
	~Child();
public:
	void user()
	{
		a = 20;
		b = 30;
	}
	void print_p()
	{
		cout << "child" << endl;
	}
public:
	Parent p;
private:
	int y;
};

Child::Child(int x, int c, int y):Parent(x,c),p(x,c)
{
	this->y = y;
	cout << "子类构造函数" << endl;
}

Child::~Child()
{
	cout << "子类析构函数" << endl;
}
/**
 * C++对象继承：
 * 1.public继承，父类的成员和函数访问等级不变；
 * 2.protected继承，父类的成员和函数public变为protected(只能在子类内部访问)，其他不变
 * 3.private继承,父类的成员和函数全部变为私有
 * 4.父类为private，子类都不能访问
 * 5.子类对象构造的时候，需要调用父类的构造函数来初始化继承来的成员
 * 6.子类对象析构的时候，需要调用父类的析构函数来析构继承来的成员
 * 7.构造的时候先调用父类的构造函数，再调用组合对象的构造函数，最后自己的
 * 8.析构的时候先调用子类的析构函数，和构造函数的调用顺序相反
 * 9.如果父类和子类有同名函数，子类的会屏蔽了父类的
 * 10.基类定义的Public静态成员被所有派生类共享，但是遵循派生类的访问控制规则
 */
int main0131(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Child c(1,2,3);
	//c.b = 20; //protected继承，只能在子类内部访问
	c.print_p();
	c.Parent::print_p();
	printf("%d \n", c.j);
	return 0;
}