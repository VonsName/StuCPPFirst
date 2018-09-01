#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Coder
{
public:
	Coder()
	{
		cout << "Coder���캯��" << endl;
	}
	virtual ~Coder() //����������,���ø���ָ���ͷű����Լ������������Դ
	{
		cout << "Coder��������" << endl;
	}
public:
	virtual int salary() = 0;
};

class PriamryCoder:public Coder
{
public:
	PriamryCoder()
	{
		cout << "PriamryCoder���캯��" << endl;
	}
	~PriamryCoder()
	{
		cout << "PriamryCoder��������" << endl;
	}
public:
	virtual int salary()
	{
		return 330;
	}
};
class MiddleCoder:public Coder
{
public:
	MiddleCoder()
	{
		cout << "MiddleCoder���캯��" << endl;
	}
	~MiddleCoder()
	{
		cout << "MiddleCoder��������" << endl;
	}
public:
	virtual int salary()
	{
		return 660;
	}
};

class AdvancedCoder:public Coder
{
public:
	AdvancedCoder()
	{
		cout << "AdvancedCoder���캯��" << endl;
	}
	~AdvancedCoder()
	{
		cout << "AdvancedCoder��������" << endl;
	}
public:
	virtual int salary()
	{
		return 990;
	}
};


//ʹ��������������,���ø���ָ���ͷű����Լ������������Դ
void free_mem(Coder *pc)
{
	delete pc;
}


void getSalary(Coder *pc)
{
	printf("����Ϊ:%d\n", pc->salary());
}

int main0181(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	
	Coder *pc1 = new PriamryCoder;
	Coder *pc2 = new MiddleCoder;
	Coder *pc3 = new AdvancedCoder;
	getSalary(pc1);
	getSalary(pc2);
	getSalary(pc3);


	free_mem(pc1);
	free_mem(pc2);
	free_mem(pc3);

	return 0;
}

