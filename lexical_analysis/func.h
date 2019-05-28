#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define MAXKEY 1024

#define NOTNUMORLET(c) ((c>'9'||c<'0')&&(c<'A'||c>'Z')&&(c<'a'||c>'z'))
#define NOTNUM(c) (c>'9'||c<'0')
#define NOTLET(c) ((c<'A'||c>'Z')&&(c<'a'||c>'z'))

/* 单词编码 */
enum e_TokenCode
{
	/* 运算符及分隔符 */
	TK_PLUS,        // + 加号  0
	TK_MINUS,       // - 减号
	TK_STAR,        // * 星号
	TK_DIVIDE,      // / 除号
	TK_MOD,	        // % 求余运算符
	TK_EQ,          // == 等于号
	TK_NEQ,         // != 不等于号
	TK_LT,          // < 小于号
	TK_LEQ,         // <= 小于等于号
	TK_GT,          // > 大于号
	TK_GEQ,         // >= 大于等于号
	TK_ASSIGN,      // = 赋值运算符 
	TK_POINTSTO,    // -> 指向结构体成员运算符
	TK_DOT,         // . 结构体成员运算符
	TK_AND,         // & 地址与运算符
	TK_OPENPA,      // ( 左圆括号
	TK_CLOSEPA,     // ) 右圆括号
	TK_OPENBR,      // [ 左中括号
	TK_CLOSEBR,     // ] 右圆括号
	TK_BEGIN,       // { 左大括号
	TK_END,         // } 右大括号
	TK_SEMICOLON,   // ; 分号    
	TK_COMMA,       // , 逗号
	TK_ELLIPSIS,    // ... 省略号
	TK_EOF,         // 文件结束符 24

	/* 常量 */
	TK_CINT,        // 整型常量  25
	TK_CCHAR,       // 字符常量
	TK_CSTR,        // 字符串常量  27

	/* 关键字 */
	KW_CHAR,        // char关键字  28
	KW_SHORT,       // short关键字
	KW_INT,         // int关键字
	KW_VOID,        // void关键字  
	KW_STRUCT,      // struct关键字   
	KW_IF,          // if关键字
	KW_ELSE,        // else关键字
	KW_FOR,         // for关键字
	KW_CONTINUE,    // continue关键字
	KW_BREAK,       // break关键字   
	KW_RETURN,      // return关键字
	KW_SIZEOF,      // sizeof关键字   

	KW_ALIGN,       // __align关键字	 
	KW_CDECL,       // __cdecl关键字 standard c call
	KW_STDCALL,     // __stdcall关键字 pascal c call   42

	/* 标识符 */
	TK_IDENT  //函数     43
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


int elf_hash(char*);//哈希公式

void strprint(int, char*);

void keyDealwith(char*, int,TkWord**);

void strDealwith(char*,char,TkWord**);//处理（动态）字符串