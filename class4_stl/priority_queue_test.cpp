#include"mypriority_queue.hpp"

void test6() {
	frank::less<int> lessComp;
	frank::priority_queue<int, std::vector<int>, frank::greator<int>> pq;
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