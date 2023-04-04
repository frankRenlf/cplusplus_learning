#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
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
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)return len;
		auto iter = nums.begin() + 1;
		while (iter != nums.end()) {
			if (*(iter - 1) == *iter) {
				nums.erase(iter);
			}
			else {
				iter++;
			}
		}
	}
};