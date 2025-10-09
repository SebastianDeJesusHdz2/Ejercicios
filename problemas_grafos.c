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
    int primero;
    int ultimo;
} TCola;
typedef struct
{
    TDato datos[MAX];
    int cima;
} TPila;

bool existe_camino(TGrafo *g, int v1, int v2)
{
    DFS(&*g,v1);
    if(g->visitado[v2]==true) {
        return true;
    } else {
        return false;
    }
}

int contar_componentes(TGrafo *g)
{
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    int componentes = 0;
    for (int i = 0; i < MAX; i++) {
        if(g->vertices[i]==true && g->visitado[i]==false) {
            componentes++;
            DFS_Recursivo(&*g,i);
        }
    }
    return componentes;
}

int contar_componentesv2(TGrafo *g)
{
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    int componentes = 0;
    for (int i = 0; i < MAX; i++) {
        if(g->vertices[i]==true && g->visitado[i]==false) {
            componentes++;
            DFS(&*g,i);
        }
    }
    return componentes;
}

int distancia_minima(TGrafo *g, int v1, int v2)
{
    TCola cola;
    int dist[MAX];
    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }
    dist[v1] = 0;
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    g->visitado[v1]=true;
    ini_cola(&cola);
    encolar(&cola,v1);
    while(!cola_esta_vacia(cola)) {
        int actual;
        desencolar(&cola,&actual);
        for (int i = 0; i < MAX; i++) {
            if(g->matriz[actual][i] == 1 && g->visitado[i] == false) {
                g->visitado[i] = true;
                encolar(&cola,i);
                dist[i] = dist[actual] + 1;
            }
        }
    }
    return dist[v2];
}

int distancia_minima_laberinto(TGrafo *g, int v1, int v2)
{
    TCola cola;
    int dist[MAX];
    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    dist[v1] = 0;
    g->visitado[v1] = true;
    ini_cola(&cola);
    encolar(&cola, v1);
    while (!cola_esta_vacia(cola)) {
        int actual;
        desencolar(&cola, &actual);
        if (actual == v2) {
            return dist[actual];
        }
        int movimientos[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int k = 0; k < 4; k++) {
            int i = actual / MAX + movimientos[k][0];
            int j = actual % MAX + movimientos[k][1];
            int vecino = i * MAX + j;
            if (i >= 0 && i < MAX && j >= 0 && j < MAX && g->matriz[i][j] == 0 && g->visitado[vecino] == false) {
                g->visitado[vecino] = true;
                encolar(&cola, vecino);
                dist[vecino] = dist[actual] + 1;
            }
        }
    }
    return -1;
}

int distancia_minima_laberinto(TGrafo *g, int v1, int v2)
{
    TCola cola;
    int dist[MAX];
    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }
    int aux = 0;
    for (int i = 0; i < MAX; i++) {
        g->visitado[i] = false;
    }
    dist[v1] = 0;
    g->visitado[v1] = true;
    ini_cola(&cola);
    encolar(&cola, v1);
    while (!cola_esta_vacia(cola) || aux==0) {
        int actual;
        desencolar(&cola, &actual);
        if (actual == v2) {
            aux = 1;
        }
        int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int cont = 0; cont < 4; cont++) {
            int i = actual / MAX + mov[cont][0];
            int j = actual % MAX + mov[cont][1];
            int aux2 = i * MAX + j;
            if (i >= 0 && i < MAX && j >= 0 && j < MAX && 
                g->matriz[i][j] == 0 && g->visitado[aux2] == false) {
                g->visitado[aux2] = true;
                encolar(&cola, aux2);
                dist[aux2] = dist[actual] + 1;
            }
        }
    }
    return dist[v2];
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

void ini_pila(TPila *pila)
{
    pila->cima = 0;
}

bool pila_esta_vacia(TPila pila)
{
    if (pila.cima == 0) {
        return true;
    } else {
        return false;
    }
}

bool pila_esta_llena(TPila pila)
{
    if (pila.cima == MAX) {
        return true;
    } else {
        return false;
    }
}

bool apilar(TPila *pila, TDato dato)
{
    if (pila_esta_llena(*pila)) {
        puts("La pila está llena ");
        return false;
    } else {
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
    } else {
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
    } else {
        *dato = cola->datos[cola->primero];
        cola->primero++;
        return true;
    }
}
