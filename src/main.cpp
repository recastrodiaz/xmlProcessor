

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
int dtdparse(DtdDocument * dtdDocument);

extern FILE * xmlin;
extern FILE * dtdin;

void testPrintBalise()
{
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
	string filePath;
	int index;
//*	
	//testPrintBalise();

	printf("Parsing XML\n");

	//xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	DocXML * doc;

	//debug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	DtdDocument dtdDocument;

	if (argv[1] != NULL)
	{
		// On a passe un fichier .xml en parametre
		if ( std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xml" ||
			 std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xsl" )
		{
			std::cout << "On va parser du XML!" << std::endl;
			index = string(argv[1]).find_last_of("/");
			filePath.assign(argv[1],index+1);
			cout<<"filepath : "<<filePath<<endl;

			xmlin = fopen(argv[1],"r+");
			if (xmlin == NULL)
				return -1;

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
				dtdURL = filePath + dtdURL;

				printf("dtdurl : %s\n",dtdURL.c_str());
				dtdin = fopen(dtdURL.c_str(),"r+");
	
				if (dtdin != NULL)
				{
					err = dtdparse( &dtdDocument );
					if (err != 0) 
					{
						printf("Parse ended with %d error(s)\n", err);
					}
					else
					{
						printf("Parse ended with success\n", err);
						dtdDocument.Print();
						dtdDocument.GenerateRE();
						if (doc->verifyValidity(dtdDocument))
						{
							cout << "THE XML DOC IS VALID !" << endl;
						}
						else
						{
							cout << "THE XML DOC IS *NOT* VALID" << endl;
						}
					}
				}
				else
				{
					printf("dtd invalide\n");
					return -1;
				}
				fclose(dtdin);
			}
			fclose(xmlin);
		}
		else if ( std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "dtd" )
		{
			std::cout << "On va parser de la DTD!" << std::endl;
			dtdin = fopen(argv[1],"r+");
			if (dtdin == NULL)
				return -1;
			
			if (dtdin != NULL)
			{
				err = dtdparse( &dtdDocument );
				if (err != 0) 
				{
					printf("Parse ended with %d error(s)\n", err);
				}
				else
				{
					printf("Parse ended with success\n", err);
					dtdDocument.Print();
				}
			}
			else
			{
				printf("dtd invalide\n");
				return -1;
			}
			fclose(dtdin);
		}
	}	

	return 0;
}

