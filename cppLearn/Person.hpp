#pragma once
#include<iostream>
using namespace std;

template<class T1,class T2>
class PersonX {
private:
	T1 name;
	T2 age;

public:
	PersonX(T1 name, T2 age);
	void print();
};


//类模板中成员函数类外实现时，需要加上模板参数列表
template<class T1, class T2>
PersonX<T1, T2>::PersonX(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}
//类模板中成员函数类外实现时，需要加上模板参数列表
template<class T1, class T2>
void PersonX<T1, T2>::print() {
	cout << "name=" << this->name << ",age=" << age << endl;
}

