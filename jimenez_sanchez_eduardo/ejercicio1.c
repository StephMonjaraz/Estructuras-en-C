//Jimenez Sanchez Eduardo Yael  Tarea 3 curso de C
#include <stdio.h>
#include <string.h>

typedef struct      //Defini la estructura Coche
{
    char marca[15];     //Inicalizando variable para la marca del coche
    char modelo[15];    //Inicalizando variable para el modelo del coche
    int año;            //Inicalizando variable para el año del coche
} Coche;

void modificar(Coche *coche)        //Funcion para modificar los datos del coche 
                                    //(Recibe un apuntador)
{
    strcpy(coche->marca, "Mazda");  //Se accede a los campos de la estructura
    strcpy(coche->modelo, "cx-70");
    coche->año=2025;
}

int main() //Funcion principal donde se cambioan los datos de la estructura Coche
{
    Coche viejo = {"Nissan","Altima", 2023};
    printf("Marca: %s \n", viejo.marca);
    printf("Modelo: %s \n", viejo.modelo);
    printf("Año: %d \n", viejo.año);

    printf("\nCompre un carro nuevo!\n");

    modificar(&viejo);      //Se pasa la direccion del coche
    printf("\nMarca: %s \n", viejo.marca);
    printf("Modelo: %s \n", viejo.modelo);
    printf("Año: %d \n", viejo.año);

    return 0;
}

