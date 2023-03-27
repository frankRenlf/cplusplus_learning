#include<iostream>
using namespace std;
class LinkedList {
public:
	LinkedList() {
		pre = new ListNode(-1); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
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
	~LinkedList() {
		ListNode* cur = pre;
		while (cur != nullptr) {
			ListNode* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
	}
	void insert(int val) {
		if (tail == nullptr) {
			head = tail = new ListNode(val);
			pre->next = head;
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