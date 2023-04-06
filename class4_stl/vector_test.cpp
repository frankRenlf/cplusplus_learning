#include"head.h"
#include"myvector.hpp"


void test2() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.insert(v.begin(), i);
	}

	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	frank::vector<int> v2(v.begin(), v.end()-5);
	cout << (v2.end() - v2.begin()) << endl;
	for (frank::vector<int>::iterator i = v2.begin(); i < v2.end(); i++)
	{
		cout << *i << " ";
	}
}
int main() {
	test2();
	cout << endl;
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}