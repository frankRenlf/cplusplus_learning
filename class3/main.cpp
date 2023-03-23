#include<iostream>
#include <vector>
using namespace std;
class A {
public:
	void show() {
		cout << "show()" << this->a << endl;
	}
private:
	int a;
};
int main() {
	A* a = nullptr;
	a->show();
	return 0;

}