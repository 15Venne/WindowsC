#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<string.h>
#define N 10
#define SWAP(a,b) {int temp=a;a=b;b=temp;}

void arrprint(int*);//输出数组

void adjustMyheap(int*, int, int);//调整最大堆

void myheapSort(int*);//堆排序

int compare(const void*, const void*);

void cntSort(int*);//计数排序

void mergeSort(int*, int, int);//归并排序

void merSort(int *, int, int, int);//两两归并

//输出数组
void arrprint(int *a)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//调整最大堆
void adjustMyheap(int *a, int begin, int end) //***
{
	int parent = begin, son = 2 * parent + 1;
	while (son < end)
	{
		if (son + 1 < end&&a[son] < a[son + 1])
		{
			son++;
		}
		if (a[son] > a[parent])
		{
			SWAP(a[son], a[parent]);
			parent = son;
			son = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//堆排序
void myheapSort(int *a)
{
	int i;
	for (i = N / 2 - 1; i >= 0; --i)
	{
		adjustMyheap(a, i, N);
	}
	SWAP(a[0], a[N - 1]);
	for (i = N - 1; i > 1; --i)
	{
		adjustMyheap(a, 0, i);
		SWAP(a[0], a[i - 1]);
	}
}

//qsort的compare
int compare(const void *a,const void *b)
{
	int *p1 = (int*)a;
	int *p2 = (int*)b;
	if (*p1 > *p2)
		return 1;
	else if (*p1 < *p2)
		return -1;
	else
		return 0;
}

//计数排序
void cntSort(int *a)
{
	int cnt[100] = { 0 };
	int i, j, k=0;
	for (i = 0; i < N; ++i)
	{
		cnt[a[i]]++;
	}
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < cnt[i]; ++j)
		{
			a[k] = i;
			k++;
		}
	}
}

//归并排序
void merSort(int *a, int left, int mid, int right)
{
	int i, j, k;
	int temp[N];
	for (i = left; i <= right; ++i)
	{
		temp[i] = a[i];
	}
	k = left;
	for (i = left, j = mid + 1; i <= mid && j <= right; ++k)
	{
		if (temp[i] < temp[j])
		{
			a[k] = temp[i];
			i++;
		}
		else
		{
			a[k] = temp[j];
			j++;
		}
	}
	while (i <= mid)
	{
		a[k] = temp[i];
		k++; i++;
	}
	while (j <= right)
	{
		a[k] = temp[j];
		k++; j++;
	}
}
void mergeSort(int* a,int left,int right)
{
	if (left<right)
	{

		mergeSort(a, left, (right + left) / 2);
		mergeSort(a, (right + left) / 2 + 1, right);
		merSort(a, left, (right + left) / 2, right);
	}
}


int main()
{
	int *a;
	a = (int*)calloc(N, sizeof(int));
	int i;
	time_t start, end;
	srand(time(NULL));
	for (i = 0; i < N; ++i)
	{
		a[i] = rand() % 100;
	}
	//arrprint(a);
	start = time(NULL);
	//myheapSort(a); //¶ÑÅÅÐò
	//qsort(a, N, sizeof(int), compare); //¿ìÅÅ
	//cntSort(a);//¼ÆÊýÅÅÐò
	mergeSort(a,0,N-1);
	printf("ÅÅÐòºó£º\n");
	//arrprint(a);
	end = time(NULL);
	printf("use time=%d\n", (int)(end - start));
	system("pause");
	return 0;
}
