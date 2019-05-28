#pragma once
#include"func.h"

//头插法
void headInsert(pNode *phead, pNode *ptail, DataType val)
{
	pNode pnew = (pNode)malloc(sizeof(Node));
	memset(pnew, 0, sizeof(Node));
	pnew->val = val;
	if (NULL == *phead)
	{
		*phead = pnew;
		*ptail = pnew;
	}
	else
	{
		pnew->next = *phead;
		*phead = pnew;
	}
}

//尾插法
void tailInsert(pNode *phead, pNode *ptail, DataType val)
{
	pNode pnew = (pNode)malloc(sizeof(Node));
	memset(pnew, 0, sizeof(Node));
	pnew->val = val;
	if (NULL == *ptail)
	{
		*phead = pnew;
		*ptail = pnew;
	}
	else
	{
		(*ptail)->next = pnew;
		*ptail = pnew;
	}
}

//有序插入
void sortInsert(pNode *phead, pNode *ptail, DataType val)
{
	pNode pnew = (pNode)malloc(sizeof(Node));
	memset(pnew, 0, sizeof(Node));
	pnew->val = val;
	pNode ppre, pcur;
	pcur = ppre = *phead;
	if (NULL == *phead)
	{
		*phead = pnew;
		*ptail = pnew;
	}
	else if (pnew->val < pcur->val)
	{
		pnew->next = *phead;
		*phead = pnew;
	}
	else
	{
		while (pcur)
		{
			if (pnew->val < pcur->val)
			{
				pnew->next = pcur;
				ppre->next = pnew;
				break;
			}
			ppre = pcur;
			pcur = pcur->next;
		}
		if (NULL == pcur)
		{
			(*ptail)->next = pnew;
			*ptail = pnew;
		}
	}
}

//删除元素
void delVal(pNode *phead, pNode *ptail, DataType val)
{
	if (NULL == *phead)
	{
		printf("List is empty.");
	}
	else
	{
		pNode pcur, ppre;
		pcur = ppre = *phead;
		if (val == pcur->val)
		{
			*phead = pcur->next;
		}
		else
		{
			while (pcur)
			{
				if (val == pcur->val)
				{
					ppre->next = pcur->next;
					break;
				}
				if (pcur == *ptail)
				{
					*ptail = ppre;
					break;
				}
				ppre = pcur;
				pcur = pcur->next;
			}
			if (NULL == pcur)
			{
				printf("Can't find the val.\n");
			}
			free(pcur);
		}
	}
}

//打印链表
void print(pNode phead)
{
	while (phead)
	{
		printf("%3d", phead->val);
		phead = phead->next;
	}
	printf("\n");
}

//把两个有序表连接成一个有序表
void listLink(pNode *phead1, pNode *phead2)
{
	if (NULL == *phead1)
	{
		*phead1 = *phead2;
		return;
	}
	if (NULL == *phead2)
	{
		return;
	}
	pNode pcur, ppre, p2;
	ppre = pcur = *phead1;
	while (*phead2)
	{
		p2 = *phead2;
		if ((*phead2)->val <= (*phead1)->val)
		{
			*phead2 = (*phead2)->next;//先删除链表2的结点，再连接
			p2->next = *phead1;
			*phead1 = p2;
			ppre = pcur = *phead1;
		}
		else
		{
			if (NULL == pcur)
			{
				ppre->next = *phead2;
				break;
			}
			if ((*phead2)->val <= pcur->val)
			{
				*phead2 = (*phead2)->next;//先删除链表2的结点，再连接
				p2->next = pcur;
				ppre->next = p2;
				continue;
			}
			ppre = pcur;
			pcur = pcur->next;
		}
	}
	p2 = NULL; phead2 = NULL; pcur = NULL; ppre = NULL;
}

//把一个链表原地逆置
void reList(pNode *phead)
{
	if (NULL == *phead)
	{
		return;
	}
	pNode pcur, ppre;
	ppre = NULL; pcur = *phead;
	while (*phead)
	{
		*phead = (*phead)->next;
		pcur->next = ppre;
		ppre = pcur;
		pcur = *phead;
	}
	*phead = ppre;
	pcur = NULL; ppre = NULL;
}

//找出链表倒数第四个结点
pNode lastElem(pNode phead,int n)
{
	pNode pcur, ppre;
	int i;
	ppre = pcur = phead;
	for (i = 1; i < n; ++i)
	{
		pcur = pcur->next;
	}
	if (NULL == pcur)
	{
		printf("Elems is less than %d.\n", n);
		return pcur;
	}
	while (NULL != pcur)
	{
		pcur = pcur->next;
		if (NULL == pcur)
		{
			break;
		}
		ppre = ppre->next;
	}
	return ppre;
}

//找出链表的中间结点
pNode midElem(pNode phead)
{
	pNode ppre, pcur;
	pcur = ppre = phead;
	if (NULL == pcur->next)
	{
		pcur = NULL;
		return ppre;
	}
	while (pcur != NULL)
	{
		if (NULL == pcur->next)
		{
			pcur = NULL;
			return ppre;
		}
		pcur = pcur->next->next;
		ppre = ppre->next;
	}
	return ppre;
}

//判断链表是否有环
int isLoop(pNode phead)
{
	if (NULL == phead || NULL == phead->next)
	{
		return 0;
	}
	pNode ppre, pcur;
	ppre = pcur = phead;
	pcur = pcur->next;
	while (pcur != ppre)
	{
		if (NULL == pcur || NULL == pcur->next)
		{
			ppre = pcur = NULL;
			return 0;
		}
		pcur = pcur->next->next;
		ppre = ppre->next;
	}
	ppre = pcur = NULL;
	return 1;
}

//判断两个链表是否相交， 如果相交， 计算交点
pNode isIntersect(pNode phead1, pNode phead2)
{
	int cnt1=0, cnt2=0;
	int i;
	pNode pcur1 = phead1, pcur2 = phead2;
	while (pcur1 != NULL)
	{
		pcur1 = pcur1->next;
		cnt1++;
	}
	while (pcur2 != NULL)
	{
		pcur2 = pcur2->next;
		cnt2++;
	}
	pcur1 = phead1; pcur2 = phead2;
	for (i = 0; i < abs(cnt1 - cnt2); ++i)
	{
		if (cnt1 > cnt2)
		{
			pcur1 = pcur1->next;
		}
		else
		{
			pcur2 = pcur2->next;
		}
	}
	while (pcur1 != pcur2)
	{
		if (NULL == pcur1 || NULL == pcur2)
		{
			pcur1 = pcur2 = NULL;
			return NULL;
		}
		pcur1 = pcur1->next;
		pcur2 = pcur2->next;
	}
	pcur1 = NULL;
	return pcur2;
}

//删除单链表重复元素
void delDup(pNode phead,pNode *ptail)
{
	if (NULL == phead || NULL == phead->next)
	{
		return;
	}
	pNode pi, pj, ppre;
	pi = phead;	
	while (NULL != pi)
	{
		ppre = pi;
		pj = pi->next;
		while (NULL != pj)
		{
			if (pi->val == pj->val)
			{
				ppre->next = pj->next;
				free(pj);
				pj = ppre->next;
				continue;
			}
			ppre = pj;
			pj = pj->next;
		}
		pi = pi->next;
	}
	*ptail = ppre;
	ppre = NULL;
}

//将一个链表按奇偶拆分
void listSeparete(pNode *phead1, pNode *phead2, pNode *ptail1, pNode *ptail2)
{
	if (NULL == *phead1 || NULL == (*phead1)->next)
	{
		*phead2 = *ptail2 = NULL;
		return;
	}
	pNode pcur, ppre;
	ppre = pcur = *phead1;
	int cnt = 1;

	pcur = pcur->next;
	cnt++;
	ppre->next = pcur->next;
	pcur->next = NULL;
	*ptail2 = *phead2 = pcur;
	pcur = ppre->next;
	cnt++;

	while (pcur)
	{
		if (cnt % 2 == 0)
		{
			ppre->next = pcur->next;
			pcur->next = *phead2;
			*phead2 = pcur;
			pcur = ppre->next;
			cnt++;
			continue;
		}
		cnt++;
		ppre = pcur;
		pcur = pcur->next;
	}
	*ptail1 = ppre;
	ppre = NULL;
}
