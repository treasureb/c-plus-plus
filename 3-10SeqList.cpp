#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#pragma warning(disable:4996)
typedef int DataType;
#define MaxSize 
#define EXPLAND_CAPACITY 10//初始容量

//静态顺序表的相关实现
//typedef struct SeqList
//{
//	DataType array[MaxSize];
//	int size;
//}SeqList;
//
//void InitSeqList(SeqList* pSeq)
//{
//	assert(pSeq);
//	memset(pSeq->array, 0, MaxSize*sizeof(DataType));
//	pSeq->size = 0;
//}
//void PrintSeqList(SeqList* pSeq)
//{
//	assert(pSeq);
//	for (int i = 0; i < pSeq->size; i++)
//	{
//		printf("%d\n", pSeq->array[i]);
//	}
//	printf("\n");
//}
//void PushBack(SeqList* pSeq, DataType data)
//{
//	assert(pSeq);
//	if (pSeq->size == MaxSize)
//	{
//		printf("Capacity Is Full!\n");
//		return;
//	}
//	pSeq->array[pSeq->size++] = data;
//
//}
//void PopBack(SeqList* pSeq)
//{
//	assert(pSeq);
//	if (0 == pSeq->size)
//	{
//		printf("Capacity Is Empty!\n");
//		return;
//	}
//	pSeq->size--;
//}
//void PushFront(SeqList* pSeq, DataType data)
//{
//	assert(pSeq);
//	if (pSeq->size == MaxSize)
//	{
//		printf("Capacity Is Full!\n");
//		return;
//	}
//	int i = pSeq->size - 1;//定位到顺序表的最后一个元素
//	for (; i >= 0; i--)
//	{
//		pSeq->array[i + 1] = pSeq->array[i];
//	}
//	pSeq->array[0] = data;
//	pSeq->size++;
//}
//void PopFront(SeqList* pSeq)
//{
//	assert(pSeq);
//	if (pSeq->size == 0)
//	{
//		printf("Capacity Is Empty!\n");
//		return;
//	}
//	int i = 0;//定位到顺序表的第一个位置
//	for (; i < pSeq->size - 1; i++)
//	{
//		pSeq->array[i] = pSeq->array[i + 1];
//	}
//	pSeq->size--;
//
//}
//void Insert(SeqList* pSeq, size_t pos, DataType data)
//{
//	assert(pSeq);
//	if (pSeq->size == MaxSize)
//	{
//		printf("Capacity Is Full!\n");
//		return;
//	}
//	int i = pSeq->size - 1;
//	for (; i >= pos; i--)
//	{
//		pSeq->array[i + 1] = pSeq->array[i];
//	}
//	pSeq->array[pos-1] = data;//因为是数组，所以插入pos-1的位置
//	pSeq->size++;
//}
//void Erase(SeqList* pSeq, size_t pos)
//{
//	if (pSeq->size == 0)
//	{
//		printf("Capacity Is Empty!\n");
//		return;
//	}
//
//	int i = pos- 1;
//	for (; i <pSeq->size-1;i++)
//	{
//		pSeq->array[i] = pSeq->array[i + 1];
//	}
//	pSeq->size--;
//}
//int Find(SeqList* pSeq, DataType data)
//{
//	for (int i = 0; i < pSeq->size - 1; i++)
//	{
//		if (pSeq->array[i] == data)
//		{
//			return i;
//		}
//	}
//}
//void Remove(SeqList* pSeq, DataType data)
//{
//	assert(pSeq);
//	if (0 == pSeq)
//	{
//		printf("Capacity Is Empty!\n");
//		return;
//	}
//
//	for (int i = 0; i < pSeq->size - 1; i++)
//	{
//		if (data == pSeq->array[i])
//		{
//			Erase(pSeq, i+1);
//			return;
//		}
//
//	}
//}
//void RemoveAll(SeqList* pSeq, DataType data)
//{
//	assert(pSeq);
//	if (0 == pSeq)
//	{
//		printf("Capacity Is Empty!\n");
//		return;
//	}
//
//	for (int i = 0; i < pSeq->size - 1; i++)
//	{
//		if (data == pSeq->array[i])
//		{
//			Erase(pSeq, i + 1);
//		}
//	}
//	return;
//}
//void BubbleSort(SeqList* pSeq)
//{
//	if (0 == pSeq)
//	{
//		printf("Capacity Is Empty!\n");
//			return;
//	}
//	int i, j;
//	int flag = 0;
//	for (i = 0; i < pSeq->size - 1; i++)
//	{
//		for (j = 0; j < pSeq->size - 1- i; j++)
//		{
//			if (pSeq->array[j] > pSeq->array[j + 1])
//			{
//				int temp = pSeq->array[j];
//				pSeq->array[j] = pSeq->array[j + 1];
//				pSeq->array[j + 1] = temp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			break;
//	}
//}
//void SelectSort(SeqList* pSeq)
//{
//	assert(pSeq);
//	int i, j, k;
//	for (i = 0; i < pSeq->size - 1; i++)
//	{
//		k = i;
//		for (j = i + 1; j < pSeq->size; j++)
//		{
//			if (pSeq->array[k]>pSeq->array[j])
//			{
//				k = j;
//			}
//		}
//		if (k != i)//判断第i小的数是不是在第i个位置上
//		{
//			int temp = pSeq->array[k];
//			pSeq->array[k] = pSeq->array[i];
//			pSeq->array[i] = temp;
//		}
//	}
//}
//int BinarySearch(SeqList* pSeq, DataType data)
//{
//	assert(pSeq);
//	int left = 0;
//	int right = pSeq->size - 1;
//	int mid = left + (right - left) / 2;//防止相加溢出
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (pSeq->array[mid] == data)
//		{
//			return mid + 1;//mid为数组的位置，+1是返回我们所希望的位置
//		}
//		else if (pSeq->array[mid] > data)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	return -1;
//}

//动态顺序表的实现

typedef struct SeqList
{
	DataType* elem;//指向当前空间
	int size;//当前有效的数据长度
	int capacity;//当前容量
}SeqList;

void InitSeqList(SeqList* pSeq)
{
	pSeq->elem = (DataType*)malloc(sizeof(DataType));
	pSeq->capacity = EXPLAND_CAPACITY;
	pSeq->size = 0;
}

void PrintSeqList(SeqList* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d\n", pSeq->elem[i]);
	}
	printf("\n");
}

void Expland_Capacity(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size == pSeq->capacity)
	{
		pSeq->size = pSeq->capacity * 2;
		DataType* newelem = (DataType*)malloc(pSeq->capacity * 2);
		memcpy(newelem, pSeq->elem, pSeq->size*sizeof(DataType));
		free(pSeq->elem);
		pSeq->elem = newelem;
	}
}

void PushBack(SeqList* pSeq,DataType data)
{
	assert(pSeq);
	Expland_Capacity(pSeq);
	pSeq->elem[pSeq->size++] = data;
}

void PopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size > 0)
	{
		pSeq->size--;
	}
	return;
}

void PushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	Expland_Capacity(pSeq);
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->elem[i + 1] = pSeq->elem[i];
	}
	pSeq->elem[0] = data;
	pSeq->size++;
}

void PopFront(SeqList* pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("Capacity Is Empty!\n");
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->elem[i] = pSeq->elem[i + 1];
	}
	pSeq->size--;
}

int main()
{
	SeqList L;
	InitSeqList(&L);
	PushBack(&L, 1);
	PushBack(&L, 2);
	PushBack(&L, 3);
	PushBack(&L, 4);
	PushBack(&L, 5);
	//SelectSort(&L);
	/*Insert(&L, 4, 4);*/
	//Erase(&L, 4);
	//RemoveAll(&L, 3);
	//BubbleSort(&L);
	//BinarySearch(&L, 2);
	PrintSeqList(&L);
	/*Find(&L, 3)*/;
	return 0;
}