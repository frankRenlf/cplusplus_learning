#include"head.h"
#include"myvector.h"

void test(string& s) {
	s[0] = 'a';
}
int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<string> v;
	v.reserve(5);
	string s("123");
	v.push_back(s);

	s[1] = '5';
	v.push_back(s);
	v.push_back(s);

	for (frank::vector<string>::iterator i = v.begin(); i < v.end(); i++)
	{
		cout << *i << endl;
	}
	return 0;
}