 /*************************************************************************
                           DATA  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par atamborrino, nrabardeau, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Balise> (fichier Balise.h) ---------
#if ! defined ( DATA_H )
#define DATA_H

//------------------------------------------------------------------------
// Rôle du module <DATA>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <cstdlib>
#include "Data.h"
#include "Element.h"
#include "../commun.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Data : public Element {
	public:
		Data(string uneValue);
		virtual ~Data();
		void Print(); 
		// Mode d'emploi : Affiche le #PCDATA

		string GetValue();
		// Mode d'emploi : Renvoie le #PCDATA

		std::string GetNom();
		// Mode d'emploi : Renvoie "#PCDATA"

		bool verifyValidity(DtdDocument & docDtd);
		// Mode d'emploi : Verifie la validite d'un 
		// noeud xml par rapport a la dtd du document

	private:
		string value;
		// #PCDATA
};

#endif // ELEMENT_H



