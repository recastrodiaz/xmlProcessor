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
#include "../DTDClass/DtdDocument.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
//
// Contrat :
//

class Balise : public Element {
	public:
		Balise(string unNom, string unNs = "");
        // Mode d'emploi :
        //
        // Contrat :
        //
		
        virtual ~Balise();
        // Mode d'emploi :
        //
        // Contrat :
        //
    
	void Print();
        // Mode d'emploi :
        //
        // Contrat :
        //
    
        void addAttribut(string label, string value);
        // Mode d'emploi :
        //
        // Contrat :
        //
    
        void addListAttributs(mapSS *uneListeAttributs);
        // Mode d'emploi :
        //
        // Contrat :
        //
    
        void addContent(vecE* elem);
        // Mode d'emploi :
        //
        // Contrat :
        //
	
	void addElement(Element* elem);
        // Mode d'emploi :
        //
        // Contrat :
        //    

        void setEmpty(bool unEmpty);
        // Mode d'emploi :
        //
        // Contrat :
        //

	string GetNom();
        // Mode d'emploi :
        //
        // Contrat :
        //

	void SetNom(string unNom);
        // Mode d'emploi :
        //
        // Contrat :
        //

	mapSS GetAttributs();
        // Mode d'emploi :
        //
        // Contrat :
        //

	string GetNs();
        // Mode d'emploi :
        //
        // Contrat :
        //

	void SetNs(string unNs);
        // Mode d'emploi :
        //
        // Contrat :
        //

        bool verifyValidity(DtdDocument & docDtd);

        std::string getName();

	private:
		mapSS attributs;
		vecE elements;
 		string nom;
        	string ns;
        	bool empty;
};

#endif // BALISE_H



