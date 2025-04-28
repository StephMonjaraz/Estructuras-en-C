#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      //estructura para libro
{
    char titulo[50];    //variable para el titulo
    char autor[50];     //variable para el autor
    int año;            //variable para el año
    int disponible;     //1 disponible, 0 no disponible
}   Libro;

Libro* añadirLibro(Libro *catalogo, int *numLibros, Libro *nuevo)   //funcion de tipo puntero para añadir libros
{
    catalogo = realloc(catalogo, (*numLibros + 1) * sizeof(Libro)); //reserva la memoria
    if (catalogo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    catalogo[*numLibros] = *nuevo;
    (*numLibros)++;
    return catalogo;
}


// funcion para eliminar un libro por título
Libro* eliminarLibro(Libro *catalogo, int *numLibros, const char *titulo) {
    int encontrado = -1;
    for (int i = 0; i < *numLibros; i++) 
    {
        if (strcmp(catalogo[i].titulo, titulo) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < *numLibros - 1; i++) {
            catalogo[i] = catalogo[i + 1];
        }
        (*numLibros)--;
        catalogo = realloc(catalogo, (*numLibros) * sizeof(Libro));
    } else {
        printf("Libro \"%s\" no encontrado.\n", titulo);
    }
    return catalogo;
}

// mostrar el catálogo
void mostrarCatalogo(Libro *catalogo, int numLibros) 
{
    printf("\n--- Catálogo de libros ---\n");
    for (int i = 0; i < numLibros; i++) {
        printf("Título: %s\n", catalogo[i].titulo);
        printf("Autor: %s\n", catalogo[i].autor);
        printf("Año: %d\n", catalogo[i].año);
        printf("Disponible: %s\n\n", catalogo[i].disponible ? "Sí" : "No");
    }
}

int main() 
{
    Libro *catalogo = NULL;
    int numLibros = 0;
    int opcion;

    Libro librosIniciales[7] = // arreglo de 7 libros iniciales 
    {
        {"Cien años de soledad", "Gabriel Garcia Marquez", 1967, 1},
        {"Don Quijote de la Mancha", "Miguel de Cervantes", 1605, 1},
        {"Orgullo y prejuicio", "Jane Austen", 1813, 1},
        {"1984", "George Orwell", 1949, 1},
        {"La Odisea", "Homero", -800, 1},
        {"El principito", "Antoine de Saint-Exupery", 1943, 1},
        {"Harry Potter y la piedra filosofal", "J.K. Rowling", 1997, 1}
    };

    for (int i = 0; i < 7; i++) {
        catalogo = añadirLibro(catalogo, &numLibros, &librosIniciales[i]);
    }

    // Eliminar 3 libros específicos automáticamente
    catalogo = eliminarLibro(catalogo, &numLibros, "Don Quijote de la Mancha");
    catalogo = eliminarLibro(catalogo, &numLibros, "Cien años de soledad");
    catalogo = eliminarLibro(catalogo, &numLibros, "Harry Potter y la piedra filosofal");

    do     // menu interactivo
    {
        printf("\n--- Menú ---\n");
        printf("1. Añadir libro\n");
        printf("2. Eliminar libro\n");
        printf("3. Mostrar catálogo\n");
        printf("4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar 

        if (opcion == 1) 
        {
            Libro nuevo;
            printf("Título: ");
            fgets(nuevo.titulo, sizeof(nuevo.titulo), stdin);
            nuevo.titulo[strcspn(nuevo.titulo, "\n")] = '\0';

            printf("Autor: ");
            fgets(nuevo.autor, sizeof(nuevo.autor), stdin);
            nuevo.autor[strcspn(nuevo.autor, "\n")] = '\0';

            printf("Año: ");
            scanf("%d", &nuevo.año);
            getchar(); // limpiar buffer

            nuevo.disponible = 1; //  disponible cuando se agrega

            catalogo = añadirLibro(catalogo, &numLibros, &nuevo);

        } else if (opcion == 2) {
            char titulo[100];
            printf("Título del libro a eliminar: ");
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            catalogo = eliminarLibro(catalogo, &numLibros, titulo);

        } else if (opcion == 3) {
            mostrarCatalogo(catalogo, numLibros);

        } else if (opcion == 4) {
            printf("Saliendo del programa...\n");

        } else {
            printf("Opción no válida.\n");
        }

    } while (opcion != 4);

    free(catalogo);     // libera memoria antes de salir

    return 0;
}
