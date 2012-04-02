%{
#include "../commun.h"
#include <stdio.h>
#include <string.h>
using namespace std;

//string dtdURL;
char dtdURL[16];
extern FILE* xmlin;
int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);


%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

%%

document
 : declarations_opt xml_element misc_seq_opt 
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
 : DOCTYPE IDENT IDENT STRING CLOSE {printf("$4 : %s\n",$4);strcpy(dtdURL,$4);}
 ;

attributs_opt
 : attributs_opt attribut
 | /*empty*/
 ;

attribut
 : IDENT EQ STRING
 ;

xml_element
 : start attributs_opt empty_or_content 
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
 : content_opt DATA		
 | content_opt comment        
 | content_opt xml_element      
 | /*empty*/         
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

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

