[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=458462&assignment_repo_type=GroupAssignmentRepo)
# Homework 04 - Longest palindrome algorithm

## Propósito
Entender a partir de su implementación el funcionamiento del algoritmo de Manacher para encontrar el palíndromo más largo.


## Instrucciones
La tarea será resuelta en equipos de hasta 2 estudiantes.

Implementar en C++ el algoritmo para encontrar el palíndromo más largo en una cadena de caracteres. Se debe implementar el algoritmo visto en clases ([ver TC2038_07_Longest Palindrome Substring_wNotes.pdf](https://experiencia21.tec.mx/courses/173572/files/62712711?wrap=1))

El programa recibe como argumentos una cadena de caracteres que contienen el texto en el cuál debemos encontrar el palíndromo más largo. El programa debe regresar la posición inicial y longitud del palíndromo más largo en la cadena.

Por ejemplo, el programa debe ser ejecutado de la siguiente manera:
```
>> ./a.out "Was it a cat I saw? Maybe a taco cat?"
```
En este texto, aparecen más de un palíndromo, por ejemplo Was it a cat I saw, y taco cat, pero el más largo es el primero, por tanto el programa debe regresar la posición inicial y longitud del primero. 

Para el ejemplo anterior la respuesta debe ser la siguiente:

```
>> 0 13
```

**Nota:**
- El índice y longitud anterior no considera las espacios en la cadena de entrada (esto facilitará un poco el desarrollo)

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
En este espacio en GitHub classroom. En la pestaña de "Actions" se evaluará el código con los casos de prueba. También se deberá subir el código al [espacio de la tarea en Canvas](https://experiencia21.tec.mx/courses/173572/assignments/5662505). 

## ¿Cómo la entrego?
Se tomarán en cuenta las soluciones sometidas en este repositorio de la plataforma de GitHub classroom. Pueden subir su archivo "homework-04.cpp" por separado o editar el que está arriba y someterlo via *commit*.

Adicionalmente, en el espacio de la tarea en canvas, un integrante del equipo entrega un archivo .ZIP llamado A0XXXXXXX-A0YYYYYYY_Act4.1, (donde las XXXXXXXs y YYYYYYY son las matrículas del equipo)
     que contenga dentro una carpeta llamada A0XXXXXXX-A0YYYYYYY_Act4.1,
          en donde se encontrará UN único archivo .cpp.  Se pueden tener uno o más archivos .h.

Un solo submission por equipo
Si se incumple este formato de entrega, se penalizará con 20 puntos sobre la nota obtenida.

