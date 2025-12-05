#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

class MapCompare {
public:
	bool operator()(const int& num1, const int& num2) const {
		return num1 > num2;
	}
};

void printSet(const map<int, string,MapCompare>& m) {
	for (map<int, string, MapCompare>::const_iterator posi = m.begin(); posi != m.end(); posi++) {
		cout << "key=" << posi->first << ",value=" << posi->second << endl;
	}
}


void mapTest() {
	map<int, string,MapCompare> m;
	m.insert(make_pair(1, "a"));
	m.insert(make_pair(2, "b"));
	m.insert(pair<int, string>(3, "c"));
	m.insert(make_pair(99, "abc"));
	m.insert(map<int, string>::value_type(4, "d"));
	m[5] = "e";

	printSet(m);

}

//int main() {
//	mapTest();
//	system("pause");
//	return 0;
//}