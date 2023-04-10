#include"head.h"

namespace frank {

	template<class Iterator, class Ref, class Ptr>
	class reverse_iterator {
	public:
		Iterator _it;
		typedef reverse_iterator<Iterator, Ref, Ptr> Self;

		reverse_iterator(Iterator it)
			:_it(it)
		{}
		Ref operator*() {
			iterator tmp = it;
			return *(--tmp);
		}
		Ptr operator->() {
			return &(operator*());
		}
		Self& operator++(const) {
			--_it;
			return *this;
		}
		Self& operator--(const) {
			++_it;
			return *this;
		}
		bool operator!=(const Self& s) {
			return _it != s._it;
		}
	};
}