#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>


using namespace std;

class People {
public:
	string name;
	int age;
	int height;
public:
	People(string name, int age, int height) :name(name), age(age), height(height) {}


};

bool personCompare(const People& p1, const People& p2) {
	if (p1.age == p2.age) {
		return p1.height > p2.height;
	}
	else
	{
		return p1.age < p2.age;
	}
}
void printList(const list<int> lint) {
	for (list<int>::const_iterator pint = lint.begin(); pint != lint.end(); pint++) {
		cout << *pint<<" ";
	}
	cout << endl;
}

bool myCompare(int num1, int num2) {
	return num1 > num2;
}

ostream& operator<<(ostream& out, const People& p) {
	out << "name:" << p.name << ",age:" << p.age << ",height:" << p.height;
	return out;
}

void ltest01() {
	list<int> lint;
	for (int i = 0; i < 10; i++)
	{
		lint.push_back(i);
	}
	printList(lint);

	list<int> lint2;
	for (int i = 10; i >0; i--)
	{
		lint2.push_back(i);
	}
	printList(lint2);

	lint.swap(lint2);
	printList(lint);
	printList(lint2);

	vector<int> vint;
	for (int i = 0; i < 50; i++)
	{
		vint.push_back(i);
	}
	vector<int>::iterator vit = vint.begin();
	vit += 6;
	cout << "********" << *vit << endl;

	vit--;
	cout <<"********" << *vit << endl;
	lint.assign(vint.begin(), vint.end());
	printList(lint);

	lint.pop_back();
	lint.pop_front();
	printList(lint);

	list<int>::iterator i = lint.begin();
	i++;
	lint.insert(i, 500);
	printList(lint);
	lint.push_front(500);
	lint.push_back(500);
	printList(lint);

	lint.remove(500);
	printList(lint);

	list<int>::iterator it = lint.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
	it++;
	it++;
	it--;
	cout << *it << endl;

	lint.reverse();
	printList(lint);
	lint.sort();
	printList(lint);

	lint.sort(myCompare);
	printList(lint);


	list<People> lp;
	lp.push_back(People("cao", 27, 175));
	lp.push_back(People("chen", 27, 166));
	lp.push_back(People("zhao", 70, 160));
	lp.push_back(People("zzz", 50, 120));

	for (list<People>::iterator pit=lp.begin(); pit!=lp.end(); pit++)
	{
		cout << *pit << endl;
	}

	lp.sort(personCompare);
	for (list<People>::iterator pit = lp.begin(); pit != lp.end(); pit++)
	{
		cout << *pit << endl;
	}





}

int main() {

	ltest01();

	system("pause");
	return 0;
}