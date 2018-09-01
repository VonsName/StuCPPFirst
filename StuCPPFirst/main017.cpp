#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class ParentA
{
public:
	ParentA(int a)
	{
		this->a = a;
		//cout << "ParentA构造函数" << endl;
	}
	~ParentA()
	{
		//cout << "ParentA析构函数" << endl;
	}
	virtual void print_pa()
	{
		printf("ParentA..............\n");
	}
protected:
private:
	int a;
};
class ChildA:public ParentA
{
public:
	ChildA(int a,int b):ParentA(a)
	{
		//cout << "ChildA构造函数" << endl;
		this->b = b;
	}
	~ChildA()
	{
		//cout << "ChildA析构函数" << endl;
	}
	virtual void print_pa()
	{
		printf("ChildA..........\n");
	}
protected:
	
private:
	int b;
};

void play(ParentA *p)
{
	p->print_pa();
}


/**
 * 1.当类中声明虚函数的时候,编译器会在类中生成一个虚函数表;
 * 2.虚函数表是一个存储类虚成员函数指针的数据结构,存储每个虚函数的入口地址
 * 3.存在虚函数的时候,每个对象中都有一个指向虚函数表的指针(vptr指针);
 * 4.父类对象和子类对象分别有vptr指针
 */
int main01701(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	/*ParentA pa(3);
	ChildA ca(1,2);
	play(&pa);
	play(&ca);*/
	ParentA *pa = NULL;
	ChildA *ca = NULL;
	ChildA arr[] = {ChildA(1,2),ChildA(3,4),ChildA(5,6)};
	pa = arr;
	ca = arr;
	pa->print_pa();
	ca->print_pa();
	pa++;
	ca++;
//	pa->print_pa();//error 段错误 子类和父类是两个不同的数据类型,pa++和ca++的步长不一样
							//只有当子类和父类所有的成员个数大小相等(子类的sizeof()大小和父类的大小一致)
					//的时候(子类没有添加新的成员变量),子类的指针步长才和父类的指针步长一样
	ca->print_pa();
	return 0;
}



class Tigger
{
public:
	Tigger()
	{

	}
	~Tigger()
	{

	}
public:
	virtual void fight() = 0;//纯虚函数
protected:
private:
};

class Tigger2:public Tigger
{
public:
	Tigger2()
	{

	}
	~Tigger2()
	{

	}
public:
	virtual void fight()
	{
		cout << "fight" << endl;
	}
protected:
private:
};
/**
 * 1.纯虚函数 该类被称为抽象类,不能创建对象
 */
int main0172(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	Tigger t;//抽象类不能被实例化
	Tigger *t1 = NULL;
	Tigger2 t2;
	t1 = &t2;
	t1->fight();
	Tigger &t = t2;
	t.fight();
	return 0;
}
