#include <iostream>
using namespace std;



int main061(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	{
		int x = 10;
		//������,�ñ�������ֻ������,����ͨ��rx�޸�x��ֵ
		const int &rx = x;//�ñ�����ʼ��������
		//rx = 20;//error,������,����ͨ���������޸�ָ����ڴ�ռ�
		int y = 90;
		//rx = y;//error,������,�����޸ĳ����õ�ָ��,
					//�൱��ָ���const int *const a;���������Լ�ָ����ڴ�ռ䶼�����޸�
	}

	{
		//����������ʼ��������
		//int &c = 40;//error 
		const int &a = 40;
	}
	{
		//��ͨ����
		int x = 10;
		int &rx = x;
		printf("%d\n", rx);
		int y = 90;
		rx = y;
		printf("%d\n", rx);
	}
	return 0;
}



#define MYFUNC(a,b) (a < b ? a:b)
//���inline��һ��,++��������ʱ��
inline int myfun(int a, int b)
{
	return (a < b ? a : b);
}
/**
 * �����������������Ͷ���д��һ��
 * C++������ֱ�Ӱ���������������ں������õĵط�
 * ��������ô����ͨ�������õĶ��⿪��(ѹջ,��ת,����);
 */
int main062(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a = 1, b = 3;
	int y=MYFUNC(++a, b);// ���滻��չ��->(++a < b ? ++a:b)
	//int y = (++a < b ? ++a : b);//2<3 ����a ,Ȼ��++a ->���3
	printf("%d\n", y);//���->3

	a= 1; b= 3;
	int x = myfun(++a, b);
	printf("%d\n", x);//���->2
	return 0;
}


/**
 * 1.C++������Ĭ�ϲ���,�����Ǵ�������Ĺ���,�ұߵı��붼��Ĭ�ϲ���
 * 2.����ռλ����,�������õ�ʱ��Ҳ���봫��
 */

void foo1(int a, int b, int)
{
	cout << "a=" << a << ",b=" << b << endl;
}

void foo(int a, int b, int = 0)
{
	cout << "a=" << a << ",b=" << b << endl;
}
int main063(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	foo1(1, 2,3);//����ռλ����,�������õ�ʱ��Ҳ���봫��
	foo(1, 2);//ok
	foo(1, 2, 3);//ok
	return 0;
}



//��������
void print_a(int a)
{
	cout << "a=" << a  << endl;
}

void print_a(int a, int b)
{
	cout << "a=" << a << ",b=" << b << endl;
}

void print_a(int a, int b,int c=5)
{
	cout << "a=" << a << ",b=" << b << ",c=" << c <<endl;
}

//�������غͲ�����˳���޹�
//void print_a(int c, int a, int b)
//{
//	cout << "a=" << a << ",b=" << b << "c=" << c << endl;
//}

void print_a(double a, double b)
{
	cout << "a=" << a << ",b=" << b << endl;
}

/**
 * ����������:
 * 0.��������ͬ
 * 1.����������ͬ;
 * 2.���������Ͳ�ͬ;
 * 3.�뺯���ķ���ֵ�޹�
 * 4.����������Ĭ�ϲ�����һ���ʱ��,����ֵ��õĶ�����
 */
int main064(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	print_a(1.9, 2.2);
	//double�Զ���������ת��Ϊint����
	print_a(1.9, 2.2,3.3);

	//print_a(10,20); //error ��Ϊ��Ĭ�ϲ���,������ƥ���ʱ������˶�����,�����غ����ĵ��ò���ȷ

	print_a(5);//ok ֻƥ�䵽��һ��������
	return 0;
}


/**
 * ����ָ��
 */

//����һ����������
typedef void(FUN)(int a);


//����һ������ָ������
typedef void(*PFUN)(double a,double b);

//ֱ�Ӷ���һ������ָ�����
void(*MYFUN)(int a, int b);


int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{


	//����һ������ָ�����
	FUN *pf = NULL;
	pf = print_a;//��һ����������ڵ�ַ��ֵ������ָ�����
	pf(5);
	
	//����һ������ָ�����
	PFUN pfun = NULL;
	pfun = print_a;//��һ����������ڵ�ַ��ֵ������ָ�����
	double i = 8.8,  j = 9.9;
	pfun(i, j);//ƥ�䵽������int���β��������ĺ���

	//ֱ�Ӷ���һ������ָ�����
	void(*MYPFUN)(int a, int b);
	MYPFUN = print_a;//��һ����������ڵ�ַ��ֵ������ָ�����
	MYPFUN(1, 2);
	//print_a(5, 7);//error ->����Ĭ�ϲ����ͺ���������һ��,ֱ�ӵ��ó��ֶ�����,�Ժ����ĵ��ò���ȷ
	return 0;
}