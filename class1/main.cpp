#include<iostream>

#include"head.h"

using namespace std;
namespace R {
	int rand = 10;
	int a = 1;
}
int test1(int a = 3) {
	return a * a;
}
int test1(int a, int b) {
	return a * a;
}
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
using R::a;
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << a << endl;
//	return 0;
//}
int main()
{
	int a;
	char b;
	cin >> a >> b;
	cout << a << b << endl;
	return 0;
}