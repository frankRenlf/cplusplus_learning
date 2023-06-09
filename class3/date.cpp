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
void Date::format(Date* const tmp) const {
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
void print(const Date& d) {
	d.print();
}

int Date::operator-(const Date& d) const {
	int k = *this >= d ? 1 : -1;
	Date d1(*this >= d ? *this : d);
	Date d2(*this < d ? *this : d);
	int sub = 0;
	while (d1 > d2) {
		sub++;
		d2++;
	}
	return sub * k;
}
std::ostream& operator<<(std::ostream& out, const Date& d) {
	out << d._year << "-" << d._month << "-" << d._day;
	return out;
}
std::istream& operator>>(std::istream& in, Date& const d) {
	in >> d._year >> d._month >> d._day;
	return in;
}

//int main() {
//	Date d1(2023, 3, 25);
//	Date d2(2024, 1, 1);
//	
//	cout << d2 - d1<< endl;
//
//	cout << d1 << " " << d2 << endl;
//	cin >> d2;
//	cout << d2;
//	return 0;
//}