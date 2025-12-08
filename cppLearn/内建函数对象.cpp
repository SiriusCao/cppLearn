#include<stdio.h>
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>


using namespace std;

void inTest() {
	negate<int> n;
	cout << n(50) << endl;

	plus<int> p;
	cout << p(10, 20) << endl;

	vector<int> vit;
	vit.push_back(2);
	vit.push_back(6);
	vit.push_back(3);
	vit.push_back(9);
	vit.push_back(5);

	sort(vit.begin(), vit.end(), /*greater<int>()*/less<int>());

	for (auto posi = vit.begin(); posi != vit.end(); posi++) {
		cout << *posi << " ";
	}
	cout << endl;

	vector<int> vit2;
	vit2.resize(vit.size());
	transform(vit.begin(), vit.end(), vit2.begin(),negate<int>());

	for (auto posi = vit2.begin(); posi != vit2.end(); posi++) {
		cout << *posi << " ";
	}
	cout << endl;



}

//int main() {
//	inTest();
//
//	system("pause");
//	return 0;
//}