#include"head.h"
#include"myvector.hpp"

void test(string& s) {
	s[0] = 'a';
}
int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	std::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.insert(v.begin(), i);
	}
	//for (frank::vector<int>::iterator i = v.begin(); i < v.end(); i++)
	//{
	//	if ((*i % 2) == 0) {
	//		i = v.insert(i, 100);
	//		i++;
	//	}
	//}
	auto pos = v.begin();
	v.erase(pos);

	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	return 0;
}