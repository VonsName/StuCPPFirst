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
	cout << "a���캯��" << endl;
}

A::~A()
{
	cout << "a����������" << endl;
}
class B
{
public:
	~B();
	B(int _b1);
private:
	int b1;
	A a1;//��ִ�б���϶���Ĺ��캯�����ж�����ն���˳��
		//	���������͹��캯���ĵ���˳���෴
};

B::B(int _b1):a1(_b1)//���캯����ʼ���б�,��ִ��a����Ĺ��캯��
{
	b1 = _b1;
	cout << "b���캯��" << endl;
}
B::~B()
{
	cout << "b��������" << endl;
}

/**
 * ʹ��malloc���������ڴ治�����ù��캯��
 * ʹ��free�ͷŶ����ڴ��ʱ�򲻻������������
 * C++����ĳ�Ա�����ͳ�Ա�����Ƿֿ��洢��
 * C++�о�̬��Ա�����;�̬��Ա������������ģ���̬��Ա�����Ƿ���ȫ������
 * ��ͨ��Ա��������һ��ָ��ǰ�����thisָ�룬����̬��Ա����û��
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


//	B *b0 = (B *)malloc(sizeof(B));//malloc������ù��캯��
	//free(b0);//free���������������

	B *b = new B(5);//new(������ڴ�) ����ù��캯��
	delete b;//delete �������������
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
	int mgetLength() const //����������Ա���������ݵ������޶���
											//const����ֻ�ܵ���const����
	{
		return initLen;
	}
	void setData(int index, int value)  //const
						//д�ں��������const���ε������ص�thisָ��ָ����ڴ�ռ�
	{							//thisָ��ָ����ڴ涼�����޸�(thisָ��ĳ�Ա����)
		data[index] = value;
		++length;
		//this->initLen = 100;
		//this->data = NULL;
	}

	//����[]������
	//void operator [](int index);

	int& operator[](int index);

	//����=�Ų�����
	Array& operator=(Array &a);

	//����==������
	bool operator==(const Array &a);

	//����!=������
	bool operator!=(const Array &a);

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

//����[]������
int& Array::operator[](int index)
{
	return *(data + index);
}

//����=�Ų�����
Array& Array::operator=(Array &a)
{
	this->initLen = 0;
	if (this->data != NULL)
	{
		delete[] this->data;
	}
	
	this->initLen = a.initLen;
	this->data = new int[this->initLen];
	for (int i = 0; i < this->initLen; i++)
	{
		this->data[i] = a.data[i];
	}
	return *this;
}


//����==������
bool Array::operator==(const Array &a)
{
	bool flag;
	if (this->initLen != a.initLen)
	{
		flag = false;
		return flag;
	}
	for (int i=0;i<this->initLen;i++)
	{
		if (this->data[i] == a.data[i])
		{
			flag = true;
		}
		else {
			flag = false;
		}
	}
	return flag;
}

//����!=������
bool Array::operator!=(const Array &a)
{
	return !(*this == a);
}

Array::Array(const Array & ra)
{
	this->initLen = ra.initLen;
	//this->data = new int[ra.mgetLength()];//����������Ա���������ݵ������޶���,
	this->data = new int[this->initLen];			//const����ֻ�ܵ���const����
	for (int i = 0; i < this->initLen; i++)
	{
		//this->setData(i, ra.getData(i));
		this->data[i] = ra.data[i];
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
	cout << "��������" << endl;
}


//��������ֵ����ֵ����Ҫ����һ������
int main092(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Array arr;
	for (int i = 0; i < 10; i++)
	{
		//arr.setData(i, i + 1);
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		//printf("%d ", arr.getData(i));
		printf("%d ", arr[i]);
	}
	printf("\n");
	//printf("%d\n", arr.mgetLength());

	Array a2 = arr;//���ÿ������캯��
	for (int i = 0; i < 10; i++)
	{
		//printf("%d ", a2.getData(i));
		printf("%d ", a2[i]);
	}
	printf("\n");

	Array a3;
	//����=�Ų�����
	a3 = a2;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a3[i]);
	}
	printf("\n");

	if (a3 == a2)
	{
		printf("���\n");
	}
	else
	{
		printf("�����\n");
	}

	Array a4;
	for (int i = 0; i < 10; i++)
	{
		a4[i] = i + 3;
	}

	if (a4 == a2)
	{
		printf("���\n");
	}
	else
	{
		printf("�����\n");
	}


	if (a4 != a2)
	{
		printf("�����\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;
}