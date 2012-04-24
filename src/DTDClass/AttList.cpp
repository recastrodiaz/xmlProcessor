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
	std::cout << "<!ATTLIST ";
	// FIXME: DEBUG	--> C'est un mElementName qu'il faut
	//std::cout << "Dans AttList::Print(), IDENT = " << mElementName << std::endl;
	// FIXME: FIN DEBUG
	if( !mElementName.empty() )
	{
		std::cout << mElementName << " ";
	}
	else
	{
		std::cout << "NULL ";
	}
	// FIXME: DEBUG
	//std::cout << "[" << mAttDefs->size() << "]" << std::endl;
	// FIXME: FIN DEBUG
	for(std::list <AttDef*>::iterator i = mAttDefs->begin(); i != mAttDefs->end(); i++)
	{
       (*i)->Print();
	}
	std::cout << ">";
}

AttList::AttList(std::string elementName, std::list<AttDef*> * aAttDefs) 
	: DtdBalise(), mElement(NULL), mElementName(elementName), mAttDefs (aAttDefs)
// Algorithme :
//
{
} //----- fin de DtdElement

AttList::~AttList ()
// Algorithme :
//
{
	// mElement est détruit par DtdDocument
	mElement = NULL;

	if( mAttDefs )
	{
		for(std::list <AttDef*>::iterator it = mAttDefs->begin(); it != mAttDefs->end(); it++)
		{
			delete *it;
		}
		delete mAttDefs;
	}
	
} //----- fin de ~DtdElement

const std::list<AttDef*> * AttList::getAttDefs() const
{
	return mAttDefs;
}



