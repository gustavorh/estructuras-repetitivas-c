#include <stdio.h>
#include <string.h>

#define pacientes 4
#define anio 2022
#define mes 06

typedef struct Paciente {
    int nroFicha;
    char genero;                // F: Femenino - M: Masculino
    int mesNacim;               // Mes de nacimiento
    int agnoNacim;              // Año de nacimiento
    char grupoSan[3];           // Grupo sanguíneo: A, B, AB, O
    char factorRh;              // +: positivo - -: negativo
    int vacCovid19[6];          // Vacunas COVID-19: 1a dosis, 2a dosis, etc . 1: si - 0: nos
}Ficha;

void main() {
    Ficha control[pacientes] = {{01, 'M', 05, 2002, "B", '+', {1, 1, 1, 0, 0, 0}},
                                {02, 'M', 04, 2004, "AB", '-',{1, 1, 0, 0, 0, 0}},
                                {03, 'F', 02, 2000, "O", '+', {1, 1, 1, 1, 0, 0}},
                                {04, 'F', 07, 2003, "A", '-', {1, 1, 1, 0, 0, 0}}
                                };

    // Declaración de variables
    int i;                          // Variable auxiliar.
    int j;                          // Variable auxiliar.
    int edadPaciente;               // Edad del paciente.
    int porcentajePacientesA = 0;   // Porcentaje de pacientes del grupo sanguineo A.
    int porcentajePacientesB = 0;   // Porcentaje de pacientes del grupo sanguineo B.
    int porcentajePacientesAB = 0;  // Porcentaje de pacientes del grupo sanguineo AB.
    int porcentajePacientesO = 0;   // Porcentaje de pacientes del grupo sanguineo O.
    int cantH;                      // Cantidad de hombres vacunados por dosis.
    int cantM;                      // Cantidad de mujeres vacunadas por dosis.

    // Mostrar número de ficha, género y edad de los pacientes que tienen solo hasta la 3ra vacuna
    printf("\nLos siguientes pacientes tienen hasta la 3ra vacuna COVID19.");
    for (i = 0; i < 4; i++) {
        edadPaciente = 0;
        if (control[i].vacCovid19[2] == 1 && control[i].vacCovid19[3] == 0) {
            if (control[i].mesNacim <= mes)
                edadPaciente = anio - control[i].agnoNacim;
            else
                edadPaciente = (anio - control[i].agnoNacim) - 1;
            printf("\nNumero de Ficha: %i, Genero: %c, Edad: %i.", control[i].nroFicha, control[i].genero, edadPaciente);
        }
    }

    // Mostrar porcentaje de pacientes por grupo sanguíneo
    printf("\n\nPorcentaje de pacientes por grupo sanguineo.");
    for (i = 0; i < 4; i++) {
        if (strcmp(control[i].grupoSan, "A") == 0)
            porcentajePacientesA++;
        else if (strcmp(control[i].grupoSan, "B") == 0)
            porcentajePacientesB++;
        else if (strcmp(control[i].grupoSan, "AB") == 0)
            porcentajePacientesAB++;
        else if (strcmp(control[i].grupoSan, "O") == 0)
            porcentajePacientesO++;
    }
    porcentajePacientesA = (float)(porcentajePacientesA * 100) / pacientes;
    porcentajePacientesB = (float)(porcentajePacientesB * 100) / pacientes;
    porcentajePacientesAB = (float)(porcentajePacientesAB * 100) / pacientes;
    porcentajePacientesO = (float)(porcentajePacientesO * 100) / pacientes;
    printf("\nEl porcentaje de pacientes del grupo sanguineo 'A' es: %i%%", porcentajePacientesA);
    printf("\nEl porcentaje de pacientes del grupo sanguineo 'B' es: %i%%", porcentajePacientesB);
    printf("\nEl porcentaje de pacientes del grupo sanguineo 'AB' es: %i%%", porcentajePacientesAB);
    printf("\nEl porcentaje de pacientes del grupo sanguineo 'O' es: %i%%", porcentajePacientesO);

    // Mostrar por cada dosis la cantidad de pacientes por genero.
    printf("\n\nLa clasificacion de dosis por genero es la siguiente:");
    for (i = 0; i < 6; i++) {
        cantH = 0;
        cantM = 0;
        for (j = 0; j < 4; j++)
            if (control[j].vacCovid19[i] == 1) {
                if (control[j].genero == 'M')
                    cantH += 1;
                else if (control[j].genero == 'F')
                    cantM += 1;
            }
        printf("\nEn la %i dosis de vacuna, hubieron %i hombres vacunados.", (i+1), cantH);
        printf("\nEn la %i dosis de vacuna, hubieron %i mujeres vacunadas.\n", (i+1), cantM);
    }

}
