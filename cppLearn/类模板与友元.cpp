#include<iostream>
using namespace std;

//类外实现 - 先做类模板声明，再做函数模板定义和实现，再做友元
template<class T1,class T2>class People;

//函数模板定义
template<class T1, class T2>void print2(People<T1,T2> p);

template<class T1,class T2>
class People {
	//1、全局函数配合友元   类内实现
	template<class T>
	friend void print1(T p) {
		cout << "name=" << p.name << ",age=" << p.age << endl;
	}
	//2、全局函数配合友元  类外实现
	friend void print2<>(People<T1, T2> p);

private:
	T1 name;
	T2 age;
public:
	People(T1 n, T2 a) :name(n), age(a) {}
};

//函数模板实现
template<class T1,class T2>
void print2(People<T1,T2> p) {
	cout << "name=" << p.name << ",age=" << p.age << endl;
}

//int main() {
//	People<string, int> p("cao", 30);
//	print2(p);
//
//	system("pause");
//	return 0;
//}