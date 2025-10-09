#include <stdio.h>
#include <stdbool.h>
#define Dirigido 1
#define No_Dirigido 0
#define MAX_Vertices 101
typedef struct grafos
{
    int tipo;
    int matriz[MAX_Vertices][MAX_Vertices];
    int num_vertices;
    bool vertices[MAX_Vertices];
} TGrafo;

void ini_grafo(TGrafo *g,int tipo);
void agrega_vertice(TGrafo *g,int v);
void agrega_arista(TGrafo *g, int v1, int v2);
void eliminar_vertice(TGrafo *g,int v);
void eliminar_arista(TGrafo *g,int v1,int v2);

void ini_grado(TGrafo *g, int tipo)
{
    g->tipo=tipo;
    for(int i=0;i<MAX_Vertices;i++) {
        for(int j=0;j<MAX_Vertices;j++) {
            g->matriz[i][j]=0;
        }
        g->vertices[i] = false;
    }
    g->num_vertices=0;
}

void agrega_vertice(TGrafo *g,int v)
{
    if(v>=0 && v<MAX_Vertices && !g->vertices[v]) {
        g->vertices[v]=true;
        g->num_vertices++;
    }
}

void agrega_arista(TGrafo *g, int v1, int v2)
{
    if(g->vertices[v1]==false) {
        agrega_vertice(&*g,v1);
    }
    if(g->vertices[v2]==false) {
        agrega_vertice(&*g,v2);
    }
    g->matriz[v1][v2]=1;
    if(g->tipo==No_Dirigido) {
        g->matriz[v2][v1] = 1;
    }
}

void eliminar_vertice(TGrafo *g,int v)
{
    if(v>=0 && v<MAX_Vertices && g->vertices[v]==true) {
        g->num_vertices--;
        g->vertices[v]=false;
        for(int i=0;i<MAX_Vertices;i++) {
            g->matriz[v][i] = 0;
            g->matriz[i][v] = 0;
        }
    }
}

void eliminar_arista(TGrafo *g,int v1,int v2)
{
    if(v1>=0 && v1<MAX_Vertices && v2>=0 && 
    v2<MAX_Vertices && g->vertices[v1] && g->vertices[v2]) {
        g->matriz[v1][v2] = 0;
        if(g->tipo==No_Dirigido) {
            g->matriz[v2][v1] = 0;
        }
    }
}
