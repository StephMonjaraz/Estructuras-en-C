/*
* Crea una estructura Departamento que contenga un arreglo de Empleado dinámico 
* Hint (1): Usen Malloc e investigen como es una estructura dinámica). 
*Hint (2): Para asignación de la memoria puede usar: sales.employees = (Employee*)malloc(sales.nEmployees *
*sizeof(Employee));
*/

#include <stdio.h>
#include <stdlib.h> // libreria para malloc
#include <string.h> //libreria para strcpy


struct Empleado{ //estructura empleado 
    char nombre[40];
    char turno[25]; //matutino 
    char puesto[15]; // vendedor, desarrollador, diseñador, analista. 
    float salario;
    int edad;
    int id;
};

struct Departamento { //estructura departamento
    char nombre[30];
    int nEmpleados;
    struct Empleado* Empleados;
};

//MALLOC:
/*
 * "memory allocation" es una función de la librería estándar <stdlib.h> que sirve para 
 * reservar un bloque de memoria durante la ejecución del programa.
 *devuelve un apuntador  al primer byte del bloque de memoria reservado.
 *Si no puede reservar la memoria, devuelve NULL.
 *
 *debemos liberar la memoria reservada con free() después de usarla para evitar fugas de memoria.
*/

int main() {
    struct Departamento tecnologia; 

    strcpy(tecnologia.nombre, "Tecnologia"); //le damos el nombre al departamento

    printf("¿Cuámtos empleados hay en el departamento de %s?", tecnologia.nombre);
    scanf("%d", &tecnologia.nEmpleados);


    // Reservamos memoria para los empleados ocn malloc
    tecnologia.Empleados=(struct Empleado*)malloc(tecnologia.nEmpleados * sizeof(struct Empleado));


    if (tecnologia.Empleados == NULL) {
        printf("No pudimos hacerla asignacion de memoria\n");
        return 1;
    }




    // Asignamos valores para cada empleado
    int i; 
    for(i=0; i<tecnologia.nEmpleados; i++){
        //para evitar que haya problemas si el usuario inserta un nombre con espacios
        // usaremos  %[^\n], que lee hasta que encuentra un salto de línea (respeta los espacios)
        printf("Empleado %d:\n", i+1);
        printf("Nombre: ");
        scanf(" %[^\n]", tecnologia.Empleados[i].nombre);
        printf("Turno: ");
        scanf(" %[^\n]", tecnologia.Empleados[i].turno);
        printf("Puesto: ");
        scanf(" %[^\n]", tecnologia.Empleados[i].puesto);
        printf("Salario: ");
        scanf("%f", &tecnologia.Empleados[i].salario);
        printf("Edad: ");
        scanf("%d", &tecnologia.Empleados[i].edad);
        tecnologia.Empleados[i].id = i + 1; //para que el id no se repita
        printf("\n");
    }


    //para conocer los datos de los empleados. 
    printf("\n\n\t\t\tINFORMACION DE EMPLEADOS:\n\n");
    
    printf("ID\tNombre\t\t\tTurno\t\tPuesto\t\tSalario\t\tEdad\n");
    for(i=0; i<tecnologia.nEmpleados; i++){
        printf("%i\t%-16s\t%-10s\t%-13s\t%.2f\t\t%i\n", tecnologia.Empleados[i].id, tecnologia.Empleados[i].nombre, tecnologia.Empleados[i].turno, tecnologia.Empleados[i].puesto, tecnologia.Empleados[i].salario, tecnologia.Empleados[i].edad);
    }
    printf("\n\n");

    // *siempre liberar la memoria al termino del programa
    free(tecnologia.Empleados);


    return 0;
}


