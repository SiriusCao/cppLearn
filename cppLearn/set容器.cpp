#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>


using namespace std;
class SetCompare {
public:
	bool operator()(int num1, int num2) const{
		return num1 > num2;
	}
};

void printSet(const set<int, SetCompare>& s) {
	for (set<int, SetCompare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void setTest() {
	set<int, SetCompare> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	s1.insert(999);
	printSet(s1);
	/*s1.erase(999);
	printSet(s1);*/
	set<int, SetCompare>::iterator p999=s1.find(999);
	cout << *p999 << endl;
	cout << s1.count(999) << endl;

	pair<set<int, SetCompare>::iterator,bool> jet=s1.insert(888);
	cout << *(jet.first) << endl;
	cout << jet.second << endl;
	pair<set<int, SetCompare>::iterator,bool> jet1=s1.insert(20);
	cout << *(jet1.first) << endl;
	cout << jet1.second << endl;
	printSet(s1);

}

int main() {

	setTest();
	system("pause");
	return 0;
}