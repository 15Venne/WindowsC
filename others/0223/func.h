#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef char DataType;

typedef struct Node {
	DataType val;
	struct Node *next;
}Node, *pNode;

void headInsert(pNode*, pNode*, DataType);//头插法

void tailInsert(pNode*, pNode*, DataType);//尾插法

void delVal(pNode*, pNode*, DataType);//删除元素

void print(pNode);//输出链表

void reList(pNode*, pNode*);//把一个链表原地逆置

pNode myPlus(pNode*, pNode*);//加法,，返回值是需要计算的最高位的指针

void listCaryy(pNode, pNode, pNode*);//进位
