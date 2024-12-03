# Push Swap

## Descripción

**Push Swap** es un proyecto diseñado para implementar y optimizar un conjunto de algoritmos que ordenan una pila de números enteros utilizando un conjunto limitado de instrucciones. El objetivo principal es minimizar el número de movimientos necesarios para lograr un ordenamiento correcto.

Este proyecto se desarrolla como parte del currículo de la escuela 42, y pone a prueba habilidades como la comprensión de estructuras de datos, la optimización de algoritmos y el manejo eficiente de memoria.

---

## Contenido

- [Características](#características)
- [Requisitos](#requisitos)
- [Compilación](#compilación)
- [Instrucciones Permitidas](#instrucciones-permitidas)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Optimización](#optimización)
- [Autor](#autor)

---

## Características

- Ordena una pila de números enteros utilizando un conjunto limitado de instrucciones.
- Implementación de algoritmos eficientes de ordenamiento como **radix sort** o **quick sort**, adaptados al conjunto de operaciones permitido.
- Diseñado para funcionar con pilas pequeñas y medianas (hasta 500 elementos).
- Compatible con el marco de evaluación de 42 para validar eficiencia y corrección.

---

## Requisitos

- Sistema operativo: **Linux** o **macOS**.
- Compilador: **GCC** o equivalente.
- Makefile funcional.

---

## Compilación

Para compilar el proyecto, simplemente ejecuta el comando:

make

## Instrucciones Permitidas

El programa debe operar exclusivamente con las siguientes instrucciones:

- **`sa`**: Intercambia los dos primeros elementos de la pila `a`.
- **`sb`**: Intercambia los dos primeros elementos de la pila `b`.
- **`ss`**: Realiza `sa` y `sb` simultáneamente.
- **`pa`**: Pasa el primer elemento de la pila `b` a la pila `a`.
- **`pb`**: Pasa el primer elemento de la pila `a` a la pila `b`.
- **`ra`**: Rota la pila `a` hacia arriba.
- **`rb`**: Rota la pila `b` hacia arriba.
- **`rr`**: Realiza `ra` y `rb` simultáneamente.
- **`rra`**: Rota la pila `a` hacia abajo.
- **`rrb`**: Rota la pila `b` hacia abajo.
- **`rrr`**: Realiza `rra` y `rrb` simultáneamente.

---

## Estructura del Proyecto

push_swap/
├── includes/            # Archivos de cabecera (.h)
├── src/                 # Archivos fuente (.c)
│   ├── push_swap.c      # Punto de entrada
│   ├── instructions.c/  # Implementación de operaciones (sa, pb, etc.)
│   ├── algorithms/      # Algoritmos de ordenamiento
│   ├── utils/           # Funciones auxiliares
├── Makefile             # Script para compilación
├── README.md            # Documentación del proyecto
