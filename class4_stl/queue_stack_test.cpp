#include"head.h"

void test4() {
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(5);
	q.push(10);
	q.push(12);
	q.push(1);
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
}
int main() {
	test4();
	return 0;
}