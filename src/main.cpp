

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
#include "ProcesseurHTML/HTMLProc.h"

using namespace std;

//extern string dtdURL;
extern int xmldebug;
extern int dtddebug;
int xmlparse(DocXML ** doc);
int dtdparse(DtdDocument * dtdDocument);
void initialise(void);

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


int parseDoc(char * docToParse, DocXML *&doc, DtdDocument *dtdDocument, int &err){
	bool xsl = false;
	int index;
	string filePath;
	string dtdURL;
	
	if(std::string(docToParse).substr(strlen(docToParse)-3,strlen(docToParse)-1) == "xsl")
		xsl = true;
	
	std::cout << "On va parser le " << std::string(docToParse).substr(strlen(docToParse)-3,strlen(docToParse)-1) << "..." << std::endl;
	xmlin = fopen(docToParse,"r+");
	if (xmlin == NULL)
		return -1;
	initialise();
	err = xmlparse(&doc);
	cout<<"doc print"<<endl;
	if (err != 0)
	{
		printf("Parse ended with %d error(s)\n", err);
	}
	else  
	{
		printf("Parse ended with success\n", err);
		doc->Print();
		if(!xsl){
			
			index = string(docToParse).find_last_of("/");
			filePath.assign(docToParse,index+1);
			cout<<"filepath : "<<filePath<<endl;
			
			dtdURL = filePath + doc->GetDtdUrl();

			printf("dtdurl : %s\n",dtdURL.c_str());
			
			dtdin = fopen(dtdURL.c_str(),"r+");
			
			if (dtdin != NULL)
			{
				err = dtdparse( dtdDocument );
				if (err != 0) 
				{
					printf("Parse ended with %d error(s)\n", err);
				}
				else
				{
					printf("Parse ended with success\n", err);
					dtdDocument->Print();
					dtdDocument->GenerateRE();
					if (doc->verifyValidity(*dtdDocument))
					{
						cout << "THE XML DOC IS VALID !" << endl;
					}
					else
					{
						cout << "THE XML DOC IS *NOT* VALID" << endl;
						err = -1;
					}
				}
			}
			else 
			{
				printf("dtd invalide\n");
				err = -1;
			}
			fclose(dtdin);
		}
	}
	fclose(xmlin);
	return err;
}

int main(int argc, char **argv)
{
	int err = 0;
//*	
	//testPrintBalise();

	printf("Parsing XML\n");

	//xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	DocXML * doc;
	DocXML * stylesheetXSL;

	//debug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	DtdDocument dtdDocument;
	cout << "argc :" << argc << endl;
	if (argc == 2)
	{
		// On a passe un fichier .xml en parametre
		if ( std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xml" 
			|| std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xsl")
		{
			parseDoc(argv[1], doc, &dtdDocument, err);
		}
		else if ( std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "dtd" )
		{
			std::cout << "On va parser la DTD..." << std::endl;
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
	else if (argc == 3)
	{
		if (std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xml")
		{
			parseDoc(argv[1], doc, &dtdDocument, err);
			if(err == 0 && std::string(argv[2]).substr(strlen(argv[2])-3,strlen(argv[2])-1) == "xsl")
			{
				parseDoc(argv[2], stylesheetXSL, &dtdDocument, err);
				if(err == 0)
				{
					HTMLProc *docHTML = new HTMLProc(doc, stylesheetXSL);
					docHTML->Print();
				}
			}
		}
	}	
	
	return 0;
}

