/*************************************************************************
                           ELEMENT  -  description
                             -------------------
    début                : 23/04/2012
    copyright            : (C) 2012 par dbrian, nrabardeau, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <HTMLProc> (fichier HTMLProc.h) ---------
#if ! defined ( HTMLPROC_H )
#define HTMLPROC_H

//------------------------------------------------------------------------
// Rôle du module <HTMLProc>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "../XMLClass/DocXML.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class HTMLProc { //abstract
	public:
		HTMLProc(DocXML *unDocXML, DocXML *unDocXSL);
		virtual ~HTMLProc();
		void Print();
	private:
		void findXSLMatch();
		void parcoursFilsXML(Balise * uneBaliseXML);
		DocXML *docHTML;
		Balise *rootXML;
		Balise *rootXSL;

		Balise *htmlCourant;
};

#endif // HTMLPROC_H



 
