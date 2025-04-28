//Jimenez Sanchez Eduardo Yael  Tarea 3 curso de C
#include <stdio.h>

typedef struct      //Defini la estructutra para los productos
{
    char Nombre[30];    //Variable de tipo char para el nombre
    float Precio;       //variable de tipo float para el Precio
    int Cantidad;       //variable de tipo int para la cantidad de productos
} Productos;

float CalcularTotal(Productos producto[], int numProductos) //Funcion que recible un arreglo y su tamaño
{
    float total=0;  //Se inicializa la variable del total en cero
    for(int i=0; i<numProductos; i++)
    {
        total+=producto[i].Precio * producto[i].Cantidad;   //se suman precio*cantidad de cada producto
    }
    return total;
}

int main()      //funcion principal 
{
    Productos inventario[4] = {     //Arreglo del inventario con cuatro productos
        {"Laptop", 9500, 12},       //Producto 1
        {"Television", 7300, 7},    //Producto 2
        {"Xbox", 7599, 30},         //Producto 3
        {"Audifonos", 1759, 17}     //Producto 4
    };

    float totalInventario=CalcularTotal(inventario, 4); //Asigna el valor del total 
                                                        //del inventario a la variable
    printf("El precio total del inventario es: %.2f \n", totalInventario);  //Imprime el total
    return 0;
}