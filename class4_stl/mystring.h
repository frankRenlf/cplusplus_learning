#pragma once
#include<iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
namespace frank {
	class string {
	public:
		string(const char* str = "")
			: _size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		~string() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
			}
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

		size_t size()const
		{
			return _size;
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
	private:
		friend ostream& operator<<(ostream& _cout, const frank::string& s);
		friend istream& operator>>(istream& _cin, frank::string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
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