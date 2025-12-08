#include<stdio.h>
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

void blPrint(int num) {
	std::cout << num << std::endl;
}

class People {
public:
	std::string name;
	int age;

	People() {
		this->name = "";
		this->age = 0;
	}

	People(std::string s,int num):name(s),age(num){}
};

class BlPrint {
public:
	void operator()(const People& p) {
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};

class Transform {
public:
	People operator()( People& p) {
		p.age += 100;
		return p;   
	}
};

void blTest() {
	std::vector<int> vit;
	for (int i = 0; i < 10; i++) {
		vit.push_back(i);
	}
	for_each(vit.begin(), vit.end(), blPrint);

	std::vector<People> vit2;
	vit2.push_back(People("cao", 27));
	vit2.push_back(People("chen", 27));
	vit2.push_back(People("zhao", 40));
	std::for_each(vit2.begin(), vit2.end(), BlPrint());

	std::vector<People> vit3;
	vit3.resize(vit2.size());
	std::transform(vit2.begin(), vit2.end(), vit3.begin(), Transform());
	std::for_each(vit3.begin(), vit3.end(), BlPrint());
}

//int main() {
//	blTest();
//
//	system("pause");
//	return 0;
//}