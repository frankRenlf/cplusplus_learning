#include"head.h"

int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	vector<string> v;
	string s("123");
	v.push_back(s);
	cout << (v[0] == s) << endl;

	s[1] = '5';
	cout << (v[0] == s) << endl;

	return 0;
}