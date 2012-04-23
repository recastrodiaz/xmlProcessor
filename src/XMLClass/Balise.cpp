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

Balise::Balise (string unNom, string unNs) : Element(), nom(unNom), ns(unNs)
/* Algorithme :
Constructeur de Balise:
 - unNom : label de la balise
 - unNs : namespace de la balise
*/
{
    this->empty=false;
    attributs = new mapSS();
    elements = new vecE();
} //----- fin de Constructeur

Balise::~Balise ()
// Algorithme : Destructeur
//
{
	vecE::iterator it;
	for (vecE::iterator it = elements->begin(); it!=elements->end(); ++it) {
    		delete (*it);
	}
	delete &elements;
	delete &attributs;
	


} //----- fin de Destructeur

void Balise::Print ()
/* Algorithme :
 Affichage de la balise et de ses composants
*/
{
    cout << "<";
    if (this->ns != ""){
        cout << this->ns<<":";
    }
    cout << this->nom;
    //attributs display
    for (mapSS::iterator it=attributs->begin(); it != attributs->end(); it++)
    {
        cout << " "<<it->first << "=\"" << it->second << "\""; 
    }
    
    if (this->empty)
        cout << "/>\r\n";
    else
    {
        cout << ">\r\n";
    
    //elements display
	for (vecE::iterator it = elements->begin(); it!=elements->end(); ++it) {
    		(*it)->Print();
	}
    
    cout << "</";
    if (this->ns != ""){
        cout << this->ns<<":";
    }        
    cout << this->nom << ">\r\n";
        
    }
    
} //----- fin de Print

void Balise::addAttribut (string label, string value)
/* Algorithme :
 Ajout d'un attribut à la balise
 - label : label de l'attribut à ajouter
 - value : valeur de l'atttribut à ajouter
*/
{
    pair<mapSS::iterator,bool> ret;
    ret = attributs->insert(pair<string, string>(label, value));
    if (!ret.second) {
        //TODO: traiter les erreurs : l'attribut existe déjà
    }
} //----- fin de addAttribut

void Balise::addListAttributs (mapSS *uneListeAttributs)
/* Algorithme :
 Ajout d'un ensemble d'attributs à la balise
 - uneListeAttributs : ensemble des attributs à ajouter à la balise
*/
{
	for (mapSS::iterator it=(*uneListeAttributs).begin(); it != (*uneListeAttributs).end(); it++)
		addAttribut (it->first, it->second);

} //----- fin de addListAttributs

void Balise::addContent (vecE* elem)
/* Algorithme :
 Ajout d'une suite d'éléments dans le corps de la balise
 - eleme: tableau contenant les éléments à ajouter au corps de la balise
*/
{
	for ( vecE::iterator it = (*elem).begin(); it != (*elem).end(); it++)
		elements->push_back(*it);
} //----- fin de addContent

void Balise::addElement(Element *elem)
/* Algorithme :
 Ajoute un element
*/
{
	elements->push_back(elem);
} //----- fin de addElement


void Balise::setEmpty(bool unEmpty)
/* Algorithme :
 Indique que la balise ne contient aucun élément en mettant à jour l'attribut.
*/
{
	this->empty = unEmpty;
} //----- fin de setEmpty

bool Balise::GetEmpty()
/* Algorithme :
*/
{
	return this->empty;
} //----- fin de setEmpty

string Balise::GetNom()
{
	return this->nom;
}

void Balise::SetNom(string unNom)
{
	this->nom = unNom;
}

mapSS& Balise::GetAttributs()
{
	return *attributs;
}

string Balise::GetNs()
{
	return this->ns;
}

void Balise::SetNs(string unNs)
{
	this->ns = unNs;
}

vecE& Balise::GetElem()
{
	return *elements;
}

bool Balise::verifyValidity(DtdDocument & docDtd)
{
	// First, we verify this node
	std::string stringToMatch = "";
	for ( vecE::iterator it = elements->begin(); it != elements->end(); it++)
	{
		stringToMatch += (**it).GetNom();
	}
	if (!docDtd.CheckXmlElementValidity(nom,stringToMatch)){
		std::cout<< "The \"" + nom + "\" tag is not valid" << endl;
		return false;
	}
	// *this* node is OK

	//we are going to check his children
	for (vecE::iterator it = elements->begin(); it != elements->end(); it++) {
		if (!(**it).verifyValidity(docDtd))
		{
			return false;
		}
	}
	return true;

}
