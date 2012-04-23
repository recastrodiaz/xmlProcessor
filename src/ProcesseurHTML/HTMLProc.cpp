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

HTMLProc::HTMLProc (DocXML *unDocXML, DocXML *unDocXSL) : rootXSL(unDocXSL->GetRoot())
/* Algorithme :
Constructeur de HTMLProc:
*/
{
	
	Balise *docXML = new Balise("docXML","");
    docXML->addElement(unDocXML->GetRoot());
    rootXML = docXML;
    
    docHTML = new DocXML();
	docHTML->SetRoot(NULL);
	findTemplate(rootXML, docHTML->GetRoot());
} //----- fin de Constructeur

HTMLProc::~HTMLProc ()
// Algorithme : Destructeur
//
{
	

} //----- fin de Destructeur




void HTMLProc::construireHTML(Balise *balXMLCourante, Balise *balHTMLCourante, Balise *balXSLCourante){
	vecE::iterator itFils;
	for(itFils=(balXSLCourante->GetElem()).begin();itFils != (balXSLCourante->GetElem()).end();itFils++){ //pour tous les fils de la balise XSL courante
		if((*itFils)->GetNom() == "apply-templates") 
			 findTemplate(balXMLCourante, balHTMLCourante);
		else if((*itFils)->GetNom() == "value-of")
		{}
        else if((*itFils)->GetNom() == "template")
		{}
		else{  //c'est une element HTML
			Balise *Bfils = dynamic_cast<Balise*>(*itFils);
			if(Bfils == 0) { //balise = data
				//Data *dataFils = new Data((Data)Bfils->GetValue());
				balHTMLCourante->addElement(*itFils);
                (*itFils)->Print();
			}
			else{ //balise avec des fils
				if (balHTMLCourante == NULL){
					balHTMLCourante = new Balise(Bfils->GetNom(), Bfils->GetNs());
                    balHTMLCourante->Print();
					construireHTML(balXMLCourante, balHTMLCourante, Bfils);
				}
				else{
					//Balise *nvelleBalHTML = new Balise(balXSLCourante->GetNom(), balXSLCourante->GetNs());
                    Balise *nvelleBalHTML = new Balise(Bfils->GetNom(), Bfils->GetNs());
                    nvelleBalHTML->Print();
					construireHTML(balXMLCourante, nvelleBalHTML, Bfils); 
					balHTMLCourante->addElement(nvelleBalHTML);
				}
			}
		}
	}
}

void HTMLProc::findTemplate(Balise *balXMLCourante, Balise *balHTMLCourante){
	vecE::iterator itFilsXML;
	vecE::iterator itXSL;
	for(itFilsXML=(balXMLCourante->GetElem()).begin();itFilsXML != (balXMLCourante->GetElem()).end();itFilsXML++){ //parcours des balises XML (fils de la balise courante)
        for(itXSL=(rootXSL->GetElem()).begin();itXSL!=(rootXSL->GetElem()).end();itXSL++){ //recherche d'une règle s'appliquant à la balise XML courante
            Balise *BXSL = dynamic_cast<Balise*>(*itXSL); //verification pour voir s'il s'agît bien d'une balise, ça aurait pu etre un data
			if(BXSL != 0) { //balise
                
                if(BXSL->GetNom() == "template" && (BXSL->GetAttributs()["match"]) == (*itFilsXML)->GetNom()){ //template found
                    cout << "balise XSL: " << BXSL->GetNom() << endl;
                    cout << "match : " << BXSL->GetAttributs()["match"] << " nom XML :" << (*itFilsXML)->GetNom() << endl;
                    construireHTML((Balise *)*itFilsXML, balHTMLCourante, BXSL);
                }
			}
			
		}
        //findTemplate((Balise *)*itFilsXML, balHTMLCourante);
	}
}


void HTMLProc::Print ()
// Algorithme :
// Affichage de la balise et de ses composants
//
{
    (docHTML->GetRoot())->Print();
        
} //----- fin de Print

/*void HTMLProc::parcoursFilsXML(Balise * uneBaliseXML){
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
}*/

/*void HTMLProc::findXSLMatch(Balise * uneBalise) {
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
				if (itXSLfils.GetNom == "apply-templates"){ //parcours des fils de la balise XML courante
					parcoursFilsXML(*itXML);
				}
				else if(itXSLfils->nom == "value-of")
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

				}
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
	
}*/

