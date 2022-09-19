#include <stdio.h>

void main() {
    // Cubo principal
    // 7 Planos (tiempo), 6 Filas (tipos de contaminante) y 3 Columnas (recursos hidricos)
    int eventos[7][6][3] =
			{ 
			  {{2, 0, 0}, {1, 3, 1}, {0, 0, 9}, {5, 0, 3}, {2, 5, 4}, {0, 1, 1}}, 		// Plano 1
			  {{5, 0, 1}, {1, 1, 1}, {3, 0, 2}, {4, 9, 10}, {0, 0, 5}, {7, 1, 7}}, 		// Plano 2
			  {{4, 0, 0}, {0, 0, 0}, {1, 2, 1}, {5, 5, 2}, {3, 6, 6}, {8, 5, 2}}, 		// Plano 3
			  {{3, 3, 1}, {9, 1, 1}, {0, 2, 0}, {5, 3, 10}, {12, 0, 12}, {9, 7, 1}},	// Plano 4
			  {{4, 2, 0}, {5, 9, 12}, {7, 5, 1}, {0, 2, 9}, {4, 1, 3}, {0, 15, 9}}, 	// Plano 5
			  {{1, 1, 0}, {2, 1, 1}, {1, 1, 1}, {0, 0, 2}, {5, 3, 2}, {4, 2, 0}}, 		// Plano 6
			  {{9, 10, 5}, {3, 7, 4}, {5, 4, 5}, {9, 8, 4}, {4, 1, 6}, {5, 0, 5}}  		// Plano 7
			};

    // Creacion de vectores paralelos
    int tiempo[7] = {2015, 2016, 2017, 2018, 2019, 2020, 2021};
    char tiposContaminante[6][22] = {"Productos Quimicos", "Desechos Industriales", "Aguas Servidas", "Relaves Mineros", "Petroleo", "Agentes Infecciosos"};
    char recursosHidricos[3][10] = {"Rios", "Lagos", "Humedales"};

    // Variables auxiliares
    int p; // Planos
    int f; // Filas
    int c; // Columnas
    int seleccion;
    int indice;
    
    int sumaContaminantes;
    float porcentaje;
    
    int sumaRecHid;
    
    int eventosRios;
    int eventosLagos;
    int eventosHumedales;
    int mayor;
    
    int sumaEventos;
    
    // printf("En el anio %i, se encontro el contaminante %s en el recurso hidrico %s", tiempo[0], tiposContaminante[0], recursosHidricos[0]);

    // Preguntar al usuario por un año para calcular el porcentaje de eventos por tipo de contaminante mientras que
    // el año seleccionado sea mayor y igual a 2015 o menor o igual a 2021.
    do {
        printf("Ingrese un a%co para calcular el porcentaje de eventos por tipo de contaminante: ", 164);
        scanf("%i", &seleccion);
        if (seleccion < 2015 || seleccion > 2021) {
            printf("El a%co seleccionado debe estar entre el rango 2015-2021.\n", 164);
        }
    } while (seleccion < 2015 || seleccion > 2021); // Se rechazan los valores que no esten en el rango de años 2015 - 2021.
    
    // Guardar el índice del año.
    for (f = 0; f < 7; f++)
    	if (tiempo[f] == seleccion) {
    		indice = f;
		}
	//printf("El indice del anio seleccionado (%i) es: %i", seleccion, indice); // Debug
	
	printf("\nCalculo de porcentaje por tipo de eventos para el a%co %i\n", 164, seleccion);
	
	// Calculo de la suma de eventos por indice (tiempo)
	for (f = 0; f < 6; f++) { // Recorre las filas para luego obtener el total de cada fila (eventos[indice][0][0] + eventos[indice][0][1] + eventos[indice][0][2])
		sumaContaminantes = 0; // Se reinicia el contador del total de la suma de contaminantes para separar por tipo de contaminante.
		for (c = 0; c < 3; c++) { // Recorre las columnas para obtener el total de cada fila.
			sumaContaminantes = sumaContaminantes + eventos[indice][f][c]; // Se suma el valor del cubo en la iteración
			//printf("\neventos[%i][%i][%i]: %i", indice, f, c, eventos[indice][f][c]); // Debug
		}
		//printf("\nLa suma del contaminante '%s' es: %f", tiposContaminante[f], sumaContaminantes); // Debug
		porcentaje = sumaContaminantes * 100 / 6; // El orden de expresiones es que las mult. y divisiones se realizen primero, de izquierda a derecha por lo que no se necesita agregar parentesis.
		printf("\nEl porcentaje de eventos para el contaminante '%s' es: %.2f%%", tiposContaminante[f], porcentaje);
	}
	//printf("\nLa suma total de eventos es: %i", sumaEventos); // Debug
	
	// Calculo del recurso hidrico más afectado por eventos de contaminacion a traves del tiempo
	
	printf("\n-----------------------------------------------------------------------------\n");
	
	// Recurso hídrico que se ha visto más afectado por eventos de contaminación a través del tiempo
	mayor = 0;
	for (p = 0; p < 7; p++) {
		sumaRecHid = 0;
		// Rios
		for (f = 0; f < 6; f++) {
			sumaRecHid = sumaRecHid + eventos[p][f][0];
			//printf("\nevento[%i][%i][0]: %i", p, f, eventos[p][f][0]);
			if (sumaRecHid > mayor) {
				mayor = sumaRecHid;
				eventosRios = mayor;
			}
		}
		//printf("\nSuma de los eventos del recurso hidrico '%s' es en el a%co %i: %i", recursosHidricos[0], 164, tiempo[p], sumaRecHid);
	}
	//printf("\nEl mayor valor de eventos para el recurso hidrico '%s' es: %i", recursosHidricos[0], eventosRios, 164);
	
	// Lagos
	mayor = 0;
	for (p = 0; p < 7; p++) {
		sumaRecHid = 0;
		// Rios
		for (f = 0; f < 6; f++) {
			sumaRecHid = sumaRecHid + eventos[p][f][1];
			//printf("\nevento[%i][%i][0]: %i", p, f, eventos[p][f][0]);
			if (sumaRecHid > mayor) {
				mayor = sumaRecHid;
				eventosLagos = mayor;
			}
		}
		//printf("\nSuma de los eventos del recurso hidrico '%s' es en el a%co %i: %i", recursosHidricos[1], 164, tiempo[p], sumaRecHid);
	}
	//printf("\nEl mayor valor de eventos para el recurso hidrico '%s' es: %i", recursosHidricos[1], eventosLagos, 164);
	
	// Humedales
	mayor = 0;
	for (p = 0; p < 7; p++) {
		sumaRecHid = 0;
		// Rios
		for (f = 0; f < 6; f++) {
			sumaRecHid = sumaRecHid + eventos[p][f][2];
			//printf("\nevento[%i][%i][0]: %i", p, f, eventos[p][f][0]);
			if (sumaRecHid > mayor) {
				mayor = sumaRecHid;
				eventosHumedales = mayor;
			}
		}
		//printf("\nSuma de los eventos del recurso hidrico '%s' es en el a%co %i: %i", recursosHidricos[2], 164, tiempo[p], sumaRecHid);
	}
	//printf("\nEl mayor valor de eventos para el recurso hidrico '%s' es: %i", recursosHidricos[2], eventosHumedales, 164);
	
	if (eventosRios >= eventosLagos && eventosRios >= eventosHumedales)
		printf("\nEl recurso hidrico que se vio mas afectado fue '%s' con un total de %i eventos.", recursosHidricos[0], eventosRios);
	else
		if (eventosLagos > eventosHumedales)
			printf("\nEl recurso hidrico que se vio mas afectado fue '%s' con un total de %i eventos.", recursosHidricos[1], eventosLagos);
		else
			printf("\nEl recurso hidrico que se vio mas afectado fue '%s' con un total de %i eventos.", recursosHidricos[2], eventosHumedales);
			
	// Año que registra la mayor cantidad de eventos de contaminación

}
