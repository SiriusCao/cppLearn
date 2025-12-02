#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

void vprint(vector<int> vit) {
	for (vector<int>::iterator it = vit.begin(); it != vit.end(); it++) {
		cout << *it;
	}
	cout << endl;
}
void vtest01() {
	/** `vector<T> v; `               		     //采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());   `       //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(n, elem);`                            //构造函数将n个elem拷贝给本身。
* `vector(const vector &vec);`         //拷贝构造函数。*/
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vprint(v);
	vector<int>::iterator vit = v.begin();
	vit++;
	vector<int> v2(vit, v.end());
	vprint(v2);
	vector<int> v3(10, 9);
	vector<int> v4(v3);
	vprint(v3);
	vprint(v4);
	/** `vector& operator=(const vector &vec);`//重载等号操作符
* `assign(beg, end);`       //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`        //将n个elem拷贝赋值给本身。*/
	vector<int> v5;
	v5 = v4;
	vprint(v5);
	v5.assign(vit, v.end());
	vprint(v5);
	
	v4.resize(3);
	vprint(v4);
	v4.resize(20);
	vprint(v4);
	/** `push_back(ele);`                                         //尾部插入元素ele
* `pop_back();`                                                //删除最后一个元素
* `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`                     //删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
* `clear();`                                                        //删除容器中所有元素*/
	v4.insert(v4.begin(), 7);
	vprint(v4);
	v4.erase(v4.begin());
	vprint(v4);
	/*v4.clear();
	vprint(v4);*/

	/** `at(int idx); `     //返回索引idx所指的数据
* `operator[]; `       //返回索引idx所指的数据
* `front(); `            //返回容器中第一个数据元素
* `back();`              //返回容器中最后一个数据元素*/
	cout << v4.at(1) << endl;
	cout << v4[1] << endl;
	cout << v4.front() << endl;
	cout << v4.back() << endl;

	vector<int> sw;
	for (int i = 0; i < 100000; i++) {
		sw.push_back(i);
	}
	cout << sw.capacity() << endl;
	cout << sw.size() << endl;

	sw.resize(3);
	cout << sw.capacity() << endl;
	cout << sw.size() << endl;

	vector<int>(sw).swap(sw);
	cout << sw.capacity() << endl;
	cout << sw.size() << endl;

	/*int i=vector<int>(sw).capacity();
	cout <<"p:" << i << endl;*/


}

void vtest02() {
	vector<int> v;
	v.reserve(100000);
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
			cout <<"v的容量为：" << v.capacity() << endl;
		}
	}
	cout << num << endl;
}

//int main() {
//	vtest02();
//
//	system("pause");
//	return 0;
//}