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
protected://ֻ���������ڲ�����
	int a;
private:
	int c;
	int x;
};
int Parent::j = 10;//��̬��Ա����������ʾ�ĳ�ʼ��
//error LNK2001: �޷��������ⲿ���� "public: static int Parent::j" (?j@Parent@@2HA)
Parent::Parent(int x,int c)
{
	this->x = x;
	this->c = c;
	cout << "���๹�캯��" << endl;
}

Parent::~Parent()
{
	cout << "������������" << endl;
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
	cout << "���๹�캯��" << endl;
}

Child::~Child()
{
	cout << "������������" << endl;
}
/**
 * C++����̳У�
 * 1.public�̳У�����ĳ�Ա�ͺ������ʵȼ����䣻
 * 2.protected�̳У�����ĳ�Ա�ͺ���public��Ϊprotected(ֻ���������ڲ�����)����������
 * 3.private�̳�,����ĳ�Ա�ͺ���ȫ����Ϊ˽��
 * 4.����Ϊprivate�����඼���ܷ���
 * 5.����������ʱ����Ҫ���ø���Ĺ��캯������ʼ���̳����ĳ�Ա
 * 6.�������������ʱ����Ҫ���ø�������������������̳����ĳ�Ա
 * 7.�����ʱ���ȵ��ø���Ĺ��캯�����ٵ�����϶���Ĺ��캯��������Լ���
 * 8.������ʱ���ȵ�������������������͹��캯���ĵ���˳���෴
 * 9.��������������ͬ������������Ļ������˸����
 * 10.���ඨ���Public��̬��Ա�����������๲��������ѭ������ķ��ʿ��ƹ���
 */
int main0131(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Child c(1,2,3);
	//c.b = 20; //protected�̳У�ֻ���������ڲ�����
	c.print_p();
	c.Parent::print_p();
	printf("%d \n", c.j);
	return 0;
}