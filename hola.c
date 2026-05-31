#include <stdio.h>

#define ASIGNATURAS 3
#define MAX_EST 50

void pedirEstudiantes(int *estudiantes);
void ingresarNotas(float notas[][ASIGNATURAS], int estudiantes);
void mostrarNotas(float notas[][ASIGNATURAS], int estudiantes);
void calcularPromediosEstudiantes(float notas[][ASIGNATURAS], float promedios[], int estudiantes);
void mostrarPromediosEstudiantes(float promedios[], int estudiantes);
void calcularPromediosAsignaturas(float notas[][ASIGNATURAS], float promedios[], int estudiantes);
void mostrarPromediosAsignaturas(float promedios[]);
void contarAprobadosAsignaturas(float notas[][ASIGNATURAS], int aprobados[], int reprobados[], int estudiantes);
void mostrarAprobadosAsignaturas(int aprobados[], int reprobados[]);

int main(void) {
    int estudiantes;
    float notas[MAX_EST][ASIGNATURAS];
    float promediosEstudiantes[MAX_EST];
    float promediosAsignaturas[ASIGNATURAS];
    int aprobados[ASIGNATURAS];
    int reprobados[ASIGNATURAS];
    void (*mostrar)(float (*)[ASIGNATURAS], int) = mostrarNotas;

    pedirEstudiantes(&estudiantes);
    ingresarNotas(notas, estudiantes);
    calcularPromediosEstudiantes(notas, promediosEstudiantes, estudiantes);
    calcularPromediosAsignaturas(notas, promediosAsignaturas, estudiantes);
    contarAprobadosAsignaturas(notas, aprobados, reprobados, estudiantes);

    mostrar(notas, estudiantes);
    mostrarPromediosEstudiantes(promediosEstudiantes, estudiantes);
    mostrarPromediosAsignaturas(promediosAsignaturas);
    mostrarAprobadosAsignaturas(aprobados, reprobados);

    return 0;
}

void pedirEstudiantes(int *estudiantes) {
    do {
        printf("Ingrese numero de estudiantes (1-%d): ", MAX_EST);
        scanf("%d", estudiantes);
    } while (*estudiantes < 1 || *estudiantes > MAX_EST);
}

void ingresarNotas(float notas[][ASIGNATURAS], int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            float *nota = &notas[i][j];
            do {
                printf("  Nota asignatura %d (0-10): ", j + 1);
                scanf("%f", nota);
            } while (*nota < 0.0f || *nota > 10.0f);
        }
    }
}

void mostrarNotas(float notas[][ASIGNATURAS], int estudiantes) {
    printf("\nNotas ingresadas:\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("Estudiante %d:", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            printf(" %.2f", notas[i][j]);
        }
        printf("\n");
    }
}

void calcularPromediosEstudiantes(float notas[][ASIGNATURAS], float promedios[], int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        float suma = 0.0f;
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += notas[i][j];
        }
        promedios[i] = suma / ASIGNATURAS;
    }
}

void mostrarPromediosEstudiantes(float promedios[], int estudiantes) {
    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promedios[i]);
    }
}

void calcularPromediosAsignaturas(float notas[][ASIGNATURAS], float promedios[], int estudiantes) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0.0f;
        for (int i = 0; i < estudiantes; i++) {
            suma += notas[i][j];
        }
        promedios[j] = suma / estudiantes;
    }
}

void mostrarPromediosAsignaturas(float promedios[]) {
    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promedios[j]);
    }
}

void contarAprobadosAsignaturas(float notas[][ASIGNATURAS], int aprobados[], int reprobados[], int estudiantes) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        aprobados[j] = 0;
        reprobados[j] = 0;
        for (int i = 0; i < estudiantes; i++) {
            if (notas[i][j] >= 6.0f) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
    }
}

void mostrarAprobadosAsignaturas(int aprobados[], int reprobados[]) {
    printf("\nAprobados y reprobados por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d: Aprobados %d, Reprobados %d\n", j + 1, aprobados[j], reprobados[j]);
    }
}
