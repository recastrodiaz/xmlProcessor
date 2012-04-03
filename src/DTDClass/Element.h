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
#include <vector>

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
			std::vector <AttList*> aAttListVector = std::vector <AttList*>(),
			std::vector <AttDef*> aAttDefVector = std::vector <AttDef*>() );
		~Element();

		void Print();

	protected:
		// Attribute name of the element
		ElementAttBase* mAttributeReference;
		// List of attributes of the element
		std::vector <AttList*> mAttList;
		// Vector of attributes definitions of the element
		std::vector <AttDef*> mAttDef;
};

#endif // ELEMENT_H



