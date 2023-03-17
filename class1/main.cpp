#include<iostream>

#include"head.h"

using namespace std;

int test1(int a=3) {
	return a * a;
}
int test1(int a,int b) {
	return a * a;
}
int main() {
	int x = test1();
	cout << "hello " << x << endl;
}