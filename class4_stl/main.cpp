#include<iostream>

using namespace std;
class Solution {
public:
	string reverseOnlyLetters(string s) {
		int n = s.size();
		string::iterator left = s.begin(), right = s.end() - 1;
		while (true) {
			while (left < right && !isalpha(*left)) { // �ж�����Ƿ�ɨ�赽��ĸ
				left++;
			}
			while (right > left && !isalpha(*right)) { // �ж��ұ��Ƿ�ɨ�赽��ĸ
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
	string::iterator it = s->end() - 1;
	for (;; it--)
	{
		cout << *it << endl;
		if (it == s->begin())break;
	}

	return 0;
}