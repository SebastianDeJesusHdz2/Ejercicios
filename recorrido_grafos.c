#include <stdio.h>
#include <stdbool.h>
#define Dirigido 1
#define No_Dirigido 0
#define MAX 101
typedef int TDato;
typedef struct grafos
{
    int tipo;
    int matriz[MAX][MAX];
    int num_vertices;
    bool vertices[MAX];
    bool visitado[MAX];
} TGrafo;
typedef struct
{
    TDato datos[MAX];
    int cima;
} TPila;
typedef struct
{
    TDato datos[MAX];
    int primero;
    int ultimo;
} TCola;

void DFS(TGrafo *g, int v_inicio);
void BFS(TGrafo *g, int v_inicio);
void DFS_R(TGrafo *g, int v_inicio);
void DFS_Recursivo(TGrafo*g, int v_actual);

void DFS(TGrafo *g, int v_inicio)
{
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    TPila pila;
    ini_pila(&pila);
    apilar(&pila, v_inicio);
    g->visitado[v_inicio] = true;
    while (!pila_esta_vacia(pila)) {
        int v_actual;
        desapilar(&pila, &v_actual);
        printf("%d ", v_actual);
        for (int i = 0; i < MAX; i++) {
            if (g->matriz[v_actual][i] != 0 && g->visitado[i] == false) {
                apilar(&pila, i);
                g->visitado[i] = true;
            }
        }
    }
}

void BFS(TGrafo *g, int v_inicio)
{
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    TCola cola;
    ini_cola(&cola);
    encolar(&cola, v_inicio);
    g->visitado[v_inicio] = true;
    while (!cola_esta_vacia(cola)) {
        int v_actual;
        desencolar(&cola, &v_actual);
        printf("%d ", v_actual);
        for (int i = 0; i < MAX; i++) {
            if (g->matriz[v_actual][i] != 0 && g->visitado[i] == false) {
                encolar(&cola, i);
                g->visitado[i] = true;
            }
        }
    }
}

void DFS_R(TGrafo *g, int v_inicio)
{
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    DFS_Recursivo(&*g,v_inicio);
}
void DFS_Recursivo(TGrafo*g, int v_actual)
{
    if(g->visitado[v_actual]==true) {
        return;
    }
    g->visitado[v_actual]=true;
    printf("%d ", v_actual);
    for (int i = 0; i < MAX; i++) {
        if (g->matriz[v_actual][i] != 0 && g->visitado[i] == false) {
                DFS_Recursivo(&*g,i);
            }
    }
}

void ini_pila(TPila *pila)
{
    pila->cima = 0;
}

bool pila_esta_vacia(TPila pila)
{
    if (pila.cima == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool pila_esta_llena(TPila pila)
{
    if (pila.cima == MAX) {
        return true;
    }
    else {
        return false;
    }
}

bool apilar(TPila *pila, TDato dato)
{
    if (pila_esta_llena(*pila)) {
        puts("La pila está llena ");
        return false;
    }
    else {
        pila->datos[pila->cima] = dato;
        pila->cima++;
        return true;
    }
}

bool desapilar(TPila *pila, TDato *dato)
{
    if (pila_esta_vacia(*pila)) {
        puts("La pila esta vacia ");
        return false;
    }
    else {
        pila->cima--;
        *dato = pila->datos[pila->cima];
        return true;
    }
}

void ini_cola(TCola *cola)
{
    cola->primero = 0;
    cola->ultimo = 0;
}

bool cola_esta_vacia(TCola cola)
{
    return (cola.primero == cola.ultimo);
}

bool cola_esta_llena(TCola cola)
{
    return (cola.ultimo - cola.primero) == MAX;
}

bool encolar(TCola *cola, TDato *dato)
{
    if (cola_esta_llena(*cola)) {
        puts("La cola esta llena ");
        return false;
    }
    if (cola->ultimo == MAX && cola->primero > 0) {
        int tam = cola->ultimo - cola->primero;
        for (int i = 0; i < tam; i++) {
            cola->datos[i] = cola->datos[cola->primero + i];
        }
        cola->primero = 0;
        cola->ultimo = tam;
    }
    cola->datos[cola->ultimo] = dato;
    cola->ultimo++;
    return true;
}

bool desencolar(TCola *cola, TDato *dato)
{
    if (cola_esta_vacia(*cola)) {
        puts("La cola esta vacia ");
        return false;
    }
    else {
        *dato = cola->datos[cola->primero];
        cola->primero++;
        return true;
    }
}