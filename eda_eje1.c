#include <stdio.h>
#include <stdlib.h>

/*
  Ejercicio: Completar la implementación del algoritmo QuickSort.

  Recordatorio:
    - QuickSort es un algoritmo de ordenamiento basado en "divide y conquista".
    - Se elige un pivote y se reordenan los elementos de modo que:
         * a la izquierda del pivote: menores o iguales,
         * a la derecha del pivote: mayores.
    - Luego se aplica recursivamente en las dos mitades.
*/

/* Función para intercambiar dos elementos */
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int particion(int arr[], int bajo, int alto) {
    int pivote = arr[bajo];

    while(1){
        while(arr[bajo] < pivote){      // - Mientras los elementos izquierdos (si se toma el inicio)
            bajo++;                     //   sean menores al pivote el indice continua avanzando
        }

        while(arr[alto] > pivote){
            alto--;            
        }
        if(bajo >= alto) {                  // Si bajo>=alto quiere decir que debe no hay que intercambiar
        return alto;                        // Se retorna el indice donde se quedó para dividir el arreglo
        } else {
            intercambiar(&arr[bajo] ,&arr[alto]);   // Else, encontramos un valor no ordenado
            bajo++;                                 // Continuamos los indices
            alto--;
    }
    }
}

void quicksort(int arr[], int bajo, int alto) {
    if (bajo>=alto){                                        // Caso base
        return;
    } else {
        int indiceParticion = particion(arr, bajo, alto);   // Aplicar particion en indice
        quicksort(arr, bajo, indiceParticion);              // QS en primera mitad
        quicksort(arr, indiceParticion + 1, alto);          // QS en segunda mitad
    }
}

/* Función auxiliar para imprimir un arreglo */
void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        return 1;
    }

    printf("Ingrese los %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Arreglo original:\n");
    imprimir_arreglo(arr, n);

    quicksort(arr, 0, n - 1);  // Llamada al algoritmo

    printf("Arreglo ordenado:\n");
    imprimir_arreglo(arr, n);

    free(arr);
    return 0;
}
