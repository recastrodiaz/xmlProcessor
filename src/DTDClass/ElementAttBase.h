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
// Classe abstraite qui represente un element d'une DTD. Cette classe permet
// le polymorphisme et de ce fait, de traiter a la fois les elements qui ont
// plusieurs attributs et ceux qui n'en n'ont qu'un seul.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "DtdElement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
class DtdElement;

class ElementAttBase
{

//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
	public:

	    enum Cardinality { C_NONE, C_AST, C_PLUS, C_QMARK };


	    ElementAttBase();
		ElementAttBase( ElementAttBase::Cardinality cardinality );
		virtual ~ElementAttBase();

		// Devrait être redéfinie dans les sous-classes
		virtual void Print() = 0;

		// Retourne l'expression reguliere (recursivement)
		virtual std::string GetRe() = 0;

		std::string GetCardinality();

		void setCardinality( ElementAttBase::Cardinality cardinality );


	protected:
		DtdElement * mOwner;
		ElementAttBase::Cardinality mCardinality;
};

#endif // ELEMENT_ATT_BASE_H



