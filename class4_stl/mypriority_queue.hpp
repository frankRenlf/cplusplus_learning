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
			_c.pop_back();
			AdjustDown(0);
		}
		const T& top() {
			return _c[0];
		}
		size_t size() {
			return _c.size();
		}
		bool empty() {
			return _c.empty();
		}
	private:
		void AdjustUp(int child) {
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (_c[parent] < _c[child]) {
					swap(_c[parent], _c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}
		void AdjustDown(int parent) {
			int child = parent * 2 + 1;
			while (child < _c.size()) {
				if (child + 1 < _c.size()
					&& _c[child] < _c[child + 1]) {
					child++;
				}
				if (_c[parent] < _c[child]) {
					swap(_c[parent], _c[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		Container _c;
	};
}