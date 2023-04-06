#include"head.h"
#include"myvector.hpp"

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
	frank::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.insert(v.begin(), i);
	}

	print_vector(v);

	frank::vector<int> v2(10, 5);
	print_vector(v2);

	v = v2;
	print_vector(v);
}
frank::vector<frank::vector<int>> generate(int numRows) {
	frank::vector<frank::vector<int>> vv;
	vv.resize(numRows);
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
int main() {
	//test2();
	frank::vector<frank::vector<int>> vv = generate(5);
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << "leak? ";
	cout << _CrtDumpMemoryLeaks() << endl;
	return 0;
}