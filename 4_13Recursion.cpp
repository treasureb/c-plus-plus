#include<iostream>
#include<stdio.h>
using namespace std;
#pragma warning(disable:4996)

typedef struct Node
{
	
	Node(int data)
		:_data(data)
		, Next(NULL)
	{};

	int _data;
	Node* Next;
}Node;


void PrintArray(int* arr, int k)
{
	if (k == 10)
		return;
		PrintArray(arr, k + 1);
		cout << arr[k] << " ";

}



int firstNsum(int n)
{
	if (n > 0)
		return firstNsum(n - 1) + n;
	return n;
}

int Factorial(int n)
{
	if (n == 0 | n == 1)
		return 1;
	else
		return Factorial(n - 1)*n;
}

int BinarySearch(int* arr, int left, int right, int k, int data)
{
	if (left < right)
	{
		int mid = (left + (right - left) >> 1);
		if (data == arr[mid])
			return mid;
		else if (arr[mid]>data)
			return BinarySearch(arr, left, mid - 1,mid, data);
		else if (arr[mid] < data)
			return BinarySearch(arr, mid + 1, right,right-mid-1,data);
	}
	else
	 return -1;
}

Node* ReverseFind(Node* pHead,int data)
{
	if (pHead)
	{
		Node* res = ReverseFind(pHead->Next,data);
		if (res)
		    return res;
		else
		{
			if (pHead->_data == data)
				return pHead;
		}
	}
	return NULL;
}


void PrintFormTailToHead(Node* pHead)
{
	if (pHead)
	{
		PrintFormTailToHead(pHead->Next);
		cout << pHead->_data << "->";
	}
	else
		return;
}

void ReverseDestory(Node*& pHead)
{
	if (pHead)
	{
		ReverseDestory(pHead->Next);
		delete pHead;
		pHead = NULL;
	}
	else
		return;
}

bool IsPalindereme(char* str, int k)
{
	if (k <= 1)//奇数个为1，偶数个为0
		return true;
	if (str[0] != str[k - 1])
		return false;

	return IsPalindereme(++str, k - 2);
}


int Feb(int first, int second, int n)
{
	if (n < 3)
		return 1;
	if (n == 3)
		return first + second;
	return Feb(second, first + second, n - 1);
}

void Test1()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	node1->Next = node2;
	node2->Next = node3;
	node3->Next = node4;
	node4->Next = node5;
	node5->Next = NULL;

	ReverseDestory(node1);
}


void Test()
{
	Node  node1(1); 
	Node  node2(2); 
	Node  node3(3);
	Node  node4(4);
	node1.Next = &node2;
	node2.Next = &node3;
	node3.Next = &node4;
	node4.Next = NULL;

	ReverseFind(&node1,3);
}

void perm(char* str, int k, int n)
{
	int i = 0;
	if (k > n)
	{
		for (; i <= n; i++)
			cout << str[i] <<" ";
		cout << endl;
	}
	else
	{
		for (i = k; i <= n; i++)
		{
			swap(k, i);
			perm(str,k + 1, n);
			swap(k, i);
		}
	}

}

int main()
{
	Test();
	int ret = 0;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	ret = Factorial(5);
	ret = BinarySearch(arr,0,8,9,2);
	cout << ret << endl;
	PrintArray(arr,0);
	cout << endl;
	Test1();
	/*char* str = "123321";
	ret = IsPalindereme(str,6);
	cout << ret << endl;*/
	char *str = "123";
	perm(str, 0, 3);
	return 0;
}



