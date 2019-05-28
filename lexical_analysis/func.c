#include"func.h"

extern TkWord *keywords;
extern int tkcnt;

//��ϣ��ʽ
int elf_hash(char *key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}

//����tokenֵ������ɫ
void strprint(int token,char *p)  
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (token >= TK_IDENT)
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);//������ɫ
	else if (token >= KW_CHAR)
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//�ؼ�����ɫ
	else if (token >= TK_CINT)
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);//������ɫ
	else
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	//�������ɫ	
	printf("%s", p);//����tokenֵ��ȡ��Ӧ�ַ������ͣ�Ȼ���ӡ
}

void keyDealwith(char *ch, int cnt, TkWord **Hash)
{
	pTkWord pnewkeyword = NULL;
	int hashval;
	if (*ch=='\0')
	{
		return;
	}
	char *p = ch;
	while ((*p <= '9' && *p >= '0') || *p == '.')
	{
		p++;
	}
	if ('\0' == *p)
	{
		strprint(25, ch);
		return;
	}

	//ͨ��������ȡkey��hashֵ
	hashval = elf_hash(ch);
	if (NULL != Hash[hashval])
	{
		while (NULL != Hash[hashval])
		{
			if (0 == strcmp(Hash[hashval]->spelling, ch))
			{
				strprint(Hash[hashval]->tkcode, ch);
				break;
			}
			Hash[hashval] = Hash[hashval]->next;
		}
	}
	else
	{
		pnewkeyword = (pTkWord)malloc(sizeof(TkWord));
		pnewkeyword->next = NULL;
		pnewkeyword->spelling = (char*)malloc(sizeof(cnt));
		pnewkeyword->tkcode = tkcnt++;
		strcpy(pnewkeyword->spelling, ch);
		Hash[hashval] = pnewkeyword;
		strprint(Hash[hashval]->tkcode, ch);
	}
}


void strDealwith(char *ch, char c,TkWord **Hash)
{
	if (ch[0] == '\0')
	{
		printf("%c", c);
		return;
	}
	Dynstring temp;
	memset(&temp, 0, sizeof(Dynstring));
	

	temp.capacity = strlen(ch) + 1;
	temp.cnt = 0;
	temp.data = (char*)realloc(temp.data, temp.capacity);
	while (*ch != '\0')
	{
		if (NOTNUMORLET(*ch))
		{
			temp.data[temp.cnt] = '\0'; //temp.dataȡ����key
			keyDealwith(temp.data, temp.cnt, Hash);
			if (*ch == 39)
			{
				temp.cnt = 0;
				temp.data[temp.cnt++] = *ch++;
				while (*ch != '\0'&& *ch != 39)
				{
					temp.data[temp.cnt++] = *ch++;
				}
				//temp.data[temp.cnt++] = *ch;
				temp.data[temp.cnt] = '\0';
				strprint(26, temp.data);
				temp.cnt = 0;
			}
			temp.data[0] = *ch;
			temp.data[1] = '\0';
			keyDealwith(temp.data, 2, Hash);
			temp.cnt = 0;
			ch++;
			continue;
		}
		temp.data[temp.cnt] = *ch++;
		temp.cnt++;
	}
	temp.data[temp.cnt] = '\0'; 
	keyDealwith(temp.data, temp.cnt, Hash);
	if (c != '"')
	{
		printf("%c", c);
	}
}