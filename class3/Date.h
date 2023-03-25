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

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d) {
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	// ��������
	~Date() {

	}

	// check
	void format();
	// ����
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	void print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// ����+����
	Date operator+(int day) {
		this->_day += day;
		format();
		return *this;
	}
	// ����-����
	Date operator-(int day) {
		this->_day -= day;
		format();
		return *this;
	}
	// ����+=����
	Date& operator+=(int day) {
		this->_day += day;
		format();
		return *this;
	}
	// ����-=����
	Date& operator-=(int day) {
		this->_day -= day;
		format();
		return *this;
	}
	// ǰ��++
	Date& operator++() {
		(*this) += 1;
		return *this;
	}
	// ����++
	Date operator++(int) {
		Date tmp(*this);
		this->_day++;
		format();
		return tmp;
	}
	// ǰ��--
	Date& operator--() {
		(*this) -= 1;
		return *this;
	}
	// ����--
	Date operator--(int) {
		Date tmp(*this);
		this->_day--;
		format();
		return tmp;
	}


	// >���������
	bool operator>(const Date& d) {
		return !((*this) <= d);
	}
	// ==���������
	bool operator==(const Date& d) {
		return this->_year == d._year
			&& this->_month == d._month
			&& this->_day == d._day;
	}
	// >=���������
	bool operator >= (const Date& d) {
		return !((*this) < d);
	}

	// <���������
	bool operator < (const Date& d) {
		if ((this->_year < d._year)
			|| (this->_year == d._year && this->_month < d._month)
			|| (this->_year == d._year && this->_month == d._month && this->_day < d._day)) {
			return true;
		}
		return false;
	}
	// <=���������
	bool operator <= (const Date& d) {
		return (*this) < d || (*this) == d;
	}
	// !=���������
	bool operator != (const Date& d) {
		return !((*this) == d);
	}
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};