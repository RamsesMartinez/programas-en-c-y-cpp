/*
* Name: leercad.c
* Copyright: (C) Marzo de 2016
* Author:  Ramses Martinez Ortiz
* Date: 30/03/16 17:20
* Description: Implementacion de la biblioteca cadenas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leercad.h"

void leerC(String *cadena){
    char c; /**Almacena el caracter leido */
    int i; /** Contola el tamanio de la cadena */
    String auxiliar = NULL; /** Almacena la cadena antes de ser copiada a la direccion recibida */

    if((*cadena) != NULL){
        free(*cadena); /**Liberamos el espacio */
        (*cadena) = NULL;
    }
    i = 1; /** Inicializa en uno para almacenar el primer caracter */
    while ((c = getchar()) != '\n'){
        auxiliar = (String) realloc(auxiliar, (i+2)*sizeof(char)); /**Agregamos mas memoria */
        if(auxiliar == NULL){
            printf("Memoria insuficiente !\n");
            exit(EXIT_FAILURE);
        }
        auxiliar[i-1] = c; /**Agregamos el caracter */
        auxiliar[i] = '\0';
        i++;
    } 
	if(auxiliar == NULL){
        auxiliar = (String)malloc(5*sizeof(char)); /**Aginamos memoria al auxiliar nulo */
        strcpy(auxiliar,"NULO");
    }else{ /**Si la cadena no es nula */
        (*cadena) = (String)realloc((*cadena),(strlen(auxiliar)+1)*sizeof(char));
        strcpy((*cadena),auxiliar); /**Copiamos la cadena auxiliar en la direccion de *cadena */
    }
	free(auxiliar);
}
