#include<iostream>
#include <vector>
#include <cassert>
using namespace std;
class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

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
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
int main() {
	Date d1(1);
	Date d2(2);
	d1 = d2;
	return 0;
}