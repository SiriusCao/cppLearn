#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>



int lambdaTest() {
	//直接调用 Lambda
	auto lam = []() {
		std::cout << "hello" << std::endl;
		};
	lam();
	lam();

	//带参数的 Lambda，返回类型可省略，复杂场景需显式指定
	auto add = [](int a,int b)/*->int(可选)*/ {
		return a + b;
		};
	auto compare = [](int a, int b) {
		return a > b ? a : b;
		};
	std::cout << add(1, 2) << std::endl;
	std::cout << compare(1, 2) << std::endl;

	//访问外部局部变量
	int sum1 = 10, sum2 = 20;
	auto add1 = [sum1, sum2]() {
		std::cout << sum1 + sum2 << std::endl;
		};
	add1();

	auto add2 = [&sum1, &sum2]() {
		sum1 = 100;
		sum2 = 200;
		};
	add2();
	std::cout << sum1 << "," << sum2 << std::endl;

	//用 Lambda 排序以及用 Lambda 遍历
	std::vector<int> v = { 8,4,2,3,96,75,82 };
	std::sort(v.begin(), v.end(), [](int num1, int num2) {
		return num1 < num2;
		});
	std::for_each(v.begin(), v.end(), [](int num) {
		std::cout << num << " ";
		});

	return 0;
}