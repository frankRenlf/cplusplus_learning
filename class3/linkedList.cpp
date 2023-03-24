#include<iostream>
using namespace std;
class LinkedList {
public:
	LinkedList() {
		pre = new ListNode(-1); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
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
//int main() {
//	LinkedList p;
//	for (int i = 0; i < 10; i++)
//	{
//		p.insert(i);
//	}
//	p.Print();
//	return 0;
//}