#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testp()
{
	printf("hello\n");
}

/**
 * ����ָ��
 */
int main0201(int argc,char *argv[])
{

	typedef void(IMyFunType)();//����һ����������
	IMyFunType *m = NULL;
	m =	&testp;
	m();


	typedef void(*PIMyFunType)();//����һ������ָ������
	PIMyFunType pm = NULL;
	pm = testp;
	pm();

	void(*FunPointer)();//ֱ������һ������ָ�����
	FunPointer = testp;
	FunPointer();
	return 0;
}






typedef void(*PIMyFunType)();//����һ������ָ������

void mainFun(PIMyFunType ptype)
{
	ptype();
}


//ֱ������һ������ָ��������β�
void mainFun1(void(*pointerMyFunType)())
{
	pointerMyFunType();
}

/**
 * ����ָ������,�Ѻ��������ͷ���ֵ������ǰ����Լ��
 */
int main(int argc, char *argv[])
{
	mainFun(testp);//����ָ������������

	mainFun1(testp);
	return 0;
}
