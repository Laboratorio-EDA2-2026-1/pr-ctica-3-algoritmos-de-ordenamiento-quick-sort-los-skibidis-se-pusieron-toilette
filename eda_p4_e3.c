#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
  Ejercicio 3. El problema del papá tacaño.

  Entrada sugerida:
    n
    t1 t2 ... tn

  Donde cada token ti es:
    - un entero positivo (costo conocido), o
    - una letra MAYÚSCULA (costo desconocido, p. ej. X, Y, Z)

  Restricciones:
    1) n >= 3
    2) Los costos conocidos son enteros positivos
    3) Hay al menos 1 costo desconocido y al menos 1 costo conocido
    4) Todo desconocido es mayor que cualquier conocido
    5) Si la mayoría son desconocidos, elegir uno al azar
*/

/* Representación de cada destino */
typedef struct {
    int es_conocido;   // 1 si el costo es conocido, 0 si es desconocido
    int costo;         // válido solo si es_conocido == 1
    char etiqueta;     // válido solo si es_conocido == 0 (p. ej., 'X', 'Y')
} Destino;

/* Imprime el arreglo de destinos tal como se interpretó */
void imprimir_destinos(const Destino *destinos, int n) {
    printf("Destinos interpretados: [ ");
    for (int i = 0; i < n; i++) {
        if (destinos[i].es_conocido) {
            printf("%d", destinos[i].costo);
        } else {
            printf("%c", destinos[i].etiqueta);
        }
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

// Me robe su funcion profe. Solo para arreglos en general
void imprimir_arr(const int *destinos, int size) {

    printf("[ ");

    for (int i = 0; i < size; i++) {

        printf("%d", destinos[i]);

        if (i < size - 1) printf(", ");
    }
    printf(" ]\n");
}

/* Utilidad: parsea un token; retorna 1 si es válido, 0 si no. */
int parsear_token(const char *tok, Destino *d) {
    // Si empieza con dígito, lo tratamos como costo conocido
    if (isdigit((unsigned char)tok[0])) {
        // Validar que sea entero positivo
        for (int i = 0; tok[i]; i++) {
            if (!isdigit((unsigned char)tok[i])) return 0;
        }
        long val = strtol(tok, NULL, 10);
        if (val <= 0) return 0;
        d->es_conocido = 1;
        d->costo = (int)val;
        d->etiqueta = '\0';
        return 1;
    }
    // Si es una letra MAYÚSCULA (una sola), lo tratamos como desconocido
    if (strlen(tok) == 1 && tok[0] >= 'A' && tok[0] <= 'Z') {
        d->es_conocido = 0;
        d->costo = 0;
        d->etiqueta = tok[0];
        return 1; 
    }
    return 0;
}

/*
 * FUNCIÓN A IMPLEMENTAR
 *
 * Objetivo general:
 *   Seleccionar el índice del destino cuya "propuesta de costo" sea la
 *   más cercana a la "media" considerada en el total (ver reglas).
 *
 * Reglas a incorporar en tu solución:
 *   (1) Siempre hay >= 3 destinos.
 *   (2) Costos conocidos: enteros positivos.
 *   (3) Hay al menos un conocido y al menos un desconocido.
 *   (4) Todo desconocido es MAYOR que cualquier conocido.
 *   (5) Si la mayoría son desconocidos, elegir uno al azar.
 *
 * Comentarios-guía (NO OBLIGATORIOS, solo orientación):
 *   - Paso 1: contar cuántos conocidos y desconocidos hay.
 *   - Paso 2 (Regla 5): si desconocidos > conocidos, elige uno al azar
 *            entre los desconocidos y retorna su índice.
 *   - Paso 3: define tu estrategia para la "media". Por ejemplo:
 *       * usar la media de los costos conocidos,
 *       * y tratar los desconocidos como "mayores que todo conocido"
 *         (puedes usar una cota, p. ej., maxConocido + 1, o un valor simbólico).
 *     Justifica en tu reporte/README cómo aproximas la media bajo la Regla 4.
 *   - Paso 4: encuentra el índice cuyo "costo (o valor representativo)"
 *             esté más cercano a la media. En caso de empate, define
 *             una política simple, p. ej., el de menor índice.
 */
int elegir_destino(const Destino *destinos, int size) {

	// printf("Eligiendo destinos... \n");

    // Escribe aquí tu función

    // Sugerencias de variables que podrías usar:
    // int conocidos = 0, desconocidos = 0;
    // int indice_elegido = -1;
    // int max_conocido = ...; // para apoyar la Regla 4 si asignas un valor simbólico
    // double media = 0.0;

    // 1) Contar conocidos vs desconocidos

    // 2) Si desconocidos > conocidos:
    //      - Elegir aleatoriamente entre índices con es_conocido == 0
    //      - return indice_aleatorio;

    // 3) Calcular "media" según tu diseño
    //      - p. ej., media de costos conocidos
    //      - asignar valor representativo a desconocidos respetando Regla 4

    // 4) Hallar el índice con distancia mínima a la media
    //      - manejar empates de forma determinista (p. ej., menor índice)

    // return -1; // Placeholder: reemplaza por el índice elegido

    int conocidos=0, desconocidos=0;
    int indice_elegido = -1;
    int indice_aleatorio = rand()%size;
    int conocidoArr[size+1];
    int promedio=0;

    //printf("Dest. totales:      %d \n", size);

    for (int i=0; i<size; i++) {

    	if (destinos[i].es_conocido) {  			    // Cuenta el numero de conocidos
    		                						    // y desconocidos. Si es conocido,
    		conocidoArr[conocidos] = destinos[i].costo; // lo mete al arr de conocidos.
    		conocidos++; 

    	} else desconocidos++; // Si el numero es desconocido, solo aumenta su cuenta.
    	
    }

    printf("Dest. conocidos:    %d ", conocidos);
    imprimir_arr(conocidoArr, conocidos);
    printf("Dest. desconocidos: %d \n", desconocidos);

    /*Caso donde hay mas desconocidos que conocidos */
    if (conocidos<desconocidos) {

    	printf("Demasiados desconocidos. Indice elegido: %d\n", indice_aleatorio);
    	return indice_aleatorio;

    } else {

    	for (int i=0; i<conocidos; i++) {
    		promedio = promedio + conocidoArr[i];
    	}
    	promedio = promedio / conocidos;
    	printf("Promedio de destinos conocidos: %d \n", promedio);
    }

    for (int i=0; i<conocidos; i++) {
    	if (conocidoArr[i] < promedio) indice_elegido = i;
    	indice_elegido--;
    }

    return indice_elegido;

}

int main(void) {

    int n;
    printf("Cuantos destinos ingresara: ");
    if (scanf("%d", &n) != 1 || n < 3) {
        fprintf(stderr, "Error: n inválido (debe ser >= 3).\n");
        return 1;
    }

    Destino *destinos = (Destino *)malloc(n * sizeof(Destino));
    if (!destinos) {
        fprintf(stderr, "Error: memoria insuficiente.\n");
        return 1;
    }

    // Semilla para la Regla 5 (elección aleatoria cuando la mayoría es desconocida)
    srand((unsigned int)time(NULL));

    // Leer n tokens
    printf("Ingrese destinos: ");
    for (int i = 0; i < n; i++) {
        char tok[64];
        if (scanf("%63s", tok) != 1) {
            fprintf(stderr, "Error: no se pudo leer el token %d.\n", i + 1);
            free(destinos);
            return 1;
        }
        if (!parsear_token(tok, &destinos[i])) {
            fprintf(stderr, "Error: token inválido en la posición %d: '%s'.\n", i + 1, tok);
            free(destinos);
            return 1;
        }
    }

    // Verificación mínima de las restricciones 3 y 4
    int hay_conocido = 0, hay_desconocido = 0;
    for (int i = 0; i < n; i++) {
        if (destinos[i].es_conocido) hay_conocido = 1; else hay_desconocido = 1;
    }
    if (!hay_conocido || !hay_desconocido) {
        fprintf(stderr, "Error: debe haber al menos un costo conocido y al menos uno desconocido.\n");
        free(destinos);
        return 1;
    }

    // (Opcional) Mostrar cómo se interpretó la entrada
    imprimir_destinos(destinos, n);

    // Llamar a la función a implementar
    int indice = elegir_destino(destinos, n);
    if (indice < 0 || indice >= n) {
        fprintf(stderr, "Advertencia: índice no válido devuelto por elegir_destino.\n");
        free(destinos);
        return 1;
    }

    // Salida: imprime el destino elegido tal cual fue ingresado
    printf("Destino elegido (lugar %d): ", indice+1);
    if (destinos[indice].es_conocido) {
        printf("%d\n", destinos[indice].costo);
    } else {
        printf("%c\n", destinos[indice].etiqueta);
    }

    free(destinos);
    return 0;
}

/*
Ejemplos de uso (solo referencia; la elección final depende de tu implementación):

Ejemplo 1:
Entrada
6
241 42 362 X 79 Y

Salida (posible)
Destinos interpretados: [ 241, 42, 362, X, 79, Y ]
Destino elegido (índice k): <valor o etiqueta>

Ejemplo 2:
Entrada
5
A 10 20 B 30

Salida (posible)
Destinos interpretados: [ A, 10, 20, B, 30 ]
Destino elegido (índice k): <valor o etiqueta>
*/