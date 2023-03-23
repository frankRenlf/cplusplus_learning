#include<iostream>
#include <vector>
using namespace std;
class B {
public:
	B(int b) {
		this->b = b;
		arr = (int*)malloc(sizeof(int) * 5);
	}
	~B() {
		if (arr) {
			free(arr);
			arr = nullptr;
			cout << "free" << endl;
		}
	}
private:
	int b;
	int* arr;
};
class A {
public:
	A()
		: a(1)
		, b(2)
	{}
	//~A() {
	//}
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