#pragma once
#include<iostream>
#include <cassert>
using namespace std;
namespace frank {
	class string {
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
			}
		}
		size_t size()const
		{
			return _size;
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
		// ����ʹ�����, ��Ϊstring���ַ����ڲ����ܻ����\0
		// ֱ��coutʱ, �ǽ�_str����char*��ӡ�ģ������ڲ���\0ʱ�������ݾͲ���ӡ��
		//cout << s._str;
		for (size_t i = 0; i < s.size(); ++i)
		{
			_cout << s[i];
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, frank::string& s)
	{
		// ����ʹ�����, ��Ϊstring���ַ����ڲ����ܻ����\0
		// ֱ��coutʱ, �ǽ�_str����char*��ӡ�ģ������ڲ���\0ʱ�������ݾͲ���ӡ��
		//cout << s._str;
		for (size_t i = 0; i < s.size(); ++i)
		{
			_cin >> s[i];
		}
		return _cin;
	}
}