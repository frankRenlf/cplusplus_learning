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
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;
	};
	template<class T>
	class __list_iterator {
	public:
		typedef list_node<T> Node;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		T& operator*() {
			return _node->_data;
		}
		__list_iterator<T>& operator++() {
			_node = _node->_next;
			return *this;
		}
		__list_iterator<T>& operator--() {
			_node = _node->_prev;
			return *this;
		}
		bool operator!=(const __list_iterator<T>& it) {
			return _node != it._node;
		}
		bool operator==(const __list_iterator<T>& it) {
			return _node == it._node;
		}
	};

	template<class T>
	class list {
	public:
		typedef __list_iterator<T> iterator;
		list() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& data) {
			Node* tail = _head->_prev;
			Node* newNode = new Node(data);
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
		}
		iterator begin() {
			iterator it(_head->_next);
			return it;
		}
		iterator end() {
			iterator it(_head);
			return it;
		}

	private:
		typedef list_node<T> Node;
		Node* _head;

	};
}