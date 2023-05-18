[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6494432&assignment_repo_type=AssignmentRepo)
# Homework 10 - Shape Context

## Propósito
Entender a partir de su implementación el funcionamiento del algoritmo Shape Context para hallar correspondencias entre formas.

## Instrucciones
La tarea será resuelta en equipos de hasta 2 estudiantes.

El algoritmo shape context (ver [TC2038_18_Shape Matching.pdf](https://experiencia21.tec.mx/courses/173572/files/69548583)) se divide en tres partes:

1. calcular el descriptor de forma para el conjunto de puntos de entrada (dispositivas 8 y 9). **100 puntos**
2. calcular matriz de costos de correspondencias (diapositivas 10 y 11)  **+25 puntos**
3. calcular distancia entre dos formas (diapositiva 12) **+25 puntos**

En esta tarea SOLO se evaluará el paso 1 del algoritmo, calcular el descriptor de forma para el conjunto de puntos de entrada (dispositivas 8 y 9). 

La implementación de las otras dos etapas brindará puntos extras, 25 puntos por cada una. Por tanto, la tarea tiene un valor total de 150 puntos, promediables con el resto de las tareas :D

Implementar en C++ el algoritmo para calcular el descriptor de una forma basado en el algoritmo de shape context usando 12 bins sectoriales y 5 bins radiales, con un radio de tamaño 10. Los sectores radiales serán uniformes y no logarítmicos.

El programa recibe como argumentos un número entero N (indicando la cantidad de puntos), seguido de N valores indicando la coordenada x de cada punto, seguido de N valores indicando la coordenada y de cada punto.

**Nota**: el orden de los histogramas en la salida es el mismo orden de los puntos como vienen en la entrada. El renglón 0 del histograma corresponde a los puntos con distancia del 0 al 2, mientras la columna 0 corresponde a los puntos con ángulos del 0 al 30 ,y así sucesivamente. Los puntos con distancia mayor a 10 son descartados.

```
>> ./a.out 5 1 -2 -3 4 12 2 4 12 16 8
```

La salida del algoritmo será para cada punto de la entrada un vector de 60 valores (12 x 5 bins).

Para el ejemplo anterior la respuesta debe ser la siguiente:
```
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 1 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
```
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
Recuerda que por cada día de entrega tarde se descontarán 10 puntos.

## ¿Dónde la entrego?
En este espacio en GitHub classroom. En la pestaña de "Actions" se evaluará el código con los casos de prueba. También se deberá subir el código al [espacio de la tarea en Canvas](https://experiencia21.tec.mx/courses/173572/assignments/5975159). 

## ¿Cómo la entrego?
Se tomarán en cuenta las soluciones sometidas en este repositorio de la plataforma de GitHub classroom. Pueden subir su archivo "homework-10.cpp" por separado o editar el que está arriba y someterlo via *commit*.

Adicionalmente, en el espacio de la tarea en canvas, un integrante del equipo entrega un archivo .ZIP llamado A0XXXXXXX-A0YYYYYYY_Act10.1, (donde las XXXXXXXs y YYYYYYY son las matrículas del equipo)
     que contenga dentro una carpeta llamada A0XXXXXXX-A0YYYYYYY_Act10.1,
          en donde se encontrará UN único archivo .cpp.  Se pueden tener uno o más archivos .h.

Un solo submission por equipo
Si se incumple este formato de entrega, se penalizará con 20 puntos sobre la nota obtenida.

