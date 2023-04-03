#pragma once
#include<iostream>
#include <cassert>
#define DEFAULT_SIZE 4
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
namespace frank {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		string(const char* str = "")
			: _size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			tmp._capacity = s._capacity;
			this->swap(tmp);
		}

		~string() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
			}
		}

		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		string& operator+=(const string& str) {
			append(str._str);
			return *this;
		}

		iterator begin() {
			return _str;
		}
		const_iterator begin()const {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator end()const {
			return _str + _size;
		}

		void push_back(char ch) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? DEFAULT_SIZE : _capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* s) {
			size_t sum = strlen(s) + _size;
			reserve(sum);
			strcpy(_str + _size, s);
			_size = sum;
		}
		void resize(size_t n, char ch = '\0') {
			if (n > _capacity) {
				reserve(n);
			}
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[_size] = '\0';
		}
		void reserve(size_t newCapacity)
		{
			// 如果新容量大于旧容量，则开辟空间
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);

				// 释放原来旧空间,然后使用新空间
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		bool empty() {
			return _size == 0;
		}

		string& operator=(const string& s) {
			if (this != &s) {
				string tmp(s._str);
				this->swap(tmp);
				//_capacity = _size = s._capacity;
				//delete[] _str;
				//_str = new char[_capacity + 1];
				//strcpy(_str, s._str);
			}
			return *this;
		}

		bool operator<(const string& s) {
			return strcmp(_str, s._str) < 0;
		}
		bool operator<=(const string& s) {
			return strcmp(_str, s._str) <= 0;
		}
		bool operator>(const string& s) {
			return !(*this <= s);
		}
		bool operator>=(const string& s) {
			return !(*this < s);
		}
		bool operator==(const string& s) {
			return strcmp(_str, s._str) == 0;
		}
		bool operator!=(const string& s) {
			return !(*this == s);
		}
		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);

		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len);
	private:
		friend ostream& operator<<(ostream& _cout, const frank::string& s);
		friend istream& operator>>(istream& _cin, frank::string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	ostream& operator<<(ostream& _cout, const frank::string& s)
	{
		// 不能使用这个, 因为string的字符串内部可能会包含\0
		// 直接cout时, 是将_str当成char*打印的，遇到内部的\0时后序内容就不打印了
		//cout << s._str;
		for (size_t i = 0; i < s.size(); ++i)
		{
			_cout << s[i];
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, frank::string& s)
	{
		// 不能使用这个, 因为string的字符串内部可能会包含\0
		// 直接cout时, 是将_str当成char*打印的，遇到内部的\0时后序内容就不打印了
		//cout << s._str;
		for (size_t i = 0; i < s.size(); ++i)
		{
			_cin >> s[i];
		}
		return _cin;
	}
}