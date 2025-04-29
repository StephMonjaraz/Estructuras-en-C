/*
* Crea un arreglo dinámico de estructuras Libro usando Malloc. 
* Hint (1): Usen Malloc e investiguen como es una estructura dinámica).
* Hint (2): Para asignación de la memoria puede usar: libros = (Libro*)malloc(nLibros * sizeof(Libro));

* Este programa servira como un registro de libros leídos, donde el usuario puede ingresar
* información sobre cada libro, como el título, autor, editorial, año de publicación, número de páginas,
* precio y calificación personal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Libro {//estructura libro
    char titulo[50];
    char autor[50];
    char editorial[50];
    int aPublicacion;
    float precio;
    float calificacion; 

};


int main() {


    int nLibros;
    struct Libro* libros; //arreglo dinámico de estructuras Libro


    printf("Dime, ¿Cuantos libros quieres registrar?: "); //solcita al usuario cuántos libros ha leído
    scanf("%d", &nLibros);

    libros = (struct Libro*)malloc(nLibros * sizeof(struct Libro)); //usamos malloc para reservar memoria

    if (libros == NULL) {

        printf("Error al asignar memoria.\n");
        return 1;

    }



    for (int i = 0; i < nLibros; i++) {
        printf("\nLibro %d:\n", i + 1);

        printf("Título: ");
        scanf(" %[^\n]", libros[i].titulo);
        printf("Autor: ");
        scanf(" %[^\n]", libros[i].autor);
        printf("Editorial: ");
        scanf(" %[^\n]", libros[i].editorial);
        printf("Año de publicación: ");
        scanf("%d", &libros[i].aPublicacion);
        printf("Precio: ");
        scanf("%f", &libros[i].precio);
        printf("Del 0-10 ¿Qué calificaciṕn le darías al libro?: ");
        scanf("%f", &libros[i].calificacion);

    }



    printf("\n\n📚 Lista de libros leídos:\n\n");
    printf("Título\t\t\tAutor\t\tAño\tPrecio\tCalif.\n");



    for (int i = 0; i < nLibros; i++) { //para imprimir los libros
        //para darle formato a la tabla, usa el -20 para que el nombre del producto ocupe 20 espacios,
        printf("%-20s\t%-15s\t%d\t%.2f\t%.1f\n",
               libros[i].titulo,
               libros[i].autor,
               libros[i].aPublicacion,
               libros[i].precio,
               libros[i].calificacion);
    }


    // *siempre liberar la memoria al termino del programa
    free(libros);
    return 0;
}
