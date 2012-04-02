/*************************************************************************
                           DTD_BALISE_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <DtdBalise> -----------------------------
#if ! defined ( DTD_BALISE_H )
#define DTD_BALISE_H

//------------------------------------------------------------------------
// Rôle du module <DTD_BALISE>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class DtdBalise
{
	public:
		virtual DtdBalise() = 0;
		virtual ~DtdBalise() = 0;

	private:
		std::string mIdent;

};

#endif // DTD_BALISE_H



