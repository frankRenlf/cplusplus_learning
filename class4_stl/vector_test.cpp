#include"head.h"
#include"myvector.hpp"
vector<vector<int>> generate2(int numRows) {
	vector<vector<int>> vv(numRows);
	//vv.resize(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		vv[i].resize(i + 1, 1);
	}
	for (int i = 2; i < numRows; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	return vv;
}
template<class T>
void print_vector(frank::vector<T>& v) {
	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test2() {
	/*Solution s;
	auto v = s.generate2(5);*/
	//frank::vector<int> v;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	v.insert(v.begin(), i);
	//}

	//print_vector(v);

	//frank::vector<int> v2(10, 5);
	//print_vector(v2);

	//v = v2;
	//print_vector(v);
	vector<vector<int>> vv = generate2(5);
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}
class person {
public:

	person(int age, const char* str = "")
		:_age(age)
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	char* _str;
	int _age;
};
bool myfunction(person i, person j) {
	bool k = (i._age > j._age);
	bool l = (strcmp(i._str, j._str) > 0 ? true : false);
	if (l) {
		return true;
	}
	else {
		if (strcmp(i._str, j._str) == 0) {
			return k;
		}
	}
	return l;
}
//int main() {
//	//test2();
//
//	//cout << "leak? ";
//	//cout << _CrtDumpMemoryLeaks() << endl;
//	person p1(26, "abc");
//	person p2(23, "abc");
//	person p3(21, "www");
//	list<person> l;
//	l.push_back(p1);
//	l.push_back(p2);
//	l.push_back(p3);
//	vector<person> v;
//	for (auto var : l)
//	{
//		v.push_back(var);
//	}
//	sort(v.begin(), v.end(), myfunction);
//	for (auto var : v)
//	{
//		cout << var._str << " " << var._age << endl;
//	}
//	return 0;
//}
void test10() {
	frank::vector<int> v;
	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	const frank::vector<int> lt2 = v;
	frank::vector<int>::const_riterator it = lt2.rbegin();
	while (it != lt2.rend()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main() {
	test10();
	return 0;
}