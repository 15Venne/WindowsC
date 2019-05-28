#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;//数据类型

typedef struct Node 
{ 
	DataType val;
	struct Node *next; //
}Node,*pNode;

typedef struct myStack 
{ 
	int size;
	pNode top;
}myStack,*pmyStack;

void initStack(pmyStack);//初始化栈

int isEmpty(pmyStack);//判断栈是否为空

void myPush(pmyStack, DataType);//入栈

DataType myPop(pmyStack);//出栈，返回栈顶元素

DataType topElem(pmyStack);//获取栈顶元素

int stackSize(pmyStack);//获取栈大小

void print(pNode);//打印链表

/**********************************************************/

typedef struct TNode
{
	char c;
	struct TNode *plchild;
	struct TNode *prchild;
}TNode,*pTNode;

typedef struct tmpQueue
{
	struct tmpQueue *next;
	pTNode treepos;
}tmpQueue,*ptmpQueue;

pTNode buildTree(char*);

void preOrder(pTNode);

void midOrder(pTNode);

void latOrder(pTNode);


//初始化栈
void initStack(pmyStack p)
{
	p->top = NULL;
	p->size = 0;
}

//判断栈是否为空
int isEmpty(pmyStack p)
{
	return !p->size;
}

//入栈
void myPush(pmyStack p, DataType val)
{
	pNode pnew;
	pnew = (pNode)calloc(1, sizeof(Node));
	pnew->val = val;
	pnew->next = p->top;
	p->top = pnew;
	p->size++;
}

//出栈，返回栈顶元素
DataType myPop(pmyStack p)
{
	if (NULL == p->top)
	{
		printf("stack is empty.\n");
		return -1;
	}
	DataType x;
	pNode pcur;
	pcur = p->top;
	p->top = p->top->next;
	x = pcur->val;
	p->size--;
	free(pcur);
	pcur = NULL;
	return x;
}

//获取栈顶元素
DataType topElem(pmyStack p)
{
	if (NULL == p->top)
	{
		printf("stack is empty.\n");
		return -1;
	}
	return p->top->val;
}

//获取栈大小
int stackSize(pmyStack p)
{
	return p->size;
}

//打印链表
void print(pNode phead)
{
	while (phead)
	{
		printf("%d ", phead->val);
		phead = phead->next;
	}
	printf("\n");
}

/****************************************************************************/

pTNode buildTree(char *s)
{
	ptmpQueue phead = NULL, ptail = NULL;
	ptmpQueue pQnew, pFree;
	pTNode treeRoot = NULL, pnew;
	while (*s)
	{
		pnew = (pTNode)calloc(1, sizeof(TNode));
		pQnew = (ptmpQueue)calloc(1, sizeof(tmpQueue));
		pnew->c = *s;
		pQnew->treepos = pnew;
		if (NULL == treeRoot)
		{
			treeRoot = pnew;
			phead = pQnew;
			ptail = pQnew;
		}
		else
		{
			ptail->next = pQnew;
			ptail = pQnew;
			if (NULL == phead->treepos->plchild)
			{
				phead->treepos->plchild = pnew;
			}
			else if (NULL == phead->treepos->prchild)
			{
				phead->treepos->prchild = pnew;
				pFree = phead;
				phead = phead->next;
				free(pFree);
				pFree = NULL;
			}
		}
		s++;
	}
	while (phead)
	{
		pFree = phead;
		phead = phead->next;
		free(pFree);
		pFree = NULL;
	}
	ptail = pQnew = NULL;
	pnew = NULL;
	return treeRoot;
}

void preOrder(pTNode p)
{
	if (p)
	{
		putchar(p->c);
		preOrder(p->plchild);
		preOrder(p->prchild);
	}
}
void midOrder(pTNode p)
{
	if (p)
	{
		midOrder(p->plchild);
		putchar(p->c);
		midOrder(p->prchild);
	}
}
void latOrder(pTNode p)
{
	if (p)
	{
		latOrder(p->plchild);
		latOrder(p->prchild);
		putchar(p->c);
	}
}


//int main()
//{
//	myStack s;
//	initStack(&s);
//	DataType val;
//	while (scanf("%d", &val) != EOF)
//	{
//		myPush(&s, val);
//	}
//	print(s.top);
//	printf("现在栈顶：%d\n", topElem(&s));
//	DataType x = myPop(&s);
//	printf("弹出元素：%d\n", x);
//	printf("现在栈顶：%d\n", topElem(&s));
//	
//	printf("现在栈大小：%d\n", s.size);
//	print(s.top);
//
//	system("pause");
//	return 0;
//}

int main()
{
	char s[100];
	gets(s);
	puts(s);
	pTNode root;

	root = buildTree(s);
	preOrder(root);
	printf("\n");
	midOrder(root);
	printf("\n");
	latOrder(root);
	printf("\n");
	system("pause");
	return 0;
}
