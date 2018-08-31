#pragma once
#include <iostream>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(char *data);
	MyString(const MyString &str);
	~MyString();
	MyString& operator=(MyString& str);
	MyString& operator=(const char *str);
	MyString& operator()(MyString& str);
	bool operator==(MyString& str);
	bool operator!=(MyString& str);
	char& operator[](int index);
	friend ostream& operator<<(ostream& out,const MyString &str);
	void print_ms();
	int myLen();
private:
	int size;
	char *data;
};

