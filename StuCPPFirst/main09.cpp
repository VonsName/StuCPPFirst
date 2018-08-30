#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class A
{
public:
	A(int _a);
	~A();

private:
	int a;
};

A::A(int _a)
{
	a = _a;
	cout << "a构造函数" << endl;
}

A::~A()
{
	cout << "a的析构函数" << endl;
}
class B
{
public:
	~B();
	B(int _b1);
private:
	int b1;
	A a1;//先执行被组合对象的构造函数，有多个按照定义顺序，
		//	析构函数和构造函数的调用顺序相反
};

B::B(int _b1):a1(_b1)//构造函数初始化列表,先执行a对象的构造函数
{
	b1 = _b1;
	cout << "b构造函数" << endl;
}
B::~B()
{
	cout << "b析构函数" << endl;
}

/**
 * 使用malloc分配对象的内存不糊调用构造函数
 * 使用free释放对象内存的时候不会调用析构函数
 * C++中类的成员变量和成员函数是分开存储的
 * C++中静态成员函数和静态成员变量是属于类的，静态成员变量是放在全局区的
 * 普通成员函数包含一个指向当前对象的this指针，而静态成员函数没有
 */
int main091(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//B b(2);

	int *p = new int;
	*p = 20;
	printf("%d\n", *p);
	delete p;
	int *p1 = new int(30);
	printf("%d\n", *p1);
	delete p1;

	int *p3 = new int[3];
	p3[0] = 11;
	p3[1] = 12;
	p3[2] = 13;
	delete []p3;


//	B *b0 = (B *)malloc(sizeof(B));//malloc不会调用构造函数
	//free(b0);//free不会调用析构函数

	B *b = new B(5);//new(分配堆内存) 会调用构造函数
	delete b;//delete 会调用析构函数
	//system("pause");
	return 0;
}


class Array
{
public:
	Array();
	Array(int len);
	~Array();
	Array(const Array & ra);
	int mgetLength() const
	{
		return length;
	}
	void setData(int index, int value)  const
						//写在函数后面的const修饰的是隐藏的this指针指向的内存空间
	{							//this指针指向的内存都不能修改(this指向的成员变量)
		data[index] = value;
		//++length;
		//this->initLen = 100;
		//this->data = NULL;
	}


	 int getData(int index) const
	{
		return data[index];
	}
	 int x;
private:
	int initLen=10;
	int length;
	int *data;
};

Array::Array()
{
	data = new int[initLen];
}
Array::Array(const Array & ra)
{
	this->data = new int[ra.mgetLength()];
	for (int i=0;i<this->mgetLength();i++)
	{
		data[i] = ra.data[i];
	}
}
Array::Array(int len)
{
	initLen = len;
	data = new int[initLen];
}
Array::~Array()
{
	if (data!=NULL)
	{
		delete[]data;
	}
	cout << "析构函数" << endl;
}
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Array arr;
	for (int i = 0; i < 10; i++)
	{
		arr.setData(i, i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr.getData(i));
	}
	printf("\n");
	printf("%d\n", arr.mgetLength());

	Array a2 = arr;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a2.getData(i));
	}
	return 0;
}