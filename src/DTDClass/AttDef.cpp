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
	std::cout << mElement->GetName() << " " << mAttType << " " << mDefaultDec;
}
AttDef::AttDef () : DtdBalise()
// Algorithme :
//
{

} //----- fin de Element

AttDef::AttDef(Element* aElement,std::string aAttType, std::string aDefaultDec ) : DtdBalise(), mElement(aElement),mAttType(aAttType), mDefaultDec(aDefaultDec)
// Algorithme :
//
{
} //----- fin de Element

AttDef::~AttDef ()
// Algorithme :
//
{
} //----- fin de ~Element


