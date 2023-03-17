#include<iostream>

#include"head.h"

using namespace std;

int test1(int a=3) {
	return a * a;
}
int test1(int a,int b) {
	return a * a;
}
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}