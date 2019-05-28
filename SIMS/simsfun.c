#include"sism.h"

//β�巨
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

//�������
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

//ɾ��ѧ����Ϣ���
void del_usr(pusr_infor *phead, pusr_infor *ptail, int id)
{
	if (NULL == *phead)
	{
		system("cls");
		titleprint();
		printf("\n\t\t\t\t��ǰѧ��Ϊ��.\n\n\n");
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
		printf("\n\t\t\t\tɾ���ɹ���\n\n\n");
	}
}

//ɾ���û���Ϣ���
void del_account(pusr_account *phead, pusr_account *ptail, char *name)
{
	if (NULL == *phead)
	{
		printf("\n\t\t\t\t��ǰѧ��Ϊ��.\n\n\n");
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
				printf("\n\t\t\t\t�Ҳ������û�����ȷ���û�����\n\n\n");
			}
			free(pcur);
		}
		pcur = ppre = NULL;
	}
}

//��ӡ��ͷ
void titleprint()
{
	printf("*************************************************************************************\n");
	printf("****************************** ѧ �� �� Ϣ �� �� ϵ ͳ ******************************\n");
	printf("*************************************************************************************\n\n");
}

//ϵͳ��ʼ��
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
	//�û���Ϣ�ļ�
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
	//ѧ����Ϣ�ļ�
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

//ȷ���˺����뼰��Ȩ��
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

// �����棬����Ȩ��չʾϵͳ�˵�
MEMUORDER show_system_memu(USR_ROLE role)
{
	char i, j;
	MEMUORDER k;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t1.ѧ����Ϣϵͳ");
	if (1 == role)
	{
		printf("\t\t2.�û���Ϣϵͳ");
	}
	printf("\n\n\t\t\t9.�˳�ϵͳ");
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
		printf("\t\t\t1.��ѯѧ����Ϣ");
		if (1 == role)
		{
			printf("\t\t2.���ѧ����Ϣ\n");
			printf("\n\t\t\t3.�޸�ѧ����Ϣ\t\t4.ɾ��ѧ����Ϣ");
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
			else if (1 == k)            //1-1-1,�����ֲ�
			{
				return 111;
			}
			else if (2 == k)           //1-1-2����ѧ�Ų�
			{
				return 112;
			}
			else                      //1-1-3,����ԱȨ�ޣ��鿴ȫ��
				return 113;
		}
		else if ('2' == j && 1 == role) //1-2�����
		{
			return 12;
		}
		else if ('3' == j && 1 == role) //1-3���޸�
		{
			return 13;
		}
		else if ('4' == j && 1 == role)//1-4��ɾ��
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
		printf("\t\t\t1.��ѯ�û���Ϣ\t\t2.����û���Ϣ\n");
		printf("\n\t\t\t3.�޸��û���Ϣ\t\t4.ɾ���û���Ϣ");
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
			else if (1 == k)  //2-1-1�����û�����
			{
				return 211;
			}
			else             //2-1-2���鿴ȫ���û�
				return 212;
		}
		else if ('2' == j) //2-2������û�
		{
			return 22;
		}
		else if ('3' == j) //2-3���޸��û�
		{
			return 23;
		}
		else if ('4' == j) //2-4��ɾ���û�
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

//����Ȩ�޲���ѧ���˵�
MEMUORDER show_search_usr_memu(USR_ROLE role)
{
	MEMUORDER i;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t\t1.�����ֲ�ѯ\n\n\t\t\t\t2.��ѧ�Ų�ѯ");
	if (1 == role)
	{
		printf("\n\n\t\t\t\t3.�鿴ȫ��");
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

//չʾ�����û��˵�
MEMUORDER show_search_account_memu()
{
	MEMUORDER i;
Loop:
	system("cls");
	titleprint();
	printf("\t\t\t\t1.���û�����ѯ\n\n\t\t\t\t2.�鿴ȫ��");
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


//ѧ�Ų��ң����ص�ǰָ��
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

//����ѧ�Ų���ѧ����Ϣ
void search_usr_info_by_id(pusr_infor phead) 
{
	int i;
	char id[20];
	pusr_infor pcur;
	
Loop:
	system("cls");
	titleprint();
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t������Ҫ��ѯ��ѧ�ţ�");
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
		printf("\n\n\t\t\t\t��ѯʧ�ܣ�\n\n\n");
	}
	else
	{
		printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
	}
	system("pause");
	goto Loop;
}

//�������ֲ���ѧ����Ϣ
void search_usr_info_by_name(pusr_infor phead)
{
	char name[20];
	pusr_infor pcur;
	pcur = phead;
Loop:
	system("cls");
	titleprint();
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t������Ҫ��ѯ�����֣�");
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
			printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
			system("pause");
			pcur = phead;
			goto Loop;
		}
		pcur = pcur->pnext;
	}
	system("cls");
	titleprint();
	printf("\n\n\t\t\t\t��ѯʧ�ܣ�\n\n\n");
	pcur = phead;
	system("pause");
	goto Loop;
}

//�˵�2���ѧ����Ϣ
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
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t�밴��ѧ�� ���� �ɼ�����ʽ����Ҫ��ӵ�ѧ����Ϣ��\n\n\t\t\t");
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
		printf("\t\t\t\tѧ�Ż�ɼ��������\n\n\n");
		system("pause");
		goto Loop;
	}
	while (pcur)
	{
		if (id == pcur->usr_id)
		{
			system("cls");
			titleprint();
			printf("\t\t\t����ѧ��Ϊ%d��ѧ������ȷ��ѧ�Ż�ʹ���޸Ĺ��ܣ�\n\n\n", id);
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
	printf("\t\t\t\t��Ҫ��ӵ�ѧ����ϢΪ��\n\n");
	printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", id, name, score);

	printf("0.����\t1.ȷ��\n������ѡ�");
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
		printf("\t\t\t\tѧ��Ϊ%d��ѧ����Ϣ��ӳɹ���\n\n", id);
		system("pause");
		free(pnew);
		goto Loop;
	}
	else
	{
		goto Loop2;
	}
}

//�˵�3�޸�ѧ����Ϣ
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
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�");
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
		printf("\n\t\t\t\t�Ҳ�����ѧ������ȷ��ѧ�ţ�\n\n\n");
	}
	else
	{
		printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", pcur->usr_id, pcur->name, pcur->score);
		printf("0.����\t1.ȷ��\n�Ƿ��޸Ĵ���Ϣ��������ѡ�");
		rewind(stdin);  scanf("%c",&order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if('1'==order)
		{
			printf("\n\t\t\t\t���������֣�");
			scanf("%s",name);
			printf("\n\t\t\t\t������ɼ���");
			scanf("%s", scorech);
			score = (float)atof(scorech);
			if (score <= 0 && strcmp(scorech, "0") != 0)
			{
				system("cls");
				titleprint();
				printf("\t\t\t\t�ɼ��������\n\n\n");
				system("pause");
				goto Loop2;
			}
		Loop3:
			system("cls");
			titleprint();
			printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", pcur->usr_id, name, score);
			printf("0.����\t1.ȷ��\n����Ϊ�޸ĺ����Ϣ��������ѡ�");
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
				printf("\t\t\t\t�޸ĳɹ���\n\n\n");
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

//�˵�4ɾ��ѧ����Ϣ
void dele_usr_info(pusr_infor *phead, pusr_infor *ptail)
{
	char order;
	char idch[20];
	int id;
	pusr_infor pget;
Loop:
	system("cls");
	titleprint();
	printf("\n��0.������ҳ��\n");
	printf("\n\t\t\t������Ҫɾ����ѧ�ţ�");
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
		printf("\t\t\t\tѧ���������\n\n\n");
		system("pause");
		goto Loop;
	}
	pget = get_usr_info_by_id(*phead, id);
Loop2:
	system("cls");
	titleprint();
	if (NULL == pget)
	{
		printf("\n\t\t\t\t�Ҳ�����ѧ������ȷ��ѧ�ţ�\n\n\n");
	}
	else
	{
		printf("\t\t\t\tѧ�ţ�%6d\n\n\t\t\t\t���֣�%6s\n\n\t\t\t\t�ɼ���%6.2f\n\n\n", pget->usr_id, pget->name, pget->score);
		printf("0.����\t1.ȷ��\n�Ƿ�ɾ������Ϣ��������ѡ�");
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

//�˵�5�����˺�
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
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t�밴���û��� ���롱��ʽ����Ҫ��ӵ��û���Ϣ��\n\n\t\t\t");
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
			printf("\t\t�����û���Ϊ%s���û�������������ʹ���޸Ĺ��ܣ�\n\n\n", name);
			system("pause");
			goto Loop;
		}
		pcur = pcur->pnext;
	}
Loop2:
	system("cls");
	titleprint();
	printf("\t\t\t\t��Ҫ��ӵ��û���ϢΪ��\n\n");
	printf("\t\t\t\t�û�����%s\n\n\t\t\t\t���룺%s\n\n\n", name, pwd);

	printf("0.����\t1.ȷ��\n������ѡ�");
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
		printf("\t\t\t\t%s�û���Ϣ��ӳɹ���\n\n", name);
		system("pause");
		free(pnew);
		goto Loop;
	}
	else
	{
		goto Loop2;
	}
}

//�˵�6�޸��˺���Ϣ
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
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t������Ҫ�޸���Ϣ���û�����");
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
		printf("\n\t\t\t\t�Ҳ������û�����ȷ���û�����\n\n\n");
	}
	else
	{
		printf("\t\t\t\t�û�����%s\n\n\t\t\t\t���룺%s\n\n\n", pcur->usr_name, pcur->usr_pwd);
		printf("0.����\t1.ȷ��\n�Ƿ��޸Ĵ���Ϣ��������ѡ�");
		rewind(stdin);  scanf("%c", &order);
		if ('0' == order)
		{
			goto Loop;
		}
		else if ('1' == order)
		{
			printf("\n\t\t\t\t���������û�����");
			scanf("%s",name);
			printf("\n\t\t\t\t�����������룺");
			scanf("%s",pwd);
		Loop3:
			system("cls");
			titleprint();
			printf("\t\t\t\t�û�����%s\n\n\t\t\t\t���룺%s\n\n\n", name, pwd);
			printf("0.����\t1.ȷ��\n����Ϊ�޸ĺ����Ϣ��������ѡ�");
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
				printf("\t\t\t\t�޸ĳɹ���\n\n\n");
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

//�˵�7ɾ���û��˻�
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
	printf("\n��0.������ҳ��\n");
	printf("\n\t\t\t������Ҫɾ�����û�����");
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
		printf("\n\t\t\t\t�Ҳ������û�����ȷ���û�����\n\n\n");
	}
	else
	{
		printf("\t\t\t\t�û�����%s\n\n\t\t\t\t���룺%s\n\n\n", pcur->usr_name, pcur->usr_pwd);
		printf("0.����\t1.ȷ��\n�Ƿ�ɾ������Ϣ��������ѡ�");
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
			printf("\n\t\t\t\tɾ���ɹ���\n\n\n");
		}
		else
		{
			goto Loop2;
		}
	}
	system("pause");
	goto Loop;
}

//�˵�8��ѯ�û��˺���Ϣ
void search_usr_account(pusr_account phead)
{
	char name[20];
	pusr_account pcur;
	pcur = phead;
Loop:
	system("cls");
	titleprint();
	printf("\n��0.������ҳ��\n");
	printf("\t\t\t������Ҫ��ѯ���û�����");
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
			printf("\t\t\t\t�û�����\t%s\n\n\t\t\t\t���룺\t\t%s\n\n\t\t\t\t����ԱȨ�ޣ�\t%d\n\n\n", pcur->usr_name, pcur->usr_pwd, pcur->usr_role);
			system("pause");
			pcur = phead;
			goto Loop;
		}
		pcur = pcur->pnext;
	}
	system("cls");
	titleprint();
	printf("\n\n\t\t\t\t��ѯʧ�ܣ�\n\n\n");
	pcur = phead;
	system("pause");
	goto Loop;
}

//�˵�9�˳�ϵͳ
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
	//�û���Ϣ�ļ�
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
	//ѧ����Ϣ�ļ�
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

