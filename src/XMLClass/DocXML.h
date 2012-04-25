/*************************************************************************
                           DOCXML  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par atamborrino, nrabardeau, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <DocXML> (fichier DocXML.h) ---------
#if ! defined ( DOCXML_H )
#define DOCXML_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENT>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Element.h"
#include "Balise.h"
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

class DocXML {
	public:
		DocXML();
		DocXML(Balise* unRoot, string unKeyword, string uneUrl);
		virtual ~DocXML();

		Balise *GetRoot();
		// Mode d'emploi : Renvoie un pointeur sur la balise
		// racine du document

		void SetRoot(Balise* uneBalise);

        	void Print();
		// Mode d'emploi : Affiche le document

		bool verifyValidity(DtdDocument & docDtd);
		// Mode d'emploi : Verifie la validite d'un document
		// xml par rapport a sa dtd

		string GetDtdUrl();
    
    private:
        Balise* root;
	// Balise racine du document xml

        string keyword;
        string dtdUrl;
	// Url de la dtd utilisee
};

#endif // DOCXML_H

