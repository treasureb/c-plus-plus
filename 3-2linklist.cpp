

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;
typedef struct Node
{
	struct Node* next;
	DataType data;
}Node, *PNode;
//��ʼ��������
void InitList(PNode* pHead)
{
	*pHead = NULL;
}
//��β������һ���µĽڵ�
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
//��β��ɾ��һ���ڵ�
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
//��ͷ������һ���µĽڵ�
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
//��ͷ��ɾ��һ���µĽڵ�
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
//����ֵΪdata�Ľڵ�
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
//��Posλ����һ���ڵ�
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
//ɾ��Posλ�Ľڵ�
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
//�Ƴ������е�һ��ֵΪdata�Ľڵ�
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
//�Ƴ�����������ֵΪdata�Ľڵ�
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
//��ȡ�����нڵ���ܸ���
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
//��ȡ�����еĵ�һ���ڵ�
PNode Front(PNode pHead)
{
	return pHead;

}
//��ȡ�����е����һ���ڵ�
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
//�����п�
int Empty(PNode pHead)
{
	if (NULL == pHead)
		return 1;
	return 0;

}

//��ȡһ���µĽ��
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
//��ӡ������
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

//��β��ͷ��ӡ������
void PrintListFromTailToHead(PNode pHead)
{
	if (pHead)
	{
		PrintListFromTailToHead(pHead->next);
		printf("%d->", pHead->data);
	}
}
//ɾ����ͷ�������ķ�β�ڵ�
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
//����ͷ��������ͷ���ǰ�����½ڵ�
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
