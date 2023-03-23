#include<iostream>
#include <vector>
#include <cassert>
using namespace std;
class B {
public:
	B(int b) {
		this->b = b;
		arr = (int*)malloc(sizeof(int) * 5);
		add();
	}
	B(B& b) {
		this->b = b.b;
		this->arr = (int*)malloc(sizeof(int) * 5);
		assert(this->arr);
		memcpy(this->arr, b.arr, 5* sizeof(int));
	}
	~B() {
		if (arr) {
			free(arr);
			arr = nullptr;
			cout << "free" << endl;
		}
	}
	void add() {
		for (int i = 0; i < 5; i++)
		{
			arr[i] = i;
		}
	}
	void show() {
		int* tmp = arr;
		int size = 5;
		while (size > 0) {
			cout << *tmp << " ";
			tmp++;
			size--;
		}
		cout << endl;
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
		b.show();
	}
private:
	int a;
	B b;
};
int main() {
	A a;
	a.show();
	A a2(a);
	a2.show();
	return 0;

}