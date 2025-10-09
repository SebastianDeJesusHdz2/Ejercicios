// Estructuras de Datos 1
// Hernandez Hernandez Sebastian de Jesus
// Fecha de entrega: 22 de agosto del 2023
// Se necesita un programa que dado 3 cantidades, se requiere saber si es un triangulo o no, ademas de que tipo de triangulo es: escaleno, isoseles, equilatero y se necesita calcular el minimo numero que sumado a sus lados nos de un triangulo
// Datos de entrada: tres cantidades entre -1 000 000 000 y 1 000 000 000
// Datos de salida: si es triangulo o no y el valor del numero minimo a sumar a sus lados para que sea triangulo
// Para si es triangulo o no 0=no es triangulo, 1 es equilatero, 2 es isoseles y 3 es escaleno
// Para el numero minimo, solo se pondra si no es triangulo de lo contrario sera 0
#include <stdio.h>

int main()
{
    int lado_a, lado_b, lado_c, triangulo, validador, resultado, rest;
    scanf("%d %d %d", &lado_a, &lado_b, &lado_c);
    validador = 0;
    resultado = 0;
    rest = 0;
    if (lado_a >= -1000000000 & lado_a <= 1000000000 & lado_b >= -1000000000 & lado_b <= 1000000000 & lado_c >= -1000000000 & lado_c <= 1000000000)
    {
        if (lado_a < 0 & lado_b < 0 & lado_c < 0)
        {
            lado_a = -1 * lado_a;
            rest = 1;
            lado_b = -1 * lado_b;
            lado_c = -1 * lado_c;
        }
        if (lado_a != 0 & lado_b != 0 & lado_c != 0)
        {
            if (lado_a + lado_b > lado_c)
            {
                triangulo = 1;
                if (lado_a + lado_c > lado_b)
                {
                    triangulo = 1;
                    if (lado_c + lado_b > lado_a)
                    {
                        triangulo = 1;
                    }
                    else
                    {
                        triangulo = 0;
                    }
                }
                else
                {
                    triangulo = 0;
                }
            }
            else
            {
                triangulo = 0;
            }
        }
        else
        {
            triangulo = 0;
        }
        if (triangulo == 1)
        {
            if (lado_a == lado_b & lado_a == lado_c)
            {
                triangulo = 1;
            }
            if (lado_a == lado_b & lado_a != lado_c)
            {
                triangulo = 2;
            }
            if (lado_a != lado_b & lado_a == lado_c)
            {
                triangulo = 2;
            }
            if (lado_a != lado_b & lado_a != lado_c & lado_b != lado_c)
            {
                triangulo = 3;
            }
        }
        if (triangulo == 0)
        {
            while (validador != 1)
            {
                resultado = resultado + 1;
                lado_a = lado_a + resultado;
                lado_b = lado_b + resultado;
                lado_c = lado_c + resultado;
                if (lado_a + lado_b > lado_c)
                {
                    validador = 1;
                    if (lado_a + lado_c > lado_b)
                    {
                        validador = 1;
                        if (lado_c + lado_b > lado_a)
                        {
                            validador = 1;
                        }
                        else
                        {
                            validador = 0;
                        }
                    }
                    else
                    {
                        validador = 0;
                    }
                }
                else
                {
                    validador = 0;
                }
            }
        }
        if (rest == 1)
        {
            resultado = resultado * -1;
        }
        printf("%d %d", triangulo, resultado);
    }
}