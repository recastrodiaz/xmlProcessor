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
	vector<Element*>::iterator it;
	for (vector<Element*>::iterator it = elements.begin(); it!=elements.end(); ++it) {
    		delete **it;
	}
	delete elements;
	delete attributs;
	


} //----- fin de Nom

Balise::getValue ()
// Algorithme :
//
{
	vector<Element*>::iterator it;
	for (vector<Element*>::iterator it = elements.begin(); it!=elements.end(); ++it) {
    		cout << (**it).getValue() << endl;
	}
} //----- fin de Nom

Balise::addAttribut (string label, string value)
// Algorithme :
//
{
	pair<map<string,string>::iterator,bool> ret;
    ret = attributs.insert(pair<string, string>(label, value));
    if (!ret.second) {
        //TODO: traiter les erreurs : l'attribut existe déjà
    }
} //----- fin de Nom

Balise::addContent (Element elem)
// Algorithme :
//
{
	elements.push_back(elem);
} //----- fin de Nom



