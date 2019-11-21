%{
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
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
digit		[0-9]
num			{digit}+
newline     [\n]+
letter		[_A-Za-z]
identifier	{letter}({letter}|{digit})*
WS			[ \t\n]*
//comment ("//".*)|("/*"(.*"\n")*(.*)"*/")
COMMENT ("/*"([^*]|\*+[^*/])*\*+"/")|("//"[^\n]*|"\/\*".*"\*\/")

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
"if"			{return IF;}
"else"			{return ELSE;}
"for"			{return FOR;}
"while"			{return WHILE;}
"void"			{return VOID;}
"int"			{return INT;}
"char"			{return CHAR;}
"input"         {return INPUT;}
"output"        {return OUTPUT;}
"print"         {return PRINT;}
"main"			{return MAIN;}
"+"				{return PLUS;}	
"-"				{return MINUS;}
"*"				{return TIMES;}
"/"				{return OVER;}
"%"				{return REMI;}
"++"			{return DPLUS;}
"--"			{return DMINUS;}
">="			{return GE;}
"<="			{return LE;}
">"				{return GT;}
"<"				{return	LT;}
"!="			{return NEQ;}
"&&"            {return AND;}
"||"            {return OR;}
"!"             {return NOT;}
"=="			{return EQ;}
"="				{return ASSIGN;}
","				{return COMMA;}
";"				{return SEMI;}		
"("				{return LP;} 
")"				{return RP;} 
"["			    {return LSP;} 
"]"		        {return RSP;} 
"{"		        {return LFP;} 
"}"			    {return RFP;}
{WS}			{/*do nothing*/}
{COMMENT}       {} 

//对于id的处理
{identifier}	{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//ID节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//初始化孩子结点为空
                    t->sibling = NULL;
                    t->nodekind = ExpK;//为什么指向表达式
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    t->attr.name=hash1[getid(yytext,yyleng)];
					yylval = t;
					return ID;
									}
				
{num}			{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//number节点
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Void;
			        t->attr.val=getNUM(yytext,yyleng);	
			        yylval =t;	
					return NUM;
				}
%%

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