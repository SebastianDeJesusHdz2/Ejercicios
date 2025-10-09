#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef int tipo;

typedef struct nodA {
  tipo info;
  struct nodA *izq, *der;
}TNodoA;

void menu();
TNodoA *crea_nodoA(int dato);
void preorden(TNodoA *r);
void inorden(TNodoA *r);
void postorden(TNodoA *r);
void inserta_nodoA(TNodoA **r, int dato);
//Elimina nodo hecho por la maestra.
int elmina_nodoA(TNodoA **r, int dato);
TNodoA *maximo_nodoA(TNodoA **r);
// Elimina nodo hecho por mi.
void elimina_nodA(TNodoA **r, int dato);
TNodoA *minimo_nodoA(TNodoA **r);
// Altura del sub arbol derecho.
int altura_subDer(TNodoA *r);
int altura_subIzq(TNodoA *r);
int altura_Arbol(TNodoA *r);
//Menor y mayor del arbol.
int mayor(TNodoA *r);
int menor(TNodoA *r);

//Antimain.
int main() {
  menu();
}

void menu() {
  int opc=0, dato, ban=0;
  TNodoA *raiz = NULL;
  while(opc != 9) {
    printf("\n1. Inserta nodo en el arbol: \n");
    printf("2. Elimina nodo del arbol: \n");
    printf("3. Imprime arbol en preorden: \n");
    printf("4. Imprime arbol en inorden: \n");
    printf("5. Imprime arbol en postorden: \n");
    printf("6. Calcula la altura del sub arbol derecho: \n");
    printf("7. Mayor del arbol: \n");
    printf("8. Menor del arbol: \n");
    printf("9. Salir: \n");
    scanf("%d", &opc);
    printf("\n");
    switch(opc) {
      case 1:
        printf("Ingresa el dato: \n");
        scanf("%d", &dato);
        inserta_nodoA(&raiz, dato);
        break;
      case 2:
        printf("Ingresa el dato a eliminar: \n");
        scanf("%d", &dato);
        ban = elmina_nodoA(&raiz, dato);
        if(ban == 1) {
          printf("Dato eliminado. \n");
        } else {
          printf("Dato no encontrado. \n");
        }
        break;
      case 3:
        preorden(raiz);
        printf("\n");
        break;
      case 4:
        inorden(raiz);
        printf("\n");
        break;
      case 5:
        postorden(raiz);
        printf("\n");
        break;
      case 6:
        dato = altura_subDer(raiz->der);
        printf("La altura del sub arbol derecho es: %d\n", dato);
        dato = altura_subIzq(raiz->izq);
        printf("La altura del sub arbol izquierdo es: %d\n", dato);
        dato = altura_Arbol(raiz);
        printf("La altura del arbol es: %d\n", dato);
        break;
      case 7:
        dato = mayor(raiz);
        if(dato!=0) {
          printf("El mayor es: %d\n", dato);
        }
        break;
      case 8:
        dato = menor(raiz);
        if(dato!=0) {
          printf("El menor es: %d\n", dato);
        }
        break;
      case 9:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opcion invalida\n");
        break;
    }
  }
}

//Crea nodo.
TNodoA *crea_nodoA(int dato) {
  TNodoA *aux;
  aux = (TNodoA *)malloc(sizeof(TNodoA));
  if (aux) {
    aux->info = dato;
    aux->izq = aux->der = NULL;
  }
  return aux;
}

//Recorridos preorden, inorden, postorden.
void preorden(TNodoA *r) {
  if(r != NULL) {
    printf("%d, ", r->info);
    preorden(r->izq);
    preorden(r->der);
  }
}

void inorden(TNodoA *r) {
  if(r != NULL) {
    inorden(r->izq);
    printf("%d, ", r->info);
    inorden(r->der);
  }
}

void postorden(TNodoA *r) {
  if(r != NULL) {
    postorden(r->izq);
    postorden(r->der);
    printf("%d, ", r->info);
  }
}

//Inserta nodo.
void inserta_nodoA(TNodoA **r, int dato) {
  if(*r == NULL) {
    *r = crea_nodoA(dato);
  } else {
    if(dato < (*r)->info) {
      inserta_nodoA(&((*r)->izq), dato);
    } else {
      if(dato > (*r)->info) {
        inserta_nodoA(&((*r)->der), dato);
      } else {
        printf("Dato repetido\n");
      }
    }
  }
}

// Elimina nodo hecho por mi.
void elimina_nodA(TNodoA **r, int dato) {
  TNodoA *aux;
  if (*r != NULL) {
    if (dato < (*r)->info) {
      elimina_nodA(&((*r)->izq), dato);
    } else {
      if (dato > (*r)->info) {
        elimina_nodA(&((*r)->der), dato);
      } else {
        if((*r)->izq == NULL) {
          aux = *r;
          *r = (*r)->der;
          free(aux);
        } else if((*r)->der == NULL) {
          aux = *r;
          *r = (*r)->izq;
          free(aux);
        } else {
          aux = minimo_nodoA(&((*r)->der));
          (*r)->info = aux->info;
          elimina_nodA(&((*r)->der), aux->info);
        }
      }
    }
  } else {
    printf("El dato no existe\n");
  }
}

TNodoA *minimo_nodoA(TNodoA **r) {
  TNodoA *aux = *r;
  if((*r)->izq == NULL) {
    *r = (*r)->der;
    aux->der = NULL;
  } else {
    aux = minimo_nodoA(&((*r)->izq));
  }
  return aux;
}

//Elimina nodo.
int elmina_nodoA(TNodoA **r, int dato) {
  TNodoA *aux;
  tipo tem;
  int b = 0;
  if(*r != NULL) {
    if(dato < (*r)->info) {
      b = elmina_nodoA(&((*r)->izq), dato);
    } else {
      if(dato > (*r)->info) {
        b = elmina_nodoA(&((*r)->der), dato);
      } else {
        aux = *r;
        if((*r)->izq == NULL) {
          *r = (*r)->der;
        } else {
          if((*r)->der == NULL) {
            *r = (*r)->izq;
          } else {
            aux = maximo_nodoA(&((*r)->izq));
            tem = aux->info;
            aux->info = (*r)->info;
            (*r)->info = tem;
          }
        }
        aux->izq = aux->der = NULL;
        free(aux);
        b = 1;
      }
    }
  }
  return b;
}

TNodoA *maximo_nodoA(TNodoA **r) {
  TNodoA *aux = *r;
  if((*r)->der == NULL) {
    *r = (*r)->izq;
    aux->izq = NULL;
  } else {
    aux = maximo_nodoA(&((*r)->der));
  }
  return aux;
}

//Calcula la altura del sub arbol derecho de un arbol.
int altura_subDer(TNodoA *r) {
  int rest;
  if(r == NULL) {
    return 1;
  } else {
    rest = altura_subDer(r->der);
    return 1 + rest;
  }
}

int altura_subIzq(TNodoA *r) {
  int rest;
  if(r == NULL) {
    return 1;
  } else {
    rest = altura_subIzq(r->izq);
    return 1 + rest;
  }
}

int altura_Arbol(TNodoA *r) {
  int alt, aliz, alde;
  if(r == NULL) {
    alt = 0;
  } else {
    aliz = altura_Arbol(r->izq);
    alde = altura_Arbol(r->der);
    if(aliz > alde) {
      alt = 1 + aliz;
    } else {
      alt = 1 + alde;
    }
  }
  return alt;
}

//Mayor del arbol.
int mayor(TNodoA *r) {
  if(r==NULL) {
    return 0;
  } else {
    while(r->der != NULL) {
      r = r->der;
    }
    return r->info;
  }
}

//Menor del arbol.
int menor(TNodoA *r) {
  if(r==NULL) {
    return 0;
  } else {
    while(r->izq != NULL) {
      r = r->izq;
    }
    return r->info;
  }
}

