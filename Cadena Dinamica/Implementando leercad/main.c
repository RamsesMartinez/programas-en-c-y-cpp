/**
* Name: main.cpp
* Copyright: (C) Marzo 2016
* Author: Ramses Martinez
* Date: 30/03/16 05:48
* Description: Programa de prueba de biblioteca leercad
*/

#include "leercad.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char opc;
    String buffer;
    do{
        printf("\ningrese cadena: ");
        leerC(&buffer);
        printf("\nResultado: %s", buffer);
        printf("\nContinuar? (s/n):\t");
        scanf("%c",&opc);
        fflush( stdin );
    }while(opc == 's' || opc == 'S');
    return (EXIT_SUCCESS);
}
