#include"mystring.h"

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
int main() {
	frank::string s1("123");
	frank::string s2(s1);
	frank::string s3 = s2;
	return 0;
}