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
	frank::string s1("123");
	s1.push_back('a');
	s1.push_back('b');
	s1.push_back('c');
	s1.push_back('d');
	cout << s1 << endl;
	s1 += "welcome";
	frank::string s2("mine 11234");
	s1 += s2;
	cout << s1 << " " << s1.size() << endl;
}
int main() {
	test1();
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}