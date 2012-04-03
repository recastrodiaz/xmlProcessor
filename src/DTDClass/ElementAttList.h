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
#include <vector>
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
		ElementAttList(ElementAttList::TypeAgregat aTypeAgregat, std::vector <ElementAttBase*> aElementAttBase = std::vector <ElementAttBase*>() );
		virtual ~ElementAttList();
		
		void Print();
        

	private:
		ElementAttList::TypeAgregat mTypeAgregat;
		std::vector <ElementAttBase*> mElementAttBase;
};

#endif // ELEMENT_ATT_LIST_H



