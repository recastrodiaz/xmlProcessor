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
		void Print(); //pour récupérer le CDATA
		string GetValue();

		// Return #PCDATA
		std::string GetNom();

		bool verifyValidity(DtdDocument & docDtd);

	private:
		string value;
};

#endif // ELEMENT_H



