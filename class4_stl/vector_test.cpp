#include"head.h"
#include"myvector.hpp"

template<class T>
void print_vector(frank::vector<T>& v) {
	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test2() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.insert(v.begin(), i);
	}

	print_vector(v);

	frank::vector<int> v2(10, 5);
	print_vector(v2);

	v = v2;
	print_vector(v);
}
int main() {
	test2();
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}