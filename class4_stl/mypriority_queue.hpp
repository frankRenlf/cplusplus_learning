#include"head.h"

namespace frank {
	template<class T>
	struct less {
		bool operator()(const T& x, const T& y) {
			return x < y;
		}
	};
	template<class T>
	struct greator {
		bool operator()(const T& x, const T& y) {
			return x > y;
		}
	};
	template<class T, class Container = vector<T>, class Comparator = less<T>>
	class priority_queue {
	public:
		void push(const T& data) {
			_con.push_back(data);
			AdjustUp(_con.size() - 1);
		}
		void pop() {
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		const T& top() {
			return _con[0];
		}
		size_t size() {
			return _con.size();
		}
		bool empty() {
			return _con.empty();
		}
	private:
		void AdjustUp(int child) {
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (_cmp(_con[parent], _con[child])) {
					swap(_con[parent], _con[child]);
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
			while (child < _con.size()) {
				if (child + 1 < _con.size()
					&& _con[child] < _con[child + 1]) {
					child++;
				}
				if (_cmp(_con[parent], _con[child])) {
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		Container _con;
		Comparator _cmp;
	};
}