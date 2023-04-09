#include"head.h"

namespace frank {
	template<class T, class Container = vector<T>>
	class priority_queue {
	public:
		void push(const T& data) {
			_c.push_back(data);
			AdjustUp(_c.size() - 1);
		}
		void pop() {
			assert(!_c.empty());
			swap(_c[0], _c[_c.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
	private:
		void AdjustUp(int child) {
		}
		void AdjustDown(int child) {
		}
		Container _c;
	};
}