#ifndef _SCLIST_H_
#define _SCLIST_H_

#include"common.h"


typedef struct SCListNode
{
	ElemType data;
	struct SCListNode *next;
}SCListNode;

//不带头结点的单循环链表

typedef SCListNode* SCList;

void SCListInit(SCList *phead);
void SCListPushBack(SCList *phead, ElemType x);
void SCListShow(SCList phead);
void SCListPushFront(SCList *phead, ElemType x);
void SCListPopBack(SCList *phead);
void SCListPopFront(SCList *phead);

//////////////////////////////////////

void SCListInit(SCList *phead)
{
	*phead = NULL;
}

void SCListPushBack(SCList *phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode *node = (SCListNode *)malloc(sizeof(SCListNode));
	assert(node != NULL);
	node->data = x;

	//结点链接
	//找到尾结点（头结点的prev），然后断开，链接新的节点进去
	//然后让新节点的next指向phead
	SCListNode *p = *phead;
	if (p == NULL)
		*phead = node;
	else
	{
		while (p->next != *phead)
			p = p->next;
		p->next = node;
	}
	node->next = *phead;
}

void SCListShow(SCList phead)
{
	SCListNode *p = phead;
	if (p != NULL)
	{
		while (p->next != phead)
		{
			printf("%d->", p->data);
			p = p->next;
		}
		printf("%d->", p->data);
	}
	printf("over.\n");
}

void SCListPushFront(SCList *phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode *node = (SCListNode *)malloc(sizeof(SCListNode));
	node->data = x;
	SCListNode *p = *phead;

	if (p == NULL)
	{
		*phead = node;
		node->next = *phead;
	}
	else
	{
		while (p->next != *phead)
			p = p->next;
		p->next = node;
		node->next = *phead;
		*phead = node;
	}
}

void SCListPopBack(SCList *phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		printf("当前链表中无数据,无法尾删\n");
		return;
	}
	SCListNode *p = (*phead)->next;
	SCListNode *prev = *phead;
	//当前链表中只有一个节点
	if (p->next == p)
	{
		*phead = NULL;
	}
	else
	{
		//当前链表中包含多个节点  利用快慢指针寻找删除之后的前驱
		while (p->next != *phead)
		{
			p = p->next;
			prev = prev->next;
		}
		prev->next = *phead;
	}
	free(p);
}

void SCListPopFront(SCList *phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		printf("当前链表中无数据，无法头删\n");
		return;
	}
	SCListNode *p = *phead;
	SCListNode *tmp = *phead;
	if (p->next == p)
		*phead = NULL;
	else
	{
		while (p->next != *phead)
			p = p->next;
		*phead = (*phead)->next;   //注意头结点指向下一个位置后，让删除之前的前驱指向新 phead
		p->next = *phead;
	}
	free(tmp);
}















#endif