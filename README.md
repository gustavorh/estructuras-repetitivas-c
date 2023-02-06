# Archivo 1

## Introducción
El código en C es un programa que realiza un seguimiento de las fichas de pacientes y su estado de vacunación contra COVID-19. Se crea una estructura de datos para representar una ficha de paciente y se utiliza para registrar la información sobre cada paciente. 

## Funciones
El código no contiene funciones, solo se utiliza el `main` para realizar todas las acciones.

## Flujo del código
1. Se crea un arreglo de estructuras llamado `control` que representa una ficha de paciente con los siguientes campos: número de ficha, género, mes y año de nacimiento, grupo sanguíneo, factor RH, y un arreglo de 6 enteros para representar las dosis de vacuna contra COVID-19 que ha recibido el paciente.
2. Se inicializa el arreglo `control` con valores predeterminados para 4 pacientes.
3. Se muestra en pantalla los pacientes que tienen solo hasta la 3ra vacuna COVID-19, incluyendo el número de ficha, género y edad de cada paciente.
4. Se muestra en pantalla el porcentaje de pacientes por grupo sanguíneo, es decir, A, B, AB, O.
5. Se muestra en pantalla la cantidad de hombres y mujeres que han recibido cada dosis de la vacuna COVID-19.

## Consideraciones
1. El código está escrito en C y se asume que se está utilizando un compilador de C para ejecutar el programa.
2. El conocimiento actualizado sobre la vacunación contra COVID-19 es hasta 2022.
3. El programa está diseñado para procesar información para 4 pacientes solamente, por lo que cualquier cambio en el número de pacientes requiere una modificación en el código.
4. La variable `mes` está definida como 06 para representar el mes de junio y la variable `anio` está definida como 2022 para representar el año. Si se quiere utilizar una fecha diferente, se debe cambiar el valor de estas variables.
5. La estructura de datos `Ficha` y el arreglo `control` se utilizan para representar la información de las fichas de pacientes y para registrar la información sobre cada paciente.
6. Se utiliza la función `strcmp` para comparar dos cadenas y determinar si son iguales o no.
7. Se utiliza la función `printf` para mostrar resultados en pantalla.

# Archivo 2

## Introduccion

El código en C se encarga de simular un monitoreo de contaminación en recursos hídricos. Al ingresar un año, se calcula el porcentaje de eventos de contaminación por tipo de contaminante y se muestra cuál recurso hídrico sufrió la mayor cantidad de eventos de contaminación.

## Funciones

No hay funciones en el código.

## Flujo del código

El código se ejecuta en un único bloque, siguiendo los siguientes pasos:
1. Se crea una matriz de 7 planos, 6 filas y 3 columnas que representa el nivel de contaminación en los recursos hídricos a lo largo de los años 2015-2021.
2. Se crean tres vectores paralelos que representan los años, los tipos de contaminantes y los recursos hídricos.
3. Se pide al usuario que ingrese un año para calcular el porcentaje de eventos por tipo de contaminante.
4. Se valida que el año ingresado esté dentro del rango 2015-2021.
5. Se calcula la suma total de contaminación en el año seleccionado.
6. Se divide la suma de contaminación de cada tipo de contaminante por la suma total y se multiplica por 100 para obtener el porcentaje.
7. Se muestran los resultados en pantalla.
8. Se calcula la cantidad de eventos de contaminación en cada recurso hídrico.
9. Se determina cuál recurso hídrico sufrió la mayor cantidad de eventos de contaminación.
10. Se muestran los resultados en pantalla.

## Consideraciones

- El código utiliza la librería stdio.h para las operaciones de entrada y salida.
- La entrada del usuario debe ser un año dentro del rango 2015-2021.
- Los resultados se muestran en pantalla y no se guardan en ningún archivo.

# Archivo 3

## Introduccion
Este código está diseñado para calcular el porcentaje de eventos relacionados con tipos de contaminación en recursos hídricos en un año específico seleccionado por el usuario.

## Funciones
No hay funciones específicas en este código, sin embargo, hay un bloque de código que hace los siguientes procedimientos:
1. Pide al usuario que ingrese el año deseado (rango 2015 a 2021).
2. Utiliza el año ingresado para encontrar el índice correspondiente en el arreglo `tiempo`.
3. Suma los eventos relacionados con los tipos de contaminación en los recursos hídricos para el año seleccionado.
4. Calcula y muestra el porcentaje de eventos relacionados con cada tipo de contaminación.

## Flujo del código
1. El programa pide al usuario que ingrese el año deseado (rango 2015 a 2021).
2. Se utiliza un `do-while` para verificar que el año ingresado esté dentro del rango permitido (2015 a 2021).
3. Se utiliza un bucle `for` para encontrar el índice correspondiente en el arreglo `tiempo` para el año ingresado.
4. Se utiliza un bucle anidado `for` para sumar los eventos relacionados con los tipos de contaminación en los recursos hídricos para el año seleccionado.
5. Se utiliza otro bucle anidado `for` para calcular y mostrar el porcentaje de eventos relacionados con cada tipo de contaminación.

## Consideraciones
- Se asume que el usuario ingresará un año dentro del rango permitido (2015 a 2021).
- El cálculo de porcentajes se hace con una precisión de 2 dígitos decimales.
