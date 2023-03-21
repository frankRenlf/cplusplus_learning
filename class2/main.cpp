#include<iostream>

//#include"head.h"

using namespace std;


int& Add2(int a, int b)
{
	int x = a + b;
	return x;
}
int& Add(int a, int b)
{
	static int c;
	c = a + b;
	return c;
}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}
int main() {
	int a = 10;
	int& x = a;
	int* y = &a;
	*y = 15;
	cout << x << endl;
	cout << *y << endl;
}