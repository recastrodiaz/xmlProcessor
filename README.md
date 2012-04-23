This is a trivial academic project using Bison (GNU parser generator to work with grammar) and Flex (a fast lexical analyser generator).

#Validating a XML file with a reference to its DTD

*Warning : for now, we only verify that each tag has the right children,
but we do not verify the correctness of attributes. (and we do not verify many other things for sure ...)*

##Compiling AnalyseurXML
    cd src/AnalyseurXML && make

##Compiling AnalyseurDTD
    cd src/AnalyseurDTD && make

##Building AnalyseurXMLDTD
    cd src/ && make

##Starting
Write a example.xml file containing a reference toward its DTD.
This reference should be like the following line :
    <!DOCTYPE example SYSTEM "example.dtd">

Then do :

    ./analyseXMLDTD example.xml

