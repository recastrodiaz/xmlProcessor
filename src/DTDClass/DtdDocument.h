/*************************************************************************
                           DTD_DOCUMENT_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
*************************************************************************/

//---------- Interface du module <DtdDocument> ---------------------------
#if ! defined ( DTD_DOCUMENT_H )
#define DTD_DOCUMENT_H

//------------------------------------------------------------------------
// Rôle du module <DTD_DOCUMENT>
// Classe qui represente notre DTD au niveau le plus haut. Elle est compose
// de balises.
//
//------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <string>
#include <map>
#include <regex.h>
#include <sys/types.h>

#include "DtdBalise.h"
#include "AttList.h"
#include "AttDef.h"
#include "DtdElement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


class DtdDocument
{
	public:

		DtdDocument();
		~DtdDocument();
		void setBalises( std::list<DtdBalise *> * balises );
		void addElementByName( std::string elementName, DtdElement * element );
		void Print();

		// Genere mRe (une std::map qui fait correspondre les noms des elements
		// de la DTD avec leurs expressions regulieres.
		void GenerateRE();

		std::map<std::string,regex_t> & getMRe();

		// Verifier si <xmlString> correspond a l'expression reguliere associee a
		// l'element DTD dont le nom est <dtdElementName>
		bool CheckXmlElementValidity(std::string dtdElementName, std::string xmlString );

	private:
	
		// La liste des balises du document
		std::list<DtdBalise *> * mBalises;
		
		// Une map qui fait la correspondance entre les noms des elements DTD et leur REGEX
		std::map<std::string,regex_t> mRe;

		// Contient tous les elements DTD qu'on peut chercher par leur nom
		std::map<std::string, DtdElement *>  mElementsByName;
};

#endif // DTD_DOCUMENT_H
