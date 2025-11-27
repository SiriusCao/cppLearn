#include<iostream>
#include"MyArray.hpp"
using namespace std;

class Person {
	friend ostream& operator<< (ostream& out, Person& p);

private:
	int age;
	int id;
public:
	Person(){}
	Person(int a,int b):age(a),id(b){}
	Person& operator=(const Person& p) {
		this->age = p.age;
		this->id = p.id;
		return *this;
}
};

ostream& operator<< (ostream & out, Person& p) {
	out << "age=" << p.age << ",id=" << p.id << endl;
	return out;
}



int main() {
	Person p1(27, 1998);
	Person p2(28, 1997);
	Person p3(29, 1996);

	MyArray<Person> arr(5);
	arr.push(p1);
	arr.push(p2);
	arr.push(p3);
	cout << arr << endl;




}