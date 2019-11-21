#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 42 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 11/21/19
# Time: 16:21:56
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start $end

    1  start : MAIN LP RP comp_stmt

    2  comp_stmt : LFP stmt_list RFP

    3  stmt_list : stmt stmt_list
    4            | stmt

    5  stmt : var_dec
    6       | exp_stmt
    7       | if_stmt
    8       | for_stmt
    9       | while_stmt
   10       | comp_stmt
   11       | input_stmt
   12       | output_stmt
   13       | print_stmt

   14  input_stmt : INPUT LP exp RP SEMI

   15  output_stmt : OUTPUT LP exp RP SEMI

   16  print_stmt : PRINT LP exp RP SEMI

   17  type_spec : INT
   18            | CHAR
   19            | VOID

   20  id_list : exp COMMA id_list
   21          | exp

   22  var_dec : type_spec id_list SEMI

   23  if_stmt : IF LP exp RP stmt
   24          | IF LP exp RP stmt ELSE stmt

   25  for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt
   26           | FOR LP SEMI exp SEMI exp RP stmt
   27           | FOR LP exp SEMI SEMI exp RP stmt
   28           | FOR LP exp SEMI exp SEMI RP stmt
   29           | FOR LP SEMI SEMI exp RP stmt
   30           | FOR LP SEMI exp SEMI RP stmt
   31           | FOR LP exp SEMI SEMI RP stmt
   32           | FOR LP SEMI SEMI RP stmt

   33  while_stmt : WHILE LP exp RP stmt

   34  exp_stmt : exp SEMI
   35           | SEMI

   36  exp : exp ASSIGN exp
   37      | or_exp

   38  or_exp : or_exp OR and_exp
   39         | and_exp

   40  and_exp : and_exp AND exp_equ
   41          | exp_equ

   42  exp_equ : exp_equ EQ simple_exp
   43          | exp_equ LE simple_exp
   44          | exp_equ GE simple_exp
   45          | exp_equ LT simple_exp
   46          | exp_equ GT simple_exp
   47          | exp_equ NEQ simple_exp
   48          | simple_exp

   49  simple_exp : simple_exp PLUS term
   50             | simple_exp MINUS term
   51             | simple_exp TIMES term
   52             | simple_exp OVER term
   53             | simple_exp REMI term
   54             | simple_exp DPLUS
   55             | simple_exp DMINUS
   56             | term

   57  term : LP exp RP
   58       | ID
   59       | NUM
   60       | NOT term

   61  Grammar :


##############################################################################
# States
##############################################################################

state 0
	$accept : . start $end

	MAIN  shift 1

	start  goto 2


state 1
	start : MAIN . LP RP comp_stmt

	LP  shift 3


state 2
	$accept : start . $end  (0)

	$end  accept


state 3
	start : MAIN LP . RP comp_stmt

	RP  shift 4


state 4
	start : MAIN LP RP . comp_stmt

	LFP  shift 5

	comp_stmt  goto 6


state 5
	comp_stmt : LFP . stmt_list RFP

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	stmt_list  goto 22
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 30
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 6
	start : MAIN LP RP comp_stmt .  (1)

	.  reduce 1


state 7
	if_stmt : IF . LP exp RP stmt ELSE stmt
	if_stmt : IF . LP exp RP stmt

	LP  shift 39


state 8
	for_stmt : FOR . LP SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI SEMI RP stmt
	for_stmt : FOR . LP SEMI SEMI RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI SEMI exp RP stmt
	for_stmt : FOR . LP SEMI SEMI exp RP stmt

	LP  shift 40


state 9
	while_stmt : WHILE . LP exp RP stmt

	LP  shift 41


state 10
	input_stmt : INPUT . LP exp RP SEMI

	LP  shift 42


state 11
	print_stmt : PRINT . LP exp RP SEMI

	LP  shift 43


state 12
	output_stmt : OUTPUT . LP exp RP SEMI

	LP  shift 44


state 13
	type_spec : INT .  (17)

	.  reduce 17


state 14
	type_spec : CHAR .  (18)

	.  reduce 18


state 15
	type_spec : VOID .  (19)

	.  reduce 19


state 16
	term : ID .  (58)

	.  reduce 58


state 17
	term : NUM .  (59)

	.  reduce 59


state 18
	term : NOT . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 45


state 19
	exp_stmt : SEMI .  (35)

	.  reduce 35


state 20
	term : LP . exp RP

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 46
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 21
	stmt : comp_stmt .  (10)

	.  reduce 10


state 22
	comp_stmt : LFP stmt_list . RFP

	RFP  shift 47


state 23
	stmt : if_stmt .  (7)

	.  reduce 7


state 24
	stmt : for_stmt .  (8)

	.  reduce 8


state 25
	stmt : var_dec .  (5)

	.  reduce 5


state 26
	stmt : print_stmt .  (13)

	.  reduce 13


state 27
	stmt : exp_stmt .  (6)

	.  reduce 6


state 28
	stmt : input_stmt .  (11)

	.  reduce 11


state 29
	exp_stmt : exp . SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 49


state 30
	stmt_list : stmt . stmt_list
	stmt_list : stmt .  (4)

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5
	.  reduce 4

	comp_stmt  goto 21
	stmt_list  goto 50
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 30
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 31
	var_dec : type_spec . id_list SEMI

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 51
	id_list  goto 52
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 32
	stmt : output_stmt .  (12)

	.  reduce 12


state 33
	stmt : while_stmt .  (9)

	.  reduce 9


state 34
	simple_exp : term .  (56)

	.  reduce 56


state 35
	exp : or_exp .  (37)
	or_exp : or_exp . OR and_exp

	OR  shift 53
	.  reduce 37


state 36
	or_exp : and_exp .  (39)
	and_exp : and_exp . AND exp_equ

	AND  shift 54
	.  reduce 39


state 37
	exp_equ : exp_equ . GE simple_exp
	exp_equ : exp_equ . NEQ simple_exp
	and_exp : exp_equ .  (41)
	exp_equ : exp_equ . LT simple_exp
	exp_equ : exp_equ . EQ simple_exp
	exp_equ : exp_equ . LE simple_exp
	exp_equ : exp_equ . GT simple_exp

	LT  shift 55
	LE  shift 56
	GT  shift 57
	GE  shift 58
	EQ  shift 59
	NEQ  shift 60
	.  reduce 41


state 38
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	exp_equ : simple_exp .  (48)
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 48


state 39
	if_stmt : IF LP . exp RP stmt ELSE stmt
	if_stmt : IF LP . exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 68
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 40
	for_stmt : FOR LP . SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI SEMI RP stmt
	for_stmt : FOR LP . SEMI SEMI RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI SEMI exp RP stmt
	for_stmt : FOR LP . SEMI SEMI exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 69
	LP  shift 20

	exp  goto 70
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 41
	while_stmt : WHILE LP . exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 71
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 42
	input_stmt : INPUT LP . exp RP SEMI

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 72
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 43
	print_stmt : PRINT LP . exp RP SEMI

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 73
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 44
	output_stmt : OUTPUT LP . exp RP SEMI

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 74
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 45
	term : NOT term .  (60)

	.  reduce 60


state 46
	term : LP exp . RP
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 75


state 47
	comp_stmt : LFP stmt_list RFP .  (2)

	.  reduce 2


state 48
	exp : exp ASSIGN . exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 76
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 49
	exp_stmt : exp SEMI .  (34)

	.  reduce 34


state 50
	stmt_list : stmt stmt_list .  (3)

	.  reduce 3


state 51
	id_list : exp . COMMA id_list
	id_list : exp .  (21)
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	COMMA  shift 77
	.  reduce 21


state 52
	var_dec : type_spec id_list . SEMI

	SEMI  shift 78


state 53
	or_exp : or_exp OR . and_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	and_exp  goto 79
	exp_equ  goto 37
	simple_exp  goto 38


state 54
	and_exp : and_exp AND . exp_equ

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	exp_equ  goto 80
	simple_exp  goto 38


state 55
	exp_equ : exp_equ LT . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 81


state 56
	exp_equ : exp_equ LE . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 82


state 57
	exp_equ : exp_equ GT . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 83


state 58
	exp_equ : exp_equ GE . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 84


state 59
	exp_equ : exp_equ EQ . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 85


state 60
	exp_equ : exp_equ NEQ . simple_exp

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 34
	simple_exp  goto 86


state 61
	simple_exp : simple_exp PLUS . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 87


state 62
	simple_exp : simple_exp MINUS . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 88


state 63
	simple_exp : simple_exp TIMES . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 89


state 64
	simple_exp : simple_exp OVER . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 90


state 65
	simple_exp : simple_exp REMI . term

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 91


state 66
	simple_exp : simple_exp DPLUS .  (54)

	.  reduce 54


state 67
	simple_exp : simple_exp DMINUS .  (55)

	.  reduce 55


state 68
	if_stmt : IF LP exp . RP stmt ELSE stmt
	if_stmt : IF LP exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 92


state 69
	for_stmt : FOR LP SEMI . exp SEMI RP stmt
	for_stmt : FOR LP SEMI . SEMI RP stmt
	for_stmt : FOR LP SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP SEMI . SEMI exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 93
	LP  shift 20

	exp  goto 94
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 70
	for_stmt : FOR LP exp . SEMI SEMI RP stmt
	for_stmt : FOR LP exp . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP exp . SEMI exp SEMI RP stmt
	for_stmt : FOR LP exp . SEMI SEMI exp RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 95


state 71
	while_stmt : WHILE LP exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 96


state 72
	input_stmt : INPUT LP exp . RP SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 97


state 73
	print_stmt : PRINT LP exp . RP SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 98


state 74
	output_stmt : OUTPUT LP exp . RP SEMI
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 99


state 75
	term : LP exp RP .  (57)

	.  reduce 57


state 76
	exp : exp ASSIGN exp .  (36)
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	.  reduce 36


state 77
	id_list : exp COMMA . id_list

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20

	exp  goto 51
	id_list  goto 100
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 78
	var_dec : type_spec id_list SEMI .  (22)

	.  reduce 22


state 79
	and_exp : and_exp . AND exp_equ
	or_exp : or_exp OR and_exp .  (38)

	AND  shift 54
	.  reduce 38


state 80
	exp_equ : exp_equ . GE simple_exp
	exp_equ : exp_equ . NEQ simple_exp
	and_exp : and_exp AND exp_equ .  (40)
	exp_equ : exp_equ . LT simple_exp
	exp_equ : exp_equ . EQ simple_exp
	exp_equ : exp_equ . LE simple_exp
	exp_equ : exp_equ . GT simple_exp

	LT  shift 55
	LE  shift 56
	GT  shift 57
	GE  shift 58
	EQ  shift 59
	NEQ  shift 60
	.  reduce 40


state 81
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	exp_equ : exp_equ LT simple_exp .  (45)
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 45


state 82
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . REMI term
	exp_equ : exp_equ LE simple_exp .  (43)
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 43


state 83
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term
	exp_equ : exp_equ GT simple_exp .  (46)

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 46


state 84
	exp_equ : exp_equ GE simple_exp .  (44)
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 44


state 85
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	exp_equ : exp_equ EQ simple_exp .  (42)
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 42


state 86
	exp_equ : exp_equ NEQ simple_exp .  (47)
	simple_exp : simple_exp . OVER term
	simple_exp : simple_exp . MINUS term
	simple_exp : simple_exp . PLUS term
	simple_exp : simple_exp . DPLUS
	simple_exp : simple_exp . DMINUS
	simple_exp : simple_exp . REMI term
	simple_exp : simple_exp . TIMES term

	PLUS  shift 61
	MINUS  shift 62
	TIMES  shift 63
	OVER  shift 64
	REMI  shift 65
	DPLUS  shift 66
	DMINUS  shift 67
	.  reduce 47


state 87
	simple_exp : simple_exp PLUS term .  (49)

	.  reduce 49


state 88
	simple_exp : simple_exp MINUS term .  (50)

	.  reduce 50


state 89
	simple_exp : simple_exp TIMES term .  (51)

	.  reduce 51


state 90
	simple_exp : simple_exp OVER term .  (52)

	.  reduce 52


state 91
	simple_exp : simple_exp REMI term .  (53)

	.  reduce 53


state 92
	if_stmt : IF LP exp RP . stmt ELSE stmt
	if_stmt : IF LP exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 101
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 93
	for_stmt : FOR LP SEMI SEMI . RP stmt
	for_stmt : FOR LP SEMI SEMI . exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 102

	exp  goto 103
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 94
	for_stmt : FOR LP SEMI exp . SEMI RP stmt
	for_stmt : FOR LP SEMI exp . SEMI exp RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 104


state 95
	for_stmt : FOR LP exp SEMI . SEMI RP stmt
	for_stmt : FOR LP exp SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI . exp SEMI RP stmt
	for_stmt : FOR LP exp SEMI . SEMI exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 105
	LP  shift 20

	exp  goto 106
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 96
	while_stmt : WHILE LP exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 107
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 97
	input_stmt : INPUT LP exp RP . SEMI

	SEMI  shift 108


state 98
	print_stmt : PRINT LP exp RP . SEMI

	SEMI  shift 109


state 99
	output_stmt : OUTPUT LP exp RP . SEMI

	SEMI  shift 110


state 100
	id_list : exp COMMA id_list .  (20)

	.  reduce 20


state 101
	if_stmt : IF LP exp RP stmt . ELSE stmt
	if_stmt : IF LP exp RP stmt .  (23)

	ELSE  shift 111
	.  reduce 23


state 102
	for_stmt : FOR LP SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 112
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 103
	for_stmt : FOR LP SEMI SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 113


state 104
	for_stmt : FOR LP SEMI exp SEMI . RP stmt
	for_stmt : FOR LP SEMI exp SEMI . exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 114

	exp  goto 115
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 105
	for_stmt : FOR LP exp SEMI SEMI . RP stmt
	for_stmt : FOR LP exp SEMI SEMI . exp RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 116

	exp  goto 117
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 106
	for_stmt : FOR LP exp SEMI exp . SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI exp . SEMI RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	SEMI  shift 118


state 107
	while_stmt : WHILE LP exp RP stmt .  (33)

	.  reduce 33


state 108
	input_stmt : INPUT LP exp RP SEMI .  (14)

	.  reduce 14


state 109
	print_stmt : PRINT LP exp RP SEMI .  (16)

	.  reduce 16


state 110
	output_stmt : OUTPUT LP exp RP SEMI .  (15)

	.  reduce 15


state 111
	if_stmt : IF LP exp RP stmt ELSE . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 119
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 112
	for_stmt : FOR LP SEMI SEMI RP stmt .  (32)

	.  reduce 32


state 113
	for_stmt : FOR LP SEMI SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 120
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 114
	for_stmt : FOR LP SEMI exp SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 121
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 115
	for_stmt : FOR LP SEMI exp SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 122


state 116
	for_stmt : FOR LP exp SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 123
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 117
	for_stmt : FOR LP exp SEMI SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 124


state 118
	for_stmt : FOR LP exp SEMI exp SEMI . exp RP stmt
	for_stmt : FOR LP exp SEMI exp SEMI . RP stmt

	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 125

	exp  goto 126
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 119
	if_stmt : IF LP exp RP stmt ELSE stmt .  (24)

	.  reduce 24


state 120
	for_stmt : FOR LP SEMI SEMI exp RP stmt .  (29)

	.  reduce 29


state 121
	for_stmt : FOR LP SEMI exp SEMI RP stmt .  (30)

	.  reduce 30


state 122
	for_stmt : FOR LP SEMI exp SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 127
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 123
	for_stmt : FOR LP exp SEMI SEMI RP stmt .  (31)

	.  reduce 31


state 124
	for_stmt : FOR LP exp SEMI SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 128
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 125
	for_stmt : FOR LP exp SEMI exp SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 129
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 126
	for_stmt : FOR LP exp SEMI exp SEMI exp . RP stmt
	exp : exp . ASSIGN exp

	ASSIGN  shift 48
	RP  shift 130


state 127
	for_stmt : FOR LP SEMI exp SEMI exp RP stmt .  (26)

	.  reduce 26


state 128
	for_stmt : FOR LP exp SEMI SEMI exp RP stmt .  (27)

	.  reduce 27


state 129
	for_stmt : FOR LP exp SEMI exp SEMI RP stmt .  (28)

	.  reduce 28


state 130
	for_stmt : FOR LP exp SEMI exp SEMI exp RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	INPUT  shift 10
	PRINT  shift 11
	OUTPUT  shift 12
	INT  shift 13
	CHAR  shift 14
	VOID  shift 15
	ID  shift 16
	NUM  shift 17
	NOT  shift 18
	SEMI  shift 19
	LP  shift 20
	LFP  shift 5

	comp_stmt  goto 21
	if_stmt  goto 23
	for_stmt  goto 24
	var_dec  goto 25
	print_stmt  goto 26
	exp_stmt  goto 27
	input_stmt  goto 28
	exp  goto 29
	stmt  goto 131
	type_spec  goto 31
	output_stmt  goto 32
	while_stmt  goto 33
	term  goto 34
	or_exp  goto 35
	and_exp  goto 36
	exp_equ  goto 37
	simple_exp  goto 38


state 131
	for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt .  (25)

	.  reduce 25


Rules never reduced
	Grammar :  (61)


##############################################################################
# Summary
##############################################################################

38 token(s), 22 nonterminal(s)
62 grammar rule(s), 132 state(s)


##############################################################################
# End of File
##############################################################################
