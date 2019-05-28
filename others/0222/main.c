//#include<stdio.h>
//#include<stdlib.h>
//
//int f(int m, int n)
//{
//	if (0 == m || 0 == n)
//	{
//		if (m != 0)
//		{
//			return 1;
//		}
//		else if (n != 0)
//		{
//			return 1;
//		}
//		else
//			return 0;
//	}
//	return f(m - 1, n) + f(m, n - 1);
//}
//int main()
//{
//	int m, n, i;
//	while (printf("请输入坐标：(m,n)"), scanf("%d%d", &m, &n) != EOF)
//	{
//		i=f(m, n);
//		printf("有%d种路径走到(%d,%d)\n", i, m, n);
//	}
//	system("pause");
//	return 0;
//}

//学生结构体
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct student {
//	int num;
//	char name[20];
//	float chineseScore;
//	float englishScore;
//	float mathScore;
//}stu,*pstu;
//
//typedef struct sumScore {
//	int num;
//	float sum;
//}sumS;
//
//void printNum(stu s[], int n)//学号递增
//{
//	int i,j;
//	stu temp;
//	for (i = n; i > 0; --i)
//	{
//		for (j = 0; j < i - 1; ++j)
//		{
//			if (s[j].num > s[j+1].num)
//			{
//				temp = s[j];
//				s[j] = s[j + 1];
//				s[j + 1] = temp;
//			}
//		}
//	}
//	printf("按学号递增排序：");
//	for (i = 0; i < n; ++i)
//	{
//		printf("%d ", s[i].num);
//	}
//	printf("\n");
//}
//
//void printScoreMax(stu s[], int n)//每门最高分
//{
//	int max1 = 0, max2 = 0, max3 = 0;
//	int i;
//	for (i = 1; i < n; ++i)
//	{
//		if (s[i].chineseScore > s[max1].chineseScore)
//		{
//			max1 = i;
//		}
//		if (s[i].englishScore > s[max2].englishScore)
//		{
//			max2 = i;
//		}
//		if (s[i].mathScore > s[max3].mathScore)
//		{
//			max3 = i;
//		}
//	}
//	printf("语文最高分的学生为：%s\n", s[max1].name);
//	printf("英语最高分的学生为：%s\n", s[max2].name);
//	printf("数学最高分的学生为：%s\n", s[max3].name);
//}
//
//void printScoreavg(stu s[], int n)//每门平均分
//{
//	float avg1=0, avg2=0, avg3=0;
//	int i;
//	for (i = 0; i < n; ++i)
//	{
//		avg1 += s[i].chineseScore;
//		avg2 += s[i].englishScore;
//		avg3 += s[i].mathScore;
//	}
//	avg1 /= n; avg2 /= n; avg3 /= n;
//	printf("语文平均分：%.2f\n英语平均分：%.2f\n数学平均分：%.2f\n", avg1,avg2,avg3);
//}
//
//void printScorerank(stu s[], int n,sumS a[])//总分排名
//{
//	int i, j;
//	sumS temp;
//	for (i = 0; i < n; ++i)
//	{
//		a[i].sum = s[i].chineseScore + s[i].englishScore + s[i].mathScore;
//	}
//	
//	for (i = n; i > 0; --i)
//	{
//		for (j = 0; j < i - 1; ++j)
//		{
//			if (a[j].sum < a[j+1].sum)
//			{
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//	printf("总分排名:\n");
//	for (i = 0; i < n; ++i)
//	{
//		printf("第%d名%d号,总分%.2f分\n", i + 1, a[i].num, a[i].sum);
//	}
//}
//
//
//
//int main()
//{
//	stu s[5] = { {20,"CC",60,70,73.5},{36,"EE",65,60,80},{15,"AA",59,65,80.5},{17,"BB",77.5,71,70.5},{33,"DD",87,78,69.5} };
//	int i;
//	sumS a[5] = {0};
//	for (i = 0; i < 5; ++i)
//	{
//		a[i].num = s[i].num;
//	}
//	//pstu ps;
//	//ps = s;
//	//s->chineseScore;s[0].chineseScore
//	printNum(s, 5);
//	printScoreMax(s, 5);
//	printScoreavg(s, 5);
//	printScorerank(s, 5, a);
//	system("pause");
//}
//
#include"func.h"



//链表的增删
//int main()
//{
//	DataType val;
//	pNode phead = NULL, ptail = NULL;
//
//	while (scanf("%d", &val) != EOF)
//	{
//		//headInsert(&phead, &ptail, val);
//		tailInsert(&phead, &ptail, val);
//		//sortInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	while (printf("输入要删除的值："),scanf("%d", &val) != EOF)
//	{
//		delVal(&phead, &ptail, val);
//		print(phead);
//	}
//	system("pause");
//	return 0;
//}

// 将两个有序链表合并成一个有序链表。
//int main()
//{
//	pNode phead1, phead2, ptail1, ptail2;
//	phead1 = phead2 = ptail1 = ptail2 = NULL;
//	DataType val;
//	printf("输入第一个链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead1, &ptail1, val);
//	}
//	printf("第一个链表为：");
//	print(phead1);
//	printf("输入第二个链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead2, &ptail2, val);
//	}
//	printf("第二个链表为：");
//	print(phead2);
//	listLink(&phead1, &phead2);
//	printf("\n合成后的链表为：\n");
//	print(phead1);
//
//	system("pause");
//	return 0;
//}

//将一个链表原地逆置。 如： 1->2 ->3 ->4 ->5 ->NULL， 输出: 5 -> 4 -> 3 ->2 ->1 -> NULL 
//int main()
//{
//	pNode phead, ptail;
//	ptail = phead = NULL;
//	DataType val;
//	printf("请输入链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	reList(&phead);
//	pNode pcur = phead;//因为上面逆置的函数没有改变其尾指针,写漏了
//	while (pcur)       //所以单独处理囧
//	{
//		if (NULL == pcur->next)
//		{
//			ptail = pcur;
//			break;
//		}
//		pcur = pcur->next;
//	}
//	pcur = NULL;
//	printf("逆置后：");
//	print(phead);
//	system("pause");
//	return 0;
//}

//找倒数第四
//int main()
//{
//	pNode phead, ptail;
//	DataType val;
//	phead = ptail = NULL;
//	printf("请输入链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	pNode get = lastElem(phead, 4);
//	if (get != NULL)
//	{
//		printf("倒数第%d个结点的值是%3d\n", 4, get->val);
//	}
//	system("pause");
//	return 0;
//}

//找中间
//int main()
//{
//	pNode phead, ptail;
//	phead = ptail = NULL;
//	DataType val;
//	printf("请输入链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	pNode get = midElem(phead);
//	if (get != NULL)
//	{
//		printf("链表中间结点的值是%3d\n", get->val);
//	}
//	system("pause");
//	return 0;
//
//}

//判断有环
//int main()
//{
//	pNode phead1, phead2, ptail1, ptail2;
//	phead1 = phead2 = ptail1 = ptail2 = NULL;
//	DataType val;
//	printf("输入第一个链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead1, &ptail1, val);
//	}
//
//	printf("输入第二个链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead2, &ptail2, val);
//	}
//	ptail2->next = phead2->next->next->next->next;//随便给链表2加环
//
//	printf("链表1%s环\n",isLoop(phead1) == 1 ? "有" : "没有");
//	printf("链表2%s环\n", isLoop(phead2) == 1 ? "有" : "没有");
//	system("pause");
//	return 0;
//}

//判断相交
//int main()
//{
//	pNode phead1, phead2, ptail1, ptail2, phead3, ptail3;
//	phead1 = phead2 = ptail1 = ptail2 = phead3 = ptail3 = NULL;
//	DataType val;
//	pNode pcur;
//	int cnt = 1;
//	printf("输入第一个链表：");//个数要大于等于5，验证用
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead1, &ptail1, val);
//	}
//	printf("第一个链表为：");
//	print(phead1);
//	printf("输入第二个链表：");//个数要大于等于3，验证用
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead2, &ptail2, val);
//	}
//	printf("第二个链表为：");
//	print(phead2);
//
//	printf("输入第三个链表：");//个数要大于1，验证用
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead3, &ptail3, val);
//	}
//
//	ptail3->next = phead1->next->next->next->next;//让链表1与链表3相交,
//	ptail3 = ptail1;
//	printf("第三个链表为：");
//	print(phead3);
//
//	pNode p13 = isIntersect(phead1, phead3);
//	pNode p12 = isIntersect(phead1, phead2);
//
//
//	if (p13 != NULL)
//	{
//		pcur = phead3;
//		while (pcur != p13)
//		{
//			pcur = pcur->next;
//			cnt++;
//		}
//		printf("\n链表1与链表3有相交，交点为链表3第%d个结点，值为%d\n", cnt, p13->val);
//	}
//	else
//		printf("\n链表1与链表3没有相交\n");
//	if (p12 != NULL)
//	{
//		pcur = phead2;
//		while (pcur != p12)
//		{
//			pcur = pcur->next;
//			cnt++;
//		}
//		printf("\n链表1与链表2有相交，交点为链表2第%d个结点，值为%d\n", cnt, p12->val);
//	}
//	else
//		printf("\n链表1与链表2没有相交\n");
//
//	ptail3->next = phead2->next->next; //让链表3与链表2相交
//	ptail3 = ptail2;
//	printf("\n第三个链表更改为：");
//	print(phead3);
//
//	pNode p23 = isIntersect(phead2, phead3);
//	if (p23 != NULL)
//	{
//		cnt = 1;
//		pcur = phead3;
//		while (pcur != p23)
//		{
//			pcur = pcur->next;
//			cnt++;
//		}
//		printf("\n链表2与链表3有相交，交点为链表3第%d个结点，值为%d\n", cnt, p23->val);
//	}
//	else
//		printf("\n链表2与链表3没有相交\n");
//	system("pause");
//	return 0;
//}

//删除单链表重复
//int main()
//{
//	pNode phead, ptail;
//	phead = ptail = NULL;
//	DataType val;
//	printf("请输入链表：");
//
//	while (scanf("%d", &val) != EOF)
//	{
//		tailInsert(&phead, &ptail, val);
//	}
//	print(phead);
//	printf("\n删除重复元素后的链表为：");
//	delDup(phead,&ptail);
//	print(phead);
//	system("pause");
//	return 0;
//}

//按奇偶拆链表
//int main()
//{
//	pNode phead1, phead2, ptail1, ptail2;
//	phead1 = ptail1 = NULL;
//	DataType val;
//	printf("请输入链表：");
//	while (scanf("%d", &val) != EOF)
//	{
//		sortInsert(&phead1, &ptail1, val);
//	}
//	print(phead1);
//	phead2 = phead1; ptail2 = ptail1;
//	listSeparete(&phead1, &phead2, &ptail1, &ptail2);
//	printf("拆分后的链表：\n");
//	print(phead1);
//	reList(&phead2);//要把链表2逆置
//	pNode pcur = phead2;//因为上面逆置的函数没有改变其尾指针,写漏了
//	while (pcur)       //所以单独处理囧
//	{
//		if (NULL == pcur->next)
//		{
//			ptail2 = pcur;
//			break;
//		}
//		pcur = pcur->next;
//	}
//	print(phead2);
//	system("pause");
//	return 0;
//}

int main()
{
	
	system("pause");
	return 0;
}
