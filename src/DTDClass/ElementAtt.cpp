/*************************************************************************
                           ElementAtt
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par recastrodiaz, fduranton, dbrian
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <ElementAtt> (fichier ElementAtt.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "ElementAtt.h"

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

void ElementAtt::Print()
{
	std::cout << contentSpec ;

    char card = '\0';
    switch(mCardinality)
    {
    	case ElementAttBase::C_NONE:
			break;
    	case ElementAttBase::C_AST:
    		card = '*';
    		break;
    	case ElementAttBase::C_PLUS:
    	    card = '+';
    		break;
    	case ElementAttBase::C_QMARK:
    	    card = '?';
    		break;
    }
	if (mCardinality != ElementAttBase::C_NONE)
	{
		std::cout << card;
	}


} //----- fin de ElementAtt::Print()
ElementAtt::ElementAtt (std::string content, ElementAttBase::Cardinality card )
	: ElementAttBase(card), contentSpec( content )
// Algorithme :
//
{
} //----- fin de ElementAtt::ElementAtt

ElementAtt::~ElementAtt ()
// Algorithme :
//
{

} //----- fin de ElementAtt::~ElementAtt




