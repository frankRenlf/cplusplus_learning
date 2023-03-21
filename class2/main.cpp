#include<iostream>

#include"head.h"

using namespace std;
class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	~A() { --_scount; }
	static int GetACount() { return _scount; }
private:
	static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}
int recall(int n) {
	if (n < 1) {
		return 0;
	}
	return n += recall(n - 1);
}
//int main() {
//	cout << recall(5) << endl;
//	test1();
//}
int& Add(int a, int b)
{
	static int c = a + b;
	return c;
}
int Add2(int a, int b)
{
	int x = a + b;
	return x;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	int x = Add2(1, 2);
	cout << "Add(1, 2) is :" << ret << endl;
	cout << "Add(1, 2) is :" << x << endl;
	return 0;
}
//int main() {
//	const int a = 10;
//	const int& b = a;
//	int c = 20;
//	const int& d = c;
//
//}