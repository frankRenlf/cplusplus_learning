class Date
{
public:
	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
	// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
	//Date(int year)
	//	:_year(year)
	//{}
	
	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���������ת������
	// explicit���ι��캯������ֹ����ת��
	Date(int year, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{}
	
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1(2022);
	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
	d1 = 2023;
	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת������
}
//int main() {
//	Test();
//	return 0;
//}