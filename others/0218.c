//#include<stdio.h>
//
//
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
//	scanf("%d", &year);
//	printf("输入月:\n");
//	scanf("%d", &month);
//	if (month < 1 || month>12)
//		return -1;
//	printf("输入日:\n");
//	scanf("%d", &day);
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
//	if (isLeapyear(year) == 1 && month >= 3)
//	{
//		sum++;
//	}
//	printf("%d月%d日是%d年的第%d天", month, day, year, sum);
//	return 0;
//}
//从键盘上输入字符，将小写字母转换成大写字母。输入“ctl + z” 结束 
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char c;
//	while (rewind(stdin), scanf("%c", &c))
//	{
//		if (c >= 'a'&&c <= 'z')
//		{
//			c = c - 32;
//		}
//		printf("%c\n", c);
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char c;
//	int alpcnt = 0, numcnt = 0, othcnt = 0;
//	while (rewind(stdin), scanf("%c", &c))
//	{
//		if (c >= 'A'&&c <= 'z')
//			alpcnt++;
//		else if (c >= '0'&&c <= '9')
//			numcnt++;
//		else
//			othcnt++;
//	}
//	int a[3] = { alpcnt,numcnt,othcnt };
//	char s[3][10] = { "alp","num","oth" };
//	//排序
//	int i, j, k, temp; char t[10];
//	for (i = 1; i < 3; ++i)
//	{
//		temp = a[i-1];
//		strcpy(t, s[i - 1]);
//		k = i - 1;
//		for (j = i; j < 3; ++j)
//		{
//			if (a[j] > temp)
//			{
//				temp = a[j];
//				k = j;
//			}
//		}
//		a[k] = a[i - 1];
//		strcpy(s[i-1], s[k]);
//		a[i - 1] = temp;
//		strcpy(s[k], t);
//
//	}
//	//输出
//	printf("%d\t", a[0]);
//	for (i = 0; i < a[0] - a[1];++i)
//		printf("\n*****\t");
//	printf("%d\t", a[1]);
//	for (i = 0; i < a[1] - a[2];++i)
//		printf("\n*****\t*****\t");
//	printf("%d\t", a[2]);
//	for (i = 0; i < a[2]; ++i)
//		printf("\n*****\t*****\t*****");
//	printf("\n%s\t%s\t%s\n",s[0],s[1],s[2]);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a[] = { 5,7,8,1,5,6 };
//	int i, j, k, temp;
//	for (i = 1; i < 6; ++i)
//	{
//		temp = a[i - 1];
//		k = i - 1;
//		for (j = i; j < 6; ++j)
//		{
//			if (a[j] > temp)
//			{
//				temp = a[j];
//				k = j;
//			}
//		}
//		a[k] = a[i - 1];
//		a[i - 1] = temp;
//	}
//	for (i = 0; i < 6; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//3
//#include<stdio.h>
//void fun(int n)
//{
//	if (n >= 2)
//		fun(n / 2);
//	printf("%d", n % 2);
//}
//
//int main()
//{
//	int i;
//	while (scanf("%d", &i))
//	{
//		fun(i);
//		printf("\n");
//	}
//	return 0;
//}
//2转10
//#include<stdio.h>
//
//int main()
//{
//	int n;
//	int i,sum;
//	while (scanf("%d",&n))
//	{
//		sum = 0, i = 1;
//		sum= n % 2;
//		n = n / 10;
//		while (n != 0)
//		{
//			if (n % 2 == 1)
//			{
//				sum = sum + i * 2;
//				i = i * 2;
//			}
//			else
//				i = i * 2;
//			n = n / 10;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}
//10转16
//#include<stdio.h>
//void fun(int n)
//{
//	if (n >= 16)
//		fun(n / 16);
//	if (n % 16 <= 9)
//		printf("%d", n % 16);
//	else if (n % 16 == 10)
//		printf("%c", 'A');
//	else if (n % 16 == 11)
//		printf("%c", 'B');
//	else if (n % 16 == 12)
//		printf("%c", 'C');
//	else if (n % 16 == 13)
//		printf("%c", 'D');
//	else if (n % 16 == 14)
//		printf("%c", 'E');
//	else
//		printf("%c", 'F');
//}
//int main()
//{
//	int n; 
//	while (scanf("%d",&n))
//	{
//		fun(n);
//		printf("\n");
//	}
//	return 0;
//}
//16转10
//#include<stdio.h>
//int change(char c)
//{
//	int i;
//	switch (c)
//	{
//	case 'A':i = 10; break;case 'B':i = 11; break;case 'C':i = 12; break;
//	case 'D':i = 13; break;case 'E':i = 14; break;case 'F':i = 15; break;
//	case '0':i = 0; break;case '1':i = 1; break;case '2':i = 2; break;
//	case '3':i = 3; break;case '4':i = 4; break;case '5':i = 5; break;
//	case '6':i = 6; break;case '7':i = 7; break;case '8':i = 8; break;
//	case '9':i = 9; break;
//	default:
//		break;
//	}
//	return i;
//}
//int main()
//{
//	char s[10] = {0};
//	int i,sum;
//	int temp;
//	while (rewind(stdin), scanf("%s",s))
//	{
//		sum = 0; i = 0;
//		while (s[i] != '\0')
//		{
//			temp = change(s[i]);
//			if (s[i + 1] != '\0')
//			{
//				sum = sum + temp * 16;
//			}
//			else
//				sum = sum + temp;
//			i++;
//		}
//		
//		printf("%d\n", sum);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n;
//	int cnt, i;
//	while (scanf("%d",&n))
//	{
//		i = 1; cnt = 0;
//		while (i <= n)
//		{
//			if (n == (n | i))
//				cnt++;
//			i = i << 1;
//		}
//		printf("%d有%d个1\n", n, cnt);
//	}
//	return 0;
//}
//有101个整数，其中有50个数出现了两次，1个数出现了一次， 找出出现了一次的那个数
//#include<stdio.h>
//int main()
//{
//	int a[11] = { 10,11,12,13,14,14,13,12,15,11,10 };
//	int i=0;
//	for (int j = 0; j < 11; ++j)
//	{
//		i = i^a[j];
//	}
//	printf("%d", i);
//	return 0;
//}
#include<stdio.h>
#include<math.h>

//判断闰年
int isLeapyear(int n)
{
	if (n % 4 == 0 && n % 100 != 0)
	{
		return 1;
	}
	else if (n % 400 == 0)
		return 1;
	else return 0;
}
//int main()
//{
//	int daySum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//	int year, month, day;
//	printf("输入年:\n");
//	scanf("%d", &year);
//	printf("输入月:\n");
//	scanf("%d", &month);
//	//保证月份合法
//	if (month < 1 || month>12)
//		return -1;
//	printf("输入日:\n");
//	scanf("%d", &day);
//	//保证日合法
//	if (day > (daySum[month] - daySum[month - 1]))
//	{
//		//若是闰年2月
//		if (isLeapyear(year) == 1 && month == 2) 
//		{
//			if (day > 29)
//				return -1;
//		}
//		else
//			return -1;
//	}
//	int sum;
//	//总日等于前面月份总日加当月
//	sum = daySum[month] + day;
//	//若是闰年且超过2月，加一天
//	if (isLeapyear(year) == 1 && month >= 3)
//	{
//		sum++;
//	}
//	printf("%d月%d日是%d年的第%d天", month, day, year, sum);
//	return 0;
//}

int fun(int year,int month,int day) //总天数函数
{
	int daySum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	if (month < 1 || month>12)
		return -1;
	if (day > (daySum[month] - daySum[month - 1]))
	{
		if (isLeapyear(year) == 1 && month == 2)
		{
			if (day > 29)
				return -1;
		}
		else
			return -1;
	}
	int sum;
	
	sum = daySum[month-1] + day;
	
	if (isLeapyear(year) == 1 && month >= 3)
	{
		sum++;
	}
	
	return sum;
}

int diffDays(int year1, int year2, int sum1, int sum2)// 天数差距函数
{
	int i = 0, j;

	if (year1 > year2)
	{
		for (j = year2 + 1; j < year1; ++j)
		{
			i = i + 365 + isLeapyear(j);
		}
		i = i + 365 - sum2 + sum1 + isLeapyear(year2);
	}
	else if (year1 < year2)
	{
		for (j = year1 + 1; j < year2; ++j)
		{
			i = i + 365 + isLeapyear(j);
		}
		i = i + 365 - sum1 + sum2 + isLeapyear(year1);
	}
	else
		i = abs(sum1 - sum2);
	return i;
}

int week(int year,int sum) //计算星期
{
	int x = 2;//以2019年1月1日是星期二作为参考
	int i = diffDays(year, 2019, sum, 1);//输入日期与2019-1-1相差的天数
	int y; //y记录输入日期的星期
	if (year >= 2019)
	{
		y = (x + i) % 7;
		//if (y == 0)
		//	printf("这天是星期天\n");
		//else
		//	printf("这天是星期%d\n", y);
	}
	else
	{
		y = (7 + (x - i) % 7) % 7;
		//if (y == 0)
		//	printf("这天是星期天\n");
		//else
		//	printf("这天是星期%d\n", y);
	}
	return y;
}
//void newDate(int n, int year, int month, int day, int x)
//{
//	int monDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	monDay[2] = 28 + isLeapyear(year);
//	if (n == 0)
//	{
//		printf("是%d年%02d月%02d日\n", year, month, day);
//		if (x == 0)
//			printf("这天是星期天\n");
//		else
//			printf("这天是星期%d\n", x);
//	}
//	else
//	{
//		x = (x + 1) % 7;
//		day++;
//		if (day > monDay[month])
//		{
//			month++;
//			day = 1;
//		}
//		if (month > 12)
//		{
//			year++;
//			month = 1;
//		}
//		newDate(n - 1, year, month, day, x);
//	}
//}

//int main()
//{
//	int year, month, day;
//	printf("输入年："); scanf("%d",&year);
//	printf("输入月："); scanf("%d",&month);
//	printf("输入日："); scanf("%d",&day);
//	int sum = fun(year,month,day);
//	int x = week(year, sum);
//	int n;
//	printf("\n经过几天后？：");
//	scanf("%d",&n);
//	printf("经过%d天后", n);
//	newDate(n, year, month, day, x);
//	return 0;
//}





//输出一个月份
//int main()
//{
//	int year, month,x;
//	printf("输入年：");
//	scanf("%d",&year);
//	printf("输入月：");
//	scanf("%d",&month);
//	x = week(year, 1);//记录输入年份1月1日的星期
//	int monDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	//若是闰年
//	if (isLeapyear(year))
//	{
//		monDay[2]++;
//	}
//	//保证月份合法
//	if (month < 1 || month>12)
//		return -1;
//
//	int sum = 1, i;
//	
//	for (i = 0; i < month; ++i)
//	{
//		sum = monDay[i] + sum;
//	}
//	 x = (x + sum - 1) % 7;//记录输入月份的1号为星期几
//	 printf("%d", x);
//	printf("\n\t\t     %d年%d月\nSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n", year, month);
//	for (i = 1; i <= x; ++i)
//	{
//		printf("   \t");
//	}
//	for (i = 1; i <= monDay[month]; ++i)
//	{
//		printf("%3d\t", i);
//		if ((x + i - 1) % 7 == 6)
//			printf("\n");
//	}
//	return 0;
//}

//输出一个年份
void print(int year,int month1, int month2,int x)
{
	int monDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//若是闰年
	if (isLeapyear(year))
	{
		monDay[2]++;
	}
	printf("| %2d  SUN MON TUE WED THU FRI SAT   %2d  SUN MON TUE WED THU FRI SAT |\n", month1, month2);

	int sum = 1,sum2=1, i , j=1;//i记录月份1的日，j记录月份2的日
	int week1, week2;//记录month1一号与month2一号的星期

	for (i = 0; i < month1; ++i)
	{
		sum = monDay[i] + sum;
	}
	for (i = 0; i < month2; ++i)
	{
		sum2 = monDay[i] + sum2;
	}
	week1 = (x + sum - 1) % 7;//记录输入月份的1号为星期几
	week2 = (x + sum2 - 1) % 7;//记录输入月份2的1号为星期几
	printf("      ");
	for (i = 1; i <= week1; ++i)
	{
		printf("    ");
	}
	int k = 1;
	i = 1;
	int m;//记录最后左月份空格
	int ret = 0;//记录右边月份最后有没有换行
	while(i <= monDay[month1] || j <= monDay[month2]) 
	{
		if (i <= monDay[month1])
		{
			printf("%3d ", i);    //输出左边月份的日期
		}
		if ((week1 + i - 1) % 7 == 6)  //如果到周六就空格输出右边月份
		{
			printf("      ");
			for (; k <= week2; ++k)
			{
				printf("    ");
			}
			while (j <= monDay[month2]) 
			{
				printf("%3d ", j);  //输出右边月份
				if ((week2 + j - 1) % 7 == 6) //如果到周六就换行
				{
					if (j < monDay[month2]) //此条件防止周六是月尾换多一行
					{
						printf("\n      ");
						j++;
						break;
					}
				}
				j++;
			}
			
		}
		if (i <= monDay[month1] && j > monDay[month2]) //情况一，右月份完了左月份没完
		{
			if (ret == 0) //记录换行情况，只会换一次行
			{
				if (i < monDay[month1])//此条件防止多换行
				{
					printf("\n      ");
					ret = 1; 
				}
			}
			while (i > monDay[month1])
			{
				printf("%3d ", i);  //输出左边剩余日期
				i++;
			}
		}
		if (i <= monDay[month1]) //一般情况
		{
			i++;
		}
		if (i > monDay[month1] && j <= monDay[month2])//情况二，左月份完了右边没完
		{
			int weeklast = week(year, fun(year, month1, monDay[month1]));//记录左边月底星期
			if (weeklast == 6 && ret == 0) //若左边月底为周六且此情况下没换过行，
			{
				for (m = 7; m > 0; m--)    //则在上面输完右边月份换行之后要隔7个日的空格
				{
					printf("    ");
				}
			}
			for ( m = 6 - weeklast; m > 0; m--)//把左边月份剩余星期空格完
			{
				printf("    ");
			}
			printf("      ");
			while (j <= monDay[month2]) //开始输出右边剩余日
			{

				if (ret == 1)   //如果此while循环换过行要隔7个日的空格
				{

					for (m = 7; m > 0; m--)
					{
						printf("    ");
					}
					printf("      ");
					ret = 0;
				}
				printf("%3d ", j); //输出
				if ((week2 + j - 1) % 7 == 6)//到周六换行，记录换行标志
				{
					if (j < monDay[month2])//防止月尾即周六多换一行
					{
						printf("\n      ");
						ret = 1;
					}
				}
				j++;
			}
			
		}
	}
	printf("\n");
}

int main()
{
	int year, month, x;
	while (printf("输入年："),scanf("%d", &year) != EOF)
	{
		x = week(year, 1);

		printf("|--------------------The Celender of Year %4d ---------------------|\n", year);
		for (int i = 1; i <= 6; ++i)
		{
			print(year, i, i + 6, x);
		}
		printf("|-------------------------------------------------------------------|\n");
	}
	return 0;
}
