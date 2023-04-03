#include"mystring.h"
#include"other_string.h"

//int main() {
//
//	string s1("123");
//	char* s = new char[5] {'a', 'b', 'c', 'd', '\0'};
//	cout << strlen(s) << endl;
//	for (int i = 0; i < 4; i++)
//	{
//		s[i] += i;
//	}
//	cout << s << endl;
//	string s2(s);
//	cout << s2.size() << endl;
//	size_t pos = s2.find("ce");
//	if (pos != string::npos) {
//		cout << s2.substr(pos);
//	}
//	else {
//		cout << "fail" << endl;
//	}
//	return 0;
//}
void test1() {
	frank::string s1("bcadf");
	frank::string s2("bcade");
	cout << (s1 <= s2) << " " << endl;
	frank::string::iterator iter = s1.begin();
	while (iter != s1.end()) {
		cout << *iter << " ";
		iter++;
	}
	for (auto ch : s2) {
		cout << ch;
	}
}
int main() {
	test1();
	cout << endl;
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}