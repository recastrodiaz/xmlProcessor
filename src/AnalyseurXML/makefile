SRC:= lex.xml.c xml.tab.c
OBJ:= ${SRC:.c=.o} 

${OBJ}: *.l *.y makefile
	@flex  -Pxml xml.l 
	@bison --debug --verbose -p xml --defines=xml.tab.h xml.y
	@g++ -g -c  ${SRC}
clean:
	@-rm -rf *.o *.tab.c lex.*.c *.tab.h *.output 

 
