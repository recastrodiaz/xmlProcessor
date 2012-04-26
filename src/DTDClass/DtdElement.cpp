/*************************************************************************
                           DtdElement  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : 
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

// Methode d'affichage d'un element
void DtdElement::Print()
{
	std::cout << "<!ELEMENT " << mIdent << " ";
	mAttributeReference->Print();
	std::cout << ">";
}//----- fin de Print()

// Constructeur par defaut de DtdElement
DtdElement::DtdElement () 
	: DtdBalise(), mAttList (), mAttDef ()
// Algorithme :
//
{
	mAttributeReference = 0;
} //----- fin de DtdElement

// Constructeur avec parametre de DtdElement
DtdElement::DtdElement (std::string aIdent, ElementAttBase * aAttributeReference, std::list <AttList*> aAttList, std::list <AttDef*> aAttDef)
	: DtdBalise(),mIdent(aIdent), mAttList (aAttList), mAttDef (aAttDef), mAttributeReference(aAttributeReference)
// Algorithme :
//
{

} //----- fin de DtdElement

// Destructeur de DtdElement
DtdElement::~DtdElement ()
// Algorithme :
//
{
		delete mAttributeReference;
		// mAttList sera détruit par DtdDocument
		// mAttDef sera détruit par DtdDocument
} //----- fin de ~DtdElement

std::string DtdElement::GetName()
{
    return mIdent;
} //----- fin de GetName()

std::string DtdElement::GetRe()
{
    return mAttributeReference->GetRe();
} //----- fin de GetRe()


