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
#include <vector>
#include <string>

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
		DtdDocument(std::string aName);
		~DtdDocument();

	private:
		std::string mName;
		std::vector<DtdBalise *> mBalises;
};

#endif // DTD_DOCUMENT_H



