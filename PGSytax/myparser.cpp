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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 11/21/19
* Time: 16:21:56
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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

#line 125 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 100 ".\\myparser.y"

	// place any extra initialisation code here

#line 149 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 105 ".\\myparser.y"

	// place any extra cleanup code here

#line 163 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 140 ".\\myparser.y"
 
			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
				Display(yyattribute(4 - 4));//以复合语句为根节点，输入必须从main开始
			
#line 276 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 146 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);//建立新的语句节点：复合语句。
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 3);
			
#line 292 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 152 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(2 - 2);//if while是兄弟节点
				(*(YYSTYPE YYFAR*)yyvalptr)= yyattribute(1 - 2);		
			
#line 308 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 157 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1) ;
			
#line 323 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 338 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 166 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 353 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 170 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 368 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 174 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 383 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 178 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 398 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 182 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 413 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 186 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 428 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 190 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 443 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 194 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 458 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 199 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
               (*(YYSTYPE YYFAR*)yyvalptr) -> type =Boolean;
               (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
            
#line 475 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 206 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(OutputK);
               (*(YYSTYPE YYFAR*)yyvalptr) -> type =Boolean;
               (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
            
#line 492 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 213 ".\\myparser.y"

               (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(PrintK);
               (*(YYSTYPE YYFAR*)yyvalptr) -> type =Boolean;
               (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
            
#line 509 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 220 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//int
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Integer;
                   
			
#line 526 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 226 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//char
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Char;
			
#line 542 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 231 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//void
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Void;
			
#line 558 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 237 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(3 - 3);
			
#line 574 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 244 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newDeclNode (VarK);//建立一个新的变量声明的节点
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 3);
			
#line 591 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 252 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                 
#line 607 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 258 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                 
#line 624 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 265 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
			
#line 643 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 273 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(4 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(8 - 8);
			
#line 661 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 280 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(8 - 8);
			
#line 679 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 287 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(8 - 8);
			
#line 697 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 294 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(7 - 7);
			
#line 714 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 300 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(4 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(7 - 7);
			
#line 731 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 306 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(7 - 7);
			
#line 748 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 312 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(6 - 6);
			
#line 764 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 318 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
			
#line 781 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 325 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
			
#line 796 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 331 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(AssignK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
			
#line 813 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 337 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 828 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 342 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op =OR;
                (*(YYSTYPE YYFAR*)yyvalptr) ->child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 846 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 349 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 861 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 354 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = AND;
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 879 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 361 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 894 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 366 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=EQ;
			
#line 912 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 373 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LE;
			
#line 930 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 380 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=GE;
			
#line 948 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 387 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LT;
			
#line 966 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 394 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=GT;
			
#line 984 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 401 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=NEQ;
			
#line 1002 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 408 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1017 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 413 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = PLUS;

                 
#line 1035 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 420 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = MINUS;

                 
#line 1053 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 427 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = TIMES;
                 
#line 1070 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 433 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = OVER;
                 
#line 1087 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 439 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = REMI;
                 
#line 1104 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 445 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DPLUS;

			
#line 1122 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 452 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DMINUS;

			
#line 1140 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 458 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1153 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 461 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
			
#line 1168 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 465 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
				
			
#line 1184 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 470 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1199 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 474 ".\\myparser.y"

			   (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
			   (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = NOT;
			   (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] =yyattribute(2 - 2);
			
#line 1216 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "IF", 257 },
		{ "MAIN", 258 },
		{ "FOR", 259 },
		{ "WHILE", 260 },
		{ "INPUT", 261 },
		{ "PRINT", 262 },
		{ "OUTPUT", 263 },
		{ "INT", 264 },
		{ "CHAR", 265 },
		{ "VOID", 266 },
		{ "ID", 267 },
		{ "NUM", 268 },
		{ "PLUS", 269 },
		{ "MINUS", 270 },
		{ "TIMES", 271 },
		{ "OVER", 272 },
		{ "REMI", 273 },
		{ "DPLUS", 274 },
		{ "DMINUS", 275 },
		{ "LT", 276 },
		{ "LE", 277 },
		{ "GT", 278 },
		{ "GE", 279 },
		{ "EQ", 280 },
		{ "NEQ", 281 },
		{ "ASSIGN", 282 },
		{ "AND", 283 },
		{ "OR", 284 },
		{ "NOT", 285 },
		{ "SEMI", 286 },
		{ "COMMA", 287 },
		{ "LP", 288 },
		{ "RP", 289 },
		{ "LFP", 290 },
		{ "RFP", 291 },
		{ "ELSE", 294 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: start",
		"start: MAIN LP RP comp_stmt",
		"comp_stmt: LFP stmt_list RFP",
		"stmt_list: stmt stmt_list",
		"stmt_list: stmt",
		"stmt: var_dec",
		"stmt: exp_stmt",
		"stmt: if_stmt",
		"stmt: for_stmt",
		"stmt: while_stmt",
		"stmt: comp_stmt",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"stmt: print_stmt",
		"input_stmt: INPUT LP exp RP SEMI",
		"output_stmt: OUTPUT LP exp RP SEMI",
		"print_stmt: PRINT LP exp RP SEMI",
		"type_spec: INT",
		"type_spec: CHAR",
		"type_spec: VOID",
		"id_list: exp COMMA id_list",
		"id_list: exp",
		"var_dec: type_spec id_list SEMI",
		"if_stmt: IF LP exp RP stmt",
		"if_stmt: IF LP exp RP stmt ELSE stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI RP stmt",
		"while_stmt: WHILE LP exp RP stmt",
		"exp_stmt: exp SEMI",
		"exp_stmt: SEMI",
		"exp: exp ASSIGN exp",
		"exp: or_exp",
		"or_exp: or_exp OR and_exp",
		"or_exp: and_exp",
		"and_exp: and_exp AND exp_equ",
		"and_exp: exp_equ",
		"exp_equ: exp_equ EQ simple_exp",
		"exp_equ: exp_equ LE simple_exp",
		"exp_equ: exp_equ GE simple_exp",
		"exp_equ: exp_equ LT simple_exp",
		"exp_equ: exp_equ GT simple_exp",
		"exp_equ: exp_equ NEQ simple_exp",
		"exp_equ: simple_exp",
		"simple_exp: simple_exp PLUS term",
		"simple_exp: simple_exp MINUS term",
		"simple_exp: simple_exp TIMES term",
		"simple_exp: simple_exp OVER term",
		"simple_exp: simple_exp REMI term",
		"simple_exp: simple_exp DPLUS",
		"simple_exp: simple_exp DMINUS",
		"simple_exp: term",
		"term: LP exp RP",
		"term: ID",
		"term: NUM",
		"term: NOT term",
		"Grammar:"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 3, 2, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 4, 1, 12 },
		{ 5, 5, 13 },
		{ 6, 5, 14 },
		{ 7, 5, 15 },
		{ 8, 1, 16 },
		{ 8, 1, 17 },
		{ 8, 1, 18 },
		{ 9, 3, 19 },
		{ 9, 1, -1 },
		{ 10, 3, 20 },
		{ 11, 5, 21 },
		{ 11, 7, 22 },
		{ 12, 9, 23 },
		{ 12, 8, 24 },
		{ 12, 8, 25 },
		{ 12, 8, 26 },
		{ 12, 7, 27 },
		{ 12, 7, 28 },
		{ 12, 7, 29 },
		{ 12, 6, 30 },
		{ 13, 5, 31 },
		{ 14, 2, 32 },
		{ 14, 1, -1 },
		{ 15, 3, 33 },
		{ 15, 1, 34 },
		{ 16, 3, 35 },
		{ 16, 1, 36 },
		{ 17, 3, 37 },
		{ 17, 1, 38 },
		{ 18, 3, 39 },
		{ 18, 3, 40 },
		{ 18, 3, 41 },
		{ 18, 3, 42 },
		{ 18, 3, 43 },
		{ 18, 3, 44 },
		{ 18, 1, 45 },
		{ 19, 3, 46 },
		{ 19, 3, 47 },
		{ 19, 3, 48 },
		{ 19, 3, 49 },
		{ 19, 3, 50 },
		{ 19, 2, 51 },
		{ 19, 2, 52 },
		{ 19, 1, 53 },
		{ 20, 3, 54 },
		{ 20, 1, 55 },
		{ 20, 1, 56 },
		{ 20, 2, 57 },
		{ 21, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 138;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 30, YYAT_SHIFT, 7 },
		{ 117, YYAT_SHIFT, 124 },
		{ 30, YYAT_SHIFT, 8 },
		{ 30, YYAT_SHIFT, 9 },
		{ 30, YYAT_SHIFT, 10 },
		{ 30, YYAT_SHIFT, 11 },
		{ 30, YYAT_SHIFT, 12 },
		{ 30, YYAT_SHIFT, 13 },
		{ 30, YYAT_SHIFT, 14 },
		{ 30, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 16 },
		{ 30, YYAT_SHIFT, 17 },
		{ 130, YYAT_SHIFT, 7 },
		{ 115, YYAT_SHIFT, 122 },
		{ 130, YYAT_SHIFT, 8 },
		{ 130, YYAT_SHIFT, 9 },
		{ 130, YYAT_SHIFT, 10 },
		{ 130, YYAT_SHIFT, 11 },
		{ 130, YYAT_SHIFT, 12 },
		{ 130, YYAT_SHIFT, 13 },
		{ 130, YYAT_SHIFT, 14 },
		{ 130, YYAT_SHIFT, 15 },
		{ 118, YYAT_SHIFT, 16 },
		{ 118, YYAT_SHIFT, 17 },
		{ 105, YYAT_SHIFT, 116 },
		{ 126, YYAT_SHIFT, 48 },
		{ 106, YYAT_SHIFT, 48 },
		{ 104, YYAT_SHIFT, 114 },
		{ 30, YYAT_SHIFT, 18 },
		{ 30, YYAT_SHIFT, 19 },
		{ 106, YYAT_SHIFT, 118 },
		{ 30, YYAT_SHIFT, 20 },
		{ 126, YYAT_SHIFT, 130 },
		{ 30, YYAT_SHIFT, 5 },
		{ 80, YYAT_SHIFT, 55 },
		{ 80, YYAT_SHIFT, 56 },
		{ 80, YYAT_SHIFT, 57 },
		{ 80, YYAT_SHIFT, 58 },
		{ 80, YYAT_SHIFT, 59 },
		{ 80, YYAT_SHIFT, 60 },
		{ 118, YYAT_SHIFT, 18 },
		{ 130, YYAT_SHIFT, 19 },
		{ 103, YYAT_SHIFT, 113 },
		{ 118, YYAT_SHIFT, 20 },
		{ 118, YYAT_SHIFT, 125 },
		{ 130, YYAT_SHIFT, 5 },
		{ 86, YYAT_SHIFT, 61 },
		{ 86, YYAT_SHIFT, 62 },
		{ 86, YYAT_SHIFT, 63 },
		{ 86, YYAT_SHIFT, 64 },
		{ 86, YYAT_SHIFT, 65 },
		{ 86, YYAT_SHIFT, 66 },
		{ 86, YYAT_SHIFT, 67 },
		{ 85, YYAT_SHIFT, 61 },
		{ 85, YYAT_SHIFT, 62 },
		{ 85, YYAT_SHIFT, 63 },
		{ 85, YYAT_SHIFT, 64 },
		{ 85, YYAT_SHIFT, 65 },
		{ 85, YYAT_SHIFT, 66 },
		{ 85, YYAT_SHIFT, 67 },
		{ 84, YYAT_SHIFT, 61 },
		{ 84, YYAT_SHIFT, 62 },
		{ 84, YYAT_SHIFT, 63 },
		{ 84, YYAT_SHIFT, 64 },
		{ 84, YYAT_SHIFT, 65 },
		{ 84, YYAT_SHIFT, 66 },
		{ 84, YYAT_SHIFT, 67 },
		{ 83, YYAT_SHIFT, 61 },
		{ 83, YYAT_SHIFT, 62 },
		{ 83, YYAT_SHIFT, 63 },
		{ 83, YYAT_SHIFT, 64 },
		{ 83, YYAT_SHIFT, 65 },
		{ 83, YYAT_SHIFT, 66 },
		{ 83, YYAT_SHIFT, 67 },
		{ 82, YYAT_SHIFT, 61 },
		{ 82, YYAT_SHIFT, 62 },
		{ 82, YYAT_SHIFT, 63 },
		{ 82, YYAT_SHIFT, 64 },
		{ 82, YYAT_SHIFT, 65 },
		{ 82, YYAT_SHIFT, 66 },
		{ 82, YYAT_SHIFT, 67 },
		{ 81, YYAT_SHIFT, 61 },
		{ 81, YYAT_SHIFT, 62 },
		{ 81, YYAT_SHIFT, 63 },
		{ 81, YYAT_SHIFT, 64 },
		{ 81, YYAT_SHIFT, 65 },
		{ 81, YYAT_SHIFT, 66 },
		{ 81, YYAT_SHIFT, 67 },
		{ 38, YYAT_SHIFT, 61 },
		{ 38, YYAT_SHIFT, 62 },
		{ 38, YYAT_SHIFT, 63 },
		{ 38, YYAT_SHIFT, 64 },
		{ 38, YYAT_SHIFT, 65 },
		{ 38, YYAT_SHIFT, 66 },
		{ 38, YYAT_SHIFT, 67 },
		{ 37, YYAT_SHIFT, 55 },
		{ 37, YYAT_SHIFT, 56 },
		{ 37, YYAT_SHIFT, 57 },
		{ 37, YYAT_SHIFT, 58 },
		{ 37, YYAT_SHIFT, 59 },
		{ 37, YYAT_SHIFT, 60 },
		{ 51, YYAT_SHIFT, 48 },
		{ 101, YYAT_SHIFT, 111 },
		{ 99, YYAT_SHIFT, 110 },
		{ 98, YYAT_SHIFT, 109 },
		{ 97, YYAT_SHIFT, 108 },
		{ 51, YYAT_SHIFT, 77 },
		{ 95, YYAT_SHIFT, 105 },
		{ 94, YYAT_SHIFT, 104 },
		{ 93, YYAT_SHIFT, 102 },
		{ 79, YYAT_SHIFT, 54 },
		{ 77, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 48 },
		{ 74, YYAT_SHIFT, 99 },
		{ 73, YYAT_SHIFT, 98 },
		{ 72, YYAT_SHIFT, 97 },
		{ 71, YYAT_SHIFT, 96 },
		{ 70, YYAT_SHIFT, 95 },
		{ 69, YYAT_SHIFT, 93 },
		{ 68, YYAT_SHIFT, 92 },
		{ 52, YYAT_SHIFT, 78 },
		{ 46, YYAT_SHIFT, 75 },
		{ 40, YYAT_SHIFT, 69 },
		{ 36, YYAT_SHIFT, 54 },
		{ 35, YYAT_SHIFT, 53 },
		{ 29, YYAT_SHIFT, 49 },
		{ 22, YYAT_SHIFT, 47 },
		{ 12, YYAT_SHIFT, 44 },
		{ 11, YYAT_SHIFT, 43 },
		{ 10, YYAT_SHIFT, 42 },
		{ 9, YYAT_SHIFT, 41 },
		{ 8, YYAT_SHIFT, 40 },
		{ 7, YYAT_SHIFT, 39 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -121, 1, YYAT_ERROR, 0 },
		{ -152, 1, YYAT_ERROR, 0 },
		{ 135, 1, YYAT_ERROR, 0 },
		{ -155, 1, YYAT_ERROR, 0 },
		{ -157, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -156, 1, YYAT_ERROR, 0 },
		{ -157, 1, YYAT_ERROR, 0 },
		{ -158, 1, YYAT_ERROR, 0 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_ERROR, 0 },
		{ -161, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -165, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -161, 1, YYAT_DEFAULT, 106 },
		{ -257, 1, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ -160, 1, YYAT_REDUCE, 37 },
		{ -160, 1, YYAT_REDUCE, 39 },
		{ -181, 1, YYAT_REDUCE, 41 },
		{ -181, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ -164, 1, YYAT_DEFAULT, 95 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ -168, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -181, 1, YYAT_REDUCE, 21 },
		{ -166, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ -170, 1, YYAT_DEFAULT, 126 },
		{ -168, 1, YYAT_DEFAULT, 95 },
		{ -169, 1, YYAT_DEFAULT, 106 },
		{ -173, 1, YYAT_DEFAULT, 126 },
		{ -174, 1, YYAT_DEFAULT, 126 },
		{ -175, 1, YYAT_DEFAULT, 126 },
		{ -176, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ -170, 1, YYAT_REDUCE, 36 },
		{ -178, 1, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -173, 1, YYAT_REDUCE, 38 },
		{ -242, 1, YYAT_REDUCE, 40 },
		{ -188, 1, YYAT_REDUCE, 45 },
		{ -195, 1, YYAT_REDUCE, 43 },
		{ -202, 1, YYAT_REDUCE, 46 },
		{ -209, 1, YYAT_REDUCE, 44 },
		{ -216, 1, YYAT_REDUCE, 42 },
		{ -223, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -180, 1, YYAT_DEFAULT, 118 },
		{ -178, 1, YYAT_DEFAULT, 106 },
		{ -179, 1, YYAT_DEFAULT, 77 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -181, 1, YYAT_ERROR, 0 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -183, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ -192, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -247, 1, YYAT_DEFAULT, 126 },
		{ -262, 1, YYAT_DEFAULT, 118 },
		{ -265, 1, YYAT_DEFAULT, 118 },
		{ -256, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -276, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -288, 1, YYAT_DEFAULT, 126 },
		{ -245, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -257, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -245, 1, YYAT_DEFAULT, 95 },
		{ 0, 0, YYAT_REDUCE, 25 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 63;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 130, 21 },
		{ 77, 100 },
		{ 130, 131 },
		{ 130, 28 },
		{ 130, 32 },
		{ 130, 26 },
		{ 130, 31 },
		{ 77, 51 },
		{ 130, 25 },
		{ 130, 23 },
		{ 130, 24 },
		{ 130, 33 },
		{ 130, 27 },
		{ 130, 29 },
		{ 118, 126 },
		{ 118, 35 },
		{ 118, 36 },
		{ 60, 86 },
		{ 60, 34 },
		{ 54, 80 },
		{ 54, 38 },
		{ 53, 79 },
		{ 53, 37 },
		{ 30, 50 },
		{ 30, 30 },
		{ 125, 129 },
		{ 124, 128 },
		{ 122, 127 },
		{ 116, 123 },
		{ 114, 121 },
		{ 113, 120 },
		{ 111, 119 },
		{ 105, 117 },
		{ 104, 115 },
		{ 102, 112 },
		{ 96, 107 },
		{ 95, 106 },
		{ 93, 103 },
		{ 92, 101 },
		{ 69, 94 },
		{ 65, 91 },
		{ 64, 90 },
		{ 63, 89 },
		{ 62, 88 },
		{ 61, 87 },
		{ 59, 85 },
		{ 58, 84 },
		{ 57, 83 },
		{ 56, 82 },
		{ 55, 81 },
		{ 48, 76 },
		{ 44, 74 },
		{ 43, 73 },
		{ 42, 72 },
		{ 41, 71 },
		{ 40, 70 },
		{ 39, 68 },
		{ 31, 52 },
		{ 20, 46 },
		{ 18, 45 },
		{ 5, 22 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 61, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 59, -1 },
		{ 57, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, -1 },
		{ 0, -1 },
		{ 43, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 20, 130 },
		{ 48, 77 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 41, 118 },
		{ 40, 118 },
		{ 39, 118 },
		{ 38, 118 },
		{ 37, 118 },
		{ 36, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 35, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 4, 54 },
		{ 1, 60 },
		{ 30, 60 },
		{ 29, 60 },
		{ 28, 60 },
		{ 27, 60 },
		{ 26, 60 },
		{ -2, -1 },
		{ 24, -1 },
		{ 23, -1 },
		{ 22, -1 },
		{ 21, -1 },
		{ 20, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -8, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 34, 130 },
		{ 22, 118 },
		{ 0, -1 },
		{ 21, 118 },
		{ 31, 130 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 30, 130 },
		{ 0, -1 },
		{ 18, 118 },
		{ 17, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 27, 130 },
		{ 0, -1 },
		{ 26, 130 },
		{ 25, 130 },
		{ 0, -1 },
		{ 24, 130 },
		{ 0, -1 },
		{ -1, 53 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 130 },
		{ 0, -1 },
		{ 22, 130 },
		{ 21, 130 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 118 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 484 ".\\myparser.y"


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
	freopen("input.txt", "r", stdin);
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}


