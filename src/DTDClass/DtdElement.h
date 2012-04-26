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
// Classe qui represente un element d'une DTD. C'est a dire le composant
// contenu entre les balises <!ELEMENT>
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

		// Retourne l'instance de l'expression reguliere (recursivement)
		std::string GetRe();

	protected:
		// Nom de l'attribut de l'element DTD
		ElementAttBase * mAttributeReference;
		// Liste des attributs de l'element DTD
		std::list <AttList*> mAttList;
		// Liste des definitions d'attributs de l'element DTD
		std::list <AttDef*> mAttDef;
		// String d'identification d'un element DTD
		std::string mIdent;
};

#endif // DtdElement_H



