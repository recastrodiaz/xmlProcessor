#!/bin/bash
# On clean
make clean
# On construit l'analyseur XML
cd AnalyseurXML
make
# On construit l'analyseur DTD
cd ../AnalyseurDTD
make
# On construit l'analyseur XML-DTD
cd ..
make
# On nettoie les differents 'build' precedents
cd AnalyseurXML
make clean
cd ../AnalyseurDTD
make clean
cd ..
# Un test pour lire les DTD
./analyseXMLDTD rap1.xml

