#include <stdio.h>      
#include <stdlib.h>     // contiene malloc, free

typedef struct  // Defini la estructura
{
    char titulo[50];        // Variable para el título
    char autor[50];         // Variable para el autor
    int año;                // Variable para el año
} Libro;

int main()  // Función principal
{
    int numLibros;          // Número de libros
    int i;                  // Contador para el ciclo
    Libro *biblioteca;      // Puntero a arreglo dinámico de libros

    printf("Cuántos libros quieres agregar: ");
    scanf("%d", &numLibros);

    // Se reserva la memoria para los libros
    biblioteca = (Libro *)malloc(numLibros * sizeof(Libro));
    if (biblioteca == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (i = 0; i < numLibros; i++)         //solicita la informacion del libro
    {
        printf("\nLibro %d\n", i + 1);

        printf("Título: ");
        scanf(" %s ", biblioteca[i].titulo); //recibe el titulo

        printf("Autor: ");
        scanf(" %s", biblioteca[i].autor);  //recible el autor

        printf("Año: ");
        scanf("%d", &biblioteca[i].año);       //recibe el año
    }

    printf("\n--- Lista de libros ---\n");  //muestra catalogo de libros
    for (i = 0; i < numLibros; i++) {
        printf("Libro %d: %s, por %s (%d)\n", 
               i + 1, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].año);
    }

    free(biblioteca);     // Liberamos la memoria

    return 0;
}
