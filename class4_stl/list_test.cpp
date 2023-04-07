#include"head.h"
#include"mylist.hpp"
void test3() {
	frank::list<int> l;
	for (size_t i = 0; i < 5; i++)
	{
		l.push_back(i);
	}
	frank::list<int>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main() {
	test3();
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;

	return 0;
}