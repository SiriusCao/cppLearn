#include<stdio.h>
#include<iostream>
#include<vector>
#include <string> 
#include<memory>

class PeoplePtr {
public:
	std::string name;

	PeoplePtr(std::string  name) {
		this->name = name;
		std::cout << this->name << "构造函数" << std::endl;
	}
	~PeoplePtr() {
		std::cout<<this->name<< "析构函数" << std::endl;
	}
	void print() {
		std::cout <<this->name<< "00000" << std::endl;
	}
};

void unique_ptr_test() {
	//方法1，采用make_unique（推荐）
	std::unique_ptr<PeoplePtr> up1 = std::make_unique<PeoplePtr>("cao");
	//方法2，直接构造
	std::unique_ptr<PeoplePtr> up2(new PeoplePtr("chen"));
	//访问对象
	up1->print();
	(*up2).print();

	// 转移所有权
	//转移后，up3 会接管原来 up1 指向的 PeoplePtr 对象（地址不变）；
	//up1 会被置为 空指针（nullptr）（unique_ptr 的设计原则：同一时间只有一个智能指针拥有对象）
	std::unique_ptr<PeoplePtr> up3 = std::move(up1);
	//只能移动，不能复制,std::unique_ptr<PeoplePtr> up3 = up1;会报错

	//释放所有权（返回原始指针，智能指针不再管理）
	PeoplePtr* posi = up3.release();
	posi->print();
	delete posi;
	posi = nullptr;

	// 重置指针
	up2.reset(new PeoplePtr("tang"));
	up2->print();

	// 获取原始指针（不释放所有权）
	PeoplePtr* p2 = up2.get();
	p2->print();
	std::cout << "结束...." << std::endl;
}

//int main() {
//	unique_ptr_test();
//	return 0;
//}