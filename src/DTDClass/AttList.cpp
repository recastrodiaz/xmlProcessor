/*************************************************************************
                           ATT_LIST  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <ATT_LIST> (fichier AttList.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "AttList.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom

void AttList::Print()
{
	std::cout << "<!ATTLIST " << mElement->GetName();
	for(std::list <AttDef*>::iterator i=mAttDefs.begin();i!=mAttDefs.end();i++)
	{
       (*i)->Print();
	}
	std::cout << ">";
}

AttList::AttList(std::list<AttDef*> aAttDefs) 
	: DtdBalise(), mElement(NULL), mAttDefs (aAttDefs)
// Algorithme :
//
{
} //----- fin de Element

AttList::~AttList ()
// Algorithme :
//
{
} //----- fin de ~Element



