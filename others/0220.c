//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char s[100];
//	char *p, *q, *o;//p指向数字，q指向字母
//	while (printf("输入字符串："),rewind(stdin),gets(s) != NULL)
//	{
//		p = s; q = s + 1;
//		char temp;
//		while (*q != '\0'/*&& *p != '\0'*/)
//		{
//			while (*p >= '0'&&*p <= '9')
//			{
//				p++;
//				q++;
//			}
//			temp = *p;
//			if (*q >= '0'&&*q <= '9')
//			{
//				*p = *q;
//				*q = temp;
//				p++;
//				o = p;
//				while (o != q)
//				{
//					temp = *o;
//					*o = *q;
//					*q = temp;
//					o++;
//				}
//				q++;
//			}
//			else
//			{
//				q++;
//			}
//		}
//	    printf("排序后：%s\n", s);
//		/**q = '\0';*/
//		memset(s, 0, sizeof(s));
//	}
//	system("pause");
//	return 0;
//}

//将 字 符 串 中 的 空 格 替 换 成 “%020”

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char s[100];
//	char *p,*q;
//	char temp;
//	while (printf("请输入带空格的字符串："), gets(s) != NULL)
//	{
//		p = s;
//		while (*p != '\0')
//		{
//			if (*p != ' ')
//			{
//				p++;
//			}
//			else
//			{
//				q = &s[strlen(s)-1];
//				*(q + 4) = '\0';
//				while (q != p )
//				{
//					*(q + 3) = *q;
//					q--;
//				}
//				*p = '%';
//				*(p + 1) = '0';
//				*(p + 2) = '2';
//				*(p + 3) = '0';
//				p+=4;
//
//			}
//		}
//		printf("%s\n", s);
//		memset(s, 0, sizeof(s));
//	}
//	system("pause");
//	return 0;
//}

//删除字符串中指定的字符。 例如 “abcdaefaghiagkl“ 删除‘a’, 以后

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char s[100];
//	char *p, *q;
//	while (printf("请输入带a的字符串："), gets(s) != NULL)
//	{
//		p = s;
//		while (*p != '\0')
//		{
//			if (*p != 'a')
//			{
//				p++;
//			}
//			else
//			{
//				q = p;
//				while (*q != '\0')
//				{
//					*q = *(q + 1);
//					q++;
//				}
//				p++;
//			}
//		}
//		printf("删除a后的字符串：%s\n", s);
//		memset(s, 0, sizeof(s));
//	}
//	system("pause");
//	return 0;
//}

//删除一个数组中重复的元素
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr[] = { 1,2,2,2,3,3,3,4,4,5,5,5,6,6,2 };
//	int len = sizeof(arr) / sizeof(int);
//	int i, j, k;
//	for (i = 0; i < len - 2; ++i)
//	{
//		j = i + 1;
//		while (j < len - 1)
//		{
//			if (arr[i] != arr[j])
//			{
//				j++;
//			}
//			else
//			{
//				for (k = j; k < len - 2; ++k)
//				{
//					arr[k] = arr[k + 1];
//				}
//				arr[k] = 0;
//				len--;
//			}
//		}
//	}
//	for (i = 0; i < len - 1; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//将 字 符 串 中 的 相 邻 的 多 余 空 格 去 掉
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char s[100];
//	char *p, *q;
//	int ret = 0;
//	while (printf("输入带多余空格的字符串："), gets(s) != NULL)
//	{
//		p = s;
//		while (*p != '\0')
//		{
//			if (*p != ' ')
//			{
//				ret = 1;
//				p++;
//			}
//			else
//			{
//				if (1 == ret)
//				{
//					ret = 0;
//					p++;
//				}
//				else
//				{
//					q = p;
//					while (*q != '\0')
//					{
//						*q = *(q + 1);
//						q++;
//					}
//				}
//			}
//		}
//		printf("删除多余空格后：%s\n", s);
//		memset(s, 0, sizeof(s));
//	}
//	system("pause");
//	return 0;
//}

//求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big1,char** big2)

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void big(char *arr[], int size, char** big1, char** big2)
//{
//	
//	int i;
//	for (i = 1; i < size ; ++i)
//	{
//		if (1 == strcmp(arr[i], *big1))
//		{
//			*big1 = arr[i];
//		}
//	}
//	for (i = 1; i < size ; ++i)
//	{
//		if (1 == strcmp(arr[i], *big2) && arr[i] != *big1)
//		{
//			*big2 = arr[i];
//		}
//	}
//	printf("最大值为%s,次大值为%s\n", *big1, *big2);
//}
//int main()
//{
//	char *b[15] = { {"hello"},{"how"},{"world"},{"helloo"},{"however"},{"worldddd"} };
//	char *big1=b[0], *big2=b[0];
//	big(b, 6, &big1, &big2);
//	system("pause");
//	return 0;
//}

//大整数加法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void jinWei(char *s,int i)//进位
{
	if (0 == i && s[i] > '9')
	{
		int len ;
		for (len = strlen(s); len > 1; --len)
		{
			s[len] = s[len - 1];
		}
		s[1] = s[0] - 10;
		s[0] = '1';
	}
	else if (s[i] > '9')
	{
		s[i] = s[i] - 10;
		s[i - 1]++;
	}
}
void jieWei(char *s, int i)//借位
{
	if (s[i] < '0' )
	{
		s[i] = s[i] + 10;
		s[i - 1]--;
	}
}
void myPlus(const char *s1, const char *s2, char *s3,int m,int n)//加法
{
	int len3 = strlen(s3);
	int i;
	for (i = len3; i > 0; --i)
	{
		s3[i] = s3[i - 1];
	}
	s3[0] = s1[m] + s2[n] - 48;
}
void myMinus(const char *s1, const char *s2, char *s3, int m, int n)//减法
{
	int len3 = strlen(s3);
	int i;
	for (i = len3; i > 0; --i)
	{
		s3[i] = s3[i - 1];
	}
	s3[0] = s1[m] - s2[n] + 48;
}
void sum(char *s1,char *s2, char *s3)
{
	int len1 = strlen(s1), len2 = strlen(s2);
	int ret = 0, i;
	if ((s1[0] == '-'&&s2[0] == '-') || s1[0] != '-'&&s2[0] != '-') //两个正数相加，两个负数相加
	{
		if (s1[0] == '-'&&s2[0] == '-')
		{
			ret = 1; //记录这是两个负数，下面删除负号
			for (i = 0; i < len1; ++i)
			{
				s1[i] = s1[i + 1];
			}
			for (i = 0; i < len2; ++i)
			{
				s2[i] = s2[i + 1];
			}
		}
		while (len1 > 0 || len2 > 0) //开始做加法
		{
			if (len1 > 0 && len2 > 0)//从个位，十位，百位依次加赋值给s3
			{
				myPlus(s1, s2, s3, len1 - 1, len2 - 1);
				len1--; len2--;
			}
			//若一个数比另外一个数长
			else if (len1 <= 0 && len2 > 0)
			{
				myPlus("0", s2, s3, 0, len2 - 1);
				len2--;
			}
			else if (len1 > 0 && len2 <= 0)
			{
				myPlus(s1, "0", s3, len1 - 1, 0);
				len1--;
			}//加法完毕
		}
		int len3;//下面进位s3
		for (len3 = strlen(s3) - 1; len3 >= 0; --len3)
		{
			jinWei(s3, len3);
		}
		if (ret == 1) //若是两负数，加回负号
		{
			for (len3 = strlen(s3); len3 > 0; --len3)
			{
				s3[len3] = s3[len3 - 1];
			}
			s3[0] = '-';
			s3[strlen(s3) - 1] = '\0';
		}
	}
	else //一正一负
	{
		int big;
		if (s1[0] == '-'&&s2[0] != '-')//去掉s1或s2的负号
		{
			big = 2;
			for (i = 0; i < len1; ++i) 
			{
				s1[i] = s1[i + 1];
			}
			len1--;
		}
		else if (s2[0] == '-'&&s1[0] != '-')
		{
			big = 1;
			for (i = 0; i < len2; ++i)
			{
				s2[i] = s2[i + 1];
			}
			len2--;
		}
		char temp[50]; int te;
		ret = 0;//记录有没有排序过
		if (len1 < len2)          //给s1s2排序，大的给s1，好做减法
		{
			strcpy(temp, s1);
			strcpy(s1, s2);
			strcpy(s2, temp);
			te = len1; len1 = len2; len2 = te;
			ret = 1;//表示有排序过
		}
		else if (len1 == len2)
		{
			for (i = 0; i < len1; ++i)
			{
				if (s1[i] < s2[i])
				{
					strcpy(temp, s1);
					strcpy(s1, s2);
					strcpy(s2, temp);
					te = len1; len1 = len2; len2 = te;
					ret = 1;
					break;
				}
				else if(s1[i]>s2[i])
				{
					break;
				}
			}
		}//排序结束，下面减法
		while (len1 > 0 || len2 > 0)
		{
			if (len1 > 0 && len2 > 0)
			{
				myMinus(s1, s2, s3, len1 - 1, len2 - 1);
				len1--; len2--;
			}
			else if (len1 > 0 && len2 <= 0)
			{
				myMinus(s1, "0", s3, len1 - 1, 0);
				len1--;
			}
		}
		//减法结束，下面借位
		int len3, j;
		for (len3 = strlen(s3) - 1; len3 >= 0; --len3)
		{
			jieWei(s3, len3);//借位
		}
		//s3前有零的情况，i记录有多少个零
		for (i = 0; i < strlen(s3); ++i)
		{
			if (s3[i] != '0')
			{
				break;
			}
		}
		if (i == strlen(s3)) //s3刚好全是零
		{
			s3[1] = '\0';
		}
		else 
		{
			if (i != 0 )//有零的情况，把零去掉
			{
				for (j = 0; i < strlen(s3); ++j, ++i)
				{
					s3[j] = s3[i];
				}
				s3[j] = '\0';
			}
			if (ret + big == 2)//正数比负数小，要加回负号
			{
				for (len3 = strlen(s3); len3 > 0; --len3)
				{
					s3[len3] = s3[len3 - 1];
				}
				s3[0] = '-';
			}
			s3[strlen(s3)] = '\0';
		}
	}
}
int main()
{
	char s1[50], s2[50], s3[60] = {0};
	
	while (printf("输入两个整数(50位以内)：\n"),rewind(stdin), gets(s1) != NULL && gets(s2) != NULL)
	{
		sum(s1, s2, s3);
		printf("两数之和为：\n%s\n", s3);
		memset(s3, 0, sizeof(s3));
	}
	system("pause");
	return 0;
}
