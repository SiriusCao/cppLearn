#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
private:
	int m_capacity;
	int m_size;
	T* pAddress;

public:
	//构造函数
	MyArray(int capacity){
		//初始化T类型数组，数组首指针指向pAddress
		this->pAddress = new T[capacity];
		this->m_capacity = capacity;
		this->m_size = 0;
	}

	//拷贝构造
	MyArray(const MyArray<T>& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//析构函数
	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
	}

	//=运算符重载
	MyArray& operator=(const MyArray<T>& arr) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//[]运算符重载
	T& operator[](int num) {
		if (num >= this->m_capacity) {
			cout << "数组越界" << endl;
			return this->pAddress[this->m_size];
		}
		return this->pAddress[num];
	}

	//尾插法
	void push(const T& val) {
		if (this->m_capacity == this->m_size) {
			cout << "数组已满" << endl;
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	//尾删法
	void pop() {
		if (this->m_size <= 0) {
			cout << "数组已空" << endl;
		}
		this->m_size--;
	}

	//获取数组容量
	int getCapacity() {
		return this->m_capacity;
	}

	//获取数组大小
	int getSize() {
		return this->m_size;
	}
};

template<class T>
ostream& operator<<(ostream& out, MyArray<T>& arr) {
	for (int i = 0; i < arr.getSize(); i++)
	{
		out << arr[i] << ",";
	}
	return out;
}
