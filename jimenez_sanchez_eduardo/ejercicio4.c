//Jimenez Sanchez Eduardo Yael  Tarea 3 curso de C
#include <stdio.h>
#include <stdlib.h>   // contiene malloc, free
#include <string.h>   // contiene strcpy

typedef struct // Defini la estructura Empleado
{
    char nombre[30];    //variable para el nombre
    float sueldo;       //variable para eñ sueldo
} Empleado;


typedef struct // Defini la estructura Departamento
{
    int numEmpleados;
    Empleado *empleados;  // Puntero al arreglo 
} Departamento;

int main() {        //funcion principal
    Departamento coyoacan;
    printf("¿Cuántos empleados tiene el departamento? ");
    scanf("%d", &coyoacan.numEmpleados);

    // Se reserva memoria para el arreglo de empleados
    coyoacan.empleados = (Empleado *)malloc(coyoacan.numEmpleados * sizeof(Empleado));
    if (coyoacan.empleados == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < coyoacan.numEmpleados; i++) { // Lectura de datos para cada empleado
        printf("\nEmpleado %d\n", i + 1);
        printf("Nombre: ");
        
        getchar();  // Limpiar antes de fgets
        fgets(coyoacan.empleados[i].nombre, 30, stdin);

        printf("Sueldo: ");
        scanf("%f", &coyoacan.empleados[i].sueldo);
    }


    printf("\n--- Lista de empleados ---\n");     // Muestra la lista de empleados
    for (int i = 0; i < coyoacan.numEmpleados; i++) {
        printf("Empleado %d: %s, Sueldo: %.2f\n",i + 1,coyoacan.empleados[i].nombre,coyoacan.empleados[i].sueldo);
    }

    // Liberar la memoria
    free(coyoacan.empleados);
    return 0;
}
