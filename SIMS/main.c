#include"sism.h"


int main(int argc,char *argv[])
{
	
	pusr_account pachead = NULL, pactail = NULL;//�û�����ͷβ
	
	pusr_infor pifhead = NULL, piftail = NULL;  //ѧ������ͷβ
	USR_ROLE role;                              //Ȩ��ֵ      
	char name[20], password[20];                //�˻�������
	int cnt = 0, i=0;
	char ch;
	MEMUORDER order;                           //��ȡ�˵�ָ��
	pusr_account pget_ac;                     //��ȡ���ҷ���ָ��
	pusr_infor pget_if;                       //��ȡ���ҷ���ָ��
	system_init(argv[1], &pachead, &pactail, &pifhead, &piftail);
	titleprint();
Loop:	
	role = -1;
	while(-1 == role)
	{
		i = 0;
		memset(name, 0, sizeof(name));
		memset(password, 0, sizeof(password));
		printf("�������˺ţ�"); scanf("%s",name);
		printf("���������룺");
		while (ch = getch(),ch!='\r')
		{
			if ('\b' == ch)
			{
				if (i <= 0)
				{
					continue;
				}
				printf("\b \b");
				i--;
			}
			else
			{
				printf("*");
				password[i] = ch;
				i++;
			}
		}
		password[i] = '\0';
		role = role_confirm(name, password,pachead);
		if (-1 == role)
			printf("\n�˺��������\n\n");
		cnt++;
		if (cnt >= 3)
		{
			printf("��ȷ���˺����룡\n");
			system("pause");
			return 0;
		}
	}
	cnt = 0;
Loop2:
	order = show_system_memu(role);
	switch (order)
	{
	case 0:
		goto Loop;
		break;
	case 111: //�����ֲ�ѯ
		search_usr_info_by_name(pifhead);
		break;

	case 112: //��ѧ�Ų�ѯ
		search_usr_info_by_id(pifhead);
		break;

	case 113: //�鿴ȫ��ѧ��
		system("cls");
		titleprint();
		pget_if = pifhead;
		printf("\t\t\t\tѧ��      ����    �ɼ�\n\n");
		while (pget_if)
		{
			printf("\t\t\t\t%4d    %6s    %.2f\n\n", pget_if->usr_id, pget_if->name, pget_if->score);
			pget_if = pget_if->pnext;
		}
		printf("\n\n");
		system("pause");
		break;

	case 12: //���ѧ��
		add_usr_info(&pifhead, &piftail);
		break;

	case 13: //�޸�ѧ��
		update_usr_info(&pifhead);
		break;

	case 14: //ɾ��ѧ��
		dele_usr_info(&pifhead,&piftail);
		break;

	case 211: //��ѯ�û�
		search_usr_account(pachead);
		break;

	case 212: //�鿴ȫ���û�
		system("cls");
		titleprint();
		pget_ac = pachead;
		printf("\t\t\t�û���\t\t����\t\t\t����ԱȨ��\n\n");
		while (pget_ac)
		{
			printf("\t\t\t%-10s\t%-15s\t\t\t%d\n\n", pget_ac->usr_name, pget_ac->usr_pwd, pget_ac->usr_role);
			pget_ac = pget_ac->pnext;
		}
		printf("\n\n");
		system("pause");
		break;

	case 22: //����û�
		add_usr_account(&pachead, &pactail);
		break;

	case 23: //�޸��û�
		updata_usr_account(&pachead);
		break;

	case 24: //ɾ���û�
		dele_usr_account(&pachead, &pactail);
		break;

	case 9:
		break;
	default:
		break;
	}
	save_data(&pachead, &pifhead, argv[1]);
	if (9 == order)
	{
		system("cls");
		titleprint();
		printf("\n\t\t\t\t\tлл\n\n\n\t\t\t\t");
		system("pause");
		return 0;
	}
	goto Loop2;
}

