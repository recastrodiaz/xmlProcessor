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

void ElementAttList::Print()
{
	// Selection du séparateur
	char agregat;
	if (mTypeAgregat == ElementAttList::A_PIPE)
	{
		agregat = '|';
	}
	else // COMMA
	{
		agregat = ',';
	}

	// Affichage des éléments.
	std::cout << "(";
	for(std::list <ElementAttBase *>::iterator it = mElementAttBase.begin(); it != mElementAttBase.end(); it++)
	{
		if(it != mElementAttBase.begin())
		//Il ne faut pas ajouter un séparateur à la fin de la chaine
		{ 
			std::cout << agregat;
		}
		(*it)->Print();
	}
	std::cout << ")";

} //----- fin de ElementAttList::Print()
void ElementAttList::push_back(ElementAttBase * elem)
{
	mElementAttBase.push_back(elem);
}
ElementAttList::ElementAttList()
	: ElementAttBase()
// Algorithme :
//
{
}
ElementAttList::ElementAttList(ElementAttList::TypeAgregat typeAgregat, std::list <ElementAttBase*> elementAttBase, ElementAttBase::Cardinality card)
	: ElementAttBase(card), mTypeAgregat( typeAgregat ), mElementAttBase ( elementAttBase )
// Algorithme :
//
{
} //----- fin de ElementAtt::ElementAtt

ElementAttList::~ElementAttList ()
// Algorithme :
//
{

} //----- fin de ElementAtt::~ElementAtt




