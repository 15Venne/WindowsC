#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>


/*LL(1)文法
 E -> E + T | E - T | T

 T -> T * F | T / F | F

 F - > (E) | i
 
 --------------------------------------

 E -> TE'

 E' -> +TE' | -TE' | e

 T -> FT'

 T' -> *FT' | /FT' | e

 F -> (E) | i
 
 
 */

#define READ(ch) ((ch)=getc(fp)) 

char ch;
int right = 0;
FILE *fp;

typedef struct struCH{
    char ch;
    struct struCH *next;
}struCH;
struCH *temp, *head, *shift;

void E();   //P(E)
void E1();  //P(E')
void T();   //P(T)
void T1();  //P(T')
void F();   //P(F)

int main(int argc, char *argv[])
{

    int errNum = 0, k = 0, m = 0;
    int countchar = 0, rowNum;
    int charerr = 0; //开关控制量

    if(NULL == (fp = fopen(argv[1], "r")))
    {
        perror("fopen");
        return -1;
    }else{
        printf("Success open file:%s \n", argv[1]);
    }

    while(!feof(fp))
    {
        READ(ch);
        ++countchar;
    }
    rewind(fp);
    if(0 == countchar)
    {
        printf("%s is a blank file!\n", argv[1]);
        return 0;
    }
    printf("countchar = %d\n", countchar);
    while(k < (countchar - 1))
    {
        ch = getc(fp);
        if(!('(' == ch || ')' == ch || 'i' == ch || 
             '+' == ch || '-' == ch || '*' == ch || '/' == ch ||
             '#' == ch || '\n' == ch || '\r' == ch))
        {
            //printf("%d\n", ch);
            
            charerr = 1;
            ++errNum;
        }
        ++k;
    }
    rewind(fp);
    //fseek(fp,0,)
    if(charerr)
    {
        printf("%d Unindentify characters in file %s\n", errNum, argv[1]);
        return 0;
    }

    for(rowNum = 1; m < (countchar - 1); ++rowNum)//识别所有行，rowNum记录行号
    {
        right = 1;
        shift = malloc(sizeof(struCH));
        shift->next = NULL;
        head = shift;

        READ(ch);
        //printf("ch = %c\n", ch);
        putchar(ch);
        ++m;
        while(ch != '\n' && m < countchar)
        {
            temp = malloc(sizeof(struCH));
            temp->ch = ch;
            temp->next = NULL;
            shift->next = temp;
            shift = shift->next;
            READ(ch);
            if(m != (countchar - 1))
            {
                putchar(ch);
            }
            ++m;
        }
        head = head->next;
        shift = head;
        putchar('\n');
        E();
        if(shift->ch == '#' && right)
        {
            printf("%s Line %d: right expression!\n", argv[1], rowNum);
        }else{
            printf("%s Line %d: error expression!\n", argv[1], rowNum);
        }
        putchar('\n');
    }

    printf("Completed!\n");
    fclose(fp);
    return 0;

}

void E()
{
    T();
    E1();
}

void E1()
{
    if('+' == shift->ch || '-' == shift->ch)
    {
        shift = shift->next;
        T();
        E1();
    }else{
        if('#' == shift->ch || ')' == shift->ch)
        { return; }
        else{
            right = 0;
        }
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if('*' == shift->ch || '/' == shift->ch)
    {
        shift = shift->next;
        F();
        T1();
    }else{
        if(shift->ch != '#' && shift->ch != ')' && 
           shift->ch != '+' && shift->ch != '-')
        {
            right = 0;
        }
    }
}

void F()
{
    if('i' == shift->ch)
    {
        shift = shift->next;
    }else{
        if('(' == shift->ch)
        {
            shift = shift->next;
            E();
            if(')' == shift->ch)
            {
                shift = shift->next;
            }else{
                right = 0;
            }
        }else{
            right = 0;
        }
    }
}






