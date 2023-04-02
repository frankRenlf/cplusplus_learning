#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <assert.h>

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
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

		string& operator=(string s)
		{
			this->swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		/////////////////////////////////////////////////////////////////
		// iterator
		iterator begin() 
		{ 
			return _str; 
		}

		iterator end() 
		{ 
			return _str + _size; 
		}

		/////////////////////////////////////////////////////////////////
		// modify
		void push_back(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		// 作业实现
		void append(const char* str);
		string& operator+=(const char* str);

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}

		/////////////////////////////////////////////////////////////////
		// capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				// 如果newSize大于底层空间大小，则需要重新开辟空间
				if (newSize > _capacity)
				{
					reserve(newSize);
				}

				memset(_str + _size, c, newSize - _size);
			}

			_size = newSize;
			_str[newSize] = '\0';
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

		////////////////////////////////////////////////////////////////////
		// access
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

		////////////////////////////////////////////////////////////////////
		// 作业
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

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
		friend ostream& operator<<(ostream& _cout, const bit::string& s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	ostream& operator<<(ostream& _cout, const bit::string& s)
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
}

///////对自定义的string类进行测试
void TestBitstring()
{
	bit::string s1("hello");
	s1.push_back(' ');
	s1.push_back('b');
	s1.push_back('i');
	s1 += 't';
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// 利用迭代器打印string中的元素
	bit::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	// 这里可以看到一个类只要支持的基本的iterator，就支持范围for
	for (auto ch : s1)
		cout << ch;
	cout << endl;
}