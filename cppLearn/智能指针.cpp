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

/*std::unique_ptr（独占所有权）
独占所有权：同一时间只能有一个unique_ptr指向对象
不可复制，只能移动（move）
离开作用域时自动释放内存*/
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

	//管理数组对象
	std::unique_ptr<int[]> arrptr = std::make_unique<int[]>(3);
	arrptr[0] = 111;
	arrptr[1] = 222;
	arrptr[2] = 333;
	std::cout << arrptr[0] << std::endl;

	std::unique_ptr<std::vector<int>> vecptr = std::make_unique<std::vector<int>>();
	vecptr->push_back(10);
	(*vecptr).push_back(20);
	std::cout << vecptr->at(0) << std::endl;
	std::cout << (*vecptr)[1] << std::endl;
}

/****************************************************/

//自定义删除器
class Deleter {
public:
	void operator()(PeoplePtr* p)const {
		if (p != nullptr) {
			std::cout << p->name << "删除器执行" << std::endl;
			delete p;
		}
	}
};
//通过lambda表达式自定义删除器
auto deleter = [](PeoplePtr* p) {
	if (p != nullptr) {
		std::cout <<p->name<< "删除器执行" << std::endl;
		delete p;
	}
	};
void deleter_test() {
	std::unique_ptr<PeoplePtr, Deleter> up(new PeoplePtr("cao"),Deleter());
	std::unique_ptr<PeoplePtr, decltype(deleter)> up1(new PeoplePtr("chen"), deleter);
}

/****************************************************/
/*std::shared_ptr（共享所有权）
共享所有权：多个shared_ptr可以指向同一对象
引用计数：跟踪有多少个shared_ptr指向对象
计数为0时自动释放内存*/
void share_ptr_test() {
	// 创建方式1：make_shared
	std::shared_ptr<PeoplePtr> sp1 = std::make_shared<PeoplePtr>("cao");
	// 创建方式2：构造函数
	std::shared_ptr<PeoplePtr> sp2(new PeoplePtr("chen"));

	// 共享所有权(可以复制)
	std::shared_ptr<PeoplePtr> sp3 = sp1;
	std::shared_ptr<PeoplePtr> sp4 = sp1;

	//引用计数：跟踪有多少个shared_ptr指向对象
	std::cout << "sp1指向的的对象有" << sp1.use_count() << "个shared_ptr指向对象" << std::endl;
	std::cout << "sp2指向的的对象有" << sp2.use_count() << "个shared_ptr指向对象" << std::endl;
	std::cout << "sp3指向的的对象有" << sp3.use_count() << "个shared_ptr指向对象" << std::endl;

	// 交换
	sp1.swap(sp2);
	sp1->print();
	sp2->print();
	sp3->print();

	// 重置指针
	sp1.reset();//释放当前对象，如果引用计数为0则删除
	sp2.reset(new PeoplePtr("tang"));
	sp2->print();

	//调用删除器
	std::shared_ptr<PeoplePtr> sp5(new PeoplePtr("xxxxx"), Deleter());

	std::cout << "结束" << std::endl;
}

/****************************************************/

//循环引用问题
class BadNode {
public:
	std::shared_ptr<BadNode> next;
	std::string str;

	BadNode(const char* s) {
		this->str = s;
	}
	~BadNode() {
		std::cout << this->str << "已经被销毁" << std::endl;
	}
};

void badNode_test() {
	std::shared_ptr<BadNode> node1 = std::make_shared<BadNode>("node1");
	std::shared_ptr<BadNode> node2 = std::make_shared<BadNode>("node2");


	node1->next = node2;
	node2->next = node1; // 循环引用！
	// 离开作用域时，引用计数不会变为0，内存泄漏
}

class GoodNode {
public:
	std::shared_ptr<GoodNode> next;
	std::weak_ptr<GoodNode> prev;// 使用weak_ptr打破循环
	std::string str;

	GoodNode(const char* s) {
		this->str = s;
	}
	~GoodNode() {
		std::cout << this->str << "已经被销毁" << std::endl;
	}
};
void goodNode_test() {
	std::shared_ptr<GoodNode> node1 = std::make_shared<GoodNode>("node1");
	std::shared_ptr<GoodNode> node2 = std::make_shared<GoodNode>("node2");

	node1->next = node2;
	node2->prev = node1;
}

/****************************************************/

/*std::weak_ptr（弱引用）
不增加引用计数：不会阻止对象被销毁
解决循环引用问题
必须转换为shared_ptr才能访问对象*/
void weak_ptr_test() {
	std::shared_ptr<PeoplePtr> sp = std::make_shared<PeoplePtr>("cao");
	std::weak_ptr<PeoplePtr> wp = sp;

	std::cout << "sp指向的的对象有" << sp.use_count() << "个智能指针指向对象" << std::endl;
	std::cout << "wp指向的的对象有" << wp.use_count() << "个智能指针指向对象" << std::endl;

	//wp->print();报错，必须转换为shared_ptr才能访问对象
	std::shared_ptr<PeoplePtr> transfer_sp=wp.lock();
	transfer_sp->print();

	std::cout << "sp指向的的对象有" << sp.use_count() << "个智能指针指向对象" << std::endl;
	std::cout << "wp指向的的对象有" << wp.use_count() << "个智能指针指向对象" << std::endl;

	sp.reset();
	transfer_sp.reset();
	if (wp.expired()) {
		std::cout << "被销毁" << std::endl;
	}
	
	
}

int main() {
	weak_ptr_test();
	return 0;
}