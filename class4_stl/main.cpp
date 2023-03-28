#include<iostream>

using namespace std;

int main() {
	string* s = new string("123");
	cout << s << ": " << *s << endl;
	return 0;
}