/*************************************************************************
                           DTD_DOCUMENT  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par fduranton, dbrian, recastrodiaz
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DTD_DOCUMENT> (fichier DtdDocument.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "DtdDocument.h"
#include "DtdElement.h"

using namespace std;

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

DtdDocument::DtdDocument ( std::list<DtdBalise *> * balises ) 
	: mBalises( balises )
// Algorithme :
//
{
} //----- fin de Element

DtdDocument::~DtdDocument ()
// Algorithme :
//
{
	// TODO delete mBalises
} //----- fin de ~Element

void DtdDocument::addElementLinkToAttList ( char * elementName, AttList * attList)
// Algorithme :
{
	ElementLinkToAttList e;
	e.elementName = std::string(elementName);
	e.attList = attList;
	mElementToLinkToAttList.push_back( e );
} //----- fin de addElementLinkToAttList()

void DtdDocument::addElementLinkToAttDef ( char * elementName, AttDef * attDef)
// Algorithme :
{
	ElementLinkToAttDef e;
	e.elementName = std::string(elementName);
	e.attDef = attDef;
	mElementLinkToAttDef.push_back( e );
} //----- fin de addElementLinkToAttDef()

void DtdDocument::Print ()
// Algorithme :
{
	for(std::list <DtdBalise *>::iterator it = mBalises->begin(); it != mBalises->end(); it++)
	{
		(*it)->Print();
	}
  
} //----- fin de Print()

void DtdDocument::GenerateRE()
{
	// Iterating over all the elements
	for (std::list<DtdBalise *>::iterator it = mBalises->begin(); it != mBalises->end(); it++)
	{
	   DtdElement* element = dynamic_cast<DtdElement*>(*it);
       if(element != 0) 
       {
          mRe[element->GetName()] = element->GetRe();
       }
	}

}

bool DtdDocument::CheckXmlElementValidity (std::string dtdElementName, std::string xmlString )
{
	// TODO
}


