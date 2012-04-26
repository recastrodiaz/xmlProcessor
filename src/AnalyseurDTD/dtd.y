%{
#include <string>
#include <list>
#include <cstring>


#include "../commun.h"

#include "../DTDClass/AttDef.h"
#include "../DTDClass/AttList.h"
#include "../DTDClass/DtdBalise.h"
#include "../DTDClass/DtdDocument.h"
#include "../DTDClass/DtdElement.h"
#include "../DTDClass/ElementAtt.h"
#include "../DTDClass/ElementAttBase.h"
#include "../DTDClass/ElementAttList.h"

extern FILE* dtdin;
void dtderror( DtdDocument * dtdDocument, char *msg );
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
	char * s; 
	DtdBalise * tDtdBalise;
	std::list<AttDef *> * tAttDefList;
	ElementAttBase * tElementAttBase;
	std::list<std::string> * tListAttType; 
	std::list<DtdBalise *> * tListDtdBalise;
	ElementAtt * tElementAtt;
	AttDef * tAttDef;
	ElementAttList * tElementAttList;
	std::list<ElementAttBase * > * tListElementAttBase;
	ElementAttBase::Cardinality tCard; 
	std::list<ElementAttBase *> * tListOfElementAttBase;
}

%parse-param { DtdDocument * dtdDocument }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING

%type <tListDtdBalise> dtd_list_opt
%type <tAttDefList> att_definition_opt
%type <tAttDef> attribute
%type <s> att_type
/* Commente car la grammaire DTD est simplifiee
%type <s> enumerate 
%type <tListAttType> enum_list_plus
%type <tListAttType> enum_list
%type <s> item_enum 
//*/
%type <tDtdBalise> elementspec
%type <tElementAttBase> contentspec
%type <tElementAttList> mixed
%type <tElementAttBase> children
%type <tElementAttList> list_mixed_plus
%type <tCard> card_opt
%type <tElementAttBase> choice_or_seq
%type <tElementAttBase> choice
%type <tElementAttBase> seq
%type <tElementAttBase> cp
%type <tListOfElementAttBase> list_choice_plus
%type <tListOfElementAttBase> list_seq_opt
%type <s> default_declaration
%%

// Axiome de la grammaire
main 														// On appelle la methode setBalises avec l'argument <dtd_list_opt>
: dtd_list_opt											{ 	dtdDocument->setBalises( $1 ); }
;

// Liste des balises d'une DTD, eventuellement vide
dtd_list_opt												// On met a jour la reference sur dtd_list_opt
: dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE	{	$$ = $1;
															// On construit une nouvelle liste d'attribut avec comme parametres <IDENT> construit en std::string et <att_definition_opt>
															AttList * attList = new AttList( std::string($3), $4 );
															// On l'ajoute a la liste des balises DTD
															$$->push_back( attList ); 
															free($3);	}
															// On met a jour la reference sur dtd_list_opt
| dtd_list_opt elementspec								{ 	$$ = $1;
															// On ajoute <elementspec> a la liste des balises DTD
															$$->push_back( $2 ); }
															// On cree une liste de balises DTD vide -> fin de recursivite
| /* empty */											{	$$ = new std::list<DtdBalise *>(); }
;

// Liste d'attribut d'une balise DTD
att_definition_opt											// On met a jour la reference sur att_definition_opt
: att_definition_opt attribute							{	$$ = $1; 
															// On ajoute l'attribut <attribute> a la liste des attributs de la balise
															$$->push_back( $2 ); }
															// On cree une liste d'attributs vide -> fin de recursivite
| /* empty */											{	$$ = new std::list<AttDef *>(); }
;

// Definition d'un attribut
attribute													// <attribute> est construit par l'appel a AttDef
: IDENT att_type default_declaration					{ 	$$ = new AttDef( std::string($1), std::string($2), std::string($3) ); 
															free( $1 );
															free( $2 );
															free( $3 );		}
;

// Type d'un attribut <attribute>
att_type													// Dans le cas de CDATA, <att_type> va valoir "CDATA"
: CDATA    												{	char * str = (char*)malloc( 5 + 1 );
															strcpy( str, "CDATA"); 
															$$ = str; }
															// On affecte TOKENTYPE a <att_type>
| TOKENTYPE												{	$$ = $1; }
/*| enumerate												 N'est jamais utilisé */
;

// Definition des declarations par defaut
default_declaration											// <default_declaration> prend la valeur de DECLARATION
: DECLARATION											{	$$ = $1;	}
															// <default_declaration> prend la valeur de STRING
| STRING     											{	$$ = $1;	}
															// On construit la chaine de caractere suivante: "FIXED " + STRING
| FIXED STRING 											{	char * str = (char*)malloc( 7 + strlen($2) + 1);
															strcpy( str, "#FIXED ");
															strcat( str, $2 );
															// On affecte str a <default_declaration>
															$$ = str;
															// On vide la memoire
															free($2);}
;


/* 
// N'est pas utilise en raison de la simplification de la DTD.
// Commente pour eviter les conflits et permettre la compilation.
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

item_enum
: IDENT
;
//*/

// Definition d'une balise <!ELEMENT>
elementspec													// On construit un element de DTD
: ELEMENT IDENT contentspec CLOSE						{	DtdElement * element = new DtdElement( std::string($2), $3 );
															// On ajoute l'element dans la liste composant le document DTD
															dtdDocument->addElementByName( std::string($2), element ); 
															// <elementspec> prend pour valeur l'element construit
															$$ = element;
															free( $2 );		}
;

// Definition du contenu
contentspec													// <contentspec> va etre construit comme un ElementAtt avec "EMPTY"
: EMPTY													{	$$ = new ElementAtt( std::string( "EMPTY" ) ); }
															// <contentspec> va etre construit comme un ElementAtt avec "ANY"
| ANY													{	$$ = new ElementAtt( std::string( "ANY" ) ); }
															// <contentspec> prend la valeur de <mixed>
| mixed													{	$$ = $1; }
															// <contentspec> prend la valeur de <children>
| children												{	$$ = $1; }
;

// Definition d'un contenu de type 'mixed'
mixed
: OPENPAR PCDATA list_mixed_plus CLOSEPAR AST			{	// On definit la cardinalite C_AST pour <mixed>
															$$->setCardinality( ElementAttList::C_AST ); }
															// On construit <mixed> comme une liste d'element de cardinalite nulle
| OPENPAR PCDATA CLOSEPAR								{	$$ = new ElementAttList( ElementAttList::A_NONE ); 
															// On ajoute a <mixed> un nouvel ElementAtt "PCDATA"
															$$->push_back( new ElementAtt( std::string( "#PCDATA" ) )); }
;

// Definition d'une liste de contenu <mixed>
list_mixed_plus												// <list_mixed_plus> est mis a jour
: list_mixed_plus PIPE IDENT							{	$$ = $1;
															// On ajoute un nouvel ElementAtt a la liste de contenu mixte
															$$->push_back( new ElementAtt( std::string($3) ));
															free( $3 ); }
															// <list_mixed_plus> est construit comme un nouvel ElementAttList avec une aggregation de type PIPE
| PIPE IDENT											{	$$ = new ElementAttList( ElementAttList::A_PIPE );
															// On ajoute un nouvel ElementAtt d'identifiant <IDENT> a la liste <list_mixed_plu>
															$$->push_back( new ElementAtt( std::string($2) )); 
															free( $2 );	}
;

// Definition d'un contenu de type 'children'
children													// <children> prend la valeur <choice_or_seq>
: choice_or_seq card_opt								{	$$ = $1 ;
															// On definit la cardinalite de <children> a la valeur <card_opt>
															$$->setCardinality( $2 );  }
;

// Definition de l'information de cardinalite
// Le principe est toujours le meme: <card_opt> est definit par une valeur de l'enum de cardinalite de la classe ElementAttBase
card_opt
: QMARK 												{	$$ = ElementAttBase::C_QMARK; }
| PLUS													{	$$ = ElementAttBase::C_PLUS; }
| AST													{	$$ = ElementAttBase::C_AST; }
| /* vide */											{	$$ = ElementAttBase::C_NONE; }
;

// Definition du type d'aggregation
// <choice_or_seq> prend la valeur adequate pour chaque cas
choice_or_seq
: choice 												{	$$ = $1;	}
| seq													{	$$ = $1;	}
;

// Definition d'une aggregation de type choix
choice
: OPENPAR cp list_choice_plus CLOSEPAR					{	// Cast dynamique de <cp> en ElementAttList*
															ElementAttList * attList = dynamic_cast<ElementAttList*>($2);
															if( !attList )
															{
																// On cree la liste d'attribut sous forme d'aggregation avec pipe
																attList = new ElementAttList( ElementAttList::A_PIPE ) ;
																// On ajoute <cp> a cette liste
																attList->push_back( $2 );
															}
															// On va parcourir <liste_choice_plus> pour ajouter chaque element dans la liste des attributs
															std::list<ElementAttBase *>::iterator it = $3->begin();
															for( ; it != $3->end(); it++)
															{
																attList->push_back( *it );
															}
															// <choice> prend la valeur de attList
															$$ = attList;
														}
;

// Definition d'une sequence
seq
: OPENPAR cp list_seq_opt CLOSEPAR						{	// Si <list_seq_opt> est vide
															if( $3->empty() )
															{
																// <seq> prend la valeur de <cp>
																$$ = $2;
															}
															else
															{
																// Cast dynamique de <cp> en ElementAttList*
																ElementAttList * attList = dynamic_cast<ElementAttList*>($2);
																if( !attList )
																{
																	// On cree la liste d'attribut sous forme d'aggregation avec virgule
																	attList = new ElementAttList( ElementAttList::A_COMMA ) ;
																	// On ajoute <cp> a cette liste
																	attList->push_back( $2 );
																}
																// On va ajouter chaque element de <list_seq_opt> dans la liste
																std::list<ElementAttBase *>::iterator it = $3->begin();
																for( ; it != $3->end(); it++)
																{
																	attList->push_back( *it );
																}
																// <seq> est mis a jour pour correspondre a la liste
																$$ = attList;
															}
															// Appel au destructeur de ElementAttList pour <list_seq_opt>
															delete $3;
														}
;

// Definition d'une partie de contenu
cp															// <cp> est mis a jour avec la valeur de <children>
: children 												{ 	$$ = $1; }
| IDENT card_opt										{	// Initialisation d'un nouvel ElementAtt avec pour valeur <IDENT>
															ElementAtt * e = new ElementAtt( std::string($1) );
															// Reglage de la cardinalite <card_opt>
															e->setCardinality( $2 );
															// Mise a jour de <cp> avec le nouvel element
															$$ = e;
															free( $1 );
														}
;

// Definition d'une liste de choix
list_choice_plus											// <list_choice_plus> est mis a jour
: list_choice_plus PIPE cp								{	$$ = $1; 
															// Ajout de <cp> a <list_choice_plus>
															$$->push_back( $3 ); }
															// <list_choice_plus> est initialise a une liste d'ElementAttBase vide
| PIPE cp												{	$$ = new std::list<ElementAttBase *>() ; 
															// Ajout de <cp> dans la liste d'ElementAttBase
															$$->push_back( $2 ); }
;

// Definition d'une liste optionnelle avec sequence
list_seq_opt												// Mise a jour de <liste_seq_opt>
: list_seq_opt COMMA cp									{	$$ = $1; 
															// Ajout de <cp> dans la liste
															$$->push_back( $3 ); }
															// Creation de la liste <liste_seq_opt> d'ElementAttBase -> fin de recursivite
| /* vide */											{	$$ = new std::list<ElementAttBase *>() ;  }
;

%%

int dtdwrap(void)
{
  return 1;
}

void dtderror( DtdDocument * dtdDocument, char *msg )
{
  fprintf(stderr, "%s\n", msg);
}


