/*************************************************************************
                           ElementAttList
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <ElementAttList> (fichier ElementAttList.h) ---------
#if ! defined ( ELEMENT_ATT_LIST_H )
#define ELEMENT_ATT_LIST_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENTATTLIST>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <iostream>

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

class ElementAttList : public ElementAttBase 
{
	public:

		enum TypeAgregat { PIPE, COMMA };

		ElementAttList();
		ElementAttList(ElementAttList::TypeAgregat aTypeAgregat, std::list <ElementAttBase*> aElementAttBase = std::list <ElementAttBase*>(), ElementAttBase::Cardinality card = ElementAttBase::NONE );
		virtual ~ElementAttList();
		
		void Print();
		void push_back(ElementAttBase * elem);
	private:
		ElementAttList::TypeAgregat mTypeAgregat;
		std::list <ElementAttBase*> mElementAttBase;
};

#endif // ELEMENT_ATT_LIST_H



