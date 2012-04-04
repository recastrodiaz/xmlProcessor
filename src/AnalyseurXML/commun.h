#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>


typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName; /* TODO Qu'est ce que cela contient ?*/


#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
