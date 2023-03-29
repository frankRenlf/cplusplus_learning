#include<iostream>

using namespace std;

int main() {
	string* s = new string("123");
	cout << s << ": " << *s << endl;
	reverse(s->begin(), s->end());
	cout << *s << endl;
	string::iterator iter = s->begin();
	while (iter != s->end()) {
		cout << *iter << endl;
		iter++;
	}
	cout << "end" << endl;
	return 0;
}