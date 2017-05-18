//#include"5_9heap.h"
//using namespace std;
//
//template <class T>
//class HuffmanNode{
//public:
//	HuffmanNode()
//	{
//		Weight(value)
//		Left(NULL)
//		Right(NULL)
//		Parent(NULL)
//	}
//
//	T Weight;              // Ȩֵ
//	T Left;  // ����
//	T Right; // �Һ���
//	T Parent;// �����
//};
//
//template <class T>
//class huffman 
//{
//public:
//	huffman(HuffmanNode* str)
//		:pRoot(NULL)
//	{}
//	~huffman()
//	{
//		if (pRoot)
//		{
//			delete[] pRoot;
//			pRoot = null;
//		}
//	}
//
//	void CreateHuffmanTree(T arr[], size_t size)
//	{
//		Heap<int> h(arr, size);
//
//		while (h.size() > 1)
//		{
//			Left = h[0];
//			h.Pop();
//			Right = h[0];
//			Parent = Left + Right;
//			h.Push(Parent);
//		}
//	}
//
//private:
//	HuffmanNode<T> *pRoot;  // �����
//};
//
//
//int main()
//{
//	int str[] = { 1, 3, 5, 7 };
//	huffman<int> h(str);
//	return 0;
//}
//
//

#ifndef __HUFFMANTREE__
#define __HUFFMANTREE__

#include "Heap.h"

//�շ������ڵ�
template<typename T>
struct HuffmanTreeNode
{
	HuffmanTreeNode(const T value)
	:_weight(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	, _pParent(NULL)
	{}

	T _weight;
	HuffmanTreeNode<T> *_pLeft;
	HuffmanTreeNode<T> *_pRight;
	HuffmanTreeNode<T> *_pParent;
};

//template<class T>
//struct CompareNode
//{
//	bool operator()(const T& left, const T& right)
//	{
//		return left->_weight < right->_weight;
//	}
//};

//�շ�����
template<typename T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	//���캯��
	HuffmanTree()
	{}
	HuffmanTree(const T array[], size_t size, const T invalid)
	{
		_CreatHuffmanTree(array, size, invalid);
	}

	//��������
	~HuffmanTree()
	{
		_DestroyHuffmanTree(_pRoot);
	}

	const Node* Root()const
	{
		return _pRoot;
	}

protected:
	//������
	void _CreatHuffmanTree(const T array[], size_t size, const T invalid)
	{
		struct CompareNode
		{
			bool operator()(const Node* left, const Node* right)
			{
				return left->_weight < right->_weight;
			}
		};


		Heap<Node*, CompareNode> hp;

		for (size_t index = 0; index < size; ++index)
		{
			if (invalid != array[index])
				hp.Insert(new Node(array[index]));
		}

		while (hp.Size() > 1)
		{
			Node* pLeft = hp.Top();
			hp.Remove();
			Node* pRight = hp.Top();
			hp.Remove();

			Node* pParent = new Node(pLeft->_weight + pRight->_weight);

			pLeft->_pParent = pParent;
			pRight->_pParent = pParent;
			pParent->_pLeft = pLeft;
			pParent->_pRight = pRight;

			hp.Insert(pParent);
		}

		_pRoot = hp.Top();
	}


	//�ݻ���
	void _DestroyHuffmanTree(Node* pRoot)
	{
		if (NULL == pRoot)
			return;

		if (pRoot->_pLeft)
			_DestroyHuffmanTree(pRoot->_pLeft);

		if (pRoot->_pRight)
			_DestroyHuffmanTree(pRoot->_pRight);

		delete pRoot;
		pRoot = NULL;
	}

private:
	Node *_pRoot;
};

#endif


