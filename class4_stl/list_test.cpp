#include"head.h"
#include"mylist.hpp"

int main() {
	//test2();
	frank::list<int> l;
	for (size_t i = 0; i < 5; i++)
	{
		l.push_back(i);
	}
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;

	return 0;
}