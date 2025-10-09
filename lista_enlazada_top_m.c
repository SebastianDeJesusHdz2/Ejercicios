#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipo;

typedef struct nodo {
  tipo info;
  struct nodo *sig;
} TNodo;

void menu();
void mas_grande(TNodo *cab, int m, int result[]);
void insertar_final(tipo dato, TNodo **cab);
void insertar_orden(int arr[], int m, tipo dato);
TNodo *crea_nodo(tipo dato);
void imprime_lista(TNodo *cab);

//antimain.
int main(void) {
  menu();
}

void menu() {
  TNodo *cab = NULL;
  int opc = 0, m;
  int result[100];
  tipo dato;
  //parte encargada de llenar la lista. 
  while(opc!=2) {
    printf("1. Insertar\n2. Salir\n");
    scanf("%d", &opc);
    if(opc==1) {
      printf("Ingrese un dato: ");
      scanf("%d", &dato);
      insertar_final(dato,&cab);
    } else if(opc!=2) {
      printf("Opcion invalida\n");
    }
  }
  //numero de datos a extraer.
  printf("Ingrese el valor de m: ");
  scanf("%d", &m);
  //buscar los m datos mas grandes de la lista.
  mas_grande(cab,m,result);
  //imprimir los datos de la lista.
  printf("Lista: \n");
  imprime_lista(cab);
  //imprimir los resultados.
  printf("Los %d datos mas grandes son: \n", m);
  for(int i=0;i<m;i++) {
    printf("%d \n", result[i]);
  }
}

//Inserta nodos al final de la lista.
void insertar_final(tipo dato, TNodo **cab) {
  TNodo *corre = *cab;
  if (*cab == NULL) {
    *cab = crea_nodo(dato);
  } else {
    while (corre->sig != NULL) {
      corre = corre->sig;
    }
    corre->sig = crea_nodo(dato);
  }
}

//Crea nodos de la lista.
TNodo *crea_nodo(tipo dato) {
  TNodo *aux;
  aux = (TNodo *)malloc(sizeof(TNodo));
  if (aux != NULL) {
    aux->info = dato;
    aux->sig = NULL;
  }
  return aux;
}

//Funcion principal para la busqueda de los m datos mas grandes.
void mas_grande(TNodo *cab, int m, int result[]) {
  TNodo *corre = cab;
  //Inicializamos el arreglo con 0.
  for (int i = 0; i < m; i++) {
      result[i] = 0;
  }
  //Recorremos la lista buscando los mas grandes.
  while (corre != NULL) {
      insertar_orden(result, m, corre->info);
      corre = corre->sig;
  }
}

//Funcion que llena el arreglo resultante con los m datos mas grandes.
void insertar_orden(int arr[], int m, tipo dato) {
    int i;
    // Si el nuevo dato es más grande que el menor de los mayores, lo insertamos.
    if (dato > arr[m-1]) {
        for (i = m-1; i > 0 && arr[i-1] < dato; i--) {
            arr[i] = arr[i-1];
        }
        arr[i] = dato;
    }
}

//Funcion que imprime la lista.
void imprime_lista(TNodo *cab) {
  TNodo *corre;
  printf("cab -> ");
  for (corre = cab; corre != NULL; corre = corre->sig) {
    printf("%d -> ", corre->info);
  }
  printf("NULL\n");
}