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
#include "Element.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class AttDef;

class AttList : public DtdBalise
{
	public:
		AttList(std::list<AttDef*> aAttDefs = std::list<AttDef*>() );
		~AttList();
		
		void Print();

	private:
		Element* mElement;
		std::list<AttDef*> mAttDefs;

};

#endif // ATT_LIST_H



