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
void test5() {
	vector<string> v{ "10","6","9","3","+"
		,"-11","*","/","*","17","+","5","+" };
	Solution s;
	cout << s.evalRPN(v);
}
int main() {
	test5();
	return 0;
}