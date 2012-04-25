%{
#include "../commun.h"
#include "../XMLClass/Element.h"
#include "../XMLClass/DocXML.h"
#include "../XMLClass/Balise.h"
#include "../XMLClass/Data.h"
#include <stdio.h>
#include <string.h>
using namespace std;


    bool empty=false;
string dtdURL;
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
   vecS * dec_opt;
   mapSS * att_opt;
   vecE * cont_opt;

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

main
 : document   { *doc = $1; }
;

document
: declarations_opt xml_element misc_seq_opt    { $$ = new DocXML($2, ((vecS)(*$1))[0], ((vecS)(*$1))[1]); }
 ;

misc_seq_opt
 : misc_seq_opt comment
 | /*empty*/
 ;
comment
 : COMMENT
 ;

declarations_opt
 : DOCTYPE IDENT IDENT STRING CLOSE { dtdURL=string($4); $$ = new vecS(); (*$$).push_back(string($3)); (*$$).push_back(string($4)); free($3); free($4); }
 | /*empty*/ { $$ = new vecS(); $$->push_back(""); $$->push_back(""); }
 ;

attributs_opt
 : attributs_opt IDENT EQ STRING { $$ = $1; (*$$)[string($2)] = string($4); free($2); free($4) }
 | attributs_opt NSIDENT EQ STRING { $$ = $1; (*$$)[string($2)] = string($4); free($2); free($4) }
 | /*empty*/ { $$ = new mapSS();}
;

xml_element
: start attributs_opt empty_or_content      { $$ = new Balise($1->second, $1->first); (*$$).addListAttributs($2); (*$$).addContent($3); $$->setEmpty(empty);} 
 ;
start
 : START	{ $$ =  $1; }	
 | NSSTART	{ $$ = $1; }
 ;
empty_or_content
: SLASH CLOSE	{ $$ = new vecE(); empty=true;}
| close_content_and_end CLOSE { $$ = $1; empty=false;}
 ;
close_content_and_end
 : CLOSE content_opt END { $$ = $2; }
 | CLOSE content_opt NSEND { $$ = $2; }
 | CLOSE content_opt error { $$ = $2; printf("Une erreur\n"); /*TODO: Traiter l'erreur! */ }
 ;
content_opt 
 : content_opt DATA	{ $$ = $1; (*$$).push_back(new Data(string($2))); }
 | content_opt comment	{ $$ = $1; }
 | content_opt xml_element   { $$ = $1; (*$$).push_back($2); }
 | /*empty*/	{ $$ = new vecE(); }
 ;
%%


/*
int main(int argc, char **argv)
{
  int err;
  FILE * file;
  if (argv[1] != NULL)
  {
  	xmlin = fopen(argv[1],"r+");
	if (xmlin == NULL)
		return -1;
  }
  xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
  err = xmlparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  	else  printf("Parse ended with success\n", err);
  fclose(xmlin);
  return 0;
}
*/

int xmlwrap(void)
{
  return 1;
}

void xmlerror(DocXML ** doc, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

