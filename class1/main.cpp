#include<iostream>

#include"head.h"
#include <stdlib.h>

using namespace std;
namespace R {
	int rand = 10;
}
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
	cout <<  R::rand << endl;
	return 0;
}