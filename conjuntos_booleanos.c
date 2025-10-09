#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
typedef struct {
    bool elementos[MAX];
    int tam;
} TConjuntoB;

void inicializar_conjunto(TConjuntoB *c);
bool eliminar(TConjuntoB *c,int dato);
bool conjunto_esta_vacio(TConjuntoB c);
bool conjunto_esta_lleno(TConjuntoB c);
bool agregar(TConjuntoB *c,int dato);

void inicializar_conjunto(TConjuntoB *c)
{
    for(int i=0;i<MAX;i++) {
        c->elementos[i]=false;
    }
    c->tam=0;
}

bool agregar(TConjuntoB *c,int dato)
{
    if(dato<0||dato>=MAX) {
        return false;
    }
    if(c->elementos[dato]==true) {
        return false;
    }
    c->elementos[dato] = true;
    c->tam++;
    return true;
}

bool eliminar(TConjuntoB *c,int dato)
{
    if(dato<0||dato>=MAX) {
        return false;
    }
    if(c->elementos[dato]==false) {
        return false;
    }
    c->elementos[dato] = false;
    c->tam--;
    return true;
}

bool conjunto_esta_vacio(TConjuntoB c)
{
    return c.tam==0;
}

bool conjunto_esta_lleno(TConjuntoB c)
{
    return c.tam==MAX;
}

void union_conjuntos(TConjuntoB a, TConjuntoB b, TConjuntoB *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<MAX;i++) {
        r->elementos[i]=a.elementos[i]||b.elementos[i];
        if(r->elementos[i]==true) {
            r->tam++;
        }
    }
}

void interseccion_conjuntos(TConjuntoB a, TConjuntoB b, TConjuntoB *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<MAX;i++) {
        r->elementos[i]=a.elementos[i]&&b.elementos[i];
        if(r->elementos[i]==true) {
            r->tam++;
        }
    }
}

void diferencia_conjuntos(TConjuntoB a, TConjuntoB b, TConjuntoB *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<MAX;i++) {
        r->elementos[i]=a.elementos;
        if(r->elementos[i]==true) {
            if(b.elementos[i]==true) {
                r->elementos[i]==false;
            } else {
                r->tam++;
            }

        }
    }
}
