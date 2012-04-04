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
		DocXML(Element unDoc, string unKeyword, string uneUrl);
		virtual ~DocXML();
    
    private:
        Element doc;
        string keyword;
        string dtdUrl;
};

#endif // DOCXML_H

