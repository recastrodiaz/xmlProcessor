#all: analyseXSL
SRC:= lex.xsl.c xsl.tab.c
OBJ:= ${SRC:.c=.o} 

${OBJ}: *.l *.y makefile
	flex  -Pxsl xsl.l 
	bison --debug --verbose -p xsl --defines=xsl.tab.h xsl.y
	g++ -g -c  ${SRC}
	#g++ -g -DYYDEBUG=1 -o analyseXSL lex.xsl.o  xsl.tab.o  
clean:
	-rm -rf *.o *.tab.c lex.*.c *.tab.h *.output 
#analyseXSL

 
