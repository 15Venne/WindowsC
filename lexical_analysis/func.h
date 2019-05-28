#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define MAXKEY 1024

#define NOTNUMORLET(c) ((c>'9'||c<'0')&&(c<'A'||c>'Z')&&(c<'a'||c>'z'))
#define NOTNUM(c) (c>'9'||c<'0')
#define NOTLET(c) ((c<'A'||c>'Z')&&(c<'a'||c>'z'))

/* ���ʱ��� */
enum e_TokenCode
{
	/* ��������ָ��� */
	TK_PLUS,        // + �Ӻ�  0
	TK_MINUS,       // - ����
	TK_STAR,        // * �Ǻ�
	TK_DIVIDE,      // / ����
	TK_MOD,	        // % ���������
	TK_EQ,          // == ���ں�
	TK_NEQ,         // != �����ں�
	TK_LT,          // < С�ں�
	TK_LEQ,         // <= С�ڵ��ں�
	TK_GT,          // > ���ں�
	TK_GEQ,         // >= ���ڵ��ں�
	TK_ASSIGN,      // = ��ֵ����� 
	TK_POINTSTO,    // -> ָ��ṹ���Ա�����
	TK_DOT,         // . �ṹ���Ա�����
	TK_AND,         // & ��ַ�������
	TK_OPENPA,      // ( ��Բ����
	TK_CLOSEPA,     // ) ��Բ����
	TK_OPENBR,      // [ ��������
	TK_CLOSEBR,     // ] ��Բ����
	TK_BEGIN,       // { �������
	TK_END,         // } �Ҵ�����
	TK_SEMICOLON,   // ; �ֺ�    
	TK_COMMA,       // , ����
	TK_ELLIPSIS,    // ... ʡ�Ժ�
	TK_EOF,         // �ļ������� 24

	/* ���� */
	TK_CINT,        // ���ͳ���  25
	TK_CCHAR,       // �ַ�����
	TK_CSTR,        // �ַ�������  27

	/* �ؼ��� */
	KW_CHAR,        // char�ؼ���  28
	KW_SHORT,       // short�ؼ���
	KW_INT,         // int�ؼ���
	KW_VOID,        // void�ؼ���  
	KW_STRUCT,      // struct�ؼ���   
	KW_IF,          // if�ؼ���
	KW_ELSE,        // else�ؼ���
	KW_FOR,         // for�ؼ���
	KW_CONTINUE,    // continue�ؼ���
	KW_BREAK,       // break�ؼ���   
	KW_RETURN,      // return�ؼ���
	KW_SIZEOF,      // sizeof�ؼ���   

	KW_ALIGN,       // __align�ؼ���	 
	KW_CDECL,       // __cdecl�ؼ��� standard c call
	KW_STDCALL,     // __stdcall�ؼ��� pascal c call   42

	/* ��ʶ�� */
	TK_IDENT  //����     43
};

//char *pp[100]; //

typedef struct Dynstring {
	int cnt;
	int capacity;
	char *data;
}Dynstring;



typedef struct TkWord {
	int tkcode;
	struct TkWord *next;
	char *spelling;
	int row;
}TkWord, *pTkWord;

typedef struct DynArray {
	int cnt;
	int capacity;
	TkWord **data;
}DynArray;


int elf_hash(char*);//��ϣ��ʽ

void strprint(int, char*);

void keyDealwith(char*, int,TkWord**);

void strDealwith(char*,char,TkWord**);//������̬���ַ���