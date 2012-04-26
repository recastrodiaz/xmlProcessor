/*************************************************************************
                           ATT_DEF  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
*************************************************************************/

//---------- Réalisation du module <AttDef> (fichier AttDef.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "AttDef.h"

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

// Affiche sur la sortie standard la définition de l'attribut: mElementName,
// mAttType, mDefaultDec
void AttDef::Print()
// Algorithme : Trivial
//
{
	if( !mElementName.empty() )
		std::cout << mElementName;
	else
		std::cout << "NULL";
	std::cout << " " << mAttType << " " << mDefaultDec;
} //----- fin de AttDef

// Constructeur par défaut
AttDef::AttDef ()
// Algorithme : Trivial
//
{

} //----- fin de AttDef

// Constructeur avec parametres
AttDef::AttDef( std::string elementName, std::string aAttType, std::string aDefaultDec ) 
	: mElement(NULL), mElementName(elementName), mAttType(aAttType), mDefaultDec(aDefaultDec)
// Algorithme : Trivial
//
{
} //----- fin de AttDef

// Destructeur
AttDef::~AttDef ()
// Algorithme : Trivial
//
{
	// mElement sera détruit par DtdDocument
	mElement = NULL;
} //----- fin de ~AttDef


