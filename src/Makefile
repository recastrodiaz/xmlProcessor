XMLPATH := ./AnalyseurXML/
DTDPATH := ./AnalyseurDTD/
SRC:= main.cpp main.h 
#${DTDPATH}*.y ${DTDPATH}*.l ${XMLPATH}*.y ${XMLPATH}*.l 

all: analyseXMLDTD

analyseXMLDTD: ${SRC}
	#flex  -Pdtd ${DTDPATH}dtd.l
	#bison --debug --verbose -p dtd --defines=${DTDPATH}dtd.tab.h ${DTDPATH}dtd.y
	#g++ -c lex.dtd.c dtd.tab.c 

	#flex  -Pxml ${XMLPATH}xml.l 
	#bison --debug --verbose -p xml --defines=${XMLPATH}xml.tab.h ${XMLPATH}xml.y
	#g++ -c  lex.xml.c  xml.tab.c  

	g++ -c main.cpp 
	g++ -o analyseXMLDTD main.o ${DTDPATH}lex.dtd.o ${DTDPATH}dtd.tab.o ${XMLPATH}lex.xml.o ${XMLPATH}xml.tab.o  

clean:
	-rm -rf *.o ${DTDPATH}*.tab.c ${DTDPATH}lex.*.c ${DTDPATH}*.tab.h ${DTDPATH}*.output ${XMLPATH}*.tab.c ${XMLPATH}lex.*.c ${XMLPATH}*.tab.h ${XMLPATH}*.output analyseXMLDTD

