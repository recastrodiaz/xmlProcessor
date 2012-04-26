/*************************************************************************
                           ATT_LIST  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
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

// Methode d'affichage d'une liste d'attribut 
void AttList::Print()
// Algorithme :
// trivial avec les iterator pour parcourir la liste des attributs
{
	std::cout << "<!ATTLIST ";
	if( !mElementName.empty() )
	{
		std::cout << mElementName << " ";
	}
	else
	{
		std::cout << "NULL ";
	}

	for(std::list <AttDef*>::iterator i = mAttDefs->begin(); i != mAttDefs->end(); i++)
	{
       (*i)->Print();
	}
	std::cout << ">";
} //----- fin de Print

// Constructeur avec parametres
AttList::AttList(std::string elementName, std::list<AttDef*> * aAttDefs) 
	: DtdBalise(), mElement(NULL), mElementName(elementName), mAttDefs (aAttDefs)
// Algorithme :
//
{
} //----- fin de AttList

// Destructeur
AttList::~AttList ()
// Algorithme :
//
{
	// mElement est détruit par DtdDocument
	mElement = NULL;
    
    //Suppression des éléments AttDef de la liste
	if( mAttDefs )
	{
		for(std::list <AttDef*>::iterator it = mAttDefs->begin(); it != mAttDefs->end(); it++)
		{
			delete *it;
		}
		delete mAttDefs;
	}
	
} //----- fin de ~AttList

// Methode d'acces aux definition d'attribut de la liste
const std::list<AttDef*> * AttList::getAttDefs() const
{
	return mAttDefs;
} //----- fin de getAttDefs



