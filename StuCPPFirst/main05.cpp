#include <iostream>
using namespace std;



int &get1()
{
	int a;
	a = 10;
	return a;
}

int* get2()
{
	int a;
	a = 10;
	return &a;
}

/**
 * 1.�����ķ���ֵΪ���õ�ʱ��,�������ջ����,���ܳ�Ϊ�������õĳ�ʼֵ,Ҳ������Ϊ��ֵʹ��
 *   ����ȫ�ֱ������߾�̬�������������ʼֵ,��ֵ������ֵ������
 * 2.
 */
int main051(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a1 = 0;
	a1 = get1();
	int &a2 = get1();
	printf("a1=%d\n", a1);//10 �����������һ������,���ǽ��յķ�ʽ��һ��
										//a1ֱ����ֱ�ӽ���һ��int��,�����᷵��һ��a�ڴ����ֵ(10)�Ŀ�����a1,�������10
	printf("a2=%d\n", a2);//���� a2������յķ�ʽ�������ý��յ�,C++����a���ڴ�ռ��ַ,
										//���Ǻ�������,a���ڵ��ڴ�ռ��ͷ�,�����������

	int *a3 = get2();
	printf("%d\n", *a3);
	return 0;
}




//�������õĺ������Ե���ֵ
int &get3()
{
	static int a = 10;
	a++;
	printf("%d\n", a);
	return a;
}
int get4()
{
	static int b = 10;
	b++;
	return b;
}
int main052(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//get4() = 20;//error �������ص����ڴ��ֵ,��������ֵ
	get3() = 50;//�������ؾ�̬����������,��������ֵ
	get3();
	return 0;
}
typedef struct T2
{
	int age;
}T2;


/**
 * C�����еĶ���ָ��
 */
int getT(T2 **pt)
{
	T2 *tmp = NULL;
	if (pt==NULL)
	{
		return -1;
	}
	tmp = (T2 *)malloc(sizeof(T2));
	if (tmp==NULL)
	{
		return -2;
	}
	tmp->age = 23;
	*pt = tmp;
	return 0;
}


/**
 * C++��ָ�������
 * �β�ʹ��ָ����������βν���ʵ��
 */
int getT2(T2 * &t)
{
	T2 *tmp = NULL;
	
	tmp = (T2 *)malloc(sizeof(T2));
	if (tmp == NULL)
	{
		return -1;
	}
	tmp->age = 25;
	t = tmp;
}

int main055(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	T2 *t = NULL;
	getT(&t);
	printf("%d\n", t->age);
	if (t!=NULL)
	{
		free(t);
		t = NULL;
	}

	T2 *t2 = NULL;
	//ָ�������,C++�������Զ�ȡ��ַ��ʵ�δ��ݵ��������β���,�β�ʹ��ָ����������βν���ʵ��
	getT2(t2);
	printf("%d\n", t2->age);
	if (t2!=NULL)
	{
		free(t2);
		t2 = NULL;
	}
	return 0;
}