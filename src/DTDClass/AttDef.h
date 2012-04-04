/*************************************************************************
                           ATT_DEF_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <AttDef>  -------------------------------
#if ! defined ( ATT_DEF_H )
#define ATT_DEF_H

//------------------------------------------------------------------------
// Rôle du module <ATT_DEF>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include "Element.h"
#include "AttList.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Element;
class AttList;

class AttDef : public DtdBalise
{
	public:
		AttDef();
		AttDef( Element* aElement, std::string aAttType, std::string aDefaultDec );
		~AttDef();
		
		void Print();
		//enum AttType { TODO };
		//enum DefaultDec { IMPLIED, REQUIRED };

	private:
		Element * mElement;
		std::string mAttType;
		std::string mDefaultDec;
};

#endif // ATT_LIST_H



