#pragma once 
#include<iostream>
using namespace std;

template <class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key, const V& value)
	:_key(key)
	, _value(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	, _pParent(NULL)
	{};
	AVLTreeNode<K,V> *_pLeft;
	AVLTreeNode<K,V> *_pRight;
	AVLTreeNode<K,V> *_pParent;
	K _key;
	V _value;
	int _bf;
};


template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_pRoot(NULL)
	{}


	bool Insert(const K& key, const V& value)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent = NULL;

		while (pCur)
		{
			if (key < pCur->_key)
			{
				pParent = pCur;//更新双亲
				pCur = pCur->_pLeft;
			}
			else if (key>pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
			{
				return false;
			}
		}

		//找到了插入的位置，然后创建待插入的结点
		pCur = new Node(key, value);
		if (key < pParent->_key)
		{
			pParent->_pLeft = pCur;
		}

		else if (key>pParent->_key)
		{
			pParent->_pRight = pCur;
		}
		return true;

		while (pParent)
		{
			if (pParent->_pLeft == pCur)
				pParent->_bf--;
			else
				pParent->_bf++;
			if (0 == pParent->_bf)
				return true;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else// 进行旋转
			{
				if (2 == pParent->_bf)
				{
					if (1 == pCur->_bf)
						_RotateLeft(pParent);
					else
						_RotateRL(pParent);
				}
				else
				{
					if (-1 == pCur->_bf)
						_RotateRight(pParent);
					else
						_RotateLR(pParent);
				}
			}
		}
	}


	void _RotateLeft(Node* pParent)
	{
		Node *pSubR = pParent->_pRight;
		Node *pSubRL = pParent->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
			pSubR->_pLeft = pParent;
			Node *pPParent = pParent->_pParent;

			pParent->_pParent = pSubR;
			pSubR->_pParent = pPParent;
			if (NULL == pParent->_pParent)
				_pRoot = pSubR;
			else
			{
				if (pPParent->_pLeft == pParent)
					pPParent->_pLeft = pSubR;
				else
					pPParent->_pRight = pSubR;
			}
		}
		pParent->_bf = pSubR->_bf = 0;

	};

	void _RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
			pSubL->_pRight = pParent;
			
			Node* pPParent = pParent->_pParent;
			pParent->_pParent = pSubL;
			pSubLR->_pParent = pPParent;
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
		pParent->_bf = pSubL->_bf = 0;
	}

	void _RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubL->_bf;
		
		_RotateLeft(pParent->_pLeft);
		_RotateRight(pParent);

		if (-1 == bf)
			pParent->_bf = 1;
		else
			pSubL->_bf = -1;

	}

	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		_RotateRight( pParent->_pRight);
		_RotateLeft( pParent);

		if (1 == bf)
			pParent->_bf = -1;
		else
			pSubR->_bf = 1;

	}

	size_t Height(Node* pRoot)
	{
		if (NULL == pRoot)
			return 0;
		if (NULL == pRoot->_pLeft&&NULL == pRoot->_pRight)
			return 1;
		size_t LeftHeight = Height(pRoot->_pLeft);
		size_t RightHeight = Height(pRoot->_pRight);
		return LeftHeight > RightHeight ? LeftHeight + 1, RightHeight + 1;
	}

	bool IsbalanceTree(Node* pRoot)
	{
		if (NULL == pRoot)
			return true;
		int LeftHeight = Height(pRoot->_pLeft);
		int RightHeight = Height(pRoot->_pRight);
		if (pRoot->_bf != LeftHeight - RightHeight | abs(pRoot->_bf) > 1)
			return false;
		return IsbalanceTree
	}
	void MidOrder()
	{
		cout << "MidOrder:" << " ";
		_MidOrder(_pRoot);
		cout << endl;
	}

	protected:
		void _MidOrder(Node* pRoot)
		{
			if (NULL == pRoot)
				return;
			_MidOrder(pRoot->_pLeft);
			cout << pRoot->_key << " ";
			_MidOrder(pRoot->_pRight);
		}
protected:
	Node* _pRoot;
};