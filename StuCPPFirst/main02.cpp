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

//�Զ��������ռ�
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
	int *px = &x; //C++����������ʹ��&ȡregister���εı���
	printf("px=%d\n", *px);

	bool flag = true;//bool��ֵֻΪ1����0��true /false
	flag = 10;
	printf("%d\n", flag);//���1

	int i = 10, j = 20;
	(i > j ? i : j) = 30;//C++�б��ʽ��������ֵ�����ʽ���ص��Ǳ����ı���(�����˱������ڴ��ַ)
						//��������C���Ի��ܷ��ر�����ֵ
	printf("j=%d\n", j);

	const int *p1 = &x;
	//*p1 = 200; error//ָ����ڴ�ռ䲻�ܱ��޸�
	p1 = NULL;

	int * const p2 = &x;
	//p2 = NULL; error //ָ����������ܱ��޸�
	*p2 = 100;
	return 0;
}