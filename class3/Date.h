#pragma once
#include<iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
class Date
{
public:

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d) {
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	// 析构函数
	~Date() {

	}

	// check
	void format(Date* const tmp);
	// 闰年
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	void print() const {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// 日期+天数
	Date operator+(int day) {
		Date tmp(*this);
		tmp._day += day;
		format(&tmp);
		return tmp;
	}
	// 日期-天数
	Date operator-(int day) {
		Date tmp(*this);
		tmp._day -= day;
		format(&tmp);
		return tmp;
	}
	// 日期+=天数
	Date& operator+=(int day) {
		this->_day += day;
		format(this);
		return *this;
	}
	// 日期-=天数
	Date& operator-=(int day) {
		this->_day -= day;
		format(this);
		return *this;
	}
	// 前置++
	Date& operator++() {
		(*this) += 1;
		return *this;
	}
	// 后置++
	Date operator++(int) {
		Date tmp(*this);
		this->_day++;
		format(this);
		return tmp;
	}
	// 前置--
	Date& operator--() {
		(*this) -= 1;
		return *this;
	}
	// 后置--
	Date operator--(int) {
		Date tmp(*this);
		this->_day--;
		format(this);
		return tmp;
	}


	// >运算符重载
	bool operator>(const Date& d) {
		return !((*this) <= d);
	}
	// ==运算符重载
	bool operator==(const Date& d) {
		return this->_year == d._year
			&& this->_month == d._month
			&& this->_day == d._day;
	}
	// >=运算符重载
	bool operator >= (const Date& d) {
		return !((*this) < d);
	}

	// <运算符重载
	bool operator < (const Date& d) {
		if ((this->_year < d._year)
			|| (this->_year == d._year && this->_month < d._month)
			|| (this->_year == d._year && this->_month == d._month && this->_day < d._day)) {
			return true;
		}
		return false;
	}
	// <=运算符重载
	bool operator <= (const Date& d) {
		return (*this) < d || (*this) == d;
	}
	// !=运算符重载
	bool operator != (const Date& d) {
		return !((*this) == d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d);

	// stream overwrite
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};