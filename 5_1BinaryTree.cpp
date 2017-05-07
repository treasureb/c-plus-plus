#pragma once

#include<iostream>
using namespace std;


//���ӱ�ʾ��
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
	//����ʹ�õ���&index,���ǲ��ܶ�һ�������������ã�����Ҫ��index����Ϊһ������
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
		if (index < size && invalid != array[index])//ע���������жϴ���
		{
			//�������ڵ�
			pRoot = new Node(array[index]);
			
			//����������
			_CreateBinaryTree(pRoot->_pLeft, array, size, ++index,invalid);//�����index+1����ʼ��index��û�з����仯
			
			//����������
			_CreateBinaryTree(pRoot->_pRight, array, size, ++index, invalid);
	
		}
	}

	//Node* _CopyBirnaryTree(Node* pRoot)
	//{
	//	Node* pNewNode = NULL;
	//	//�������ڵ�
	//	if (pNewNode)
	//	{
	//		pNewNode = new Node(pRoot->_value);

	//		//����������
	//		pNewNode->_pLeft = _CopyBirnaryTree(pRoot->_pLeft);

	//		//���������� 
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
	Node* _pRoot;//���ڵ�
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