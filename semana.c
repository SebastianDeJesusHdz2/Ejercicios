// Estructuras de Datos 1
// Hernandez Hernandez Sebastian de Jesus
// Fecha de entrega: 22 de agosto del 2023
// Se necesita un programa que dando una fecha determinada imprima que dia de la semana es, cual fue el dia anterior y cual fue el dia de despues.
// Datos de entrada: año, mes, dia
// Datos de salida: dia anterior, dia actual y dia siguiente.
//  0 domingo, 1 lunes, 2 martes, 3 miercoles, 4 jueves, 5 viernes y 6 sabado
#include <stdio.h>

int main()
{
    int ano, mes, dia, semana, guia1, guia2, guia3, guia4, guia5;
    scanf("%d %d %d", &ano, &mes, &dia);
    if (ano >= 0, ano <= 10000, mes >= 1, mes <= 12, dia >= 1, dia <= 31)
    {
        if (mes > 2)
        {
            mes = mes - 2;
        }
        else
        {
            mes = mes + 10;
            ano = ano - 1;
        }
        guia3 = ano / 100;
        guia2 = ano % 100;
        guia1 = ((13 * mes) - 1) / 5;
        guia1 = guia1 + (guia2 / 4) + (guia3 / 4);
        semana = (guia1 + guia2 + dia) + (5 * guia3);
        semana = semana % 7;
        if (semana == 7)
        {
            semana = 0;
        }
        if (semana == 0)
        {
            guia5 = 6;
        }
        else
        {
            guia5 = semana - 1;
        }
        if (semana == 6)
        {
            guia4 = 0;
        }
        else
        {
            guia4 = semana + 1;
        }
        if (semana <= 6, semana >= 0)
        {
            printf("%d %d %d", guia5, semana, guia4);
        }
    }
}