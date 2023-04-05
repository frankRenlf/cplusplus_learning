#include"head.h"
#include"myvector.h"

void test(string& s) {
	s[0] = 'a';
}
int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<string> v;
	string s("123");
	v.push_back(s);

	s[1] = '5';
	v.push_back(s + 'b');
	v.push_back(s + 'c');
	v.insert(v.end(), "xxx");
	for (frank::vector<string>::iterator i = v.begin(); i < v.end(); i++)
	{
		cout << *i << endl;
	}
	return 0;
}