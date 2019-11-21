%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019��11��19��
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

//����id�Ĵ���
{identifier}	{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//ID�ڵ�
                    for (int i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;//��ʼ�����ӽ��Ϊ��
                    t->sibling = NULL;
                    t->nodekind = ExpK;//Ϊʲôָ�����ʽ
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    t->attr.name=hash1[getid(yytext,yyleng)];
					yylval = t;
					return ID;
									}
				
{num}			{	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));//number�ڵ�
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
    for(i;i<leng;i++)//����һ������
    {
        Id[i]=*text;
        text++;//������һ������
    }
    Id[i]='\0';//�������е����Ժ����\0������
    int index =compute(Id,leng)%1000;//index:id�ڷ��ű��е�λ��	
    if(hash1[index][0]=='\0')	//��������ڸñ���
    {
        strcpy(hash1[index],Id);//�����ñ���
    }
    else{
        while(hash1[index][0]!='\0'&&strcmp(Id,hash1[index])!=0)//index��Ϊ����id�����index�±겻���
//��û���ù���index����ֹ��� 
          {
            index++;
          }
        }
    return index;
}
int compute(char* str,int len)
{
    int hash = 0;  
    for (int i=0;str[i]!='\0';i++)//���ζ���idֱ������������
    {
        hash=hash+str[i]-'a';//ASC���ȥa�õ�����λ��
    }
    return hash;  
}

int getNUM(char *text,int leng){
    int value=0;
    for(int i=0;i<leng;i++)
    {
        value=value*10+*text-'0';//���ֽڱ����
        text++;
    }
    return value;
}