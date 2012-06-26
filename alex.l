%{

#include <stdio.h>
#include <string.h>

#include "include/libtds.h"
#include "include/libgci.h"
#include "include/header.h"

#include "include/asin.h"

extern FILE *yyin;
extern int yydebug;

void creaNOmbre();
void creCentera();
void truncReal();


/*****************************************************************************/

%}

%option yylineno
digito [0-9] 
letra [a-zA-Z]
comm \/\/[^\n]*\n

mas [\+]
por [\*]
menos [\-]
div [\/]
gt [>]
lt [<]

asig [=]

parabr [\(]
parcer [\)]
llavabr [\{]
llavcer [\}]
corabr [\[]
corcer [\]]
puntoycoma [;]
punto [\.]
coma [,]
newline [\n]
tab [\x20\t]+

%%


{newline} {}
{tab} {}
{comm} {} //comentarios



{puntoycoma} {return(PUNTOYCOMA_);}
{punto} {return(PUNTO_);}
{coma} {return(COMA_);}

{parabr} {return(PARABR_);}
{parcer} {return(PARCER_);}
{llavabr} {return(LLAVABR_);}
{llavcer} {return(LLAVCER_);}
{corabr} {return(CORABR_);}
{corcer} {return(CORCER_);}

int {return(INT_);}
struct {return(STRUCT_);}
read {return(READ_);}
print {return(PRINT_);}
if {return(IF_);}
else {return(ELSE_);}
for {return(FOR_);}
return {return(RETURN_);}

{mas} {return(MAS_);}
{por} {return(POR_);}
{menos} {return(MENOS_);}
{div} {return(DIV_);}
{mas}{mas} {return(INCMAS_);}
{menos}{menos} {return(INCMENOS_);}

{asig} {return(ASIG_);}
{mas}{asig} {return(ASIGMAS_);}
{menos}{asig} {return(ASIGMENOS_);}

{asig}{asig} {return(IGUAL_);}
!{asig} {return(DIF_);}
{gt} {return(GT_);}
{gt}{asig} {return(GTE_);}
{lt} {return(LT_);}
{lt}{asig} {return(LTE_);}


{letra}({letra}|{digito})* {creaNombre(); return(ID_);} 
{digito}+ {creaCentera(); return(CTE_);} //constantes enteras
{digito}+{punto}{digito}+ {truncCreal(); return(CTE_);} 

. {printf("\nnorec %d -> %d", yytext[0], -1);} //caractero desconoscido

%%





int main (int argc, char **argv)
{
	char * nom_fich;
	int i, n = 0;
	for (i=0; i<argc; ++i) 
	{
		if (strcmp(argv[i], "-v")==0) 
		{ 
			verbosidad = TRUE; 
			n++; 
		}

		else if (strcmp(argv[i], "-t")==0) 
		{ 
			verTDS = TRUE; 
			n++; 
		}
	}

	--argc; 
	n++;

	if (argc == n) 
	{
		if ((yyin = fopen (argv[argc], "r")) == NULL)
		{
			fprintf (stderr, "Fichero no valido %s\n", argv[argc]);
		}
		else 
		{
			if (verbosidad == TRUE) 
			{
				fprintf(stdout,"%3d.- ", yylineno);
			}
			nom_fich = argv[argc];
			yyparse ();
			if (numErrores > 0)
			{
				fprintf(stdout,"\nNumero de errores: %d \n", numErrores);
			}
			else if (numErrores == 0)
			{
				vuelcaCodigo(nom_fich);
			}
			else
			{
				fprintf(stdout,"\nCheck your code man, got: %d no. of errors.\n", numErrores);
			}
		}
	}
	else fprintf (stderr, "Uso: cmc [-v] [-t] fichero\n");
}

void creaNombre()
/* Comprueba que el identificador no exceda la talla maxima (14); en ese */
/* caso, lo trunca. */
{ char *t;
	if (yyleng > 14) {
		fprintf(stdout,"Warning at line %d: identificador truncado a longitud %d\n",yylineno, 14);
		yyleng=14;
	}
	t = (char *)malloc(yyleng+1); strncpy(t, yytext, yyleng);
	t[yyleng] = '\0'; 
	yylval.ident = t;
}

/* Transforma una subcadena a la constante entera que representa */
void creaCentera()
{ yylval.cent = atoi(yytext); }

void truncCreal()
/* Transforma una subcadena, que representa una constante real, a una */
/* constante entera truncandola. */
{ char *t;
fprintf(stdout,
"\nWarning at line %d: constante real truncada a entera\n", yylineno);
yyleng = strcspn(yytext,".");
t = (char *)malloc(yyleng+1); strncpy(t, yytext, yyleng);
t[yyleng] = '\0'; yylval.cent = atoi(t);
}
