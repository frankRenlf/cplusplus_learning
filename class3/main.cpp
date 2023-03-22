#include<iostream>
using namespace std;
int main() {
	int* arr = new int[3] {1, 2, 3};
	int arr2[] = { 1,2,3,4 };
	for (auto& a : arr2)
	{
		a *= 2;
		cout << a << " ";
	}
	cout << endl;
	for (auto a : arr2)
	{
		cout << a << " ";
	}
	delete[] arr;
	return 0;
}