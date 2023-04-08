#pragma once
#include<iostream>
#include <cassert>
#define DEFAULT_SIZE 4
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace frank {
	template<class T>
	class list_node {
	public:
		list_node(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
		//~list_node() {
		//	_next = nullptr;
		//	_prev = nullptr;
		//}

		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;
	};
	template<class T>
	class __list_iterator {
		typedef list_node<T> Node;
		typedef __list_iterator<T> self;
	public:
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		T& operator*() {
			return _node->_data;
		}
		T* operator->() {
			return &(operator*());
		}
		self& operator++() {
			_node = _node->_next;
			return *this;
		}
		self operator++(int) {
			self old = *this;
			_node = _node->_next;
			return old;
		}
		self& operator--() {
			_node = _node->_prev;
			return *this;
		}
		self operator--(int) {
			self old = *this;
			_node = _node->_prev;
			return old;
		}
		bool operator!=(const self& it) {
			return _node != it._node;
		}
		bool operator==(const self& it) {
			return _node == it._node;
		}
	};

	template<class T>
	class list {
	public:
		typedef __list_iterator<T> iterator;
		iterator begin() {
			return iterator(_head->_next);
		}
		iterator begin() const {
			return iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		iterator end() const {
			return iterator(_head);
		}
		list() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//~list() {
		//	Node* cur = _head->_next;
		//	_head->_prev->_next = nullptr;
		//	delete _head;
		//	while (cur != nullptr) {
		//		Node* next = cur->_next;
		//		delete cur;
		//		cur = next;
		//	}
		//}
		void push_back(const T& data) {
			Node* tail = _head->_prev;
			Node* newNode = new Node(data);
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
		}

	private:
		typedef list_node<T> Node;
		Node* _head;
	};
}