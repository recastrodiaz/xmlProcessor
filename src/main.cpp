

#include "main.h"
using namespace std;

extern string dtdURL;
extern int xmldebug;
extern int dtddebug;
int xmlparse();
int dtdparse();

extern FILE * xmlin;
extern FILE * dtdin;

int main(int argc, char **argv)
{

printf("Parsing XML\n");

int err;
  
  if (argv[1] != NULL)
  {
  	xmlin = fopen(argv[1],"r+");
	if (xmlin == NULL)
		return -1;
  }
	
	

  //xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
  err = xmlparse();
  if (err != 0){
 printf("Parse ended with %d error(s)\n", err);

}
  	else  
{
	printf("Parse ended with success\n", err);
	printf("dtdurl : %s\n",dtdURL.c_str());
	dtdin = fopen(dtdURL.c_str(),"r+");
}
  fclose(xmlin);


if (dtdin != NULL){
 err =dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
}
else{
printf("dtd invalide\n");
return -1;
}
  //dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

 
 
 
  return 0;

}

