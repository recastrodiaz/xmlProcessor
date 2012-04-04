/*************************************************************************
                           ElementAttList
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <ElementAttList> (fichier ElementAttList.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "ElementAttList.h"

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

void ElementAttList::print()
{
}

ElementAttList::ElementAttList()
	: ElementAttBase()
// Algorithme :
//
{
}
ElementAttList::ElementAttList(ElementAttList::TypeAgregat typeAgregat, std::vector <ElementAttBase*> elementAttBase)
	: ElementAttBase(), mTypeAgregat( typeAgregat ), mElementAttBase ( elementAttBase )
// Algorithme :
//
{
} //----- fin de ElementAtt::ElementAtt

ElementAttList::~ElementAttList ()
// Algorithme :
//
{

} //----- fin de ElementAtt::~ElementAtt




