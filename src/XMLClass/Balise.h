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
#include <map>
#include <vector>
#include <cstdlib>

#include "../commun.h"
#include "Element.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Balise : public Element {
	public:
		Balise(string unNom);
		virtual ~Balise();
		void Print();
        void addAttribut(string label, string value);
	void addListAttributs(mapSS *uneListeAttributs);
        void addContent(vecE* elem);

	private:
		mapSS attributs;
		vecE elements;
 		string nom;
};

#endif // BALISE_H



