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
}

AttList::AttList () : DtdBalise(), mAttDefs ()
// Algorithme :
//
{
	mElement = NULL;
} //----- fin de Element

AttList::AttList (std::string aIdent, Element* aElement) : DtdBalise(aIdent), mAttDefs ()
// Algorithme :
//
{
	mElement = aElement;
} //----- fin de Element

AttList::~AttList ()
// Algorithme :
//
{
} //----- fin de ~Element



