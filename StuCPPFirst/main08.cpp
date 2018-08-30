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
 * 拷贝构造函数，自己实现深拷贝
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
 * 1.当类中没有定义构造函数和拷贝构造函数，C++编译器会默认一个拷贝构造函数和构造函数
 * 2.当类中定义了拷贝构造函数，编译器不会提供无参数构造函数
 */
int main081(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Name n("lisi");
	printf("%s\n", n.getName());
	Name n1 = n;
	printf("%s\n", n1.getName());
	Name n3(n1);
	printf("%s\n", n3.getName());
	Name n4("王五");
//	n4 = n3;//简单的赋值操作，浅拷贝，n4重新指向了n3，n4原来的内存泄漏，释放内存的时候
			//相当于释放了n3两次，程序段错误 重载=号操作符
	printf("%s\n", n4.getName());
	return 0;
}