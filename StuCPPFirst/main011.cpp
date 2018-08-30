#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


class Complex
{
public:
	Complex();
	Complex(int a,int b);
	~Complex();
public:

	//��Ա��������<<������  �������������ʹ�ó�Ա��������
	//ostream& operator <<(ostream &out);
	

	//������Ԫ��������<<������
	friend ostream& operator <<(ostream &out,const  Complex &c);

	//������Ԫ���������� >>������
	friend istream& operator >> (istream &in, vector <int> &v);

	friend istream& operator << (istream &in, vector <int> &v);

private:
	int a;
	int b;
};

Complex::Complex()
{
}

Complex::Complex(int a,int b)
{
	this->a = a;
	this->b = b;
}

Complex::~Complex()
{
}

//��Ա��������<<������ �������������ʹ�ó�Ա��������
//ostream& Complex::operator<<(ostream &out)
//{
//	out << this->a << "," << this->b << endl;
//	return out;
//}


//������Ԫ��������<<������
ostream& operator <<(ostream &out, const  Complex &c) {
	out << c.a << "," << c.b << endl;
	return out;
 }


//������Ԫ���������� >>������
istream& operator >> (istream &in,  vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		in >> v[i];
	}
	return in;
}


//������Ԫ���������� <<������
ostream& operator << (ostream &out, vector <int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return out;
}


//���������
int main0111(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	Complex c1(1, 2),c2(3,5);
	cout << c1 <<"\n"<< c2;

	cout << "�����볤��" << endl;
	int k;
	cin >> k;


	vector<int> v1(k);
	cin >> v1;

	cout << v1 << endl;
	return 0;
}


class User
{
public:
	User();
	User(int age,const char *name);
	~User();

	void operator =(User &u);

public:
	void print_u() {
		printf("age=%d  = name=%s\n", this->age, this->name);
	}

private:
	int age;
	char *name;
};

User::User()
{
}

void User::operator=(User &u)
{
	//���ͷŵ�ԭ�����ڴ�
	if (this->name != NULL)
	{
		//free(this->name);
		delete[] this->name;
		this->name = NULL;
	}
	this->age = u.age;
	this->name = (char *)malloc(sizeof(char)*strlen(u.name) + 1);
	strcpy(this->name, u.name);
}
User::User(int age, const char *name)
{
	this->age = age;
	//this->name = (char *)malloc(sizeof(char)*strlen(name)+1);
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}
User::~User()
{
	if (this->name != NULL)
	{
		//free(this->name);
		delete[] this->name;
		this->name = NULL;
	}
}

/**
 * 18��ʱ��
 */
//=�Ų����������ȼ��Ǵ�������
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	User u1(23, "lisi");
	u1.print_u();
	User u2;
	u2 = u1;//���صȺŲ�����,������;���������,ֻ�Ǽ򵥵ĸ�ֵ����,�ͷ��ڴ��ʱ������down��
	u2.print_u();
	return 0;
}