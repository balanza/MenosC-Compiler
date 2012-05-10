%{
#include <stdio.h>
#include "include/libtds.h"
#include "include/libgci.h"
extern int yylineno;

/**************** Variables globales **********************/
int old_dvar;              /* Desplazamiento en el Segmento de Variables  */
int dpar;              /* Desplazamiento en el Segmento de Parametros de funcion  */
int nivel; 			   /* Nivel de anidamiento */

%}
/**************** Definiciones para la gestion de BISON **********************/
/*%token YYERROR_VERBOSE*/
/********** Tipos de datos para las declaraciones %token y %type *************/
%union
{
  char* ident;  /* Para los identificadores  */
  int cent;  /* Para constantes enteras */
  int op_rel;
  struct tipo_def /* Estructura para una descricion de tipo */
	{
	  int talla;                            
	  int tipo;  
	  int ref;                          
	} tdef;
	struct exp_def{
		int tipo;
		int val;
	} expdef;
}

%token  PUNTOYCOMA_ PUNTO_ COMA_ PARABR_ PARCER_ LLAVABR_ LLAVCER_
CORABR_ CORCER_ INT_ STRUCT_ READ_ PRINT_ IF_ ELSE_ FOR_ RETURN_ MAS_ POR_
MENOS_ DIV_ INCMAS_ INCMENOS_ ASIG_ ASIGMAS_ ASIGMENOS_ IGUAL_ DIF_ GT_ GTE_ LT_
LTE_
%token <ident> ID_
%token <cent> CTE_
%type <tdef> tipo
%type <tdef> declaracionVariable
%type <tdef> listaCampos
%type <tdef> cabeceraFuncion
%type <tdef> declaracionFuncion
%type <tdef> parametrosFormales
%type <tdef> listaParametrosFormales

%type <expdef> expresion

%%
programa: 
	{
		nivel = 0;		
		dvar = 0;
		si = 0;
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
declaracion: declaracionVariable {mostrarTDS(nivel);}
  | declaracionFuncion
;
declaracionVariable: tipo ID_ PUNTOYCOMA_ 
	{
		printf("\ndeclarando var %s", $2);
		if(!insertaSimbolo($2, VARIABLE, $1.tipo, dvar, nivel, -1)){
			yyerror("---> identificador repetido");
		}
		//mostrarTDS(nivel);
		dvar += $1.talla; // update shift
		
		$$.talla = $1.talla; // moviendo hacia 
		$$.tipo = $1.tipo;   //  arriba los valores
	}
  | tipo ID_ CORABR_ CTE_ CORCER_ PUNTOYCOMA_
  {
  	printf("\n cte: %d", $4);
  	if($1.tipo!=T_ENTERO){
		yyerror("el tipo de los vectores tiene que ser int");
	} else if($4<=0){
		yyerror("el array debe contener un numero positivo de elementos");
	} else {
		printf("\ndeclarando array %s", $2);
		if(!insertaSimbolo($2, VARIABLE, T_ARRAY, dvar, nivel, -1)){
			yyerror("---> identificador repetido");
		}
		//mostrarTDS(nivel);
		dvar += $4 * $1.talla; // update shift
		
		$$.talla = $4 * $1.talla; // moviendo hacia 
		$$.tipo = $1.tipo;   //  arriba los valores
	}
	
	
  }
;
tipo: INT_ 
	{
		$$.talla = TALLA_ENTERO;
		$$.tipo = T_ENTERO;
	}
  | STRUCT_ LLAVABR_ listaCampos LLAVCER_
  	{
  		$$.talla = $3.talla;
  		$$.tipo = T_RECORD;
  	}
;
listaCampos: declaracionVariable 
	{
		if(!$1.tipo==T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		}
		$$.talla = $1.talla;
	}
  | listaCampos declaracionVariable
	{
		if(!$2.tipo==T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		}
		$$.talla += $2.talla;
	}
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
		if($1.tipo!=T_ENTERO){
  			yyerror("la funcion tiene que ser de tipo int");
  		}
		nivel++;
		cargaContexto(nivel);
		dpar = 0;
		old_dvar = dvar;
		dvar = 0;
	} 
	parametrosFormales  PARCER_
	{
		$$.tipo = $1.tipo;
		$$.ref = -1;//$4.ref;
	}	
;
parametrosFormales: {$$.ref = -1;}
  | listaParametrosFormales {$$.ref = $1.ref;}
;
listaParametrosFormales: tipo ID_ 
  	{
  		if($1.tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		printf("\ndeclarando parametro %s", $2);
			if(!insertaSimbolo($2, VARIABLE, T_ENTERO, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += TALLA_ENTERO;
				$$.ref = insertaInfoDominio(-1, $1.tipo);
			}
		}
  	}
  | tipo ID_ COMA_ listaParametrosFormales   	
  	{
  		if($1.tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		if(!insertaSimbolo($2, VARIABLE, T_ENTERO, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += TALLA_ENTERO;
			}
			$$.ref = insertaInfoDominio($$.ref, $1.tipo);
		}
  	} 
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
expresion: expresionIgualdad //TODO: PASAR VALORES
	{
		$$.tipo = NULL;
		$$.val = NULL;
	}
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
  			
	  		if(sss.categoria==NULO){ 
	  			yyerror("\n variable NO declarada todavia");
	  		}
  		}
  | CTE_ 
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
