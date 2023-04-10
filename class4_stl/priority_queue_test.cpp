#include"mypriority_queue.hpp"
struct lessStr {
	bool operator()(const string& s1, const string& s2) {
		return s1 < s2;
	}
};
struct greatorStr {
	bool operator()(const string& s1, const string& s2) {
		return s1 > s2;
	}
};
void test6() {
	frank::less<int> lessComp;
	frank::priority_queue<int, std::vector<int>, frank::less<int>> pq;
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
void test7() {
	frank::less<string> lessComp;
	frank::priority_queue<string, std::vector<string>, greatorStr> pq;
	pq.push("345");
	pq.push("1234");
	pq.push("567");
	for (size_t i = 0; i < 3; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	vector<string> v = { "345","1231","567" };
	sort(v.begin(), v.end(), lessStr());
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void test8() {
	vector<string> v = { "345","1231","567" };

	frank::priority_queue<string, std::vector<string>, greater<string>> pq(v.begin()+1, v.end());
	int sz = pq.size();
	for (size_t i = 0; i < sz; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//int main() {
//	test8();
//	return 0;
//}