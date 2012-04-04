%{
#include "../commun.h"
#include "../XMLClass/Element.h"
#include "../XMLClass/DocXML.h"
#include "../XMLClass/Balise.h"
#include "../XMLClass/Data.h"
#include <stdio.h>
#include <string.h>
using namespace std;



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
   : document   { *doc = $1; } // recopie du poly mais pas trop compris
   ;

document
: declarations_opt xml_element misc_seq_opt    { $$ = new DocXML(((vecS)(*$1))[0], ((vecS)(*$1))[1], ((vecS)(*$1))[2]); }
 ;

misc_seq_opt
 : misc_seq_opt comment
 | /*empty*/
 ;
comment
 : COMMENT
 ;

declarations_opt
 : DOCTYPE IDENT IDENT STRING CLOSE { dtdURL=string($4); (*$$).push_back(string($2)); (*$$).push_back(string($3)); (*$$).push_back(string($4)); free($2); free($3); free($4); }
 | /*empty*/ { $$ = new vecS(); }
 ;

attributs_opt
 : attributs_opt IDENT EQ STRING { $$ = $1; (*$$)[string($2)] = string($4); free($2); free($4) }
 | /*empty*/ { $$ = new mapSS();}
;

xml_element
 : start attributs_opt empty_or_content      { $$ = new Balise($1->second); (*$$).addListAttributs($2); (*$$).addContent($3); } 
 ;
start
 : START	{ $$ =  $1; }	
 | NSSTART	{ $$ = $1; }
 ;
empty_or_content
 : SLASH CLOSE	{ $$ = new vecE(); }
 | close_content_and_end CLOSE { $$ = $1; } 
 ;
close_content_and_end
 : CLOSE content_opt END { $$ = $2; }
 ;
content_opt 
 : content_opt DATA	{ $$ = $1; (*$$).push_back(new Data(string($2))); }
 | content_opt comment
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

