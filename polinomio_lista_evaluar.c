// programa para crear una lista que represente un polinomio y ademas evaluarlo.
//printf("\n");

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int numero;
  int exponente;
} tipo;

typedef struct nod {
  tipo info;
  struct nod *sig;
} TNodo;

TNodo *crea_nodo(tipo dato);
tipo leer_dato(TNodo *cab);
void inserta_ordenado(tipo dato, TNodo **cab);
void imprime_polinomio(TNodo *cab);
int evalua_polinomio(TNodo *cab, int x);
void menu();

int main() {
  menu();
  return 0;
}

void menu() {
  TNodo *cab = NULL;
  tipo dato;
  int i, n, rest, x;
  int opc = 0;
  printf("Ingrese el numero de terminos del polinomio: ");
  scanf("%d", &n);
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("El %d° termino es: \n", i + 1);
    dato = leer_dato(cab);
    printf("\n");
    crea_nodo(dato);
    inserta_ordenado(dato, &cab);
  }
  
  printf("El polinomio es: \n");
  printf("\n");
  imprime_polinomio(cab);
  printf("\n");
  while (opc != 2) {
    printf("\n");
    printf("1. Evaluar el polinomio\n");
    printf("2. Salir\n");
    scanf(" %d", &opc);
    printf("\n");
    switch (opc) {
    case 1:
      printf("Ingrese el valor de x: ");
      scanf("%d", &x);
      printf("\n");
      rest = evalua_polinomio(cab, x);
      printf("El resultado de evaluar el polinomio en x = %d es: %d\n", x, rest);
      printf("\n");
      break;
    case 2:
      printf("Saliendo del programa...\n");
      break;
    default:
      printf("Opcion invalida. Intente de nuevo.\n");
      break;
    }
  }
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

tipo leer_dato(TNodo *cab) {
  tipo dato;
  int exp_exist = 0;
  do {
    printf("Ingrese el numero: ");
    scanf("%d", &dato.numero);
    do {
      printf("Ingrese el exponente: ");
      scanf("%d", &dato.exponente);
      if (dato.exponente < 0) {
        printf("El exponente debe ser mayor o igual a 0\n");
      } else {
        TNodo *corre;
        corre = cab;
        while (corre != NULL) {
          if (corre->info.exponente == dato.exponente) {
            exp_exist = 1;
            printf("El exponente ya existe. Ingrese otro exponente.\n");
            break;
          }
          corre = corre->sig;
        }
        if (corre == NULL) {
          exp_exist = 0;
        }
      }
    } while (dato.exponente < 0 || exp_exist == 1);
  } while (exp_exist == 1);
  return dato;
}

void inserta_ordenado(tipo dato, TNodo **cab) {
  TNodo *aux, *ant, *nuevo;
  aux = *cab;
  ant = NULL;
  while (aux != NULL && aux->info.exponente > dato.exponente) {
    ant = aux;
    aux = aux->sig;
  }
  nuevo = crea_nodo(dato);
  if (ant == NULL) {
    nuevo->sig = *cab;
    *cab = nuevo;
  } else {
    ant->sig = nuevo;
    nuevo->sig = aux;
  }
}

void imprime_polinomio(TNodo *cab) {
  TNodo *corre;
  printf("P(x) =");
  for (corre = cab; corre != NULL; corre = corre->sig) {
    if (corre->info.numero >= 0)
      printf(" + ");
    else
      printf(" - ");
    printf("%dx^%d", abs(corre->info.numero), corre->info.exponente);
  }
  printf("\n");
}

int evalua_polinomio(TNodo *cab, int x) {
  TNodo *corre;
  int resultado = 0;
  for (corre = cab; corre != NULL; corre = corre->sig) {
    resultado += corre->info.numero * pow(x, corre->info.exponente);
  }
  return resultado;
}