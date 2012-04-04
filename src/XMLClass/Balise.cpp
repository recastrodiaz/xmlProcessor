/*************************************************************************
                           BALISE  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par nrabardeau, atamborrino, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <BALISE> (fichier Balise.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Balise.h"
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

Balise::Balise (string unNom) : Element(), nom(unNom)
// Algorithme :
//
{
} //----- fin de Nom

Balise::~Balise ()
// Algorithme :
//
{
	vecE::iterator it;
	for (vecE::iterator it = elements.begin(); it!=elements.end(); ++it) {
    		delete (*it);
	}
	delete &elements;
	delete &attributs;
	


} //----- fin de Nom

void Balise::Print ()
// Algorithme :
//
{
	vecE::iterator it;
	for (vecE::iterator it = elements.begin(); it!=elements.end(); ++it) {
    		(*it)->Print();
	}
} //----- fin de Nom

void Balise::addAttribut (string label, string value)
// Algorithme :
//
{
    pair<mapSS::iterator,bool> ret;
    ret = attributs.insert(pair<string, string>(label, value));
    if (!ret.second) {
        //TODO: traiter les erreurs : l'attribut existe déjà
    }
} //----- fin de Nom

void Balise::addListAttributs (mapSS *uneListeAttributs)
// Algorithme :
//
{
	for (mapSS::iterator it=(*uneListeAttributs).begin(); it != (*uneListeAttributs).end(); it++)
		addAttribut (it->first, it->second);

} //----- fin de Nom

void Balise::addContent (vecE* elem)
// Algorithme :
//
{
	for ( vecE::iterator it = (*elem).begin(); it != (*elem).end(); it++)
		elements.push_back(*it);
} //----- fin de Nom



