%{
#include "../commun.h"
using namespace std;
extern FILE* dtdin;
void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
	char * tS; 
	std::string tString;
	std::list<AttDef > * tAttDefList;
	ElementAttBase * tElementAttBase;
	std::list<std::string> * tListAttType; 
	std::list<DtdBalise *> * tListDtdBalise;
	ElementAtt * tElementAtt;
	AttDef tAttDef;
	ElementAttBase * tElementAttBase;
	ElementAttList * tElementAttList;
	std::list<ElementAttBase * > * tListElementAttBase;
	ElementAttBase::Cardinality tCard; 
}

%parse-param { DtdDocument ** dtdDocument }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <tS> IDENT TOKENTYPE DECLARATION STRING

%type <tAttDefList> att_definition_opt
%type <tAttDef> attribute
%type <tListAttType> att_type
%type <tListAttType> enumerate
%type <tListAttType> enum_list_plus
%type <tListAttType> enum_list
%type <tString> item_enum
%type <tDtdBalise> dtd_list_opt
%type <tElementAtt> elementspec
%type <tElementAttBase> contentspec
%type <tElementAttList> mixed
%type <tElementAttList> children
%type <tListElementAttBase> list_mixed_plus
%type <tCard> card_opt
%type <tListElementAttBase> choice_or_seq
%type <tElementAttList> cp
%type <tElementAttList> liste_choice_plus
%type <tString> default_declaration
%%

main 
: dtd_list_opt											{ 	* dtdDocument = new DtdDocument( $1 ); }
;

dtd_list_opt
: dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE	{	$$ = $1;
															$$->push_back( AttList($3, $5 )); }
| dtd_list_opt elementspec								{ 	$$ = $1;
															$$->push_back( $2 ); }
| /* empty */
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
															$$->push_back( std::string($1) ); }
| TOKENTYPE												{	$$ = new std::list<std::string>();
															$$->push_back( std::string($1) ); }
| enumerate												{	$$ = $1; }
;

default_declaration
: DECLARATION											{	$$ = std::string($1);	}
| STRING     											{	$$ = std::string($1);	}
| FIXED STRING 											{	std::string str($1);
															str += $2;
															$$ = str; }
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
: EMPTY													{	$$ = new ElementAtt( std::string( $1 ) ); }
| ANY													{	$$ = new ElementAtt( std::string( $1 ) ); }
| mixed													{	$$ = $1; }
| children
;

mixed
: OPENPAR PCDATA list_mixed_plus CLOSEPAR AST			{	$$ = new ElementAttList( $3, ElementAttList::NONE ); }
| OPENPAR PCDATA CLOSEPAR								{	std::list<ElementAttBase * > * mixedList = new std::list<ElementAttBase *>();
															mixedList->push_back( new ElementAtt( std::string( $2 ) );
															$$ = new ElementAttList( mixedList, ElementAttList::NONE ); }
;

list_mixed_plus
: list_mixed_plus PIPE IDENT							{	$$ = $1;
															$$->push_back( new ElementAtt( ElementAttList::PIPE, std::string($3) )); }
| PIPE IDENT											{	$$ = new ElementAttList();
															$$->push_back( ElementAttList::PIPE, ElementAttList::NONE, std::string($2) ); }
;

children
: choice_or_seq card_opt								{	$$ = new ElementAttList( $2, $1 )) ; }
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
: OPENPAR cp liste_choice_plus CLOSEPAR
;

seq
: OPENPAR cp liste_seq_opt CLOSEPAR
;

cp
: children 												{ 	$$ = $1; }
| IDENT card_opt										{	std::list<ElementAttBase *> * cpList = new std::list<ElementAttBase *>();
															cpList->push_back( new ElementAtt( std::string($1) ));
															$$ = new ElementAttList( cpList, $2 )) ; }
;

liste_choice_plus
: liste_choice_plus PIPE cp								{	$$ = $1; 
															$$->push_back( $3, ElementAttList::PIPE ); }
| PIPE cp												{	$$ = new ElementAttList( $2, $1 )) ; }
;

liste_seq_opt
: liste_seq_opt COMMA cp								{	$$ = $1; 
															$$->push_back( $3, ElementAttList::COMMA ); }
| /* vide */											{	$$ = new ElementAttList(); }
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


