#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include <ctime>
#include<functional>
#include<algorithm>
#include <random>
#include <chrono>

class People {
public:
	std::string name;
	int age;

	People() {
		this->name = "";
		this->age = 0;
	}
	People(std::string s, int num) :name(s), age(num) {}

	bool operator==(const People& p)const {
		return this->name == p.name && this->age == p.age;
	}
};

class CTPrint {
public:
	void operator()(const People& p) {
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};

class ReplaceIf {
public:
	bool operator()(const People& p)const {
		return p.age < 40;
	}
};

void copyAndTihuan(){
	std::vector<People> vpe;
	vpe.push_back(People("cao", 27));
	vpe.push_back(People("chen", 28));
	vpe.push_back(People("zhang", 97));
	vpe.push_back(People("li", 44));

	std::vector<People> vpe2;
	vpe2.resize(vpe.size());
	std::copy(vpe.begin(), vpe.end(), vpe2.begin());
	std::for_each(vpe2.begin(), vpe2.end(), CTPrint());

	std::cout << "-----------------" << std::endl;

	std::replace(vpe2.begin(), vpe2.end(), People("li", 44), People("chenxaowei", 18));
	std::for_each(vpe2.begin(), vpe2.end(), CTPrint());

	std::cout << "-----------------" << std::endl;
	std::replace_if(vpe2.begin(), vpe2.end(), ReplaceIf(),People("vvvv",1000));
	std::for_each(vpe2.begin(), vpe2.end(), CTPrint());
	std::cout << "============================" << std::endl;

	std::swap(vpe, vpe2);
	std::for_each(vpe.begin(), vpe.end(), CTPrint());
	std::cout << "-----------------" << std::endl;
	std::for_each(vpe2.begin(), vpe2.end(), CTPrint());


}

int main() {
	copyAndTihuan();
	system("pause");
	return 0;
}