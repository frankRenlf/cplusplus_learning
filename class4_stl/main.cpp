#include<iostream>

using namespace std;
class Solution {
public:
	string reverseOnlyLetters(string s) {
		int n = s.size();
		string::iterator left = s.begin(), right = s.end() - 1;
		while (true) {
			while (left < right && !isalpha(*left)) { // ÅÐ¶Ï×ó±ßÊÇ·ñÉ¨Ãèµ½×ÖÄ¸
				left++;
			}
			while (right > left && !isalpha(*right)) { // ÅÐ¶ÏÓÒ±ßÊÇ·ñÉ¨Ãèµ½×ÖÄ¸
				right--;
			}
			if (left >= right) {
				break;
			}
			swap(*left, *right);
			left++;
			right--;
		}
		return s;
	}
};

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
	(*s) += "abc";
	cout << *s << endl;
	while (!s->empty()) {
		cout << s->back() << " ";
		s->pop_back();
	}
	return 0;
}