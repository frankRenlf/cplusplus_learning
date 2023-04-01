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
	char* s = new char[5] {'a', 'b', 'c', 'd', '\0'};
	cout << strlen(s) << endl;
	for (int i = 0; i < 4; i++)
	{
		s[i] += i;
	}
	cout << s << endl;
	string s2(s);
	cout << s2.size() << endl;
	return 0;
}