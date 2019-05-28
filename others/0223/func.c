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

//删除
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
		printf("%c", phead->val);
		phead = phead->next;
	}
	printf("\n");
}


//把一个链表原地逆置
void reList(pNode *phead, pNode *ptail)
{
	if (NULL == *phead)
	{
		return;
	}
	pNode pcur, ppre;
	ppre = NULL; pcur = *phead;
	*ptail = pcur;
	while (*phead)
	{
		*phead = (*phead)->next;
		pcur->next = ppre;
		ppre = pcur;
		pcur = *phead;
	}
	*phead = ppre;
	//(*ptail)->next = NULL;
	pcur = NULL; ppre = NULL;
}

//加法
pNode myPlus(pNode *phead1, pNode *phead2)
{
	if (NULL == *phead1 || NULL == *phead2)
	{
		if (NULL == *phead1)
		{
			*phead1 = *phead2;
			*phead2 = NULL;
		}
		return *phead1;
	}

	pNode pcur1, pcur2;
	pcur1 = *phead1; pcur2 = *phead2;
	while (NULL != pcur1 || NULL != pcur2)
	{

		pcur1->val += pcur2->val - 48;
		if (NULL == pcur1->next)
		{
			pcur1->next = pcur2->next;
			free(*phead2);
			*phead2 = pcur2 = NULL;
			return pcur1;
		}
		if (NULL == pcur2->next)
		{
			free(*phead2);
			*phead2 = pcur2 = NULL;
			return pcur1;
		}
		pcur1 = pcur1->next;
		pcur2 = pcur2->next;
		free(*phead2);
		*phead2 = pcur2;
	}
	return pcur1;
}

//进位
void listCaryy(pNode phead, pNode get, pNode *ptail)
{
	if (NULL == phead || NULL == get)
	{
		return;
	}
	pNode pcur = phead;
	while (pcur != get)
	{
		if (pcur->val > '9')
		{
			pcur->val -= 10;
			pcur->next->val++;
		}
		pcur = pcur->next;
	}
	while (pcur->val > '9')
	{
		pcur->val -= 10;
		if (NULL == pcur->next)
		{
			pNode pnew;
			pnew = (pNode)malloc(sizeof(Node));
			memset(pnew, 0, sizeof(Node));
			pnew->val = '1';
			pcur->next = pnew;
			*ptail = pnew;
			pnew = pcur = get = NULL;
			return;
		}
		pcur = pcur->next;
		pcur->val++;
	}
	pcur = get = NULL;
}
