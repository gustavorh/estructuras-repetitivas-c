#include <stdio.h>

void main(){												   //
	float Eventos [2][6][3]={1,2,3,4,5,6,7,8,9,10,11,12,12,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
	
	//Vectores
	char tipos_cont[6][22]={"Productos Quimicos","Desechos Industriales","Aguas Servidas","Relaves Minerales","Petroleo","Agentes Infecciosos"};
	char recur_hidrico[3][10]={"Rios","Lagos","Humedales"};
	int tiempo[2]={2015,2016};//2017,2018,2019,2020,2021};
	 
	short int f;
	short int c;
	short int p;
	int seleccion;
	int total=0;
	int indice;
	
	
	float contador;
	float porcentaje;

	
	
	printf("TAREA 1A\n");
//Porcentaje de eventos por tipo de contaminante	
	do{
		printf("\nIngrese año que usted desea (2015 a 2021 es el rango de años): ");
		scanf("%i",&seleccion); 	
		if ( seleccion < 2015 || seleccion > 2021)
			printf("ERROR. Año ingresado incorrecto.\n");
	}while( seleccion<2015 || seleccion>2021);
	
	for(f=0;f<2;f++)//guardar indice del año ingresado
		if (tiempo[f] == seleccion)
		{
			indice=f;
		}	
	
	// Recorre tipos de contaminante 
	for(f=0;f<6;f++)//suma de los eventos en el año
	{
		// Recorre recursos hidricos
		for(c=0;c<3;c++)
		{	
			// Guarda la suma de los eventos
			total+=Eventos[indice][f][c];	
		}
	}
	
	// Salida al usuario
	printf("\nAno %i:",tiempo[indice]);
	for(f=0;f<6;f++)//printf("\n Tipo de contaminante: %s",tipos_cont[f]);
	{	
		contador=0;
	    porcentaje=0;
		for(c=0;c<3;c++) {
			printf("\n  Recurso hidrico afectado: %s, Vale %f ",recur_hidrico[c],Eventos[indice][f][c]);
	       		
			contador=contador+Eventos[indice][f][c];
			printf("\n  Recurso hidrico afectado: %s, Vale %f ",recur_hidrico[c],Eventos[indice][f][c]);
		}
		porcentaje=100*(contador/total);
		printf("\nEl porcentaje de eventos relacionados con %s son: %.2f",tipos_cont[f],porcentaje);
	}
}
