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

	string s1("123");
	string s2("abc");
	//s1.swap(s2);
	//swap(s1, s2);
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
	cout << s1 << " " << s2 << endl;
	return 0;
}