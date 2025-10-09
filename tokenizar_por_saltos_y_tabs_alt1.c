/*
    Ejemplo 3 de strtok en C
    @author parzibyte
*/
#include <stdio.h>
#include <string.h>

int main(){
    char cadena[] = "Hola\nMundo\t\t\tSeparado\nPor\nSaltos y tabulaciones",
    delimitador[] = "\n\t";
    char *token = strtok(cadena, delimitador);
    if(token != NULL){
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            printf("Token: %s\n", token);
            token = strtok(NULL, delimitador);
        }
    }
}