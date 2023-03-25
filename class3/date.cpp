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
void Date::format(Date* tmp) {
	int limitDay = tmp->GetMonthDay(tmp->_year, tmp->_month);
	while (tmp->_day > limitDay) {
		tmp->_day -= limitDay;
		tmp->_month++;
		if (tmp->_month > 12) {
			tmp->_month -= 12;
			tmp->_year++;
		}
		limitDay = tmp->GetMonthDay(tmp->_year, tmp->_month);
	}
	while (tmp->_day <= 0) {
		tmp->_month--;
		if (tmp->_month == 0) {
			tmp->_month = 12;
			tmp->_year--;
		}
		limitDay = tmp->GetMonthDay(tmp->_year, tmp->_month);
		tmp->_day += limitDay;
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
	Date d2(2022, 5, 31);
	Date d3 = d2++;
	Date d4 = ++d2;
	d3.print();
	d4.print();
	return 0;
}