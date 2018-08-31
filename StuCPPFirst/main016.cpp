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
	cout << "Parent1���캯��" << endl;
	p = new char[10];
	strcpy(p, "Parent1");
}

Parent1::~Parent1()
{
	cout << "Parent1��������" << endl;
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
	cout << "Child1���캯��" << endl;
	p = new char[10];
	strcpy(p, "Child1");
}

Child1::~Child1()
{
	cout << "Child1��������" << endl;
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

	void test()//û��virtual�ؼ���  �����ض���
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
	cout << "Child2���캯��" << endl;
	p = new char[10];
	strcpy(p, "Child2");
}

Child2::~Child2()
{
	cout << "Child2��������" << endl;
	if (p != NULL)
	{
		delete[] p;
	}
}


/**
 * 1.C++�ж�̬ ->�ڷ�������ǰ�����virtual�ؼ���
 * 2.��̬����->�����ƥ��,�����ڱ���׶�ʵ��;��������ʹ�þ�̬����;
 * 3.��̬����->����� ƥ������������ʱ����;if switch
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


//���ֳ�������,ͨ������ָ���ͷ��ڴ�,ִֻ���˸������������
//�п��ܻ�����ڴ�й©
//����취:�ڸ������������ǰ����virtual�ؼ���(����������),
//�Ϳ���ͨ������ָ��ִ�������������������,���������������Դ
void howtoDelte(Parent1 *p1)
{
	delete p1;
}

/**
 * 1.������������ʱ��,���ȴӶ����µ��ø���Ĺ��캯��,���������빹�캯���ĵ���˳���෴
 * 2.����->
 *		���ر�����ͬһ�����н���
 *		�������ڱ����ڼ���ݲ������ͺ͸������������ĵ���
 *		�����޷����ظ���ĺ���,�����ͬ�������ᱻ�����ͬ����������
 * 3.��д->
 *		��д���뷢���ڸ��������֮��
 *		���ұ����븸���ͬ����������ȫ��ͬ��ԭ��
 *		ʹ��virtual�ؼ���֮��,�ܲ�����̬(�����ʹ��virtual�ؼ���,���ض���,�����ε�����ĺ���);
 *		��̬��������ʱ�ڸ��ݾ���Ķ������Ͳ��������ĵ���
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Child2 *c2 = new Child2;
	c2->test();
	c2->Parent1::test();
//	c2->print(1, 2, 3); //error û�����غ������� 3 ������ ->C++��������Ϊ�Ǻ������� ���෢�������Ƹ���

	Parent1 *p1 = NULL;
	p1 = new Parent1;
	p1->print(1, 2, 3);
	Child1 c1;
	p1 = &c1;
	p1->print(1, 2, 3);
	howtoDelte(c2);
	return 0;
}