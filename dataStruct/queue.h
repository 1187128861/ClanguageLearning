#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "common.h"

//��ʽ���У��������нṹ��Ͷ��нڵ�ṹ��������
typedef  struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *head;  //��ͷָ��
	LinkQueueNode *tail;   //��βָ��
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

//��malloc�����½ڵ㲢���ڵ�ָ���������ֵ
//�����ǰ������û�нڵ㣬����ͷ��βͬʱָ���½ڵ�
//�����ǰ�������Ѿ�����Ԫ�أ�����βָ��ָ��ýڵ㣬������βָ��
//�˴��Ĳ���Ϊβ��
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

//����ǰ�ж������Ƿ�Ϊ�գ�pq->head == NULL
//�����м�Ľṹ��ָ��p���ͷŽڵ�
//���еĳ���˳���Ƚ��ȳ��������е�ͷɾ����
void LinkQueueDe(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->head != NULL)      //�ж϶����Ƿ�Ϊ�գ����ս���
	{
		LinkQueueNode  *p = pq->head;
		if (pq->head == pq->tail)    //�ж��Ƿ�ֻ��һ��Ԫ��
			pq->head = pq->tail = NULL;
		else
			pq->head = p->link;
		free(p);
	}
}

ElemType LinkQueueFront(LinkQueue *pq)
{
	assert(pq != NULL);
	assert(pq->head != NULL);     //�ж��Ƿ����Ԫ��
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
		printf("����Ϊ��\n");
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

//�¶���ָ��ָ����е�ͷ��Ȼ������ͷ�
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


//˳�����

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
		printf("����������%d�������\n");
		return;
	}
	psq->base[psq->rear++] = x;
}
//����������� �������п�
void SqeQueueDe(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueEmpty(psq))
	{
		printf("�����ѿգ����ܳ���\n");
		return;
	}
	psq->front++;   //ֱ���ƶ�ָ��ָ�򣬵��ڱ��ǰ���������Ч
}

int SeqQueueSize(SeqQueue *psq)
{
	assert(psq != NULL);
	return (psq->rear - psq->front);   //˳�����ֱ���������Ҫѭ����
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


//ѭ������
//ѭ��������ѧҪע��ĵ㣺ָ���ָ��λ�õ��ƶ���Ҫ������ȡģ
//ѭ�������ж�ͷ��ǰһλ�ÿ�����Ŀ�ģ����ֿն��к�������
//�ն��У�pcq->front == pcq->rear;
//�����У�(pcq->rear+1)%(pcq->capcaity+1) == pcq->front;
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
		printf("ѭ������������%d�������\n", x);
		return;
	}

	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);  //ѭ������
}

void CycleSeqQueueDe(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	if (CycleSeqQueueIsEmpty(pcq))
	{
		printf("ѭ�������ѿգ����ܳ���\n");
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