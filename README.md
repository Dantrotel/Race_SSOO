

# Simulación de Carrera de Autos con Multihebras en C++

Este programa simula una carrera de autos utilizando programación con múltiples hebras en C++. Cada auto corre en su propia hebra, avanzando en intervalos de distancia y pausas aleatorias hasta completar la distancia total de la carrera. Al final, el programa muestra un podio con los tres primeros autos que terminan la carrera.

## Requisitos

Para compilar y ejecutar este programa, necesitas:

- Un compilador compatible con C++11 o superior (como `g++`).
- `make` para gestionar la compilación.
- Sistema operativo Linux o similar.

## Estructura del Proyecto

El proyecto consta de los siguientes archivos:

- `race.cpp`: Código fuente del programa.
- `Makefile`: Archivo para compilar el programa con `make`.
- `README.md`: Este archivo, con las instrucciones de uso.

## Instrucciones para Compilar y Ejecutar

### Paso 1: Clonar o descargar el repositorio

Si este proyecto está en un repositorio de Git, clónalo o descárgalo en tu máquina. Luego, navega al directorio del proyecto.

```bash
git clone <URL-del-repositorio>
cd <directorio-del-proyecto>

```

Paso 2: Compilar el programa

Este proyecto incluye un archivo Makefile que facilita la compilación. Simplemente ejecuta el siguiente comando en la terminal:


```bash

make

```
Esto generará un ejecutable llamado race.
Paso 3: Ejecutar el programa

Una vez que el programa haya sido compilado correctamente, puedes ejecutarlo con el siguiente comando:


```bash

./race <distancia> <numero_de_autos>

```
    distancia: La distancia total que deben recorrer los autos (en metros).
    numero_de_autos: El número total de autos que participarán en la carrera.

Ejemplo de ejecución:


```bash

./race 100 5

```
Este comando simula una carrera donde 5 autos deben recorrer 100 metros cada uno. Los autos avanzarán en intervalos aleatorios entre 1 y 10 metros, y se detendrán por pausas aleatorias entre 100 y 500 milisegundos.

Salida esperada:

Durante la carrera, el programa imprimirá el progreso de cada auto en tiempo real. Al final, mostrará un podio con los tres primeros autos que terminan la carrera y una lista de los autos restantes (si los hay).


```php

Auto0 avanza 7 metros (total: 7 metros)
Auto1 avanza 10 metros (total: 10 metros)
Auto2 avanza 5 metros (total: 5 metros)
...
Auto1 ha terminado la carrera en el lugar 1!
Auto3 ha terminado la carrera en el lugar 2!
Auto0 ha terminado la carrera en el lugar 3!

========== Podio ==========
1er Lugar: Auto1
2do Lugar: Auto3
3er Lugar: Auto0
============================

```
Si hay menos de 3 autos, el programa mostrará una "X" en las posiciones vacantes del podio.
Limpieza de archivos compilados

Si deseas eliminar el ejecutable y los archivos de compilación, puedes usar el siguiente comando:


```bash

make clean

```
Esto eliminará el archivo race generado durante la compilación.
Notas adicionales

    El programa utiliza la biblioteca estándar de C++ para manejo de hebras (<thread>), sincronización con mutex (<mutex>) y generación de números aleatorios (<random>).
    La salida de la carrera está sincronizada para evitar colisiones de texto en la consola, y se utiliza un mutex para controlar la impresión en pantalla.


## Integrantes:

- Fernando Flores
- Daniel Aguayo 
