/*************************************************************************
                           DTD_DOCUMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DTD_DOCUMENT> (fichier DtdDocument.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

#include <regex.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
//------------------------------------------------------ Include personnel
#include "DtdDocument.h"
#include "DtdElement.h"

using namespace std;

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom

DtdDocument::DtdDocument ()
	: mBalises( NULL )
// Algorithme :
//
{
} //----- fin de ~Element

DtdDocument::~DtdDocument ()
// Algorithme :
//
{
	// TODO delete mBalises
} //----- fin de ~Element

void DtdDocument::setBalises( std::list<DtdBalise *> * balises )
{
	mBalises = balises;
	std::list<DtdBalise *>::iterator it = mBalises->begin();
	for( ; it != mBalises->end(); it++ )
	{
		AttList * attList = dynamic_cast<AttList *>( * it );
		if( attList )
		{
			std::map<std::string, DtdElement *>::iterator element;
			
			element = mElementsByName.find( attList->mElementName );
			if( element != mElementsByName.end() )
				attList->mElement = element->second;
			
			const std::list<AttDef *> * attDefs = attList->getAttDefs();
			std::list<AttDef *>::const_iterator it2 = attDefs->begin();
			for( ; it2 != attDefs->end(); it2++ )
			{
				element = mElementsByName.find( (*it2)->mElementName );
				if( element != mElementsByName.end() )
					(*it2)->mElement = element->second;
			}
		}
	}

}

void DtdDocument::addElementByName ( std::string elementName, DtdElement * element )
// Algorithme :
{
	mElementsByName.insert( std::pair<std::string, DtdElement* >( elementName, element ) ); // TODO fix this
} //----- fin de addElementByName()

void DtdDocument::Print ()
// Algorithme :
{
	for(std::list <DtdBalise *>::iterator it = mBalises->begin(); it != mBalises->end(); it++)
	{
		(*it)->Print();
		std::cout << std::endl;
	}
} //----- fin de Print()

void DtdDocument::GenerateRE()
{
	// Iterating over all the elements
	for (std::list<DtdBalise *>::iterator it = mBalises->begin(); it != mBalises->end(); it++)
	{
	   DtdElement* element = dynamic_cast<DtdElement*>(*it);
       if(element != 0) 
       {
          mRe[element->GetName()] = element->GetRe();
       }
	}
}

std::map<std::string,std::string> & DtdDocument::getMRe()
{
	return mRe;
}

bool DtdDocument::CheckXmlElementValidity (std::string dtdElementName, std::string xmlString )
{
	regex_t regex;
	int reti;
	char msgbuf[100];
	std::string strRegExp;
	map<string,string>::iterator dtdElementNameIt = mRe.find(dtdElementName);

	if ( dtdElementNameIt == mRe.end())
	{
		return false;
	}

	// We have found the dtdElementName

	// Compile regular expression
	reti = regcomp(&regex,(dtdElementNameIt->second).c_str(), REG_EXTENDED);
	if (reti) {
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	//DEBUG
	cout << dtdElementNameIt->second + " : " + xmlString << endl;

	// Execute regular expression
	reti = regexec(&regex, xmlString.c_str(), 0, NULL,0);
	if (!reti) {
		// match
		//DEBUG
		cout << "matched !" << endl;

		regfree(&regex);
		return true;
	} else if (reti == REG_NOMATCH) {
		cout << "not matched !" << endl;
		// No match

		//DEBUG
		regfree(&regex);

		return false;
	} else {
		regfree(&regex);
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		fprintf(stderr, "Regex match failed: %s\n", msgbuf);
		exit(1);
	}

}


