#include <stdio.h>
#include <stdlib.h>

/*
  Ejercicio: QuickSort con pivote = promedio de los valores en el subarreglo.

  Requisitos:
    - El pivote es el promedio (double) de los valores del segmento actual.
    - El pivote puede NO pertenecer al arreglo.
    - En el arreglo de salida solo pueden aparecer valores del arreglo original
      (NO se inserta el pivote como elemento).

  Sugerencia de diseño (no obligatorio):
    - calcular_promedio_segmento(arr, bajo, alto) -> double
    - particion_por_promedio(arr, bajo, alto, pivote) -> índice final (int)
      (reorganizar comparando cada arr[i] con el pivote)
    - quicksort_promedio(arr, bajo, alto) -> recursivo
*/

static inline void intercambiar(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}


double calcular_promedio_segmento(int arr[], int bajo, int alto) {
    double piv;     // pivote donde se guardan los valores

    for (int i = bajo; i<=alto ; i++) {
        piv = piv + arr[i];                 // Se recorre el arreglo hasta que se sumen todos los valores
    }

    piv = piv/(alto - bajo);                // Se saca el promedio

    return piv;                             // Se regresa el valor del pivote
}


int particion_por_promedio(int arr[], int bajo, int alto, double pivote) {

    int i = bajo; int j = alto;         // cambio por variables mas simples

    while(1){
        while(arr[i] < pivote){         // - Mientras los elementos izquierdos (si se toma el inicio)
            i++;                        //   sean menores al pivote el indice continua avanzando
        }

        while(arr[j] >= pivote){        // >= para encontrar duplicados
            j--;            
        }
        if(i >= j) {                    // Si bajo>=alto quiere decir que debe no hay que intercambiar
        return j;                       // Se retorna el indice donde se quedó para dividir el arreglo
        } else {
            intercambiar(&arr[i] ,&arr[j]);   // Else, encontramos un valor no ordenado
            i++;                                 // Continuamos los indices
            j--;
        }
    }
}

/*
  QuickSort con pivote = promedio:
    - Caso base: si bajo >= alto, terminar.
    - Paso:
        1) pivote = promedio de arr[bajo..alto]
        2) k = particion_por_promedio(arr, bajo, alto, pivote)
        3) Llamar recursivamente a los segmentos definidos por k
*/
void quicksort_promedio(int arr[], int bajo, int alto) {
    if (bajo>=alto){                                        // Caso base
        return;
    } else {
        int pivote = calcular_promedio_segmento(arr, bajo, alto);
        int k = particion_por_promedio(arr, bajo, alto, pivote);   // Aplicar particion en indice
        quicksort_promedio(arr, bajo, k);              // QS en primera mitad
        quicksort_promedio(arr, k + 1, alto);          // QS en segunda mitad
    }
}

/* Utilidad para imprimir un arreglo */
void imprimir_arreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: n inválido.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: entrada inválida en la posición %d.\n", i + 1);
            free(arr);
            return 1;
        }
    }

    // Antes
    // printf("Antes:  "); imprimir_arreglo(arr, n);

    quicksort_promedio(arr, 0, n - 1);

    // Después
    imprimir_arreglo(arr, n);

    free(arr);
    return 0;
}

/*
Ejemplo de uso:
Entrada:
8
5 2 9 2 7 10 3 6

Salida esperada:
2 2 3 5 6 7 9 10

Notas de implementación:
- La media puede ser no entera; compárala como double contra enteros.
- Define claramente qué lado incluye los == pivote para asegurar terminación.
- No insertes el pivote en el arreglo (restricción).
*/
