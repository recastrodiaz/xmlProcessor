/*************************************************************************
                           DtdElement  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <DtdElement> (fichier DtdElement.h) ---------
#if ! defined ( DtdElement_H )
#define DtdElement_H

//------------------------------------------------------------------------
// Rôle du module <DtdElement>
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

class DtdElement : public DtdBalise
{

//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
	public:
		DtdElement();
		DtdElement(std::string aIdent, ElementAttBase * aAttributeReference, 
			std::list <AttList*> aAttList = std::list <AttList*>(),
			std::list <AttDef*> aAttDef = std::list <AttDef*>() );
		~DtdElement();

		void Print();
		std::string GetName();
		std::string GetRe();

	protected:
		// Attribute name of the DtdElement
		ElementAttBase * mAttributeReference;
		// List of attributes of the DtdElement
		std::list <AttList*> mAttList;
		// Vector of attributes definitions of the DtdElement
		std::list <AttDef*> mAttDef;
		// String that identify the DtdElement
		std::string mIdent;
};

#endif // DtdElement_H



