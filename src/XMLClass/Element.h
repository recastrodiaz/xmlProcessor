/*************************************************************************
                           ELEMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par atamborrino, nrabardeau, lardon
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
#include "../DTDClass/DtdDocument.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Element { //abstract
	public:
		Element();
		virtual ~Element();
		virtual void Print() = 0; 
		// Mode d'emploi : Affichera le contenu du noeud *this*

		virtual std::string GetNom() = 0;
		// Mode d'emploi : Renvoie le nom du noeud xml *this*
		// NB : le nom d'un noeud de type Data est "#PCDATA"

		virtual bool verifyValidity(DtdDocument & docDtd)=0;
		// Mode d'emploi : Verifiera la validite du noeud xml 
		// par rapport a la dtd
};

#endif // ELEMENT_H



