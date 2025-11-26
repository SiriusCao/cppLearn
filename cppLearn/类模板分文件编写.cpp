#include<iostream>
//类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//因此将声明和实现写到一起，文件后缀名改为.hpp
#include"Person.hpp"
using namespace std;


//int main() {
//	PersonX<string, int> p("cao", 27);
//	p.print();
//
//	system("pause");
//	return 0;
//}