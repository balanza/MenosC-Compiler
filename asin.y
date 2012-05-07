%{
#include <stdio.h>
#include "include/libtds.h"
#include "include/libgci.h"
extern int yylineno;
%}
/**************** Definiciones para la gestion de BISON **********************/
/*%token YYERROR_VERBOSE*/
/********** Tipos de datos para las declaraciones %token y %type *************/
%union
{
  char* ident;  /* Para los identificadores  */
  int cent;  /* Para constantes enteras */
  int op_rel;
}

%token  PUNTOYCOMA_ PUNTO_ COMA_ PARABR_ PARCER_ LLAVABR_ LLAVCER_
CORABR_ CORCER_ INT_ STRUCT_ READ_ PRINT_ IF_ ELSE_ FOR_ RETURN_ MAS_ POR_
MENOS_ DIV_ INCMAS_ INCMENOS_ ASIG_ ASIGMAS_ ASIGMENOS_ IGUAL_ DIF_ GT_ GTE_ LT_
LTE_
%token <ident> ID_
%token <cent> CTE_

%%
programa: 
	{
		nivel = 0;
		
		dvar = 0;
		cargaContexto(nivel);
	}
secuenciaDeclaraciones
	{
		descargaContexto(nivel);
	}
;
secuenciaDeclaraciones: declaracion
  | secuenciaDeclaraciones declaracion
;
declaracion: declaracionVariable
  | declaracionFuncion
;
declaracionVariable: tipo ID_ PUNTOYCOMA_ 
	{
		printf("\ndeclarando var %s", $2);
		insertaSimbolo($2, VARIABLE, T_ENTERO, dvar, nivel, -1);
		dvar += TALLA_ENTERO;
	
	}
  | tipo ID_ CORABR_ CTE_ CORCER_ PUNTOYCOMA_
;
tipo: INT_
  | STRUCT_ LLAVABR_ listaCampos LLAVCER_
;
listaCampos: declaracionVariable
  | listaCampos declaracionVariable
;
declaracionFuncion: cabeceraFuncion bloque 
	{
		descargaContexto(nivel);
		nivel--;
		dvar = old_dvar;
	}
;
cabeceraFuncion: tipo ID_ PARABR_ 
	{
		nivel++;
		cargaContexto(nivel);
		dpar = 0;
		old_dvar = dvar;
		dvar = 0;
	} 
	parametrosFormales PARCER_
;
parametrosFormales: 
  | listaParametrosFormales
;
listaParametrosFormales: tipo ID_ 
  	{
  		//RECUERDA: codigo duplicado
  		printf("\ndeclarando parametro %s", $2);
		insertaSimbolo($2, VARIABLE, T_ENTERO, -dpar, nivel, -1);
		dpar += TALLA_ENTERO;
  	}
  | tipo ID_ 
  	{
  		//RECUERDA: codigo duplicado
  		printf("\ndeclarando parametro %s", $2);
		insertaSimbolo($2, VARIABLE, T_ENTERO, -dpar, nivel, -1);
		dpar += TALLA_ENTERO;
  	}
  	COMA_ listaParametrosFormales
;
bloque: LLAVABR_ declaracionVariableLocal listaInstrucciones LLAVCER_
;
declaracionVariableLocal:
  | declaracionVariableLocal declaracionVariable
;
listaInstrucciones: 
  | listaInstrucciones instruccion
;
instruccion: 
	{
		nivel++;
		cargaContexto(nivel);
	}
	LLAVABR_ declaracionVariableLocal listaInstrucciones LLAVCER_
	{
		nivel--;
		descargaContexto(nivel);
	}
  | instruccionExpresion
  | instruccionEntradaSalida
  | instruccionSeleccion
  | instruccionIteraccion
  | instruccionSalto
;
instruccionExpresion: PUNTOYCOMA_
 | expresion PUNTOYCOMA_
;
instruccionEntradaSalida: READ_ PARABR_ ID_ PARCER_ PUNTOYCOMA_
  | PRINT_ PARABR_ expresion PARCER_ PUNTOYCOMA_
;
instruccionSeleccion: IF_ PARABR_ expresion PARCER_ instruccion ELSE_ instruccion
;
instruccionIteraccion: FOR_ PARABR_ expresionOpcional PUNTOYCOMA_ expresion PUNTOYCOMA_ expresionOpcional PARCER_ instruccion
;
expresionOpcional: 
  | expresion
;
instruccionSalto: RETURN_ expresion PUNTOYCOMA_
;
expresion: expresionIgualdad
  | ID_ operadorAsignacion expresion
  | ID_ CORABR_ expresion CORCER_ operadorAsignacion expresion
  | ID_ PUNTO_ ID_ operadorAsignacion expresion
;
expresionIgualdad: expresionRelacional
  | expresionIgualdad operadorIgualdad expresionRelacional
;
expresionRelacional: expresionAditiva
  | expresionRelacional operadorRelacional expresionAditiva
;
expresionAditiva: expresionMultiplicativa
  | expresionAditiva operadorAditivo expresionMultiplicativa
;
expresionMultiplicativa: expresionUnaria
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria
;
expresionUnaria: expresionSufija
  | operadorUnario expresionUnaria
  | operadorIncremento ID_
;
expresionSufija: ID_ CORABR_ expresion CORCER_
  | ID_ PUNTO_ ID_
  | ID_ operadorIncremento
  | ID_ PARABR_ parametrosActuales PARCER_ 
  | PARABR_ expresion PARCER_
  | ID_ {
  			SIMB sss = obtenerSimbolo($1);
  			
  			//printf("\n\n%d\n\n", sss.categoria);
	  		if(sss.categoria!=NULO){ 
	  			printf("\n variable ya declarada %s", $1);
	  		}else{//la variable no està declarada todavia
	  			printf("\n variable NO declarada todavia %s", $1);
	  		}
  		}
  | CTE_ {printf("\n valor: %d", $1);}
;
parametrosActuales:
  | listaParametrosActuales
;
listaParametrosActuales: expresion
  | expresion COMA_ listaParametrosActuales
;
operadorAsignacion: ASIG_
  | ASIGMAS_
  | ASIGMENOS_
;
operadorIgualdad: IGUAL_
  DIF_
;
operadorRelacional: GT_
  | GTE_
  | LT_
  | LTE_
;
operadorAditivo: MAS_
  | MENOS_
;
operadorMultiplicativo: POR_
  | DIV_
;
operadorIncremento: INCMAS_
  | INCMENOS_
;
operadorUnario: MAS_
  | MENOS_
;
%%


/* Llamada por yyparse ante un error */
yyerror (char *s)
{
printf ("Linea %d: %s\n", yylineno, s);
}
