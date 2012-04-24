#include "../commun.h"
#include "../XMLClass/Balise.h"
#include "../XMLClass/Element.h"
#include "../XMLClass/Data.h"
#include "../XMLClass/DocXML.h"
#include "HTMLProc.h"

#include <iostream>
using namespace std;

int main()
{
	//Arbre XSL
    /*
     <xsl:stylesheet>
     
     <xsl:template match="liste_nombres">
     <html>
     <body>
     data dans le body
     <ul>
     <xsl:apply-templates select="nombre"/>
     </ul>
     </body>
     </html>
     </xsl:template>
     
     <xsl:template match="nombre">
     <li>
     <xsl:value-of select="."/>
     </li>
     </xsl:template>
     
     </xsl:stylesheet>
     */
    Balise *XSLStylsheet = new Balise("stylesheet", "xsl");
    
    //template1
    Balise *template1 = new Balise("template", "xsl");
	template1->addAttribut("match", "liste_nombres");
	
	Balise *html = new Balise("html", "");
	Balise *body = new Balise("body", "");
    Data *dataB = new Data("data dans le body");
	Balise *ul = new Balise("ul", "");	
	Balise *applyT = new Balise("apply-templates", "xsl");
    applyT->setEmpty(true);
    applyT->addAttribut("select", "nombre");

	ul->addElement(applyT);
    body->addElement(dataB);
	body->addElement(ul);
	html->addElement(body);
	template1->addElement(html);

    //template2
    Balise *template2 = new Balise("template", "xsl");
	template2->addAttribut("match", "nombre");
	
	Balise *li = new Balise("li", "");
    Balise *valueOf = new Balise("value-of", "xsl");
    valueOf->addAttribut("select","nombreDix");
    valueOf->setEmpty(true);
    
	li->addElement(valueOf);
	template2->addElement(li);
	
    XSLStylsheet->addElement(template1);
    XSLStylsheet->addElement(template2);
	cout << "arbre XSL : "<<endl;
	XSLStylsheet->Print();
    cout << endl;
    
    //Arbre XML
    /*
     <liste_nombres>
        <nombre>
            <nombreDix>dix</nombreDix>
        </nombre>
        <nombre>zero</nombre>
     </liste_nombres>
     */
    Balise *listeNombres = new Balise("liste_nombres","");
    
    Balise *nombreDix = new Balise("nombre","");
    Balise *nombreDix2 = new Balise("nombreDix","");
    Data *dataDix = new Data("dix");
    nombreDix2->addElement(dataDix);
    nombreDix->addElement(nombreDix2);
    Balise *nombreZero = new Balise("nombre","");
    Data *dataZero = new Data("zero");
    nombreZero->addElement(dataZero);
    
    listeNombres->addElement(nombreDix);
    listeNombres->addElement(nombreZero);
    
    cout << "arbre XML : " << endl;
    listeNombres->Print();
    cout << endl;
    
    DocXML *arbreXML = new DocXML(listeNombres, "", "");
    DocXML *arbreXSL = new DocXML(XSLStylsheet, "", "");
    
    HTMLProc *docHTML = new HTMLProc(arbreXML, arbreXSL);
    docHTML->Print();
    
    /*//test findFils
    cout << "test de findFils(): value-of select='nombreDix'" << endl;
    bool erreur = false;
    Data *data = docHTML->findFils("nombreDix", arbreXML->GetRoot(), erreur);
    if(erreur)
        cout << "erreur" << endl;
    else
        cout << "data : " << data->GetValue() << endl;*/
    
    
    
    
} 









