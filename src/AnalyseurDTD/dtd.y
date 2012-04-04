%{
#include <string>
#include <list>
#include "../commun.h"

#include "../DTDClass/AttDef.h"
#include "../DTDClass/AttList.h"
#include "../DTDClass/DtdBalise.h"
#include "../DTDClass/DtdDocument.h"
#include "../DTDClass/Element.h"
#include "../DTDClass/ElementAtt.h"
#include "../DTDClass/ElementAttBase.h"
#include "../DTDClass/ElementAttList.h"

extern FILE* dtdin;
void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
	char * tS; 
	std::list<AttDef > * tAttDefList;
	ElementAttBase * tElementAttBase;
	std::list<std::string> * tListAttType; 
	std::list<DtdBalise *> * tListDtdBalise;
	ElementAtt * tElementAtt;
	AttDef tAttDef;
	ElementAttList * tElementAttList;
	std::list<ElementAttBase * > * tListElementAttBase;
	ElementAttBase::Cardinality tCard; 
}

%parse-param { DtdDocument ** dtdDocument }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <tS> IDENT TOKENTYPE DECLARATION STRING

%type <tListDtdBalise> dtd_list_opt
%type <tAttDefList> att_definition_opt
%type <tAttDef> attribute
%type <tListAttType> att_type
%type <tListAttType> enumerate
%type <tListAttType> enum_list_plus
%type <tListAttType> enum_list
%type <tS> item_enum
%type <tElementAtt> elementspec
%type <tElementAttBase> contentspec
%type <tElementAttList> mixed
%type <tElementAttBase> children
%type <tListElementAttBase> list_mixed_plus
%type <tCard> card_opt
%type <tListElementAttBase> choice_or_seq
%type <tListElementAttBase> choice
%type <tListElementAttBase> seq
%type <tElementAttList> cp
%type <tElementAttList> list_choice_plus
%type <tElementAttList> list_seq_opt
%type <tS> default_declaration
%%

main 
: dtd_list_opt											{ 	* dtdDocument = new DtdDocument( $1 ); }
;

dtd_list_opt
: dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE	{	$$ = $1;
															$$->push_back( AttList($3, $4 )); }
| dtd_list_opt elementspec								{ 	$$ = $1;
															$$->push_back( $2 ); }
| /* empty */											{	$$ = new std::list<DtdBalise *>(); }
;

att_definition_opt
: att_definition_opt attribute							{	$$ = $1; 
															$$->push_back( $2 ); }
| /* empty */											{	$$ = new std::list<AttDef>(); }
;

attribute
: IDENT att_type default_declaration					{ 	$$ = new AttDef( $1, $2, $3 ); }
;

att_type
: CDATA    												{	$$ = new std::list<std::string>();
															$$->push_back( std::string("CDATA") ); }
| TOKENTYPE												{	$$ = new std::list<std::string>();
															$$->push_back( std::string($1) ); }
| enumerate												{	$$ = $1; }	/* N'est jamais utilisé */
;

default_declaration
: DECLARATION											{	$$ = $1;	}
| STRING     											{	$$ = $1;	}
| FIXED STRING 											{	char * str = malloc( 7 + strlen($2) + 1);
															strcpy( str, "#FIXED ");
															strcat( str, $2 );
															$$ = str;
															free($2); /* TODO free STRINGs */ }
;

enumerate
: OPENPAR enum_list_plus CLOSEPAR						{	$$ = $2 ); }
;

enum_list_plus
: enum_list PIPE item_enum								{	$$ = $1;
															$1->push_back( std::string($3)); /* TODO PIPE */}
;
enum_list
: item_enum              								{	$$ = new std::list<std::string>();
															$$->push_back( std::string($1) ); }
| enum_list PIPE item_enum								{	$$ = $1;
															$$->push_back( std::string($3) ); /*TODO PIPE*/}
;

item_enum
: IDENT													{ 	$$ = $1; }
;

elementspec
: ELEMENT IDENT contentspec CLOSE						{	$$ = new Element( $2, $3 ); }
;

contentspec
: EMPTY													{	$$ = new ElementAtt( std::string( "EMPTY" ) ); }
| ANY													{	$$ = new ElementAtt( std::string( "ANY" ) ); }
| mixed													{	$$ = $1; }
| children
;

mixed
: OPENPAR PCDATA list_mixed_plus CLOSEPAR AST			{	$$ = new ElementAttList( ElementAttList::AST ); 
															$$->push_back( $3 ); }
| OPENPAR PCDATA CLOSEPAR								{	$$ = new ElementAttList( ElementAttList::NONE ); 
															$$->push_back( new ElementAtt( std::string( "#PCDATA" ) ); }
;

list_mixed_plus
: list_mixed_plus PIPE IDENT							{	$$ = $1;
															$$->push_back( new ElementAtt( std::string($3) )); }
| PIPE IDENT											{	$$ = new ElementAttList( ElementAttList::PIPE );
															$$->push_back( new ElementAtt( std::string($2) )); }
;

children
: choice_or_seq card_opt								{	$$ = new ElementAttList( $1 )) ; 
															$$->push_back( $2 ); }
;

card_opt
: QMARK 												{	$$ = ElementAttBase::QMARK; }
| PLUS													{	$$ = ElementAttBase::PLUS; }
| AST													{	$$ = ElementAttBase::AST; }
| /* vide */											{	$$ = ElementAttBase::NONE; }
;

choice_or_seq
: choice 												{	$$ = $1;	}
| seq													{	$$ = $1;	}
;

choice
: OPENPAR cp list_choice_plus CLOSEPAR					{	$$ = new ElementAttList( $3, ElementAttList::PIPE )) ; /*TODO $2 ???*/}
;

seq
: OPENPAR cp list_seq_opt CLOSEPAR						{	$$ = new ElementAttList( $3, ElementAttList::COMMA )) ; /*TODO $2 ???*/}
;

cp
: children 												{ 	$$ = $1; }
| IDENT card_opt										{	$$ = new ElementAttList( ElementAttList::NONE )) ;
															$$->push_back( new ElementAtt( std::string($1) ); }
;

list_choice_plus
: list_choice_plus PIPE cp								{	$$ = $1; 
															$$->push_back( $3 ); }
| PIPE cp												{	$$ = new ElementAttList( ElementAttList::PIPE )) ; 
															$$->push_back( $2 ) }
;

list_seq_opt
: list_seq_opt COMMA cp									{	$$ = $1; 
															$$->push_back( $3 ); }
| /* vide */											{	$$ = new ElementAttList( ElementAttList::COMMA ); }
;

%%

int main(int argc, char **argv)
{
	int err;
	
	dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	
	DtdDocument * dtdDocument;
	err = dtdparse( &dtdDocument );
	if (err != 0) printf("Parse ended with %d error(s)\n", err);
		else  printf("Parse ended with success\n", err);

	delete dtdDocument;

	return 0;
}

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


