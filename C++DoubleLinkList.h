#include<iostream>
#include<assert.h>

using namespace std;
typedef int DataType;

struct Node
{
	Node(const DataType data)
	:_data(data)
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
	List();
	List(size_t n, const DataType& data = DataType());
	List(const List& l);
	List& operator=(const List& l);
	~List();
	void PushBack(const DataType& data);
	void PopBack();
	void PushFront(const DataType& data);
	void PopFront();
	void Insert(Node* pos, const DataType& data);
	void Erase(Node* pos);
	void Assign(size_t n, const DataType data = DataType());
	void Clear();
	void DestroyList();

	Node& Front();
	const Node& Front()const;
	Node& Back();
	const Node& Front()const;
	Node& operator[](size_t index);
	const Node& operator[](size_t index)const;
	size_t Size()const;
	bool Empty()const;


private:
	Node* _pHead;
	Node* _pTail;
	size_t size;
};

