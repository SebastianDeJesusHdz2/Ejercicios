typedef int tipo;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  tipo info;
  struct nodo *sig;
} TNodo;

void imprime_listaC(TNodo *cab);
tipo leerdato();
TNodo *crea_nodo(tipo dato);
void inserta_inicioC(TNodo **cab, tipo dato);
void inserta_finalC(TNodo **cab, tipo dato);
void inserta_ordenadoC(TNodo **cab, tipo dato);

int main() {
  TNodo *cab = NULL;
  int opc = 0;
    tipo dato;
    while (opc != 5) {
      printf("\n");
      printf("1. Inserta inicio\n");
      printf("2. Inserta final\n");
      printf("3. Inserta ordenado\n");
      printf("4. Imprime\n");
      printf("5. Salir\n");
      printf("\n");
      printf("Dame la opcion: ");
      scanf("%d", &opc);
      printf("\n");
      switch (opc) {
      case 1:
        dato = leerdato();
        inserta_inicioC(&cab, dato);
        break;
      case 2:
        dato = leerdato();
        inserta_finalC(&cab, dato);
        break;
      case 3:
        dato = leerdato();
        inserta_ordenadoC(&cab, dato);
        break;
      case 4:
        if (cab != NULL) {
          imprime_listaC(cab);
        } else {
          printf("Lista vacia\n");
        }
        break;
      case 5:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opcion invalida\n");
        break;
      }
    }
  }

//lee un dato para crear un nodo con ese dato
tipo leerdato() {
  tipo dato;
  printf("Ingrese un dato: ");
  scanf("%d", &dato);
  printf("\n");
  return dato;
}

//crea un nodo de la lista.
TNodo *crea_nodo(tipo dato) {
  TNodo *aux;
  aux = (TNodo *)malloc(sizeof(TNodo));
  if (aux != NULL) {
    aux->info = dato;
    aux->sig = NULL;
  }
  return aux;
}

void inserta_inicioC(TNodo **cab, tipo dato) {
  TNodo *aux;
  if(*cab==NULL) {
    *cab = crea_nodo(dato);
    (*cab)->sig = *cab;
  } else {
    aux = *cab;
    while(aux->sig!=*cab) {
      aux = aux->sig;
    }
    aux->sig = crea_nodo(dato);
    aux->sig->sig = *cab;
    *cab = aux->sig;
  }
}

void inserta_finalC(TNodo **cab, tipo dato) {
  TNodo *aux;
  if(cab==NULL) {
    *cab = crea_nodo(dato);
    (*cab)->sig = *cab;
  } else {
    aux = *cab;
    while(aux->sig!=*cab) {
      aux = aux->sig;
    }
    aux->sig = crea_nodo(dato);
    aux->sig->sig = *cab;
  }
}

void inserta_ordenadoC(TNodo **cab, tipo dato) {
  TNodo *aux, *nv;
  if(*cab==NULL || (*cab)->info > dato) {
    inserta_inicioC(cab, dato);
  } else {
    aux = *cab;
    while(aux->sig!=*cab && aux->sig->info < dato) {
      aux = aux->sig;
    }
    nv = crea_nodo(dato);
    nv->sig = aux->sig;
    aux->sig = nv;
  }
}

void imprime_listaC(TNodo *cab) {
  TNodo *aux;
  if(cab) {
    for(aux = cab; aux->sig!=cab; aux = aux->sig) {
      printf("%d -> ", aux->info);
    }
    printf("%d -> ", aux->info);
  }
  printf("%d", aux->sig->info);
}