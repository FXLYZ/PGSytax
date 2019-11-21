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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 11/21/19
# Time: 16:21:56
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "if"

    2  "else"

    3  "for"

    4  "while"

    5  "void"

    6  "int"

    7  "char"

    8  "input"

    9  "output"

   10  "print"

   11  "main"

   12  "+"

   13  "-"

   14  "*"

   15  "/"

   16  "%"

   17  "++"

   18  "--"

   19  ">="

   20  "<="

   21  ">"

   22  "<"

   23  "!="

   24  "&&"

   25  "||"

   26  "!"

   27  "=="

   28  "="

   29  ","

   30  ";"

   31  "("

   32  ")"

   33  "["

   34  "]"

   35  "{"

   36  "}"

   37  [ \t\n]*

   38  ("/*"([^*]|\*+[^*/])*\*+"/")|("//"[^\n]*|"\/\*".*"\*\/")

   39  [_A-Za-z]([_A-Za-z]|[0-9])*

   40  [0-9]+


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x25               goto 5
	0x26               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30 - 0x39 (10)   goto 14
	0x3b               goto 15
	0x3c               goto 16
	0x3d               goto 17
	0x3e               goto 18
	0x41 - 0x5a (26)   goto 19
	0x5b               goto 20
	0x5d               goto 21
	0x5f               goto 19
	0x61 - 0x62 (2)    goto 19
	0x63               goto 22
	0x64               goto 19
	0x65               goto 23
	0x66               goto 24
	0x67 - 0x68 (2)    goto 19
	0x69               goto 25
	0x6a - 0x6c (3)    goto 19
	0x6d               goto 26
	0x6e               goto 19
	0x6f               goto 27
	0x70               goto 28
	0x71 - 0x75 (5)    goto 19
	0x76               goto 29
	0x77               goto 30
	0x78 - 0x7a (3)    goto 19
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33


state 2
	^INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x25               goto 5
	0x26               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30 - 0x39 (10)   goto 14
	0x3b               goto 15
	0x3c               goto 16
	0x3d               goto 17
	0x3e               goto 18
	0x41 - 0x5a (26)   goto 19
	0x5b               goto 20
	0x5d               goto 21
	0x5f               goto 19
	0x61 - 0x62 (2)    goto 19
	0x63               goto 22
	0x64               goto 19
	0x65               goto 23
	0x66               goto 24
	0x67 - 0x68 (2)    goto 19
	0x69               goto 25
	0x6a - 0x6c (3)    goto 19
	0x6d               goto 26
	0x6e               goto 19
	0x6f               goto 27
	0x70               goto 28
	0x71 - 0x75 (5)    goto 19
	0x76               goto 29
	0x77               goto 30
	0x78 - 0x7a (3)    goto 19
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33


state 3
	0x09 - 0x0a (2)    goto 3
	0x20               goto 3

	match 37


state 4
	0x3d               goto 34

	match 26


state 5
	match 16


state 6
	0x26               goto 35


state 7
	match 31


state 8
	match 32


state 9
	match 14


state 10
	0x2b               goto 36

	match 12


state 11
	match 29


state 12
	0x2d               goto 37

	match 13


state 13
	0x2a               goto 38
	0x2f               goto 39

	match 15


state 14
	0x30 - 0x39 (10)   goto 14

	match 40


state 15
	match 30


state 16
	0x3d               goto 40

	match 22


state 17
	0x3d               goto 41

	match 28


state 18
	0x3d               goto 42

	match 21


state 19
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 39


state 20
	match 33


state 21
	match 34


state 22
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x67 (7)    goto 19
	0x68               goto 43
	0x69 - 0x7a (18)   goto 19

	match 39


state 23
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 44
	0x6d - 0x7a (14)   goto 19

	match 39


state 24
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 45
	0x70 - 0x7a (11)   goto 19

	match 39


state 25
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x65 (5)    goto 19
	0x66               goto 46
	0x67 - 0x6d (7)    goto 19
	0x6e               goto 47
	0x6f - 0x7a (12)   goto 19

	match 39


state 26
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61               goto 48
	0x62 - 0x7a (25)   goto 19

	match 39


state 27
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x74 (20)   goto 19
	0x75               goto 49
	0x76 - 0x7a (5)    goto 19

	match 39


state 28
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 50
	0x73 - 0x7a (8)    goto 19

	match 39


state 29
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6e (14)   goto 19
	0x6f               goto 51
	0x70 - 0x7a (11)   goto 19

	match 39


state 30
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x67 (7)    goto 19
	0x68               goto 52
	0x69 - 0x7a (18)   goto 19

	match 39


state 31
	match 35


state 32
	0x7c               goto 53


state 33
	match 36


state 34
	match 23


state 35
	match 24


state 36
	match 17


state 37
	match 18


state 38
	0x00 - 0x09 (10)   goto 38
	0x0a               goto 54
	0x0b - 0x29 (31)   goto 38
	0x2a               goto 55
	0x2b - 0xff (213)  goto 38


state 39
	0x00 - 0x09 (10)   goto 39
	0x0b - 0xff (245)  goto 39

	match 38


state 40
	match 20


state 41
	match 27


state 42
	match 19


state 43
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61               goto 56
	0x62 - 0x7a (25)   goto 19

	match 39


state 44
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x72 (18)   goto 19
	0x73               goto 57
	0x74 - 0x7a (7)    goto 19

	match 39


state 45
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 58
	0x73 - 0x7a (8)    goto 19

	match 39


state 46
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 1


state 47
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6f (15)   goto 19
	0x70               goto 59
	0x71 - 0x73 (3)    goto 19
	0x74               goto 60
	0x75 - 0x7a (6)    goto 19

	match 39


state 48
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x68 (8)    goto 19
	0x69               goto 61
	0x6a - 0x7a (17)   goto 19

	match 39


state 49
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 62
	0x75 - 0x7a (6)    goto 19

	match 39


state 50
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x68 (8)    goto 19
	0x69               goto 63
	0x6a - 0x7a (17)   goto 19

	match 39


state 51
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x68 (8)    goto 19
	0x69               goto 64
	0x6a - 0x7a (17)   goto 19

	match 39


state 52
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x68 (8)    goto 19
	0x69               goto 65
	0x6a - 0x7a (17)   goto 19

	match 39


state 53
	match 25


state 54
	0x00 - 0x29 (42)   goto 54
	0x2a               goto 66
	0x2b - 0xff (213)  goto 54


state 55
	0x00 - 0x09 (10)   goto 38
	0x0a               goto 54
	0x0b - 0x29 (31)   goto 38
	0x2a               goto 55
	0x2b - 0x2e (4)    goto 38
	0x2f               goto 67
	0x30 - 0xff (208)  goto 38


state 56
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x71 (17)   goto 19
	0x72               goto 68
	0x73 - 0x7a (8)    goto 19

	match 39


state 57
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 69
	0x66 - 0x7a (21)   goto 19

	match 39


state 58
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 3


state 59
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x74 (20)   goto 19
	0x75               goto 70
	0x76 - 0x7a (5)    goto 19

	match 39


state 60
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 6


state 61
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6d (13)   goto 19
	0x6e               goto 71
	0x6f - 0x7a (12)   goto 19

	match 39


state 62
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6f (15)   goto 19
	0x70               goto 72
	0x71 - 0x7a (10)   goto 19

	match 39


state 63
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6d (13)   goto 19
	0x6e               goto 73
	0x6f - 0x7a (12)   goto 19

	match 39


state 64
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x63 (3)    goto 19
	0x64               goto 74
	0x65 - 0x7a (22)   goto 19

	match 39


state 65
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x6b (11)   goto 19
	0x6c               goto 75
	0x6d - 0x7a (14)   goto 19

	match 39


state 66
	0x00 - 0x29 (42)   goto 54
	0x2a               goto 66
	0x2b - 0x2e (4)    goto 54
	0x2f               goto 76
	0x30 - 0xff (208)  goto 54


state 67
	0x00 - 0x09 (10)   goto 77
	0x0b - 0x29 (31)   goto 77
	0x2a               goto 78
	0x2b - 0xff (213)  goto 77

	match 38


state 68
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 7


state 69
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 2


state 70
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 79
	0x75 - 0x7a (6)    goto 19

	match 39


state 71
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 11


state 72
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x74 (20)   goto 19
	0x75               goto 80
	0x76 - 0x7a (5)    goto 19

	match 39


state 73
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 81
	0x75 - 0x7a (6)    goto 19

	match 39


state 74
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 5


state 75
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x64 (4)    goto 19
	0x65               goto 82
	0x66 - 0x7a (21)   goto 19

	match 39


state 76
	match 38


state 77
	0x00 - 0x09 (10)   goto 77
	0x0b - 0x29 (31)   goto 77
	0x2a               goto 78
	0x2b - 0xff (213)  goto 77


state 78
	0x00 - 0x09 (10)   goto 77
	0x0b - 0x29 (31)   goto 77
	0x2a               goto 78
	0x2b - 0x2e (4)    goto 77
	0x2f               goto 67
	0x30 - 0xff (208)  goto 77


state 79
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 8


state 80
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x73 (19)   goto 19
	0x74               goto 83
	0x75 - 0x7a (6)    goto 19

	match 39


state 81
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 10


state 82
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 4


state 83
	0x30 - 0x39 (10)   goto 19
	0x41 - 0x5a (26)   goto 19
	0x5f               goto 19
	0x61 - 0x7a (26)   goto 19

	match 9


#############################################################################
# Summary
#############################################################################

1 start state(s)
40 expression(s), 83 state(s)


#############################################################################
# End of File
#############################################################################
