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

// Constructeur par defaut de ElementAttList
ElementAttList::ElementAttList()
	: ElementAttBase()
// Algorithme :
//
{
} //----- fin de ElementAtt::ElementAtt

// Constructeur avec arguments de ElementAttList
ElementAttList::ElementAttList(ElementAttList::TypeAgregat typeAgregat, std::list <ElementAttBase*> elementAttBase, ElementAttBase::Cardinality card)
	: ElementAttBase(card), mTypeAgregat( typeAgregat ), mElementAttBase ( elementAttBase )
// Algorithme :
//
{
} //----- fin de ElementAtt::ElementAtt

// Destructeur de ElementAttList
ElementAttList::~ElementAttList ()
// Algorithme :
//
{
	for(std::list <ElementAttBase *>::iterator it = mElementAttBase.begin(); it != mElementAttBase.end(); it++)
    {
      delete * it;
    }
} //----- fin de ElementAtt::~ElementAtt


std::string ElementAttList::GetRe()
{ 
    std::string agregat;
    if (mTypeAgregat == ElementAttList::A_PIPE)
    {
      agregat = "|";
    }
    else
    {
      agregat = "";
    }
    
    std::string re("(");
    for(std::list <ElementAttBase *>::iterator it=mElementAttBase.begin();it!=mElementAttBase.end();it++)
    {
      re += (*it)->GetRe();
      if(it != --mElementAttBase.end())
          re += agregat;
    }
    re += ")";

	re += GetCardinality();

    return re;
}

void ElementAttList::Print()
{
	// Selection du séparateur
	std::string agregat = " ";
	if (mTypeAgregat == ElementAttList::A_PIPE)
	{
		agregat = " | ";
	}
	else // COMMA
	{
		agregat = ", ";
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
	std::cout << ")" + GetCardinality();

} //----- fin de ElementAttList::Print()

// Methode d'ajout de <elem> dans la liste d'attributs
void ElementAttList::push_back(ElementAttBase * elem)
{
	mElementAttBase.push_back(elem);
}
