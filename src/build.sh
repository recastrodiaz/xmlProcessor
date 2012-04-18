#!/bin/bash
# On construit l'analyseur XML
cd AnalyseurXML
make
# On construit l'analyseur DTD
cd ../AnalyseurDTD
make
# On construit l'analyseur XML-DTD
cd ..
make
# Un test pour lire les DTD
./analyseXMLDTD rap1.dtd

