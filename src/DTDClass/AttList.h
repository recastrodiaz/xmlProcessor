/*************************************************************************
                           ATT_LIST_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <AttList> -------------------------------
#if ! defined ( ATT_LIST_H )
#define ATT_LIST_H

//------------------------------------------------------------------------
// Rôle du module <ATT_LIST>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>

#include "AttDef.h"
#include "DtdBalise.h"
#include "DtdElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class DtdDocument;
class AttDef;
class DtdElement;

class AttList : public DtdBalise
{
	public:
		AttList(std::string elementName, std::list<AttDef*> * aAttDefs = new std::list<AttDef*>() );
		~AttList();
		
		void Print();
		const std::list<AttDef*> * getAttDefs() const;

	private:
		DtdElement* mElement;
		std::string mElementName;
		std::list<AttDef*> * mAttDefs;
		
		friend class DtdDocument;

};

#endif // ATT_LIST_H



