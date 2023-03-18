#include<iostream>
//#include<cstdio>

using namespace std;
typedef int datatype;
class stack
{
public:
	void init()
	{
		_array = (datatype*)malloc(sizeof(datatype) * 3);
		if (NULL == _array)
		{
			perror("malloc…Í«Îø’º‰ ß∞‹!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	}
	void push(datatype data)
	{
		checkcapacity();
		_array[_size] = data;
		_size++;
	}
	void pop()
	{
		if (empty())
			return;
		_size--;
	}
	datatype top() { return _array[_size - 1]; }
	int empty() { return 0 == _size; }
	int size() { return _size; }
	void destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	void checkcapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			datatype* temp = (datatype*)realloc(_array, newcapacity *
				sizeof(datatype));
			if (temp == NULL)
			{
				perror("realloc…Í«Îø’º‰ ß∞‹!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	datatype* _array;
	int _capacity;
	int _size;
};
int main()
{
	stack s;
	s.init();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	printf("%d\n", s.top());
	printf("%d\n", s.size());
	s.pop();
	s.pop();
	printf("%d\n", s.top());
	printf("%d\n", s.size());
	s.destroy();
	return 0;
}