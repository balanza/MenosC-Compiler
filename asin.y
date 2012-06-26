%{
#include <stdio.h>
#include "include/libgci.h"
#include "include/libtds.h"
#include "include/header.h"
extern int yylineno;



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
	  TIPO_ARG exp;
	  int instr1;  //2 slots de referencia a instruciones
	  int instr2;                         
	} tdef;


}

%token  PUNTOYCOMA_ PUNTO_ COMA_ PARABR_ PARCER_ LLAVABR_ LLAVCER_
CORABR_ CORCER_ INT_ STRUCT_ READ_ PRINT_ IF_ ELSE_ FOR_ RETURN_ MAS_ POR_
MENOS_ DIV_ INCMAS_ INCMENOS_ ASIG_ ASIGMAS_ ASIGMENOS_ IGUAL_ DIF_ GT_ GTE_ LT_
LTE_
%token <ident> ID_
%token <cent> CTE_

%type <tdef> tipo
%type <tdef> bloque
%type <tdef> declaracion
%type <tdef> secuenciaDeclaraciones
%type <tdef> declaracionVariable
%type <tdef> listaCampos
%type <tdef> cabeceraFuncion
%type <tdef> declaracionFuncion
%type <tdef> declaracionVariableLocal
%type <tdef> parametrosFormales
%type <tdef> listaParametrosFormales
%type <tdef> parametrosActuales
%type <tdef> listaParametrosActuales

%type <tdef> expresion
%type <tdef> expresionSufija
%type <tdef> expresionIgualdad
%type <tdef> expresionOpcional
%type <tdef> expresionRelacional
%type <tdef> expresionAditiva
%type <tdef> expresionMultiplicativa
%type <tdef> expresionUnaria

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
		hayMain = 0;
		cargaContexto(nivel);
		
 		numErrores = 0;
 		
		
		/**************************** Desplazamiento global ****************************/
		// 	Lo calculamos sumando la talla de todas las "declaraciones de variables
		//	que se dan en la declaración inicial. 				        
		lansDespGlobal = creaLans(si);
		emite(INCTOP, crArgNulo(), crArgNulo(), crArgNulo());
		
		/*********************** Direccion de la funcion "main" ************************/
		lansMain=creaLans(si);
		emite(GOTOS, crArgNulo(), crArgNulo(), crArgNulo());
		
	}
secuenciaDeclaraciones
	{
		//completa la instruccion de INCTOP inicial
		completaLans(lansDespGlobal, crArgEntero($2.talla));
		
		
		//averigua que haya un main en el programa
		if(hayMain==0){
			yyerror("ni un main en todo el programa");
		}
		
		mostrarTDS(nivel);
		
		descargaContexto(nivel);
		
	}
;
secuenciaDeclaraciones: declaracion
	{
		$$.talla = $1.talla;
	}
  | secuenciaDeclaraciones declaracion 
  	{
		$$.talla = $1.talla + $2.talla;
	}
;
declaracion: declaracionVariable 
	{
		
		if(!insertaSimbolo($1.id, VARIABLE, $1.tipo, dvar, nivel, $1.ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += $1.talla; // update shift
		}
		
		mostrarTDS(nivel);
		$$.talla = $1.talla;
		
	}
  | declaracionFuncion 
	{
		$$.talla = 0;
	}
;
declaracionVariable: tipo ID_ PUNTOYCOMA_ 
	{
		$$.id = $2;
		$$.tipo = $1.tipo; 
		$$.talla = $1.talla;
		$$.ref = $1.ref;
		
	}
  | tipo ID_ CORABR_ CTE_ CORCER_ PUNTOYCOMA_
  {
  	
  	if($1.tipo!=T_ENTERO){
		yyerror("el tipo de los vectores tiene que ser int");
	} else if($4<=0){
		yyerror("el array debe contener un numero positivo de elementos");
		$$.id = $2;
		$$.tipo = T_ERROR;
		$$.talla = 1; // ???
		$$.ref = insertaInfoArray($1.tipo, 4);
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
		
	//	printf("\nLOG campo %s ref -1", $1.id);
		if($1.tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else {
			int ref = insertaInfoCampo(-1, $1.id, $1.tipo, 0);
			if(ref == -1){
				yyerror("error en la declaracion de campo de la estructura (primero)");
			}
			$$.ref = ref;
			
		}
		$$.talla = $1.talla;
		
	}
  | listaCampos declaracionVariable  	
	{
		
		//printf("\nLOG campo %s ref %d", $2.id, $1.ref);	
		if($2.tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else if(insertaInfoCampo($1.ref, $2.id, $2.tipo, $1.talla)==-1){
	//		printf("\nLOG campo %s ", $2.id);
			yyerror("error en la declaracion de campo de la estructura");
		}

		$$.talla = $1.talla + $2.talla;
		$$.ref = $1.ref;
	}
;
declaracionFuncion: cabeceraFuncion bloque 
	{
		//calcula tamaño del RA
		/*int t_ra;
		t_ra = $2.talla + $3.talla;
		if(hayReturn == 1){
			t_ra += tallaReturn;
		}*/
	
		//completa lans de INCTOP		
		completaLans(lansDespFuncion, crArgEntero(dvar));
		
		//completa lans return function
		if(lansReturn!=-1){
			completaLans(lansReturn, crArgEtiqueta(si));
		}
	
		//emite funciones de salida de la funcion
		emite(TOPFP, crArgNulo(), crArgNulo(), crArgNulo());
		emite(FPPOP, crArgNulo(), crArgNulo(), crArgNulo());
		
		
		//detecta la funcion main, y define el cierre de de la funcion (o del programa entero)
		if(strcmp("main",$1.id) == 0){
			emite(FIN, crArgNulo(), crArgNulo(), crArgNulo());
		} else {
			emite(RET, crArgNulo(), crArgNulo(), crArgNulo());
		}


		//mostrarTDS(nivel); 
	
		//restaura entorno
		descargaContexto(nivel);
		nivel--;
		dvar = old_dvar + 1;
		
	}
;
cabeceraFuncion: 

	tipo ID_ 
	{
		//prepara entorno
		nivel++;
		cargaContexto(nivel);
		dpar = TALLA_SEGENLACES;
		old_dvar = dvar;
		dvar = 0;	
		lansReturn = -1;
	}
	PARABR_ parametrosFormales  PARCER_
	{	
	
		//comproba tipo
		if($<tdef>1.tipo!=T_ENTERO){
  			yyerror("la funcion tiene que ser de tipo int");
  		} 
  		
		
		//inserta simbolo
		if(!insertaSimbolo($2, FUNCION, $1.tipo, si, nivel, $5.ref)){
			yyerror("funcion repetida");
		}
		
		//detecta el main
		if(strcmp("main",$2) == 0){
			if(hayMain==0){
				hayMain = 1;
				completaLans(lansMain, crArgEtiqueta(si));
			} else {
				yyerror("hay dos declaraciones de main en el programa");
			}		
		}
		
		//emision de codigo por la inicializacion del RA de la funcion
		emite(PUSHFP, crArgNulo(), crArgNulo(), crArgNulo());
		emite(FPTOP, crArgNulo(), crArgNulo(), crArgNulo());	
  		lansDespFuncion = creaLans(si);	
		emite(INCTOP, crArgNulo(), crArgNulo(), crArgNulo());
		
		
		
		$$.ref = $5.ref;
		$$.talla = $5.talla; //suma del tamaño de los parametros
		$$.id = $2;
		$$.tipo = $1.tipo;
		
		
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
	  		dpar += $1.talla;
	  	//		printf("\nLOG par %s desp %d nivel %d", $2, nivel, -dpar);
			if(!insertaSimbolo($2, PARAMETRO, $1.tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				
				$$.ref = insertaInfoDominio(-1, $1.tipo);
			}
		}
  	}
  | tipo ID_ COMA_  	
  	{
  		if($1.tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		dpar += $1.talla;
	  		//	printf("\nLOG par %s desp %d nivel %d", $2, nivel, -dpar);
	  		if(!insertaSimbolo($2, PARAMETRO, $1.tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				
			}
			
	
		}
  	} 
  	 listaParametrosFormales 
  	 {
  	 	$$.ref = insertaInfoDominio($5.ref, $1.tipo);
  	 	$$ = $5;
  	 }
;
bloque: LLAVABR_ declaracionVariableLocal listaInstrucciones LLAVCER_ 
	{
		$$.talla = $2.talla;
	}
;
declaracionVariableLocal: 
	{
		$$.talla = dvar;
		
	}
  | declaracionVariableLocal declaracionVariable
  	{

		if(!insertaSimbolo($2.id, VARIABLE, $2.tipo, dvar, nivel, $2.ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += $2.talla; // update shift
		}
		
				mostrarTDS(nivel);
		$$.talla = dvar;
		
	}
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
		descargaContexto(nivel);
		nivel--;
	}
  | instruccionExpresion
  | instruccionEntradaSalida
  | instruccionSeleccion
  | instruccionIteraccion
  | instruccionSalto
;
instruccionExpresion: PUNTOYCOMA_ 
	{
		
	}
 | expresion PUNTOYCOMA_
;
instruccionEntradaSalida: READ_ PARABR_ ID_
	{
		SIMB sim = obtenerSimbolo($3);
		if(sim.categoria == NULO)
		{
			yyerror("Error: Identificador no declarado");
		}
		else
		{
			TIPO_ARG argRead = crArgPosicion(sim.nivel,sim.desp);
			emite(EREAD, crArgNulo(), crArgNulo(), argRead);
		}
	}
	PARCER_ PUNTOYCOMA_ 
	
	| PRINT_ PARABR_ expresion 
	{
		emite(EWRITE, crArgNulo(), crArgNulo(), $3.exp);
	}
	PARCER_ PUNTOYCOMA_;
;
instruccionSeleccion: IF_ PARABR_ expresion PARCER_ 
	{
		
		//controlo que la expresion sea de tipo logico
		if($3.tipo!=T_LOGICO){
			yyerror("La expresion de la condicion de control no es de tipo logico");
		}
	
		//condiccion para saltar al cuerpo del else
		$<tdef>$.instr1 = creaLans(si);
		emite(EIGUAL, $3.exp, crArgEntero(0), crArgNulo());
	}
	instruccion 
	{
		$<tdef>$.instr2 = creaLans(si); //fin del bloque if-else
		emite(GOTOS, crArgNulo(), crArgNulo(), crArgNulo());
		completaLans($<tdef>5.instr1, crArgEtiqueta(si));		
	}
	ELSE_ instruccion
	{
		
		completaLans($<tdef>7.instr2, crArgEtiqueta(si));
	}
;
instruccionIteraccion: FOR_ PARABR_ expresionOpcional PUNTOYCOMA_ 
	{
		//principio del bucle (justo despues de las instrucciones de inicializaccion)
		$<tdef>$.instr1 = si;
	}
	expresion PUNTOYCOMA_ 
	{
		//controlo que la expresion sea de tipo logico
		if($6.tipo!=T_LOGICO){
			yyerror("La expresion de la condicion de entrada del bucle no es de tipo logico");
		}
		
		//instruccion para salir del bucle
		$6.instr1 = creaLans(si);
				
		
		emite(EIGUAL, $<tdef>6.exp, crArgEntero(0), crArgNulo());
		//instruccion para volver a las instrucciones cuerpo del bucle
		$6.instr2 = creaLans(si);
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgNulo());	//inicio de la funcion de incremento
		
		//instruccion para salir del bucle		
		$<tdef>$.instr2 = si;

	}
	expresionOpcional PARCER_ 
	{
		//inicio de la funcion de incremento
		$<tdef>8.instr1 = si;
		//vuelve a ejecutar la condiccion de entrada al bucle
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgEtiqueta($<tdef>5.instr1));
		completaLans($<tdef>6.instr2, crArgEtiqueta(si));
	}
	instruccion
	{
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgEtiqueta($<tdef>8.instr2));
		
		completaLans($<tdef>6.instr1, crArgEtiqueta(si));
	}
;
expresionOpcional: 
	{
		
	}
  | expresion
  	{
  		$$ = $1;
  	}
;
instruccionSalto: RETURN_ expresion PUNTOYCOMA_ 
	{
		//enciende el flag de existencian de return en la funcion
		hayReturn = 1;
		
		
		INF inf = obtenerInfoFuncion(-1);
		if($2.tipo != inf.tipo)	{
//			printf("\nLOG func: %s tipo: %d expr: %d", inf.nombre, inf.tipo, $2.tipo);
			yyerror("Tipo devuelto por el return es incorrecto.");
		}
		//if(strcmp("main",inf.nombre) != 0 ){ // No es main
		
	
		int desp = -(inf.tparam + TALLA_SEGENLACES + tallaTipo($2.tipo));
		emite(EASIG,$2.exp,crArgNulo(),crArgPosicion(nivel,desp));
		
		//acaba la funcion, emite un salto al fin
		int lans = creaLans(si);
		if(lansReturn==-1){
			lansReturn = lans;
		} else {
			lansReturn = fusionaLans(lansReturn, lans);
		}
		emite(GOTOS, crArgNulo(), crArgNulo(), crArgNulo());
		
		//}
	}
	
;
expresion: expresionIgualdad 
	{
		$$ = $1;
	}
  | ID_ operadorAsignacion expresion
  	{
  		
  		SIMB id;
		id = obtenerSimbolo($1);
		if (id.categoria == NULO){
			yyerror("Identificador no declarado");
		}
		if ((id.tipo==$3.tipo)){ 
			$$.tipo = $3.tipo;
	
		
			TIPO_ARG id_arg = crArgPosicion(id.nivel, id.desp);
			TIPO_ARG exp_arg = $3.exp;
		
		
			switch($2){
				case MASASIG: // id = id + exp
					emite(ESUM, id_arg, exp_arg, id_arg);
				//	printf("\nemite asignacion de variable %s+=%d", $1, id_arg.val.i);
					break;
				case MENOSASIG:
					emite(EDIF, id_arg, exp_arg, id_arg);
				//	printf("\nemite asignacion de variable %s-=%d", $1, id_arg.val.i);
					break;
				case ASIG:
					emite(EASIG, exp_arg, crArgNulo(), id_arg);
				//	printf("\nemite asignacion de variable %s=%d", $1, id_arg.val.i);
					break;

			}
		
			//printf("\nemite asignacion de variable para %s (sube valor arriba)", $1);
			//emite(EASIG, id_arg, crArgNulo(), $$);
			$$.exp = id_arg;
			$$.tipo = id.tipo;
  		
  		}
		else {
			
			yyerror("Error de tipos en la asignacion de la ((expresion))");
			$$.tipo=T_ERROR;
		}
  	}
  | ID_ CORABR_ expresion CORCER_ operadorAsignacion expresion
  	{
		SIMB id;
		
		id = obtenerSimbolo($1);
		if(id.categoria==NULO){
			yyerror("variable array no declarada");	
			$$.tipo = T_ERROR;
		}if(id.tipo!=T_ARRAY)
		{
			yyerror("La variable no es de tipo array.");
		} else {
			TIPO_ARG indice = $3.exp; //indice
			TIPO_ARG valor = $6.exp; // valor de la expresion para asignar
			TIPO_ARG elem = crArgPosicion(nivel, creaVarTemp()); //variable por el valor del elemento id[expresion]
			TIPO_ARG id_arg = crArgPosicion(id.nivel, id.desp);
			
			
			
			switch($5){
				case MASASIG: //leo el elemento del array
					emite(EAV, id_arg, indice, elem);
					emite(ESUM, valor, elem, elem);
					break;
				case MENOSASIG://leo el elemento del array
			emite(EAV, id_arg, indice, elem);
					emite(EDIF, elem, valor, elem);
					break;
				case ASIG:
					emite(EASIG, valor, crArgNulo(), elem);
					break;
			}			

			emite(EVA, id_arg, indice, elem);
			$$.exp = elem;
			$$.tipo = id.tipo;
		}
	}
  | ID_ PUNTO_ ID_ operadorAsignacion expresion
  	{
		SIMB id;
		REG campo;		
		TIPO_ARG exp_arg = $5.exp;
			
		id = obtenerSimbolo($1);
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			$$.tipo = T_ERROR;
		} else {
			campo = obtenerInfoCampo(id.ref, $3);
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				$$.tipo = T_ERROR;
			}else if($5.tipo!=1 && campo.tipo!=exp_arg.tipo){
			//	printf("\nLOG: exp  tipo: %d exp.tipo: %d exp.val.i: %d", $5.tipo, $5.exp.tipo, $5.exp.val.i);
			//	printf("\nLOG: registro: %s campo: %s tipo esxpresion: %d tipo campo: %d", $1, $3, exp_arg.tipo, campo.tipo);
				yyerror("se trata de asignar un valor de un tipo incorrecto a un campo");	
				$$.tipo = T_ERROR;			
			}else{
				TIPO_ARG campo_arg = crArgPosicion(id.nivel, id.desp + campo.desp);
				TIPO_ARG temp = crArgPosicion(nivel, creaVarTemp());  
				
				switch($4){
					case MASASIG: //leo el elemento del registro
						emite(EASIG, campo_arg, crArgNulo(), temp);
						emite(ESUM, exp_arg, temp, campo_arg);
						break;
					case MENOSASIG://leo el elemento del registro
						emite(EASIG, campo_arg, crArgNulo(), temp);
						emite(EDIF, exp_arg, temp, campo_arg);
						break;
					case ASIG:
						emite(EASIG, exp_arg, crArgNulo(), campo_arg);
						break;
				}
				

				$$.exp = campo_arg;
				$$.tipo = campo.tipo;
			}
		}
  	}
;
expresionIgualdad: expresionRelacional
  	{
  		$$ = $1;
  	}
  | expresionIgualdad operadorIgualdad expresionRelacional
   	{
   		int oprel;
  		
  		TIPO_ARG exp1_arg = $1.exp;
  		TIPO_ARG exp2_arg = $3.exp;
  		TIPO_ARG true_arg = crArgEntero(1);
  		TIPO_ARG false_arg = crArgEntero(0);
  		
  	
  		switch($2){
  			case IGUAL:
  				oprel = EIGUAL;
  				break;
  			case DISTINTO:
				oprel = EDIST;		
  				break;
  			default:
  				yyerror("Operador igualdad desconocido");
  		}
  		
  		
  		$$.exp = crArgPosicion(nivel, creaVarTemp());  	
 		emite(EASIG, true_arg, crArgNulo(), $$.exp);  	
 		emite(oprel, exp1_arg, exp2_arg, crArgEtiqueta(si+2));  	
 		emite(EASIG, false_arg, crArgNulo(), $$.exp);
 		
 		$$.tipo = T_LOGICO;
  	}
;
expresionRelacional: expresionAditiva
	{
		$$ = $1;
	}
  | expresionRelacional operadorRelacional expresionAditiva
  	{
  		int oprel;
  		
  		TIPO_ARG exp1_arg = $1.exp;
  		TIPO_ARG exp2_arg = $3.exp;
  		TIPO_ARG true_arg = crArgEntero(1);
  		TIPO_ARG false_arg = crArgEntero(0);
  		
  	
  		switch($2){
  			case MAYOR:
  				oprel = EMAY;
  				break;
  			case MENOR:
				oprel = EMEN;		
  				break;
  			case MAYORIG:
  				oprel = EMAYEQ;
  				break;
  			case MENORIG:
  				oprel = EMENEQ;
  				break;
  			default:
  				yyerror("Operador relacional desconocido");
  		}
  		
  		
  		$$.exp = crArgPosicion(nivel, creaVarTemp());  	
 		emite(EASIG, true_arg, crArgNulo(), $$.exp);  	
 		emite(oprel, exp1_arg, exp2_arg, crArgEtiqueta(si+2));  	
 		emite(EASIG, false_arg, crArgNulo(), $$.exp);
  		
  		
 		$$.tipo = T_LOGICO;
  		
  	}
;
expresionAditiva: expresionMultiplicativa
	{
		$$ = $1;
	}
  | expresionAditiva operadorAditivo expresionMultiplicativa
  	{
  		TIPO_ARG exp1_arg = $1.exp;
  		TIPO_ARG exp2_arg = $3.exp;
  		
  		$$.exp = crArgPosicion(nivel, creaVarTemp());
  	
  		switch($2){
  			case MAS:
  				emite(ESUM, exp1_arg, exp2_arg, $$.exp);
  				break;
  			case MENOS:
  				emite(EDIF, exp1_arg, exp2_arg, $$.exp);
  				break;
  			default:
  				yyerror("Operador aditivo desconocido");
  		}
  		
  		
  		$$.tipo = $1.tipo;
  	}
;
expresionMultiplicativa: expresionUnaria
	{
		$$ = $1;
	}
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria
  	{
  		TIPO_ARG exp1_arg = $1.exp;
  		TIPO_ARG exp2_arg = $3.exp;
  		
  		$$.exp = crArgPosicion(nivel, creaVarTemp());
  	
  		switch($2){
  			case POR:
  				emite(EMULT, exp1_arg, exp2_arg, $$.exp);
  				break;
  			case DIV:
  				emite(EDIVI, exp1_arg, exp2_arg, $$.exp);
  				break;
  			default:
  				yyerror("Operador multiplicativo desconocido");
  		}
  		
  		$$.tipo = $1.tipo;
  	}
;
expresionUnaria: expresionSufija 
	{
		$$ = $1;
	}
  | operadorUnario expresionUnaria
  	{
  		TIPO_ARG exp_arg = $2.exp;
  		
  		if($1 == MENOS){
	  		
	  		$$.exp = crArgPosicion(nivel, creaVarTemp());
	  		emite(EDIF, crArgEntero(0), exp_arg, $$.exp);
  		} else {
	  		//printf("\nemite expresionUnaria (+)");
	  		emite(EASIG, exp_arg, crArgNulo(), $$.exp);
	  		$$ = $2;
  		}
  	}
  | operadorIncremento ID_ 
  	{
  		 		
  		SIMB sim; 
  		TIPO_ARG res;
  		  		
		sim = obtenerSimbolo($2);
		/* comprobaciones semanticas */
		res = crArgPosicion(sim.nivel, sim.desp);
		$$.exp = crArgPosicion(nivel, creaVarTemp());		
		$$.tipo = T_ENTERO;
		/************************************** INCREMENTA o DECREMENTA 1 */
		
		int operador;
		if($1==MASMAS){
			operador = ESUM;
		}else{
			operador = EDIF;
		}
		
		
		emite(operador, res, crArgEntero(1), res);
		/***************************************************** Asignacion */
		
		emite(EASIG, res, crArgNulo(), $$.exp);
		
		
  		$$.tipo = sim.tipo;
  	}
;
expresionSufija: ID_ CORABR_ expresion CORCER_
	{
		SIMB id;
		id = obtenerSimbolo($1);
		if(id.categoria==NULO){
			yyerror("Variable array no declarada");	
			$$.tipo = T_ERROR;
		} else 
		if(id.tipo!=T_ARRAY)
		{
			yyerror("La variable no es de tipo array.");
		}else
		{
			TIPO_ARG indice = $3.exp;
			$$.exp = crArgPosicion(nivel, creaVarTemp());
			emite(EAV, crArgPosicion(id.nivel, id.desp), indice, $$.exp);
		}

  		$$.tipo = id.tipo;
	}
  | ID_ PUNTO_ ID_
  	{
		SIMB id;
		REG campo;		
			
		id = obtenerSimbolo($1);
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			$$.tipo = T_ERROR;
		} if(id.tipo!=T_RECORD)
		{
			yyerror("La variable no es de tipo registro.");
		}else {
			campo = obtenerInfoCampo(id.ref, $3);
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				$$.tipo = T_ERROR;
			}else{
				$$.exp = crArgPosicion(id.nivel, id.desp + campo.desp);
				$$.tipo = campo.tipo;
			}
		}
  	}
  | ID_ operadorIncremento
	{
		SIMB sim; 
  		TIPO_ARG res;
  		  		
		sim = obtenerSimbolo($1);
		/* comprobaciones semanticas */
		res = crArgPosicion(sim.nivel, sim.desp);
		$$.exp = crArgPosicion(nivel, creaVarTemp());		
		$$.tipo = T_ENTERO;
		/************************************** INCREMENTA o DECREMENTA 1 */
		
		int operador;
		if($2==MASMAS){
			operador = ESUM;
		}else{
			operador = EDIF;
		}
		
		/***************************************************** Asignacion */
		emite(EASIG, res, crArgNulo(), $$.exp);
		
		emite(operador, res, crArgEntero(1), res);
		
		
		
  		$$.tipo = sim.tipo;
	} 
  | ID_ 
  	{
  		//espacio reservado para el valor de retorno
  		emite(EPUSH, crArgNulo(), crArgNulo(), crArgEntero(0));
  	}
  	PARABR_ parametrosActuales PARCER_ 
	{
		//obtener simbolo de la funcion desde la tabla de simbolos
		SIMB id = obtenerSimbolo($1); 
		
		
		if(id.categoria == NULO){
			yyerror("Funcion no declarada.");
			$$.tipo=T_ERROR;
		} else {
			
			if(comparaDominio(id.ref, $4.ref)==1){
				INF info = obtenerInfoFuncion(id.ref);
		  		
  				//emitir call
				$$.exp = crArgPosicion(nivel, creaVarTemp());
				$$.tipo = info.tipo;
				emite(CALL, crArgNulo(), crArgNulo(), crArgEtiqueta(id.desp));
				emite(DECTOP, crArgNulo(), crArgNulo(), crArgEntero(info.tparam));
				emite(EPOP, crArgNulo(), crArgNulo(), $$.exp);
			}
			else
			{
				yyerror("Parametros incorrectos");
				$$.tipo=T_ERROR;
			}
		}
		
	}
  | PARABR_ expresion PARCER_
	{
		$$ = $2;
	}
  | ID_ {
  			SIMB id = obtenerSimbolo($1);
  			
	  		if(id.categoria==NULO){ 
	  			yyerror("\n variable NO declarada todavia, primer uso");
	  			$$.tipo = T_ERROR;
	  		} else {
	  	//		printf("\nLOG var %s desp %d nivel %d", $1, id.nivel, id.desp);
	  			$$.exp = crArgPosicion(id.nivel, id.desp);
	  			$$.tipo = id.tipo; 
	  		}
	  		
	  		
  		}
  | CTE_ 
  	{
  		
  		$$.exp = crArgEntero($1);
  		printf("\nCTE tipo: %d valor %d", $$.exp.tipo, $$.exp.val.i);
  		$$.tipo = T_ENTERO;
  	}
;
parametrosActuales:
	{
		$$.ref = insertaInfoDominio(-1,T_VACIO);
	}
  | listaParametrosActuales
	{
		if($1.tipo != T_ERROR){
			$$.ref = $1.ref;
		}  
	}
;
listaParametrosActuales: expresion 
	{
		
		$$.ref = insertaInfoDominio(-1, $1.tipo);
		emite(EPUSH, crArgNulo(), crArgNulo(), $1.exp);
	}
  | expresion COMA_ listaParametrosActuales
	{
		$$.ref = insertaInfoDominio($3.ref, $1.tipo);
		emite(EPUSH, crArgNulo(), crArgNulo(), $1.exp);
	}
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
		$$ = MASMAS;
	}
  | INCMENOS_
	{
		$$ = MENOSMENOS;
	}
;
operadorUnario: MAS_
	{
		$$ = MAS;
	}
  | MENOS_
	{
		$$ = MENOS;
	}
;
%%


/* Llamada por yyparse ante un error */
yyerror (char *s)
{

	printf ("\nERROR ->Linea %d: %s", yylineno, s);
	numErrores++;
}



/**************** Funciones de utilidad **********************/
int tallaTipo(int tipo){
	if(tipo == T_ENTERO){
		return TALLA_ENTERO;
	} 
	return 0;
}


