%{

using namespace std;
#include "commun.h"

int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);
string dtdUrl;

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
}

/*
 %parse-param {
    ElementName ** en; // recopie du poly mais pas trop compris
    Element ** e;
 }
 */

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

%%
/*
 main
   : document   { *en = $1; } // recopie du poly mais pas trop compris
   ;
 */

document
: declarations_opt xml_element misc_seq_opt    /* { (Balise*)*e = $2; } */
 ;
misc_seq_opt
 : misc_seq_opt comment
 | /*empty*/
 ;
comment
 : COMMENT
 ;

declarations_opt
 : declaration
 | /*empty*/
 ;
 
declaration
 : DOCTYPE IDENT IDENT STRING CLOSE {dtdUrl = $4;} /* { $$ = new DocXML($1,,$2,$4); } */
 ;

attributs_opt
 : attributs_opt attribut
 | /*empty*/
 ;

attribut
 : IDENT EQ STRING  /* ((Balise*)*e).addAttribut($1, $3); */
 ;

xml_element
 : start attributs_opt empty_or_content     /* { $$ = new Balise(); } */
 ;
start
 : START		
 | NSSTART	
 ;
empty_or_content
 : SLASH CLOSE	
 | close_content_and_end CLOSE 
 ;
close_content_and_end
 : CLOSE	content_opt END 
 ;
content_opt 
 : content_opt DATA		/* { ((Balise*)*e).addContent(new Data($2)); } */
 | content_opt comment        
 | content_opt xml_element  /* { ((Balise*)*e).addContent($2); *e = *2; } */
 | /*empty*/         
 ;
%%

extern FILE* xmlin;

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
int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

