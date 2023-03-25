#include"Date.h"
int Date::GetMonthDay(int year, int month)
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
void Date::format() {
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
		this->_month--;
		if (this->_month == 0) {
			this->_month = 12;
			this->_year--;
		}
		limitDay = this->GetMonthDay(this->_year, this->_month);
		this->_day += limitDay;
	}
}
int Date::operator-(const Date& d) {
	this->_year -= d._year;
	this->_month -= d._month;
	while (this->_month <= 0) {
		this->_year--;
	}
	return 0;
}
int main() {
	Date d1(2, 2, 28);
	Date d2(2, 3, 30);
	//d2 += 90;
	d2 -= 29;
	cout << (d1 >= d2) << endl;
	return 0;
}