/*************************************************************************
                           DTD_DOCUMENT_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <DtdDocument> ---------------------------
#if ! defined ( DTD_DOCUMENT_H )
#define DTD_DOCUMENT_H

//------------------------------------------------------------------------
// Rôle du module <DTD_DOCUMENT>
//
//
//------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <string>
#include <map>

#include "DtdBalise.h"
#include "AttList.h"
#include "AttDef.h"
#include "DtdElement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------td::list<DtdBalise* Types

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
		void GenerateRE();
		std::map<std::string,std::string> & getMRe();

		bool CheckXmlElementValidity (std::string dtdElementName, std::string xmlString );

	private:
	
		std::list<DtdBalise *> * mBalises;
		
		// a map matching the names of dtd elements with their RE
		std::map<std::string,std::string> mRe;

		// Contains all DtdElements, searchable by name
		std::map<std::string, DtdElement *>  mElementsByName;
};

#endif // DTD_DOCUMENT_H



