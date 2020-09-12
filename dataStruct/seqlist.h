#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
	ElemType *base;
	size_t cap;
	size_t size;
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* plist);
void SeqListDestory(SeqList* plist);
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);
void SeqListPopBack(SeqList *plist);
void SeqListPopFront(SeqList *plist);
void SeqListInsertByVal(SeqList *plist, ElemType x);
void SeqListSort(SeqList *plist);

// ˳������
int SeqListFind(SeqList *plist, ElemType x);

// ˳���ɾ��posλ�õ�ֵ
void SeqListEraseBypos(SeqList *plist, size_t pos);
void SeqListEraseByVal(SeqList *plist, ElemType x);
void SeqListReverse(SeqList *plist);
void SeqListClear(SeqList *plist);
void SeqListMod(SeqList *plist, size_t pos, ElemType x);
int SeqListBinaryFind(SeqList *plist, ElemType x);



/////////////////////////////////////////////////////
void SeqListInit(SeqList *plist)
{
	assert(plist);
	plist->cap = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType *)malloc(sizeof(ElemType)*plist->cap);
	plist->size = 0;
}

bool _Inc(SeqList *plist, size_t new_cap)
{
	assert(plist && new_cap>plist->cap);
	ElemType *new_base = (ElemType *)malloc(sizeof(ElemType)* new_cap);
	if (new_cap == NULL){
		return false;
	}

	memcpy(new_base, plist->base, sizeof(plist->cap));

	free(plist->base);

	plist->base = new_base;
	plist->cap = new_cap;
	return true;

}

bool IsFull(SeqList *plist)
{
	assert(plist);
	return plist->size >= plist->cap;
}

bool IsEmpty(SeqList *plist)
{
	assert(plist);
	return plist->size == 0;
}


void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist);
	if (IsFull(plist)){
		printf("˳���������%d ����ͷ������.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist);
	if (IsFull(plist)){
		printf("˳���������%d ����β������.\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; --i){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}

void SeqListShow(SeqList *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("˳���Ϊ��!\n");
		return;
	}
	for (size_t i = 0; i < plist->size; ++i){
		printf("%d  ", plist->base[i]);
	}
	printf("\n");
}



void SeqListDestory(SeqList* plist)
{
	assert(plist);
	free(plist->base);
	plist->cap = 0;
	plist->size = 0;
}

bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{
	assert(plist);
	if (IsFull(plist)){
		printf("˳�������....\n");
		return false;
	}
	if (pos<0 || pos >= plist->size){
		printf("�޷����룬λ�÷Ƿ�....\n");
		return false;
	}
	for (size_t i = plist->size; i>pos; --i){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
	return true;
}

void SeqListInsertByVal(SeqList *plist, ElemType x)
{
	assert(plist);
	if (IsFull(plist) && _Inc(plist, plist->cap*2)){
		printf("˳����������޷���ֵ����.\n");
		return;
	}
#if 0
	size_t pos = 0;
	//for (int i = 0; i < plist->size; i++){
	//	if (plist->base[i] < x){
	//		pos++;
	//	}
	//}
	while (pos<plist->size && x>plist->base[pos]){
		pos++;
	}
	for (int i = plist->size; i >pos; ++i){
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
#endif
	
	size_t end = plist->size - 1;
	while (end >= 0 && x < plist->base[end]){
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end + 1] = x;
	plist->size++;
}

int SeqListFind(SeqList* plist, ElemType x)
{
	assert(plist);
#if 0
	if (IsEmpty(plist)){
		return -1;
	}
	for (size_t i = plist->size-1; i >= 0; --i){
		if (plist->base[i] == x){
			return i;
		}
	}
	return -2;
#endif
	int pos = 0;
	while (pos < plist->size && x != plist->base[pos]){
		pos++;
	}
	if (pos == plist->size){
		pos = -1;
	}
	return pos;
}

void SeqListEraseByPos(SeqList* plist, size_t pos)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("˳���Ϊ��!\n");
		return;
	}
	if (pos<0 || pos>plist->size){
		printf("��ɾ����λ�÷Ƿ�!\n");
		return;
	}
	if (pos == plist->size){
		plist->size--;
	}
	else{
		for (size_t i = pos; i < plist->size; ++i){
			plist->base[i] = plist->base[i+1];
		}
	}
	plist->size--;
	printf("ɾ���ɹ�!\n");
}

void SeqListEraseByVal(SeqList *plist, ElemType x)
{
	assert(plist);
	//�����ж�˳����״̬��Find����λ�ã�������ڣ�EraseByPos�жϲ�ɾ��
	int pos = SeqListFind(plist, x);
	if (pos == -1){
		return;
	}
	SeqListEraseByPos(plist, pos);
}

void SeqListMod(SeqList *plist, size_t pos, ElemType x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("˳���Ϊ��!\n");
		return;
	}
	if (pos<0 || pos>= plist->size){
		printf("Ҫ�޸ĵ�λ�÷Ƿ�!\n");
		return;
	}
	plist->base[pos] = x;
	printf("�޸ĳɹ�!\n");
}

void SeqListPopBack(SeqList *plist)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����β��ɾ��.\n");
		return;
	}
	plist->size--;
}

void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("˳����ѿգ�����ͷ��ɾ��.\n");
		return;
	}
	for (int i = 0; i < plist->size-1; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqListSort(SeqList *plist)
{
	assert(plist);
	if (IsEmpty(plist) || plist->size==1){
		printf("�������㹻������.\n");
		return;
	}
	for (int i = 0; i < plist->size - 1; i++){
		for (int j = 0; j < plist->size - i - 1; j++){
			if (plist->base[j]>plist->base[j + 1]){
				int tmp = plist->base[j];
				plist->base[j] = plist->base[j + 1];
				plist->base[j + 1] = tmp;
			}
		}
	}

}

void SeqListReverse(SeqList *plist)
{
	assert(plist);
	if (plist->size == 1){
		return;
	}
	int start = 0;
	int end = plist->size - 1;
	while (start <= end){
#if 0
		int tmp = plist->base[start];
		plist->base[start] = plist->base[end];
		plist->base[end] = tmp;
#endif
		Swap(&plist->base[start], &plist->base[end]);
		start++;
		end--;
	}
}

void SeqListClear(SeqList *plist)
{
	assert(plist);
	plist->size = 0;
}

int SeqListBinaryFind(SeqList *plist,ElemType x)
{
	assert(plist);
	if (IsEmpty(plist)){
		printf("˳���Ϊ��..\n");
		return -1;
	}
	int start = 0;
	int end = plist->size - 1;
	while (start <= end){
		int mid = (start + end) / 2;
		if (plist->base[mid] > x){
			end = mid - 1;
		}
		else if (plist->base[mid] < x){
			start = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

#endif