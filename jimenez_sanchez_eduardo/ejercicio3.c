//Jimenez Sanchez Eduardo Yael  Tarea 3 curso de C
#include <stdio.h>
#include <stdlib.h>  //incluy rand()
#include <time.h>    // Para usar time()

typedef struct      //Defini la estructura de un punto
{
    int x;
    int y;
} Punto;

int aleatorio(int min, int max)     //Funcion para generar un numero aleatoria entre un min y un max
{
    return (rand() % (max - min + 1)) + min;    //numero pseudoaleatorio
}

Punto puntoAleatorio()  //Estructura que devuelve un punto con coordenadas aleatorias
{
    Punto casa;
    casa.x = aleatorio(-70,70); //coord x
    casa.y = aleatorio(-70,70); //coord y
    return casa;
}

int main()
{
    srand(time(NULL));      //se toma el tiempo para generar los numero aleatorios
    Punto casa = puntoAleatorio();

    printf("Las coordenadas de mi casa son x=%d , y=%d \n", casa.x, casa.y);
    return 0;
}
