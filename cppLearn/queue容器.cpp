#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

void qtest01() {
	/*构造函数：
- `queue<T> que;`                                 //queue采用模板类实现，queue对象的默认构造形式
- `queue(const queue &que);`            //拷贝构造函数
赋值操作：
- `queue& operator=(const queue &que);`           //重载等号操作符
数据存取：
- `push(elem);`                             //往队尾添加元素
- `pop();`                                      //从队头移除第一个元素
- `back();`                                    //返回最后一个元素
- `front(); `                                  //返回第一个元素
大小操作：
- `empty();`            //判断堆栈是否为空
- `size(); `              //返回栈的大小*/
	queue<int> qint;
	for (int i = 0; i < 10; i++) {
		qint.push(i);
	}
	cout << qint.front() << " " << qint.back() << endl;
	qint.pop();
	cout << qint.front() << " " << qint.back() << endl;

}

//int main() {
//	qtest01();
//	system("pause");
//	return 0;
//}