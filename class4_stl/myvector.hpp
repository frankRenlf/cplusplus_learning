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
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef reverse_iterator<iterator, T&, T*> riterator;
		typedef reverse_iterator<const_iterator, const T&, const T*> const_riterator;
		riterator rbegin() {
			return riterator(end());
		}
		const_riterator rbegin() const {
			return const_riterator(cend());
		}
		riterator rend() {
			return riterator(begin());
		}
		const_riterator rend() const {
			return const_riterator(cbegin());
		}
		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(size_t n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}

		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 5);
		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
		* 最终选择的是：vector(InputIterator first, InputIterator last)
		* 因为编译器觉得区间构造两个参数类型一致，因此编译器就会将InputIterator实例化为int
		* 但是10和5根本不是一个区间，编译时就报错了
		* 故需要增加该构造方法
		*/
		vector(int n, const T& value = T())
			: _start(new T[n])
			, _finish(_start + n)
			, _endofstorage(_finish)
		{
			for (int i = 0; i < n; ++i)
			{
				_start[i] = value;
			}
		}

		// 若使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
		// 重新声明迭代器，迭代器区间[first,last)可以是任意容器的迭代器
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.cbegin(), v.cend());
			this->swap(tmp);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		size_t size() const {
			return _finish - _start;
		}


		size_t capacity() const {
			return _endofstorage - _start;
		}
		bool empty() const
		{
			return _start == _finish;
		}

		void reserve(size_t newCapacity) {
			size_t oldSize = size();
			if (newCapacity > capacity()) {
				T* tmp = new T[newCapacity];
				if (_start) {
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];					
					delete[] _start;
				}
				_start = tmp;
			}
			_finish = _start + oldSize;
			_endofstorage = _start + newCapacity;
		}

		void resize(size_t n, const T& val = T()) {
			if (n > capacity()) {
				reserve(n);
			}
			if (n > size()) {
				while (_finish < _start + n) {
					*_finish = val;
					_finish++;
				}
			}
			else {
				_finish = _start + n;
			}
		}

		void push_back(const T& x) {
			check_expand();
			*_finish = x;
			_finish++;
		}
		void pop_back() {
			if (_finish == _start) {
				return;
			}
			_finish--;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		void clear() {
			_finish = _start;
		}
		///////////////////////////////////////////////////////////
		// 元素访问
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}
		void check_expand() {
			if (_finish == _endofstorage) {
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
		}
		iterator insert(iterator pos, const T& val) {
			assert(pos >= _start && pos <= _finish);
			size_t index = pos - _start;
			check_expand();
			pos = _start + index;
			iterator end = _finish;

			while (end > pos) {
				*end = *(end - 1);
				end--;
			}
			*pos = val;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos) {
			assert(pos >= _start && pos <= _finish);
			iterator loc = pos;
			while (loc < _finish) {
				*(loc) = *(loc + 1);
				loc++;
			}
			_finish--;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}