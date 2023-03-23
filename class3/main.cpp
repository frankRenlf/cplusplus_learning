#include<iostream>
#include <vector>
using namespace std;
class B {
public:
	B() {
		this->b = 2;
	}
private:
	int b;
};
class A {
public:
	A() {
		a = 1;
	}
	void show() {
		cout << "show()" << this->a << endl;
	}
private:
	int a;
	B b;
};
int main() {
	A a;
	return 0;

}