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

DtdDocument::DtdDocument () 
// Algorithme :
//
{
} //----- fin de Element

DtdDocument::~DtdDocument ()
// Algorithme :
//
{
} //----- fin de ~Element
void DtdDocument::Print ()
// Algorithme :
{
for(std::list <DtdBalise *>::iterator i=mBalises.begin();i!=mBalises.end();i++)
  {
   (*i)->Print();
  }
  
} //----- fin de Print()


