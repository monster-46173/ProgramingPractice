#pragma once

#include <stdlib.h>

#ifndef LIST_INIT_SIZE
	#define LIST_INIT_SIZE 100
#endif
#ifndef LISTINCREMENT
	#define LISTINCREMENT 10
#endif
#ifndef TYPE
	typedef int ElemType;
#endif

#define ERROR 0
#define OVERFLOW -2
#define OK 1

typedef int Status;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

void InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L, int i, ElemType e);
Status ListDelete_Sq(SqList *L, int i, ElemType *e);
int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType));
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc, Status (*compare)(ElemType, ElemType));
void PrintList_Sq(SqList *L, void (*outputItem)(int i, ElemType e));

void InitList_Sq(SqList *L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)	//i��1��ʼ 
{
	ElemType *p, *q;
	ElemType *newbase;
	if (i < 1 || i > L->length + 1)
		return ERROR;
	if (L->length >= L->listsize)
	{
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i - 1]);
	for (p = &(L->elem[L->length - 1]); p > q; p--)
		*p = *(p - 1);
	*q = e;
	L->length++;
	return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	ElemType *p, *q;
	if (i < 1 || i > L->length)
		return ERROR;
	p = &(L->elem[i - 1]);
	*e = *p;
	q = L->elem + L->length - 1;
	for (p++; p < q; p++)
		*(p - 1) = *p;
	L->length--;
	return OK;
}

int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType))
{
	//��˳����в�ѯ��һ�������ж�����������Ԫ�أ� 
	//�����ڣ��򷵻�����λ�򣨴�1��ʼ�������򷵻�0
	int i = 0;
	ElemType *p = L->elem;
	while (i <= L->length && !(*compare)(*p++, e))
		i++;
	if (i <= L->length)
		return i;
	else
		return 0;
}

void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc, Status (*compare)(ElemType, ElemType))
{
	//��֪���Ա�La��Lb��ֵ�ǵݼ���������
	//�鲢La��Lb�õ��µ����Ա�Lc��Lc�е�����Ԫ��Ҳ��ֵ
	//�ǵݼ����С� 
	ElemType *pa = La->elem, *pb = Lb->elem, *pc;
	Lc->listsize = La->length + Lb->length;
	Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem)
		exit(OVERFLOW);
	pc = Lc->elem;
	while (pa <= La->elem + La->length - 1 && 
		pb <= Lb->elem + Lb->length - 1 &&
		pc <= Lc->elem + Lc->listsize - 1)
	{
		if ((*compare)(*pa, *pb)) {	//pa > pb
			*pc = *pb;
			pb++;
		} else {
			*pc = *pa;
			pa++;
		}
		pc++;
		Lc->length++;
	}
	while (pa <= La->elem + La->length - 1)
	{
		*pc++ = *pa++;
		Lc->length++;
	}
	while (pb <= Lb->elem + Lb->length - 1)
	{
		*pc++ = *pb++;
		Lc->length++;
	}
}

void PrintList_Sq(SqList *L, void (*outputItem)(int i, ElemType e))
{
	int i;
	for (i = 0; i < L->length; i++)
		(*outputItem)(i + 1, L->elem[i]);
}
