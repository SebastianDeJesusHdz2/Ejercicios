#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
  //analisis de gramatica
  char cad[100] = "X = a + 12 * 23;";
  char i = cad[0];
  int cont = 0;
  int t = strlen(cad);
  for(int cont2 = 0; cont2 < t; cont2++) {
    i = cad[cont2];
    if(i == ' ') {
      cont++;
    }
    i++;
  }
  printf("%s\n", strtok(cad, " "));
  for(int j = 0; j < cont; j++) {
    printf("%s\n", strtok(NULL, " ;"));
  }
}


/*

Gramatica:
S->aSBC
S->abC
bB->bb
bC->bc
CB->BC
cC->cc

*/