#include "../commun.h"
#include "../XMLClass/Balise.h"
#include "../XMLClass/Element.h"
#include "../XMLClass/Data.h"
#include "../XMLClass/DocXML.h"

#include <iostream>
using namespace std;

int main()
{
	Balise *template1 = new Balise("template", "xsl");
	template1->addAttribut("match", "liste_nombres");
	
	Balise *html = new Balise("html", "");
	Balise *body = new Balise("body", "");
	Balise *ul = new Balise("ul", "");	
	Balise *applyT = new Balise("apply-templates", "xsl");

	ul->addElement(applyT);
	body->addElement(ul);
	html->addElement(body);
	template1->addElement(html);
	
	cout << "template1 : "<<endl;
	template1->Print();
} 
