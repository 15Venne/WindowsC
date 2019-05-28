#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef int DataType;

typedef struct Node {
	DataType val;
	struct Node *next;
}Node, *pNode;

void headInsert(pNode*, pNode*, DataType);//头插法

void tailInsert(pNode*, pNode*, DataType);//尾插法

void sortInsert(pNode*, pNode*, DataType);//有序插入

void delVal(pNode*, pNode*, DataType);//删除元素

void listLink(pNode*, pNode*);//两个有序链表合成一个有序链表

void print(pNode);//输出链表

void reList(pNode*);//把链表逆置

pNode lastElem(pNode, int);//找倒数元素

pNode midElem(pNode);//找中间元素

int isLoop(pNode);//判断是否有环

pNode isIntersect(pNode, pNode);//判断是否相交

void delDup(pNode, pNode*);//删除重复元素

void listSeparete(pNode*, pNode*, pNode*, pNode*);//将一个链表按奇偶拆分


