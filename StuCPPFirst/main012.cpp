#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"
using namespace std;


int main0121(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{

	MyString str("qeqeqweqw");
	str.print_ms();

	//拷贝构造函数
	MyString str2 = str;
	str2.print_ms();

	MyString str3;

	//重载=号操作符
	str3 = str2;
	str3.print_ms();

	MyString str4(str3);
	str4.print_ms();

	if (str4 == str3)
	{
		printf("相等\n");
	}
	else {
		printf("不相等\n");
	}

	MyString str5("adsada");
	if (str5 != str3)
	{
		printf("不相等\n");
	}
	else {
		printf("相等\n");
	}
	MyString str6;
	str6.print_ms();

	MyString str7("qewqe1312312");
	cout << str7;

	MyString str8 = "zaaaaaa";
	str8.print_ms();

	if (str8 > str3)
	{
		printf("大于\n");
	}
	else {
		printf("小于\n");
	}

	MyString str9;
	cin >> str9;
	str9.print_ms();
	return 0;
}