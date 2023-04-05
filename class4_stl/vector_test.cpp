#include"head.h"
#include"myvector.h"

void test(string& s) {
	s[0] = 'a';
}
int main() {
	/*Solution s;
	auto v = s.generate2(5);*/
	frank::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.insert(v.begin(), i);
	}
	for (frank::vector<int>::iterator i = v.begin(); i < v.end(); i++)
	{
		if ((*i % 2) == 0) {
			i = v.insert(i, 100);
			i++;
		}
	}v.insert(v.end()-1, 999);
	for (frank::vector<int>::iterator i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	return 0;
}