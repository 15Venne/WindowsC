#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SUMSCORE(p) (p->val.score1 + p->val.score2 + p->val.score3)
#define WORD(p) (p->val.s)
#define N 10
#define SWAP(a,b) do{pNode temp=a;a=b;b=temp;}while(0)

typedef struct student {
	int num;
	char name[20];
	char sex;
	float score1;
	float score2;
	float score3;
}stu;

typedef struct wordNode {
	char s[20];
	int cnt;
}wordNode;

typedef wordNode DataType;

typedef struct Node {
	DataType val;
	struct Node *next;
}Node,*pNode;
 
void sortInsert(pNode*, pNode*, DataType);//有序建链表

void buildList(pNode*, pNode*, char*);

void print(pNode);//打印链表（总分）

unsigned int wdcnt(char*);//统计字符串的单词个数

void buildHeap(pNode*);

void fixupMinheap(pNode*, int, int);


//有序插入单词
//void wordInsert(pNode *phead, pNode *ptail, DataType val)
//{
//	pNode pnew = (pNode)malloc(sizeof(Node));
//	memset(pnew, 0, sizeof(Node));
//	pnew->val = val;
//	pNode ppre, pcur;
//	pcur = ppre = *phead;
//	if (NULL == *phead)
//	{
//		*phead = pnew;
//		*ptail = pnew;
//	}
//	else if ((strcmp(WORD(pnew),WORD(pcur))) <= 0)
//	{
//		if ((strcmp(WORD(pnew), WORD(pcur))) == 0)
//		{
//			(*phead)->val.cnt++;
//			free(pnew);
//		}
//		else
//		{
//			pnew->next = *phead;
//			*phead = pnew;
//		}
//	}
//	else
//	{
//		while (pcur)
//		{
//			if ((strcmp(WORD(pnew), WORD(pcur))) <= 0)
//			{
//				if ((strcmp(WORD(pnew), WORD(pcur))) == 0)
//				{
//					pcur->val.cnt++;
//					free(pnew);
//					break;
//				}
//				pnew->next = pcur;
//				ppre->next = pnew;
//				break;
//			}
//			ppre = pcur;
//			pcur = pcur->next;
//		}
//		if (NULL == pcur)
//		{
//			(*ptail)->next = pnew;
//			*ptail = pnew;
//		}
//	}
//	pnew = pcur = ppre = NULL;
//}

//调整最小堆
void fixupMinheap(pNode *pa, int start, int end)
{
	int dad = start, son = dad * 2 + 1;
	while (son < end)
	{
		if (son + 1 < end && pa[son]->val.cnt > pa[son + 1]->val.cnt)
			son++;
		if (pa[dad]->val.cnt > pa[son]->val.cnt)
		{
			SWAP(pa[dad], pa[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else
			break;
	}
}

//最小堆排序
void buildHeap(pNode *pa)
{
	int i;
	for (i = N / 2 - 1; i >= 0; i--)
	{
		fixupMinheap(pa, i, N);
	}
	SWAP(pa[0], pa[N - 1]);
	for (i = N - 1; i > 1; i--)
	{
		fixupMinheap(pa, 0, i);
		SWAP(pa[0], pa[i - 1]);
	}
}

//插入单词
void wordInsert(pNode *phead, pNode *ptail, DataType val)
{
	pNode pnew = (pNode)malloc(sizeof(Node));
	memset(pnew, 0, sizeof(Node));
	pNode pcur; pcur = *phead;
	pnew->val = val;
	if (NULL == *ptail)
	{
		*phead = pnew;
		*ptail = pnew;
		pnew->val.cnt = 1;
	}
	else
	{
		while (pcur)
		{
			if (strcmp(WORD(pnew), WORD(pcur)) == 0)
			{
				pcur->val.cnt++;
				free(pnew);
				pnew = pcur = NULL;
				return;
			}
			pcur = pcur->next;
		}
		(*ptail)->next = pnew;
		*ptail = pnew;
		pnew->val.cnt = 1;
	}
	pnew = pcur = NULL;
}

//字符串挑出单词建立链表
void buildList(pNode *phead, pNode *ptail, char *s)
{
	char word[20];
	int i, j, ret;
	i = 0; ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{

			if (s[i] == '\n' || (s[i] >= '0' && s[i] <= '9'))
			{
				i++;
				continue;
			}
			j = 0;
			memset(word, 0, sizeof(word));
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\n')
			{
				word[j] = s[i];
				i++;
				j++;
			}
			wordNode wd;
			memset(&wd, 0, sizeof(wordNode));
			strcpy(wd.s, word);
			wordInsert(phead, ptail, wd);
		}
		else 
			i++;
	}
}


//打印成绩
//void print(pNode phead)
//{
//	while (phead)
//	{
//		printf("%.2f, ", SUMSCORE(phead));
//		phead = phead->next;
//	}
//	printf("\n");
//}

//统计单词个数
unsigned int wdcnt(char *s)
{
	
	int i, ret;
	unsigned int cnt;
	i = 0; ret = 0; cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			ret = 0;
		}
		else
		{
			if (s[i] == '\n'|| (s[i] >= '0' && s[i] <= '9'))
			{
				i++;
				continue;
			}
			if (ret == 0)
			{
				cnt++;
			}
			ret = 1;
		}
		i++;
	}
	return cnt;
}

//void sortInsert(pNode *phead, pNode *ptail, DataType val)
//{
//	pNode pnew = (pNode)malloc(sizeof(Node));
//	memset(pnew, 0, sizeof(Node));
//	pnew->val = val;
//	pNode ppre, pcur;
//	pcur = ppre = *phead;
//	if (NULL == *phead)
//	{
//		*phead = pnew;
//		*ptail = pnew;
//	}
//	else if (SUMSCORE(pnew) > SUMSCORE(pcur))
//	{
//		pnew->next = *phead;
//		*phead = pnew;
//	}
//	else
//	{
//		while (pcur)
//		{
//			if (SUMSCORE(pnew) > SUMSCORE(pcur))
//			{
//				pnew->next = pcur;
//				ppre->next = pnew;
//				break;
//			}
//			ppre = pcur;
//			pcur = pcur->next;
//		}
//		if (NULL == pcur)
//		{
//			(*ptail)->next = pnew;
//			*ptail = pnew;
//		}
//	}
//}
//

//int main()
//{
//	pNode phead, ptail;
//	phead = ptail = NULL;
//	DataType val;
//
//	FILE *fp = fopen("file.txt", "r+");
//	if (NULL == fp)
//	{
//		perror("fopen");
//	}
//	while (memset(&val,0,sizeof(val)), (fscanf(fp, "%d%s %c%f%f%f", &val.num,val.name,&val.sex,&val.score1,&val.score2,&val.score3)) != EOF)
//	{
//		fprintf(stdout, "%d %s %c %.2f %.2f %.2f\n", val.num, val.name, val.sex, val.score1, val.score2, val.score3);
//		sortInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	fclose(fp);
//	fp = fopen("file.txt", "w+");
//	if (NULL == fp)
//	{
//		perror("fopen");
//	}
//	while (phead)
//	{
//		fprintf(fp, "%d %s %c %5.2f %5.2f %5.2f\n", phead->val.num, phead->val.name, phead->val.sex, phead->val.score1, phead->val.score2, phead->val.score3);
//		phead = phead->next;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char filename[50] = "The_Holy_Bible_Res.txt";
//	FILE *fp = fopen("The_Holy_Bible.txt", "r+");
//	FILE *fp1 = fopen("The_Holy_Bible_Res.txt", "w+");
//	char buf[500];
//	int i, ilen;
//	while (memset(buf, 0, sizeof(buf)), (fgets(buf,sizeof(buf),fp)) != NULL)
//	{
//		ilen = strlen(buf);
//		for (i = 0; i < ilen; ++i)
//		{
//			if (buf[i] >= 'A' && buf[i] <= 'Z')
//			{
//				buf[i] += 32;
//			}
//			else if (buf[i]=='\n')
//			{
//				continue;
//			}
//			else if ((buf[i]<'A' || buf[i]>'Z') && (buf[i]<'0' || buf[i]>'9') && (buf[i] < 'a' || buf[i] > 'z'))
//			{
//				buf[i] = ' ';
//			}
//		}
//		fputs(buf, fp1);
//		//printf("%s", buf);
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	FILE *fp = fopen("The_Holy_Bible_Res.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
	}
	char buf[500];
	pNode phead, ptail;
	phead = ptail = NULL;
	unsigned int cnt = 0, linecnt = 1, wordcnt = 0;
	int i, ilen;
	pNode pcur, pa[N];//建堆用
	time_t star, end;
	star = time(NULL);
	while (memset(buf, 0, sizeof(buf)), (fgets(buf, sizeof(buf), fp)) != NULL)
	{
		ilen = strlen(buf);
		for(i = 0; i < ilen; ++i)
		{
			cnt++;
			if ('\n' == buf[i])
			{
				linecnt++;
			}
		}
		wordcnt += wdcnt(buf);
		buildList(&phead, &ptail, buf);
	}
	
	printf("cnt=%d\nlinecnt=%d\nwordcnt=%d\n", cnt, linecnt, wordcnt);
	
	pcur = phead;
	for (i = 0; i < N; ++i)
	{
		pa[i] = pcur;
		pcur = pcur->next;
	}
	//buildHeap(pa);
	
	for (i = N / 2 - 1; i >= 0; i--)
	{
		fixupMinheap(pa, i, N);
	}
	while (pcur)
	{
		if (pcur->val.cnt > pa[0]->val.cnt)
		{
			pa[0] = pcur;
			fixupMinheap(pa, 0, N);
		}
		pcur = pcur->next;
	}
	SWAP(pa[0], pa[N - 1]);
	for (i = N - 1; i > 1; i--)
	{
		fixupMinheap(pa, 0, i);
		SWAP(pa[0], pa[i - 1]);
	}
	printf("\n-------------------------\n");
	for (i = 0; i < N; ++i)
	{
		printf("%s=%d\n", pa[i]->val.s, pa[i]->val.cnt);
	}
	end = time(NULL);
	printf("经过了%d秒\n", end - star);
	system("pause");
	return 0;
}
