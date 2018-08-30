#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Num
{
public:
	Num();
	~Num();
	Num(int a, int b);

	friend class Num2;//��Ԫ��

	//������Ԫ��������+�������
	friend Num operator+(Num &n1, Num &n2);

	//��Ա��������+�������
	Num& operator +(const Num &n);

	//��Ա��������ǰ��--������
	Num& operator --();

	//��Ա�������غ���--������,Ҫ����Ԫ��
	Num operator--(int);

	//������Ԫ��������ǰ��++������
	friend Num&  operator ++(Num &n1);

	//������Ԫ�������غ���++������,Ҫ����Ԫ��
	friend Num  operator ++(Num &n1,int);

public:

	friend void modifyNum(Num *n);//��Ԫ����,���������ⲿ�޸����˽�г�Ա

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

//����+�����
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

//���ⲿ�������+����
Num operator+(Num &n1, Num &n2)
{
	//Num tmp(n1.getA() + n2.getA(), n1.getB() + n2.getB());//ȫ�ֺ�������+�����
	Num tmp(n1.a + n2.a, n1.b + n2.b);//��Ԫ��������+�����
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


//��Ԫ����
int main0102(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Num n1(1,2);
	printf("%d %d\n", n1.getA(), n1.getB());
	modifyNum(&n1);//��Ԫ����
	printf("%d %d\n", n1.getA(), n1.getB());
	Num2 n2;
	n2.setA(90);
	Num &n3 = n2.getNum();
	printf("%d %d \n", n3.getA(), n3.getB());
	
	return 0;
}


//�������������Ϊ��Ԫ����,Ҳ��������Ϊ��Ա����
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


//����ǰ��++
Num&  operator ++(Num &n1) {
	n1.a++;
	n1.b++;
	return n1;
}

//���غ���++
Num  operator ++(Num &n1, int)
{
	Num tmp = n1;
	n1.a++;
	n1.b++;
	return tmp;
}


//��Ա��������ǰ��--������
Num& Num::operator--()
{
	this->a--;
	this->b--;
	return *this;
}

//��Ա�������غ���--������
Num Num::operator--(int)
{

	Num tmp = *this;
	this->a--;
	this->b--;
	return tmp;
}


/**
 * C++��������Ԫ�������������� = -> () []������
 * ����ʹ�ó�Ա�������� << >>������
 */
//����һԪ�����
int main01015(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//ǰ��++
	Num n1(1, 2);
	++n1;
	printf("%d %d\n", n1.getA(), n1.getB());

	//����++
	Num n2(1, 2);
	n2++;
	printf("%d %d\n", n2.getA(), n2.getB());

	//ǰ��--
	Num n3(3, 5);
	--n3;
	printf("%d %d\n", n3.getA(), n3.getB());


	//����--
	Num n4(6, 7);
	n4--;
	printf("%d %d\n", n4.getA(), n4.getB());
	return 0;
}