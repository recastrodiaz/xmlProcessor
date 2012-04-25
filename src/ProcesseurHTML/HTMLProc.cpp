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

HTMLProc::HTMLProc (DocXML *unDocXML, DocXML *unDocXSL) : rootXSL(unDocXSL->GetRoot()), erreur(false)
/* Algorithme :
Constructeur de HTMLProc:
*/
{
	
	Balise *docXML = new Balise("docXML","");
	Balise *root = new Balise("/","");
	root->addElement(unDocXML->GetRoot());
    docXML->addElement(root);
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

Data * HTMLProc::findFils(string nom, Element *baliseCourante, bool &erreur){
    Data *data = dynamic_cast<Data*>(baliseCourante);
    if (data != 0) {//c'est une data donc j'arrete la recherche
        return NULL; //pas trouvé
    }else{
        Balise *baliseC = dynamic_cast<Balise*>(baliseCourante);
        if(baliseCourante->GetNom() == nom){ //je trouve la balise que je recherche
            Data *DToAdd = dynamic_cast<Data*>(baliseC->GetElem().front());
            if ((DToAdd != 0) && (baliseC->GetElem().size() == 1)){ //vérification du contenu à ajouter => il faut que ce soit uniquement une Data
                return DToAdd;
            }else{
                erreur = true;
                return NULL; //trouvé mais erreur car contient autre chose qu'une simple DATA
            }
        }else{
            vecE::iterator itFils;
            Data *result;
            for(itFils=(baliseC->GetElem()).begin();itFils!=(baliseC->GetElem()).end();itFils++){
                result = findFils(nom, (*itFils), erreur); 
                if(result != NULL || erreur)//choix de retourner le contenu de la première balise rencontrée même si c'est une erreur
                    return result;
            }
            return result;
        }
    }
}


void HTMLProc::construireHTML(Balise *balXMLCourante, Balise *balHTMLCourante, Balise *balXSLCourante){
	vecE::iterator itFils;
    //
	for(itFils=(balXSLCourante->GetElem()).begin();itFils != (balXSLCourante->GetElem()).end();itFils++){ //pour tous les fils de la balise XSL courante
		if((*itFils)->GetNom() == "apply-templates") 
            findTemplate(balXMLCourante, balHTMLCourante);
		else if((*itFils)->GetNom() == "value-of"){
            if(((Balise*)(*itFils))->GetAttributs()["select"] == balXMLCourante->GetNom() || ((Balise*)(*itFils))->GetAttributs()["select"] == "."){ //<xsl:value-of select="NomBaliseCourante" >
                Data *DToAdd = dynamic_cast<Data*>(balXMLCourante->GetElem().front());
                if ((DToAdd != 0) && (balXMLCourante->GetElem().size() == 1)){ //vérification du contenu à ajouter => il faut que ce soit uniquement une Data
                    balHTMLCourante->addElement(DToAdd);
                }else{
                    //Erreur on ne rajoute pas uniquement une Data
                    cout << "Erreur on ne rajoute pas seulement une DATA" << endl;
                    erreur = true;
                }
            }else{ //<xsl:value-of select="NomBaliseFille">
                bool erreurXSL = false;
                Data *DToAdd = findFils(((Balise*)(*itFils))->GetAttributs()["select"], balXMLCourante, erreurXSL);
                if(DToAdd != NULL)
                    balHTMLCourante->addElement(DToAdd);
                else if (erreurXSL){
                    //Erreur on ne rajoute pas uniquement une Data
                    cout << "Erreur on ne rajoute pas seulement une DATA" << endl;
                    erreur = true;
                }else{
                    //Balise non trouvée
                    cout << "Erreur balise non trouvée" << endl;
                }
            }
        }else{  //c'est une element HTML
			Balise *Bfils = dynamic_cast<Balise*>(*itFils);
			if(Bfils == 0) { //balise = data
				balHTMLCourante->addElement(*itFils);
			}else{ //balise avec des fils
				if (balHTMLCourante == NULL){//on initialise l'arbre HTML comme c'est la première balise
					balHTMLCourante = new Balise(Bfils->GetNom(), Bfils->GetNs());
                    docHTML->SetRoot(balHTMLCourante);
					construireHTML(balXMLCourante, balHTMLCourante, Bfils);
				}else{//l'arbre HTML a déjà été initialisé on ajoute à la suite
                    Balise *nvelleBalHTML = new Balise(Bfils->GetNom(), Bfils->GetNs());
					construireHTML(balXMLCourante, nvelleBalHTML, Bfils); 
					balHTMLCourante->addElement(nvelleBalHTML);//on ajoute la balise fille au contenu
				}
			}
		}
	}
}

void HTMLProc::findTemplate(Element *balXMLCourante, Balise *balHTMLCourante){
	Data *data = dynamic_cast<Data*>(balXMLCourante);
    if (data != 0) {//c'est une data donc j'arrete la recherche
        return; //je suis descendu au plus profond
    }else{
        vecE::iterator itFilsXML;
        vecE::iterator itXSL;
        Balise *baliseC = dynamic_cast<Balise*>(balXMLCourante);
        for(itFilsXML=(baliseC->GetElem()).begin();itFilsXML != (baliseC->GetElem()).end();itFilsXML++){ //parcours des balises XML (fils de la balise courante)
            if((baliseC->GetElem()).size() != 0)
                findTemplate((Balise *)*itFilsXML, balHTMLCourante); //récursion pour les fils
            for(itXSL=(rootXSL->GetElem()).begin();itXSL!=(rootXSL->GetElem()).end();itXSL++){ //recherche d'une règle s'appliquant à la balise XML courante
                Balise *BXSL = dynamic_cast<Balise*>(*itXSL); //verification pour voir s'il s'agît bien d'une balise, ça aurait pu etre un data
                if(BXSL != 0) { //c'est une balise
                    if(BXSL->GetNom() == "template" && (BXSL->GetAttributs()["match"]) == (*itFilsXML)->GetNom()){ //template trouvé
                        construireHTML((Balise *)*itFilsXML, balHTMLCourante, BXSL);
                    }
                }
            }
        }
    }
}


void HTMLProc::Print ()
// Algorithme :
// Affichage de la balise et de ses composants
//
{
    docHTML->Print();
    
} //----- fin de Print
