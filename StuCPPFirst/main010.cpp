#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Num
{
public:
	Num();
	~Num();
	Num(int a, int b);
public:
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

int main0101(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Num n1(1,2);
	Num n2(3, 5);
	n1.add(n2);
	printf("%d %d\n", n1.getA(), n1.getB());
	return 0;
}