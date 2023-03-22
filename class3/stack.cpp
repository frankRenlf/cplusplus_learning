#include<iostream>
using namespace std;
class Stack {
public:
	Stack() {
		this->_size = 0;
		pre = new Node(-1);
		top = bottom = pre->next;
	}
	void push(int val) {
		if (top == nullptr) {
			top = bottom = new Node(val);
		}
		else {
			top->next = new Node(val);
			top = top->next;
		}
		this->_size++;
	}
	int pop() {
		this->_size--;
		int ret = top->val;
		Node* tmp = bottom;
		while (tmp->next != top) {
			tmp = tmp->next;
		}
		delete top;
		tmp->next = nullptr;
		return ret;
	}
	void print() {
		Node* tmp = bottom;
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
	Node* pre;
	Node* top;
	Node* bottom;
};
int main() {
	Stack stack;
	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
	}
	stack.print();
	cout << stack.pop() << endl;
	stack.print();
	return 0;
}