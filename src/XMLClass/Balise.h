/*************************************************************************
                           BALISE  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par atamborrino, nrabardeau, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Balise> (fichier Balise.h) ---------
#if ! defined ( BALISE_H )
#define BALISE_H

//------------------------------------------------------------------------
// Rôle du module <BALISE>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdlib>
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Balise : public Element { //abstract
	public:
		Balise(unNom);
		virtual ~Balise();
		void getValue();

	private:
		map<string, string> attributs;
		vector<Element*> elements;
 		string nom;
};

#endif // ELEMENT_H



