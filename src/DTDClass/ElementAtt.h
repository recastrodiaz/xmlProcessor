/*************************************************************************
                           ElementAtt
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par rcastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <ElementAtt> (fichier ElementAtt.h) ---------
#if ! defined ( ELEMENTATT_H )
#define ELEMENTATT_H

//------------------------------------------------------------------------
// Rôle du module <ELEMENTATT>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <stdlib>
#include "ElementAttBase.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class ElementAtt : public ElementAttBase { //abstract
	public:
		ElementAtt();
		virtual ~ElementAtt();


	private:
		string ident;
};

#endif // ELEMENTATT_H



