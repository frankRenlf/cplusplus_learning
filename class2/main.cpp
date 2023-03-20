#include<iostream>
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
int main() {
	cout << recall(5) << endl;
}