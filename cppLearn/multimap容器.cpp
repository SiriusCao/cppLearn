#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

void multimapTest() {
	multimap<int, string> mm;
	mm.insert(make_pair(1, "a"));
	mm.insert(make_pair(2, "b"));
	mm.insert(make_pair(2, "B"));
	mm.insert(make_pair(2, "bB"));
	mm.insert(make_pair(3, "c"));
	
	multimap<int,string>::iterator posi=mm.find(2);
	int count=mm.count(2);
	for (int i = 0; posi != mm.end() /*&& i < count*/; posi++, i++) {
		cout << "key:" << posi->first << ",value:" << posi->second << endl;
	}
}

int main() {
	multimapTest();
	system("pause");
	return 0;
}