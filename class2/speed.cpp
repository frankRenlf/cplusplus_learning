#include <time.h>
#include<iostream>

//#include"head.h"

using namespace std;
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
int mul(int a, int b) {
	int c = a * b;
	return c;
}
inline int mul_inline(int a, int b) {
	int c = a * b;
	return c;
}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 20000; ++i) {
		mul(3, 3);
	}
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 20000; ++i) {
		mul_inline(3, 3);
	}
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
	//cout << ((end1 - begin1)<(end2 - begin2)) << endl;
}
//int main() {
//	TestRefAndValue();
//	return 0;
//}