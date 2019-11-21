%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年11月19日
****************************************************************************/
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "mylexer.h"

enum {StmtK,ExpK,DeclK};
enum {IfK,WhileK,AssignK,ForK,CompK,InputK,OutputK,PrintK};
enum {OpK,ConstK,IdK,TypeK};//ConstK常量，TypeK:intege char类型
enum {VarK};//变量声明
enum {Void,Integer,Char,Boolean};
#define MAXCHILDREN 5//最多孩子数
int line=0;
int Num=0;//给ShowNode行数计数
struct TreeNode
   { 
	struct TreeNode * child[MAXCHILDREN];
     struct TreeNode * sibling;//兄弟
     int lineno;
     int nodekind;//三个节点类型 stmt exp decl
     int kind;// op const id type var
     union{ int op;//存储token中的符号
             int val;//数字常量的值
           char *name; }attr;//if语句,while语句,变量声明,id声明等
     int type; /* for type checking of exps */
   } ;
TreeNode * newStmtNode(int kind)
{ 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
   printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) 
    t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind = kind;
    t->lineno = line++;
  }
  return t;  
}
TreeNode * newExpNode(int kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) 
    t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind = kind;
    t->lineno = line++;
    t->type = Void;
  }
   return t;
}
TreeNode * newDeclNode(int kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = DeclK;
    t->kind = kind;
    t->lineno = line++;
  }
  return t;
}
void Display(struct TreeNode *p);		//显示语法树
void ShowNode(struct TreeNode *p);		//显示某个节点
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

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

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif
}

// place any declarations here
%token IF MAIN FOR WHILE INPUT PRINT OUTPUT
%token INT CHAR VOID 
%token ID NUM
%token PLUS MINUS TIMES OVER REMI DPLUS DMINUS
%token LT LE GT GE EQ NEQ ASSIGN AND OR NOT
%token SEMI COMMA LP RP LFP RFP 
 
%left	COMMA 
%right	ASSIGN 
%left	EQ NEQ 
%left	LT LE GT GE 
%left	PLUS MINUS 
%left   TIMES OVER REMI 
%left   DPLUS DMINUS
%left	LP RP LSP RSP LFP RFP 
%right	ELSE 
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
start		:MAIN LP RP comp_stmt//main（）主函数体
			{ 
			    $$ = $4;
				Display($4);//以复合语句为根节点，输入必须从main开始
			}
			;
comp_stmt	:LFP  stmt_list RFP//{函数表达式}
			{	
				$$ = newStmtNode(CompK);//建立新的语句节点：复合语句。
				$$->child[0]=$2;
			}
			;
stmt_list	:stmt stmt_list		//递归		
			{
				$$->sibling=$2;//if while是兄弟节点
				$$= $1;		
			}
			|stmt						
			{
				$$ = $1 ;
			}
			;
stmt		:var_dec	//具体表达式类型，变量声明，表达式，if，for，while、主函数				
			{	
				$$ = $1;
			}
			|exp_stmt					
			{	
				$$ = $1;
			}
			|if_stmt					
			{	
				$$ = $1;
			}
			|for_stmt
			{
				$$ = $1;
			}
			|while_stmt 
			{
				$$ = $1;
			}        
			|comp_stmt					
			{	
				$$ = $1;
			}
			|input_stmt
			{
			    $$ = $1;
			}
			|output_stmt
			{
			    $$ = $1;
			}
			|print_stmt
			{
			    $$ = $1;
			}
			;
input_stmt  :INPUT LP exp RP SEMI//input();
            {
               $$ = newStmtNode(InputK);
               $$ -> type =Boolean;
               $$ -> child[0] = $3;
            }
            ;
output_stmt  :OUTPUT LP exp RP SEMI//output();
            {
               $$ = newStmtNode(OutputK);
               $$ -> type =Boolean;
               $$ -> child[0] = $3;
            }
            ;            
print_stmt  :PRINT LP exp RP SEMI//print();
            {
               $$ = newStmtNode(PrintK);
               $$ -> type =Boolean;
               $$ -> child[0] = $3;
            }
            ;			
type_spec	:INT	
			{
				$$ = newExpNode(TypeK);//int
                $$->type=Integer;
                   
			}	
			|CHAR	
			{
				$$ = newExpNode(TypeK);//char
                $$->type=Char;
			}
			|VOID	
			{
				$$ = newExpNode(TypeK);//void
                $$->type=Void;
			}
			;
id_list		:exp COMMA id_list//表达式，表达式
			{
				$$ = $1;
				$$->sibling=$3;
			}
			|exp
			;			             
var_dec		:type_spec id_list SEMI//变量声明 int/char a=/a;
			{	
				$$ = newDeclNode (VarK);//建立一个新的变量声明的节点
				$$->child[0]=$1;
				$$->child[1]=$2;
			}
			;

if_stmt     :IF LP exp RP stmt //if(表达式） 语句
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
      
            | IF LP exp RP  stmt ELSE stmt//if（表达式）语句 else 语句
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
for_stmt	:FOR LP exp SEMI exp SEMI exp RP stmt//for(exp;exp;exp)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
                $$->child[3] = $9;
			}
			|FOR LP SEMI exp SEMI exp RP stmt//for(;exp;exp)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $4;
                $$->child[1] = $6;
                $$->child[2] = $8;
			}
			|FOR LP exp SEMI SEMI exp RP stmt//for(exp;;exp)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $6;
                $$->child[2] = $8;
			}
			|FOR LP exp SEMI exp SEMI RP stmt//for(exp;exp;)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $8;
			}
			|FOR LP SEMI SEMI exp RP stmt//for(;;exp)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $5;
                $$->child[1] = $7;
			}
			|FOR LP SEMI exp SEMI RP stmt//for(;exp;)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $4;
                $$->child[1] = $7;
			}
			|FOR LP exp SEMI SEMI RP stmt//for(exp;;)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $7;
			}
			|FOR LP SEMI SEMI RP stmt//for(;;)语句
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $6;
			}
			;
while_stmt	:WHILE LP exp RP stmt//while()
			{
				$$ = newStmtNode(WhileK);
				$$->child[0] = $3;
                $$->child[1] = $5;
			}
			;
exp_stmt	:exp SEMI		//表达式语句；
			{
				$$ = $1;
			}
			|SEMI
			;
exp			:exp ASSIGN exp//a=表达式
			{
				$$ = newStmtNode(AssignK);
				$$->child[0]=$1;
				$$->child[1]=$3;
			}			
			|or_exp
			{
			    $$ = $1;
			}
			;
or_exp      :or_exp OR and_exp
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op =OR;
                $$ ->child[0] = $1;
                $$ -> child[1] = $3;
            }
            |and_exp
            {
                $$ = $1;
            }
            ;
and_exp     :and_exp AND exp_equ
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op = AND;
                $$ -> child[0] = $1;
                $$ -> child[1] = $3;
            }
            |exp_equ
            {
                $$ = $1;
            }
            ;
exp_equ     :exp_equ EQ simple_exp//==
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=EQ;
			}
			|exp_equ LE simple_exp//<=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LE;
			}
			|exp_equ GE simple_exp//>=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=GE;
			}
			|exp_equ LT simple_exp//<
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LT;
			}
			|exp_equ GT simple_exp	//>
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=GT;
			}
			|exp_equ NEQ simple_exp	//!=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=NEQ;
			}
			|simple_exp
			{
				$$ = $1;
			}
			;
simple_exp  : simple_exp PLUS term //+ - * \ ++ --
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;

                 }
            | simple_exp MINUS term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;

                 } 
            | simple_exp TIMES term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                 } 
            | simple_exp OVER term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                 } 
            | simple_exp REMI term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = REMI;
                 } 
            |simple_exp DPLUS 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = DPLUS;

			}
			|simple_exp DMINUS 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = DMINUS;

			}
            | term { $$ = $1; }
            ;
term		:LP exp RP				
			{
				$$ = $2;
			}
			|ID					
			{
				$$ = $1;
				
			}
			|NUM				
			{
				$$ = $1;
			}
			|NOT term
			{
			   $$ = newExpNode(OpK);
			   $$ -> attr.op = NOT;
			   $$ -> child[0] =$2;
			}
			;
Grammar
	: /* empty */
	;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
void Display(struct TreeNode *p)//显示语法树
{

	struct TreeNode *temp ;
	temp =(struct TreeNode *) malloc (sizeof(struct TreeNode));//留出地址空间
    for(int i=0;i<MAXCHILDREN;i++){
	   if(p->child[i] != NULL)
	   {
		Display(p->child[i]);//递归打印孩子结点，直到没有孩子结点
	   }
	}
	ShowNode(p);//打印所有孩子节点
	temp=p->sibling;
	if(temp!=NULL){
    	Display(temp);//打印兄弟节点
	}	
	return;		
}

void ShowNode(struct TreeNode *p)//显示某个节点
{
    p->lineno=Num++;
	struct TreeNode *temp ;
	temp = (struct TreeNode *) malloc (sizeof(struct TreeNode)); //留出地址空间
	printf("%d:",p->lineno);//行号
	switch(p->nodekind)
	{
		case StmtK:
		{
			const char *names[8] = {"If_statement,",  "While_statement," ,"Assign_statement,","Output_statement,", "For_statement," , "Compound_statement,","Input_statement,","Print_statement," };
			printf("%s\t\t\t",names[p->kind]);//可以直接从数组里面打印，一一对应
			break;
		}
			
		case ExpK:
		{
			const char *names[4] = {"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier," };
			const char *types[3] = {"Void","Integer ","Char"};
			printf("%s\t", names[ p->kind ]);
			
			switch( p->kind )
			{
				case OpK:
					{
					   switch(p->attr.op)
					   {
					       case PLUS:
					       {
					           printf("\top:+\t\t");
					           break;
					       }
					       case MINUS:
					       {
					           printf("\top:-\t\t");
					           break;
					       }
					       case TIMES:
					       {
					           printf("\top:*\t\t");
					           break;
					       }
					       case OVER:
					       {
					           printf("\top:/\t\t");
					           break;
					       }
					       case REMI:
					       {
					           printf("\top:%\t\t");
					           break;
					       }
					       case DPLUS:
					       {
					           printf("\top:++\t\t");
					           break;
					       }
					       case DMINUS:
					       {
					           printf("\top:--\t\t");
					           break;
					       }
					       case LT:
					       {
					           printf("\top:<\t\t");
					           break;
					       }
					       case LE:
					       {
					           printf("\top:<=\t\t");
					           break;
					       }
					       case GT:
					       {
					           printf("\top:>\t\t");
					           break;
					       }
					       case GE:
					       {
					           printf("\top:>=\t\t");
					           break;
					       }	
					       case EQ:
					       {
					           printf("\top:==\t\t");
					           break;
					       }
					       case NOT:
					       {
					           printf("\top:!=\t\t");
					           break;
					       }
					       case OR:
					       {
					           printf("\top:||\t\t");
					           break;
					           					       }
					       case AND:
					       {
					           printf("\top:&&\t\t");
					           break;
					       }
					   }
					   break;
					}
				case ConstK:
					{
						printf("values: %d\t",p->attr.val);
						break;//数字常量
					}
				case IdK:
					{
						printf("symbol: %s\t",p->attr.name);
						break;//字符
					}
				case TypeK:
					{
						printf("%s\t", types[ p->type ]);
						break;//types[3]中存储的Integer
					}
			}
			break;
		}
		case DeclK:
		{
			char names[2][20] = { "Var Declaration, ", "other"};
			printf("%s\t\t\t",names[p->kind]);
			break;//变量声明 int a,b;整体
		}
		
	}
	printf("children: ");
	for(int i=0;i<MAXCHILDREN;i++){
	    if(p->child[i] != NULL)
	    {
		    printf("%d  ",p->child[i]->lineno);//输出所有孩子结点
		    temp = p->child[i]->sibling;
		
		    while(temp != NULL)//有兄弟打印兄弟节点
		    {
			    printf("%d  ",temp->lineno);
			    temp = temp->sibling;
		    }
		
	    }
	}
	printf("\n");
	return ;
}
int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}

