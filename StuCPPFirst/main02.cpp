#include <iostream>


class Teacher
{
public:
	Teacher();
	~Teacher();

private:
	int a = 20;
};

Teacher::Teacher()
{
}

Teacher::~Teacher()
{
}

//自定义命名空间
namespace A 
{
	int a = 20;
}
namespace B
{
	int a = 30;
}

int main02(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("%d\n", A::a);
	printf("%d\n", B::a);

	register int x = 20;
	int *px = &x; //C++编译器可以使用&取register修饰的变量
	printf("px=%d\n", *px);

	bool flag = true;//bool的值只为1或者0；true /false
	flag = 10;
	printf("%d\n", flag);//输出1

	int i = 10, j = 20;
	(i > j ? i : j) = 30;//C++中表达式可以做左值，表达式返回的是变量的本身(返回了变量的内存地址)
						//而不是像C语言汇总返回变量的值
	printf("j=%d\n", j);

	const int *p1 = &x;
	//*p1 = 200; error//指向的内存空间不能被修改
	p1 = NULL;

	int * const p2 = &x;
	//p2 = NULL; error //指针变量本身不能被修改
	*p2 = 100;
	return 0;
}