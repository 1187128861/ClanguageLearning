#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "common.h"

//链式队列：包含队列结构体和队列节点结构体两部分
typedef  struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *head;  //队头指针
	LinkQueueNode *tail;   //队尾指针
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
void LinkQueueEn(LinkQueue *pq, ElemType x);
void LinkQueueDe(LinkQueue *pq);
ElemType LinkQueueFront(LinkQueue *pq);
int LinkQueueSize(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
void LinkQueueShow(LinkQueue *pq);
void LinkQueueDestroy(LinkQueue *pq);
/////////////////////////////////////////////

void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->head = pq->tail = NULL;
}

//先malloc开辟新节点并给节点指向的数据域赋值
//如果当前链队中没有节点，就让头和尾同时指向新节点
//如果当前链队中已经存在元素，就让尾指针指向该节点，并更新尾指针
//此处的操作为尾插
void LinkQueueEn(LinkQueue *pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	if (pq->head == NULL)
		pq->head = pq->tail = node;
	else
	{
		pq->tail->link = node;
		pq->tail = node;
	}
}

//出队前判断链队是否为空，pq->head == NULL
//定义中间的结构体指针p来释放节点
//队列的出队顺序：先进先出，链队中的头删操作
void LinkQueueDe(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->head != NULL)      //判断队列是否为空，不空进入
	{
		LinkQueueNode  *p = pq->head;
		if (pq->head == pq->tail)    //判断是否只有一个元素
			pq->head = pq->tail = NULL;
		else
			pq->head = p->link;
		free(p);
	}
}

ElemType LinkQueueFront(LinkQueue *pq)
{
	assert(pq != NULL);
	assert(pq->head != NULL);     //判断是否存在元素
		return pq->head->data;
}

int LinkQueueSize(LinkQueue *pq)
{
	assert(pq != NULL);
	int size = 0;
	LinkQueueNode *p = pq->head;
	while (p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}

bool LinkQueueEmpty(LinkQueue *pq)
{
	assert(pq != NULL);
	return pq->head == NULL;
}

void LinkQueueShow(LinkQueue *pq)
{
	assert(pq != NULL);
#if 0
	if (LinkQueueEmpty(pq))
	{
		printf("队列为空\n");
		return;
	}
#endif
	LinkQueueNode *p = pq->head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

//新定义指针指向队列的头，然后逐个释放
void LinkQueueDestroy(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->head;
	while (p != NULL)
	{
		pq->head = p->link;
		free(p);
		p = pq->head;
	}
}


//顺序队列

#define QUEUE_DEFAULT_SIZE 8

typedef struct SeqQueue
{
	ElemType *base;
	int capacity;
	int front;
	int rear;
}SeqQueue;

void SeqQueueInit(SeqQueue *psq, int sz = QUEUE_DEFAULT_SIZE);
void SeqQueueEn(SeqQueue *psq, ElemType x);
void SqeQueueDe(SeqQueue *psq);
bool SeqQueueEmpty(SeqQueue *psq);
int SeqQueueSize(SeqQueue *psq);
void SeqQueueShow(SeqQueue *psq);
void SeqQueueDestroy(SeqQueue *psq);

/////////////////////////////////////////////////////
bool SeqQueueEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

void SeqQueueInit(SeqQueue *psq, int sz)
{
	assert(psq != NULL);
	psq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	psq->base = (ElemType *)malloc(sizeof(ElemType)*psq->capacity);
	psq->front = psq->rear = 0;
}

void SeqQueueEn(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (psq->rear >= psq->capacity) 
	{
		printf("队列已满，%d不能入队\n");
		return;
	}
	psq->base[psq->rear++] = x;
}
//入队需判满， 出队需判空
void SqeQueueDe(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueEmpty(psq))
	{
		printf("队列已空，不能出队\n");
		return;
	}
	psq->front++;   //直接移动指针指向，等于标记前面的数据无效
}

int SeqQueueSize(SeqQueue *psq)
{
	assert(psq != NULL);
	return (psq->rear - psq->front);   //顺序队列直接作差，不需要循环。
}

void SeqQueueShow(SeqQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i < psq->rear; ++i)
		printf("%d->", psq->base[i]);
	printf("\n");
}

void SeqQueueDestroy(SeqQueue *psq)
{
	assert(psq != NULL);
	free(psq->base);
	psq->base = NULL;
	psq->capacity = psq->front = psq->rear = 0;
}


//循环队列
//循环队列中学要注意的点：指针的指向，位置的移动需要与容量取模
//循环队列中队头的前一位置空留，目的：区分空队列和满队列
//空队列：pcq->front == pcq->rear;
//满队列：(pcq->rear+1)%(pcq->capcaity+1) == pcq->front;
typedef struct CycleSeqQueue
{
	ElemType *base;
	int capacity;
	int front;
	int rear;
}CycleSeqQueue;

void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz = QUEUE_DEFAULT_SIZE);
bool CycleSeqQueueIsEmpty(CycleSeqQueue *pcq);
bool CycleSeqQueueIsFull(CycleSeqQueue *pcq);
void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x);
void CycleSeqQueueDe(CycleSeqQueue *pcq);
ElemType CycleSeqQueueFront(CycleSeqQueue *pcq);
int CycleSeqQueueSize(CycleSeqQueue *pcq);
void CycleSeqQueueShow(CycleSeqQueue *pcq);
void CycleSeqQueueDestroy(CycleSeqQueue *pcq);

///////////////////////////////////////////////////////
bool CycleSeqQueueIsEmpty(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return pcq->front == pcq->rear;
}

bool CycleSeqQueueIsFull(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return ((pcq->rear + 1) % (pcq->capacity+1)) == pcq->front;
}

void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz)
{
	assert(pcq != NULL);
	pcq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	pcq->base = (ElemType *)malloc(sizeof(ElemType)*pcq->capacity);
	pcq->front = pcq->rear = 0;
}

void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x)
{
	assert(pcq != NULL);
	if (CycleSeqQueueIsFull(pcq))
	{
		printf("循环队列已满，%d不能入队\n", x);
		return;
	}

	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);  //循环队列
}

void CycleSeqQueueDe(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	if (CycleSeqQueueIsEmpty(pcq))
	{
		printf("循环队列已空，不能出队\n");
		return;
	}
	pcq->front = (pcq->front + 1) % (pcq->capacity + 1);
}

ElemType CycleSeqQueueFront(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	assert(!CycleSeqQueueIsEmpty(pcq));
	return pcq->base[pcq->front];
}

int CycleSeqQueueSize(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	int size = 0;
	for (int i = pcq->front; i != pcq->rear;)
	{
		size++;
		i = (i + 1) % (pcq->capacity + 1);
	}
	return size;
}

void CycleSeqQueueShow(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	for (int i = pcq->front; i != pcq->rear;)
	{
		printf("%d->", pcq->base[i]);
		i = (i + 1) % (pcq->capacity + 1);
	}
	printf("\n");
}

void CycleSeqQueueDestroy(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	free(pcq->base);
	pcq->base = NULL;
	pcq->capacity = pcq->front = pcq->rear = 0;
}


#endif