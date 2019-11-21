/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 42 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 11/21/19
* Time: 16:21:56
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019年11月19日
****************************************************************************/
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <malloc.h>
#include <stdlib.h>

#include "myparser.h"

enum {StmtK,ExpK,DeclK};
enum {IfK,WhileK,AssignK,ForK,CompK,InputK,OutputK,PrintK};
enum {OpK,ConstK,IdK,TypeK};
enum {VarK};
enum {Void,Integer,Char};

#define MAXCHILDREN 5
char *Id=new char[10];
struct TreeNode
   { 
	struct TreeNode * child[MAXCHILDREN];
     struct TreeNode * sibling;
     int lineno;
     int nodekind;
     int kind;
     union{ int op;
             int val;
           char *name; }attr;
     //int value;
     int type;/* for type checking of exps */ 
   } ;
int getid(char *text,int leng);
int compute(char* str,int len);
int getNUM(char *text,int leng);
char hash1[1000][10];
extern YYSTYPE yylval;
extern int line;

#line 83 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 58 ".\\mylexer.l"

	// place any extra initialisation code here

#line 107 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 63 ".\\mylexer.l"

	// place any extra cleanup code here

#line 119 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 82 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 190 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 88 ".\\mylexer.l"
return IF;
#line 197 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 89 ".\\mylexer.l"
return ELSE;
#line 204 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 90 ".\\mylexer.l"
return FOR;
#line 211 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 91 ".\\mylexer.l"
return WHILE;
#line 218 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 92 ".\\mylexer.l"
return VOID;
#line 225 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 93 ".\\mylexer.l"
return INT;
#line 232 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 94 ".\\mylexer.l"
return CHAR;
#line 239 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 95 ".\\mylexer.l"
return INPUT;
#line 246 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 96 ".\\mylexer.l"
return OUTPUT;
#line 253 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 97 ".\\mylexer.l"
return PRINT;
#line 260 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 98 ".\\mylexer.l"
return MAIN;
#line 267 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 99 ".\\mylexer.l"
return PLUS;
#line 274 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 100 ".\\mylexer.l"
return MINUS;
#line 281 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 101 ".\\mylexer.l"
return TIMES;
#line 288 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 102 ".\\mylexer.l"
return OVER;
#line 295 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 103 ".\\mylexer.l"
return REMI;
#line 302 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 104 ".\\mylexer.l"
return DPLUS;
#line 309 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 105 ".\\mylexer.l"
return DMINUS;
#line 316 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 106 ".\\mylexer.l"
return GE;
#line 323 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 107 ".\\mylexer.l"
return LE;
#line 330 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 108 ".\\mylexer.l"
return GT;
#line 337 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 109 ".\\mylexer.l"
return	LT;
#line 344 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 110 ".\\mylexer.l"
return NEQ;
#line 351 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 111 ".\\mylexer.l"
return AND;
#line 358 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 112 ".\\mylexer.l"
return OR;
#line 365 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 113 ".\\mylexer.l"
return NOT;
#line 372 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 114 ".\\mylexer.l"
return EQ;
#line 379 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 115 ".\\mylexer.l"
return ASSIGN;
#line 386 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 116 ".\\mylexer.l"
return COMMA;
#line 393 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 117 ".\\mylexer.l"
return SEMI;
#line 400 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 118 ".\\mylexer.l"
return LP;
#line 407 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 119 ".\\mylexer.l"
return RP;
#line 414 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 120 ".\\mylexer.l"
return LSP;
#line 421 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 121 ".\\mylexer.l"
return RSP;
#line 428 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 122 ".\\mylexer.l"
return LFP;
#line 435 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 123 ".\\mylexer.l"
return RFP;
#line 442 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 124 ".\\mylexer.l"
/*do nothing*/
#line 449 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 125 ".\\mylexer.l"

#line 456 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 128 ".\\mylexer.l"
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//ID节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//初始化孩子结点为空
                    t->sibling = NULL;
                    t->nodekind = ExpK;//为什么指向表达式
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    t->attr.name=hash1[getid(yytext,yyleng)];
					yylval = t;
					return ID;
									
#line 473 "mylexer.cpp"
		}
		break;
#line 139 ".\\mylexer.l"
				
#line 478 "mylexer.cpp"
	case 40:
		{
#line 140 ".\\mylexer.l"
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//number节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Void;
			        t->attr.val=getNUM(yytext,yyleng);	
			        yylval =t;	
					return NUM;
				
#line 493 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 193;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 42, 18 },
		{ 3, 3 },
		{ 3, 3 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 38, 13 },
		{ 66, 66 },
		{ 0, 78 },
		{ 59, 47 },
		{ 46, 25 },
		{ 39, 13 },
		{ 76, 66 },
		{ 60, 47 },
		{ 3, 1 },
		{ 4, 1 },
		{ 54, 55 },
		{ 3, 3 },
		{ 47, 25 },
		{ 5, 1 },
		{ 6, 1 },
		{ 43, 22 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 44, 23 },
		{ 13, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 78, 78 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 67, 78 },
		{ 45, 24 },
		{ 36, 10 },
		{ 55, 55 },
		{ 48, 26 },
		{ 49, 27 },
		{ 50, 28 },
		{ 51, 29 },
		{ 67, 55 },
		{ 52, 30 },
		{ 53, 32 },
		{ 38, 38 },
		{ 0, 39 },
		{ 56, 43 },
		{ 57, 44 },
		{ 58, 45 },
		{ 37, 12 },
		{ 61, 48 },
		{ 62, 49 },
		{ 63, 50 },
		{ 64, 51 },
		{ 65, 52 },
		{ 66, 54 },
		{ 34, 4 },
		{ 68, 56 },
		{ 69, 57 },
		{ 70, 59 },
		{ 71, 61 },
		{ 20, 1 },
		{ 72, 62 },
		{ 21, 1 },
		{ 73, 63 },
		{ 74, 64 },
		{ 75, 65 },
		{ 35, 6 },
		{ 79, 70 },
		{ 22, 1 },
		{ 80, 72 },
		{ 23, 1 },
		{ 24, 1 },
		{ 81, 73 },
		{ 82, 75 },
		{ 25, 1 },
		{ 77, 77 },
		{ 40, 16 },
		{ 83, 80 },
		{ 26, 1 },
		{ 41, 17 },
		{ 27, 1 },
		{ 28, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 29, 1 },
		{ 30, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 19, 83 },
		{ 0, 0 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 },
		{ 19, 83 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 83, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -5, 37 },
		{ 0, 17, 26 },
		{ 0, 0, 16 },
		{ 0, 51, 0 },
		{ 0, 0, 31 },
		{ 0, 0, 32 },
		{ 0, 0, 14 },
		{ 0, 14, 12 },
		{ 0, 0, 29 },
		{ 0, 26, 13 },
		{ 0, -26, 15 },
		{ 0, -42, 40 },
		{ 0, 0, 30 },
		{ 0, 38, 22 },
		{ 0, 41, 28 },
		{ 0, -58, 21 },
		{ 83, 0, 39 },
		{ 0, 0, 33 },
		{ 0, 0, 34 },
		{ 83, -73, 39 },
		{ 83, -70, 39 },
		{ 83, -55, 39 },
		{ 83, -82, 39 },
		{ 83, -38, 39 },
		{ 83, -57, 39 },
		{ 83, -53, 39 },
		{ 83, -49, 39 },
		{ 83, -40, 39 },
		{ 0, 0, 35 },
		{ 0, -59, 0 },
		{ 0, 0, 36 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 17 },
		{ 0, 0, 18 },
		{ 55, 19, 0 },
		{ -39, 57, 38 },
		{ 0, 0, 20 },
		{ 0, 0, 27 },
		{ 0, 0, 19 },
		{ 83, -29, 39 },
		{ 83, -46, 39 },
		{ 83, -44, 39 },
		{ 83, 0, 1 },
		{ 83, -93, 39 },
		{ 83, -33, 39 },
		{ 83, -43, 39 },
		{ 83, -31, 39 },
		{ 83, -30, 39 },
		{ 83, -29, 39 },
		{ 0, 0, 25 },
		{ -54, 35, 0 },
		{ -38, 16, 0 },
		{ 83, -35, 39 },
		{ 83, -21, 39 },
		{ 83, 0, 3 },
		{ 83, -36, 39 },
		{ 83, 0, 6 },
		{ 83, -28, 39 },
		{ 83, -28, 39 },
		{ 83, -24, 39 },
		{ 83, -13, 39 },
		{ 83, -20, 39 },
		{ -54, -25, 0 },
		{ 77, 0, 38 },
		{ 83, 0, 7 },
		{ 83, 0, 2 },
		{ 83, -26, 39 },
		{ 83, 0, 11 },
		{ 83, -25, 39 },
		{ 83, -21, 39 },
		{ 83, 0, 5 },
		{ 83, -5, 39 },
		{ 0, 0, 38 },
		{ 78, 51, 0 },
		{ -77, 8, 0 },
		{ 83, 0, 8 },
		{ 83, -16, 39 },
		{ 83, 0, 10 },
		{ 83, 0, 4 },
		{ 0, 70, 9 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 151 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

int getid(char *text,int leng)
{
    int i=0;
    for(i;i<leng;i++)//读入一个单词
    {
        Id[i]=*text;
        text++;//读入下一个单词
    }
    Id[i]='\0';//读完所有单词以后加上\0结束符
    int index =compute(Id,leng)%1000;//index:id在符号表中的位置	
    if(hash1[index][0]=='\0')	//如果不存在该变量
    {
        strcpy(hash1[index],Id);//创建该变量
    }
    else{
        while(hash1[index][0]!='\0'&&strcmp(Id,hash1[index])!=0)//index不为空且id数组和index下标不相等
//找没有用过的index，防止溢出 
          {
            index++;
          }
        }
    return index;
}
int compute(char* str,int len)
{
    int hash = 0;  
    for (int i=0;str[i]!='\0';i++)//依次读入id直到遇到结束符
    {
        hash=hash+str[i]-'a';//ASC码减去a得到返回位置
    }
    return hash;  
}

int getNUM(char *text,int leng){
    int value=0;
    for(int i=0;i<leng;i++)
    {
        value=value*10+*text-'0';//把字节变成数
        text++;
    }
    return value;
}
