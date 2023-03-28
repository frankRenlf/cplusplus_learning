#include<iostream>
#include<vector>
using namespace std;
template<class T>
class LinkedList {
public:
	LinkedList() {
		pre = new ListNode(); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
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
	// ���ú�������main����֮��ÿ�γ����˳���ʱ��ͻ����Ƿ�����ڴ�й©
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