#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
typedef int TDato;
typedef struct {
    TDato datos[MAX];
    int tam;
} TConjunto;
bool agregar(TConjunto *c,TDato dato);
bool eliminar(TConjunto *c,TDato dato);
int buscar(TConjunto c,TDato dato);
bool conjunto_esta_lleno(TConjunto c);
bool conjunto_esta_vacio(TConjunto c);
void inicializar_conjunto(TConjunto *c);
int distintos(int arreglo[], int tam);
void union_conjuntos(TConjunto a, TConjunto b, TConjunto *r);
void interseccion_conjuntos(TConjunto a, TConjunto b, TConjunto *r);
void diferencia_conjuntos(TConjunto a, TConjunto b, TConjunto *r);
void imprimir_rest(TConjunto c);
void leer_datos(TConjunto *a,int tam);
int main()
{
    int arreglo[] = {1,5,3,6,3,5,1,6,8,10};
    int rest = distintos(arreglo,10);
    printf("%d\n", rest);
    TConjunto a,b,r;
    inicializar_conjunto(&a);
    inicializar_conjunto(&b);
    leer_datos(&a,10);
    leer_datos(&b,10);
    printf("Union\n");
    union_conjuntos(a,b,&r);
    imprimir_rest(r);
    printf("Intersección\n");
    interseccion_conjuntos(a,b,&r);
    imprimir_rest(r);
    printf("Diferencia\n");
    diferencia_conjuntos(a,b,&r);
    imprimir_rest(r);
}

void leer_datos(TConjunto *a,int tam)
{
    for(int i=0;i<tam;i++)
    {
        TDato dato;
        scanf("%d", &dato);
        agregar(&*a,dato);
    }
}


void imprimir_rest(TConjunto c)
{
    for(int i = 0; i<c.tam;i++)
    {
        printf("%d ", c.datos[i]);
    }
    printf("\n");
}

void inicializar_conjunto(TConjunto *c)
{
    c->tam = 0;
}

bool conjunto_esta_vacio(TConjunto c)
{
    return c.tam==0;
}

bool conjunto_esta_lleno(TConjunto c)
{
    return c.tam==MAX;
}

bool agregar(TConjunto *c,TDato dato)
{
    if(conjunto_esta_lleno(*c))
    {
        return false;
    }
    int pos = buscar(*c,dato);
    if(pos==-1)
    {
        int i = c->tam;
        while(i>0 && c->datos[i-1]>dato)
        {
            c->datos[i] = c->datos[i-1];
            i--;
        }
        c->datos[i] = dato;
        c->tam++;
        return true;
    } else {
        return false;
    }
}

bool eliminar(TConjunto *c,TDato dato)
{
    int pos = buscar(*c,dato);
    if(pos==-1)
    {
        return false;
    }
    for(int i=pos; i<c->tam-1 ;i++)
    {
        c->datos[i] = c->datos[i+1];
    }
    c->tam--;
    return true;
}

int buscar(TConjunto c,TDato dato)
{
    bool encontrado = false;
    int resultado = -1;
    int ini = 0, fin = c.tam-1, mitad;
    while(ini<=fin && !encontrado)
    {
        mitad = (ini + fin) / 2;
        if(c.datos[mitad]==dato)
        {
            encontrado = true;
            resultado = mitad;
        }
        else
        {
            if(c.datos[mitad]>dato)
            {
                fin = mitad - 1;
            }
            else 
            {
                ini = mitad + 1;
            }

        }
    }
    return resultado;
}

int distintos(int arreglo[], int tam)
{
    TConjunto c;
    inicializar_conjunto(&c);
    for(int i = 0; i<tam;i++)
    {
        agregar(&c,arreglo[i]);
    }
    return c.tam;
}

void union_conjuntos(TConjunto a, TConjunto b, TConjunto *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<a.tam;i++)
    {
        agregar(&*r,a.datos[i]);
    }
    for(int i = 0; i<b.tam;i++)
    {
        agregar(&*r,b.datos[i]);
    }
}

void interseccion_conjuntos(TConjunto a, TConjunto b, TConjunto *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<a.tam;i++)
    {
        int pos = buscar(b,a.datos[i]);
        if(pos!=-1)
        {
            agregar(&*r,a.datos[i]);
        }
    }
}

void diferencia_conjuntos(TConjunto a, TConjunto b, TConjunto *r)
{
    inicializar_conjunto(&*r);
    for(int i = 0; i<a.tam;i++)
    {
        int pos = buscar(b,a.datos[i]);
        if(pos==-1)
        {
            agregar(&*r,a.datos[i]);
        }
    }
}