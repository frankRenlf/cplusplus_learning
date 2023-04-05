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
	class vector {
	public:
		typedef T* iterator;
		typedef const T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		size_t size() const {
			return _finish - _start;
		}


		size_t capacity() const {
			return _endofstorage - _start;
		}

		void reserve(size_t newCapacity) {

		}

		void push_back(const T& x) {
			if (_finish == _endofstorage) {
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = x;
			_finish++;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}