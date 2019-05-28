#include"sism.h"


int main(int argc,char *argv[])
{
	
	pusr_account pachead = NULL, pactail = NULL;//用户链表头尾
	
	pusr_infor pifhead = NULL, piftail = NULL;  //学生链表头尾
	USR_ROLE role;                              //权限值      
	char name[20], password[20];                //账户，密码
	int cnt = 0, i=0;
	char ch;
	MEMUORDER order;                           //获取菜单指令
	pusr_account pget_ac;                     //获取查找返回指针
	pusr_infor pget_if;                       //获取查找返回指针
	system_init(argv[1], &pachead, &pactail, &pifhead, &piftail);
	titleprint();
Loop:	
	role = -1;
	while(-1 == role)
	{
		i = 0;
		memset(name, 0, sizeof(name));
		memset(password, 0, sizeof(password));
		printf("请输入账号："); scanf("%s",name);
		printf("请输入密码：");
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
			printf("\n账号密码错误！\n\n");
		cnt++;
		if (cnt >= 3)
		{
			printf("请确认账号密码！\n");
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
	case 111: //按名字查询
		search_usr_info_by_name(pifhead);
		break;

	case 112: //按学号查询
		search_usr_info_by_id(pifhead);
		break;

	case 113: //查看全部学生
		system("cls");
		titleprint();
		pget_if = pifhead;
		printf("\t\t\t\t学号      名字    成绩\n\n");
		while (pget_if)
		{
			printf("\t\t\t\t%4d    %6s    %.2f\n\n", pget_if->usr_id, pget_if->name, pget_if->score);
			pget_if = pget_if->pnext;
		}
		printf("\n\n");
		system("pause");
		break;

	case 12: //添加学生
		add_usr_info(&pifhead, &piftail);
		break;

	case 13: //修改学生
		update_usr_info(&pifhead);
		break;

	case 14: //删除学生
		dele_usr_info(&pifhead,&piftail);
		break;

	case 211: //查询用户
		search_usr_account(pachead);
		break;

	case 212: //查看全部用户
		system("cls");
		titleprint();
		pget_ac = pachead;
		printf("\t\t\t用户名\t\t密码\t\t\t管理员权限\n\n");
		while (pget_ac)
		{
			printf("\t\t\t%-10s\t%-15s\t\t\t%d\n\n", pget_ac->usr_name, pget_ac->usr_pwd, pget_ac->usr_role);
			pget_ac = pget_ac->pnext;
		}
		printf("\n\n");
		system("pause");
		break;

	case 22: //添加用户
		add_usr_account(&pachead, &pactail);
		break;

	case 23: //修改用户
		updata_usr_account(&pachead);
		break;

	case 24: //删除用户
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
		printf("\n\t\t\t\t\t谢谢\n\n\n\t\t\t\t");
		system("pause");
		return 0;
	}
	goto Loop2;
}

