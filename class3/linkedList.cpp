#include<iostream>
#include<vector>
using namespace std;
template<class T>
class LinkedList {
public:
	LinkedList() {
		pre = new ListNode(); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
		head = nullptr;
		tail = nullptr;
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
	void insert(T val) {
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
	class ListNode {
	public:
		ListNode(T val) :val(val), next(nullptr) {}
		ListNode() :val(), next(nullptr) {}
		~ListNode() {}
		T val;
		ListNode* next;
	};
private:
	ListNode* head;
	ListNode* pre;
	ListNode* tail;
	int _size;
};
//int main() {
//	int* a = NULL;
//	int* b = nullptr;
//	cout << a << endl;
//	cout << b << endl;
//
//}
int main() {
	LinkedList<int>* p = new LinkedList<int>;
	for (double i = 0.0; i < 10.0; i++)
	{
		p->insert(i + 1.2);
	}
	p->Print();
	// 将该函数放在main函数之后，每次程序退出的时候就会检测是否存在内存泄漏
	delete p;
	try {
		_CrtDumpMemoryLeaks();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	vector<int> v;

	return 0;
}  