#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

#define STACK_DEFAULT_SIZE 8


//top 指向的空间是即将放入元素的空间
//栈 --》 受操作限制的顺序表

//顺序栈
typedef struct SeqStack
{
	ElemType *base;
	size_t	  capacity;
	int		  top;
}SeqStack;

void SeqStackInit(SeqStack *pst, int size = STACK_DEFAULT_SIZE);
void SeqStackPush(SeqStack *pst, ElemType x);
void SeqStackPop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst); //取栈顶元素
void SeqStackShow(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);
int SeqStackSize(SeqStack *pst);

bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst);
	return pst->top >= pst->capacity;
}

bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst);
	return pst->top == 0;
}

void SeqStackInit(SeqStack *pst, int size)
{
	assert(pst);
	pst->capacity = size > STACK_DEFAULT_SIZE ? size : STACK_DEFAULT_SIZE;
	pst->base = (ElemType *)malloc(sizeof(ElemType)*pst->capacity);
	pst->top = 0;
}

void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst)){
		printf("栈已满，%d 不能入栈.\n");
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst)){
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	assert(!SeqStackIsEmpty(pst));
	return pst->base[pst->top-1];
}

void SeqStackShow(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i){
		printf("| %d |\n", pst->base[i]);
	}
	printf("---\n");
}

int SeqStackSize(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top;
}

void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	pst->base = 0;
	pst->capacity = 0;
	free(pst->base);
	pst->base = NULL;
}









//链栈

typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;

void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
void LinkStackShow(LinkStack pst);
ElemType LinkStackTop(LinkStack pst);
int LinkStackSize(LinkStack pst);
void LinkStackDestroy(LinkStack *pst);


/////////////////////////////////////////////////
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = *pst; //相当于头插，作用呢：先进后出
	*pst = node;
}

void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst != NULL){
		LinkStackNode *p = *pst;
		*pst = p->link;
		free(p);
	}
}

void LinkStackShow(LinkStack pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst;
	while (p != NULL){
		printf("| %d |\n", p->data);
		p = p->link;
	}
	printf("----\n");
}

ElemType LinkStackTop(LinkStack pst)
{
	assert(pst != NULL);
	return pst->data;
}

int LinkStackSize(LinkStack pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = pst;
	while (p != NULL){
		size++;
		p = p->link;
	}
	return size;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(*pst != NULL);
	LinkStackNode *p = *pst;
	while (p != NULL){
		*pst = p->link;
		free(p);
		p = *pst;
	}
}


#endif