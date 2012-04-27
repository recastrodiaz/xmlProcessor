

#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>

#include "commun.h"
#include "XMLClass/DocXML.h"
#include "XMLClass/Balise.h"

#include "DTDClass/DtdDocument.h"
#include "ProcesseurHTML/HTMLProc.h"

using namespace std;

extern int xmldebug;
extern int dtddebug;
int xmlparse(DocXML ** doc);
int dtdparse(DtdDocument * dtdDocument);
void initialise(void);

extern FILE * xmlin;
extern FILE * dtdin;

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

	if (err != 0)
	{
		std::cout << "Parse ended with " << err << " error(s)" << std::endl;
	}
	else  
	{
		std::cout << "Parse ended with success" << std::endl;
        std::cout << "===============================================" << std::endl;
		doc->Print();
        std::cout << "===============================================" << std::endl;
		if(!xsl){
			
			index = string(docToParse).find_last_of("/");
			filePath.assign(docToParse,index+1);
			std::cout << "filepath : " << filePath << std::endl;
			
			dtdURL = filePath + doc->GetDtdUrl();

			std::cout << "dtdurl : " << dtdURL << std::endl;
			
			dtdin = fopen(dtdURL.c_str(),"r+");
			
			if (dtdin != NULL)
			{
				err = dtdparse( dtdDocument );
				if (err != 0) 
				{
					std::cout << "Parse ended with " << err << "error(s)" << std::endl;
				}
				else
				{
					std::cout << "Parse ended with success" << std::endl;
                    std::cout << "=================== DTD ========================" << std::endl;
					dtdDocument->Print();
                    std::cout << "=================== DTD ========================" << std::endl;
					dtdDocument->GenerateRE();
					if (doc->verifyValidity(*dtdDocument))
					{
						std::cout << "THE XML DOC IS VALID !" << std::endl;
					}
					else
					{
						std::cout << "THE XML DOC IS *NOT* VALID" << std::endl;
						err = -1;
					}
				}
			}
			else 
			{
				std::cout << "dtd invalide" << std::endl;
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

	std::cout << "Parsing XML" << std::endl;

	//xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	DocXML * doc;
	DocXML * stylesheetXSL;

	//debug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	DtdDocument dtdDocument;

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
					std::cout << "Parse ended with " << err << "error(s)" << std::endl;
				}
				else
				{
					std::cout << "Parse ended with success" << std::endl;
					dtdDocument.Print();
				}
			}
			else
			{
				std::cout << "dtd invalide" << std::endl;
				return -1;
			}
			fclose(dtdin);
		}
	}
	else if (argc == 3)
	{
		// Sert a capter les return -1 de parseDoc();
		int resultatParsing;

		if (std::string(argv[1]).substr(strlen(argv[1])-3,strlen(argv[1])-1) == "xml")
		{
			// On recupere le retour de parseDoc()
			resultatParsing = parseDoc(argv[1], doc, &dtdDocument, err);
			if(err == 0 && std::string(argv[2]).substr(strlen(argv[2])-3,strlen(argv[2])-1) == "xsl")
			{
				// On recupere le retour de parseDoc()
				resultatParsing = parseDoc(argv[2], stylesheetXSL, &dtdDocument, err);
				if(err == 0 && resultatParsing != -1)
				{
					HTMLProc *docHTML = new HTMLProc(doc, stylesheetXSL);
                    std::cout << "=================== HTML ========================" << std::endl;
					docHTML->Print();
                    std::cout << "=================== HTML ========================" << std::endl;
				}
			}
		}
	}
	return 0;
}

