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
		~Node() {
			delete this;
		}
	//private:
		int _val;
		Node* next;
	};
	Node* head;
	Node* tail;
	int _size;
};
//int main() {
//	list l;
//	l.add(1);
//	l.add(2);
//	return 0;
//}