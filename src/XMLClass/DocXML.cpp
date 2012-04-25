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

DocXML::DocXML() : root(NULL)
{
}

DocXML::DocXML (Balise* unRoot, string unKeyword, string uneUrl) : root(unRoot), keyword(unKeyword), dtdUrl(uneUrl) 
/* Algorithme :
   - unRoot : pointe vers la balise racine du document xml
   - unKeyword : SYSTEM eventuellement
   - uneUrl : url de la dtd correspondant au document xml
*/
{
} //----- fin de Constructeur

DocXML::~DocXML ()
// Algorithme : trivial
{
} //----- fin de Destructeur


void DocXML::Print()
// Algorithme : trivial
{
	if(root != NULL)
    	this->root->Print();
	else
		std::cout << "ROOT IS NULL" << std::endl;
} //----- fin de Print


bool DocXML::verifyValidity(DtdDocument & docDtd)
// Algorithme : Verification recursive de la validite
// de tous les noeuds du document xml
{
	return root->verifyValidity(docDtd);
} //----- fin de verifyValidity


Balise* DocXML::GetRoot(){
	return this->root;
} //----- fin de GetRoot

void DocXML::SetRoot(Balise* uneBalise){
	this->root = uneBalise;
} //----- fin de SetRoot

string DocXML::GetDtdUrl(){
	return dtdUrl;
} //----- fin de GetDtdUrl

