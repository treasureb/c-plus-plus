
#include<iostream>
#include<assert.h>
using namespace std;


#pragma once

typedef int DataType;

struct Node
{
	Node(const DataType& data)
	: _data(data)
	, _pNext(NULL)
	, _pPre(NULL)
	{}

	DataType _data;
	Node* _pNext;
	Node* _pPre;
};

class List
{
public:
	List()
		: _pHead(NULL)
		, _pTail(NULL)
		, _size(0)
	{}

	List(size_t n, const DataType& data = DataType())
	{}

	List(const List& l)
	{
		// _CopyList(l._pHead);
	}

	List& operator=(const List& l)
	{
		if (this != &l)//·ÀÖ¹×Ô¸³Öµ
		{
			DestroyList();
			//CopyList(l._pHead);
		}

		return *this;
	}

	~List()
	{
		DestroyList();
	}

	//////////////////////////////////////////////////
	void PushBack(const DataType& data)
	{
		Node* pNode = new Node(data);
		if (NULL == _pHead)
		{
			_pHead = _pTail = pNode;
		}
		else
		{
			/*
			Node* pTailNode = _pHead;
			while(pTailNode->_pNext)
			{
			pTailNode = pTailNode->_pNext;
			}

			pTailNode->_pNext = pNode;
			*/

			_pTail->_pNext = pNode;
			pNode->_pPre = _pTail;
			_pTail = _pTail->_pNext;
		}

		++_size;
	}

	void PopBack()
	{
		if (NULL == _pHead)
		{
			return;
		}
		else if (_pHead == _pTail)
		{
			delete _pHead;
			_pHead = _pTail = NULL;
		}
		else
		{
			_pTail = _pTail->_pPre;
			delete _pTail->_pNext;
			_pTail->_pNext = NULL;
		}

		--_size;
	}

	void PushFront(const DataType& data)
	{
		Node* pNode = new Node(data);
		if (NULL == _pHead)
		{
			_pHead = _pTail = pNode;
		}
		else
		{
			pNode->_pNext = _pHead;
			_pHead->_pPre = pNode;
			_pHead = pNode;
		}

		++_size;
	}

	void PopFront()
	{
		if (_pHead == NULL)
		{
			cout << "List Is Empty!\n" << endl;
			return;
		}
		else if (_pHead == _pTail)
		{
			delete _pHead;
			_pHead = _pTail = NULL;
		}
		else
		{
			Node* del = _pHead;
			_pHead = _pHead->_pNext;
			_pHead->_pPre = NULL;
			_pTail->_pNext = _pHead;
			del->_pNext = NULL;
			delete del;
		}
	}

	void Insert(Node* pos, const DataType& data)
	{
		if (NULL == pos || NULL == _pHead)
			return;

		if (pos == _pTail)
		{
			PushBack(data);
		}
		else
		{
			Node* pNode = new Node(data);
			pNode->_pNext = pos->_pNext;
			pos->_pNext->_pPre = pNode;
			pos->_pNext = pNode;
			pNode->_pPre = pos;
			++_size;
		}
	}

	Node& Back()
	{
		return *_pTail;
	}
	void Erase(Node* pos)
	{
		if (NULL == pos || pos == _pHead)
		{
			delete _pHead;
		}
		Node * del = pos;
		Node * pre = pos->_pPre;
		pos->_pNext = pos;
		pos->_pPre = pre->_pNext;
		delete del;
		delete pre;

	}

	void Assign(size_t n, const DataType data = DataType());
	void Clear()
	{
		DestroyList();
		_size = 0;
	}

	////////////Acess////////////////////
	Node& Front()
	{
		return *_pHead;
	}

	const Node& Front()const
	{
		return *_pHead;
	}


	const Node& Back()const
	{
		return *_pTail;
	}

	Node& operator[](size_t index)
	{
		if (0 == _size)
		{
			cout << "Error Index!\n"<<endl;
		}
		return _pHead[index];
	}
	const Node& operator[](size_t index)const
	{
		if (0 == _size)
		{
			cout << "Error Index!\n" << endl;
		}
		return _pHead[index];
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}
	void DestroyList()
	{
		while (_pHead)
		{
			PopFront();
		}
	}

private:
	Node* _pHead;
	Node* _pTail;
	size_t _size;
};

void test()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.DestroyList();
	l.Back();
}
int main()
{
	test();
	return 0;
}