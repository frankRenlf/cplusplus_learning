#include"head.h"
#include"mylist.hpp"
class AA {
public:
	AA(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{}
	int _a1;
	int _a2;
};
template<class T>
void print_list(frank::list<T> lt) {
	frank::list<AA>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << it->_a1 * it->_a2 << " ";
		++it;
	}
	cout << endl;
}
void test3() {
	frank::list<AA> l;
	for (size_t i = 0; i < 5; i++)
	{
		l.push_back(AA(i, i));
	}
	print_list(l);
}

int main() {
	test3();
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;

	return 0;
}