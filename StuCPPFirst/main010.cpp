#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Num
{
public:
	Num();
	~Num();
	Num(int a, int b);

	friend class Num2;//友元类

	//利用友元函数重载+号运算符
	friend Num operator+(Num &n1, Num &n2);

	//成员函数重载+号运算符
	Num& operator +(const Num &n);

	//成员函数重载前置--操作符
	Num& operator --();

	//成员函数重载后置--操作符,要返回元素
	Num operator--(int);

	//利用友元函数重载前置++操作符
	friend Num&  operator ++(Num &n1);

	//利用友元函数重载后置++操作符,要返回元素
	friend Num  operator ++(Num &n1,int);

public:

	friend void modifyNum(Num *n);//友元函数,可以在类外部修改类的私有成员

	Num &add(const Num n)
	{
		this->a = this->a + n.a;
		this->b = this->b + n.b;
		return *this;
	}
	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}
private:
	int a;
	int b;
};

Num::Num()
{
}
Num::Num(int a, int b)
{
	this->a = a;
	this->b = b;
}
Num::~Num()
{
}

//重载+运算符
Num& Num::operator+(const Num &n)
{
	this->a = this->a + n.a;
	this->b = this->b + n.b;
	return *this;
}

class Num2
{
public:
	Num2();
	~Num2();
	void setA(int i)
	{
		num.a = 9;
		num.b = 10;
	}
	Num& getNum()
	{
		return this->num;
	}
private:
	Num num;
};

Num2::Num2()
{
}

Num2::~Num2()
{
}

//类外部的运算符+重载
Num operator+(Num &n1, Num &n2)
{
	//Num tmp(n1.getA() + n2.getA(), n1.getB() + n2.getB());//全局函数重载+运算符
	Num tmp(n1.a + n2.a, n1.b + n2.b);//友元函数重载+运算符
	return tmp;
}

int main0101(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Num n1(1,2);
	Num n2(3, 5);
	n1.add(n2);
	printf("%d %d\n", n1.getA(), n1.getB());
	return 0;
}


void modifyNum(Num *n)
{
	n->a = 99;
}


//友元函数
int main0102(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Num n1(1,2);
	printf("%d %d\n", n1.getA(), n1.getB());
	modifyNum(&n1);//友元函数
	printf("%d %d\n", n1.getA(), n1.getB());
	Num2 n2;
	n2.setA(90);
	Num &n3 = n2.getNum();
	printf("%d %d \n", n3.getA(), n3.getB());
	
	return 0;
}


//运算符可以重载为友元函数,也可以重载为成员函数
int main01013(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Num n1(2, 5);
	Num n2(3, 7);
	Num &n3 = n1 + n2;
	printf("%d %d \n", n3.getA(), n3.getB());

	Num n5 = n1 + n2;
	printf("%d %d \n", n3.getA(), n3.getB());
	return 0;
}


//重载前置++
Num&  operator ++(Num &n1) {
	n1.a++;
	n1.b++;
	return n1;
}

//重载后置++
Num  operator ++(Num &n1, int)
{
	Num tmp = n1;
	n1.a++;
	n1.b++;
	return tmp;
}


//成员函数重载前置--操作符
Num& Num::operator--()
{
	this->a--;
	this->b--;
	return *this;
}

//成员函数重载后置--操作符
Num Num::operator--(int)
{

	Num tmp = *this;
	this->a--;
	this->b--;
	return tmp;
}


/**
 * C++不能用友元函数操作符重载 = -> () []操作符
 * 不能使用成员函数重载 << >>操作符
 */
//重载一元运算符
int main01015(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//前置++
	Num n1(1, 2);
	++n1;
	printf("%d %d\n", n1.getA(), n1.getB());

	//后置++
	Num n2(1, 2);
	n2++;
	printf("%d %d\n", n2.getA(), n2.getB());

	//前置--
	Num n3(3, 5);
	--n3;
	printf("%d %d\n", n3.getA(), n3.getB());


	//后置--
	Num n4(6, 7);
	n4--;
	printf("%d %d\n", n4.getA(), n4.getB());
	return 0;
}