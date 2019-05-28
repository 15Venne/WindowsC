#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define SWAP(a,b) {int tmp;tmp=a;a=b;b=tmp;}

void selectSort(int*);

void insertSort(int*);

void quickSort(int*, int, int);

void arrprint(int*);

void selectSort(int *a)
{
	int i, j, k;
	int max;
	for (i = N - 1; i > 0; --i)
	{
		max = a[0];
		k = 0;
		for (j = 1; j <= i; ++j)
		{
			if (a[j] > max)
			{
				max = a[j];
				k = j;
			}
		}
		SWAP(a[k], a[i]);
	}
}

void insertSort(int *a)
{
	int i, j, k;
	int temp;
	for (i = 1; i < N; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				for (k = i; k > j; --k)
				{
					a[k] = a[k - 1];
				}
				a[j] = temp;
			}
		}
	}
}

int partition(int *a, int left, int right)
{
	int temp = a[left];
	int i = left; left++;
	while (left <= right)
	{
		if (a[left] <= temp)
		{
			left++;
		}
		else
		{
			if (a[right] >= temp)
			{
				right--;
			}
			else
			{
				SWAP(a[left], a[right]);
				left++;
				right--;
			}
		}
	}
	SWAP(a[i], a[right]);
	return right;
}

void quickSort(int *a, int left, int right)
{
	int pivot;
	if (left < right)
	{
		pivot = partition(a, left, right);
		quickSort(a, left, pivot - 1);
		quickSort(a, pivot + 1, right);
	}
}

void arrprint(int *a)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		printf("%3d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int *a;
	int i;
	a = (int*)malloc(N * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < N; ++i)
	{
		a[i] = rand() % 100;
	}
	arrprint(a);
	//selectSort(a);
	//insertSort(a);
	quickSort(a, 0, N - 1);
	printf("ÅÅÐòºó£º\n");
	arrprint(a);

	system("pause");
	return 0;
}
