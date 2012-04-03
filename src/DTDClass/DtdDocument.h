/*************************************************************************
                           DTD_DOCUMENT_H  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <DtdDocument> ---------------------------
#if ! defined ( DTD_DOCUMENT_H )
#define DTD_DOCUMENT_H

//------------------------------------------------------------------------
// Rôle du module <DTD_DOCUMENT>
//
//
//------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <list>

#include "DtdBalise.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class DtdDocument
{
	public:
		DtdDocument();
		~DtdDocument();

	private:
		std::list<DtdBalise *> mBalises;

};

#endif // DTD_DOCUMENT_H



