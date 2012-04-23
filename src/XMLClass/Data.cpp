/*************************************************************************
                           DATA  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par nrabardeau, atamborrino, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <DATA> (fichier Data.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Data.h"
#include <iostream>
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

Data::Data (string uneValue) : Element(), value(uneValue)
// Algorithme :
//
{
} //----- fin de Nom

Data::~Data ()
// Algorithme :
//
{
} //----- fin de Nom

string Data::GetValue ()
// Algorithme :
//
{
  return value;
} //----- fin de Nom


void Data::Print ()
// Algorithme :
//
{
    	cout << this->value << endl;
} //----- fin de Nom

std::string Data::getName()
{
	return "#PCDATA";
}

bool Data::verifyValidity(DtdDocument & docDtd)
{
	// No verification here
	return true;
}


 
