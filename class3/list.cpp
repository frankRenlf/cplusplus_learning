#include<iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;

class list {
public:
	list() {
		head = new Node(-1);
		tail = head;
		_size = 0;
	}
	~list() {
		Node* tmp = head;
		while (tmp != nullptr) {
			Node* nt = tmp;
			tmp = tmp->next;
			delete nt;
		}
	}
	void add(int val) {
		;
		tail->next = new Node(val);
		tail = tail->next;
		_size++;
	}
	void print() {
		Node* tmp = head;
	}
private:
	class Node {
	public:
		Node(int val)
			:_val(val)
			, next(nullptr)
		{}

		//private:
		int _val;
		Node* next;
	};
	Node* head;
	Node* tail;
	int _size;
};
int main() {
	list l;
	l.add(1);
	l.add(2);
	list l2(l);
	return 0;
}
