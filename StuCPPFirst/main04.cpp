#include <iostream>


/**
 * C++����
 * 1.���ú���һ�������������ʼ��
 * 2.������ָ��һ����ռ4���ֽڣ�
 */
int main041(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int a = 10;
	//���ñ���Ҫ��ʼ��
	int &b = a;//b������a��һ��������
				//b��a�൱����һ���������޸��ĸ�����Ӱ������һ��
	printf("b=%d\n", b);
	printf("a=%d\n", a);
	b = 100;
	printf("b=%d\n", b);
	printf("a=%d\n", a);

	a = 200;
	printf("b=%d\n", b);
	printf("a=%d\n", a);
	return 0;
}


void swap01(int *x, int *y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap02(int &x, int &y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

struct T1
{
	char name[64];
	int age;

	int &a;
	int &b;
};
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int x = 10;
	int y = 20;
	swap01(&x, &y);//ʹ��ָ�뽻��
	printf("x=%d y=%d\n", x, y);

	swap01(&x, &y);//ʹ�����ý���
	printf("x=%d y=%d\n", x, y);

	printf("sizeof(T1)=%d\n", sizeof(T1));
	return 0;
}