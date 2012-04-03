/*************************************************************************
                           ELEMENT_ATT_BASE  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <ElementAttBase> (fichier ElementAttBase.h) ---------
#if ! defined ( ELEMENT_ATT_BASE_H )
#define ELEMENT_ATT_BASE_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENT_ATT_BASE>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <cstdlib>

#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
class Element;

class ElementAttBase
{

//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
	public:
		ElementAttBase();
		virtual ~ElementAttBase();
		// Should be redefined in subclasses
		virtual void Print() = 0;

		enum Cardinality { AST, PLUS, QMARK };
		enum ContentSpec { EMPTY, ANY };

	protected:
		// Element the attribute refers to
		Element * owner;
};

#endif // ELEMENT_ATT_BASE_H



