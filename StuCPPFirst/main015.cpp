#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class AA
{
public:
	AA();
	~AA();
public:
	int a;
private:

};

AA::AA()
{
	cout << "����AA�Ĺ��캯��" << endl;
}

AA::~AA()
{
}
class BB:virtual public AA //����virtual AA����Ĺ��캯��ֻ����һ��
{
public:
	BB();
	~BB();
	int b;
	int x;
private:

};

BB::BB()
{
}

BB::~BB()
{
}

class CC:virtual public AA //����virtual AA����Ĺ��캯��ֻ����һ��
{
public:
	CC();
	~CC();
	int c;
	int x;
private:

};

CC::CC()
{

}


CC::~CC()
{

}
class DD: public CC,public BB
{
public:
	DD();
	~DD();

private:

};

DD::DD()
{

}

DD::~DD()
{

}

//virtual ռ���ڴ�
int main0151(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//�̳еĶ����ԣ�����A��������a,��B����C���̳�����A
//	CC c1;
//	c1.a = 20;
//	BB b1;
//	b1.a = 20;
	DD dd;
//	dd.a = 30; //ERROR a����ȷ 
	dd.a = 80; //����취����̳�virtual
//	dd.x = 99; //ERROR a����ȷ 
	return 0;
}