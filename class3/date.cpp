#include<iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
class Date
{
public:
	// 闰年
	// 获取某年某月的天数
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
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	// 析构函数
	~Date() {

	}

	// check
	void format() {
		int limitDay = this->GetMonthDay(this->_year, this->_month);
		while (this->_day > limitDay) {
			this->_day -= limitDay;
			this->_month++;
			if (this->_month > 12) {
				this->_month -= 12;
				this->_year++;
			}
			limitDay = this->GetMonthDay(this->_year, this->_month);
		}
		while (this->_day <= 0) {
			if (this->_month == 1) {
				this->_month = 12;
				this->_year--;
			}
			else {
				this->_month--;
			}
			limitDay = this->GetMonthDay(this->_year, this->_month);
			this->_day += limitDay;
		}
	}
	// 日期+天数
	Date operator+(int day) {
		this->_day += day;
		format();
		return *this;
	}
	// 日期-天数
	Date operator-(int day) {
		this->_day -= day;
		format();
		return *this;
	}
	// 日期+=天数
	Date& operator+=(int day) {
		this->_day += day;
		format();
		return *this;
	}
	// 日期-=天数
	Date& operator-=(int day) {
		this->_day -= day;
		format();
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
		format();
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
		format();
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
	int operator-(const Date& d) {
		this->_year -= d._year;
		this->_month -= d._month;
		while (this->_month <= 0) {
			this->_year--;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
int main() {
	Date d1(2, 2, 28);
	Date d2(2, 3, 30);
	//d2 += 90;
	d2 -= 30;
	cout << (d1 >= d2) << endl;
	return 0;
}