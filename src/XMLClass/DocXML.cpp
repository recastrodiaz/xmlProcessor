/*************************************************************************
                           DOCXML  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par nrabardeau, atamborrino, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DOCXML> (fichier DocXML.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DocXML.h"

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

DocXML::DocXML (Balise* unRoot, string unKeyword, string uneUrl) : root(unRoot), keyword(unKeyword), dtdUrl(uneUrl) 
// Algorithme :
//
{
} //----- fin de Nom

DocXML::~DocXML ()
// Algorithme :
//
{
} //----- fin de Nom


void DocXML::Print()
// Algorithme :
//
{
	if(root != NULL)
    	this->root->Print();
	else
		std::cout << "ROOT IS NULL" << std::endl;
} //----- fin de Nom


bool DocXML::verifyValidity(DtdDocument & docDtd)
{
	return root->verifyValidity(docDtd);
}


