/*************************************************************************
                           ElementAttList
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <ElementAttList> (fichier ElementAttList.h) ---------
#if ! defined ( ELEMENTATTLIST_H )
#define ELEMENTATTLIST_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENTATTLIST>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdlib>
#include "ElementAttBase.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class ElementAttList : public ElementAttBase { //abstract
	public:
	    ElementAttList();
		ElementAttList(ElementAttList::TypeAgregat unAgregat);
		virtual ~ElementAttList();
        enum TypeAgregat { PIPE, COMMA };

	private:
		ElementAttList::TypeAgregat typeAgregat;
};

#endif // ELEMENTATT_H



