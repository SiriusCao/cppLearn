#include<iostream>
using namespace std;

template<typename T>
void myswap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

template<typename T>
void sort(T arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		int max = i;
		for (int j = i+1; j < length; j++)
		{
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		if (max != i) {
			//1、自动类型推导
			myswap(arr[max], arr[i]);
			////2、显示指定类型
			//myswap<T>(arr[max], arr[i]);
		}
	}
}

template<typename T>
void printArr(T arr[], int length) {
	for (int i = 0; i < length-1; i++)
	{
		cout << arr[i]<<",";
	}
	cout << arr[length - 1];
	cout << endl;
}

//int main() {
//	int arr[10] = { 8,0,2,3,4,6,7,1,5,9 };
//	sort(arr, sizeof(arr)/sizeof(int));
//	printArr(arr, sizeof(arr) / sizeof(int));
//	system("pause");
//	return 0;
//}