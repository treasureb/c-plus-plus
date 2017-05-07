#pragma once

#include<iostream>
using namespace std;


//孩子表示法
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& value)
	:_value(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	{};

	T _value;
	BinaryTreeNode<T>* _pLeft;
	BinaryTreeNode<T>* _pRight;
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_pRoot(NULL)
	{}

	BinaryTree(const T array[], size_t size,const T& invalid)
	{
		size_t index = 0;//
		_CreateBinaryTree(_pRoot, array, size, index, invalid);
	}
	//下面使用到了&index,但是不能对一个常量进行引用，所以要把index定义为一个变量
	//BinaryTree(const BinaryTree<T>& bt)
	//{
	//    _pRoot = CopyBinaryTree();
	//}

	BinaryTree<T>& operator=(const BinaryTree<T>& bt)
	{
		if (this != &bt)
		{
			_DestroyBinaryTree(_pRoot);
		//	_pRoot = CopyBinaryTree();
		}

		return *this;
	}
	~BinaryTree()
	{
		_DestroyBinaryTree(_pRoot);
	}
	void PreOrder()
	{	
		cout << "PreOrder:" << endl;
		_PreOrder(_pRoot);
		cout << endl;
	}

	//Node* CopyBinaryTree()
	//{
	//	_CopyBirnaryTree(_pRoot);
	//}
	Node* Find(const T& value)
	{
		return _Find()
	}

private:
	void _CreateBinaryTree(Node* &pRoot, const T array[],size_t size, size_t& index,const T& invalid)
	{
		if (index < size && invalid != array[index])//注意条件的判断次序
		{
			//创建根节点
			pRoot = new Node(array[index]);
			
			//创建左子数
			_CreateBinaryTree(pRoot->_pLeft, array, size, ++index,invalid);//如果用index+1，初始的index并没有发生变化
			
			//创建右子数
			_CreateBinaryTree(pRoot->_pRight, array, size, ++index, invalid);
	
		}
	}

	//Node* _CopyBirnaryTree(Node* pRoot)
	//{
	//	Node* pNewNode = NULL;
	//	//拷贝根节点
	//	if (pNewNode)
	//	{
	//		pNewNode = new Node(pRoot->_value);

	//		//拷贝左子树
	//		pNewNode->_pLeft = _CopyBirnaryTree(pRoot->_pLeft);

	//		//拷贝右子树 
	//		pNewNode->_pRight = _CopyBirnaryTree(pRoot->_pRight);
	//	}
	//}

	void _DestroyBinaryTree(Node* &pRoot)
	{
		if (pRoot)
		{
			_DestroyBinaryTree(pRoot->_pLeft);
			_DestroyBinaryTree(pRoot->_pRight);
			delete pRoot;
			pRoot = NULL;
		}
	}
	void _PreOrder(Node* pRoot)
	{
		if (pRoot)
		{
			cout << pRoot->_value << " " << endl;

			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}
	}

	void PostOrder(Node* pRoot)
	{
		if (pRoot)
		{
			cout << _pRoot->_value << " " << endl;

			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}
	}

	


private:
	Node* _pRoot;//根节点
};

int main()
{
	char* ptr = "124###35##6";
	BinaryTree<char> bt(ptr, strlen(ptr), '#');
	//BinaryTree<char> bt1(bt);

	bt.PreOrder();
	/*BinaryTree<char> bt2;
	bt2 = bt1;
	bt2.PreOrder();
*/
	return 0;
}