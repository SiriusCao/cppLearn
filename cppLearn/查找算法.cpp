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

	bool operator==(const People& p) const{
		return this->age == p.age && this->name == p.name;
	}
	bool operator<(const People& p) const {
		if (this->age != p.age) {
			return this->age < p.age;
		}
		return this->name < p.name;
	}
};
class BlPrint {
public:
	void operator()(const People& p) {
		std::cout << "name:" << p.name << ",age:" << p.age << std::endl;
	}
};

class ComparePerson {
public:
	bool operator()(const People& p1, const People& p2)const {
		if (p1.age != p2.age) {
			return p1.age < p2.age;
		}
		return p1.name < p2.name;
	}
};

class PeopleGreat {
public:
	bool operator()(const People& p) {
		return p.age > 40;
	}
};

std::ostream& operator<<(std::ostream& out, People& p) {
	out << "name:" << p.name << ",age:" << p.age ;
	return out;
}

void findTest() {
	std::vector<int> vit;
	vit.push_back(10);
	vit.push_back(20);
	vit.push_back(30);
	std::vector<int>::iterator posi = std::find(vit.begin(), vit.end(), 20);
	std::cout << *posi << std::endl;

	std::vector<People> vp;
	vp.push_back(People("cao", 50));
	vp.push_back(People("chen", 27));
	auto pposi=std::find(vp.begin(), vp.end(), People("zhao", 29));
	if (pposi != vp.end()) {
		std::cout << *pposi << std::endl;
	}
	else {
		std::cout << "Î´ÕÒµ½" << std::endl;
	}

	std::vector<People>::iterator ppposi=std::find_if(vp.begin(), vp.end(), PeopleGreat());
	std::cout << *ppposi << std::endl;

	vp.push_back(People("chen", 90));
	auto xlposi=std::adjacent_find(vp.begin(), vp.end());
	if (xlposi != vp.end()) {
		std::cout << *xlposi << std::endl;
	}
	else {
		std::cout << "Î´ÕÒµ½" << std::endl;
	}

	std::sort(vp.begin(), vp.end(), ComparePerson());
	std::for_each(vp.begin(), vp.end(), BlPrint());

	bool jet=std::binary_search(vp.begin(), vp.end(), People("chen", 90));
	std::cout << jet << std::endl;
	


}

int main() {
	findTest();

	system("pause");
	return 0;
}