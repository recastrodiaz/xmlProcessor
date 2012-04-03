/*************************************************************************
                           ElementAtt
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
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
#include <cstdlib>
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

class ElementAtt : public ElementAttBase {
	public:
		ElementAtt(std::string aIdent);
		virtual ~ElementAtt();
		
		void Print();


	private:
		std::string mIdent;
};

#endif // ELEMENTATT_H



