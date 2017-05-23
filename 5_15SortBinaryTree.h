#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;


template <class K, class V>
struct BSTNode
{
	BSTNode(const K& key, const V& value)
	: _pLeft(NULL)
	, _pRight(NULL)
	, _key(key)
	, _value(value)
	{}

	BSTNode<K, V>* _pLeft;
	BSTNode<K, V>* _pRight;
	K _key;
	V _value;
};

template <class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:

	BSTree()
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
	}

	bool Remove(const K& key)
	{
		if (NULL == _pRoot)
			return false;

		if (NULL == _pRoot->_pLeft&& NULL == _pRoot->_pRight)
		{
			delete _pRoot;
			_pRoot = NULL;
			return true;
		}
		//开始找删除的位置
		Node *pCur = _pRoot;
		Node *pParent = NULL;
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
				break;
		}
		//出了循环，位置肯定找到了
		if (pCur == NULL)
		{
			return false;
		}

		if (NULL == pCur->_pLeft)
		{
			if (pCur->_key == key)//判断是否为根节点
			{
				_pRoot = pCur->_pRight;
				delete pCur;
				pCur = NULL;
				return true;
			}
			else if (pParent->_pLeft == pCur)//判断是否为双亲的左结点
			{
				pParent->_pLeft = pCur->_pRight;
			}
			else//双亲的右结点
			{
				pParent->_pRight = pCur->_pRight;
			}
		}

		else if (NULL == pCur->_pRight)
		{
			if (pCur->_key == key)
			{
				_pRoot = pCur->_pLeft;
				delete pCur;
				pCur = NULL;
				return true;
			}
			else if (pParent->_pRight = pCur)
			{
				pParent->_pRight = pCur->_pLeft;
			}
			else
			{
				pParent->_pLeft = pCur->_pLeft;
			}
		}
		else//到了这里，说明待删除的结点左右孩子都有
		{
			Node* sub = pCur;
			Node* First = pCur->_pRight;
			if (First->_pLeft)
			{
				sub = First;
				First = First->_pLeft;
			}
			swap(pCur->_key, First->_key);
			swap(pCur->_value, First->_value);
			pCur = First;
			if (pCur->_pLeft == NULL)
			{
				if (sub->_pLeft == pCur)
				{
					sub->_pLeft = pCur->_pRight;
				}
				else
				{
					sub->_pRight = pCur->_pRight;
				}
			}
			else if (pCur->_pRight == NULL)
			{
				if (sub->_pLeft == pCur)
				{
					sub->_pLeft = pCur->_pLeft;
				}
				else
				{
					sub->_pLeft = pCur->_pLeft;
				}
			}
		}
		delete pCur;
		pCur = NULL;
		return true;
	}



	Node* Find(const K& key)
	{
		if (NULL == _pRoot)
			return NULL;

		Node *pCur = _pRoot;
		while (pCur)
		{
			if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else if (key>pCur->_key)
				pCur = pCur->_pRight;
			else
				break;
		}
		return pCur;
	}

	bool Insert_R(const K& key, const V& value)
	{
		return _Insert_R(_pRoot, key, value);
	}

	bool Remove_R(const K& key)
	{
		return _Remove_R(_pRoot, key);
	}

	void MidOrder()
	{
		_MidOrder(_pRoot);
		cout << endl;
	}



protected:
	bool _Insert_R(Node*& pRoot, const K& key, const V& value)
	{
		if (NULL == pRoot)
		{
			pRoot = new Node(key, value);
			return true;
		}
		if (key < pRoot->_key)
			return _Insert_R(pRoot->_pLeft, key, value);
		else if (key>pRoot->_key)
			return _Insert_R(pRoot->_pRight, key, value);
		else
			return false;
	}

	bool _Remove_R(Node *&pRoot, const K&key)
	{
		if (NULL == pRoot)
			return false;
		if (key > pRoot->_pLeft)
			return _Remove_R(pRoot->_pRight, key);
		else if (key < pRoot->_key)
			return _Remove_R(pRoot->_pLeft, key);
		else
		{
			Node *pCur = pRoot;
			if (pRoot->_pLeft == NULL)
				pRoot = pRoot->_pLeft;
			else if (pRoot->_pRight == NULL)
				pRoot = pRoot->_pLeft;
			else
			{
				Node *First = pRoot->_pRight;
				while (First->_pLeft)
				{
					First = First->_pLeft;
				}
				swap(pCur->_key, First->_key);
				swap(pCur->_value, First->_value);
				return _Remove_R(pRoot->_pRight, key);
			}
			delete pCur;
			pCur = NULL;
			return true;
		}
	}


	void _MidOrder(Node* _pRoot)
	{
		if (NULL == _pRoot)
			return;
		_MidOrder(_pRoot->_pLeft);
		cout << _pRoot->_key << " ";
		_MidOrder(_pRoot->_pRight);
	}



protected:
	BSTNode<K, V>* _pRoot;

};