#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include <unordered_map>
using namespace std;
class MinStack {
public:
	MinStack() {
		stack2.push(INT_MAX);
	}

	void push(int val) {
		stack1.push(val);
		stack2.push(min(stack2.top(), val));
	}

	void pop() {
		stack1.pop();
		stack2.pop();
	}

	int top() {
		return stack1.top();
	}

	int getMin() {
		return stack2.top();
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
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
	string reverseWords(string s) {
		int pos = s.find(" ");
		string ret = "";
		while (pos != string::npos) {
			string sub = s.substr(0, pos);
			reverse(sub.begin(), sub.end());
			ret += sub + " ";
			s = s.substr(pos + 1);
			pos = s.find(" ");
		}
		reverse(s.begin(), s.end());
		ret += s;
		return ret;
	}
	string reverseWords_ori(string s) {
		int length = s.length();
		int i = 0;
		while (i < length) {
			int start = i;
			while (i < length && s[i] != ' ') {
				i++;
			}

			int left = start, right = i - 1;
			while (left < right) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
			while (i < length && s[i] == ' ') {
				i++;
			}
		}
		return s;
	}
	char firstUniqChar(string s) {
		int arr[26] = { 0 };
		int length = s.size();
		for (auto ch : s)
		{
			arr[ch - 'a']++;
		}
		for (size_t i = 0; i < length; i++)
		{
			if (arr[s[i] - 'a'] == 1)return s[i];
		}
		return ' ';
	}
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v;
		for (size_t i = 0; i < numRows; i++)
		{
			vector<int> el;
			for (size_t j = 0; j <= i; j++)
			{
				if (i >= 1) {
					if (j >= 1 && j < i) {
						el.push_back(v[i - 1][j - 1] + v[i - 1][j]);
					}
					else {
						el.push_back(1);
					}
				}
				else {
					el.push_back(1);
				}
			}
			v.push_back(el);
		}
		return v;
	}
	vector<vector<int>> generate2(int numRows) {
		vector<vector<int>> v(numRows);
		for (size_t i = 0; i < numRows; i++)
		{
			v[i].resize(i + 1, 1);
			for (size_t j = 0; j <= i; j++)
			{
				if (i >= 1) {
					if (j >= 1 && j < i) {
						v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
					}
					else {
						v[i][j] = 1;
					}
				}
				else {
					v[i][j] = 1;
				}
			}
		}
		return v;
	}
	vector<vector<int>> generate3(int numRows) {
		vector<vector<int>> ret(numRows);
		for (int i = 0; i < numRows; ++i) {
			ret[i].resize(i + 1);
			ret[i][0] = ret[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
		return ret;
	}
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)return len;
		auto iter = nums.begin() + 1;
		while (iter != nums.end()) {
			if (*(iter - 1) == *iter) {
				nums.erase(iter);
				len--;
			}
			else {
				iter++;
			}
		}
		return len;
	}
	vector<string> combinations;
	unordered_map<char, string> phoneMap{
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) {
			return combinations;
		}

		string combination;
		backtrack(digits, digits.size(), 0, combination);
		return combinations;
	}

	void backtrack(const string& digits, int n, int index, string& combination) {
		if (index == n) {
			combinations.push_back(combination);
			return;
		}
		char c = digits[index];
		for (auto x : phoneMap[c]) {
			combination.push_back(x);
			backtrack(digits, n, index + 1, combination);
			combination.pop_back();
		}
	}

};