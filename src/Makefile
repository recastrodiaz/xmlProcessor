XMLPATH := AnalyseurXML/
DTDPATH := AnalyseurDTD/
SRC:= main.cpp XMLClass/*.cpp DTDClass/*.cpp
OBJ:= main.o Element.o DocXML.o Balise.o Data.o DtdDocument.o DtdBalise.o DtdElement.o AttList.o AttDef.o ElementAttBase.o ElementAtt.o ElementAttList.o

all: analyseXMLDTD

analyseXMLDTD: ${SRC} main.h  
	
	@make -C ${XMLPATH} 
	@make -C ${DTDPATH} 

	@g++ -g -c ${SRC}
	@g++ -DYYDEBUG=1 -g -o analyseXMLDTD ${OBJ} ${DTDPATH}lex.dtd.o ${DTDPATH}dtd.tab.o ${XMLPATH}lex.xml.o ${XMLPATH}xml.tab.o

clean:
	@make -C ${XMLPATH} clean
	@make -C ${DTDPATH} clean
	@-rm -rf *.o analyseXMLDTD

Test :
	@echo "\nTest rap1.xml\n"
	./analyseXMLDTD Tests/rap1.xml

	@echo "\nTest rap2.xml\n"
	./analyseXMLDTD Tests/rap2.xml
