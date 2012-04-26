/*************************************************************************
                           ATT_DEF_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
*************************************************************************/

//---------- Interface du module <AttDef>  -------------------------------
#if ! defined ( ATT_DEF_H )
#define ATT_DEF_H

//------------------------------------------------------------------------
// Rôle du module <ATT_DEF>
// La classe AttDef modelise la definition d'un attribut, ie la balise 
// <!ATTLIST>. Notamment, il enregistre l'element auquel fait reference
// cet attribut et le type de cet attribut.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include "DtdElement.h"
#include "AttList.h"

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
class DtdElement;
class AttList;

class AttDef
{
	public:
		AttDef();
		AttDef( std::string elementName, std::string aAttType, std::string aDefaultDec );
		~AttDef();
		
		
		void Print();
		// Mode d'emploi: 
		// Affiche sur la sortie standard la définition de l'attribut: mElementName,
		// mAttType, mDefaultDec

	private:
		DtdElement * mElement; // Element de référence
		std::string mElementName; // Nom de l'Element
		std::string mAttType; // Type de l'attribut
		std::string mDefaultDec; 
		
		friend class DtdDocument;
};

#endif // ATT_LIST_H



