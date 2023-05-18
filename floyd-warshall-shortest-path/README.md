[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6067080&assignment_repo_type=AssignmentRepo)
# Homework 07 - Floyd-Warshall for finding the shortest path

## Propósito
Entender a partir de su implementación el funcionamiento del algoritmo de Floyd-Warshall para encontrar un árbol de expansión mínima en un grafo ponderado dirigido.


## Instrucciones
La tarea será resuelta en equipos de hasta 2 estudiantes.

Implementar en C++ el algoritmo de Floyd-Warshall para encontrar un árbol de expansión mínima en un grafo ponderado dirigido. ([TC2038_12_Shortest Path Floyd Warshall_wNotes.pdf](https://experiencia21.tec.mx/courses/173572/files/65062749/))

El programa recibe como argumentos un número entero N (indicando la cantidad de aristas), seguido de N valores indicando el nodo de origen de las aristas, seguido N valores indicando el nodo de destino de las aristas, seguido N valores indicando el peso de las aristas y seguido de dos números indicando el nodo de origen y el nodo de destino del recorrido a encontrar.

Por ejemplo, el programa debe ser ejecutado de la siguiente manera:
```
>> ./a.out 16 2 3 1 1 0 4 6 5 4 1 6 2 1 6 0 0 3 6 2 5 2 7 2 7 5 3 0 7 7 4 7 4 17 52 36 32 26 37 40 28 35 29 58 34 19 93 16 38 2 5
```

Para el ejemplo anterior la respuesta debe ser la siguiente:

```
>>  2 3 17
    3 6 52
    6 4 93
    4 5 35
```

**Nota:**
- La salida deben ser las aristas de la ruta de los nodos especificados en los últimos dos número del vector de argumentos. Las aristas se imprimen con el nodo de origen, destino y el peso separadas por un salto de línea.


## Evaluación
Tu programa debe compilar sin errores ni warnings y debe ejecutarse correctamente en un ambiente linux. Piensa en posibles casos de prueba extremos que pueden ser utilizados para probar tu programa.
Tu solución propuesta debe ser correcta y eficiente.

Para obtener el 100% de los puntos de esta actividad, tu programa:

- **80%** - Lista de 4 casos de prueba para cada una de las funcionalidades donde para cada una se evaluará:
  - **Excelente (80%)** - evalúa correctamente los 4 casos de prueba.
  - **Muy Bien (60%)** - evalúa correctamente 3 casos de prueba.
  - **Bien (40%)** - evalúa correctamente 2 casos de prueba
  - **Insuficientre (20%)** - evalúa correctamente 1 o 0 casos de prueba.
- **20%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación  [descargar](https://experiencia21.tec.mx/courses/173572/files/52881961?wrap=1)

## ¿Dónde la entrego?
En este espacio en GitHub classroom. En la pestaña de "Actions" se evaluará el código con los casos de prueba. También se deberá subir el código al [espacio de la tarea en Canvas](https://experiencia21.tec.mx/courses/173572/assignments/5813314). 

## ¿Cómo la entrego?
Se tomarán en cuenta las soluciones sometidas en este repositorio de la plataforma de GitHub classroom. Pueden subir su archivo "homework-07.cpp" por separado o editar el que está arriba y someterlo via *commit*.

Adicionalmente, en el espacio de la tarea en canvas, un integrante del equipo entrega un archivo .ZIP llamado A0XXXXXXX-A0YYYYYYY_Act7.1, (donde las XXXXXXXs y YYYYYYY son las matrículas del equipo)
     que contenga dentro una carpeta llamada A0XXXXXXX-A0YYYYYYY_Act7.1,
          en donde se encontrará UN único archivo .cpp.  Se pueden tener uno o más archivos .h.

Un solo submission por equipo
Si se incumple este formato de entrega, se penalizará con 20 puntos sobre la nota obtenida.

