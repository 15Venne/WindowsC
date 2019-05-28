#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>
#include<conio.h>
#include <windows.h>
#include <time.h>

//1
//int main()
//{
//	int i, j, k;
//	int cnt = 0;
//	int s = 0;
//	for (i = 1; i < 5; ++i)
//	{
//		for (j = 1; j < 5; ++j)
//		{
//			for (k = 1; k < 5; ++k)
//			{
//				if (i != j && i != k && j != k)
//				{
//					cnt++;
//					s = i * 100 + j * 10 + k;
//					printf("%d ", s);
//				}
//			}
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("一共%d个", cnt);
//	return 0;
//}
//2
//double fun(double n)
//{
//	double bonus = 0;
//	double p1 = 0.1,
//		p2 = 0.75,
//		p3 = 0.05,
//		p4 = 0.03,
//		p5 = 0.015,
//		p6 = 0.01;
//	int temp = (int)n / 10;
//	if (temp < 1)
//		bonus = n * p1;
//	else if (temp >= 1 && temp < 2)
//		bonus = 10 * p1 + (n - 10)*p2;
//	else if (temp >= 2 && temp < 4)
//		bonus = 10 * p1 + 10 * p2 + (n - 20)*p3;
//	else if (temp >= 4 && temp < 6)
//		bonus = 10 * p1 + 10 * p2 + 20 * p3 + (n - 40)*p4;
//	else if (temp >= 6 && temp < 10)
//		bonus = 10 * p1 + 10 * p2 + 20 * p3 + 20 * p4 + (n - 60)*p5;
//	else if (temp >= 10)
//		bonus = 10 * p1 + 10 * p2 + 20 * p3 + 20 * p4 + 40 * p5 + (n - 100)*p6;
//	return bonus;
//}
//int main()
//{
//	printf("输入利润： (万元)\n");
//	double I;
//	scanf("%lf",&I);
//	printf("奖金：%f万元 ", fun(I));
//	return 0;
//}
//3
//int fun(int n)
//{
//	int m1 = sqrt((double)(n+100));
//	int k = n + 100;
//	if (n+100 == m1*m1)
//	{
//		int m2 = sqrt((double)(n + 268));
//		if (n + 268 == m2*m2)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i=1;
//	while (fun(i) == 0)
//	{
//		i++;
//	}
//	printf("%d ", i);
//	return 0;
//}
//4
//int isLeapyear(int n)
//{
//	if (n % 4 == 0 && n % 100 != 0)
//	{
//		return 1;
//	}
//	else if (n % 400 == 0)
//		return 1;
//	else return 0;
//}
//int main()
//{
//	int daySum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//	int year, month, day;
//	printf("输入年:\n");
//	scanf("%d",&year);
//	printf("输入月:\n");
//	scanf("%d",&month);
//	if (month < 1 || month>12)
//		return -1;
//	printf("输入日:\n");
//	scanf("%d",&day);
//	if (day > (daySum[month] - daySum[month - 1]))
//	{
//		if (isLeapyear(year) == 1 && month == 2)
//		{
//			if (day > 29)
//				return -1;
//		}
//		else 
//			return -1;
//	}
//	int sum;
//	sum = daySum[month] + day;
//	if (isLeapyear(year) == 1&&month>=3)
//	{
//		sum++;
//	}
//	printf("%d月%d日是%d年的第%d天", month, day, year, sum);
//	return 0;
//}
//int main()
//{
//	int x, y, z;
//	printf("输入整数x：");
//	scanf("%d",&x);
//	printf("输入整数y：");
//	scanf("%d",&y);
//	printf("输入整数z：");
//	scanf("%d",&z);
//	int temp = x;
//	if (temp > y)
//	{
//		temp = y;
//		if (temp > z)
//		{
//			temp = z;
//			z = x;
//			x = temp;
//		}
//		else
//		{
//			y = x;
//			x = temp;
//		}
//	}
//	if (y > z)
//	{
//		temp = y;
//		y = z;
//		z = temp;
//	}
//	printf("从小到大为：%d %d %d", x, y, z);
//	return 0;
//}
//6
//int main() 
//{
//	printf("  ******\n");
//	printf(" *\n");
//	printf("*\n");
//	printf("*\n");
//	printf("*\n");
//	printf(" *\n");
//	printf("  ******\n");
//	return 0;
//}
//7
//int main() {
//	char a = 176, b = 219;
//	system("cmd /c chcp 437");
//	printf("%c%c%c%c%c\n", b, a, a, a, b);
//	printf("%c%c%c%c%c\n", a, b, a, b, a);
//	printf("%c%c%c%c%c\n", a, a, b, a, a);
//	printf("%c%c%c%c%c\n", a, b, a, b, a);
//	printf("%c%c%c%c%c\n", b, a, a, a, b);
//	return 0;
//}
//8
//int main()
//{
//	int i, j;
//	for (i = 1; i < 10; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%d*%d=%-3d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//9
//int main()
//{
//	int i, j;
//	system("cmd /c chcp 437");
//	for (i = 0; i < 8; ++i)
//	{
//		for (j = 0; j < 8; ++j)
//		{
//			if ((i + j) % 2 == 0)
//				printf("%c", 219);
//			else
//				printf("  ");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//10
//int main()
//{
//	int i, j; 
//	system("cmd /c chcp 437");
//	printf("\1 \1\n");
//	for (i = 1; i < 11; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%c%c",219,219);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//11
//int fun(int n)
//{
//	if (n == 1 || n == 2)
//		return 2;
//	return fun(n - 1) + fun(n - 2);
//}
//int main()
//{
//	int month;
//	printf("输入第几月：");
//	while (scanf("%d",&month))
//	{
//		printf("第%d个月兔子总数为：%d\n",month,fun(month));
//		printf("输入第几月：");
//	}
//	return 0;
//}
//12
//int isprime(int n)
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
//int main()
//{
//	int i, cnt = 0;
//	printf("101到200之间的素数为：");
//	for (i = 101; i < 200; ++i)
//	{
//		if (isprime(i) == 1)
//		{
//			printf("%d ", i);
//			cnt++;
//		}
//	}
//	printf("\n一共%d个", cnt);
//}
//13
//int main()
//{
//	for (int i = 100; i < 1000; ++i)
//	{
//		int j = i % 100 % 10;
//		int k = i % 100 / 10;
//		int m = i / 100;
//		if (i == (j*j*j + k * k*k + m * m*m))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//14
//int main()
//{
//	int n;
//	printf("输入n：");
//	scanf("%d",&n);
//	int k;
//	printf("%d=", n);
//	for (k = 2; k <= n; )
//	{
//		if (n % k == 0)
//		{
//			printf("%d*", k);
//			n = n / k;
//		}
//		else
//			k++;
//	}
//	printf("\b ");
//	return 0;
//}
//15
//int main()
//{
//	int score;
//	printf("输入成绩：");
//	scanf("%d",&score);
//	char grade = score>=90?'A':(score>=60?'B':'C');
//	printf("评价：%c", grade);
//	return 0;
//}
//16
//int main()
//{
//	int m, n;
//	printf("输入m和n：\n");
//	scanf("%d%d",&m,&n);
//	if (m > n)
//	{
//		int temp = m;
//		m = n;
//		n = temp;
//	}
//	int i;
//	for (i = m; i > 1; --i)
//	{
//		if (m % i == 0)
//		{
//			if (n % i == 0)
//			{
//				break;
//			}
//		}
//	}
//	printf("最大公约数为：%d", i);
//	printf("最小公倍数为：%d", m*n / i);
//	return 0;
//}
//17
//int main()
//{
//	char c;
//	int alpha = 0, space = 0, digit = 0, others = 0;
//	printf("输入一行字符：\n");
//	while ((c = getchar()) != '\n')
//	{
//		if (isalpha(c))
//			alpha++;
//		else if (isspace(c))
//			space++;
//		else if (isdigit(c))
//			digit++;
//		else
//			others++;
//	}
//	printf("字母: %d个\n", alpha);
//	printf("空格: %d个\n", space);
//	printf("数字: %d个\n", digit);
//	printf("其他: %d个\n", others);
//	return 0;
//}
//int fun(int a, int n)
//{
//	int temp = a;
//	int s = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		s = s + temp;
//		temp = temp * 10 + a;
//	}
//	return s;
//}
//int main()
//{
//	int a, n;
//	printf("输入a的值：");
//	scanf("%d",&a);
//	printf("输入n的值：(多少项相加)");
//	scanf("%d",&n);
//	printf("结果为：%d", fun(a, n));
//	return 0;
//}
//19
//int isPer(int n)
//{
//	int k, sum = 0;
//	for (k = 2; k < n; )
//	{
//		if (n % k == 0)
//		{
//			sum = sum + k;
//		}
//		k++;
//	}
//	if (sum + 1 == n)
//		return 1;
//	else 
//		return 0;
//}
//int main()
//{
//	printf("1000以内的所有完数：");
//	for (int i = 2; i < 1000; ++i)
//	{
//		if (isPer(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//20
//int main()
//{
//	double sum = 100;
//	double jump = 0;
//	int temp = 2;
//	for (int i = 1; i <= 10; ++i)
//	{
//		sum = sum + jump * 2;
//		jump = 100.0 / temp;
//		temp = temp * 2;
//	}
//	printf("第10次落地时共经过%f米\n", sum);
//	printf("第10次反弹%f米\n", jump);
//	return 0;
//}
//21
//int main()
//{
//	int sum = 1;
//	for (int i = 9; i >= 1; --i)
//	{
//		sum = (sum + 1) * 2;
//	}
//	printf("第一天摘了%d个桃子", sum);
//	return 0;
//}
//22
//int main()
//{
//	char i, j, k;   //设a的对手是i，b的对手是j，c的对手是k;
//	for (i = 'x'; i <= 'z'; ++i)
//	{
//		for (j = 'x'; j <= 'z'; ++j)
//		{
//			if (i == j)
//				continue;
//			else
//			{
//				for (k = 'x'; k <= 'z'; ++k)   //列出所有可能
//				{
//					if (k == i || k == j)
//						continue;
//					else
//						if(i!='x'&&k!='x'&&k!='z')   //排除条件
//							printf("a VS %c\nb VS %c\nc VS %c\n", i, j, k);
//				}
//			}
//		}
//	}
//	return 0;
//}
//23
//int main()
//{
//	int n = 23;  //奇数
//	for (int i = 0; i < n/2+1; ++i)
//	{
//		for (int j = 1; j <=n ; ++j)
//		{
//			if (j <= n / 2 + 1 + i && j >= n / 2 + 1 - i)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	for (int i = 1; i <= n / 2 ; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			if (j <= i || j > n - i)
//				printf(" ");
//			else
//				printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//24
//int main()
//{
//	double sum = 0;
//	double a = 2, b = 1;
//	double temp ;
//	for (int i = 1; i <= 20; ++i)
//	{
//		sum = sum + a/b;
//		temp = a;
//		a = a + b;
//		b = temp;
//	}
//	printf("%f ", sum);
//	return 0;
//}
//25
//int main()
//{
//	float sum = 0, temp = 1;
//	for (float i = 1; i <= 20; ++i)
//	{
//		temp = temp * i;
//		sum = sum + temp;
//	}
//	printf("%e", sum);
//	return 0;
//}
//26
//int fun(int n)
//{
//	if (n == 1 || n == 0)
//	{
//		return 1;
//	}
//	else
//		return n * fun(n - 1);
//}
//int main()
//{
//	printf("5!=%d", fun(5));
//	return 0;
//}
//void fun(int n) 
//{
//	if (!n) return;
//	char c;
//	c = getchar();
//	fun(--n);
//	putchar(c);
//}
//
//int main()
//{
//	fun(5);
//	return 0;
//}
//28
//int fun(int id)
//{
//	if (id == 1)
//		return 10;
//	else
//		return fun(id - 1) + 2;
//}
//int main()
//{
//	printf("第五个人%d岁", fun(5));
//	return 0;
//}
//29
//int main()
//{
//	int num;
//	printf("输入一个不多于5位的正整数：");
//	scanf("%d",&num);
//	int temp = num;
//	int cnt = 1;
//	printf("逆序为：");
//	while (temp / 10 != 0)
//	{
//		printf("%d", temp % 10);
//		temp = temp / 10;
//		cnt++;
//	}
//	printf("%d\n", temp);
//	printf("它是%d位数", cnt);
//	return 0;
//}
//int isHui(int n)
//{
//	if (n % 10 == n / 10000)
//	{
//		if (n % 10000 / 1000 == n % 100 / 10)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("(判断回文数)输入一个5位数：");
//	scanf("%d",&n);
//	printf("\n%d", n);
//	if (isHui(n) == 1)
//		printf("是");
//	else
//		printf("不是");
//	printf("回文数\n");
//	return 0;
//}
//31
//int main()
//{
//	char f, s;
//	printf("请输入星期几的第一个字母：");
//	scanf("%c",&f);
//	switch (f)
//	{
//	case 'S':
//		printf("请输入星期几的第二个字母：");
//		scanf(" %c",&s);
//		if (s == 'a')
//			printf("Saturday星期六");
//		else if (s == 'u')
//			printf("Sunday星期天");
//		else
//			printf("输入不合法");
//		break;
//	case 'M':
//		printf("Monday星期一");
//		break;
//	case 'T':
//		printf("请输入星期几的第二个字母：");
//		scanf(" %c",&s);
//		if (s == 'u')
//			printf("Tuesday星期二");
//		else if (s == 'h')
//			printf("Thursday星期四");
//		else
//			printf("输入不合法");
//		break;
//	case 'W':
//		printf("Wednesday星期三");
//		break;
//	case 'F':
//		printf("Friday星期五");
//		break;
//	default:
//		printf("输入不合法");
//		break;
//	}
//	return 0;
//}
//32
//char colors[][10] = {
//	"\033[0m",
//	"\033[31m",
//	"\033[32m",
//	"\033[33m",
//	"\033[34m",
//	"\033[35m",
//	"\033[36m"
//};
//
//int main() {
//	int i = 0;
//	char c;
//	printf("Hello World!");
//	while ((c = getchar()) && c != EOF) {
//		if (c == '\n') continue;
//		printf("%s", colors[++i]);
//		printf("Hello World!");
//		printf("%s\n", colors[0]);
//		if (i >= 6) i = 0;
//	}
//	return 0;
//}
//33
//void gotoxy(int x, int y) {
//	COORD pos = { x,y };
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
//	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
//}
//
//int main() {
//	int x, y;
//	gotoxy(3, 3);
//	printf("hello,world!");
//	system("pause");
//	system("cls");
//	return 0;
//}
//35
//int main()
//{
//	printf("\033[36m");
//	printf("The color");
//	return 0;
//}
//36
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
//int main()
//{
//	printf("100以内的素数：");
//	for (int i = 2; i <= 100; ++i)
//	{
//		if (isPrime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//37
//int main()
//{
//	int a[10] = {0};
//	printf("请输入10个数：\n");
//	for (int i = 0; i < 10; ++i)
//	{
//		scanf("%d",&a[i]);
//	}
//	printf("\n");
//	printf("您输入的10个数为：");
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	for(int k=0;k<10;++k)
//	{ 
//		int temp = a[k];
//		int j = k;
//		for (int i = k; i < 10; ++i)
//		{
//			if (a[i] < temp)
//			{
//				temp = a[i];
//				j = i;
//			}
//		}
//		a[j] = a[k];
//		a[k] = temp;
//	}
//	printf("从小到大排序：");
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//38
//int main()
//{
//	int a[3][3] = { 10,22,34,
//				    51,32,60,
//				    12,15,38};
//	int sum = 0;
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			if (i == j || i + j == 3 - 1)
//			{
//				sum = sum + a[i][j];
//			}
//		}
//	}
//	printf("%d ", sum);
//	return 0;
//}
//39
//int main()
//{
//	int a[15] = { 10,20,30,40,50,60,70,80,90,100 };
//	int n;
//	printf("原来的数组：");
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("输入要插入的整数：");
//	scanf("%d",&n);
//	int m = 0;
//	while (n > a[m])
//	{
//		m++;
//	}
//	for (int j = 10; j >m; --j)
//	{
//		a[j] = a[j - 1];
//	}
//	a[m] = n;
//	printf("插入后的数组：");
//	for (int k = 0; k < 10 + 1; ++k)
//	{
//		printf("%d ", a[k]);
//	}
//	return 0;
//}
//40
//void swap(int *n, int *m)
//{
//	int temp = *n;
//	*n = *m;
//	*m = temp;
//}
//
//int main()
//{
//	int a[10] = { 10,20,30,40,50,60,70,80,90,100 };
//	int i, j;
//	for (i = 0, j = 10 - 1; i <= j; ++i, --j)
//	{
//		swap(&a[i], &a[j]);
//	}
//	for (int k = 0; k < 10; ++k)
//	{
//		printf("%d ", a[k]);
//	}
//	return 0;
//}
//41
//51
// 0&0=0; 0&1=0; 1&1=1;
//int main()
//{
//	int a, b;
//	a = 077;     // 00111111
//	b = a & 3;  // 00111111 & 0011=0000011
//	printf("%d\n", b);
//	b &= 7;  // 0011 & 0111 = 0011
//	printf("\40:The a&b(decimal)is %d\n", b);
//	return 0;
//}

//52
// 0|0=0; 0|1=1; 1|0=1; 1|1=1;
//int main()
//{
//	int a, b;
//	a = 077;    // 00111111
//	b = a | 3;   // 0011 1111 | 0000 0011=0011 1111
//	printf("%d\n", b);  //63
//	b |= 7;       // 0011 1111 | 0000 0111=0011 1111
//	printf("%d\n", b);
//	return 0;
//}
//53
////0^0=0; 0^1=1; 1^0=1; 1^1=0;
//int main()
//{
//	int a, b;
//	a = 077;            // 00111111
//	b = a ^ 3;          // 0011 1111 ^ 0000 0011 = 0011 1100 (60)
//	printf("%d\n", b);  
//	b ^= 7;             // 0011 1100 ^ 0000 0111 = 0011 1011 (59)
//	printf("%d\n", b);
//	return 0;
//}

//54
//int main()
//{
//	unsigned a, b, c, d;
//	scanf("%o",&a);
//	b = a >> 4;
//	c = ~(~0 << 4);
//	d = b & c;
//	printf("%o\n%o\n", a, d);
//	return 0;
//}
//int main() {
//	int n;
//	scanf("%o", &n);
//	printf("%o\n", n & 017);
//	return 0;
//}
//55
////~0=1; ~1=0;
//int main()
//{
//	int a, b;
//	a = 234;  //     11101010
//	b = ~a;   //     00010101  
//	          // 取反11101010
//	          // 加1 11101011  （235）
//	          // 最高位（32）变1 ，即取负  (-235) 
//	printf("%d\n", b);
//	a = ~a;   
//	printf("%d\n", a);
//	return 0;
//}
//61
//int main()
//{
//	int a[10][10] = { 0 };
//	for (int i = 0; i < 10; ++i)
//	{
//		a[i][0] = 1;
//		for (int j = 1; j <= i; ++j)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			printf("%3d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//66
//int main()
//{
//	int a[3] = { 0 };
//	printf("请输入3个数：\n");
//	for (int i = 0; i < 3; ++i)
//	{
//		scanf("%d", &a[i]);
//	}
//	printf("\n");
//	printf("您输入的3个数为：");
//	for (int i = 0; i < 3; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	for (int k = 0; k < 3; ++k)
//	{
//		int temp = a[k];
//		int j = k;
//		for (int i = k; i < 3; ++i)
//		{
//			if (a[i] > temp)
//			{
//				temp = a[i];
//				j = i;
//			}
//		}
//		a[j] = a[k];
//		a[k] = temp;
//	}
//	printf("\n从大到小排序：");
//	for (int i = 0; i < 3; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//67
//void swap(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a[8] = { 5,8,1,6,9,4,5,6 };
//	int max = a[0], maxi = 0;
//	for (int i = 1; i < 8; ++i)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//			maxi = i;
//		}
//	}
//	swap(&a[0], &a[maxi]);
//	int min = a[1], mini = 1;
//	for (int j = 2; j < 8; ++j)
//	{
//		if (a[j] < min)
//		{
//			min = a[j];
//			mini = j;
//		}
//	}
//	swap(&a[mini], &a[8 - 1]);
//	for (int k = 0; k < 8; ++k)
//	{
//		printf("%d ", a[k]);
//	}
//	return 0;
//}
//68
//int main()
//{
//	int n = 10, m = 3;
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i = 0; i < 3; ++i)
//	{
//		int temp = a[10 - 1];
//		for (int j = 10 - 1; j > 0; --j)
//		{
//			a[j] = a[j - 1];
//		}
//		a[0] = temp;
//	}
//	for (int k = 0; k < 10; ++k)
//	{
//		printf("%d ", a[k]);
//	}
//	return 0;
//}
//69
//void inS(int a[],int i,int *p)
//{
//	if (*p == 0)        //如果要在a[0]前插入，则插在队尾，以不改变最后留下的人的位置。
//	{
//		a[i] = 3;     
//		*p = i;
//	}
//	else
//	{
//		for (int j = i; j > (*p); --j)
//		{
//			a[j] = a[j - 1];
//		}
//		a[*p] = 3;
//	}
//}
//int main()
//{
//	int a[100] = {0};
//	int n=10;
//	int i = 1;
//	a[0] = 1;      //最后留下的固定在a[0],最后他为1号。
//	int p = 0;    //*p始终指向删除3后面的1.（即每次在1之前插入3，直至数组个数为n，看a[0]变为什么即可）
//	while (i < n)
//	{
//		inS(a, i, &p);
//		p = p - 1;
//		if (p == -1)
//		{
//			p = i;
//		}
//		a[p] = 2;
//		p = p - 1;
//		if (p == -1)
//		{
//			p = i;
//		}
//		a[p] = 1;
//		i++;
//	}
//	for (int j = 0; j < n; ++j)
//	{
//		printf("%d ", a[j]);
//	}
//	printf("\n p=%d \n", p);
//	printf("第%d号那位", n - p + 1);
//	return 0;
//}
//70
//int main()
//{
//	char ch[30] = { 0 };
//	printf("输入字符串：");
//	scanf("%s",ch);
//	int i = 0;
//	while (ch[i] != '\0')
//	{
//		i++;
//	}
//	printf("%d", i);
//	return 0;
//}
//71
//typedef struct
//{
//	int id;
//	int score;
//}student;
//
//void input(student s[],int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("输入第%d个学生学号和成绩：\n",i+1);
//		scanf("%d",&s[i].id);
//		scanf("%d",&s[i].score);
//	}
//}
//void output(student s[],int n)
//{
//	printf("学号 成绩\n");
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%-4d %-4d\n", s[i].id, s[i].score);
//	}
//}
//int main()
//{
//	student s[5];
//	input(s, 5);
//	output(s, 5);
//	return 0;
//}
//72
//struct Node {
//	int val;
//	struct Node *next;
//};
//
//void reverse_construct(struct Node **head, int n) {
//	if (n == 0) {
//		*head = NULL;
//		return;
//	}
//
//	*head = (struct Node*)malloc(sizeof(struct Node));
//	(*head)->next = NULL;
//	scanf("%d", &(*head)->val);
//
//	struct Node *p;
//
//	while (--n) {
//		p = (struct Node*)malloc(sizeof(struct Node));
//		scanf("%d", &p->val);
//		p->next = *head;
//		*head = p;
//	}
//}
//
//void release(struct Node *p) {
//	struct Node *t = p;
//	while (p) {
//		t = p;
//		p = p->next;
//		free(t);
//	}
//}
//
//void print(struct Node *p) {
//	while (p) {
//		printf("%d ", p->val);
//		p = p->next;
//	}
//} 
//
//int main() {
//	struct Node *List;
//	int n;
//	printf("How many nodes do you want?\n");
//	scanf("%d", &n);
//	printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
//	reverse_construct(&List, n);
//	print(List);
//	release(List);
//	return 0;
//}

//struct Node {
//	int val;
//	struct Node *next;
//};
//
//void reverse_construct(struct Node **head, int n) {
//	*head = (struct Node*)malloc(sizeof(struct Node));
//	(*head)->next = NULL;
//	scanf("%d", &(*head)->val);
//
//	struct Node *p;
//
//	while (--n) {
//		p = (struct Node*)malloc(sizeof(struct Node));
//		scanf("%d", &p->val);
//		p->next = *head;
//		*head = p;
//	}
//}
//
//void release(struct Node *p) {
//	struct Node *t = p;
//	while (p) {
//		t = p;
//		p = p->next;
//		free(t);
//	}
//}
//
//void print(struct Node *p) {
//	while (p) {
//		printf("%d ", p->val);
//		p = p->next;
//	}
//}
//
//void reverse_print(struct Node *p) {
//	if (!p) return;
//	reverse_print(p->next);
//	printf("%d ", p->val);
//}
//
//
//int main() {
//	struct Node *List;
//	int n;
//	printf("How many nodes do you want?\n");
//	scanf("%d", &n);
//	printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
//	reverse_construct(&List, n);
//
//	printf("\nNormal Order Print\n");
//	print(List);
//
//	printf("\nReverse Order Print\n");
//	reverse_print(List);
//
//	printf("\n");
//	release(List);
//	return 0;
//}
//struct Node {
//	int val;
//	struct Node *next;
//};
//
//void reverse_construct(struct Node **head, int n) {
//	*head = (struct Node*)malloc(sizeof(struct Node));
//	(*head)->next = NULL;
//	scanf("%d", &(*head)->val);
//
//	struct Node *p;
//
//	while (--n) {
//		p = (struct Node*)malloc(sizeof(struct Node));
//		scanf("%d", &p->val);
//		p->next = *head;
//		*head = p;
//	}
//}
//
//void release(struct Node *p) {
//	struct Node *t = p;
//	while (p) {
//		t = p;
//		p = p->next;
//		free(t);
//	}
//}
//
//void print(struct Node *p) {
//	while (p) {
//		printf("%d ", p->val);
//		p = p->next;
//	}
//}
//
//void reverse_print(struct Node *p) {
//	if (!p) return;
//	reverse_print(p->next);
//	printf("%d ", p->val);
//}
//
//void concatenate(struct Node **l1, struct Node **l2, struct Node **l3) {
//	struct Node *p = (*l1)->next, *cur;
//	cur = *l3 = *l1;
//
//	while (p) {
//		cur->next = p;
//		cur = p;
//		p = p->next;
//	}
//
//	p = (*l2);    //
//	while (p) {
//		cur->next = p;
//		cur = p;
//		p = p->next;
//	}                         
//	l1 = l2 = NULL;
//}
//
//int main() {
//	struct Node *l1, *l2, *l3;
//	int n;
//
//	printf("How many nodes do you want for list 1?\n");
//	scanf("%d", &n);
//	printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
//	reverse_construct(&l1, n);
//
//	printf("How many nodes do you want for list 2?\n");
//	scanf("%d", &n);
//	printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
//	reverse_construct(&l2, n);
//
//	concatenate(&l1, &l2, &l3);
//
//	print(l3);
//	release(l3);
//	return 0;
//}
//76
//double fun1(int n)
//{
//	double sum = 0;
//	int i = 1;
//	while (i <= n)
//	{
//		sum = sum + 1.0/i;
//		i = i + 2;
//	}
//	return sum;
//}
//double fun2(int n)
//{
//	double sum = 0;
//	int i = 2;
//	while (i <= n)
//	{
//		sum = sum + 1.0 / i;
//		i = i + 2;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 15;
//	double sum ;
//	if (n % 2 == 1)
//	{
//		sum = fun1(n);
//	}
//	else
//		sum = fun2(n);
//	printf("%f ", sum);
//}
//78
//static struct man
//{
//	char name[20];
//	int age;
//}person[4] = {"li",18,"wang",19,"zhang",20,"sun",22};
//
//int main()
//{
//	struct man *q, *p;
//	int i, m = 0;
//	p = person;
//	for (i = 0; i < 4; ++i)
//	{
//		if (m < p->age)
//		{
//			q = p;
//			p++;
//			m = q->age;
//		}
//	}
//	printf("%s,%d", (*q).name, (*q).age);
//}
//79
//void swap(char **s1, char **s2) {
//	char *t;
//	t = *s1;
//	*s1 = *s2;
//	*s2 = t;
//}
//int main()
//{
//	char str[3][20];
//	printf("Please input three strings\n");
//	scanf("%s",str[0]);
//	scanf("%s",str[1]);
//	scanf("%s",str[2]);
//	if (strcmp(str[0], str[1]) > 0)
//	{
//		swap(&str[0], &str[1]);
//	}
//	if (strcmp(str[0], str[2]) > 0)
//	{
//		swap(&str[0], &str[2]);
//	}
//	if (strcmp(str[1], str[2]) > 0)
//	{
//		swap(&str[1], &str[2]);
//	}
//	printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
//}
//80
//int main()
//{
//	int j;
//	for (int i = 4; i < 10000; i += 4)
//	{
//		int temp = i;
//		int cnt = 0;
//		for (int k = 0; k < 5; ++k)
//		{
//			j = temp / 4 * 5 + 1;
//			temp = j;
//			if (j % 4 == 0)
//				cnt++;
//			else
//				break;
//		}
//		if (cnt == 4)
//		{
//			printf("%d ", temp);
//			break;
//		}
//	}
//	return 0;
//}
//81
//int main()
//{
//	int i;
//	for (i = 10; i < 100; ++i)
//	{
//		if ((i * 8) < 100 && (i * 9) > 100)
//		{
//			if (809 * i == 800 * i + 9 * i + 1)
//			{
//				printf("%d ", i);
//			}
//		}
//	}
//	return 0;
//}
//82
//int main()
//{
//	char *p, s[6];
//	int n=0;
//	p = s;
//	gets(p);
//	while (*(p) != '\0')
//	{
//		n = n * 8 + *p - 48;
//		p++;
//	}
//	printf("%d", n);
//}
//83
//int main()
//{
//	long sum = 4, s = 4;
//	int j;
//	for (j = 2; j <= 8; ++j)
//	{
//		if (j == 2)
//			s *= 7;
//		else
//			s *= 8;
//		sum += s;
//	}
//	printf("\nsum=%ld", sum);
//	return 0;
//}
//84
//int isPrime(int n) {
//	int i;
//	if (n == 2) return 1;
//	for (i = 2; i * i <= n; ++i) {
//		if (n % i == 0) return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int n;
//	printf("输入一个偶数:");
//	scanf("%d", &n);
//	for (int i = 2; i <= n/2; ++i)
//	{
//		if (isPrime(i) == 1 && isPrime(n - i) == 1)
//		{
//			printf("%d = %d + %d\n", n, i, n - i);
//		}
//	}
//	return 0;
//}
//85
//int main()
//{
//	int n;
//	printf("输入一个素数：");
//	scanf("%d",&n);
//	int cnt = 1;
//	long int i;
//	for (i = 9; i%n != 0; i = i * 10 + 9)
//	{
//		cnt++;
//	}
//	printf("能被%d个9整除", cnt);
//	return 0;
//}
//void stringcat(char *new, char *s1, char *s2) {
//	int i = 0, j = 0;
//	while (s1[i] != '\0') 
//	{
//		new[i] = s1[i];
//		++i;
//	}
//	while (s2[j] != '\0')
//	{
//		new[i] = s2[j];
//		i++;
//		j++;
//	}
//	new[i] = 0;
//}
//
//int main() {
//	char s1[] = "Hello ", s2[] = "World!", s3[100];
//	stringcat(s3, s1, s2);
//	printf("%s\n", s3);
//	return 0;
//}
//87
//struct student
//{
//	int x;
//	char c;
//}a;
//f(struct student b)
//{
//	b.x = 20;
//	b.c = 'y';
//}
//
//int main()
//{
//	a.x = 3;
//	a.c = 'a';
//	f(a);
//	printf("%d,%c", a.x, a.c);
//}
//88
//int main()
//{
//	int n, i, j;
//	for (i = 0; i < 7; ++i) 
//	{
//		scanf("%d", &n);
//		for (j = 0; j < n; ++j)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}
//89
//void swap(int *m, int *n)
//{
//	int temp = *m;
//	*m = *n;
//	*n = temp;
//}
//int main()
//{
//	int n;
//	printf("输入一个4位数:");
//	scanf("%d", &n);
//	int num[4] = { n / 1000,n % 1000 / 100,n % 100 / 10,n % 10 };
//	for (int i = 0; i < 4; ++i)
//	{
//		num[i] = (num[i] + 5) % 10;
//	}
//	swap(&num[0], &num[3]);
//	swap(&num[1], &num[2]);
//	printf("\n加密后的数据：");
//	for (int i = 0; i < 4; ++i)
//	{
//		printf("%d", num[i]);
//	}
//}
//90
//#define M 5
//int main()
//{
//	int a[M] = { 1,2,3,4,5 };
//	int i, j, t;
//	i = 0; j = M - 1;
//	while (i<j)
//	{
//		t = *(a + i);
//		*(a + i) = *(a + j);
//		*(a + j) = t;
//		i++; j--;
//	}
//	for (i = 0; i < M; ++i)
//		printf("%d", *(a + i));
//}
//int main() {
//	FILE *fp = fopen("097.db", "w");
//	char c;
//	while ((c = getchar()) && c != '#') {
//		fprintf(fp, "%c", c);
//	}
//	fclose(fp);
//	return 0;
//}
//int main()
//{
//	FILE *fp;
//	char ch, filename[10];
//	scanf("%s", filename);
//	if ((fp = fopen(filename, "w")) == NULL)
//	{
//		printf("cannot open file\n");
//		exit(0);
//	}
//	ch = getchar();
//	while (ch != '#')
//	{
//		fputc(ch, fp);
//		putchar(ch);
//		ch = getchar();
//	}
//}
//98
//int main()
//{
//	FILE *fp;
//	char str[100], filename[10];
//	int i = 0;
//	if ((fp = fopen("test", "w")) == NULL)
//	{
//		printf("cannot open the file\n");
//		exit(0);
//	}
//	printf("Please input a string:\n");
//	gets(str);
//	while (str[i] != '!')
//	{
//		if (str[i] >= 97 && str[i] <= 122)
//		{
//			str[i] = str[i] - 32;
//		}
//		fputc(str[i], fp);
//		i++;
//	}
//	fclose(fp);
//	fp = fopen("test", "r");
//	fgets(str, strlen(str) + 1, fp);
//	printf("%s\n", str);
//	fclose(fp);
//	return 0;
//}

//int main()
//{
//	FILE *fpA,*fpB,*fpC;
//	int i, j, n, ni;
//	char c[160], t, ch;
//
//
//
//	if ((fpA = fopen("A", "r")) == NULL)
//	{
//		printf("file A cannot be opened\n");
//		exit(0);
//	}
//	printf("A contents are:\n");
//	for (i = 0; (ch = fgetc(fpA)) != EOF; ++i)
//	{
//		c[i] = ch;
//		putchar(c[i]);
//	}
//	fclose(fpA);
//	ni = i;
//
//
//	if ((fpB = fopen("B", "r")) == NULL)
//	{
//		printf("file B cannot be oppened\n");
//		exit(0);
//	}
//	printf("B contents are :\n");
//	for (i = 0; (ch = fgetc(fpB)) != EOF; ++i)
//	{
//		c[i] = ch;
//		putchar(c[i]);
//	}
//	fclose(fpB);
//	n = i;
//
//	for (i = 0; i < n; ++i)
//	{
//		printf("%c", c[i]);
//		for (j = i + 1; j < n; ++j)
//		{
//			if (c[i] > c[j])
//			{
//				t = c[i];
//				c[i] = c[j];
//				c[j] = t;
//			}
//		}
//	}
//
//	printf("\n C file is:\n");
//	fpC = fopen("C", "w");
//	for (i = 0; i < n; ++i)
//	{
//		putc(c[i], fpC);
//		putchar(c[i]);
//	}
//	fclose(fpC);
//	return 0;
//}
//
//100
struct student
{
	char num[6];
	char name[8];
	int score[3];
	float avr;
}stu[5];
int main()
{
	int i, j, sum;
	FILE *fp;
	for (i = 0; i < 5; ++i)
	{
		printf("please input No.%d score:\n", i+1);
		printf("stuNo:");
		scanf("%s",stu[i].num);
		printf("name:");
		scanf("%s",stu[i].name);
		sum = 0;
		for (j = 0; j < 3; ++j)
		{
			printf("score%d:", j + 1);
			scanf("%d", &stu[i].score[j]);
			sum += stu[i].score[j];
		}
		stu[i].avr = sum / 3.0;
		printf("\n");
	}
	fp = fopen("stud", "w");
	for (i = 0; i < 5; ++i)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);
	return 0;
}
