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
		virtual void Print() = 0; //pour récupérer le CDATA

		// Return the name of the node.
		// NB : the name of a data node is #PCDATA
		virtual std::string GetNom() = 0;

		virtual bool verifyValidity(DtdDocument & docDtd)=0;
};

#endif // ELEMENT_H



