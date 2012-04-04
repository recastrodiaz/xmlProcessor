/*************************************************************************
                           DtdElement  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DtdElement> (fichier DtdElement.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "DtdElement.h"

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

void DtdElement::Print()
{
	std::cout << "<!ELEMENT " << mIdent << " ";
	mAttributeReference->Print();
	std::cout << ">";
}//----- DtdElement::Print()

std::string DtdElement::GetName()
{
	return mIdent;
}//----- DtdElement::GetName()

DtdElement::DtdElement () 
	: DtdBalise(), mAttList (), mAttDef ()
// Algorithme :
//
{
	mAttributeReference = 0;
} //----- fin de DtdElement

DtdElement::DtdElement (std::string aIdent, ElementAttBase * aAttributeReference, std::list <AttList*> aAttList, std::list <AttDef*> aAttDef)
	: DtdBalise(),mIdent(aIdent), mAttList (aAttList), mAttDef (aAttDef), mAttributeReference(aAttributeReference)
// Algorithme :
//
{

} //----- fin de DtdElement

DtdElement::~DtdElement ()
// Algorithme :
//
{
} //----- fin de ~DtdElement



