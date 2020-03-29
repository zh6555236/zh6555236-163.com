# zh6555236-163.com
#pragma once

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);
void SeqList_Destroy(SeqList *List);
void SeqList_Clear(SeqList *List);
int SeqList_Length(SeqList *List);
int SeqList_Capacity(SeqList *List);
int SeqList_Insert(SeqList *List,SeqListNode *node,int pos);
SeqListNode *SeqList_Get(SeqList *List, int pos);
SeqListNode *SeqList_Delete(SeqList *List, int pos);
