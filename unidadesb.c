// Estructuras de Datos 1
// Hernandez Hernandez Sebastian de Jesus
// Fecha de entrega: 22 de agosto del 2023
// se requiere un programa que al introducir una cantidad de pulgadas imprima su equivalente en millas, furlongs, yardas, pies y pulgadas
// Datos de entrada: pulgadas de 0 hasta 2 000 000 000
// Datos de salida: millas, furlongs, yardas, pies y pulgadas
#include <stdio.h>

int main()
{
    int pulg, milla, furlong, yarda, pies, residuo;
    scanf("%d", &pulg);
    if (pulg >= 0, pulg <= 2000000000)
    {
        milla = pulg / 63360;
        residuo = pulg % 63360;
        furlong = residuo / 7920;
        residuo = residuo % 7920;
        yarda = residuo / 36;
        residuo = residuo % 36;
        pies = residuo / 12;
        residuo = residuo % 12;
        printf("%d %d %d %d %d", milla, furlong, yarda, pies, residuo);
    }
}