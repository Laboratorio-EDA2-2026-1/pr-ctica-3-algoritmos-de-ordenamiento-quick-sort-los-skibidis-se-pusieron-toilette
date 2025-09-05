[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/3RIBfofK)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=20328639&assignment_repo_type=AssignmentRepo)
# Práctica 3. Algoritmos de Ordenamiento.
## Quick Sort.

La práctica consta de ejercicios, las instrucciones de los cuales se presentan a continuación.

## Ejercicio 1.
Termina de escribir la implementación del algoritmo QuickSort (recuerda que en la última clase, se nos acabó el tiempo antes de terminar la versión final del pseudocódigo).

## Ejercicio 2.
Escribe una implementación diferente para el algoritmo QuickSort en el que el pivote es el promedio de los valores ingresados (incluso si éste no pertenece a la lista).

### Restricciones: 
1. El pivote se calcula como el promedio (tipo double) de los elementos entre los índices bajo y alto.
2. El pivote no se inserta en el arreglo; únicamente se usa para decidir cómo partir el arreglo.
3. Se debe definir una convención de partición clara. Ejemplo sugerido:
  -A la izquierda: todos los elementos < pivote.
  -A la derecha: todos los elementos ≥ pivote.

4. El algoritmo debe funcionar incluso si el promedio no es un número entero.
5. El algoritmo debe garantizar progreso (evitar ciclos infinitos), por ejemplo, asegurando que siempre haya movimiento de índices en la partición.

 ### Casos borde a considerar
1. Todos los elementos iguales.
   - El promedio = valor común.
   - La convención >= pivote debe garantizar que el arreglo no quede atascado en recursión infinita.

2. Varios elementos repetidos.
   - Si hay valores repetidos alrededor del pivote, verifica que la partición no pierda elementos.

3. Arreglo muy pequeño.
   - Para subarreglos de tamaño 0 o 1 (bajo >= alto), se debe cortar la recursión inmediatamente.

4. Promedio con decimales.
   - Ejemplo: subarreglo `[2, 5, 9]`.
   - Promedio = 16 / 3 = 5.33.
   - Convención: < 5.33 a la izquierda (2, 5), >= 5.33 a la derecha (9).

## Ejercicio 3. El problema del papá tacaño.
Una familia está de viaje en una ciudad nueva. Cada día del viaje, observan las opciones de lugares que hay por visitar para planear su itinerario. El papá tacaño, en lugar de ver lo atractivo de las opciones, ve el costo que les tomará llegar a cada uno de dichos lugares. No queriendo ser injusto con su familia, les propone el lugar cuyo costo se aproxima a la media de los costos en total. 

Restricciones: 
1. Siempre se consideran al menos tres destinos turísticos.
2. El costo de todo destino turístico es un entero positivo.
3. En cada lista de opciones, se considera, al menos, una opción cuyo costo es desconocido, lo que se representa con una letra mayúscula (por ejemplo, `X`), y al menos una opción cuyo costo es conocido. Un ejemplo de entrada admisible es `Input: [241, 42, 362, X, 79, Y]`.
4. Siempre se supone que los destinos cuyo costo es desconocido tienen un costo mayor que aquellos para los cuales es conocido.
5. Si en una lista de opciones, la mayoría de los destinos tiene costo desconocido, entonces se elige un al azar.

## Ejercicio 4. Problema de las tuercas y los tornillos. 
Se tiene un conjunto de `n` tuercas de diferentes tamaños y `n` tornillos de diferentes tamaños. Existe una correspondencia uno a uno entre las tuercas y los tornillos (cada tornillo corresponde exactamente a una tuerca). El problema consiste en emparejar eficientemente tuercas y tornillos.

Restricción:
No está permitido comparar una tuerca con otra tuerca, ni un tornillo con otro tornillo. Solo se puede comparar una tuerca con un tornillo (o un tornillo con una tuerca) para determinar cuál es más grande o más pequeño.
