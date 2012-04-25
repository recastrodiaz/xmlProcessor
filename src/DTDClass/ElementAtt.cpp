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
	std::cout << contentSpec + GetCardinality();

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

std::string ElementAtt::GetRe()
{
	std::string contentSpecWithCardinality = "(" + contentSpec + ")" + GetCardinality();
    return contentSpecWithCardinality;
}




