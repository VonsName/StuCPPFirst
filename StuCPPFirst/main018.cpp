#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Coder
{
public:
	Coder()
	{
		cout << "Coder构造函数" << endl;
	}
	virtual ~Coder() //虚析构函数,利用父类指针释放本身以及所有子类的资源
	{
		cout << "Coder析构函数" << endl;
	}
public:
	virtual int salary() = 0;
};

class PriamryCoder:public Coder
{
public:
	PriamryCoder()
	{
		cout << "PriamryCoder构造函数" << endl;
	}
	~PriamryCoder()
	{
		cout << "PriamryCoder析构函数" << endl;
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
		cout << "MiddleCoder构造函数" << endl;
	}
	~MiddleCoder()
	{
		cout << "MiddleCoder析构函数" << endl;
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
		cout << "AdvancedCoder构造函数" << endl;
	}
	~AdvancedCoder()
	{
		cout << "AdvancedCoder析构函数" << endl;
	}
public:
	virtual int salary()
	{
		return 990;
	}
};


//使用了虚析构函数,利用父类指针释放本身以及所有子类的资源
void free_mem(Coder *pc)
{
	delete pc;
}


void getSalary(Coder *pc)
{
	printf("工资为:%d\n", pc->salary());
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

