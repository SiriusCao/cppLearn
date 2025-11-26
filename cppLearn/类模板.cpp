#include<iostream>
using namespace std;

//类模板在模板参数列表中可以有默认参数
template<class T,class Y=int>
class Person {
public:
	T name;
	Y age;
	
	Person(){
	}
	Person(T name, Y age) {
		this->name = name;
		this->age = age;
	}

	void print() {
		cout << "Person print()" << endl;
	}
};

ostream& operator<<(ostream& out, Person<string,int> &p) {
	out << "name=" << p.name << ",age=" << p.age;
	return out;
}

template<class T>
class Police {
public:
	T person;

	void check() {
		//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
		person.print();
	}
};

//通过类模板创建的对象，可以有三种方式向函数中进行传参:
//1、指定传入的类型
void operate1(Person<string ,int> p){
	p.print();
}
void test1() {
	Person<string, int>p1("cao", 27);
	operate1(p1);
}

//2、参数模板化(本质是个函数模板)
template<class T1 ,class T2>
void operate2(Person<T1,T2> p) {
	cout << "T1的类型为" << typeid(T1).name() << endl;
	cout << "T2的类型为" << typeid(T2).name() << endl;
	p.print();
}
void test2() {
	Person<string, int>p1("cao", 27);
	operate2(p1);
}

//3、整个类模板化
 template<class T>
 void operate3(T p) {
	 cout << typeid(T).name() << endl;
	 p.print();
}
 void test3() {
	 Person<string, int>p1("cao", 27);
	 operate3(p1);
 }


//int main() {
//	// 指定T 为string类型，Y 为 int类型
//	Person<string, int>p1("cao", 27);
//	cout << p1 << endl;
//
//	Police<Person<string, int>> police;
//	police.check();
//
//	test3();
//
//
//	system("pause");
//	return 0;
//}