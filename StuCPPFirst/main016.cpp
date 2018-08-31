#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



class Parent1
{
public:
	Parent1();
	virtual ~Parent1();
public:

	void test()
	{
		printf("Parent1...aaa\n");
	}
	virtual void print()
	{
		cout <<"Parent1"<<endl;
	}

	virtual void print(int  a)
	{
		cout << "Parent1" << endl;
	}

	virtual void print(int a, int b)
	{
		cout << "Parent1" << endl;
	}

	virtual void print(int a, int b, int c)
	{
		cout << "Parent1 a ..b...c...." << endl;
	}
private:
	char *p;
};

Parent1::Parent1()
{
	cout << "Parent1构造函数" << endl;
	p = new char[10];
	strcpy(p, "Parent1");
}

Parent1::~Parent1()
{
	cout << "Parent1析构函数" << endl;
	if (p != NULL)
	{
		delete[] p;
	}
}

class Child1:public Parent1
{
public:
	Child1();
	~Child1();
public:
	virtual void print()
	{
		cout << "Child1" << endl;
	}

	virtual void print(int  a)
	{
		cout << "Child1" << endl;
	}

	virtual void print(int a, int b)
	{
		cout << "Child1" << endl;
	}

	virtual void print(int a, int b,int c)
	{
		cout << "Child1 a...b....c....." << endl;
	}
private:
	char *p;
};

Child1::Child1()
{
	cout << "Child1构造函数" << endl;
	p = new char[10];
	strcpy(p, "Child1");
}

Child1::~Child1()
{
	cout << "Child1析构函数" << endl;
	if (p != NULL)
	{
		delete[] p;
	}
}


class Child2 :public Child1
{
public:
	Child2();
	~Child2();
public:

	void test()//没有virtual关键字  属于重定义
	{
		printf("Child2....\n");
	}

	virtual void print()
	{
		cout << "Child2" << endl;
	}
	virtual void print(int a)
	{
		cout << "Parent1" << endl;
	}
	virtual void print(int a,int b)
	{
		cout << "Parent1" << endl;
	}
private:
	char *p;
};

Child2::Child2()
{
	cout << "Child2构造函数" << endl;
	p = new char[10];
	strcpy(p, "Child2");
}

Child2::~Child2()
{
	cout << "Child2析构函数" << endl;
	if (p != NULL)
	{
		delete[] p;
	}
}


/**
 * 1.C++中多态 ->在方法名字前面加上virtual关键字
 * 2.静态联编->程序的匹配,连接在编译阶段实现;函数重载使用静态联编;
 * 3.动态联编->程序的 匹配连接在运行时进行;if switch
 */
int main0161(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Parent1 *p = NULL;
	Parent1 p1;
	Child1 c1;
	p = &p1;
	p->print();
	p = &c1;
	p->print();
	return 0;
}


//这种场景至下,通过父类指针释放内存,只执行了父类的析构函数
//有可能会造成内存泄漏
//解决办法:在父类的析构函数前加上virtual关键字(虚析构函数),
//就可以通过父类指针执行所有子类的析构函数,析构所有子类的资源
void howtoDelte(Parent1 *p1)
{
	delete p1;
}

/**
 * 1.创建子类对象的时候,会先从顶至下调用父类的构造函数,析构函数与构造函数的调用顺序相反
 * 2.重载->
 *		重载必须在同一个类中进行
 *		重载是在编译期间根据参数类型和个数决定函数的调用
 *		子类无法重载父类的函数,父类的同名函数会被子类的同名函数覆盖
 * 3.重写->
 *		重写必须发生在父类和子类之间
 *		并且必须与父类的同名函数有完全相同的原型
 *		使用virtual关键字之后,能产生多态(如果不使用virtual关键字,叫重定义,会屏蔽掉父类的函数);
 *		多态是在运行时期根据具体的对象类型产生函数的调用
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Child2 *c2 = new Child2;
	c2->test();
	c2->Parent1::test();
//	c2->print(1, 2, 3); //error 没有重载函数接受 3 个参数 ->C++编译器认为是函数重载 子类发生了名称覆盖

	Parent1 *p1 = NULL;
	p1 = new Parent1;
	p1->print(1, 2, 3);
	Child1 c1;
	p1 = &c1;
	p1->print(1, 2, 3);
	howtoDelte(c2);
	return 0;
}