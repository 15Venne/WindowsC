#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SELECT do{printf("\n\n\n0.������һ��\n������ѡ�");}while(0)

typedef int USR_ROLE;
typedef int MEMUORDER;


typedef struct usr_account {
	char usr_name[20];
	char usr_pwd[20];
	USR_ROLE usr_role;
	struct usr_account *pnext;
}usr_account,*pusr_account;

typedef struct usr_infor {
	int usr_id;
	char name[20];
	float score;
	struct usr_infor *pnext;
}usr_infor,*pusr_infor;

void titleprint();

void system_init(const char*, pusr_account*, pusr_account*, pusr_infor*, pusr_infor*);//ϵͳ��ʼ��

void tailInsert(pusr_account*, pusr_account*, usr_account*); //β�巨

void sortInsert(pusr_infor*, pusr_infor*, usr_infor*);//�������

void del_usr(pusr_infor*, pusr_infor*, int);

void del_account(pusr_account*, pusr_account*, char*);

USR_ROLE role_confirm(char*, char*, pusr_account);//ȷ���˺����뷵��Ȩ��ֵ

MEMUORDER show_system_memu(USR_ROLE);//����Ȩ��չʾϵͳ�˵�

MEMUORDER show_search_usr_memu(USR_ROLE);//����Ȩ��չʾ����ѧ���˵�

MEMUORDER show_search_account_memu();//չʾ�����û��˵�

void search_usr_info_by_id(pusr_infor);//����id����ѧ����Ϣ
                                        //
pusr_infor get_usr_info_by_id(pusr_infor, int);//ѧ�Ų��ң����ص�ǰָ��
                                     //�˵�1
void search_usr_info_by_name(pusr_infor);//�������ֲ���ѧ����Ϣ

void add_usr_info(pusr_infor *phead, pusr_infor *ptail);//�˵�2���ѧ����Ϣ

void update_usr_info(pusr_infor *phead);//�˵�3�޸�ѧ����Ϣ

void dele_usr_info(pusr_infor *phead, pusr_infor *ptail);//�˵�4ɾ��ѧ����Ϣ

void add_usr_account(pusr_account *phead, pusr_account *ptail);//�˵�5�����˺�

void updata_usr_account(pusr_account *phead);//�˵�6�޸��˺���Ϣ

void dele_usr_account(pusr_account *phead, pusr_account *ptail);//�˵�7ɾ���û��˻�

void search_usr_account(pusr_account phead);//�˵�8��ѯ�û��˺���Ϣ

void save_data(pusr_account *pachead, pusr_infor *pifhead, char *filename);//�˵�9�˳�ϵͳ
