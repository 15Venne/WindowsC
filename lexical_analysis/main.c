#include"func.h"

TkWord keywords[100] = {
	{TK_PLUS,NULL,"+"},
	{TK_MINUS,NULL,"-"},
	{TK_STAR,NULL,"*"},
	{TK_DIVIDE,NULL,"/"},
	{TK_MOD,NULL,"%"},
	{TK_EQ,NULL,"=="},
	{TK_NEQ,NULL,"!="},
	{TK_LT,NULL,"<"},
	{TK_LEQ,NULL,"<="},
	{TK_GT,NULL,">"},
	{TK_GEQ,NULL,">="},
	{TK_ASSIGN,NULL,"="},
	{TK_POINTSTO,NULL,"->"},
	{TK_DOT,NULL,"."},
	{TK_AND,NULL,"&"},
	{TK_OPENPA,NULL,"("},
	{TK_CLOSEPA,NULL,")"},
	{TK_OPENBR,NULL,"["},
	{TK_CLOSEBR,NULL,"]"},
	{TK_BEGIN,NULL,"{"},
	{TK_END,NULL,"}"},
	{TK_SEMICOLON,NULL,";"},
	{TK_COMMA,NULL,","},
	{TK_ELLIPSIS,NULL,"..."},
	{TK_EOF,NULL,"End_Of_File"},

	{TK_CINT,NULL,"整型常量"},
	{TK_CCHAR,NULL,"字符常量"},
	{TK_CSTR,NULL,"字符串常量"},

	{KW_CHAR,NULL,"char"},
	{KW_SHORT,NULL,"short"},
	{KW_INT,NULL,"int"},
	{KW_VOID,NULL,"void"},
	{KW_STRUCT,NULL,"struct"},

	{KW_IF,NULL,"if"},
	{KW_ELSE,NULL,"else"},
	{KW_FOR,NULL,"for"},
	{KW_CONTINUE,NULL,"continue"},
	{KW_BREAK,NULL,"break"},
	{KW_RETURN,NULL,"return"},
	{KW_SIZEOF,NULL,"sizeof"},
	{KW_ALIGN,NULL,"__align"},
	{KW_CDECL,NULL,"__cdecl"},
	{KW_STDCALL,NULL,"__stdcall"},
	{TK_IDENT,NULL,"函数名"}
};

int tkcnt = 44;


TkWord *Hash[MAXKEY] = { 0 };




int main(int argc,char *argv[])
{
	int i;
	for (i = 0; i < 44; ++i)
	{
		if (Hash[elf_hash(keywords[i].spelling)] == NULL)
		{
			Hash[elf_hash(keywords[i].spelling)] = &keywords[i];
		}
		else
		{
			while (Hash[elf_hash(keywords[i].spelling)]->next != NULL)
			{
				Hash[elf_hash(keywords[i].spelling)] = Hash[elf_hash(keywords[i].spelling)]->next;
			}
			Hash[elf_hash(keywords[i].spelling)]->next = &keywords[i];
		}
	}
	int hashval;
	char *p;
	FILE *fp = fopen(argv[1], "r");
	if (NULL == fp)
	{
		perror("fopen");
	}
	
	Dynstring dynstr;
	dynstr.capacity = 10;
	dynstr.data = (char*)malloc(dynstr.capacity);
	dynstr.cnt = 0;
	char c;
	while ((c=fgetc(fp)) != EOF)  //读取文件，把字符串存进动态字符串，然后处理字符串，拆成key
	{
		if(c == ' '||c == '\n')
		{
			dynstr.data[dynstr.cnt] = '\0';
			strDealwith(dynstr.data, c,Hash);
			dynstr.capacity = 10;
			dynstr.data = (char*)realloc(dynstr.data, dynstr.capacity);
			dynstr.cnt = 0;
		}
		else if (c == '"')
		{
			dynstr.data[dynstr.cnt] = '\0';
			strDealwith(dynstr.data, c, Hash);
			dynstr.capacity = 10;
			dynstr.data = (char*)realloc(dynstr.data, dynstr.capacity);
			dynstr.cnt = 0;
			dynstr.data[dynstr.cnt++] = '"';
			while ((c = fgetc(fp)) != EOF && c != '"')
			{
				if (dynstr.cnt == dynstr.capacity - 1)
				{
					dynstr.data = (char*)realloc(dynstr.data, dynstr.capacity + 10);
					dynstr.capacity += 10;
				}
				dynstr.data[dynstr.cnt] = c;
				dynstr.cnt++;
			}
			dynstr.data[dynstr.cnt++] = '"';
			dynstr.data[dynstr.cnt] = '\0';
			p = (char*)malloc(12);
			strcpy(p, "字符串常量");
			hashval = elf_hash(p);
			strprint(Hash[hashval]->tkcode, dynstr.data);
			dynstr.capacity = 10;
			dynstr.data = (char*)realloc(dynstr.data, dynstr.capacity);
			dynstr.cnt = 0;
		}
		else
		{
			if (dynstr.cnt == dynstr.capacity - 1)
			{
				dynstr.data = (char*)realloc(dynstr.data, dynstr.capacity + 10);
				dynstr.capacity += 10;
			}
			dynstr.data[dynstr.cnt] = c;
			dynstr.cnt++;
		}
	}


	system("pause");
	return 0;
}