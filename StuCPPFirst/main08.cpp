#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;


class Name
{
public:
	Name();
	~Name();
	Name(const Name &rn);
	Name(const char *name);
public:
	char *getName()
	{
		return name;
	}
private:
	char *name;
};

Name::Name()
{
}
/**
 * �������캯�����Լ�ʵ�����
 */
Name::Name(const char *src)
{
	assert(src);
	int len = strlen(src) + 1;
	name = (char *)malloc(sizeof(char)*len);
	strcpy(name, src);
}
Name::Name(const Name &rn)
{
	int len = strlen(rn.name) + 1;
	name = (char *)malloc(sizeof(char)*len);
	strcpy(name, rn.name);
}
Name::~Name()
{
	if (name!=NULL)
	{
		free(name);
	}
}

/**
 * 1.������û�ж��幹�캯���Ϳ������캯����C++��������Ĭ��һ���������캯���͹��캯��
 * 2.�����ж����˿������캯���������������ṩ�޲������캯��
 */
int main081(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Name n("lisi");
	printf("%s\n", n.getName());
	Name n1 = n;
	printf("%s\n", n1.getName());
	Name n3(n1);
	printf("%s\n", n3.getName());
	Name n4("����");
//	n4 = n3;//�򵥵ĸ�ֵ������ǳ������n4����ָ����n3��n4ԭ�����ڴ�й©���ͷ��ڴ��ʱ��
			//�൱���ͷ���n3���Σ�����δ��� ����=�Ų�����
	printf("%s\n", n4.getName());
	return 0;
}