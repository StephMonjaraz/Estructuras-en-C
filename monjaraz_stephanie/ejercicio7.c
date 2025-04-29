/*

* Crea un programa donde simule la gestión de pacientes de un hospital (nombre, edad,
*diagnostico y prioridad). En prioridad ( 1- 3, donde 1 es urgente) (3 pts.). Hint: Use una
*lista enlazada, donde cada nodo sea un Paciente y un apuntador al siguiente nodo.

*1. Funciones para: Un paciente al inicio de la lista, Eliminar un paciente por nombre,
*Imprimir la lista actualizada
*2. En el Main: Se añaden 10 pacientes con diferentes prioridades, se eliminan a 2
*pacientes en específicos, y se actualiza la lista.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estructura paciente
struct Paciente{
    char nombre[50];
    int edad;
    char diagnostico[100];
    int prioridad;
    struct Paciente *siguiente;//apuntador al siguiente nodo
};



// funcion para agrgar un paciente al inicio de la lista
void agregarPacienteUp(struct Paciente** cabeza, char nombre[], int edad, char diagnostico[], int prioridad){
    struct Paciente* nuevo = (struct Paciente*)malloc(sizeof(struct Paciente)); //asigma mmemoria con malloc

    if (nuevo == NULL){ //avisa si no se pudo asignar memoria
        printf("Error al asignar memoria para nuevo paciente.\n");
        return;

    }


    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    strcpy(nuevo->diagnostico, diagnostico);
    nuevo->prioridad = prioridad;

    nuevo->siguiente = *cabeza; //el nuevo nodo apunta a lo que era la cabeza
    *cabeza = nuevo;          //y la cabeza apunta al nueevo nodo
}

// funcion para imprimir la lista de pacientes
void imprimeLista(struct Paciente* cabeza){
    printf("\n\n\t\t\tINFORMACION DE PACIENTES:\n\n");
    printf("Nombre\t\t\t\tEdad\tDiagnóstico\t\t\t\t\t\tPrioridad\n");
    struct Paciente* actual = cabeza;
    while (actual != NULL){
        printf("%-30s\t%i\t%-35s\t\t\t\t%-14i\n", 
               actual->nombre, 
               actual->edad, 
               actual->diagnostico, 
               actual->prioridad);
        actual = actual->siguiente;

    }
}

// función para eliminar un paciente por su nombre
void eliminarPaciente(struct Paciente** cabeza, char nombre[]){
    struct Paciente* actual = *cabeza; //apuntador al primer nodo
    struct Paciente* anterior = NULL;// apuntador al nodo anterior


    while (actual != NULL && strcmp(actual->nombre, nombre) != 0){ //mientras no sea NULL y el nombre no coincida
        anterior = actual;// guard el nodo actual
        actual = actual->siguiente;//pasa al siguiente nodo
    }


    if (actual == NULL){//si no se encontró el paciente

        printf("Paciente '%s' no encontrado.\n", nombre);
        return;

    }


    if (anterior == NULL) {
        *cabeza = actual->siguiente; //era el primero
    } else{
        anterior->siguiente = actual->siguiente;//lo saltamos
    }
// *siempre liberar la memoria al termino del programa
    free(actual);
    printf("Se eliminó al Paciente: %s.\n", nombre);
}



int main(){

    struct Paciente* lista = NULL;

    //pacientes de "La historia del loco"
    agregarPacienteUp(&lista, "Francis Petrel", 21, "Esquizofrenia paranoide", 2);
    agregarPacienteUp(&lista, "Evans “El Señor del Mal”", 47, "Psicopatía severa", 1);
    agregarPacienteUp(&lista, "Cleo", 35, "Trastorno de identidad disociativo", 3);
    agregarPacienteUp(&lista, "Napoleón", 45, "Trastorno delirante", 2);
    agregarPacienteUp(&lista, "Noticiero", 28, "Trastorno obsesivo-compulsivo", 2);
    agregarPacienteUp(&lista, "Paciente anónimo A", 28, "Trastorno de identidad disociativo", 3);
    agregarPacienteUp(&lista, "Thomas Reed", 40, "Esquizofrenia desorganizada", 1);
    agregarPacienteUp(&lista, "Isaac Monroe", 55, "Depresión mayor resistente", 2);
    agregarPacienteUp(&lista, "Samuel Bishop", 40, "Trastorno de estrés postraumático", 3);
    agregarPacienteUp(&lista, "larisse Vega", 28, "Anorexia nerviosa severa", 1);
    
    printf("\nLista actual de los pacientes del Western State Hospital:");
    imprimeLista(lista);


    //eliminamos dos pacientes 
    eliminarPaciente(&lista, "Cleo");
    eliminarPaciente(&lista, "Paciente anónimo A");


    //lista final
    printf("\nLista actualizada:");
    imprimeLista(lista);

    return 0;


}
