#include<iostream>
using namespace std;
#pragma warning(disable:4996)

template<class T>
class Heap
{
public:
	Heap(size_t size)
	{
		currentSize = 0;
		capacity = size;
		heap = new T[capacity + 1];//heap[0]不使用
	}

	~Heap()
	{
		delete[] heap;
		heap = NULL;
	}

	bool IsEmpty()
	{
		return 0 == currentSize;
	}

	T Top()
	{
		return heap[1];
	}

	void Push(T data)
	{
		if (currentSize >= capacity)
			cout << "The Capacity Is Full!" << endl;
		else
		{
			currentSize++;
			int currentNode = currentSize;
			while (currentNode > 1 && heap[currentNode / 2] < data)
			{
				heap[currentNode] = heap[currentNode / 2];
				currentNode = currentNode / 2;
			}
			heap[currentNode] = data;

		}
	}

	void Heap<T>::Pop()
	{
		if (IsEmpty())
			cout << "The Heap Is Empty!" << endl;
		else
		{
			cout << currentSize << endl;
			T last = heap[currentSize];
			currentSize--;
			int currentNode = 1;
			int child = 2;
			while (child <= currentSize)
			{
				if (child < currentSize&&heap[child] < heap[child + 1])
					child++;
				if (last >= heap[child])
					break;
				else
				{
					heap[currentNode] = heap[child];
					currentNode = child;
					child = child * 2;
				}
			}
			heap[currentNode] = last;
		}
	}
private:
	T *heap;
	int currentSize;
	int capacity;
};

int main()
{
	Heap<int> H(100);
	H.Push(20);
	H.Push(30);
	H.Push(15);
	H.Push(40);
	H.Push(90);
	H.Push(100);
	cout << "堆顶元素为：" << H.Top() << endl;
	H.Pop();
	cout << "堆顶元素为：" << H.Top() << endl;
	/*H.Pop();
	cout << "堆顶元素为：" << H.Top() << endl;
	cout << "堆顶元素为：" << H.Top() << endl;*/
	return 0;
}

