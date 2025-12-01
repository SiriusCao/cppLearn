#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> vit) {
	for (vector<int>::iterator it = vit.begin(); it != vit.end(); it++) {
		cout << *it;
	}
	cout << endl;
}

int main() {
	//容器：vector

	//算法：for_each

	//迭代器：vector<int > ::iterator
	vector<vector<int>> A;//模板参数指定容器中存放的数据的类型
	vector<int> a1;//模板参数指定容器中存放的数据的类型
	vector<int> a2;
	vector<int> a3;
	vector<int> a4;

	for (int i = 1; i <= 4; i++)
	{
		a1.push_back(i);
		a2.push_back(i + 1);
		a3.push_back(i + 2);
		a4.push_back(i + 3);
	}

	A.push_back(a1);
	A.push_back(a2);
	A.push_back(a3);
	A.push_back(a4);

	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

	//第一种遍历方式：
	//for (vector<vector<int>>::iterator vit = A.begin(); vit != A.end(); vit++) {
	//	for (vector<int>::iterator it = (*vit).begin(); it != (*vit).end(); it++) {
	//		cout << *it;
	//	}
	//	cout << endl;
	//}

	//第二种遍历方式，通过print()函数进行
	for_each(A.begin(),A.end(),print);



	system("pause");
	return 0;
}