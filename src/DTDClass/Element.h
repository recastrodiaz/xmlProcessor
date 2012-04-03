/*************************************************************************
                           ELEMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Element> (fichier Element.h) ---------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENT>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <cstdlib>

#include "ElementAttBase.h"
#include "DtdBalise.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC

class Element : public DtdBalise
{

//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
	public:
		Element( std::string ident, ElementAttBase * attributeReference );
		~Element();

	protected:
		// Name of the element
		std::string mIdent;
		// Attribute name of the element
		ElementAttBase * mAttributeReference;
};

#endif // ELEMENT_H



