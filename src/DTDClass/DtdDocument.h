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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------td::list<DtdBalise* Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


class DtdDocument
{
	public:

		struct ElementLinkToAttList
		{
			std::string elementName;
			AttList * attList;
		};

		struct ElementLinkToAttDef
		{
			std::string elementName;
			AttDef * attDef;
		};

		DtdDocument( std::list<DtdBalise *> * );
		~DtdDocument();
		void addElementLinkToAttList( std::string elementName, AttList * attList );
		void addElementLinkToAttDef ( std::string elementName, AttDef * attDef);
		void Print();
		void GenerateRE();

	private:
		std::list<DtdBalise *> * mBalises;
		
		// a map matching the names of dtd elements with their RE
		std::map<std::string,std::string> re;

		std::list<ElementLinkToAttList> mElementToLinkToAttList;
		std::list<ElementLinkToAttDef>  mElementLinkToAttDef;
};

#endif // DTD_DOCUMENT_H



