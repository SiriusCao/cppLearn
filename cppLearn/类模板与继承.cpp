#include<iostream>
using namespace std;
//当类模板碰到继承时，需要注意一下几点：
//
//* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//* 如果不指定，编译器无法给子类分配内存
template<class T>
class A {
public :
	T t;
};

class B :public A<int> {
public:
	B() {
		cout << "B狗崽方法" << endl;
	}
};
//* 如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1,class T2>
class C :public A<T1> {
public:
	T2 t2;

	C() {
		cout << "C构造方法"<<endl;
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

//int main() {
//	B b;
//
//	C<int, double> c;
//
//	system("pause");
//	return 0;
//}