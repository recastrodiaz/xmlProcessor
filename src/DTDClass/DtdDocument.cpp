/*************************************************************************
                           DTD_DOCUMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
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

// Constructeur par defaut de DtdDocument
DtdDocument::DtdDocument ()
	: mBalises( NULL )
// Algorithme :
//
{
} //----- fin de DtdDocument

// Destructeur de DtdDocument
DtdDocument::~DtdDocument ()
// Algorithme :
// Libere la memoire allouee dynamiquement
{
	if( mBalises )
	{
		std::list<DtdBalise *>::iterator it = mBalises->begin();
		for( ; it != mBalises->end(); it++ )
		{
			delete * it; 
		}
		delete mBalises;
	}

	// Supprime les regex
	std::map<std::string, regex_t>::iterator iter;
	for (iter = mRe.begin(); iter != mRe.end(); ++iter) {
		regfree(&(iter->second));
	}
} //----- fin de ~DtdDocument

// Methode qui permet de construire la liste des balises DTD de notre
// classe DtdDocument
void DtdDocument::setBalises( std::list<DtdBalise *> * balises )
// Algorithme :
// -Parcourt la std::list de balise DTD passee en parametre a l'aide des
// iterator de la STL
// -Fait un dynamic_cast en AttList* de chaque element de la liste
// -Si ce cast reussi, ajoute l'element dans la map <mElementsByName> puis
// fait la correspondance entre ce nom d'element et la definition de l'a-
// ttribut.
{
	mBalises = balises;
	std::list<DtdBalise *>::iterator it = mBalises->begin();
	for( ; it != mBalises->end(); it++ )
	{
		AttList * attList = dynamic_cast<AttList *>( * it );
		if( attList )
		{
			std::map<std::string, DtdElement *>::iterator element;
			
			// Cherche dans la map <mElementsByName> le nom d'element
			// correspond a celui de <attList> et met a jour ce nom
			// le cas echeant.
			element = mElementsByName.find( attList->mElementName );
			if( element != mElementsByName.end() )
				attList->mElement = element->second;
			
			// Cherche dans la liste des definitions d'attributs une
			// correspondance entre l'element de reference de l'attribut
			// et le nom d'<element>.
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

}//----- fin de setBalises

// Methode d'ajout d'un DtdElement par son nom
void DtdDocument::addElementByName ( std::string elementName, DtdElement * element )
// Algorithme :
// trivial
{
	mElementsByName.insert( std::pair<std::string, DtdElement* >( elementName, element ) );
} //----- fin de addElementByName()

// Affichage du document DTD
void DtdDocument::Print ()
// Algorithme :
// Parcourt toutes les balises pour les afficher
{
	for(std::list <DtdBalise *>::iterator it = mBalises->begin(); it != mBalises->end(); it++)
	{
		(*it)->Print();
		std::cout << std::endl;
	}
} //----- fin de Print()

void DtdDocument::GenerateRE()
{
	// Itere sur tous les elements
	for (std::list<DtdBalise *>::iterator it = mBalises->begin();
			it != mBalises->end(); it++) {
		DtdElement* element = dynamic_cast<DtdElement*>(*it);
		if (element != 0) {
			std::string strRegExp = element->GetRe();
			int reti;
			regex_t regex;

			// Compile l'expression reguliere
			reti = regcomp(&regex, strRegExp.c_str(),
					REG_EXTENDED);
			if (reti) {
				fprintf(stderr, "Could not compile regex\n");
				exit(1);
			}

			// Pour le debug
			cout <<  element->GetName() + " : "+strRegExp << endl;
			mRe[element->GetName()] = regex;
		}
	}
} //----- fin de GenerateRE()

std::map<std::string,regex_t> & DtdDocument::getMRe()
{
	return mRe;
} //----- fin de getMRe()

bool DtdDocument::CheckXmlElementValidity(std::string dtdElementName, std::string xmlString )
{
	int reti;
	char msgbuf[100];
	std::string strRegExp;
	map<string,regex_t>::iterator dtdElementNameIt = mRe.find(dtdElementName);

	if ( dtdElementNameIt == mRe.end())
	{
		//DEBUG
		cout << "Unknown tag" << endl;

		return false;
	}

	// <dtdElementName> a ete trouve
	regex_t regex = dtdElementNameIt->second;

	// Execution de l'expression reguliere
	reti = regexec(&regex, xmlString.c_str(), 0, NULL,0);
	if (!reti) {
		// matching
		//DEBUG
		cout << "matched !" << endl;
		return true;

	} else if (reti == REG_NOMATCH) {
		// pas de matching
		cout << "not matched !" << endl;
		return false;

	} else {
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		fprintf(stderr, "Regex match failed: %s\n", msgbuf);
		exit(1);
	}

} //----- fin de CheckXmlElementValidity()


