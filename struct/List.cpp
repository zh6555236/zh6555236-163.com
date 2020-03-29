#define  _CRT_SECURE_NO_WARNINGS 
#include "List.h"
#include <iostream>
using namespace std;

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;

}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	memset(tmp, 0, sizeof(TSeqList));
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capacity);
	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;
}
void SeqList_Destroy(SeqList *List)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;
	free(tmp->node);
	free(tmp);
	tmp = nullptr;
	return;
}
void SeqList_Clear(SeqList *List)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;
	tmp->length = 0;
	return;
}
int SeqList_Length(SeqList *List)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;
	return tmp->length;
}
int SeqList_Capacity(SeqList *List)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;
	return tmp->capacity;
}
int SeqList_Insert(SeqList *List, SeqListNode *node, int pos)
{
	int i = 0;
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;
	if (pos > tmp->length)
	{
		pos = tmp->length + 1;
	}
	
	for (i = tmp->length ; i > pos; i--)
	{
		tmp->node[i] = tmp->node[i - 1];

	}
	tmp->node[i] = (unsigned int)node;
	tmp->length++;
	return 0;
}
SeqListNode *SeqList_Get(SeqList *List, int pos)
{
	TSeqList *tmp = nullptr;
	tmp = (TSeqList*)List;

	return (SeqListNode*)tmp->node[pos];
}
SeqListNode *SeqList_Delete(SeqList *List, int pos)
{
	int i = 0;
	TSeqList *tmp = nullptr;
	SeqListNode* ret = nullptr;
	tmp = (TSeqList*)List;
	ret = (SeqListNode*)tmp->node[pos];
	for (i = pos; i < tmp->length; i++)
	{
		tmp->node[i] = tmp->node[i + 1];
	}
	tmp->length--;
	return ret;
}
