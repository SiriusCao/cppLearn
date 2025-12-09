#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<functional>
#include<algorithm>

class People {
public:
	std::string name;
	int age;

	People() {
		this->name = "";
		this->age = 0;
	}
	People(std::string s, int num) :name(s), age(num) {}

	bool operator==(const People& p) {
		return this->age == p.age;
	}
};

class PanDuan {
public:
	bool operator()(const People& p) {
		return p.age < 40;
	}
};

void countTest() {
	std::vector<People> vpe;
	vpe.push_back(People("cao", 27));
	vpe.push_back(People("chen", 26));
	vpe.push_back(People("zhang", 27));
	vpe.push_back(People("li", 44));

	int num=std::count(vpe.begin(), vpe.end(), People("wang", 4));

	std::cout << num << std::endl;

	int num1 = std::count_if(vpe.begin(), vpe.end(), PanDuan());
	std::cout << num1 << std::endl;

}

//int main() {
//	countTest();
//
//	system("pause");
//	return 0;
//}