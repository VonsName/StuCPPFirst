#include <iostream>


/**
 * const��#define��const���ɱ���������ģ��ṩ���ͼ�����������
 *				   #define����Ԥ�������	
 */
int main031(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	//C++��const���εĳ�������������һ�ŷ��ű����ʱ��û�з����ڴ�ռ�
	//ֻ�е�ʹ��&ȡ��ַ��ʱ����ߵ�const���εı���Ϊȫ�ֱ�����ʱ��Ż�����ڴ�ռ�
	const int a = 10;
//	a = 20;//error ���������޸�
	int *p = NULL;
	//p = &a; //error const���εı���(����)����ȡ��ַ��ָ�����p
	p = (int *)&a;
	*p = 1000; //const���εı���a���ܱ��޸ģ�����C�����п��������޸�
			//����C++�����Ŀ�����һ���ڴ�ռ䣬�޸ĵ��Ǹ��ڴ�ռ��ֵ��
	printf("%d\n", a);//�������10��

	const int *p1 = NULL;
	p1 = &a;//C++ֻ��ʹ��const���ε�ָ�����������ָ�룩ָ��const���εı�����������
			//����ָ�루������ָ�룩��ָ������ָ��
	//*p1 = 100;//error �����޸�
	return 0;
}


void fun1()
{
	#define  M 10;

}

void fun2()
{
	//printf("%d\n", M);//ERROR
}

int main032(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	fun1();
	fun2();
	return 0;
}