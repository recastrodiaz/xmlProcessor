SRC:= main.cpp HTMLProc.cpp ../XMLClass/*.cpp 
#OBJ:= *.o
OBJ:= main.o HTMLProc.o Element.o DocXML.o Balise.o Data.o 
#${DTDPATH}*.y ${DTDPATH}*.l ${XMLPATH}*.y ${XMLPATH}*.l 

all: testHTMLProc

testHTMLProc: ${SRC} 

	g++ -g -c ${SRC}
	g++ -DYYDEBUG=1 -g -o testHTMLProc ${OBJ} 

clean:
	-rm -rf *.o testHTMLProc

