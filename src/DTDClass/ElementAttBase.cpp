/*************************************************************************
                           DtdElement_ATT_BASE  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DtdElement_ATT_BASE> (fichier ElementAttBase.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "ElementAttBase.h"

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

// Constructeur par defaut de ElementAttBase
ElementAttBase::ElementAttBase () : mCardinality(ElementAttBase::C_NONE)
// Algorithme :
//
{
} //----- fin de ElementAttBase

// Constructeur avec parametre de ElementAttBase
ElementAttBase::ElementAttBase (ElementAttBase::Cardinality cardinality) : mCardinality(cardinality)
// Algorithme :
//
{
} //----- fin de ElementAttBase

// Destructeur de ElementAttBase
ElementAttBase::~ElementAttBase ()
// Algorithme :
//
{
	mOwner = NULL;
} //----- fin de ~ElementAttBase

// Methode de modification de la cardinalite
void ElementAttBase::setCardinality( ElementAttBase::Cardinality cardinality )
{
	mCardinality = cardinality;
} //----- fin de setCardinality

// Methode qui retourne la cardinalite
std::string ElementAttBase::GetCardinality()
{
	std::string card = "";
	switch (mCardinality) {
		case ElementAttBase::C_AST:
			card += "*";
			break;
		case ElementAttBase::C_PLUS:
			card += "+";
			break;
		case ElementAttBase::C_QMARK:
			card += "?";
			break;
		}
	return card;
} //----- fin de GetCardinality
