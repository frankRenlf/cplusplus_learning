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
		memcpy(this->arr, b.arr, 5 * sizeof(int));
	}
	~B() {
		if (arr) {
			free(arr);
			arr = nullptr;
			cout << "free" << endl;
		}
	}
	bool operator==(const B& b2) {
		bool k = true;
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] != b2.arr[i])
			{
				k = false;
			}
		}
		return b == b2.b
			&& k;
	}
	B& operator=(const B& b2) {
		if (this == &b2) {
			return *this;
		}
		this->b = b2.b;
		this->arr = (int*)malloc(sizeof(int) * 5);
		assert(this->arr);
		memcpy(this->arr, b2.arr, 5 * sizeof(int));
		return *this;
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
//private:
	int b;
	int* arr;
};
class A {
public:
	A(int val)
		: a(val)
		, b(val)
	{}
	~A() {
	}
	bool operator==(const A& a1) {
		return a == a1.a
			&& b == a1.b;
	}
	void show() {
		b.show();
	}
//private:
	int a;
	B b;
};

int main() {
	A a(1);
	//a.show();
	A a2(a);
	//a2.show();
	cout << (a == a2) << endl;
	A a3(3);
	A a4(4);
	a4.b.arr[0] = 2;
	a3 = a4;	
	cout << (a3 == a4) << endl;

	return 0;

}