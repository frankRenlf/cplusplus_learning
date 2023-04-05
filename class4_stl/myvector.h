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
		typedef const T* const_iterator;

		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}
		const_iterator begin()const {
			return _start;
		}

		const_iterator end()const {
			return _finish;
		}

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
			size_t oldSize = size();
			if (newCapacity > capacity()) {
				T* tmp = new T[newCapacity];
				if (_start) {
					memcpy(tmp, _start, size() * sizeof(T));
					delete[] _start;
				}
				_start = tmp;
			}
			_finish = _start + oldSize;
			_endofstorage = _start + newCapacity;
		}

		void push_back(const T& x) {
			if (_finish == _endofstorage) {
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back() {
			if (_finish == _start) {
				return;
			}
			_finish--;
		}
		T& operator[](size_t index) {
			assert(index < size());
			return _start[index];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}