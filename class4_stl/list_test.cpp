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
void print_list(const frank::list<T>& lt) {
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
	frank::list<int> lt2 = lt;
	auto it = lt.begin();
	while (it != lt.end()) {
		if (*it % 2 == 0) {
			it = lt.erase(it);
		}
		else {
			++it;
		}
	}

	print_list(lt2);
	print_list(lt);
	frank::list<int> lt3 = lt2;
	print_list(lt3);

}
void test9() {
	frank::list<int> lt;
	for (size_t i = 0; i < 5; i++)
	{
		lt.push_back(i);
	}
	const frank::list<int> lt2 = lt;
	lt.rbegin();
	frank::list<int>::const_riterator it = lt2.rbegin();
	while (it != lt2.rend()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main() {
	test9();
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;

	return 0;
}