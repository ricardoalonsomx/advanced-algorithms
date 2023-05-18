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

# --------------------------------------

# Homework 07 - Floyd-Warshall for finding the shortest path

## Purpose
To understand the implementation and functionality of the Floyd-Warshall algorithm for finding a minimum spanning tree in a weighted directed graph.


## Instructions
The task will be solved in teams of up to 2 students.

Implement the Floyd-Warshall algorithm in C++ to find a minimum spanning tree in a weighted directed graph. ([TC2038_12_Shortest Path Floyd Warshall_wNotes.pdf](https://experiencia21.tec.mx/courses/173572/files/65062749/))

The program receives an integer N as arguments, indicating the number of edges, followed by N values indicating the source node of the edges, followed by N values indicating the destination node of the edges, followed by N values indicating the weight of the edges, and finally two numbers indicating the source node and destination node of the path to be found.

For example, the program should be executed as follows:
```
>> ./a.out 16 2 3 1 1 0 4 6 5 4 1 6 2 1 6 0 0 3 6 2 5 2 7 2 7 5 3 0 7 7 4 7 4 17 52 36 32 26 37 40 28 35 29 58 34 19 93 16 38 2 5
```

For the above example, the expected output should be as follows:

```
>>  2 3 17
    3 6 52
    6 4 93
    4 5 35
```

**Note:**
- The output should be the edges of the path between the nodes specified by the last two numbers in the argument vector. The edges are printed with the source node, destination node, and weight separated by a line break.


## Evaluation
Your program should compile without errors or warnings and should run correctly in a Linux environment. Think of extreme test cases that can be used to test your program.
Your proposed solution should be correct and efficient.

To obtain 100% of the points for this activity, your program should:

- **80%** - List 4 test cases for each of the functionalities, where each case will be evaluated as follows:
  - **Excellent (80%)** - correctly evaluates all 4 test cases.
  - **Very Good (60%)** - correctly evaluates 3 test cases.
  - **Good (40%)** - correctly evaluates 2 test cases.
  - **Insufficient (20%)** - correctly evaluates 1 or 0 test cases.
- **20%** - The code should follow the coding standards specified in the provided coding standards document.

## Where do I submit it?
In this GitHub classroom space. The code will be evaluated using the test cases in the "Actions" tab. The code should also be uploaded to the assignment space on Canvas. 

## How do I submit it?
Solutions submitted in this repository on the GitHub classroom platform will be considered. You can either upload your separate "homework-07.cpp" file or edit the existing file and commit it.

Additionally, in the Canvas assignment space, one team member should submit a .ZIP file named A0XXXXXXX-A0YYYYYYY_Act7.1 (where XXXXXXX and YYYYYYY are the team's IDs
