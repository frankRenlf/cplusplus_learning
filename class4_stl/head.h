#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include <unordered_map>

using namespace std;
class MyStack {
public:
	MyStack() {

	}

	void push(int x) {
		_q.push(x);
		while (!_s.empty()) {
			_q.push(_s.front());
			_s.pop();
		}
		while (!_q.empty()) {
			_s.push(_q.front());
			_q.pop();
		}
	}

	int pop() {
		int ret = _s.front();
		_s.pop();
		return ret;
	}

	int top() {
		return _s.front();
	}

	bool empty() {
		return _s.empty() && _q.empty();
	}
private:
	queue<int> _s;
	queue<int> _q;
};
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
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (auto el : nums) {
			pq.push(el);
		}
		while (k > 1) {
			pq.pop();
			k--;
		}
		return pq.top();
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> _st;
		for (auto s : tokens) {
			if (isdigit(s[s.size() - 1])) {
				_st.push(stoi(s));
			}
			else {
				string oper = s;
				int a1 = _st.top();
				_st.pop();
				int a2 = _st.top();
				_st.pop();
				int add = 0;
				if (s == "+") {
					add = a2 + a1;
				}
				else if (s == "-") {
					add = a2 - a1;
				}
				else if (s == "*") {
					add = a2 * a1;
				}
				else {
					add = a2 / a1;
				}
				_st.push(add);
			}
		}
		return _st.top();
	}
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int n = pushV.size();
		//辅助栈
		stack<int> s;
		//遍历入栈的下标
		int j = 0;
		//遍历出栈的数组
		for (int i = 0; i < n; i++) {
			//入栈：栈为空或者栈顶不等于出栈数组
			while (j < n && (s.empty() || s.top() != popV[i])) {
				s.push(pushV[j]);
				j++;
			}
			//栈顶等于出栈数组
			if (s.top() == popV[i])
				s.pop();
			//不匹配序列
			else
				return false;
		}
		return true;
	}
	string reverseOnlyLetters(string s) {
		int n = s.size();
		string::iterator left = s.begin(), right = s.end() - 1;
		while (true) {
			while (left < right && !isalpha(*left)) { // 判断左边是否扫描到字母
				left++;
			}
			while (right > left && !isalpha(*right)) { // 判断右边是否扫描到字母
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