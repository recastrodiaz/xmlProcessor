/*************************************************************************
                           ATT_DEF  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
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
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom
void AttDef::Print()
{
	if( mElement )
		std::cout << mElement->GetName();
	else;
		std::cout << "NULL";
	std::cout << " " << mAttType << " " << mDefaultDec;
}
AttDef::AttDef () : DtdBalise()
// Algorithme :
//
{

} //----- fin de DtdElement

AttDef::AttDef(std::string aAttType, std::string aDefaultDec ) 
	: DtdBalise(), mElement(NULL),mAttType(aAttType), mDefaultDec(aDefaultDec)
// Algorithme :
//
{
} //----- fin de DtdElement

AttDef::~AttDef ()
// Algorithme :
//
{
} //----- fin de ~DtdElement



