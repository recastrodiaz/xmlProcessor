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
// Classe representant une liste de balises <!ATTLIST> reliees a une balise
// <!ELEMENT>.
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

		enum TypeAgregat { A_PIPE, A_COMMA, A_NONE };

		ElementAttList();
		ElementAttList(ElementAttList::TypeAgregat aTypeAgregat = ElementAttList::A_NONE, std::list <ElementAttBase*> aElementAttBase = std::list <ElementAttBase*>(), ElementAttBase::Cardinality card = ElementAttBase::C_NONE );
		virtual ~ElementAttList();
		
		void Print();
		void push_back(ElementAttBase * elem);

		// Retourne l'expression reguliere (recursivement)
		std::string GetRe();

	private:
		ElementAttList::TypeAgregat mTypeAgregat;
		std::list <ElementAttBase*> mElementAttBase;
};

#endif // ELEMENT_ATT_LIST_H



