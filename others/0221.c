#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二级指针服务于指针数组的偏移
void print(char **p,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		puts(p[i]);
	}
}
//打印二维数组
void printArr(char (*p)[10],int row)
{
	int i;
	for(i=0;i<row;i++)
	{
		puts(p[i]);
	}
}
int main()
{
	char b[5][10]={"lele","xiongda","hanmeimei","lilei","ThinkPad"};
	char **p;
	char *tmp;
	int i,j;
	p=(char**)malloc(20);//一级指针强制转换为二级指针，使用动态的指针数组
	for(i=0;i<5;i++)
	{
		p[i]=b[i];
	}
	print(p,5);
	printf("-----------------------------\n");
	for(i=5;i>1;i--)
	{
		for(j=0;j<i-1;j++)
		{
			if(strcmp(p[j],p[j+1])>0)
			{
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}
		}
	}
	print(p,5);
	printf("-----------------------------\n");
	printArr(b,5);
	system("pause");
}
