#all: analyseXML
SRC:= lex.xml.c xml.tab.c
OBJ:= ${SRC:.c=.o} 

${OBJ}: *.l *.y makefile
	flex  -Pxml xml.l 
	bison --debug --verbose -p xml --defines=xml.tab.h xml.y
	g++ -c  ${SRC}
	#g++ -g -DYYDEBUG=1 -o analyseXML lex.xml.o  xml.tab.o  
clean:
	-rm -rf *.o *.tab.c lex.*.c *.tab.h *.output 
#analyseXML

 
