#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

void test01() {
	//string构造函数：
	//string();           				//创建一个空的字符串 例如: string str;
	//string(const char* s); 	        //使用字符串s初始化
	//string(const string& str);     //使用一个string对象初始化另一个string对象
	//string(int n, char c);            //使用n个字符c初始化
	string s1;
	s1 = "abcdefg";
	cout << s1 << endl;

	const char str[] = "aaaa";
	string s2(str);
	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 'c');
	cout << s4 << endl;
}

void test02() {
	/*string赋值的函数原型：
	string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
	string& operator=(const string &s);//把字符串s赋给当前的字符串
	string& operator=(char c); //字符赋值给当前的字符串*/
	string s1 = "abceffg";
	cout << s1 << endl;
	char str[] = "aaaaa";
	string s2;
	s2 = s1;
	cout << s2 << endl;
	string s3;
	s3 = str;
	cout << s3 << endl;
	char c = 'c';
	string s4;
	s4 = c;
	cout << s4 << endl;
	/*string& assign(const char* s);  //把字符串s赋给当前的字符串
	string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
	string& assign(const string &s); //把字符串s赋给当前字符串
	string& assign(int n, char c); //用n个字符c赋给当前字符串*/
	char strr[] = "poiuy";
	string ss1;
	ss1.assign(strr);
	cout << ss1 << endl;
	string ss2;
	ss2.assign(strr, 2);
	cout << ss2 << endl;
	string ss3;
	ss3.assign(ss2);
	cout << ss3 << endl;
	string ss4;
	ss4.assign(10, 'b');
	cout << ss4 << endl;
}

void test03() {
	/*string& operator+=(const char* str);`                   //重载+=操作符
	string& operator+=(const char c);`                         //重载+=操作符
	string& operator+=(const string& str);`                //重载+=操作符*/
	string sss1 = "pqrstuvw";
	char strrr[] = "aaa";
	sss1 += strrr;
	cout << sss1 << endl;
	sss1 += 'c';
	cout << sss1 << endl;
	sss1 += "bbbb";
	cout << sss1 << endl;
	/*string& append(const char* s); `                               //把字符串s连接到当前字符串结尾
	string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
	string& append(const string &s);`                           //同operator+=(const string& str)
	string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾*/
	sss1.append(strrr);
	cout << sss1 << endl;
	sss1.append(strrr, 1);
	cout << sss1 << endl;
	sss1.append("qqq");
	cout << sss1 << endl;
	sss1.append("abcdefg", 0, 3);
	cout << sss1 << endl;
}
void test04() {
	/*int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
	int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
	int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
	int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
	int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
	int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
	int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
	int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
	string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
	string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串*/
	string ssss4 = "abcdefghijkl";
	cout << ssss4.find("b") << endl;
	cout << ssss4.find('c') << endl;
	cout << ssss4.rfind("k") << endl;
	ssss4.replace(2, 1, "99");
	cout << ssss4 << endl;
	/*int compare(const string &s) const; `  //与字符串s比较
	int compare(const char *s) const;`      //与字符串s比较*/
	string h = "hello";
	char hh[] = "hello";
	cout << h.compare(hh) << endl;
	/*char& operator[](int n); `     //通过[]方式取字符
	char& at(int n);   `                    //通过at方法获取字符*/
	string cc = "abcdefg";
	cout << cc[2] << endl;
	cout << cc.at(3) << endl;
	/*string& insert(int pos, const char* s);  `                //插入字符串
	string& insert(int pos, const string& str); `        //插入字符串
	string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
	string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符 */
	cc.erase(5, 2);
	cc.insert(2, "99");
	cout << cc << endl;
	//`string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串
	string email = "12344@123.com";
	int pos = email.find('@');
	string username=email.substr(0,pos);
	cout << username << endl;
}
//int main() {
//	test04();
//
//	system("pause");
//	return 0;
//}