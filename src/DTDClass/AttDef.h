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
#include <string>
#include <list>

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

class AttDef : public DtdBalise
{
	public:
		AttDef();
		~AttDef();
		
		enum AttType { TODO };
		enum DefaultDec { IMPLIED, REQUIRED };

	private:
		Element * mElement;
		AttType mAttType;
		DefaultDec mDefaultDec;

};

#endif // ATT_LIST_H



