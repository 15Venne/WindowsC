#include<stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
//1
//int fun(int score[],int n,int below[])
//{
//	int sum = 0;
//	for (int i = 0; i < n; ++i)
//		sum += score[i];
//	int avg = sum / n;
//	int j = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (score[i] < avg)
//		{
//			below[j] = score[i];
//			j++;
//		}
//	}
//	return j;
//}
//
//int main()
//{
//	int score[9] = { 10,20,30,40,50,60,70,80,90 };
//	int below[9];
//	int j = fun(score,9,below);
//	printf("%d\n", j);
//	for (int i = 0; i < j; ++i)
//		printf("%d ", below[i]);
//	return 0;
//}

//2
//int fun(int num,int a[])
//{
//	int j = 0;
//	for(int i=7;i<num;++i)
//		if ((i % 7 == 0 || i % 11 == 0) && i % 77 != 0)
//		{
//			a[j] = i;
//			j++;
//		}
//	return j;
//}
//
//int main()
//{
//	int a[1000];
//	int n = fun(1000, a);
//	printf("个数为：%d\n", n);
//	for (int i = 0; i < n; ++i)
//		printf("%d ", a[i]);
//	return 0;
//}

//3
//void fun(int x, int pp[], int *n)
//{
//	*n = 0;
//	for(int i = 1; i <= x; i=i+2)
//	{
//		if (x%i == 0)
//		{
//			pp[*n] = i;
//			(*n)++;
//		}
//	}
//}
//
//int main()
//{
//	int pp[30];
//	int n;
//	fun(30, pp, &n);
//	for (int i = 0; i < n; i++)
//		printf("%d ", pp[i]);
//	return 0;
//}
//4
//void fun(char *tt, int pp[])
//{
//	int i = 0;
//	while (tt[i] != '\0')
//	{
//		switch (tt[i])
//		{
//		case 'a':pp[0]++; break; case 'b':pp[1]++; break; case 'c':pp[2]++; break;
//		case 'd':pp[3]++; break; case 'e':pp[4]++; break; case 'f':pp[5]++; break;
//		case 'g':pp[6]++; break; case 'h':pp[7]++; break; case 'i':pp[8]++; break;
//		case 'j':pp[9]++; break; case 'k':pp[10]++; break; case 'l':pp[11]++; break;
//		case 'm':pp[12]++; break; case 'n':pp[13]++; break; case 'o':pp[14]++; break;
//		case 'p':pp[15]++; break; case 'q':pp[16]++; break; case 'r':pp[17]++; break;
//		case 's':pp[18]++; break; case 't':pp[19]++; break; case 'u':pp[20]++; break;
//		case 'v':pp[21]++; break; case 'w':pp[22]++; break; case 'x':pp[23]++; break;
//		case 'y':pp[24]++; break; case 'z':pp[25]++; break;
//		default:
//			break;
//		}
//		i++;
//	}
//}
//
//int main()
//{
//	char *tt = "abcdefgabcdeabc";
//	int pp[26] = {0};
//	fun(tt, pp);
//	for (int i = 0; i < 26; ++i)
//		printf("%d ", pp[i]);
//	return 0;
//}
//5
//int isPrime(int n)
//{
//	int is = 1;
//	int m = (int)sqrt((double)n );
//	for (int i = 2; i <= m; ++i)
//	{
//		if (n%i == 0)
//		{
//			is = 0;
//			break;
//		}
//	}
//	return is;
//}
//
//void fun(int m, int k, int xx[])
//{
//	int cnt = 0;
//	for (int i = m + 1; cnt < k; ++i)
//	{
//		if (isPrime(i) == 1)
//		{
//			xx[cnt] = i;
//			cnt++;
//		}
//	}
//}
//
//int main()
//{
//	int xx[5] = { 0 };
//	fun(17, 5, xx);
//	for (int i = 0; i < 5; ++i)
//		printf("%d ", xx[i]);
//	return 0;
//}

//6
//void fun(char a[], char b[], int n)
//{
//	for (int i = 0; i < n; ++i)
//		b[i] = a[i];
//	int lengtha = 0;
//	while (a[lengtha] != '\0')
//		lengtha++;
//	for (int i = n + 1; i < lengtha; ++i)
//		b[i-1] = a[i];
//	b[lengtha] = '\0';
//}
//
//int main()
//{
//	char *a = "World", b[6] = {0};
//	fun(a, b, 3);
//	printf("%s", b);
//	return 0;
//}

//7
//int fun(int *s, int t, int *k)
//{
//	int max = 0;
//	for (int i = 0; i < t; ++i)
//	{
//		if (s[i] > max)
//		{
//			max = s[i];
//			*k = i;
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	int s[10]={ 876, 675, 896, 101, 301, 401, 980, 431, 451, 777 };
//	int k=0;
//	int max = fun(s, 10, &k);
//	printf("%d, %d", k, max);
//	return 0;
//}
//8

//int sum(int n)
//{
//	if(n==1)
//		return 1;
//	else 
//		return n + sum(n - 1);
//}
//
//double fun(int n)
//{
//	double S=0;
//	for (int i = 1; i <= n; ++i)
//		S = S + 1.0/sum(i);
//	return S;
//}
//
//int main()
//{
//	double S = fun(11);
//	printf("%f", S);
//}

//9
//double fun(int m, int n)
//{
//	if (m <= n)
//		return -1;
//	else
//	{
//		int temp = m;
//		double p = temp/(temp-n);
//		for (int i = 2; i <= (m - n); ++i, --temp)
//			p = p * (temp - 1) / (temp - 1 - n);
//		return p;
//	}
//}
//int main()
//{
//	double p = fun(12, 8);
//	printf("%f ", p);
//}

//10
//double fun() {
//	double x1 = 0, x0;
//	do {
//		x0 = x1;
//		x1 = cos(x0);
//	} while (fabs(x0 - x1) >= 0.000001);
//
//	return x1;
//}
//
//int main()
//{
//	printf("%f", fun());
//	return 0;
//}

//11
//void fun(int a[][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			a[i][j] = 0;
//		}
//	}
//}
//int main()
//{
//	int a[3][3] = { 1,9,7,
//				    2,3,8,
//				    4,5,6 };
//	fun(a);
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//	return 0;
//} 

//12
//void fun(int a[][5],double *s)
//{
//	double s1 = 0, s2 = 0, s3 = 0, s4 = 0, sum;
//	for (int i = 0; i < 5; ++i)
//	{
//		s1 += a[0][i];
//		s2 += a[i][0];
//		s3 += a[4][i];
//		s4 += a[i][4];
//	}
//	sum = s1 + s2 + s3 + s4 - a[0][0] - a[0][4] - a[4][0] - a[4][4];
//	*s = sum / (5 * 4 - 4);
//}
//
//int main()
//{
//	int a[5][5] = { 0,1,2,7,9,
//				    1,9,7,4,5,
//				    2,3,8,3,1,
//		            4,5,6,8,2,
//				    5,9,1,4,1 };
//	double s;
//	fun(a, &s);
//	printf("%f ", s);
//	return 0;
//}

//13
//void fun(int tt[5][4],int pp[4])
//{
//	int min;
//	for (int i = 0; i < 4; ++i)
//	{
//		min = tt[0][i];
//		for (int j = 1; j < 5; ++j)
//		{
//			if (tt[j][i] < min)
//			{
//				min = tt[j][i];
//			}
//		}
//		pp[i] = min;
//	}
//}
//
//int main()
//{
//	int pp[4];
//	int tt[5][4] = { 0,2,2,3,
//	                 3,0,3,3,
//	                 4,4,0,2,
//	                 5,5,1,0};
//	fun(tt, pp);
//	for (int i = 0; i < 4; ++i)
//	{
//		printf("%d ", pp[i]);
//	}
//	return 0;
//}

//14
//int fun(int a[4][5])
//{
//	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, sum;
//	for (int i = 0; i < 5; ++i)
//	{
//		s1 += a[0][i];
//		s3 += a[3][i];
//	}
//	for (int i = 0; i < 4; ++i)
//	{
//		s2 += a[i][0];
//		s4 += a[i][4];
//	}
//	sum = s1 + s2 + s3 + s4 - a[0][0] - a[0][4] - a[3][0] - a[3][4];
//	return sum;
//}
//
//int main()
//{
//	int a[4][5] = {1,3,5,7,9,
//		           2,9,9,9,4,
//		           6,9,9,9,8,
//	               1,3,5,7,0};
//	printf("%d ", fun(a));
//	return 0;
//}

//15
//unsigned fun(unsigned w)
//{
//	if (w <= 10)
//		return -1;
//	else
//	{
//		unsigned s = 1, temp = w;
//		while (temp / 10 != 0)
//		{
//			s *= 10;
//			temp = temp / 10;
//		}
//		return w%s;
//	}
//}
//
//int main()
//{
//	unsigned w1 = 5923, w2 = 923, w3 = 23;
//	printf("%u ,%u, %u", fun(w1), fun(w2), fun(w3));
//}

//16
//float fun(double h)
//{
//	h *= 100;
//	h += 0.5;
//	h = (int)h;
//	return (float)h /100;
//}
//
//int main()
//{
//	double h1 = 8.32433, h2 = 8.32533;
//	printf("%f ,%f ", fun(h1), fun(h2));
//}

//17

//void fun(char *s)
//{
//	int len = strlen(s);
//	char temp;
//	for (int i = 0, j = len - 1; i < j; ++i, --j)
//	{
//		temp = s[i];
//		s[i] = s[j];
//		s[j] = temp;
//	}
//}
//
//int main()
//{
//	char s[] = "abcdefg";
//	fun(s);
//	printf("%s ", s);
//	return 0;
//}

//18
//void fun(int a[3][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			if (i != j)
//			{
//				int temp;
//				temp = a[i][j];
//				a[i][j] = a[j][i];
//				a[j][i] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[3][3] = { 100,200,300,
//	                400,500,600,
//	                700,800,900};
//	fun(a);
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//19
//int fun(char *ch,char a)
//{
//	int cnt = 0;
//	int len = strlen(ch);
//	for (int i = 0; i < len; ++i)
//	{
//		if (ch[i] == a)
//		{
//			for (int j = i; j < len-1; ++j)
//			{
//				ch[j] = ch[j + 1];
//			}
//			ch[len - 1] = '\0';
//			len--;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	char ch[] = "turbo c and borland c++";
//	int cnt=fun(ch, 'n');
//	printf("被删了%d 个。\n", cnt);
//	printf("%s ", ch);
//	return 0;
//}

//20
//int isPrime(int n)
//{
//	int is = 1;
//	int m = (int)sqrt((double)n);
//	for (int i = 2; i <= m; ++i)
//	{
//		if (n%i == 0)
//		{
//			is = 0;
//			break;
//		}
//	}
//	return is;
//}
//
//int fun(int lim, int aa[])
//{
//	int cnt = 0;
//	if (lim < 2)
//		return cnt;
//	else
//	{
//		aa[0] = 2;
//		for (int i = 3; i <= lim; i=i+2)
//		{
//			if (isPrime(i) == 1)
//			{
//				cnt++;
//				aa[cnt] = i;
//			}
//		}
//		return cnt + 1;
//	}
//}
//
//int main()
//{
//	int aa1[2] = { 0 }, aa2[10] = { 0 }, aa3[200] = {0};
//	int n1 = fun(2, aa2), n2 = fun(10, aa2), n3 = fun(200, aa3);
//	printf("n1=%d ,n2=%d ,n3=%d \n", n1, n2, n3);
//	for (int i = 0; i < n3; ++i)
//		printf("%d ", aa3[i]);
//	return 0;
//}

//21
//void fun(char *ch)
//{
//	int len = strlen(ch);
//	for (int i = 1; i < len - 1; ++i)
//	{
//		char temp = ch[i];
//		char max = ch[i];
//		int k = i;
//		for (int j = i + 1; j < len - 1; ++j)
//		{
//			if (ch[j] > max)
//			{
//				max = ch[j];
//				k = j;
//			}
//		}
//		ch[i] = ch[k];
//		ch[k] = temp;
//	}
//}
//
//int main()
//{
//	char ch[] = "CEAedca";
//	fun(ch);
//	printf("%s ", ch);
//	return 0;
//}

//22
//typedef struct LNode
//{
//	int data;
//	struct LNode *p;
//}LNode;

//int fun(LNode *h)
//{
//	h=h->next;
//	int max;
//	while (h->data > max)
//	{
//		max = h->data;
//		h = h->next;
//	}
//	return max;
//}

//23
//int fun(char *ch)
//{
//	int is = 1;
//	int len = strlen(ch);
//	for (int i = 0, j = len - 1; i < j; ++i, --j)
//	{
//		if (ch[i] != ch[j])
//		{
//			is=0;
//			break;
//		}
//	}
//	return is;
//}
//
//int main()
//{
//	char ch1[]="LEVEL",ch2[]="123312";
//	printf("LEVEL是否回文： ");
//	if (fun(ch1) == 1)
//	{
//		printf("YES\n");
//	}
//	else printf("NO\n");
//
//	printf("123312是否回文： ");
//	if (fun(ch2) == 1)
//	{
//		printf("YES\n");
//	}
//	else printf("NO\n");
//	return 0;
//}

//24
//int fun(char *ch)
//{
//	if (ch[0] != '-')
//	{
//		int num = 0;
//		for (int i = 0; i <= strlen(ch) - 1; ++i) {
//			num = num * 10 + ch[i] - '0';
//		}
//		return num;
//	}
//	else
//	{
//		int num = 0;
//		for (int i = 1; i <= strlen(ch) - 1; ++i) {
//			num = num * 10 + ch[i] - '0';
//		}
//		return num-2*num;
//	}
//}
//
//int main()
//{
//	char ch[] = "-1234";
//	printf("%d ", fun(ch));
//	return 0;
//}

//25
//char *fun(char *ch1, char *ch2)
//{
//	int len1 = 0, len2 = 0;
//	while (ch1[len1] != '\0') 
//	{
//		len1++;
//	}
//	while (ch2[len2] != '\0')
//	{
//		len2++;
//	}
//	if (len1 >= len2)
//		return ch1;
//	else return ch2;
//}
//
//int main()
//{
//	char ch1[] = "beijing", ch2[] = "shanghai";
//	printf("%s ", fun(ch1, ch2));
//	return 0;
//}

//26
//double fun()
//{
//	double s = 1, sum = 0;
//	for (int i = 1, j = 3; s > 0.0005; ++i, j = j + 2)
//	{
//		sum = sum + s;
//		s = s * i / j;
//	}
//	return sum;
//}
//
//int main()
//{
//	printf("%f ", fun());
//	return 0;
//}

//27
//int fun(int n,int a[])
//{
//	int cnt = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (i % 7 == 0 || i % 11 == 0)
//		{
//			a[cnt] = i;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	int a[50], m = 50;
//	int n = fun(m, a);
//	printf("n=%d \n", n);
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//28
//void fun(int x[], int n, int *max, int *index)
//{
//	for (int i = 1; i < n; ++i)
//	{
//		if (x[i] > *max)
//		{
//			*max = x[i];
//			*index = i;
//		}
//	}
//}
//
//int main()
//{
//	int x[10] = { 1,2,3,4,5,6,7,8,9,15 }, n = 10;
//	int max = x[1], index = 0;
//	fun(x, n, &max, &index);
//	printf("最大值为：%d,最大值的下标为%d。", max, index);
//	return 0;
//}

//void fun(char *ss)
//{
//	int len = strlen(ss);
//	for (int i = 1; i < len; i=i+2)
//	{
//		if (ss[i] <= 'z'&&ss[i] >= 'a')
//		{
//			ss[i] = ss[i] - 32;
//		}
//	}
//}
//int main()
//{
//	char ss[] = "abc4EFg";
//	fun(ss);
//	printf("%s ", ss);
//}
//30
//int fun(int a[][2])
//{
//	int max=a[0][0];
//	for(int i=0;i<4;++i)
//		for (int j = 0; j < 2; ++j)
//		{
//			if (a[i][j] > max)
//			{
//				max = a[i][j];
//
//			}
//		}
//	return max;
//}
//
//int main()
//{
//	
//	int a[4][2] = {1,1,
//	               2,2,
//	               3,15,
//	               4,4};
//	int max = fun(a);
//	printf("max=%d ", max);
//	return 0;
//}
//31,32
//void fun(char *s, char *t)
//{
//	for (int i = 1, j = 0; i < strlen(s); i = i + 2)
//	{
//		if (s[i] % 2 == 1)
//		{
//			t[j] = s[i];
//			j++;
//		}
//	}
//}
//
//int main()
//{
//	char s[] = "ABCDEFG12345", t[11] = { 0 };
//	fun(s, t);
//	printf("%s ", t);
//}

//33
//void fun(char *ch,int n)
//{
//	int i = 0;
//	while (ch[i] != '\0')
//	{
//		i++;
//	}
//	int cnt = 0, len = i;
//	while (ch[i - 1] == '*')
//	{
//		cnt++;
//		i--;
//		if (cnt > n)
//		{
//			ch[len-1] = '\0';
//			len--;
//		}
//	}
//}
//
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	int n = 4;
//	fun(ch, n);
//	printf("%s ", ch);
//	return 0;
//}

//34
//typedef struct
//{
//	int stuedentData, score;
//}studentScore;
//
//int fun(studentScore s[],int n,int h[],int *max)
//{
//	int cnt = 1;
//	for (int i = 1; i < n; ++i)
//	{
//		if (s[i].score > *max)
//		{
//			*max = s[i].score;	
//			cnt = 1;
//		}
//		else if(s[i].score==*max)
//		{
//			cnt++;
//		}
//	}
//	for (int i = 0, j = 0; j < cnt; ++i)
//	{
//		if (s[i].score == *max)
//		{
//			h[j] = s[i].stuedentData;
//			j++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	studentScore s[8] = { {1,60},{2,70},{3,80},{4,95},{5,95},{6,75},{7,95},{8,80} };
//	int h[8] = { 0 };
//	int max = s[0].score;
//	int cnt = fun(s, 8, h,&max);
//	printf("最高分的学生人数：%d。\n最高分为：%d。\n学生数据： ", cnt,max);
//	for (int i = 0; i < cnt; ++i)
//	{
//		printf("%d ", h[i]);
//	}
//	return 0;
//}
//35
//int fun(char *ch)
//{
//	int cnt = 0;
//	int len = strlen(ch);
//	for (int i = 0; i < len; ++i)
//	{
//		if (ch[i] == 32)
//		{
//			for (int j = i; j < len - 1; ++j)
//			{
//				ch[j] = ch[j + 1];
//			}
//			ch[len - 1] = '\0';
//			len--;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	char ch[] = "asd af aa z67";
//	int cnt = fun(ch);
//	printf("%s ", ch);
//	printf("\n被删了%d个空格。", cnt);
//	return 0;
//}

//36
//void fun(char *ch)
//{
//	int len = 0;
//	while (ch[len] != '\0')
//	{
//		len++;
//	}
//	int temp=len++;
//	while (ch[0] == '*')
//	{
//		for (int i = 0; i < temp-1; i++)
//		{
//			ch[i] = ch[i + 1];
//			ch[temp - 1] = '*';
//		}
//		temp--;
//	}
//}
//
//int main()
//{
//	char ch[] = "*******A*BC*DEF*G****";
//	fun(ch);
//	printf("%s ", ch);
//	return 0;
//}

//37
//typedef struct
//{
//	int id;
//	double score[8];
//	double avg;
//}studentData;
//
//void fun(studentData *s)
//{
//	double sum = 0;
//	for (int i = 0; i < 8; ++i)
//	{
//		sum += s->score[i];
//	}
//	double avg = sum / 8;
//	s->avg = avg;
//}
//
//int main()
//{
//	studentData stuData = { 15,{85.5,76,69.5,85,91,72,64.5,87.5} };
//	fun(&stuData);
//	printf("平均分为：%f ", stuData.avg);
//	return 0;
//}

//38
//int fun(char *ss,char a)
//{
//	int cnt = 0;
//	for (int i = 0; i < strlen(ss); ++i)
//	{
//		if (ss[i] == a)
//		{
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	char ss[] = "123412132";
//	char a = '1';
//	printf("%d ", fun(ss, a));
//	return 0;
//}

//39
//void fun(int a[],int n,int p)
//{
//	for (int i = 0; i <= p; ++i)
//	{
//		int temp = a[0];
//		for (int j = 0; j < n-1; ++j)
//		{
//			a[j] = a[j + 1];
//		}
//		a[n - 1] = temp;
//	}
//}
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	fun(a,10,3);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d, ", a[i]);
//	}
//	return 0;
//}
//40
//void fun(char *ch, int m)
//{
//	int n = strlen(ch);
//	for (int i = 0; i < m; ++i)
//	{
//		char temp = ch[0];
//		for (int j = 0; j < n - 1; ++j)
//		{
//			ch[j] = ch[j + 1];
//		}
//		ch[n-1] = temp;
//	}
//}
//
//int main()
//{
//	char ch[] = "ABCDEFGHIJK";
//	fun(ch, 3);
//	printf("%s ", ch);
//	return 0;
//}

//41
//void fun(char a[3][4], char *b)
//{
//	int bi = 0;
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			b[bi] = a[j][i];
//			bi++;
//		}
//	}
//}
//int main()
//{
//	char a[3][4] = {'W','W','W','W',
//	                'S','S','S','S',
//	                'H','H','H','H'};
//	char b[15] = { 0 };
//	fun(a, b);
//	printf("%s ", b);
//	return 0;
//}

//42
//void fun(int a[][3], int m)
//{
//	int k = 0;
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 3 - 1; j >= k; --j)
//		{
//			a[i][j] *= m;
//		}
//		k++;
//	}
//}
//int main()
//{
//	int a[3][3] = { 1,9,7,2,3,8,4,5,6 };
//	int m = 2;
//	fun(a, m);
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			printf("%d\t", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//43
//void fun(char ch[][15], int num,char **max)
//{
//	int maxlen = 0;
//	for (int i = 0; i < num; ++i)
//	{
//		if (strlen(ch[i]) > maxlen)
//		{
//			maxlen = strlen(ch[i]);
//			*max = ch[i];
//		}
//	}
//}
//
//int main()
//{
//	char *max;
//	char ch[15][15]={0};
//	int num = 0;
//	char c[30] = {0};
//	while(scanf("%s", ch[num]))
//	{
//		if (strcmp(ch[num], "****") == 0)
//			break;
//		else
//		{
//			num++;
//		}
//	} 
//	fun(ch, num, &max);
//	printf("%s", max);
//	return 0;
//}

//44
//int fun(char *ch1, char *ch2)
//{
//	int len1 = strlen(ch1);
//	int len2 = strlen(ch2);
//	int cnt = 0;
//	for (int i = 0; i <= len1 - len2; )
//	{
//		for (int j = 0; j < len2; ++j)
//		{
//			if (ch2[j] != ch1[i])
//			{
//				i++;
//				break;
//			}
//			else
//			{
//				i++;
//				if (j == len2 - 1)
//				{
//					cnt++;
//				}
//			}
//
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	char ch1[] = "asd asasdfg asd as zx67 asd mklo";
//	char ch2[] = "as";
//	printf("%d ", fun(ch1, ch2));
//	return 0;
//}

//45
//void fun(char *ch, int n, int h, int e)
//{
//	int len = n;
//	for (int i = 0; i < h; ++i)
//	{
//		for (int j = 0; j < len - 1; ++j)
//		{
//			ch[j] = ch[j + 1];
//			ch[len - 1] = '\0';
//		}
//		len--;
//	}
//	ch[n -1 - h - e] = '\0';
//}
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	fun(ch, 22, 4, 7);
//	printf("%s ",ch);
//	return 0;
//}
//46
//typedef struct 
//{
//	int id;
//	int score;
//}student;
//
//void fun(student s[], int n)
//{
//	
//	for (int i = 0; i < n-1; ++i)
//	{
//		int max = s[i].score;
//		int maxi = i;
//		student temp = s[i];
//		int j = i + 1;
//		for (; j < n; ++j)
//		{
//			if (s[j].score > max)
//			{
//				max = s[j].score;
//				maxi = j;
//			}
//		}
//		s[i] = s[maxi];
//		s[maxi] = temp;
//	}
//}
//
//int main()
//{
//	student s[4] = { {1, 60},
//					 {2, 70},
//					 {3, 80},
//					 {4, 95} };
//	fun(s, 4);
//	for (int i = 0; i < 4; ++i)
//	{
//		printf("%d: %d\n", s[i].id, s[i].score);
//	}
//	return 0;
//}

//47
//void fun(char *ss)
//{
//	int n = strlen(ss);
//	for (int i = 1; i < n; i = i + 2)
//	{
//		if (ss[i] <= 'z'&&ss[i] > 'a')
//		{
//			ss[i] = ss[i] - 32;
//		}
//	}
//}
//int main()
//{
//	char ss[] = "abc4EFgh";
//	fun(ss);
//	printf("%s ", ss);
//	return 0;
//}
//48
//int fun(int a, int b)
//{
//	int c;
//	a = a / 10 * 1000 + a % 10 * 10;
//	b = b / 10 * 100 + b % 10;
//	c = a + b;
//}
//int main()
//{
//	int a = 45, b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//49
//void fun(char *s,char *t)
//{
//	int i = 0, j = 0;
//	while (s[i] != '\0')
//	{
//		if(i%2==1||s[i]%2==0)
//		{
//			t[j] = s[i];
//			j++;
//		}
//		i++;
//	}
//}
//int main()
//{
//	char s[] = "ABCDEFG12345";
//	char t[30] = { 0 };
//	fun(s, t);
//	printf("%s ", t);
//	return 0;
//}
//50
//typedef struct
//{
//	int id;
//	int score;
//}studentScore; 
//
//void fun(studentScore a[],int n, int *max)
//{
//	int maxScore = a[0].score;
//	for (int i = 1; i < n; ++i)
//	{
//		if (a[i].score > maxScore)
//		{
//			maxScore = a[i].score;
//			*max = i;
//		}
//	}
//}
//
//int main()
//{
//	studentScore a[4] = {{1,60},{2,70},{3,95},{4,85}};
//	int max=0;
//	fun(a, 4, &max);
//	printf("最高分为：%d ,学号是：%d", a[max].score, a[max].id);
//	return 0;
//}
//51

//int isPrime(int n)
//{
//	int is = 1;
//	int m = (int)sqrt((double)n);
//	for (int i = 2; i <= m; ++i)
//	{
//		if (n%i == 0)
//		{
//			is = 0;
//			break;
//		}
//	}
//	return is;
//}
//
//int fun(int m,int xx[])
//{
//	int k = 0;
//	for (int i = 2; i < m; ++i)
//	{
//		if (isPrime(i) == 0)
//		{
//			xx[k] = i;
//			k++;
//		}
//	}
//	return k;
//}
//int main()
//{
//	int m = 17;
//	int xx[15] = { 0 };
//	int k = fun(m, xx);
//	printf("%d\n", k);
//	for (int i = 0; i < k; ++i)
//	{
//		printf("%d ", xx[i]);
//	}
//	return 0;
//}

//52
//void fun(char *p1, char *p2)
//{
//	int i = strlen(p1);
//	int j = 0;
//	for (; p2[j] != '\0'; ++i, ++j)
//		p1[i] = p2[j];
//}
//int main()
//{
//	char p1[50] = "FirStString--", p2[] = "SecondString";
//	fun(p1, p2);
//	printf("%s ", p1);
//	return 0;
//}
//53
//void fun(int A[][3], int B[][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			B[i][j] = A[i][j] + A[j][i];
//		}
//	}
//}
//int main()
//{
//	int A[3][3]={1,2,3,4,5,6,7,8,9};
//	int B[3][3] = { 0 };
//	fun(A, B);
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			printf("%d\t", B[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//54
//typedef struct
//{
//	int id;
//	int score;
//}student;
//double fun(student s[10], int *n,int b[])
//{
//	double avg = 0;
//	int sum = 0;
//	for (int i = 0; i < 10; ++i)
//	{
//		sum += s[i].score;
//	}
//	avg = sum / 10;
//	for (int i = 0; i < 10; ++i)
//	{
//		if (s[i].score < avg)
//		{
//			b[(*n)] = s[i].id;
//			(*n)++;
//		}
//	}
//	return avg;
//}
//int main()
//{
//	student s[10] = { {1,60},{2,95},{3,86},{4,73},{5,98},{6,66},{7,81},{8,71},{9,68},{10,59} };
//	int n = 0;
//	int b[10] = { 0 };
//	double avg = fun(s, &n,b);
//	printf("平均分是：%f\n低于平均分的人数为：%d\n分别是：", avg, n);
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d号 ", b[i]);
//	}
//	return 0;
//}
//55
//void fun(int a[3][4],int b[],int *n)
//{
//	for(int i=0;i<3;++i)
//		for (int j = 0; j < 4; ++j)
//		{
//			b[(*n)] = a[i][j];
//			(*n)++;
//		}
//}
//int main()
//{
//	int a[3][4] = { 33,33,33,33,
//	                44,44,44,44,
//	                55,55,55,55 };
//	int b[12] = { 0 };
//	int n=0;
//	fun(a, b, &n);
//	for (int i = 0; i < 12; ++i)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}
//56
//void fun(char *ch, char *p)
//{
//	char *i = ch, *j = ch;
//	while (i <= p)          //遍历字符串，把所有字母移到前面
//	{
//		if (*i != '*')
//		{
//			*j = *i;
//			j++;
//		}
//		i++;               //最后j指向最后一个字母的下一位
//	}
//	while (*++p != '\0')   //循环次数为尾部*号的个数
//	{
//		*j = '*';          //从j开始置*
//		j++;
//	}
//	*j = '\0';            //中断字符串
//}
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	char *p = ch + 13;
//	fun(ch, p);
//	printf("%s ", ch);
//	return 0;
//}
//57
//typedef struct
//{
//	int id;
//	int score;
//}student;
//int fun(student s[10],student b[],int low,int heigh)
//{
//	int n = 0;
//	for (int i = 0; i < 10; ++i)
//	{
//		if (s[i].score >= low && s[i].score <= heigh)
//		{
//			b[n] = s[i];
//			n++;
//		}
//	}
//	return n;
//}
//int main()
//{
//	student s[] = { {1,60},{2,95},{3,86},{4,73},{5,98},{6,66},{7,61},{8,71},{9,69},{10,59} };
//	student b[10] = { 0 };
//	int low = 60, heigh = 69;
//	int n = fun(s, b, low, heigh);
//	printf("在分数范围内的学生：\n");
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d号%d分 ", b[i].id, b[i].score);
//	}
//	return 0;
//}

//58
//double fun(int n)
//{
//	double sum = 0;
//	for (int i = 21; i < n; ++i)
//	{
//		if (i % 21 == 0)
//		{
//			sum = sum + i;
//		}
//	}
//	double s = sqrt(sum);
//	return s;
//}
//int main()
//{
//	int n = 1000;
//	printf("%f ", fun(n));
//	return 0;
//}
//59
//void fun(char ch[3][15], char newch[])
//{
//	int k = 0;
//	for (int i = 0; i < 3; ++i)
//	{
//		int j = 0;
//		while (ch[i][j] != '\0')
//		{
//			newch[k] = ch[i][j];
//			j++;
//			k++;
//		}
//	}
//}
//int main()
//{
//	char ch[3][15] = { "AAAA","BBBBBBB","CC" };
//	char newch[50] = { 0 };
//	fun(ch, newch);
//	printf("%s ", newch);
//	return 0;
//}
//60
//int fun(int a[19], int n)
//{
//	int temp = 0;
//	int i = 1;
//	while (i<n)
//		if (a[i-1] == a[i])
//		{
//			i++;
//		}
//		else
//		{
//			a[temp + 1] = a[i];
//			temp++;
//			i++;
//		}
//	return temp+1;
//}
//
//int main()
//{
//	int a[19] = { 2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10 };
//	int m = fun(a, 19);
//	printf("删除后数组数据个数：%d, 分别是：", m);
//	for (int i = 0; i < m; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//61
//void fun(int age[15],int d[11])
//{
//	int j;
//	for (int i = 0; i < 15; ++i)
//	{
//		j = age[i] / 10;
//		if (j > 10) 
//			d[10]++;
//		else
//		{
//			d[j]++;
//		}
//	}
//}
//int main()
//{
//	int N = 15;
//	int age[15] = { 0 };
//	int d[11] = { 0 };
//	srand((unsigned)time(NULL));
//	printf("全部人年龄： ");
//	for (int i = 0; i < N; ++i)
//	{
//		age[i] = rand() % 110 ;
//		printf("%d ", age[i]);
//	}
//	printf("\n");
//	fun(age, d);
//	for (int i = 0; i < 11; ++i) 
//	{
//		if (i != 10)
//			printf("%2d岁 -%3d岁: ", i * 10, i * 10 + 10);
//		else
//			printf("     >100岁: ");
//
//			printf("%2d人 ", d[i]);
//		printf("\n");
//	}
//	return 0;
//}
//62
//int fun(char *s)
//{
//	int i = 0;
//	int cnt = 1;
//	while (s[i] != '\0')
//	{
//		if (s[i] == ' ') 
//			cnt++;
//		i++;
//	}
//	return cnt;
//}
//int main()
//{
//	char s[] = "hello world abc";
//	printf("%d ", fun(s));
//	return 0;
//}
//63
//int fun(int n)
//{
//	int sum = 0;
//	for (int i = 2; i < n; ++i)
//	{
//		if (n%i == 0)
//		{
//			sum += i;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int n = 856;
//	printf("%d ", fun(n));
//	return 0;
//}
//64
//void fun(char *ch,char *t)
//{
//	int i = 0;
//	int j = 0;
//	while (ch[i] != '\0')
//	{
//		if (ch[i] % 2 == 0)
//		{
//			t[j] = ch[i];
//			j++;
//		}
//		i++;
//	}
//}
//int main()
//{
//	char ch[] = "ABCDEFG12345";
//	char t[15] = { 0 };
//	fun(ch, t);
//	printf("%s ", t);
//	return 0;
//}
//65
//int fun(int a, int b)
//{
//	if ((a >= 10 && a < 100) && (b >= 10 && b < 100))
//	{
//		a = a / 10 * 100 + a % 10;
//		b = b / 10 * 10 + b % 10 * 1000;
//		return a + b;
//	}
//	else
//		return -1;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//66
//void fun(char *ch)
//{
//	int i = 0, j = 0;
//	while (ch[j] != '\0')
//	{
//		while (ch[j] == '*')
//		{
//			j++;
//		}
//		ch[i] = ch[j];
//		i++;
//		j++;
//	}
//	ch[i] = '\0';
//}
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	fun(ch);
//	printf("%s ", ch);
//	return 0;
//}
//67
//typedef struct
//{
//	char id[7];
//	int score;
//}student;
//student fun(student s[4],char *ch)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		if (strcmp(s[i].id, ch) == 0)
//		{
//			return s[i];
//		}
//	}
//	student blank;
//	blank.id[0] = '\0';
//	blank.score = -1;
//	return blank;
//}
//int main()
//{
//	student s[4] = { {"1001",60},{"1002",75},{"1004",95},{"1005",80} };
//	char c1[] = "1004", c2[] = "1003";
//	student s1 = fun(s, c1), s2 = fun(s, c2);
//	printf("学生s1 id:%s ,score:%d\n学生s2 id:%s ,score:%d", s1.id, s1.score, s2.id, s2.score);
//	return 0;
//}
//68
//double fun(int n)
//{
//	double s = 0;
//	double temp = 1;
//	for (int i = 0; i <= n; ++i)
//	{
//		s = s + temp;
//		temp = temp / (i+1);
//	}
//	return s;
//}
//int main()
//{
//	printf("%f ", fun(15));
//	return 0;
//}
//69
//int fun(int t)
//{
//	int a = 0, b = 1;
//	int c = a + b;
//	while (c <= t)
//	{
//		int temp = c;
//		c = c + b;
//		b = temp;
//	}
//	return c;
//}
//int main()
//{
//	int t = 1000;
//	printf("%d ", fun(t));
//	return 0;
//}
//70
//double fun(int n)
//{
//	if (n < 1)
//		return -1;
//	double s = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		s = s + 1.0 / (i*(i + 1));
//	}
//	return s;
//}
//int main()
//{
//	int n = 10;
//	printf("%f ", fun(n));
//	return 0;
//}
//71
//int fun(int a ,int b)
//{
//	if ((a >= 10 && a < 100) && (b >= 10 && b < 100))
//		{
//				a = a / 10 * 10 + a % 10*1000;
//				b = b / 10 * 100 + b % 10 ;
//			return a + b;
//		}
//	else
//		return -1;
//}
//int main()
//{
//	int a = 45, b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//72
//void fun(char *s, char *t)
//{
//	int i = 1;
//	int j = 0;
//	while (s[i] != '\0')
//	{
//		t[j] = s[i];
//		j++;
//		i += 2;
//	}
//}
//int main()
//{
//	char s[] = "ABCDEFGHIJK", t[15] = { 0 };
//	fun(s, t);
//	printf("%s ", t);
//	return 0;
//}
//73
//void fun(char *ch, char *h, char *p)
//{
//	char *temp = h+1;
//	while (temp <= p)
//	{
//		if (*temp == '*')
//		{
//			temp++;
//		}
//		else
//		{
//			h++;
//			*h = *temp;
//			temp++;
//		}
//	}
//	p++;
//	h++;
//	while (*p != '\0')
//	{
//		*h = '*';
//		h++;
//		p++;
//	}
//	*h = '\0';
//}
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	char *h = ch + 4;
//	char *p = ch + 13;
//	fun(ch, h, p);
//	printf("%s ", ch);
//	return 0;
//}
//74
//typedef struct
//{
//	int id;
//	int score;
//}student;
//int fun(student s[8], student h[])
//{
//	int cnt = 1;
//	int min = s[0].score;
//	int j = 0;
//	for (int i = 1; i < 8; ++i)
//	{
//		if (s[i].score < min)
//		{
//			min = s[i].score;
//			cnt = 1;
//			h[j] = s[i];
//			j = 1;
//		}
//		else if (s[i].score == min)
//		{
//			cnt++;
//			h[j] = s[i];
//			j++;
//		}
//	}
//	return cnt;
//}
//int main()
//{
//	student s[8] = { {1,95},{2,60},{3,65},{4,90},{5,60},{6,70},{7,60},{8,95} };
//	student h[8] = {0};
//	int n = fun(s, h);
//	printf("最低分数为：%d分，分别是：",h[0].score);
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d号 ", h[i].id);
//	}
//	return 0;
//}
//75
//void fun(int a[3][4], int b[])
//{
//	int i , j ;
//	int bi = 0;
//	for (i=0; i < 4; ++i)
//	{
//		for (j=0; j < 3; ++j)
//		{
//			b[bi] = a[j][i];
//			bi++;
//		}
//	}
//}
//int main()
//{
//	int a[3][4] = { 33,33,33,33,
//	                44,44,44,44,
//	                55,55,55,55 };
//	int b[15] = { 0 };
//	fun(a, b);
//	for (int i = 0; i < 12; ++i)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}
//76
//double fun(double x)
//{
//	if (x >= 0.97)
//		return -1;
//	double s = 0;
//	double temp = 1;
//	int n = 1;
//	while (fabs(temp) >= 0.000001)
//	{
//		s = s + temp;
//		temp = temp * (0.5 - n + 1) * x / n;
//		n++;
//	}
//	return s;
//}
//int main()
//{
//	double x = 0.21;
//	printf("%f ", fun(x));
//	return 0;
//}
//77
//int fun(int a, int b)
//{
//	a = a / 10 + a % 10 * 100;
//	b = b / 10 * 10 + b % 10 * 1000;
//	return a + b;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//78
//void fun(char *ch,char *t)
//{
//	int i = 0, j = 0;
//	while (ch[i] != '\0')
//	{
//		if (ch[i] % 2 == 1)
//		{
//			t[j] = ch[i];
//			j++;
//			i++;
//		}
//		else 
//			i++;
//	}
//}
//int main()
//{
//	char ch[] = "ABCDEFG12345";
//	char t[15] = { 0 };
//	fun(ch, t);
//	printf("%s ", t);
//	return 0;
//}
//79
//typedef struct
//{
//	int id;
//	int score;
//}student;
//void fun(student s[7],student *m)
//{
//	m->id = s[0].id;
//	m->score = s[0].score;
//	for (int i = 1; i < 7; ++i)
//	{
//		if (s[i].score < m->score)
//		{
//			m->score = s[i].score;
//			m->id = s[i].id;
//		}
//	}
//}
//int main()
//{
//	student s[7] = { {1,70},{2,80},{3,65},{4,95},{5,84},{6,69}, {7,88} };
//	student lowest;
//	fun(s, &lowest);
//	printf("最低分：%d号%d分 ", lowest.id, lowest.score);
//	return 0;
//}
//80
//void fun(int a[][3],int n)
//{
//	for (int i=0; i < 3; ++i)
//	{
//		for (int j=0; j <= i; ++j)
//		{
//			a[i][j] *= n;
//		}
//	}
//}
//int main()
//{
//	int a[][3] = { 1,9,7,2,3,8,4,5,6 };
//	int n = 3;
//	fun(a, n);
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			printf("%d\t", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//81
//int fun(int a, int b)
//{
//	a = a / 10 * 100 + a % 10;
//	b = b / 10 * 1000 + b % 10 * 10;
//	return a + b;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//82
//double fun(double a[],int n)
//{
//	double sum = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		sum += a[i];
//	}
//	return sum / n;
//}
//int main()
//{
//	double score[5] = { 90.5,72,80,61.5,55 };
//	printf("%.2f ", fun(score, 5));
//	return 0;
//}
//83
//void fun(char *ch)
//{
//	int i = 0, j = 0;
//	while (ch[i] != '\0')
//	{
//		if (ch[i] != '*')
//		{
//			j = i;
//		}
//		i++;
//	}
//	ch[j+1] = '\0';
//}
//int main()
//{
//	char c[] = "****A*BC*DEF*G*******";
//	fun(c);
//	printf("%s ", c);
//	return 0;
//}
//84
//int fun(int a, int b)
//{
//	a = a / 10 + a % 10 * 100;
//	b = b / 10 * 1000 + b % 10 * 10;
//	return a + b;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//85
//typedef struct
//{
//	int id;
//	int score;
//	struct student *next;
//}student;
//double fun(student *h)
//{
//	double sum = 0;
//	int cnt = 0;
//	h = h->next;
//	while (h != NULL)
//	{
//		sum = sum + h->score;
//		h = h->next;
//		cnt++;
//	}
//	return sum / cnt;
//}
//int main()
//{
//	student st8={8,87,NULL},st7={7,64,&st8},st6={6,72,&st7},st5={5,91,&st6},
//		    st4={4,85,&st5},st3={3,69,&st4},st2={2,76,&st3},st1={1,85,&st2},
//	        h = { 0,-1,&st1 };
//	printf("%f ", fun(&h));
//	return 0;
//}
//86
//double fun(double x[10])
//{
//	double s = 0;
//	double sum = 0;
//	for (int i = 0; i < 10; ++i)
//	{
//		sum += x[i];
//	}
//	double avg = sum / 10;
//	for (int i = 0; i < 10; ++i)
//	{
//		s += (x[i] - avg)*(x[i] - avg);
//	}
//	s = s / 10;
//	return sqrt(s);
//}
//int main()
//{
//	double a[] = { 95,89,76,65,88,72,85,81,90,56 };
//	printf("%f ", fun(a));
//	return 0;
//}
//87
//int fun(int a, int b)
//{
//	a = a / 10 * 1000 + a % 10 * 10;
//	b = b / 10 + b % 10 * 100;
//	return a + b;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//88
//void fun(char *ch)
//{
//	int i = 0, j = 0;
//	while (ch[i] == '*')
//	{
//		i++;
//	}
//	j = i;
//	while (ch[i] != '\0')
//	{
//		if (ch[i] == '*')
//		{
//			i++;
//		}
//		else
//		{
//			ch[j] = ch[i];
//			i++;
//			j++;
//		}
//	}
//	ch[j] = '\0';
//}
//int main()
//{
//	char ch[] = "****A*BC*DEF*G*******";
//	fun(ch);
//	printf("%s ", ch);
//	return 0;
//}
//89
//typedef struct
//{
//	int id;
//	int score;
//}student;
//double fun(student s[9], student b[], int *n)
//{
//	int sum = 0;
//	for (int i = 0; i < 9; ++i)
//	{
//		sum += s[i].score;
//	}
//	double avg = sum / 9.0;
//	int j = 0;
//	for (int i = 0; i < 9; ++i)
//	{
//		if ((double)s[i].score >= avg)
//		{
//			b[j] = s[i];
//			j++;
//		}
//	}
//	*n = j;
//	return avg;
//}
//int main()
//{
//	student s[9] = { {1,70},{2,65},{3,80},{4,82},{5,67},{6,95},{7,88},{9,73} };
//	student b[9] = { 0 };
//	int n=0;
//	double avg=fun(s, b, &n);
//	printf("平均分为：%f分\n高于平均分的学生：", avg);
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d号%d分 ", b[i].id, b[i].score);
//	}
//	return 0;
//}
//90
//double fun(int n)
//{
//	double s = 0;
//	double temp = 0;
//	int j = 1;
//	for (int i = 0; i <= n; i++)
//	{
//		s = s + temp;
//		temp = 1.0/ j - 1.0 / (j + 1);
//		j = j + 2;
//	}
//	return s;
//}
//int main()
//{
//	int n = 8;
//	printf("%f ", fun(n));
//	return 0;
//}
//91
//int fun(int a, int b)
//{
//	a = a / 10 * 10 + a % 10 * 1000;
//	b = b / 10 + b % 10 * 100;
//	return a + b;
//}
//int main()
//{
//	int a = 45;
//	int b = 12;
//	printf("%d ", fun(a, b));
//	return 0;
//}
//92
//double fun(int m)
//{
//	if (m < 1)
//		return -1;
//	double s;
//	double sum = 0;
//	int i = 1;
//	while (i <= m)
//	{
//		sum=sum+log((double)i);
//		i++;
//	}
//	s = sqrt(sum);
//	return s;
//}
//int main()
//{
//	int m = 20;
//	printf("%f ", fun(m));
//	return 0;
//}
//93
//double fun(int n,double x)
//{
//	if (n < 0)
//	{
//		return -1;
//	}
//	else if (n == 0)
//	{
//		return 1;
//	}
//	double s = 0;
//	int i = 1;
//	double temp = 1;
//	while (i <= n)
//	{
//		s = s + temp;
//		temp = temp * x / i;
//		i++;
//	}
//	return s;
//}
//int main()
//{
//	int n = 10;
//	double x = 0.3;
//	printf("%f ", fun(n, x));
//	return 0;
//}
//94
//void fun(char *ch)
//{
//	int i = 0, j = 0;
//	while (ch[i] == '*')
//	{
//		i++;
//	}
//	while (ch[i]!='\0')
//	{
//		ch[j] = ch[i];
//		j++;
//		i++;
//	}
//	ch[i] = '\0';
//}
//int main()
//{
//	char ch[] = "*******A*BC*DEF*G****";
//	fun(ch);
//	printf("%s ", ch);
//	return 0;
//}

//95
//void fun(char *ch, int n)
//{
//	int i = 0, j = 0;
//	while (ch[i] == '*')
//	{
//		if (i < n)
//		{
//			i++;
//		}
//		else
//		{
//			j = i;
//			break;
//		}
//	}
//	while (ch[i] == '*')
//	{
//		i++;
//	}
//	while (ch[i] != '\0')
//	{
//		ch[j] = ch[i];
//		j++;
//		i++;
//	}
//	ch[j] = '\0';
//}
//int main()
//{
//	char ch[] = "*******A*BC*DEF*G****";
//	int n = 4;
//	fun(ch, n);
//	printf("%s ", ch);
//	return 0;
//}
//96
//double fun(double a[9])
//{
//	double s = 0;
//	for (int i = 0; i < 9 - 1; ++i)
//	{
//		s += sqrt((a[i] + a[i + 1]) / 2);
//	}
//	return s;
//}
//int main()
//{
//	double a[9] = { 12,34,4,23,34,45,18,3,11 };
//	printf("%f ", fun(a));
//	return 0;
//}

//97
//double fun(int n)
//{
//	if (n <= 1 || n > 100)
//	{
//		return -1;
//	}
//	double s = 0;
//	double temp = 0;
//	int i = 0;
//	int j = 0;
//	while (i <= n)
//	{
//		s = s + temp;
//		temp = 1.0/(j + i + 1);
//		j = j + i + 1;
//		i++;
//		
//	}
//	return s; 
//}
//int main()
//{
//	int n = 50;
//	printf("%f ", fun(n));
//	return 0;
//}
//98
//double fun(int n)
//{
//	if (n > 100)
//	{
//		return -1;
//	}
//	double s = 0;
//	for (int i = 5; i <= n; ++i)
//	{
//		if (i % 5 == 0 || i % 9 == 0)
//		{
//			s = s + 1.0 / i;
//		}
//	}
//	return s;
//}
//int main()
//{
//	int n = 20;
//	printf("%f ", fun(n));
//	return 0;
//}
//99
//int isPrime(int n)
//{
//	int is = 1;
//	int m = (int)sqrt((double)n);
//	for (int i = 2; i <= m; ++i)
//	{
//		if (n%i == 0)
//		{
//			is = 0;
//			break;
//		}
//	}
//	return is;
//}
//double fun(int n)
//{
//	if (n <= 2 || n > 100)
//	{
//		return -1;
//	}
//	double sum = 0;
//	for (int i = 3; i <= n; ++i)
//	{
//		if (isPrime(i) == 1)
//		{
//			sum += sqrt(i);
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int n = 100;
//	printf("%f ", fun(n));
//	return 0;
//}

//100
//double fun(int n)
//{
//	if (n <= 1 || n > 100)
//	{
//		return -1;
//	}
//	double s = 0;
//	double temp = 1;
//	int i = 1;
//	while (i <= n)
//	{
//		s = s + temp;
//		temp = temp + sqrt(i + 1.0);
//		i++;
//	}
//	return s;
//}
//int main()
//{
//	int n = 20;
//	printf("%f ", fun(n));
//	return 0;
//}
//