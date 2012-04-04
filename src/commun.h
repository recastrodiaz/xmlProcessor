#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include "XMLClass/Element.h"


//typedef pair<string,string> Attribut;
//typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;

typedef vector<Element*> vecE;
typedef map<string,string> mapSS;
typedef vector<string> vecS;


#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
