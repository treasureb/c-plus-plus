#ifndef __HEAP__
#define __HEAP__
#include<iostream>
#include <vector>
using namespace std;

template<typename T>
struct Less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<typename T>
struct Great
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<typename T, template<class> class Compare = Less>
class Heap
{
public:
	//构造函数
	Heap()//默认构造函数
	{}
	Heap(const T array[], size_t size)
	{
		_heap.resize(size);

		for (int index = 0; index < size; ++index)
			_heap[index] = array[index];

		for (int root = (_heap.size() - 2) >> 1; root >= 0; --root)//因为下标从0开始，所以_heap.size()-2
		{
			_AdjustDown(root);
		}
	}

	//插入
	void Push(const T& value)
	{
		_heap.push_back(value);//先把元素插进去，然后进行调整
		if (_heap.size() > 1)
			_AdjustUp();
	}

	//删除
	void Pop()
	{
		if (0 == _heap.size())
			return;
		_heap[0] = _heap[_heap.size() - 1];
		_heap.pop_back();
		if (_heap.size()>1)
			_AdjustDown(0);
	}

	//求大小
	size_t Size()const
	{
		return _heap.size();
	}

	//判空
	bool Empty()const
	{
		return _heap.empty();
	}

	//求堆顶
	const T& Top()const
	{
		return _heap.front();
	}

	void PrintHeap()
	{
		cout << "Heap:" << endl;
		for (int i = 0; i <= _heap.size() - 1; i++)
		{
			cout <<_heap[i] << " ";
		}
		cout << endl;
	}

private:
	//向下调整
	void _AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		size_t size = _heap.size();

		while (child < size)
		{
			if ((child + 1)<size && Compare<T>()(_heap[child + 1], _heap[child]))
				child += 1;

			if (Compare<T>()(_heap[child], _heap[parent]))
			{
			std:; swap(_heap[parent], _heap[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}

	//向上调整
	void _AdjustUp()
	{
		size_t child = _heap.size() - 1;
		size_t parent = child -1 >> 1;

		while (0 != child)
		{
			if (Compare<T>()(_heap[child], _heap[parent]))
			{
				std::swap(_heap[child], _heap[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
				return;
		}
	}

private:
	std::vector<T> _heap;
};

#endif