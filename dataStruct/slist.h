#ifndef _SLIST_H_
#define _SLIST_H_

#include "common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef SListNode* SList;

void SListInit(SList *phead);
void SListPushBack(SList *phead, ElemType x);
void SListPushFront(SList *phead, ElemType x);
void SListShow(SList phead);
void SListPopBack(SList *phead);
void SListPopFront(SList *phead);
void SListSort(SList *phead);
void SListInsertByVal(SList *phead, ElemType x);
void SListEraseByVal(SList *phead, ElemType x);
SList SListFind(SList phead, ElemType x);
void SListReverse(SList *phead);
void SListClear(SList *phead);
void SListEraseAll(SList *phead, ElemType x);
ElemType SListFront(SList phead);
ElemType SListBack(SList phead);

size_t SListLength(SList phead);

////////////////////////////////////////////////////////


void SListPushBack(SList *phead, ElemType x)
{
	assert(phead);
	SList s = (SList)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	SList p = *phead;
	if (p == NULL){
		*phead = s;
	}
	else{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
	}
}

void SListPushFront(SList *phead, ElemType x)
{
	assert(phead);
	SList s = (SList)malloc(sizeof(SListNode));
	s->data = x;
	SList p = *phead;

	//链接节点
	s->next = *phead;
	*phead = s;
}

void SListShow(SList phead)
{
	//assert(phead);
	SList p = phead;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over!\n");
}

void SListPopBack(SList *phead)
{
	assert(phead);
	SList p = *phead;
	SList prev = NULL;

	if (p != NULL){
		while (p->next != NULL){
			prev = p;
			p = p->next;
		}

		//需要判断释放的链表中是否只有一个节点
		if (prev == NULL){
			*phead = NULL;
		}
		else{
			prev->next = NULL;
		}
		free(p);
	}
}

void SListPopFront(SList *phead)
{
	assert(phead);
	SList p = *phead;
#if 0
	if (p->next == NULL){
		*phead = NULL;
	}
	else{
		*phead = p->next;
		p->next == NULL;
	}
	free(p);
#endif
	if (p != NULL){
		*phead = p->next;
		free(p);
	}
}

void SListSort(SList *phead)
{
	assert(phead);
	if (SListLength(*phead) <= 1){
		return;
	}
	SList tmp = *phead, prev = NULL;
	//tmp用于定位（位置为要插入的位置的下一个），prev用于保存插入位置（tmp前一个位置）
	SList p = *phead;
	SList q = p->next;
	p->next = NULL;  //断开第一个节点

	while (q != NULL){
		p = q;
		q = q->next;

		//寻找插入位置
		while (tmp != NULL  &&p->data > tmp->data){
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL){
			p->next = *phead;
			*phead = p;
		}
		else{
			p->next = prev->next;
			prev->next = p;
		}
		tmp = *phead;
		prev = NULL;
	}

}

void SListInsertByVal(SList *phead, ElemType x)
{
	assert(phead);
	SList p = *phead, prev = NULL;
	//确定插入的位置
	while (p != NULL &&  x > p->data){
		prev = p;
		p = p->next;
	}

	SList s = (SList)malloc(sizeof(SListNode));
	s->data = x;
	s->next = NULL;

	if (prev == NULL){
		s->next = *phead;
		*phead = s;
	}
	else{
		prev->next = s;
		s->next = p;
		//s->next = prev->next;  //p == prev->next;
	}
}

size_t SListLength(SList phead)
{
	size_t size = 0;
	SList p = phead;
	while (p != NULL){
		size++;
		p = p->next;
	}
	return size;
}
//倒数第k个节点
SListNode *SListFindNode(SList phead, int k)
{
	if (k > SListLength(phead))
		return NULL;
	SListNode *pre = phead;
	while (k > 0)
	{
		pre = pre->next;
		k--;
	}
	
	SListNode *p_k;
	while (pre != NULL)
	{
		pre = pre->next;
		p_k = p_k->next;
	}
	return p_k;
}

void SListEraseByVal(SList *phead, ElemType x)
{
#if 0
	assert(phead != NULL);
	SListNode *p = SListFind(*phead, key);
	if (p == NULL)
		return;

	if (p->next == NULL) //删除的是末尾节点
		SListPopBack(phead);  // 末尾节点无法采用覆盖的方式进行删除
	else
	{
		SListNode *q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
	}
#endif

	assert(phead);
	SList p = SListFind(*phead, x);
	if (p == NULL){
		return;
	}
	SList prev = *phead;
	//排除当前节点和下一个节点不是p，保证prev是p的前驱
	while (prev != p && prev->next != p){
		prev = prev->next;
	}
	//case1：要删除的节点是头结点
	if (prev == p){
		*phead = p->next;
	}
	else{
	//case2:要删除的节点不是头结点
		prev->next = p->next;
	}
	free(p);
}

SList SListFind(SList phead, ElemType x)
{
#if 0
	SList p = phead;
	while (p != NULL){
		if ((p->data == x)){
			return p;
		}
		p = p->next;
	}
	return NULL;
#endif

	SList p = phead;
	while (p != NULL && p->data!=x){
		p = p->next;
	}
	return p;
}

void SListReverse(SList *phead)
{
	assert(phead);
	SList p = *phead;
	SList q = p->next;
	p->next = NULL;
	
	while (q != NULL){
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
		//q = q->next;  放在这有问题，死循环
	}
}

void SListClear(SList *phead)
{
	assert(phead);
	SList p = NULL;
	while (*phead != NULL){
		*phead = p->next;
		free(p);
	}
}

ElemType SListFront(SList phead)
{
	assert(phead);
	return phead->data;
}

ElemType SListBack(SList phead)
{
	assert(phead);
	SList p = phead;
	while (p->next != NULL){
		p = p->next;
	}
	return p->data;
}

void SListEraseAll(SList *phead, ElemType x)
{
	//assert(phead);
	while (1){
		SList p = SListFind(*phead, x);
		if (p == NULL){
			return;
		}

		SList prev = *phead;
		while (prev != p && prev->next != p){
			prev = prev->next;
		}
		if (p == *phead){
			*phead = p->next;
		}
		else{
			prev->next = p->next;
		}
		free(p);
	}
}

#endif