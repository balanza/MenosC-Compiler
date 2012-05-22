%{
#include <stdio.h>
#include "include/libgci.h"
#include "include/libtds.h"
extern int yylineno;

/**************** Variables globales **********************/
int old_dvar;              /* Desplazamiento en el Segmento de Variables  */
int dpar;              /* Desplazamiento en el Segmento de Parametros de funcion  */
int dcmp;              /* Desplazamiento del campo en una estructura  */
int nivel; 			   /* Nivel de anidamiento */
/************************************* Codigos para los distintos operadores */
#define DISTINTO      0
#define IGUAL         1
#define MAYOR         2
#define MENOR         3
#define MAYORIG       4
#define MENORIG       5
#define POR           6
#define DIV           7
#define MAS           8
#define MENOS         9
#define ASIG         10
#define MASASIG      11
#define MENOSASIG    12
#define MASMAS       13
#define MENOSMENOS   14 
/******************************************* Tallas de los tipos y segmentos */
#define TALLA_ENTERO     1
#define TALLA_SEGENLACES 2       /* Talla del segmento de Enlaces de Control */

%}
/**************** Definiciones para la gestion de BISON **********************/
/*%token YYERROR_VERBOSE*/
/********** Tipos de datos para las declaraciones %token y %type *************/
%union
{
  char* ident;  
  /* Para los identificadores  */
  int cent;  /* Para constantes enteras */
  int operador;
  struct tipo_def /* Estructura para una descricion de tipo */
	{
	  int talla;                            
	  int tipo;  
	  char* id;
	  int ref;                          
	} tdef;
    TIPO_ARG expdef; 
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
%type <expdef> expresionSufija
%type <expdef> expresionIgualdad
%type <expdef> expresionOpcional
%type <expdef> expresionRelacional
%type <expdef> expresionAditiva
%type <expdef> expresionMultiplicativa
%type <expdef> expresionUnaria

%type <operador> operadorAsignacion
%type <operador> operadorIgualdad
%type <operador> operadorRelacional
%type <operador> operadorAditivo
%type <operador> operadorMultiplicativo
%type <operador> operadorIncremento
%type <operador> operadorUnario

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
		vuelcaCodigo("codigo");
	}
;
secuenciaDeclaraciones: declaracion
  | secuenciaDeclaraciones declaracion 
  	{
		//mostrarTDS(nivel);
	}
;
declaracion: declaracionVariable 
	{
		printf("\ndeclarando var %s", $1.id);
		if(!insertaSimbolo($1.id, VARIABLE, $1.tipo, dvar, nivel, $1.ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += $1.talla; // update shift
		}
		
	}
  | declaracionFuncion 
	{
		printf("\ndeclarando func %s", $1.id);
		if(!insertaSimbolo($1.id, FUNCION, $1.tipo, dvar, nivel, $1.ref)){
			yyerror("---> funcion repetida");
		} else {
			dvar += $1.talla; // update shift
		}
		
	}
;
declaracionVariable: tipo ID_ PUNTOYCOMA_ 
	{
		$$.id = $2;
		$$.tipo = $1.tipo; 
		$$.talla = $1.talla;
		$$.ref = $1.ref;
		printf("\nINFO VAR: tipo: %d, nombre: %s", $1.tipo, $2);
	}
  | tipo ID_ CORABR_ CTE_ CORCER_ PUNTOYCOMA_
  {
  	//printf("\n cte: %d, tipo: %d", $4, $1.tipo);
  	if($1.tipo!=T_ENTERO){
		yyerror("el tipo de los vectores tiene que ser int");
	} else if($4<=0){
		yyerror("el array debe contener un numero positivo de elementos");
	} else {	
		$$.id = $2;
		$$.tipo = T_ARRAY;
		$$.talla = 1; // ???
		$$.ref = insertaInfoArray($1.tipo, $4);	
	}
	
	
	
  }
;
tipo: INT_ 
	{
		$$.talla = TALLA_ENTERO;
		$$.tipo = T_ENTERO;
		$$.ref = -1;
	}
  | STRUCT_ LLAVABR_ listaCampos LLAVCER_
  	{
  		$$.talla = $3.talla;
  		$$.tipo = T_RECORD;
  		$$.ref = $3.ref;
  	}
;
listaCampos: declaracionVariable
	{
		printf("\ndeclarando campo %s", $1.id);
		if($1.tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else if($$.ref=insertaInfoCampo(-1, $1.id, $1.tipo, 0) == -1){
			yyerror("error en la declaracion de campo de la estructura");
		}
		dcmp = $1.talla;
	}
  | listaCampos declaracionVariable  	
	{
		printf("\ndeclarando campo %s, ref %d", $2.id, $1.ref);
		if($2.tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else if($$.ref=insertaInfoCampo($1.ref, $2.id, $2.tipo, dcmp)==-1){
			yyerror("error en la declaracion de campo de la estructura");
		}
		dcmp += $2.talla;
	}
;
declaracionFuncion: cabeceraFuncion bloque 
	{
		descargaContexto(nivel);
		nivel--;
		dvar = old_dvar;
		
		$$.tipo = $1.tipo;
		$$.ref = $1.ref;
		$$.id = $1.id;
		$$.talla = $1.talla;
	}
;
cabeceraFuncion: tipo ID_ PARABR_ 
	{
		if($1.tipo!=T_ENTERO){
  			yyerror("la funcion tiene que ser de tipo int");
  			//TODO: parar ejecucion
  		} 
  		
  			nivel++;
			cargaContexto(nivel);
			dpar = TALLA_SEGENLACES;
			old_dvar = dvar;
			dvar = 0;
  		
		
	} 
	parametrosFormales  PARCER_
	{
	
		$$.tipo = $1.tipo;
		$$.ref = $5.ref;
		$$.id = $2;
		$$.talla = $1.talla;		
	}	
;
parametrosFormales: 
	{
		$$.ref = insertaInfoDominio(-1, T_VACIO);
	}
  | listaParametrosFormales 
  	{
  		$$.ref = $1.ref;
  	}
;
listaParametrosFormales: tipo ID_ 
  	{
  		if($1.tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		printf("\ndeclarando parametro (a) %s", $2);
			if(!insertaSimbolo($2, PARAMETRO, $1.tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += $1.talla;
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
	  		printf("\ndeclarando parametro (b) %s", $2);
	  		if(!insertaSimbolo($2, PARAMETRO, $1.tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += $1.talla;
			}
			$$.ref = insertaInfoDominio($4.ref, $1.tipo);
			mostrarTDS(nivel);
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
	{
		$$.val.i = 0;
	}
  | expresion
  	{
  		$$.val = $1.val;
  	}
;
instruccionSalto: RETURN_ expresion PUNTOYCOMA_
;
expresion: expresionIgualdad 
	{
		$$.val = $1.val;
	}
  | ID_ operadorAsignacion expresion
  	{
  		$$.val = $3.val;
  		
  		SIMB sim;
		sim = obtenerSimbolo($1);
		if (sim.categoria == NULO){
			yyerror("Identificador no declarado");
		}
		if ((sim.tipo==$3.tipo)&&(sim.tipo==T_ENTERO)){ 
			$$.tipo = T_ENTERO;
		}
		else {
		
			if (($3.tipo!=T_ERROR)&&(sim.tipo!=T_ERROR)){
				yyerror("Error de tipos en la asignacion de la ((expresion))");
			}
			$$.tipo=T_ERROR;
		}
		
  		
  		
  	}
  | ID_ CORABR_ expresion CORCER_ operadorAsignacion expresion
  	{
  		$$.val = $6.val;
  	}
  | ID_ PUNTO_ ID_ operadorAsignacion expresion
  	{
  		$$.val = $5.val; //TODO; añadir switch for operadores de asignacion
  	}
;
expresionIgualdad: expresionRelacional
  	{
  		$$.val = $1.val;
  	}
  | expresionIgualdad operadorIgualdad expresionRelacional
   	{
   		//TODO: TEST XOR
   		int x = (($1.val.i == $3.val.i) ^ $2==IGUAL); //TODO: COMPROBAR VALORES DE POSICIONES
   		/*
   			x es cierta si:
   				- el operador es de igualdad y los valores son iguales
   				- el operador es de no-igualidad y los valores son distintos
   			sino, x es falso
   		*/
   		printf("\n XOR v1: %d, v2: %d, op: %d, res: %d", $1.val.i, $3.val.i, $2, x);
   		$$.val.i = x;  		
  	}
;
expresionRelacional: expresionAditiva
	{
		$$.val = $1.val;
	}
  | expresionRelacional operadorRelacional expresionAditiva
  	{
  		switch($2){
  			case MAYOR:
  				$$.val.i = ($1.val.i > $3.val.i);
  				break;
  			case MENOR:
  				$$.val.i = ($1.val.i < $3.val.i);
  				break;
  			case MAYORIG:
  				$$.val.i = ($1.val.i >= $3.val.i);
  				break;
  			case MENORIG:
  				$$.val.i = ($1.val.i <= $3.val.i);
  				break;
  			default:
  				yyerror("Operador relacional desconocido");
  		}
  	}
;
expresionAditiva: expresionMultiplicativa
	{
		$$.val = $1.val;
	}
  | expresionAditiva operadorAditivo expresionMultiplicativa
  	{
  		switch($2){
  			case MAS:
  				$$.val.i = $1.val.i + $3.val.i;
  				break;
  			case MENOS:
  				$$.val.i = $1.val.i - $3.val.i;
  				break;
  			default:
  				yyerror("Operador aditivo desconocido");
  		}
  	}
;
expresionMultiplicativa: expresionUnaria
	{
		$$.val = $1.val;
	}
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria
  	{
  		switch($2){
  			case POR:
  				$$.val.i = $1.val.i * $3.val.i;
  				break;
  			case DIV:
  				$$.val.i = $1.val.i / $3.val.i;
  				break;
  			default:
  				yyerror("Operador multiplicativo desconocido");
  		}
  	}
;
expresionUnaria: expresionSufija 
	{
		$$.val = $1.val;
	}
  | operadorUnario expresionUnaria
  	{
  		if($1 == MENOS){
  			$$.val.i = - $2.val.i;
  		} else {
  			$$.val.i = $2.val.i;
  		}
  	}
  | operadorIncremento ID_ 
  	{
  		 		
  		SIMB sim; 
  		TIPO_ARG res;
  		  		
		sim = obtenerSimbolo($2);
		/* comprobaciones semanticas */
		res = crArgPosicion(sim.nivel, sim.desp);
		$$ = crArgPosicion(nivel, creaVarTemp());		
		$$.tipo = T_ENTERO;
		/************************************** INCREMENTA o DECREMENTA 1 */
		emite($1, res, crArgEntero(1), res);
		/***************************************************** Asignacion */
		emite(EASIG, res, crArgNulo(), $$);
  	}
;
expresionSufija: ID_ CORABR_ expresion CORCER_
	{
		$$.val.i = -1;
	}
  | ID_ PUNTO_ ID_
  	{
  		$$.val.i = -1;
  	}
  | ID_ operadorIncremento
	{
		$$.val.i = -1; //valor de ID_
					//TODO: ID_ := ID_ + 1
		$$.tipo = T_ENTERO;
	}
  | ID_ PARABR_ parametrosActuales PARCER_ 
	{
		$$.val.i = -1; 
		//TODO: $$.tipo = tipo de la funcion
	}
  | PARABR_ expresion PARCER_
	{
		$$.val.i = $2.val.i;
		$$.tipo = $2.tipo;
	}
  | ID_ {
  			SIMB id = obtenerSimbolo($1);
  			
	  		if(id.categoria==NULO){ 
	  			yyerror("\n variable NO declarada todavia, primer uso");
	  		} else {
	  			
	  		}
	  		
	  		
	  		$$.tipo = id.tipo;
  		}
  | CTE_ 
  	{
  		$$.val.i = $1;
  		$$.tipo = T_ENTERO;
  	}
;
parametrosActuales:
  | listaParametrosActuales
;
listaParametrosActuales: expresion
  | expresion COMA_ listaParametrosActuales
;
operadorAsignacion: ASIG_
	{
		$$ = ASIG;
	}
  | ASIGMAS_
	{
		$$ = MASASIG;
	}
  | ASIGMENOS_
	{
		$$ = MENOSASIG;
	}
;
operadorIgualdad: IGUAL_
	{
		$$ = IGUAL;
	}
  | DIF_
	{
		$$ = DISTINTO;
	}
;
operadorRelacional: GT_
	{
		$$ = MAYOR;
	}
  | GTE_
	{
		$$ = MAYORIG;
	}
  | LT_
	{
		$$ = MENOR;
	}
  | LTE_
	{
		$$ = MENORIG;
	}
;
operadorAditivo: MAS_
	{
		$$ = MAS;
	}
  | MENOS_
	{
		$$ = MENOS;
	}
;
operadorMultiplicativo: POR_
	{
		$$ = POR;
	}
  | DIV_
	{
		$$ = DIV;
	}
;
operadorIncremento: INCMAS_
	{
		$$ = ESUM;//MASMAS;
	}
  | INCMENOS_
	{
		$$ = EDIF;//MENOSMENOS;
	}
;
operadorUnario: MAS_
	{
		$$ = ESUM;
	}
  | MENOS_
	{
		$$ = EDIF;
	}
;
%%


/* Llamada por yyparse ante un error */
yyerror (char *s)
{
printf ("Linea %d: %s\n", yylineno, s);
}
