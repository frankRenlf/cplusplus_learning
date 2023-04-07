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
	class list {
		typedef list_node<T> Node;
	public:
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
	private:
		Node* _head;
	};
}