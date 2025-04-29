/*
* Programa para usar un apuntador que modifique los datos de una estructura Coche 
*/
#include <stdio.h>
#include <string.h>


struct MyCar{   // struct: para agrupar un conjunto de variables que tienen caracteristicas en común. 
    //arreglos
    char marca[20];        
    char modelo[20];      
    char color[40];
    //enteros       
    int anio;               
}; 

void mostrarCoche(struct MyCar *coche){ //solo para imprimir los datos. Ayuda a evtar repetición de código
    printf("\n%s %s del año %d, en un distinguido color %s.\n\n", 
           coche->marca, coche->modelo, coche->anio, coche->color);
}

int main(){
    // Creamos un "coche real" a partir del molde (estructura)
    struct MyCar miCoche;  // crea un objeto a partir de un molde. Ahora el programa tiene un espacio en memoria 
                          //donde puede guardar, modificar o leer los datos de mi coche. 
    struct MyCar *ptrCoche; //declaro el apuntador Coche. 
    ptrCoche = &miCoche; //ahora el apuntador apunta a la dirección de memoria en dode esta miCoche. 


     //*------------------------------------------------------------------------*//
    // Valores iniciales de MyCar
    strcpy(miCoche.marca, "Rolls-Royce");
    strcpy(miCoche.modelo, "Silver Ghost");
    strcpy(miCoche.color, "Plata brillante");
    miCoche.anio = 1907;
    printf("\nSu modelo anterior era:");
    mostrarCoche(ptrCoche);

    //*------------------------------------------------------------------------*//
    // Modifica los datos de MyCar
    strcpy(ptrCoche->marca, "Rolls-Royce");
    strcpy(ptrCoche->modelo, "Phantom II");
    strcpy(ptrCoche->color, "Azul marino con detalles en plata");
    ptrCoche->anio = 1930;



    printf("\nNuevo modelo elegido:");
    mostrarCoche(ptrCoche);

    return 0;
}
