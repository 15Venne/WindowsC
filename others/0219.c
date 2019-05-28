//#include<stdio.h>
//void mystrcpy(char *s1, char *s2)
//{
//	int i = 0;
//	while (s2[i] != '\0')
//	{
//		s1[i] = s2[i];
//		i++;
//	}
//	s1[i] = '\0';
//}
//int mystrcmp(char *s1, char *s2)
//{
//	int i = 0;
//	while (s1[i] != '\0' || s2[i] != '\0')
//	{
//		if (s1[i] > s2[i])
//		{
//			return 1;
//		}
//		else if (s1[i] < s2[i])
//		{
//			return -1;
//		}
//		i++;
//	}
//	return 0;
//}
//void mystrcat(char *s1, char *s2)
//{
//	int i = 0;
//	int j = 0;
//	while (s1[i] != '\0')
//	{
//		i++;
//	}
//	while (s2[j] != '\0')
//	{
//		s1[i] = s2[j];
//		i++;
//		j++;
//	}
//}
//int mystrlen(char *s)
//{
//	int i = 0;
//	while (s[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	char s1[15] = { "hello" };
//	char s2[15] = { "world" };
//	char s3[15] = { "how" };
//	char s4[15] = { "how" };
//	printf("%d\n", mystrlen(s1));
//	mystrcat(s1, s2);
//	printf("%s\n", s1);
//	printf("%d %d\n", mystrcmp(s1, s3), mystrcmp(s3, s4));
//	mystrcpy(s4, s1);
//	printf("%s\n", s4);
//	return 0;
//}

//输入一行字符串（单词和若干空格）， 输出该行单词个数。
//#include<stdio.h>
//int main()
//{
//	char s[100];
//	int i,ret;
//	int cnt;
//	printf("输入一行字符串：");
//	while (gets(s) != NULL)
//	{
//		printf("%s\n", s);
//		i = 0; ret = 0; cnt = 0;
//		while (s[i] != '\0')
//		{
//			if (s[i] == ' ')
//			{
//				ret = 0;
//				i++;
//			}
//			else 
//			{
//				if (ret == 0)
//				{
//					cnt++;
//				}
//				ret = 1;
//				i++;
//			}
//		}
//		printf("字符串的单词数量为%d\n", cnt);
//	}
//	return 0;
//}

//输入一行字符串，输出该行单词，每个一行
//#include<stdio.h>
//int main()
//{
//	char s[100];
//	int i, ret;
//	int cnt;
//	printf("输入一行字符串：");
//	while (gets(s) != NULL)
//	{
//		printf("%s\n", s);
//		i = 0; ret = 0; cnt = 0;
//		while (s[i] != '\0')
//		{
//			if (s[i] == ' ')
//			{
//				if (ret == 1)
//				{
//					printf("\n");
//				}
//				ret = 0;
//				i++;
//			}
//			else
//			{
//				printf("%c", s[i]);
//				ret = 1;
//				i++;
//			}
//		}
//	}
//	return 0;
//}
//输入一行字符串，把字符串翻转 

#include<stdio.h>
#include<string.h>
void rePrint(char *s)
{
	int len = strlen(s);
	int i ;
	for (i = len-1; i >= 0; --i)
	{
		printf("%c", s[i]);
	}
}

int main()
{
	char s1[100];
	char s2[100];
	int len,i,j;
	int ret = 0;
	int k=0;
	while (gets(s1) != NULL)
	{
		len = strlen(s1);
		for (i = 0,j = len - 1; i < len ; ++i,--j)
		{
			s2[i] = s1[j];
		}
		s2[i] = '\0';
		printf("%s\n", s2);
		i = 0;
		printf("反转后：");
		while (s2[i] != '\0')
		{
			if (s2[i] == ' ')
			{
				if (ret == 1)
				{
					s1[k] = '\0';
					k = 0;
					rePrint(s1);
				}
				ret = 0;
				printf(" ");
				i++;
			}
			else
			{
				ret = 1;
				s1[k] = s2[i];
				k++;
				i++;
			}
		}
		if (ret == 1)
		{
			s1[k] = '\0';
			k = 0;
			rePrint(s1);
		}

	}
	return 0;
}
