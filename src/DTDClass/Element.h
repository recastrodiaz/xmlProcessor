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
#include <list>
#include <iostream>

#include "ElementAttBase.h"
#include "DtdBalise.h"
#include "AttList.h"
#include "AttDef.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
class AttDef;
class AttList;
class ElementAttBase;

class Element : public DtdBalise
{

//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
	public:
		Element();
		Element(std::string aIdent, ElementAttBase * aAttributeReference, 
			std::list <AttList*> aAttList = std::list <AttList*>(),
			std::list <AttDef*> aAttDef = std::list <AttDef*>() );
		~Element();

		void Print();
		std::string GetName();

	protected:
		// Attribute name of the element
		ElementAttBase * mAttributeReference;
		// List of attributes of the element
		std::list <AttList*> mAttList;
		// Vector of attributes definitions of the element
		std::list <AttDef*> mAttDef;
		// String that identify the Element
		std::string mIdent;
};

#endif // ELEMENT_H



