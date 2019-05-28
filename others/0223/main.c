#include"func.h"

int main()
{
	pNode phead1, ptail1, phead2, ptail2;
	DataType c;
	phead1 = ptail1 = phead2 = ptail2 = NULL;
	printf("请输入第一个数:\n");
	while (scanf("%c", &c) != EOF)
	{
		headInsert(&phead1, &ptail1, c);
	}
	delVal(&phead1, &ptail1, '\n');//多读了一个'\n'，删除
	//reList(&phead1, &ptail1);
	//print(phead1);
	printf("请输入第二个数:\n");
	while (scanf("%c", &c) != EOF)
	{
		headInsert(&phead2, &ptail2, c);
	}
	delVal(&phead2, &ptail2, '\n');
	//reList(&phead2, &ptail2);
	//print(phead2);
	
	pNode get = myPlus(&phead1, &phead2);//加法
	ptail2 = NULL;

	listCaryy(phead1, get, &ptail1);//进位
	reList(&phead1, &ptail1);//逆置
	printf("\n相加后：\n");
	print(phead1);//输出
	system("pause");
	return 0;
}
