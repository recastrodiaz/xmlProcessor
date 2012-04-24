This is a trivial academic project using Bison (GNU parser generator to work with grammar) and Flex (a fast lexical analyser generator).

#Validating a XML file with a reference to its DTD

*Warning : for now, we only verify that each tag has the right children,
but we do not verify the correctness of attributes. (and we do not verify many other things for sure ...)*

## Compiling (The long way)

###Compiling AnalyseurXML
    cd src/AnalyseurXML && make clean && make

###Compiling AnalyseurDTD
    cd src/AnalyseurDTD && make clean && make

###Building AnalyseurXMLDTD
    cd src/ && make
    
## Compiling (The sort way)
    cd src && make clean && ./build

##Starting
Write an example.xml file containing a reference toward its DTD.
This reference should be like the following line :
    <!DOCTYPE example SYSTEM "example.dtd">

Then do :

    ./analyseXMLDTD example.xml

