#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

void printDeque(const deque<int>& dint) {
	for (deque<int>::const_iterator dit = dint.begin(); dit != dint.end(); dit++) {
		cout << *dit<<" ";
	}
	cout << endl;
}
void dtest01() {
	/** `deque<T>` deqT;                      //默认构造形式
* `deque(beg, end);`                  //构造函数将[beg, end)区间中的元素拷贝给本身。
* `deque(n, elem);`                    //构造函数将n个elem拷贝给本身。
* `deque(const deque &deq);`   //拷贝构造函数*/
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(10, 100);
	printDeque(d3);

	deque<int> d4(d3);
	printDeque(d4);

	/** deque& operator=(const deque &deq); `         //重载等号操作符
* `assign(beg, end);`                                           //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`                                             //将n个elem拷贝赋值给本身*/
	d4 = d2;
	printDeque(d4);

	d3.assign(d1.begin(), d1.end());
	printDeque(d3);
	/** `deque.empty();`                       //判断容器是否为空
* `deque.size();`                         //返回容器中元素的个
* `deque.resize(num);`                //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
  ​			                             //如果容器变短，则末尾超出容器长度的元素被删除。
* `deque.resize(num, elem);`     //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
  ​                                                     //如果容器变短，则末尾超出容器长度的元素被删除。*/
	cout << d4.size() << endl;
	d4.resize(3);
	printDeque(d4);
	/*两端插入操作：
- `push_back(elem);`          //在容器尾部添加一个数据
- `push_front(elem);`        //在容器头部插入一个数据
- `pop_back();`                   //删除容器最后一个数据
- `pop_front();`                 //删除容器第一个数据*/
	d4.push_back(500);
	d4.push_front(500);
	printDeque(d4);

/*指定位置操作：
* `insert(pos,elem);`         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。
* `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。
* `clear();`                           //清空容器的所有数据
* `erase(beg,end);`             //删除[beg,end)区间的数据，返回下一个数据的位置。
* `erase(pos);`                    //删除pos位置的数据，返回下一个数据的位置。*/
	d4.insert(d4.begin()+1,10, 999);
	printDeque(d4);
	/*- `at(int idx); `     //返回索引idx所指的数据
- `operator[]; `      //返回索引idx所指的数据
- `front(); `            //返回容器中第一个数据元素
- `back();`              //返回容器中最后一个数据元素*/
	d4[0] = 888;
	printDeque(d4);

	//`sort(iterator beg, iterator end)`  //对beg和end区间内元素进行排序
	sort(d4.begin(), d4.end());
	printDeque(d4);
}

int main() {
	dtest01();
	system("pause");
	return 0;
}