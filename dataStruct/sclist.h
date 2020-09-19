#ifndef _SCLIST_H_
#define _SCLIST_H_

#include"common.h"


typedef struct SCListNode
{
	ElemType data;
	struct SCListNode *next;
}SCListNode;

//����ͷ���ĵ�ѭ������

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

	//�������
	//�ҵ�β��㣨ͷ����prev����Ȼ��Ͽ��������µĽڵ��ȥ
	//Ȼ�����½ڵ��nextָ��phead
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
		printf("��ǰ������������,�޷�βɾ\n");
		return;
	}
	SCListNode *p = (*phead)->next;
	SCListNode *prev = *phead;
	//��ǰ������ֻ��һ���ڵ�
	if (p->next == p)
	{
		*phead = NULL;
	}
	else
	{
		//��ǰ�����а�������ڵ�  ���ÿ���ָ��Ѱ��ɾ��֮���ǰ��
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
		printf("��ǰ�����������ݣ��޷�ͷɾ\n");
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
		*phead = (*phead)->next;   //ע��ͷ���ָ����һ��λ�ú���ɾ��֮ǰ��ǰ��ָ���� phead
		p->next = *phead;
	}
	free(tmp);
}















#endif