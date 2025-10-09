#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef int tipo;

typedef struct nodAV {
  tipo info;
  struct nodAV *izq, *der;
  int FE;
}TNodoAV;

/*

)//  Nodos de arboles B  //(

typedef struct nodAB {
  int *claves;
  struct nodA **hijos;
  int n_c;
} TNodoAB;

TNodoAB *crea_nodoAB(int grado);

TNodoAB *crea_nodoAB(int grado) {
  TNodoAB *aux;
  aux = (TNodoAB*) malloc(sizeof(TNodoAB));
  if(aux != NULL) {
    aux->claves = (int*) malloc(sizeof(int)*(grado*2+1));
    aux->hijos = (TNodoAB**) malloc(sizeof(TNodoAB*)*(grado*2+1));
    return aux;
  }
}
Muerte......
*/

void menu();
TNodoAV *crea_nodoAV(int dato);
void preorden(TNodoAV *r);
void inorden(TNodoAV *r);
void postorden(TNodoAV *r);
int inserta_nodoAV(TNodoAV **r, int dato);
//Elimina nodo hecho por la maestra.
int elmina_nodoAV(TNodoAV **r, int dato);
TNodoAV *maximo_nodoAV(TNodoAV **r);
// Elimina nodo hecho por mi.
void elimina_nodAV(TNodoAV **r, int dato);
TNodoAV *minimo_nodoAV(TNodoAV **r);
// Altura del sub arbol derecho.
int altura_subDer(TNodoAV *r);
int altura_subIzq(TNodoAV *r);
int altura_Arbol(TNodoAV *r);
//Menor y mayor del arbol.
int mayor(TNodoAV *r);
int menor(TNodoAV *r);

//Antimain.
int main() {
  menu();
}

void menu() {
  int opc=0, dato, ban=0;
  TNodoAV *raiz = NULL;
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
        ban = inserta_nodoAV(&raiz, dato);
        break;
      case 2:
        printf("Ingresa el dato a eliminar: \n");
        scanf("%d", &dato);
        ban = elmina_nodoAV(&raiz, dato);
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
TNodoAV *crea_nodoAV(int dato) {
  TNodoAV *aux;
  aux = (TNodoAV *)malloc(sizeof(TNodoAV));
  if (aux) {
    aux->info = dato;
    aux->izq = aux->der = NULL;
    aux->FE = 0;
  }
  return aux;
}

//Recorridos preorden, inorden, postorden.
void preorden(TNodoAV *r) {
  if(r != NULL) {
    printf("(%d, FE=%d) ", r->info, r->FE);
    preorden(r->izq);
    preorden(r->der);
  }
}

void inorden(TNodoAV *r) {
  if(r != NULL) {
    inorden(r->izq);
    printf("(%d, FE=%d) ", r->info, r->FE);
    inorden(r->der);
  }
}

void postorden(TNodoAV *r) {
  if(r != NULL) {
    postorden(r->izq);
    postorden(r->der);
    printf("(%d, FE=%d) ", r->info, r->FE);
  }
}

//Inserta nodo balanceado.
int inserta_nodoAV(TNodoAV **r, int dato) {
  int b=0;
  TNodoAV *nodo1, *nodo2;
  if(*r == NULL) {
    *r = crea_nodoAV(dato);
  } else {
    if((*r)->info > dato) {
      b = inserta_nodoAV(&((*r)->izq), dato);
      if(b==1) {
        switch((*r)->FE) {
          case 1:
            (*r)->FE = 0;
            b=0;
            break;
          case 0:
            (*r)->FE = -1;
            b=1;
            break;
          case -1: //Rotacion por la izquierda.
            nodo1 = (*r)->izq;
            if(nodo1->FE <= 0) { //Rotacion II.
              (*r)->izq = nodo1->der;
              nodo1->der = *r;
              nodo1->FE=0;
              *r = nodo1;
            } else { //Rotacion ID.
              nodo2 = nodo1->der;
              nodo1->der = nodo2->izq;
              nodo2->izq = nodo1;
              (*r)->izq = nodo2->der;
              nodo2->der = *r;
              switch(nodo2->FE) {
                case -1: 
                  (*r)->FE = 1;
                  nodo1->FE = 0;
                  break;
                case 0: 
                  (*r)->FE = 0;
                  nodo1->FE = 0;
                  break;
                case 1:
                  (*r)->FE = 0;
                  nodo1->FE = -1;
                  break;
              }
              nodo2->FE = 0;
              *r = nodo2;
            }
            break;
        }
      }
    } else {
      if((*r)->info < dato) {
        b = inserta_nodoAV(&((*r)->der), dato);
        if(b==1) {
          switch((*r)->FE) {
            case -1:
              (*r)->FE = 0;
              b=0;
              break;
            case 0:
              (*r)->FE = 1;
              b=1;
              break;
            case 1: //Rotacion por la derecha.
              nodo1 = (*r)->der;
              if(nodo1->FE >= 0) { //Rotacion DD.
                (*r)->der = nodo1->izq;
                nodo1->izq = *r;
                nodo1->FE=0;
                *r = nodo1;
              } else { //Rotacion DI.
                nodo2 = nodo1->izq;
                nodo1->izq = nodo2->der;
                nodo2->der = nodo1;
                (*r)->der = nodo2->izq;
                nodo2->izq = *r;
                switch(nodo2->FE) {
                  case -1: 
                    (*r)->FE = 0;
                    nodo1->FE = 1;
                    break;
                  case 0: 
                    (*r)->FE = 0;
                    nodo1->FE = 0;
                    break;
                  case 1:
                    (*r)->FE = -1;
                    nodo1->FE = 0;
                    break;
                }
                nodo2->FE = 0;
                *r = nodo2;
              }
              break;
          }
        }
      } else {
        printf("Dato repetido\n");
      }
    }
  }
  return b;
}

//Elimina nodo balanceado.
int elimina_nodoAV(TNodoAV **r, int dato) {
  int b = 0;
  TNodoAV *nodo1, *nodo2;
  if (*r == NULL) {
    printf("Dato no encontrado\n");
    return b;
  } else {
    if (dato < (*r)->info) {
      b = elimina_nodoAV(&((*r)->izq), dato);
      if (b == 1) {
        switch ((*r)->FE) {
        case -1:
          (*r)->FE = 0;
          b = 1;
          break;
        case 0:
          (*r)->FE = 1;
          b = 0;
          break;
        case 1: // rotacion derecha
          nodo1 = (*r)->der;
          if (nodo1->FE >= 0) { // rotacion DD
            (*r)->der = nodo1->izq;
            nodo1->izq = *r;
            *r = nodo1;
            if (nodo1->FE == 0) {
              (*r)->FE = -1;
              nodo1->FE = 1;
              b = 0;
            } else {
              (*r)->FE = 0;
              nodo1->FE = 0;
              b = 1;
            }
          } else { // rotacion DI
            nodo2 = nodo1->izq;
            nodo1->izq = nodo2->der;
            nodo2->der = nodo1;
            (*r)->der = nodo2->izq;
            nodo2->izq = *r;
            switch (nodo2->FE) {
            case -1:
              (*r)->FE = 0;
              nodo1->FE = 1;
              break;
            case 0:
              (*r)->FE = 0;
              nodo1->FE = 0;
              break;
            case 1:
              (*r)->FE = -1;
              nodo1->FE = 0;
              break;
            }
            nodo2->FE = 0;
            *r = nodo2;
            b = 1;
          }
          break;
        }
      }
    } else if (dato > (*r)->info) {
      b = elimina_nodoAV(&((*r)->der), dato);
      if (b == 1) {
        switch ((*r)->FE) {
        case 1:
          (*r)->FE = 0;
          b = 1;
          break;
        case 0:
          (*r)->FE = -1;
          b = 0;
          break;
        case -1: // rotacion izquierda
          nodo1 = (*r)->izq;
          if (nodo1->FE <= 0) { // rotacion II
            (*r)->izq = nodo1->der;
            nodo1->der = *r;
            *r = nodo1;
            if (nodo1->FE == 0) {
              (*r)->FE = 1;
              nodo1->FE = -1;
              b = 0;
            } else {
              (*r)->FE = 0;
              nodo1->FE = 0;
              b = 1;
            }
          } else { // rotacion ID
            nodo2 = nodo1->der;
            nodo1->der = nodo2->izq;
            nodo2->izq = nodo1;
            (*r)->izq = nodo2->der;
            nodo2->der = *r;
            switch (nodo2->FE) {
            case -1:
              (*r)->FE = 1;
              nodo1->FE = 0;
              break;
            case 0:
              (*r)->FE = 0;
              nodo1->FE = 0;
              break;
            case 1:
              (*r)->FE = 0;
              nodo1->FE = -1;
              break;
            }
            nodo2->FE = 0;
            *r = nodo2;
            b = 1;
          }
          break;
        }
      }
    } else {               
      if ((*r)->izq == NULL) { 
        TNodoAV *temp = *r;
        *r = (*r)->der;
        free(temp);
        b = 1;
      } else if ((*r)->der == NULL) {
        TNodoAV *temp = *r;
        *r = (*r)->izq;
        free(temp);
        b = 1;
      } else {
        TNodoAV *temp = (*r)->izq;
        while (temp->der != NULL)
          temp = temp->der;
        (*r)->info = temp->info;
        b = elimina_nodoAV(&((*r)->izq), temp->info);
        if (b == 1) {
          switch ((*r)->FE) {
          case -1:
            (*r)->FE = 0;
            b = 1;
            break;
          case 0:
            (*r)->FE = 1;
            b = 0;
            break;
          case 1: // rotacion derecha
            nodo1 = (*r)->der;
            if (nodo1->FE >= 0) { // rotacion DD
              (*r)->der = nodo1->izq;
              nodo1->izq = *r;
              *r = nodo1;
              if (nodo1->FE == 0) {
                (*r)->FE = -1;
                nodo1->FE = 1;
                b = 0;
              } else {
                (*r)->FE = 0;
                nodo1->FE = 0;
                b = 1;
              }
            } else { // rotacion DI
              nodo2 = nodo1->izq;
              nodo1->izq = nodo2->der;
              nodo2->der = nodo1;
              (*r)->der = nodo2->izq;
              nodo2->izq = *r;
              switch (nodo2->FE) {
              case -1:
                (*r)->FE = 0;
                nodo1->FE = 1;
                break;
              case 0:
                (*r)->FE = 0;
                nodo1->FE = 0;
                break;
              case 1:
                (*r)->FE = -1;
                nodo1->FE = 0;
                break;
              }
              nodo2->FE = 0;
              *r = nodo2;
              b = 1;
            }
            break;
          }
        }
      }
    }
  }
  return b;
}

TNodoAV *minimo_nodoAV(TNodoAV **r) {
  TNodoAV *aux = *r;
  if((*r)->izq == NULL) {
    *r = (*r)->der;
    aux->der = NULL;
  } else {
    aux = minimo_nodoAV(&((*r)->izq));
  }
  return aux;
}

//Elimina nodo.
int elmina_nodoAV(TNodoAV **r, int dato) {
  TNodoAV *aux;
  tipo tem;
  int b = 0;
  if(*r != NULL) {
    if(dato < (*r)->info) {
      b = elmina_nodoAV(&((*r)->izq), dato);
    } else {
      if(dato > (*r)->info) {
        b = elmina_nodoAV(&((*r)->der), dato);
      } else {
        aux = *r;
        if((*r)->izq == NULL) {
          *r = (*r)->der;
        } else {
          if((*r)->der == NULL) {
            *r = (*r)->izq;
          } else {
            aux = maximo_nodoAV(&((*r)->izq));
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

TNodoAV *maximo_nodoAV(TNodoAV **r) {
  TNodoAV *aux = *r;
  if((*r)->der == NULL) {
    *r = (*r)->izq;
    aux->izq = NULL;
  } else {
    aux = maximo_nodoAV(&((*r)->der));
  }
  return aux;
}

//Calcula la altura del sub arbol derecho de un arbol.
int altura_subDer(TNodoAV *r) {
  int rest;
  if(r == NULL) {
    return 1;
  } else {
    rest = altura_subDer(r->der);
    return 1 + rest;
  }
}

int altura_subIzq(TNodoAV *r) {
  int rest;
  if(r == NULL) {
    return 1;
  } else {
    rest = altura_subIzq(r->izq);
    return 1 + rest;
  }
}

int altura_Arbol(TNodoAV *r) {
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
int mayor(TNodoAV *r) {
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
int menor(TNodoAV *r) {
  if(r==NULL) {
    return 0;
  } else {
    while(r->izq != NULL) {
      r = r->izq;
    }
    return r->info;
  }
}
