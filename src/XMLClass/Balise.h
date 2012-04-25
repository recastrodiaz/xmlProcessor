/*************************************************************************
 BALISE  -  description
 -------------------
 début                : 02/04/2012
 copyright            : (C) 2012 par atamborrino, nrabardeau, lardon
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface du module <Balise> (fichier Balise.h) ---------
#if ! defined ( BALISE_H )
#define BALISE_H

//------------------------------------------------------------------------
// Rôle du module <BALISE>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

#include "../commun.h"
#include "Element.h"
#include "../DTDClass/DtdDocument.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
//
// Contrat :
//

class Balise: public Element {
public:
	Balise(string unNom, string unNs = "");
	virtual ~Balise();

	void Print();

	void addAttribut(string label, string value);
	// Mode d'emploi : Ajoute un attribut label="value"

	void addListAttributs(mapSS *uneListeAttributs);
	// Mode d'emploi : Ajoute une map<string,string> 
	// d'attribut label="value"

	void addElement(Element* elem);
	// Mode d'emploi : Ajoute un element fils

	void addContent(vecE* elem);
	// Mode d'emploi : Ajoute un vecteur<Element>
	// d'elements fils

	void setEmpty(bool unEmpty);
	// Mode d'emploi : Indique s'il s'agit d'une
	// balise vide

	bool GetEmpty();

	string GetNom();
	void SetNom(string unNom);
	string GetNs();
	// Mode d'emploi : Renvoie le namespace

	void SetNs(string unNs);

	mapSS& GetAttributs();
	vecE& GetElem();
	
	bool verifyValidity(DtdDocument & docDtd);
	// Mode d'emploi : Verifie la validite d'un 
	// noeud xml par rapport a la dtd du document

	private:
	mapSS *attributs;
	vecE *elements;
	string nom;
	string ns;
	bool empty;
};

#endif // BALISE_H

