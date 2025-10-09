//Hacerlo me tomo entre 2-3 horas
/*
Entradas:
  6
  push_back 3
  push_front 7
  clear
  push_front 5
  erase 2
  push_front 9
Salidas:
  9 5
*/

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipo;

typedef struct nod {
  tipo info;
  struct nod *sig;
} TNodo;

TNodo *crea_nodo(tipo dato);
tipo leerdato();
void menu();
void inserta_inicio(tipo dato, TNodo **cab);
void elimina_inicio(TNodo **cab);
void insertar_final(tipo dato, TNodo **cab);
void elimina_final(TNodo **cab);
void elimina_X(TNodo **cab, tipo x);
void elimina_todo(TNodo **cab);
void imprime_lista(TNodo *cab);


//antimain
int main() {
  menu();
}

//menu principal del programa.
void menu() {
  TNodo* cab = NULL;
  tipo aux = leerdato();
  char oper[20];
  char inst[20];
  tipo dato;
  for (int opc = 0; opc < aux + 1; opc++) {
    fgets(oper, sizeof(oper), stdin);
    sscanf(oper, "%s %d", inst, &dato);
      if (strcmp("push_front", inst) == 0) {
            inserta_inicio(dato, &cab);
      } else if (strcmp("pop_front", inst) == 0) {
            elimina_inicio(&cab);
      } else if (strcmp("push_back", inst) == 0) {
            insertar_final(dato, &cab);
      } else if (strcmp("pop_back", inst) == 0) {
            elimina_final(&cab);
      } else if (strcmp("erase", inst) == 0) {
            elimina_X(&cab, dato);
      } else if (strcmp("clear", inst) == 0) {
            elimina_todo(&cab);
      }
  }
  imprime_lista(cab);
  elimina_todo(&cab);
}


//lee el numero de operaciones.
tipo leerdato() {
  tipo dato;
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

//funcion para insertar un nodo al inicio de la lista.
void inserta_inicio(tipo dato, TNodo **cab) {
  TNodo *aux;
  aux = crea_nodo(dato);
  if (aux) {
    aux->sig = *cab;
    *cab = aux;
  }
}

//funcion para eliminar el primer nodo de la lista
void elimina_inicio(TNodo **cab) {
  TNodo *aux;
  if(*cab) {
    aux = *cab;
    *cab = aux->sig;
    aux->sig = NULL;
    free(aux);
  }
}

//funcion para insertar un nodo al final de la lista
void insertar_final(tipo dato, TNodo **cab) {
  TNodo *aux = crea_nodo(dato);
  if (aux == NULL) {
    return;
  }
  if (*cab == NULL) {
    *cab = aux;
  } else {
    TNodo *corre = *cab;
    while (corre->sig != NULL) {
      corre = corre->sig;
    }
    corre->sig = aux;
  }
}

//funcion para eliminar el nodo al final de la lista.
void elimina_final(TNodo **cab) {
  TNodo *aux, *ant;
  if(*cab) {
    if((*cab)->sig == NULL) {
      aux = *cab;
      *cab = NULL;
      free(aux);
    }
    aux = *cab;
    while(aux->sig) {
      ant = aux;
      aux = aux->sig;
    }
    ant->sig = NULL;
    free(aux);
  }
}

//funcion para eliminar un nodo x de la lista.
void elimina_X(TNodo **cab, tipo x) {
  TNodo *aux = *cab, *ant = NULL;
  if (*cab != NULL) {
    if ((*cab)->info == x) {
      *cab = aux->sig;
      free(aux);
      return;
    }
    while (aux != NULL && aux->info != x) {
      ant = aux;
      aux = aux->sig;
    }
    if (aux == NULL) {
      return;
    }
    ant->sig = aux->sig;
    free(aux);
  } 
}

//funcion para eliminar todos los nodos de la lista.
void elimina_todo(TNodo **cab) {
  TNodo *aux;
  while(*cab) {
    aux = *cab;
    *cab = (*cab)->sig;
    aux->sig = NULL;
    free(aux);
  }
}

//funcion para imprimir la lista.
void imprime_lista(TNodo *cab) {
  TNodo *corre;
  for (corre = cab; corre != NULL; corre = corre->sig) {
    printf("%d ", corre->info);
  }
}