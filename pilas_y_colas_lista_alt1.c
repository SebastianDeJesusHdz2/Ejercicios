  #include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct {
  int *pila;
  int tam;
  int tope;
} TPila;

typedef struct nodo {
  tipo info;
  struct nodo *sig;
} TNodo;

typedef struct {
  TNodo *tope;
  int tam;
} TPilaN;

typedef struct {
  TNodo *frente;
  TNodo *final;
  int tam;
} TCola;

//definiciones de lista
TNodo *crea_nodo(tipo dato);

// definiciones de pilas
void menu_pilas();
void inicializa_Pila(TPila *p, int n);
void inicializar_PilaN(TPilaN *p, int n);
int pila_vacia(TPilaN p);
int push(TPilaN *p, tipo dato);
int pop(TPilaN *p, tipo *dato);
void imprimir_pila(TPilaN p);

//definiciones de colas
void menu_colas();
void inicializar_Cola(TCola *c);
int cola_vacia(TCola c);
int encolar(TCola *c, tipo dato);
int desencolar(TCola *c, tipo *dato);
void imprimir_Cola(TCola c);

int main() {
  int op;
  printf("1.Pilas\n");
  printf("2.Colas\n");
  printf("3.Salir\n");
  printf("Ingrese una opcion: ");
  scanf("%d", &op);
  switch (op) {
    case 1:
      menu_pilas();
      break;
    case 2:
      menu_colas();
      break;
    case 3:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion invalida\n");
      break;
  }
}

void menu_colas() {
  TCola cola;
  inicializar_Cola(&cola);
  tipo dato;
  int opcion;
  do {
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Imprimir cola\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    printf("\n");
    switch (opcion) {
      case 1:
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        if (!encolar(&cola, dato)) {
          printf("Error al encolar el dato.\n");
        }
        break;
      case 2:
        if (!desencolar(&cola, &dato)) {
          printf("No se pudo desencolar ningún dato.\n");
        }
        break;
      case 3:
        imprimir_Cola(cola);
        break;
      case 4:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opción no válida.\n");
        break;
    }
    printf("\n");
  } while (opcion != 4);
}

void menu_pilas() {
  TPilaN pila;
  inicializar_PilaN(&pila, 100);
  int opcion, dato;
  do {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Imprimir Pila\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        push(&pila, dato);
        break;
      case 2:
        if (!pop(&pila, &dato)) {
          printf("La pila está vacía\n");
        }
        break;
      case 3:
        imprimir_pila(pila);
        break;
      case 4:
        printf("Saliendo del programa...\n");
        break;
      default:
        printf("Opción no válida.\n");
    }
    printf("\n");
  } while (opcion != 4);
}

void inicializa_Pila(TPila *p, int n) {
  p->pila = (int *)malloc(sizeof(int) * n);
  if(p->pila != NULL) {
    p->tam = n;
    p->tope = 0;
  } else {
    p->tam = 0;
  }
}

void inicializar_PilaN(TPilaN *p, int n) {
  p->tope = NULL;
  p->tam = 0;
}

int pila_vacia(TPilaN p) {
  int b;
  b = (p.tope == NULL) ? 1 : 0;
  return (b);
}

int push(TPilaN *p, tipo dato) {
  TNodo *aux;
  int b = 0;
  aux = crea_nodo(dato);
  if(aux != NULL) {
    aux->sig = p->tope;
    p->tope = aux;
    p->tam++;
    b = 1;
  }
  return b;
}

TNodo *crea_nodo(tipo dato) {
  TNodo *aux;
  aux = (TNodo *)malloc(sizeof(TNodo));
  if (aux != NULL) {
    aux->info = dato;
    aux->sig = NULL;
  }
  return aux;
}

int pop(TPilaN *p, tipo *dato) {
  TNodo *aux;
  int b = 0;
  if(!pila_vacia(*p)) {
    aux = p->tope;
    p->tope = aux->sig;
    p->tam--;
    *dato = aux->info;
    free(aux);
    b = 1;
  }
  return b;
}


void inicializar_Cola(TCola *c) {
  c->frente = NULL;
  c->final = NULL;
  c->tam = 0;
}

int cola_vacia(TCola c) {
  return (c.frente == NULL);
}

int encolar(TCola *c, tipo dato) {
  TNodo *aux;
  int b = 0;
  aux = crea_nodo(dato);
  if (aux != NULL) {
    if (cola_vacia(*c)) {
      c->frente = aux;
    } else {
      c->final->sig = aux;
    }
    c->final = aux;
    c->tam++;
    b = 1;
  }
  return b;
}

int desencolar(TCola *c, tipo *dato) {
  TNodo *aux;
  int b = 0;
  if (!cola_vacia(*c)) {
    aux = c->frente;
    c->frente = aux->sig;
    c->tam--;
    *dato = aux->info;
    free(aux);
    if (c->frente == NULL) {
      c->final = NULL;
    }
    b = 1;
  }
  return b;
}

void imprimir_pila(TPilaN p) {
  TNodo *actual = p.tope;
  if (pila_vacia(p)) {
    printf("La pila está vacía.\n");
    return;
  }
  printf("Tope -> ");
  while (actual != NULL) {
    printf("%d -> ", actual->info);
    actual = actual->sig;
  }
  printf("Fondo\n");
}

void imprimir_Cola(TCola c) {
  if (cola_vacia(c)) {
    printf("La cola está vacía.\n");
  } else {
    TNodo *actual = c.frente;
    printf("Frente <- ");
    while (actual != NULL) {
      printf("%d <- ", actual->info);
      actual = actual->sig;
    }
    printf("Final\n");
    printf("\n");
  }
}

