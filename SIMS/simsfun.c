#include"sism.h"

//尾插法
void tailInsert(pusr_account *phead, pusr_account *ptail, usr_account *val)
{
	pusr_account pnew = (pusr_account)malloc(sizeof(usr_account));
	memset(pnew, 0, sizeof(usr_account));
	*pnew = *val;
	if (NULL == *ptail)
	{
		*phead = pnew;
		*ptail = pnew;
		(*ptail)->pnext = NULL;
	}
	else
	{
		(*ptail)->pnext = pnew;
		*ptail = pnew;
		(*ptail)->pnext = NULL;
	}
}

//有序插入
void sortInsert(pusr_infor *phead, pusr_infor *ptail, usr_infor *val)
{
	pusr_infor pnew = (pusr_infor)malloc(sizeof(usr_infor));
	memset(pnew, 0, sizeof(usr_infor));
	*pnew = *val;
	pusr_infor ppre, pcur;
	pcur = ppre = *phead;
	if (NULL == *phead)
	{
		*phead = pnew;
		*ptail = pnew;
	}
	else if (pnew->usr_id < pcur->usr_id)
	{
		pnew->pnext = *phead;
		*phead = pnew;
	}
	else
	{
		while (pcur)
		{
			if (pnew->usr_id < pcur->usr_id)
			{
				pnew->pnext = pcur;
				ppre->pnext = pnew;
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if (NULL == pcur)
		{
			(*ptail)->pnext = pnew;
			*ptail = pnew;
			(*ptail)->pnext = NULL;
		}
	}
	pnew = ppre = pcur = NULL;
}

//删除学生信息结点
void del_usr(pusr_infor *phead, pusr_infor *ptail, int id)
{
	if (NULL == *phead)
	{
		system("cls");
		titleprint();
		printf("\n\t\t\t\t当前学生为空.\n\n\n");
		return;
	}
	else
	{
		pusr_infor pcur, ppre;
		pcur = ppre = *phead;
		if (id == pcur->usr_id)
		{
			*phead = pcur->pnext;
		}
		else
		{
			while (pcur)
			{
				if (id == pcur->usr_id)
				{
					if (pcur == *ptail)
					{
						*ptail = ppre;
						(*ptail)->pnext = NULL;
						break;
					}
					ppre->pnext = pcur->pnext;
					break;
				}
				ppre = pcur;
				pcur = pcur->pnext;
			}
			if (NULL == pcur)
			{
				return;
			}
			free(pcur);
		}
		pcur = ppre = NULL;
		system("cls");
		titleprint();
		printf("\n\t\t\t\t删除成功！\n\n\n");
	}
}

//删除用户信息结点
void del_account(pusr_account *phead, pusr_account *ptail, char *name)
{
	if (NULL == *phead)
	{
		printf("\n\t\t\t\t当前学生为空.\n\n\n");
	}
	else
	{
		pusr_account pcur, ppre;
		pcur = ppre = *phead;
		if (0 == strcmp(pcur->usr_name,name))
		{
			*phead = pcur->pnext;
		}
		else
		{
			while (pcur)
			{
				if (0 == strcmp(pcur->usr_name, name))
				{
					ppre->pnext = pcur->pnext;
					break;
				}
				if (pcur == *ptail)
				{
					*ptail = ppre;
					(*ptail)->pnext = NULL;
					break;
				}
				ppre = pcur;
				pcur = pcur->pnext;
			}
			if (NULL == pcur)
			{
				printf("\n\t\t\t\t找不到此用户！请确认用户名！\n\n\n");
			}
			free(pcur);
		}
		pcur = ppre = NULL;
	}
}

//打印表头
void titleprint()
{
	printf("*************************************************************************************\n");
	printf("****************************** 学 生 信 息 管 理 系 统 ******************************\n");
	printf("*************************************************************************************\n\n");
}

//系统初始化
void system_init(const char *configure_filename, pusr_account *pachead,pusr_account *pactail, pusr_infor *pifhead, pusr_infor *piftail)
{
	FILE *fp,*fp1,*fp2;
	usr_account usrAccount;
	usr_infor usrInfor;
	char filename[2][20] = {0};
	fp = fopen(configure_filename, "r");
	if (NULL == fp)
	{
		perror("fopen");
	}
	fscanf(fp, "%s", filename[0]); 
	fscanf(fp, "%s", filename[1]);
	fclose(fp);
	//用户信息文件
	fp1 = fopen(filename[0], "r+");
	if (NULL == fp1)
	{
		perror("fopen");
	}
	while (memset(&usrAccount, 0, sizeof(usrAccount)), (fscanf(fp1, "%s%s%d", usrAccount.usr_name, usrAccount.usr_pwd, &usrAccount.usr_role)) != EOF)
	{
		tailInsert(pachead, pactail, &usrAccount);
	}
	fclose(fp1);
	//学生信息文件
	fp2 = fopen(filename[1], "r+");
	if (NULL == fp2)
	{
		perror("fopen");
	}
	while (memset(&usrInfor, 0, sizeof(usrInfor)), (fscanf(fp2, "%d%s%f", &usrInfor.usr_id, usrInfor.name, &usrInfor.score)) != EOF)
	{
		//printf("%d %s %.2f\n", usrInfor.usr_id, usrInfor.name, usrInfor.score);
		sortInsert(pifhead, piftail, &usrInfor);
	}
	fclose(fp2);
}

//确认账号密码及其权限
USR_ROLE role_confirm(char *name, char *pwd, pusr_account pachead)
{
	pusr_account pcur = pachead;
	while (pcur)
	{
		if (0 == strcmp(pcur->usr_name, name))
		{
			if (0 == strcmp(pcur->usr_pwd, pwd))
				return pcur->usr_role;
			else
				return -1;
		}
		pcur = pcur->pnext;
	}
	return -1;
}

// 主界面，根据权限展示系统菜单
MEMUORDER show_system_memu(USR_ROLE role)
{
	char i, j;
	MEMUORDER k;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t1.学生信息系统");
	if (1 == role)
	{
		printf("\t\t2.用户信息系统");
	}
	printf("\n\n\t\t\t9.退出系统");
	SELECT;

	rewind(stdin);
	scanf("%c", &i);

	system("cls");
	titleprint();
	if ('9' == i)
	{
		return 9;
	}
	else if ('0' == i)
	{
		return 0;
	}
	else if ('1' == i)
	{
	Loop2:
		printf("\t\t\t1.查询学生信息");
		if (1 == role)
		{
			printf("\t\t2.添加学生信息\n");
			printf("\n\t\t\t3.修改学生信息\t\t4.删除学生信息");
		}
		SELECT;
		rewind(stdin);
		scanf("%c", &j);
		if ('0' == j)
		{
			goto Loop;
		}
		else if ('1' == j)                     //1-1
		{
			k = show_search_usr_memu(role);
			if (0 == k)
			{
				system("cls");
				titleprint();
				goto Loop2;
			}
			else if (1 == k)            //1-1-1,按名字查
			{
				return 111;
			}
			else if (2 == k)           //1-1-2，按学号查
			{
				return 112;
			}
			else                      //1-1-3,管理员权限，查看全部
				return 113;
		}
		else if ('2' == j && 1 == role) //1-2，添加
		{
			return 12;
		}
		else if ('3' == j && 1 == role) //1-3，修改
		{
			return 13;
		}
		else if ('4' == j && 1 == role)//1-4，删除
		{
			return 14;
		}
		else
		{
			system("cls");
			titleprint();
			goto Loop2;
		}
	}
	else if ('2' == i && 1 == role)
	{
	Loop3:
		printf("\t\t\t1.查询用户信息\t\t2.添加用户信息\n");
		printf("\n\t\t\t3.修改用户信息\t\t4.删除用户信息");
		SELECT;
		rewind(stdin);
		scanf("%c", &j);
		if ('0' == j)
		{
			goto Loop;
		}
		else if ('1' == j) //2-1
		{
			k = show_search_account_memu();
			if (0 == k)  
			{
				system("cls");
				titleprint();
				goto Loop3;
			}
			else if (1 == k)  //2-1-1，按用户名查
			{
				return 211;
			}
			else             //2-1-2，查看全部用户
				return 212;
		}
		else if ('2' == j) //2-2，添加用户
		{
			return 22;
		}
		else if ('3' == j) //2-3，修改用户
		{
			return 23;
		}
		else if ('4' == j) //2-4，删除用户
		{
			return 24;
		}
		else
		{
			system("cls");
			titleprint();
			goto Loop3;
		}
	}
	else
	{
		goto Loop;
	}
	system("pause");
}

//根据权限查找学生菜单
MEMUORDER show_search_usr_memu(USR_ROLE role)
{
	MEMUORDER i;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t\t1.按名字查询\n\n\t\t\t\t2.按学号查询");
	if (1 == role)
	{
		printf("\n\n\t\t\t\t3.查看全部");
	}
	SELECT;
	rewind(stdin);
	scanf("%d", &i);
	if (0 == i)
	{
		return 0;
	}
	else if (1 == i)
	{
		return 1;
	}
	else if (2 == i)
	{
		return 2;
	}
	else if (3 == i && 1 == role)
	{
		return 3;
	}
	else
	{
		goto Loop;
	}
	system("pause");
}

//展示查找用户菜单
MEMUORDER show_search_account_memu()
{
	MEMUORDER i;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t\t1.按用户名查询\n\n\t\t\t\t2.查看全部");
	SELECT;
	rewind(stdin);
	scanf("%d", &i);
	if (0 == i)
	{
		return 0;
	}
	else if (1 == i)
	{
		return 1;
	}
	else if (2 == i)
	{
		return 2;
	}
	else
	{
		goto Loop;
	}
	system("pause");
}


//学号查找，返回当前指针
pusr_infor get_usr_info_by_id(pusr_infor phead, int id)
{
	pusr_infor pcur;
	pcur = phead;
	while (pcur)
	{
		if (pcur->usr_id == id)
		{
			return pcur;
			
		}
		if (pcur->usr_id > id)
		{
			break;
		}
		pcur = pcur->pnext;
	}
	return NULL;
}

//根据学号查找学生信息
void search_usr_info_by_id(pusr_infor phead) 
{
	int i;
	char id[20];
	pusr_infor pcur;
	
Loop:
	system("cls");
	titleprint();
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请输入要查询的学号：");
	memset(id, 0, sizeof(id));
	scanf("%s",id);
	if (0 == strcmp(id,"0"))
	{
		pcur = NULL;
		return ;
	}
	i = atoi(id);
	pcur = get_usr_info_by_id(phead, i);
	system("cls");
	titleprint();
	if (NULL == pcur)
	{
		printf("\n\n\t\t\t\t查询失败！\n\n\n");
	}
	else
	{
		printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
	}
	system("pause");
	goto Loop;
}

//根据名字查找学生信息
void search_usr_info_by_name(pusr_infor phead)
{
	char name[20];
	pusr_infor pcur;
	pcur = phead;
Loop:
	system("cls");
	titleprint();
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请输入要查询的名字：");
	memset(name, 0, sizeof(name));
	scanf("%s",name);
	if (0 == strcmp(name, "0"))
	{
		pcur = NULL;
		return;
	}
	while (pcur)
	{
		if (0 == strcmp(name, pcur->name))
		{
			system("cls");
			titleprint();
			printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
			system("pause");
			pcur = phead;
			goto Loop;
		}
		pcur = pcur->pnext;
	}
	system("cls");
	titleprint();
	printf("\n\n\t\t\t\t查询失败！\n\n\n");
	pcur = phead;
	system("pause");
	goto Loop;
}

//菜单2添加学生信息
void add_usr_info(pusr_infor *phead, pusr_infor *ptail)
{
	pusr_infor pnew, pcur;
	int id; char name[20]; float score;
	char idch[20]; char scorech[20];
	char order;
Loop:
	system("cls");
	titleprint();
	pcur = *phead;
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请按“学号 姓名 成绩”格式输入要添加的学生信息：\n\n\t\t\t");
	memset(name, 0, sizeof(name)); memset(idch, 0, sizeof(idch)); memset(scorech, 0, sizeof(scorech));
	rewind(stdin);
	scanf("%s",idch);
	if (0 == strcmp(idch, "0"))
	{
		pnew = pcur = NULL;
		return;
	}
	scanf("%s%s",name,scorech);
	id = atoi(idch); score = (float)atof(scorech);
	if (id <= 0 || (score <= 0 && strcmp(scorech,"0")!=0))
	{
		system("cls");
		titleprint();
		printf("\t\t\t\t学号或成绩输入错误！\n\n\n");
		system("pause");
		goto Loop;
	}
	while (pcur)
	{
		if (id == pcur->usr_id)
		{
			system("cls");
			titleprint();
			printf("\t\t\t已有学号为%d的学生！请确认学号或使用修改功能！\n\n\n", id);
			system("pause");
			goto Loop;
		}
		if (id < pcur->usr_id)
			break;
		pcur = pcur->pnext;
	}
Loop2:
	system("cls");
	titleprint();
	printf("\t\t\t\t需要添加的学生信息为：\n\n");
	printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", id, name, score);

	printf("0.返回\t1.确认\n请输入选项：");
	rewind(stdin);
	scanf("%c", &order);
	if ('0' == order)
	{
		goto Loop;
	}
	else if ('1' == order)
	{
		pnew = (pusr_infor)malloc(sizeof(usr_infor));
		pnew->usr_id = id;
		strcpy(pnew->name, name);
		pnew->score = score;
		pnew->pnext = NULL;
		sortInsert(phead, ptail, pnew);
		system("cls");
		titleprint();
		printf("\t\t\t\t学号为%d的学生信息添加成功！\n\n", id);
		system("pause");
		free(pnew);
		goto Loop;
	}
	else
	{
		goto Loop2;
	}
}

//菜单3修改学生信息
void update_usr_info(pusr_infor *phead)
{
	pusr_infor pcur;
	int id; char idch[20];
	char name[20];
	float score;  char scorech[20];
	char order;
Loop:
	system("cls");
	titleprint();
	pcur = *phead;
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请输入要修改信息的学生学号：");
	memset(idch, 0, sizeof(idch));
	rewind(stdin); scanf("%s", idch);
	if (0 == strcmp(idch, "0"))
	{
		pcur = NULL;
		return;
	}
	id = atoi(idch);
	pcur = get_usr_info_by_id(*phead, id);
Loop2:
	system("cls");
	titleprint();
	if (NULL == pcur)
	{
		printf("\n\t\t\t\t找不到此学生！请确认学号！\n\n\n");
	}
	else
	{
		printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
		printf("0.返回\t1.确认\n是否修改此信息，请输入选项：");
		rewind(stdin);  scanf("%c",&order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if('1'==order)
		{
			printf("\n\t\t\t\t请输入名字：");
			scanf("%s",name);
			printf("\n\t\t\t\t请输入成绩：");
			scanf("%s", scorech);
			score = (float)atof(scorech);
			if (score <= 0 && strcmp(scorech, "0") != 0)
			{
				system("cls");
				titleprint();
				printf("\t\t\t\t成绩输入错误！\n\n\n");
				system("pause");
				goto Loop2;
			}
		Loop3:
			system("cls");
			titleprint();
			printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", pcur->usr_id, name, score);
			printf("0.返回\t1.确认\n以上为修改后的信息，请输入选项：");
			rewind(stdin);  scanf("%c",&order);
			if ('0' == order)
			{
				goto Loop2;
			}
			else if ('1' == order)
			{
				strcpy(pcur->name, name);
				pcur->score = score;
				system("cls");
				titleprint();
				printf("\t\t\t\t修改成功！\n\n\n");
			}
			else
			{
				goto Loop3;
			}
		}
		else
		{
			goto Loop2;
		}
	}
	system("pause");
	goto Loop;
}

//菜单4删除学生信息
void dele_usr_info(pusr_infor *phead, pusr_infor *ptail)
{
	char order;
	char idch[20];
	int id;
	pusr_infor pget;
Loop:
	system("cls");
	titleprint();
	printf("\n（0.返回首页）\n");
	printf("\n\t\t\t请输入要删除的学号：");
	rewind(stdin);
	memset(idch, 0, sizeof(idch));
	scanf("%s",idch);
	if (0 == strcmp(idch,"0"))
	{
		pget = NULL;
		return;
	}
	id = atoi(idch);
	if (id <= 0)
	{
		system("cls");
		titleprint();
		printf("\t\t\t\t学号输入错误！\n\n\n");
		system("pause");
		goto Loop;
	}
	pget = get_usr_info_by_id(*phead, id);
Loop2:
	system("cls");
	titleprint();
	if (NULL == pget)
	{
		printf("\n\t\t\t\t找不到此学生！请确认学号！\n\n\n");
	}
	else
	{
		printf("\t\t\t\t学号：%6d\n\n\t\t\t\t名字：%6s\n\n\t\t\t\t成绩：%6.2f\n\n\n", pget->usr_id, pget->name, pget->score);
		printf("0.返回\t1.确认\n是否删除此信息，请输入选项：");
		rewind(stdin);  scanf("%c", &order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if ('1' == order)
		{
			del_usr(phead, ptail, id);
		}
		else
		{
			goto Loop2;
		}
	}
	system("pause");
	goto Loop;
}

//菜单5增加账号
void add_usr_account(pusr_account *phead, pusr_account *ptail)
{
	pusr_account pnew, pcur;
	char name[20];
	char pwd[20];
	char order;
Loop:
	system("cls");
	titleprint();
	pcur = *phead;
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请按“用户名 密码”格式输入要添加的用户信息：\n\n\t\t\t");
	memset(name, 0, sizeof(name)); memset(pwd, 0, sizeof(pwd));
	rewind(stdin);
	scanf("%s",name);
	if (0 == strcmp(name, "0"))
	{
		pnew = pcur = NULL;
		return;
	}
	scanf("%s",pwd);
	while (pcur)
	{
		if (0 == strcmp(pcur->usr_name,name))
		{
			system("cls");
			titleprint();
			printf("\t\t已有用户名为%s的用户！请另起名或使用修改功能！\n\n\n", name);
			system("pause");
			goto Loop;
		}
		pcur = pcur->pnext;
	}
Loop2:
	system("cls");
	titleprint();
	printf("\t\t\t\t需要添加的用户信息为：\n\n");
	printf("\t\t\t\t用户名：%s\n\n\t\t\t\t密码：%s\n\n\n", name, pwd);

	printf("0.返回\t1.确认\n请输入选项：");
	rewind(stdin);
	scanf("%c", &order);
	if ('0' == order)
	{
		goto Loop;
	}
	else if ('1' == order)
	{
		pnew = (pusr_account)malloc(sizeof(usr_account));
		strcpy(pnew->usr_name, name);
		strcpy(pnew->usr_pwd, pwd);
		pnew->usr_role = 0;
		pnew->pnext = NULL;
		tailInsert(phead, ptail, pnew);
		system("cls");
		titleprint();
		printf("\t\t\t\t%s用户信息添加成功！\n\n", name);
		system("pause");
		free(pnew);
		goto Loop;
	}
	else
	{
		goto Loop2;
	}
}

//菜单6修改账号信息
void updata_usr_account(pusr_account *phead)
{
	pusr_account pcur;
	char name[20];
	char pwd[20];
	char order;
Loop:
	system("cls");
	titleprint();
	pcur = *phead;
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请输入要修改信息的用户名：");
	memset(name, 0, sizeof(name));
	rewind(stdin); scanf("%s", name);
	if (0 == strcmp(name, "0"))
	{
		pcur = NULL;
		return;
	}
	while (pcur)
	{
		if (0 == strcmp(pcur->usr_name, name))
		{
			break;
		}
		pcur = pcur->pnext;
	}
Loop2:
	system("cls");
	titleprint();
	if (NULL == pcur)
	{
		printf("\n\t\t\t\t找不到此用户！请确认用户名！\n\n\n");
	}
	else
	{
		printf("\t\t\t\t用户名：%s\n\n\t\t\t\t密码：%s\n\n\n", pcur->usr_name, pcur->usr_pwd);
		printf("0.返回\t1.确认\n是否修改此信息，请输入选项：");
		rewind(stdin);  scanf("%c", &order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if ('1' == order)
		{
			printf("\n\t\t\t\t请输入新用户名：");
			scanf("%s",name);
			printf("\n\t\t\t\t请输入新密码：");
			scanf("%s",pwd);
		Loop3:
			system("cls");
			titleprint();
			printf("\t\t\t\t用户名：%s\n\n\t\t\t\t密码：%s\n\n\n", name, pwd);
			printf("0.返回\t1.确认\n以上为修改后的信息，请输入选项：");
			rewind(stdin);  scanf("%c", &order);
			if ('0' == order)
			{
				goto Loop2;
			}
			else if ('1' == order)
			{
				strcpy(pcur->usr_name, name);
				strcpy(pcur->usr_pwd, pwd);
				system("cls");
				titleprint();
				printf("\t\t\t\t修改成功！\n\n\n");
			}
			else
			{
				goto Loop3;
			}
		}
		else
		{
			goto Loop2;
		}
	}
	system("pause");
	goto Loop;
}

//菜单7删除用户账户
void dele_usr_account(pusr_account *phead, pusr_account *ptail)
{
	char order;
	char name[20];
	pusr_account pcur, ppre;
Loop:
	system("cls");
	titleprint();
	pcur = *phead;
	ppre = pcur;
	printf("\n（0.返回首页）\n");
	printf("\n\t\t\t请输入要删除的用户名：");
	rewind(stdin);
	memset(name, 0, sizeof(name));
	scanf("%s",name);
	if (0 == strcmp(name, "0"))
	{
		ppre = pcur = NULL;
		return;
	}
	while (pcur)
	{
		if (0 == strcmp(pcur->usr_name, name))
		{
			break;
		}
		ppre = pcur;
		pcur = pcur->pnext;
	}
Loop2:
	system("cls");
	titleprint();
	if (NULL == pcur)
	{
		printf("\n\t\t\t\t找不到此用户！请确认用户名！\n\n\n");
	}
	else
	{
		printf("\t\t\t\t用户名：%s\n\n\t\t\t\t密码：%s\n\n\n", pcur->usr_name, pcur->usr_pwd);
		printf("0.返回\t1.确认\n是否删除此信息，请输入选项：");
		rewind(stdin);  scanf("%c", &order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if ('1' == order)
		{
			if (pcur == *phead)
			{
				*phead = pcur->pnext;
			}
			if (pcur == *ptail)
			{
				*ptail = ppre;
				(*ptail)->pnext = NULL;
			}
			ppre->pnext = pcur->pnext;
			free(pcur);
			ppre = pcur = NULL;
			system("cls");
			titleprint();
			printf("\n\t\t\t\t删除成功！\n\n\n");
		}
		else
		{
			goto Loop2;
		}
	}
	system("pause");
	goto Loop;
}

//菜单8查询用户账号信息
void search_usr_account(pusr_account phead)
{
	char name[20];
	pusr_account pcur;
	pcur = phead;
Loop:
	system("cls");
	titleprint();
	printf("\n（0.返回首页）\n");
	printf("\t\t\t请输入要查询的用户名：");
	memset(name, 0, sizeof(name));
	scanf("%s", name);
	if (0 == strcmp(name, "0"))
	{
		pcur = NULL;
		return;
	}
	while (pcur)
	{
		if (0 == strcmp(name, pcur->usr_name))
		{
			system("cls");
			titleprint();
			printf("\t\t\t\t用户名：\t%s\n\n\t\t\t\t密码：\t\t%s\n\n\t\t\t\t管理员权限：\t%d\n\n\n", pcur->usr_name, pcur->usr_pwd, pcur->usr_role);
			system("pause");
			pcur = phead;
			goto Loop;
		}
		pcur = pcur->pnext;
	}
	system("cls");
	titleprint();
	printf("\n\n\t\t\t\t查询失败！\n\n\n");
	pcur = phead;
	system("pause");
	goto Loop;
}

//菜单9退出系统
void save_data(pusr_account *pachead, pusr_infor *pifhead, char *configure_filename)
{
	FILE *fp, *fp1, *fp2;
	pusr_account p1; p1 = *pachead;
	pusr_infor p2; p2 = *pifhead;
	char filename[2][20] = { 0 };
	fp = fopen(configure_filename, "r");
	if (NULL == fp)
	{
		perror("fopen");
	}
	fscanf(fp, "%s", filename[0]);
	fscanf(fp, "%s", filename[1]);
	fclose(fp);
	//用户信息文件
	fp1 = fopen(filename[0], "w+");
	if (NULL == fp1)
	{
		perror("fopen");
	}
	while (p1)
	{
		fprintf(fp1, "%s %s %d\n", p1->usr_name, p1->usr_pwd, p1->usr_role);
		p1 = p1->pnext;
	}
	fclose(fp1);
	//学生信息文件
	fp2 = fopen(filename[1], "w+");
	if (NULL == fp2)
	{
		perror("fopen");
	}
	while (p2)
	{
		fprintf(fp2, "%d %s %.1f\n", p2->usr_id, p2->name, p2->score);
		p2 = p2->pnext;
	}
	fclose(fp2);
}

