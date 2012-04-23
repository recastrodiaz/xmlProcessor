/*************************************************************************
                           HTMLPROC  -  description
                             -------------------
    début                : 02/04/2012
    copyright            : (C) 2012 par nrabardeau, atamborrino, lardon
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <HTMLPROC> (fichier HTMLProc.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "HTMLProc.h"
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

HTMLProc::HTMLProc (DocXML *unDocXML, DocXML *unDocXSL) : rootXML(unDocXML->root) ,rootXSL(unDocXSL->root)
/* Algorithme :
Constructeur de HTMLProc:
*/
{
	
	docHTML = new DocXML();
	docHTML.SetRoot(NULL);
	htmlCourant = docHTML.getRoot();
	findXSLMatch(rootXML);
} //----- fin de Constructeur

HTMLProc::~HTMLProc ()
// Algorithme : Destructeur
//
{
	

} //----- fin de Destructeur

void HTMLProc::parcoursFilsXML(Balise * uneBaliseXML){
// Algorithme : parcoursFilsXML
//parcours de l'arbre XML
//
	vecE::iterator itXML;
	for(itXML=(uneBaliseXML->elements).begin();itXML!=(uneBaliseXML->elements).end(); itXML++){
		Balise *Bfils = dynamic_cast<Balise*>(*itXML);
		if(Bfils != 0) {
			cout << "cast reussi" << endl;
			findXSLMatch(Bfils);
		}
		else{
			cout << "cast fail" << endl;
		}
	}
}

void HTMLProc::findXSLMatch(Balise * uneBalise/*ajouter parametre contenant l'arbre html*/) {
// Algorithme : findXSLMatch
//remplissage de l'arbre html
//
	vecE::iterator itXML;
	vecE::iterator itXSL = this->rootXSL;
	for(itXML=(uneBalise->elements).begin();itXML!=(uneBalise->elements).end(); itXML++){ //parcours de l'arbre XML
		
		if(itXSL.nom == "template" && (itXSL.attributs[0])->second == uneBalise.nom){ //parcours de l'arbre XSL
			vecE::iterator itXSLfils;
			//on traite!
			for (itXSLfils= (itXSL->elements).begin() ; itXSLfils != (itXSL->elements).end(); itXSLfils++){ //
				if (itXSLfils.nom == "apply-templates"){ //parcours des fils de la balise XML courante
					parcoursFilsXML(*itXML);
				}
				/*else if(itXSLfils->nom == "value-of")
				{
					if(itXSLfils->attributs[0]->first == "select")
					{
					  if(itXSLfils->attributs[0]->second == ".")
					  { // Valeur de la data de la balise XML
					    // On suppose qu'il n'existe qu'un seul fils à l'élément considéré
                                            // et que ce fils est un élément Data
   					docHTML->elements.addElement(itXML->elements[0])
						
					  }
					  else if(((itXSLfils->attributs[0])->second)[0] == '@' )
					  {  // Valeur de l'attribut de la balise XML
						
					  }
					}

				}*/
				else{ //copie dans l'arbre html des balises filles du "xsl:template" courant
					if(itXSLfils->ns != "xsl"){
						Balise *baliseToAdd = new Balise(itXSLfils->GetNom(), itXSLfils->GetNs());
						(htmlCourant==NULL) ? htmlCourant = baliseToAdd : htmlCourant->addElement(baliseToAdd);
					}
					htmlCourant->elements.addElement(*itXSLfils);	
				}	
			}
		}
		else{
			parcoursFilsXML(uneBalise);
		}
		itXSL++;
	}
	
}

void HTMLProc::Print ()
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
    for (mapSS::iterator it=(this->attributs).begin(); it != (this->attributs).end(); it++)
    {
        cout << " "<<it->first << "=\"" << it->second << "\""; 
    }
    
    if (this->empty)
        cout << "/>\r\n";
    else
    {
        cout << ">\r\n";
    
    //elements display
	for (vecE::iterator it = elements.begin(); it!=elements.end(); ++it) {
    		(*it)->Print();
	}
    
    cout << "</";
    if (this->ns != ""){
        cout << this->ns<<":";
    }        
    cout << this->nom << ">\r\n";
        
    }
    
} //----- fin de Print


