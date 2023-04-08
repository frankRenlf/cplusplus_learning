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
	auto it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test3() {
	frank::list<int> lt;
	for (size_t i = 0; i < 5; i++)
	{
		lt.push_back(i);
	}
	auto it = lt.begin();
	while (it != lt.end()) {
		if (*it % 2 == 0) {
			it=lt.erase(it);
		}
		else {
			++it;
		}
	}
	print_list(lt);
	lt.clear();
}

int main() {
	test3();
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;

	return 0;
}