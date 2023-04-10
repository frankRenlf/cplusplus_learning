#pragma once
#include<iostream>
#include <cassert>
#include "myreverseiterator.hpp"
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

		typedef reverse_iterator<iterator, T&, T*> riterator;
		typedef reverse_iterator<const_iterator, const T&, const T*> const_riterator;
		riterator rbegin() {
			return riterator(end());
		}
		const_riterator rbegin() const {
			return const_riterator(end());
		}
		riterator rend() {
			return riterator(begin());
		}
		const_riterator rend() const {
			return const_riterator(begin());
		}

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
			empty_init();
		}
		list(const list<T>& lt) {
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>& operator=(list<T> lt) {
			return *this;
		}
		template<class InputIterator>
		list(InputIterator first, InputIterator last) {
			empty_init();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}
		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
		}
		void empty_init() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}
		void push_back(const T& data) {
			insert(end(), data);
		}
		void push_front(const T& data) {
			insert(begin(), data);
		}
		void pop_back() {
			erase(--end());
		}
		void pop_front() {
			erase(begin());
		}
		iterator insert(iterator pos, const T& data) {
			Node* newNode = new Node(data);
			Node* cur = pos._node;
			cur->_prev->_next = newNode;
			newNode->_prev = cur->_prev;
			newNode->_next = cur;
			cur->_prev = newNode;
			return iterator(newNode);
		}
		iterator erase(iterator pos) {
			assert(pos != end());
			Node* cur = pos._node;
			Node* next = cur->_next;
			cur->_prev->_next = next;
			next->_prev = cur->_prev;
			delete cur;
			return iterator(next);
		}

	private:
		Node* _head;
	};
}