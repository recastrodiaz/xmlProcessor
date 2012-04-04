

#include "main.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>

#include "commun.h"
//#include "XMLClass/Element.h"
#include "XMLClass/DocXML.h"
#include "XMLClass/Balise.h"
//#include "XMLClass/Data.h"

#include "DTDClass/DtdDocument.h"

using namespace std;

extern string dtdURL;
extern int xmldebug;
extern int dtddebug;
int xmlparse(DocXML ** doc);
int dtdparse(DtdDocument ** dtdDocument);

extern FILE * xmlin;
extern FILE * dtdin;

void testPrintBalise(){
    Balise* b1 = new Balise ("test", "eheh");
    mapSS* attr = new mapSS();
    (*attr)["id1"]="kikoo";
    (*attr)["id2"]="lol";
    b1->addListAttributs (attr);
    b1->setEmpty(false);
    cout<<"b1 : "<<endl;
    b1->Print();
    
         
}

int main(int argc, char **argv)
{
	int err;
/*	testPrintBalise();

	printf("Parsing XML\n");

	if (argv[1] != NULL)
	{
		xmlin = fopen(argv[1],"r+");
		if (xmlin == NULL)
			return -1;
	}

	//xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	DocXML * doc;

	err = xmlparse(&doc);
	cout<<"doc print"<<endl;
	doc->Print();
	if (err != 0)
	{
		printf("Parse ended with %d error(s)\n", err);

	}
  	else  
	{
		printf("Parse ended with success\n", err);
		printf("dtdurl : %s\n",dtdURL.c_str());
		dtdin = fopen(dtdURL.c_str(),"r+");
	}
	fclose(xmlin);
*/

	if (argv[1] != NULL)
	{
		dtdin = fopen(argv[1],"r+");
		if (dtdin == NULL)
			return -1;
	}

	// dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	DtdDocument * dtdDocument;
	if (dtdin != NULL){
		err = dtdparse( &dtdDocument );
		if (err != 0) 
		{
			printf("Parse ended with %d error(s)\n", err);
		}
		else
		{
			printf("Parse ended with success\n", err);
			dtdDocument->Print();
		}
	}
	else
	{
		printf("dtd invalide\n");
		return -1;
	}
	fclose(dtdin);
	
	return 0;

}

