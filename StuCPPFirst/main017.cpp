#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class ParentA
{
public:
	ParentA(int a)
	{
		this->a = a;
		//cout << "ParentA���캯��" << endl;
	}
	~ParentA()
	{
		//cout << "ParentA��������" << endl;
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
		//cout << "ChildA���캯��" << endl;
		this->b = b;
	}
	~ChildA()
	{
		//cout << "ChildA��������" << endl;
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
 * 1.�����������麯����ʱ��,������������������һ���麯����;
 * 2.�麯������һ���洢�����Ա����ָ������ݽṹ,�洢ÿ���麯������ڵ�ַ
 * 3.�����麯����ʱ��,ÿ�������ж���һ��ָ���麯�����ָ��(vptrָ��);
 * 4.���������������ֱ���vptrָ��
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
//	pa->print_pa();//error �δ��� ����͸�����������ͬ����������,pa++��ca++�Ĳ�����һ��
							//ֻ�е�����͸������еĳ�Ա������С���(�����sizeof()��С�͸���Ĵ�Сһ��)
					//��ʱ��(����û������µĳ�Ա����),�����ָ�벽���ź͸����ָ�벽��һ��
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
	virtual void fight() = 0;//���麯��
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
 * 1.���麯�� ���౻��Ϊ������,���ܴ�������
 */
int main0172(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
//	Tigger t;//�����಻�ܱ�ʵ����
	Tigger *t1 = NULL;
	Tigger2 t2;
	t1 = &t2;
	t1->fight();
	Tigger &t = t2;
	t.fight();
	return 0;
}
