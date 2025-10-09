// Estructuras de Datos 1
// Hernandez Hernandez Sebastian de Jesus
// Fecha de entrega: 22 de agosto del 2023
// Se necesita un programa capaz de leer grados fahrenheit y que imprima su equivalente en grados celsius y además decir si esta fria o caliente.
// Datos de entreda: F= -450 a 1000
// Datos de salida: Temperatura en celsius y temperatura en numero 0=fria y 1=caliente
// Celsius<=36 es frio y Celsius >36 es caliente
// 9Celsius = 5(Fahrenheit - 32)
#include <stdio.h>

int main()
{
    int celsius, fahren, temp;
    scanf("%d", &fahren);
    celsius = 5 * (fahren - 32);
    celsius = celsius / 9;
    if (celsius <= 36)
    {
        temp = 0;
    }
    else
    {
        temp = 1;
    }
    printf("%d %d\n", celsius, temp);
}
