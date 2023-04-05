#include"head.h"
#include"myvector.h"


int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<string> v;
	v.reserve(5);
	string s("123");
	v.push_back(s);

	s[1] = '5';
	cout << &(v[0]) << endl;
	cout << &(s) << endl;
	return 0;
}