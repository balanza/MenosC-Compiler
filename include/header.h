/**************** Variables globales **********************/
int old_dvar;              /* Desplazamiento en el Segmento de Variables  */
int dpar;              /* Desplazamiento en el Segmento de Parametros de funcion  */
int dcmp;              /* Desplazamiento del campo en una estructura  */
int nivel; 			   /* Nivel de anidamiento */
int hayMain;           /* Se pone a 1 cuando encontramos la funcion main */
int lansMain;          /* instruccion a la cual se encuentra el main */    
int lansDespGlobal;         /* tamaño del desplazamento global */ 
int hayReturn;         /* Indica si una funcion tiene una devolucion de valor*/ 
int tallaReturn;       /* Talla del eventual valor de return*/
int lansDespFuncion;    /* Se utiliza para resolver la lans del tamaño del desplazamento inicial de una funcion*/
int verbosidad;
int verTDS;
int numErrores;

#define TRUE 1
#define FALSE 0

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
