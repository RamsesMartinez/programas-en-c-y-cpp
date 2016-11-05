Leer Cadena
====================
Programa para leer cadenas en C de forma dinámica, de tal fotrma que no es necesario inicializar el arreglo de caracteres con un tamaño en específico.

 - Desarrollado en DevC++ 5.9.2
 - Compilador: GCC 32 4.9.2 32-bit Release


### Instrucciones de uso:

#####1. Incluir los archivos 
Los archivos "leercad.h" y "leercad.a" se deberan incluir en la carpeta que contenga el programa principal

###### ¡¡¡PASO IMPORTANTE!!! - Configurar DevC
Incluir la biblioteca en la fase de enlazado.
 - Acudimos a "Proyecto - opciones de proyecto" 
 - Buscamos la pestaña "Argumentos para el programa" (También se puede encontrar como "Parámetro en versiones anteriores")
 - En la columna de la derecha, correspondiente a "linker", pulsamos el botón "Agregar libreria u Objeto" 
 - Añadimos el fichero "leercad.a"
 - Para evitar conflictos de compilación se recomiendo (no es obligatorio) utilizar el compilador TDM-GCC 4.9.2 32-bit Release
 - Ahora ya podremos ejecutar e código

#####2. Se incluye el archivo de cabecera en nuestro programa
~~~c
#include "leercad.h"
~~~
#####3. se declara una variable del tipo *String*
~~~c
String buffer;
~~~
#####4. Se implementa la funcion para leer la cadena
~~~c
leerC(&buffer);
~~~
#####5. Se imprime en pantalla. Por ejemplo con un *scanf()*
~~~c
printf("Cadena: \n",buffer);
~~~

###Ejemplo:
~~~c
int main(int argc, char const *argv[]) {
    char opc;
    do{
        String buffer;
        printf("\ningrese cadena: ");
        leerCadena(&buffer);
        printf("\nResultado: %s", buffer);
        printf("\nContinuar? (s/n):\t");
        scanf("%c",&opc);
        fflush( stdin );
    }while(opc == 's' || opc == 'S');
    return (EXIT_SUCCESS);
}
~~~
