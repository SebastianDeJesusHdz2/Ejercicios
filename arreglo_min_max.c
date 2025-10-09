#include <stdio.h>

#define MR 1000

void menu();
void captura(int arr[], int *tam);
void busca_men_MAY(int arr[], int tam, int *men, int *may);

//antimain
int main(void) {
  menu();
}

void menu() {
  int arr[MR];
  int tam, men, may;
  //captura los elemetos del arreglo.
  captura(arr, &tam);
  //busca el menor y mayor de los elementos del arreglo.
  busca_men_MAY(arr, tam, &men, &may);
  //Muestra los resultados.
  printf("El menor es %d y el mayor es %d", men, may);
}

//Funcion que captura los datos del arreglo.
void captura(int arr[], int *tam) {
  printf("Tamaño del arreglo: ");
  scanf("%d", tam);
  printf("Elementos del arreglo:\n");
  for (int i = 0; i < *tam; i++) {
    scanf("%d", &arr[i]);
  }
}

void busca_men_MAY(int arr[], int tam, int *men, int *may) {
  int i;
  //Inicializacion del menor y el mayor.
  *men = 100000;
  *may = 0;
  //recorre el arreglo.
  for (i = 0; i < tam-1; i += 2) {
    //si menor el primero que el segundo.
    if (arr[i] < arr[i+1]) {
      //si el segundo es mayor que el primero.
      if (arr[i+1] > *may) {
        *may = arr[i+1];
      }
      //si el primero es mayor que el segundo.
      if (arr[i] < *men) {
        *men = arr[i];
      }
    } else {
      //si el primero es mayor que el mayor actual.
      if (arr[i] > *may) {
        *may = arr[i];
      }
      //si el segundo es menor que el menor actual.
      if (arr[i+1] < *men) {
        *men = arr[i+1];
      } 
    }
  }
  //Recorre el arreglo (Solo si es impar).
  if (tam % 2 != 0) {
    //si el ultimo es mayor que el mayor actual.
    if (arr[tam - 1] > *may) {
      *may = arr[tam - 1];
    }
    //si el ultimo es menor que el menor actual.
    if (arr[tam - 1] < *men) {
      *men = arr[tam - 1];
    }
  }
}