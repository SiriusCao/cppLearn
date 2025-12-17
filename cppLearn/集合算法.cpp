#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <iterator>
#include<functional>

class People {
public:
	std::string name;
	int age;
public:
	People() {
		this->name = "";
		this->age = 0;
	}

	People(std::string s, int num) : name(s),age(num){}


	bool operator<(const People& p) const {
		if (this->age != p.age) {
			return this->age < p.age;
		}
		else {
			return this->name < p.name;
		}
	}

};

class JiheCompare {
public:
	bool operator()(const People& p1, const People& p2)const {
		if (p1.age != p2.age) return p1.age < p2.age;
		return p1.name < p2.name;
		//return p1 < p2;
	}
};

class JihePrint {
public:
	void operator()(const People& p)const {
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};


void JiheTest() {
	std::vector<People> v1;
	v1.push_back(People("cao", 27));
	v1.push_back(People("chen", 18));
	v1.push_back(People("tang", 42));
	v1.push_back(People("li", 2));
	std::sort(v1.begin(), v1.end(),/*JiheCompare()*/std::less<People>());


	std::vector<People> v2;
	v2.push_back(People("2cao", 27));
	v2.push_back(People("2chen", 18));
	v2.push_back(People("2tang", 42));
	v2.push_back(People("2li", 2));
	v2.push_back(People("chen", 18));
	std::sort(v2.begin(), v2.end(),/*JiheCompare()*/std::less<People>());

	//交集
	std::vector<People> v3;
	v3.resize(std::min(v1.size(), v2.size()));
	//用于排序的比较器类型和用于集合操作（如 set_intersection）的比较器类型必须是完全相同的类型
	std::vector<People>::iterator v3end=std::set_intersection(v1.begin(), v1.end(), 
		v2.begin(), v2.end(),
		v3.begin(),
		/*JiheCompare()*/std::less<People>());
	std::for_each(v3.begin(), v3end, JihePrint());

	std::cout << "*--------------------------*" << std::endl;

	//并集
	std::vector<People> v4;
	v4.resize(v1.size() + v2.size());
	std::vector<People>::iterator v4end=std::set_union(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		v4.begin(),
		std::less<People>());
	std::for_each(v4.begin(), v4end, JihePrint());

	std::cout << "*--------------------------*" << std::endl;

	//差集
	std::vector<People> v5;
	v5.resize(std::max(v1.size(), v2.size()));
	std::vector<People>::iterator v5end = std::set_difference(v2.begin(), v2.end(),
		v1.begin(), v1.end(),
		v5.begin(),
		std::less<People>());
	std::for_each(v5.begin(), v5end, JihePrint());
}

//int main() {
//	JiheTest();
//
//	system("pause");
//	return 0;
//}