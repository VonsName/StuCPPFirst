#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string.h>
#include <iostream>
using namespace std;



MyString::MyString()
{
}


MyString::MyString(char *str)
{
	if (str == NULL)
	{
		int len = 1;
		this->data = new char[len];
		strcpy(this->data, "");
	}
	else {
		int len = strlen(str) + 1;
		this->data = new char[len];
		strcpy(this->data, str);
	}
	
}

MyString::MyString(const MyString &str)
{
	this->data = new char[strlen(str.data) + 1];
	strcpy(this->data, str.data);
}

MyString::~MyString()
{
	if (this->data!=NULL)
	{
		delete[] this->data;
	}
}

//重载=号操作符(赋值)
MyString& MyString::operator=(const char *str)
{
	if (str == NULL)
	{
		return *this;
	}
	this->data = new char[strlen(str) + 1];
	unsigned int i = 0;
	for (i = 0; i < strlen(str); i++);
	{
		data[i] = str[i];
	}
	data[i] = '\0';
	return *this;
}

//重载=号操作符(初始化)
MyString& MyString::operator=(MyString& str)
{
	if (this->data!=NULL)
	{
		delete[] this->data;
	}
	int len = strlen(str.data) + 1;
	this->data = new char[len];
	strcpy(this->data, str.data);
	return *this;
}


//重载()操作符
MyString& MyString::operator()(MyString& str)
{
	*this = str;
	return *this;
}

//重载 == 操作符
bool MyString::operator==(MyString& str)
{

	if (this->data != NULL&&str.data != NULL)
	{
//		return (strcmp(this->data, str.data) == 0);
		int i = 0;
		/*while (*(this->data+i)!='\0'&&(*(this->data+i) != '\0'))
		{
			if (*(this->data+i)!=*(str.data+i))
			{
				return false;
			}
			i++;
		}*/
		while (this->data[i] != '\0'&&str.data[i] != '\0')
		{
			if (this->data[i] != str.data[i])
			{
				return false;
			}
			i++;
		}
	}
	return true;
}

//重载 != 操作符
bool MyString::operator!=(MyString& str)
{
	return !(*this == str);
}

//重载[]
char& MyString::operator[](int index)
{
	return this->data[index];
}

void MyString::print_ms()
{
	//printf("%s\n", this->data);
	cout << *this;
}

int MyString::myLen()
{
	return strlen(this->data);
}

ostream& operator<<(ostream& out, const MyString &str)
{
	if (str.data == NULL)
	{
		return out;
	}
	for (unsigned int i=0;i<strlen(str.data);i++)
	{
		out << str.data[i];
	}
	out << endl;
	return out;
}
