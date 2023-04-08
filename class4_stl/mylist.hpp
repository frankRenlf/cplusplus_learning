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
	template<class T, class Ref, class Ptr>
	class __list_iterator {
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
	public:
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		Ref operator*() {
			return _node->_data;
		}
		Ptr operator->() {
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
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		iterator begin() {
			return iterator(_head->_next);
		}
		const_iterator begin() const {
			return const_iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		const_iterator end() const {
			return const_iterator(_head);
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

		void insert(iterator pos, const T& data) {
			Node* newNode = new Node(data);
			Node* cur = pos._node;
			cur->_prev->_next = newNode;
			newNode->_prev = cur->_prev;
			newNode->_next = cur;
			cur->_prev = newNode;
		}

	private:
		Node* _head;
	};
}