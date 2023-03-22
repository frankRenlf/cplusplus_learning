#include<iostream>
using namespace std;
//int main() {
//	int* arr = new int[3] {1, 2, 3};
//	int arr2[] = { 1,2,3,4 };
//	for (auto& a : arr2)
//	{
//		a *= 2;
//		cout << a << " ";
//	}
//	cout << endl;
//	for (auto a : arr2)
//	{
//		cout << a << " ";
//	}
//	delete[] arr;
//	return 0;
//}
class LinkedList {
public:
	LinkedList() {
		pre = new ListNode(-1); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
		head = pre->next;
		tail = head;
		_size = 0;
	}
	void Print() {
		ListNode* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void insert(int val) {
		if (tail == nullptr) {
			head = tail = new ListNode(val);
		}
		else {
			tail->next = new ListNode(val);
			tail = tail->next;
		}
		_size++;
	}
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int val) :val(val), next(nullptr) {
		}
	};
private:
	ListNode* head;
	ListNode* pre;
	ListNode* tail;
	int _size = 0;
};
//int main() {
//	int* a = NULL;
//	int* b = nullptr;
//	cout << a << endl;
//	cout << b << endl;
//
//}
int main() {
	LinkedList p;
	for (int i = 0; i < 10; i++)
	{
		p.insert(i);
	}
	p.Print();
	return 0;
}