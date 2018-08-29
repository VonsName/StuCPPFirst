#include <iostream>
using namespace std;



/**
 * 1.当类中没有定义构造函数和拷贝构造函数，C++编译器会默认一个拷贝构造函数和构造函数
 * 2.当类中定义了拷贝构造函数，编译器不会提供无参数构造函数
 */
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	return 0;
}