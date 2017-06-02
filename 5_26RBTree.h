#pragma once
#include<iostream>
using namespace std;

enum COLOR{RED,BLACK};

template <class K,class V>
struct RBTreeNode
{
	RBTreeNode(const K& key, const V& value)
	: _pLeft(NULL)
	, _pRight(NULL)
	, _pParent(NULL)
	, _key(key)
	, _value(value)
	, _color(RED)
	{}

	RBTreeNode* _pLeft;
	RBTreeNode* _pRight;
	RBTreeNode* _pParent;
	K _key;
	V _value;
	COLOR _color;
}; 

template <class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_pRoot(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value);
			_pRoot->_color = BLACK;
			return true;
		}

		Node* pCur = _pRoot;
		Node* pParent = NULL;
		while (pCur)
		{
			if (key < pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (key>pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
				return false;
		}
		//找到插入的位置
		pCur = new Node(key, value);
		if (key < pParent->_key)
		{
			pParent->_pLeft = pCur;
		}
		if (key>pParent->_key)
		{
			pParent->_pRight = pCur;
		}

		pCur->_pParent = pParent;
		
		while (pParent->_color == RED && _pRoot != pCur)
		{
			Node* pGrandFather = pParent->_pParent;
			if (pGrandFather->_pLeft == pParent)
			{
				Node* pUncle = pGrandFather->_pRight;
				if (pUncle&&RED == pUncle->_color)//情况三
				{
					pParent->_color = BLACK;
					pUncle->_color = BLACK;
					pGrandFather->_color = RED;

					pCur = pGrandFather;
					pParent = pParent->_pParent;
				}

				else//情况五
				{
					if (pCur == pParent->_pRight)
					{
						_RotateL(pParent);
						std::swap(pCur, pParent);
					}
					pGrandFather->_color = RED;
					pParent->_color = BLACK;
					_RotateR(pGrandFather);
				}

			}

			else
			{
				Node* pUncle = pGrandFather->_pLeft;
				if (pUncle && RED == pUncle->_color)//情况三
				{
					pParent->_color = BLACK;
					pUncle->_color = BLACK;
					pGrandFather->_color = RED;

					pCur = pGrandFather;
					pParent = pParent->_pParent;
				}

				else//情况五
				{
					if (pCur == pParent->_pLeft)
					{
						_RotateR(pParent);
						std::swap(pCur, pParent);
					}
					pGrandFather->_color = RED;
					pParent->_color = BLACK;
					_RotateL(pGrandFather);
				}

			}
		}
		_pRoot->_color = BLACK;
		return true;
	}

	void _RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}
		else
		{
			pSubR->_pLeft = pParent;
			Node* pPParent = pParent->_pParent;

			pParent->_pParent = pSubR;
			pSubR->_pParent = pPParent;
			if (NULL == pPParent)
				_pRoot = pSubR;
			else
			{
				if (pPParent->_pLeft = pParent)
					pPParent->_pLeft = pSubR;
				else
					pPParent->_pRight = pSubR;
			}
		}
	}

	void _RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		else
		{
			pSubL->_pRight = pParent;
			Node* pPParent = pParent->_pParent;
			pParent->_pParent = pSubL;
			pSubL->_pParent = pPParent;
			if (NULL == pParent->_pParent)
			{
				_pRoot = pSubL;
			}
			else
			{
				if (pPParent->_pLeft == pParent)
					pPParent->_pLeft = pSubL;
				else
					pPParent->_pRight = pSubL;
			}
		}
	}
	bool CheckRBTree()
	{
		size_t k = 0;
		if (NULL == _pRoot)
			return true;
	    if (_pRoot->_color == RED)
		{
			cout << "根节点为红" << " ";
			return false;
		}

		size_t BlackCount = 0;
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
			{
				BlackCount++;
			}
			pCur = pCur->_pLeft;
		}
		return _CheckRBTree(_pRoot, BlackCount, k);
	}

	bool _CheckRBTree(Node* pRoot, const size_t BlackCount, size_t k)
	{
		if (NULL == pRoot)
			return true;
		if (BLACK == pRoot->_color)
			k++;
		Node* pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "相邻为红" << " ";
			return false;
		}

		if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		{
			if (k != BlackCount)
			{
				cout << "黑色个数不相等" << " ";
				return false;
			}
		}

		return _CheckRBTree(pRoot->_pLeft, BlackCount, k) && _CheckRBTree(pRoot->_pRight,BlackCount,k);
	}
		
protected:
	Node* _pRoot;

};	