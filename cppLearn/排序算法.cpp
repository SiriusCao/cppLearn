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

	/*bool operator==(const People& p) {
		return this->age == p.age;
	}*/

	//bool operator<(const People& p) {
	//	return this->age < p.age;
	//}
};

bool operator<(const People& p1, const People& p2) {
	return p1.age < p2.age;
}

class SortCompare {
public:
	bool operator()(const People& p1, const People& p2) const{
		return p1.age < p2.age;
	}
};

class SortPrint {
public:
	void operator()(const People& p) const{
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};


void sortTest() {
	std::vector<People> vpe;
	vpe.push_back(People("cao", 27));
	vpe.push_back(People("chen", 28));
	vpe.push_back(People("zhang", 97));
	vpe.push_back(People("li", 44));

	std::sort(vpe.begin(), vpe.end(), SortCompare());
	std::for_each(vpe.begin(), vpe.end(), SortPrint());

	std::cout << "------------------" << std::endl;

	//Ëæ»ú´òÂÒ
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vpe.begin(), vpe.end(), g);
	std::for_each(vpe.begin(), vpe.end(), SortPrint());

	std::cout << "------------------" << std::endl;
	std::sort(vpe.begin(), vpe.end(), SortCompare());
	std::vector<People> vpe2;
	vpe2.push_back(People("22cao", 227));
	vpe2.push_back(People("22chen", 228));
	vpe2.push_back(People("222zhang", 297));
	vpe2.push_back(People("2li", 244));
	std::sort(vpe2.begin(), vpe2.end(), SortCompare());

	std::vector<People> vpe3;
	vpe3.resize(vpe.size() + vpe2.size());
	std::merge(vpe.begin(), vpe.end(), vpe2.begin(), vpe2.end(), vpe3.begin());
	std::for_each(vpe3.begin(), vpe3.end(), SortPrint());


	//std::cout << "--------------" << std::endl;

	//std::reverse(vpe3.begin(), vpe3.end());
	//std::for_each(vpe3.begin(), vpe3.end(), SortPrint());
}

//int main() {
//	sortTest();
//
//	system("pause");
//	return 0;
//}