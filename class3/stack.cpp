#include<iostream>
using namespace std;
class Stack {
public:
	Stack() {
		this->_size = 0;
		_pre = new Node(-1);
		_top = _bottom = _pre->next;
	}
	void push(int val) {
		if (_top == nullptr) {
			_top = _bottom = new Node(val);
		}
		else {
			_top->next = new Node(val);
			_top = _top->next;
		}
		this->_size++;
	}
	int pop() {
		this->_size--;
		int ret = _top->val;
		Node* tmp = _bottom;
		while (tmp->next != _top) {
			tmp = tmp->next;
		}
		delete _top;
		tmp->next = nullptr;
		return ret;
	}
	void print() {
		Node* tmp = _bottom;
		while (tmp != nullptr) {
			cout << tmp << ": ";
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
private:
	class Node {
	public:
		Node(int val) {
			this->val = val;
			this->next = nullptr;
		}
		int val;
		Node* next;
	};
	int _size;
	Node* _pre;
	Node* _top;
	Node* _bottom;
};
//int main() {
//	Stack stack;
//	for (int i = 0; i < 5; i++)
//	{
//		stack.push(i);
//	}
//	stack.print();
//	cout << stack.pop() << endl;
//	stack.print();
//	return 0;
//}