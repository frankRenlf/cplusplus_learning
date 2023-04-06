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
}
int main() {
	test2();
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}