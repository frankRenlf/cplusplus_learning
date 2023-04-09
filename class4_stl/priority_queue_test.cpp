#include"mypriority_queue.hpp"

void test6() {
	frank::less<int> lessComp;
	cout << lessComp(1, 2) << endl;
	frank::greator<int> greatorComp;
	cout << greatorComp(1, 2) << endl;
	frank::priority_queue<int> pq;
	for (size_t i = 0; i < 10; i++)
	{
		pq.push(i);
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main() {
	test6();
	return 0;
}