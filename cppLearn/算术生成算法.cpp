#include<vector>
#include<set>
#include <ctime>
#include<functional>
#include<algorithm>
#include <string>
#include<stdio.h>
#include<iostream>
#include<numeric>
class People {
public:
	std::string name;
	int age;

	People() {
		this->name = "";
		this->age = 0;
	}
	People(std::string s, int num) :name(s), age(num) {}

	int operator+(const People& p)const {
		return this->age + p.age;
	}
};

int operator+(int num, const People& p) {
	return p.age + num;
}

class SSPrint {
public:
	void operator()(const People& p)const {
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};

void SStest() {
	std::vector<People> vpe;
	vpe.push_back(People("cao", 27));
	vpe.push_back(People("chen", 28));
	vpe.push_back(People("zhang", 97));
	vpe.push_back(People("li", 44));
	//int a = vpe[0] + vpe[1];
	int sum = std::accumulate(vpe.begin(), vpe.end(), 0);
	std::cout << sum << std::endl;

	std::vector<People>::iterator vpe_begin = vpe.begin();
	std::vector<People>::iterator vpe_end = vpe.end();
	vpe_begin++;
	vpe_end--;
	std::fill(vpe_begin, vpe_end, People("fffff", 6666));
	std::for_each(vpe.begin(), vpe.end(), SSPrint());

}

int main() {
	SStest();

	system("pause");
	return 0;
}