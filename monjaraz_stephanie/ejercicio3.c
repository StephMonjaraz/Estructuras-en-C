/*
* Crea una función que retorne una estructura Punto con coordenadas aleatorias.
*/

#include<stdio.h>
#include<stdlib.h> // libreria para poder usar rand() (genera los numeros aleatorios)
#include <time.h> // libreria para poder usar time() (para inicializar el generador de numeros aleatorios)

struct Punto //estructura punto (x, y)
{
    int x;
    int y;
};

struct Punto Coordenadas_aleatorias() //funcion que crea un punto aleatorio
{

    struct Punto p;
    //asignamos valores aleatorio para x y y, en el ranfo de 0 a 100
    p.x=rand()%100; 
    p.y=rand()%100; 
    return p;
}

int main (){

    srand(time(NULL)); //seed random o smilla aleatoria, inicializa el generador de numeros aleatorios
  
    printf("\nLas coordenadas obtenidas son:\n\n");

    
    for (int i = 0; i < 5; i++) { //para poder generar 5 puntos aleatorios
        struct Punto p = Coordenadas_aleatorias(); // Genera un nuevo p aleatorio
        printf("Punto %i: (%i, %i)\n", i + 1, p.x, p.y); 
    }


    return 0;
}


