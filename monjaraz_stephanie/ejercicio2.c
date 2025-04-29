/*
* Crea un arreglo de estructuras Producto (nombre, 
* precio, cantidad) y calcula el valor total de inventario.
*/

#include<stdio.h>

struct Producto //Estructura producto (nombre, precio y cantidad)
{
    char nombre[30];
    float precio;
    int cantidad;
};

int main (){
        
    struct Producto inventario[5] = {
        /// Asignamos valores a csda producto al momento de inicializar el arreglo.
        {"Ribbon", 589, 1},//589
        {"Espresso", 700, 5}, //3500
        {"Shortcake", 600, 3}, //1800
        {"CinnamonRoll", 690, 2},//1380
        {"Toast", 580, 3} //1740

    };

    float Subtotal = 0; //inicializamos la variable subtotal en 0
    float total = 0; //inicializamos la variable total en 0


    // Estado actual del inventario
    printf("\n\n\t\t\tINVENTARIO:\n\n");
    printf("Producto\t\tPrecio\tCantidad\tSubtotal\n");

        

    for (int i = 0; i < 5; i++)//recorre el arreglo 
    {

         //el total se obtiene multiplicando el precio por la cantidad de products que se compraro.
         Subtotal = inventario[i].precio * inventario[i].cantidad; 

        // para darle formato a la tabla, usa el -16 para que el nombre del producto ocupe 16 espacios,
        printf("%-16s\t%.2f\t%i\t\t%.2f\n",inventario[i].nombre, inventario[i].precio,   inventario[i].cantidad, Subtotal);
        total += Subtotal; //obtenems el total sumando todos los subtotales de cda producto
    }

    printf("\n El inventario tiene un valor de: %.2f\n\n", total); //imprime el total del inventario


    
}
