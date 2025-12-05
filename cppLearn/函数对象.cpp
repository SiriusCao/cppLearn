#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


using namespace std;

class GraterFive {
public:
	bool operator()(int num) {
		return num > 5;
	}
};

class VecCompare {
public:
	bool operator()(int num1, int num2){
		return num1 > num2;
	}
};

void func() {
	vector<int> vit;
	vit.push_back(2);
	vit.push_back(6);
	vit.push_back(3);
	vit.push_back(9);
	vit.push_back(5);
	vector<int>::iterator posi = find_if(vit.begin(), vit.end(), GraterFive());
	if (posi == vit.end()) {
		cout << "no exit" << endl;
	}
	else {
		cout << *posi << endl;
		posi++;
		cout << *posi << endl;//只是指向第一个符合条件的元素
	}

	for (vector<int>::iterator posi = vit.begin(); posi != vit.end(); posi++) {
		cout << *posi << " ";
	}
	cout << endl;
	sort(vit.begin(),vit.end(),VecCompare());
	for (vector<int>::iterator posi = vit.begin(); posi != vit.end(); posi++) {
		cout << *posi << " ";
	}
	cout << endl;

	list<int> lit;
	lit.push_back(2);
	lit.push_back(6);
	lit.push_back(3);
	lit.push_back(9);
	lit.push_back(5);
	lit.sort(VecCompare());
	for (list<int>::iterator posi = lit.begin(); posi != lit.end(); posi++) {
		cout << *posi << " ";
	}
	cout << endl;


}

//int main() {
//	func();
//
//	system("pause");
//	return 0;
//}