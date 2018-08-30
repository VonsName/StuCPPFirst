#include <iostream>
using namespace std;


/**
 * C++编译器会默认有无参数的构造函数和拷贝构造函数
 */
class Test
{
public:
	Test();
	Test(int a, int b);
	~Test();
	Test(const Test &t);
public:
	void setAge(int age)
	{
		this->age = age;
	}
	int  getAge()
	{
		return this->age;
	}
private:
	int age;
};

Test::Test()
{
	cout << "构造函数调用" << endl;
}


Test::Test(int a, int b)
{
	cout << "有参数构造函数" << endl;
}

//拷贝构造函数(赋值构造函数);主要是用来解决浅拷贝的问题
Test::Test(const Test &t)
{
	this->age = t.age;
	cout << "拷贝构造函数" << endl;
}


Test::~Test()
{
	cout << "析构函数调用" << endl;
}


void f()
{
	Test t1;
	t1.setAge(23);
	cout << t1.getAge() << endl;

	Test t4(t1);//调用拷贝构造函数
//	Test t2 = t1;//这里会自动调用拷贝构造函数,把t1拷贝给t2;

	Test t3 = Test(1,2);//这里会产生一个匿名对象，且不会调用拷贝构造函数
					//然后直接用这个匿名对象赋值给t3,这里只会调用一次构造函数(且是有参数的)
					//整个函数只调用两次析构函数(t3和t1);

	//对象的初始化和对象的赋值是两个不同的概念
	t3 = t1;//这里只是简单的赋值操作，不会调用构造函数，也不会产生新的对象(不会多调用一次析构函数)
}


void f1(Test t)//C++编译器调用拷贝构造函数，将实参拷贝给形参
{
	printf("%d\n", t.getAge());
}

//返回t对象的时候C++编译器调用了拷贝构造函数,产生一个匿名对象；
Test f2()
{
	Test t;
	t.setAge(19);
	return t;
}

/**
 * struct的属性默认是public的
 * class的属性默认是private的
 */
int main071(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	f();
//	Test t;
//	t.setAge(18);
//	f1(t);//调用f1()函数的时候，C++编译器会默认调用拷贝构造函数(会产生一个新的对象)
			//用于初始化形参
			//所以这里结束的时候会调用2次析构函数；

//-----------------------------------------------------------------
//	Test t1;
//	t1 = f2();//2次构造函数，一次拷贝构造函数(f2()函数返回的时候)，三次析构
			//这里不是=号调用的拷贝构造函数，=号在这里只是简单的赋值
			//第一次析构函数内的对象，第二次析构f2()返回的匿名对象
			//第三次析构t1对象

//----------------------------------------------------------------------
	Test t2 = f2();//f2()函数返回的时候会调用拷贝构造函数，两次析构函数
					//这里不是=号调用的拷贝构造函数，=号在这里只是简单的赋值
					//直接把函数返回的匿名对象给t2(给匿名对象一个名字)
				//第一次析构函数是析构函数内的对象，第二次是析构t2对象
	return 0;
}