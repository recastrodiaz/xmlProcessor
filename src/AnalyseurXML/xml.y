%{
#include "../commun.h"
#include "../XMLClass/Element.h"
#include "../XMLClass/DocXML.h"
#include "../XMLClass/Balise.h"
#include "../XMLClass/Data.h"
#include <stdio.h>
#include <string.h>
using namespace std;

//on estime qu'une balise est par défaut une balise de ce type <balise></balise> et non de ce type <balise />
bool empty=false;
//string contenant le nom de la balise
static char* nomBalise;
extern FILE* xmlin;
int xmlwrap(void);
void xmlerror(DocXML** doc, char *msg);
int xmllex(void);


%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
   DocXML * doc;
   Balise * tag;
   vecS * dec_opt; /* vector<string> */
   mapSS * att_opt; /* map<string, string> */
   vecE * cont_opt; /* vector<Element*> */

}


%parse-param { DocXML ** doc} 

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

%type <doc> document
%type <tag> xml_element 
%type <dec_opt> declarations_opt
%type <att_opt> attributs_opt
%type <cont_opt> content_opt
%type <en> start
%type <cont_opt> close_content_and_end
%type <cont_opt> empty_or_content

%%

/* transformation afin de n'avoir qu'un seul objet à droite */
main
 : document   { *doc = $1; }
 ;

document
/* création d'un nouveau document XML qui contiendra l'arbre XML à partir des informations récupérée sur le doctype */
 : declarations_opt xml_element misc_seq_opt    { $$ = new DocXML($2, ((vecS)(*$1))[0], ((vecS)(*$1))[1]); }
 ;

misc_seq_opt
/* on ne prend pas en compte les différents options de la balise <? ?> */
 : misc_seq_opt comment
 | /*empty*/
 ;
comment 
/* les commentaires ne seront également pas pris en compte dans l'arbre XML */
 : COMMENT
 ;

declarations_opt
/* on fait remonter un vecteur de string contenant les informations concernant le doctype: l'url du doctype,le motClé SYSTEM ou bien le FPI si le mot clé est PUBLIC */
 : DOCTYPE IDENT IDENT STRING CLOSE {   $$ = new vecS();
                                        (*$$).push_back(string($3)); 
                                        (*$$).push_back(string($4));
                                        free($3); 
                                        free($4); }
/* s'il n'y a pas de déclaration de doctype on fait remonter des chaines vides */
 | /*empty*/ {  $$ = new vecS();
                $$->push_back(""); 
                $$->push_back(""); }
 ;

attributs_opt
/* on ajoute à la map l'attribut et sa valeur pour le cas où il n'y a pas de namespace */
 : attributs_opt IDENT EQ STRING {  $$ = $1;
                                    (*$$)[string($2)] = string($4); 
                                    free($2); 
                                    free($4) }
/* on ajoute à la map l'attribut et sa valeur pour le cas où il y a un de namespace */
 | attributs_opt NSIDENT EQ STRING {    $$ = $1; 
                                        (*$$)[string($2)] = string($4); 
                                        free($2); 
                                        free($4) }
/* on crée une nouvelle map qui contiendra tous les attributs et leur valeur */
 | /*empty*/ { $$ = new mapSS();}
 ;

xml_element
/* on crée une nouvelle balise à partir de son nom et de son namespace, on lui ajoute la liste d'atributs récupérée, on lui ajoute le contenu récupéré et on indique si elle est vide ( c'est à dire de ce type : <balise />) ou non. Si elle n'a pas été fermée on l'indique à l'utilisateur */
: start attributs_opt empty_or_content      {   nomBalise = strdup(($1->second).c_str());
                                                $$ = new Balise($1->second, $1->first); 
                                                (*$$).addListAttributs($2); 
                                                (*$$).addContent($3); 
                                                $$->setEmpty(empty); } 
 ;

start
/* on renvoit une paire avec le nom et comme namespace une chaine vide */
 : START	{ $$ =  $1; }	
/* on renvoit une paire avec le nom et le namespace */
 | NSSTART	{ $$ = $1; }
 ;

empty_or_content
/* la balise est vide donc on met à jour emty et on passe un vecteur vide */
 : SLASH CLOSE	{   $$ = new vecE(); 
                    empty=true; }
/* la balise a un contenu donc on met à jour le empty à false et on passe le contenu */
 | close_content_and_end CLOSE {    $$ = $1; 
                                    empty=false; }
 ;

close_content_and_end
/* on renvoit le contenu dans le cas où c'est une balise "normale" */
 : CLOSE content_opt END { $$ = $2; }
/* on renvoit le contenu dans le cas où c'est une balise avec un namespace */
 | CLOSE content_opt NSEND { $$ = $2; }
/* on se trouve dans le cas où une balise n'a pas été fermée donc on prévient l'utilisateur tout en continuant l'exécution => le résultat de l'analyse indiquera qu'il y a une erreur dans le parsing */
 | CLOSE content_opt error {    $$ = $2; 
                                printf("La balise %s n'a pas ete fermee\n", nomBalise); }
 ;

content_opt
/* on ajoute au vecteur la donnée et on renvoit le vecteur */
 : content_opt DATA	{   $$ = $1; 
                        (*$$).push_back(new Data(string($2))); }
/* on ne prend pas en compte les commentaires donc on ne fait que renvoyer simplement la donnée */
 | content_opt comment	{ $$ = $1; }
/* on ajoute la balise fille au vecteur et on renvoit le vecteur d'éléments */
 | content_opt xml_element   {  $$ = $1; 
                                (*$$).push_back($2); }
/* on crée le vecteur qui contiendra tous les éléments appartenant à la balise en cours */
 | /*empty*/	{ $$ = new vecE(); }
 ;

%%

int xmlwrap(void)
{
  return 1;
}

void xmlerror(DocXML ** doc, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

