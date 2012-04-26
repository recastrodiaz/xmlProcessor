/*************************************************************************
                           ATT_LIST_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
*************************************************************************/

//---------- Interface du module <AttList> -------------------------------
#if ! defined ( ATT_LIST_H )
#define ATT_LIST_H

//------------------------------------------------------------------------
// Rôle du module <ATT_LIST>
// La classe AttList represente une liste d'attribut associee a un element.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>

#include "AttDef.h"
#include "DtdBalise.h"
#include "DtdElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class DtdDocument;
class AttDef;
class DtdElement;

class AttList : public DtdBalise
{
	public:
	
		AttList(std::string elementName, std::list<AttDef*> * aAttDefs = new std::list<AttDef*>() );
		~AttList();
		
		// Affiche l'Attlist sur la sortie standard.
		void Print();
		
		//Renvoi la liste de tous les AttDefs liés à l'Attlist.
		const std::list<AttDef*> * getAttDefs() const;

	private:
		DtdElement* mElement; // Element rattaché à l'Attlist
		std::string mElementName; // String contenant le nom de l'élément rattaché à l'Attlist.
		std::list<AttDef*> * mAttDefs; // Liste de définition d'attribut
		
		friend class DtdDocument;

};

#endif // ATT_LIST_H



