/*************************************************************************
                           ElementAtt
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <ElementAtt> (fichier ElementAtt.h) ---------
#if ! defined ( ELEMENTATT_H )
#define ELEMENTATT_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENTATT>
// Classe qui modelise un attribut unique d'un element. Cela signifie que
// la balise <!ELEMENT> a laquelle est ratachee <!ATTLIST> n'a que cette 
// derniere rattachee a elle.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
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

class ElementAtt : public ElementAttBase 
{
	public:
		ElementAtt( std::string ident, ElementAttBase::Cardinality card = ElementAttBase::C_NONE);

		virtual ~ElementAtt();
		
		void Print();

		// Retourne l'instance de l'expression reguliere (recursivement)
		std::string GetRe();


	private:
		std::string contentSpec;
};

#endif // ELEMENTATT_H



