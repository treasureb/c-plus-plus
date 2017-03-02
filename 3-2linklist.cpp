

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;
typedef struct Node
{
	struct Node* next;
	DataType data;
}Node, *PNode;
//初始化单链表
void InitList(PNode* pHead)
{
	*pHead = NULL;
}
//从尾部插入一个新的节点
void Pushback(PNode* pHead, DataType data)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = NULL;
	}
}
//从尾部删除一个节点
void Popback(PNode *pHead)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		PNode pPre = pCur;

		while (pCur)
		{
			pPre = pCur;
			pCur = pCur->next;
		}

		free(pCur);
		pPre->next = NULL;

	}
}
//从头部插入一个新的节点
void PushFront(PNode *pHead, DataType data)
{
	PNode pNewNode = BuyNode(data);
	assert(pHead);
	if (pNewNode)
	{
		pNewNode->next = *pHead;
		*pHead = pNewNode;
	}
}
//从头部删除一个新的节点
void PopFront(PNode *pHead)
{
	PNode Del = NULL;
	assert(*pHead);
	if (NULL == pHead)
	{
		return;
	}

	Del = *pHead;
	*pHead = (*pHead)->next;
	free(Del);
}
//查找值为data的节点
PNode Find(PNode *pHead, DataType data)
{
	PNode pCurNode = *pHead;
	while (pCurNode)
	{
		if (pCurNode->data == data);
		return pCurNode;

		pCurNode = pCurNode->next;
	}
	return NULL;
}
//在Pos位插入一个节点
void Insert(PNode Pos, DataType data)
{
	PNode pNewNode = NULL;

	if (NULL == Pos)
	{
		return;
	}

	pNewNode = BuyNode(data);
	pNewNode->next = Pos->next;
	Pos->next = pNewNode;
}
//删除Pos位的节点
void Erase(PNode *pHead, PNode Pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == Pos)
		return;
	else if (Pos == *pHead)
	{
		*pHead = Pos->next;
		free(Pos);
	}
	else
	{
		PNode pPre = *pHead;
		while (pPre->next != Pos)
		{
			pPre = pPre->next;
		}
		pPre->next = Pos->next;
		free(Pos);
	}
}
//移除链表中第一个值为data的节点
void Remove(PNode *pHead, DataType data)
{
	PNode pPreNode = NULL;
	PNode pCurNode = *pHead;
	assert(*pHead);
	while (pCurNode->data != data)
	{
		pPreNode = pCurNode;
		pCurNode = pCurNode->next;
	}
	pPreNode->next = pCurNode->next;
	free(pCurNode);
}
//移除链表中所有值为data的节点
void RemoveAll(PNode *pHead, DataType data)
{
	PNode pPreNode = NULL;
	PNode pCurNode = NULL;
	assert(*pHead);

	pPreNode = *pHead;
	pCurNode = (*pHead)->next;

	while (pCurNode)
	{
		if (pCurNode->data == data)
		{
			pPreNode->next = pCurNode->next;
			free(pCurNode);
			pCurNode->next = pPreNode->next;
		}
		pCurNode = pCurNode->next;
	}
	if ((*pHead)->data == data)
	{
		pCurNode = *pHead;
		*pHead = (*pHead)->next;
		free(pCurNode);
	}
}
//获取链表中节点的总个数
size_t Size(PNode pHead)
{
	int count;
	while (pHead)
	{
		pHead = pHead->next;
		count++;
	}
	return count;
}
//获取链表中的第一个节点
PNode Front(PNode pHead)
{
	return pHead;

}
//获取链表中的最后一个节点
PNode Back(PNode pHead)
{
	if (NULL == pHead)
		return;
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	return pHead;
}
//链表判空
int Empty(PNode pHead)
{
	if (NULL == pHead)
		return 1;
	return 0;

}

//获取一个新的结点
PNode BuyNode(DataType data)
{
	PNode pTemp = (PNode)malloc(sizeof(Node));
	if (NULL == pTemp)
	{
		printf("This is Empty!");
	}
	else
	{
		pTemp->data = data;
		pTemp->next = NULL;
	}
	return pTemp;
}
//打印单链表
void Printlist(PNode pHead)
{
	PNode pCur = pHead;

	while (pCur)
	{
		printf("%d ->", pCur->data);
		pCur = pCur->next;
	}

	printf("\n");
}

//从尾到头打印单链表
void PrintListFromTailToHead(PNode pHead)
{
	if (pHead)
	{
		PrintListFromTailToHead(pHead->next);
		printf("%d->", pHead->data);
	}
}
//删除无头单链表的非尾节点
void DeleteNotTailNode(PNode pPos)
{
	PNode pDelNode = NULL;
	if (NULL == pPos || NULL == pPos)
		return;

	pDelNode = pPos->next;
	pPos->data = pDelNode->data;
	pPos->next = pDelNode->next;
	free(pDelNode);

}
//在无头单链表非头结点前插入新节点
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
		return;
	else
	{
		PNode pNewNode = BuyNode(pos->data);
		if (pNewNode)
		{
			pNewNode->data = pos->next;
			pos->next = pNewNode;
			pos->data = data;
		}
	}

}

void Fun1()
{
	PNode pHead;
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Printlist(pHead);


}

int main()
{
	Fun1();
	return 0;
}

