#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SELECT do{printf("\n\n\n0.返回上一级\n请输入选项：");}while(0)

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

void system_init(const char*, pusr_account*, pusr_account*, pusr_infor*, pusr_infor*);//系统初始化

void tailInsert(pusr_account*, pusr_account*, usr_account*); //尾插法

void sortInsert(pusr_infor*, pusr_infor*, usr_infor*);//有序插入

void del_usr(pusr_infor*, pusr_infor*, int);

void del_account(pusr_account*, pusr_account*, char*);

USR_ROLE role_confirm(char*, char*, pusr_account);//确认账号密码返回权限值

MEMUORDER show_system_memu(USR_ROLE);//根据权限展示系统菜单

MEMUORDER show_search_usr_memu(USR_ROLE);//根据权限展示查找学生菜单

MEMUORDER show_search_account_memu();//展示查找用户菜单

void search_usr_info_by_id(pusr_infor);//根据id查找学生信息
                                        //
pusr_infor get_usr_info_by_id(pusr_infor, int);//学号查找，返回当前指针
                                     //菜单1
void search_usr_info_by_name(pusr_infor);//根据名字查找学生信息

void add_usr_info(pusr_infor *phead, pusr_infor *ptail);//菜单2添加学生信息

void update_usr_info(pusr_infor *phead);//菜单3修改学生信息

void dele_usr_info(pusr_infor *phead, pusr_infor *ptail);//菜单4删除学生信息

void add_usr_account(pusr_account *phead, pusr_account *ptail);//菜单5增加账号

void updata_usr_account(pusr_account *phead);//菜单6修改账号信息

void dele_usr_account(pusr_account *phead, pusr_account *ptail);//菜单7删除用户账户

void search_usr_account(pusr_account phead);//菜单8查询用户账号信息

void save_data(pusr_account *pachead, pusr_infor *pifhead, char *filename);//菜单9退出系统
