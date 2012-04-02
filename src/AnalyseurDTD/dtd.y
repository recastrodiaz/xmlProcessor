%{

void yyerror(char *msg);
int yywrap(void);
int yylex(void);
%}

%union { 
   char *s; 
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING
%%

main 
: dtd_opt
;

dtd_opt
: dtd_opt
| dtd_list_opt elementspec_opt
;

dtd_list_opt
: dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE            
| /* empty */                     
;

att_definition_opt
: att_definition_opt attribute
| /* empty */
;

attribute
: IDENT att_type default_declaration
;

att_type
: CDATA    
| TOKENTYPE
| enumerate
;

enumerate
: OPENPAR enum_list_plus CLOSEPAR
;

enum_list_plus
: enum_list PIPE item_enum
;

enum_list
: item_enum               
| enum_list PIPE item_enum
;

elementspec_opt
: elementspec_opt elementspec
| /* vide */
;

elementspec
: ELEMENT IDENT contentspec CLOSE
;

contentspec
: EMPTY
| ANY
| mixed
| children
;


card_opt
: QMARK 
| PLUS
| AST
| /* vide */
;

children
: choice_or_seq card_opt
;

choice_or_seq
: choice | seq
;

cp
: children 
| IDENT card_opt
;

choice
: OPENPAR cp liste_choice_plus CLOSEPAR
;

seq
: OPENPAR cp liste_seq_opt CLOSEPAR
;

liste_choice_plus
: liste_choice_plus PIPE cp
| PIPE cp
;

liste_seq_opt
: liste_seq_opt COMMA cp
| /* vide */
;

mixed
: OPENPAR PCDATA liste_mixed_opt CLOSEPAR AST
| OPENPAR PCDATA CLOSEPAR
;

liste_mixed_opt
: liste_mixed_opt PIPE IDENT
| /* vide */
;

item_enum
: IDENT
;

default_declaration
: DECLARATION 
| STRING     
| FIXED STRING 
;
%%
int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = yyparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
  return 0;
}
int yywrap(void)
{
  return 1;
}

void yyerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


