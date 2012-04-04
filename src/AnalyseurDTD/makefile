#all: analyseDTD
SRC:= lex.dtd.c dtd.tab.c
OBJ:= ${SRC:.c=.o} 

${OBJ}: *.l *.y makefile
	flex  -Pdtd dtd.l
	bison --debug --verbose -p dtd --defines=dtd.tab.h dtd.y
	g++ -c ${SRC} 
	# g++ -DYYDEBUG=1 -o analyseDTD lex.dtd.o dtd.tab.o 

clean:
	-rm -rf *.o *.tab.c lex.*.c *.tab.h *.output 
#analyseDTD


