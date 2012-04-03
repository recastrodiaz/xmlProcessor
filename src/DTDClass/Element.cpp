/*************************************************************************
                           ELEMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <ELEMENT> (fichier Element.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Element.h"

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

void Element::Print()
{
}

Element::Element () : DtdBalise(), mAttList (), mAttDef ()
// Algorithme :
//
{
	mAttributeReference = 0;
} //----- fin de Element

Element::Element (std::string aIdent, ElementAttBase * aAttributeReference, std::vector <AttList*> aAttListVector, std::vector <AttDef*> aAttDefVector) 
	: DtdBalise(aIdent), mAttList (aAttListVector), mAttDef (aAttDefVector)
// Algorithme :
//
{
	mAttributeReference = aAttributeReference;
} //----- fin de Element

Element::~Element ()
// Algorithme :
//
{
} //----- fin de ~Element



