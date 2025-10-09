// Estructuras de Datos 1
// Hernandez Hernandez Sebastian de Jesus
// Fecha de entrega: 22 de agosto del 2023
// Se necesita un programa que al introducir los lados de un rectangulo y los lados de otro rectangulo, nos indique si uno cabe dentro del otro, tambien indicar si entra girando 90°.
// Datos de entrada: Altura y base del primer rectangulo y altura y base del segundo rectangulo
// Datos de salida: Si uno de los rectangulos cabe dentro del otro y si se necesita girar o no
//  Para medir si caben: 0 si ninguno cabe dentro del otro, 1 si el primero cabe en el segundo y 2 si el segundo cabe dentro del primero.
//  Para medir si se debe girar: 1 si se debe de girar y cualquier otro caso sera 0
#include <stdio.h>

int main()
{
    int base1, altura1, base2, altura2, rectangulo, girar, comp;
    scanf("%d %d %d %d", &base1, &altura1, &base2, &altura2);
    rectangulo = 0;
    girar = 0;
    if (base1 >= 1 & base1 <= 2000000000 & altura1 >= 1 & altura1 <= 2000000000 & base2 >= 1 & base2 <= 2000000000 & altura2 >= 1 & altura2 <= 2000000000)
    {
        if (base1 <= base2)
        {
            if (altura1 <= altura2)
            {
                rectangulo = 1;
            }
            else
            {
                rectangulo = 0;
                if (altura1<=base2 & altura2>=base1)
                {
                    rectangulo = 1;
                    girar = 1;
                }
            }
        }
        else
        {
            if (altura2 <= altura1)
            {
                rectangulo = 2;
            }
            else
            {
                rectangulo = 0;
                if (altura2 <= base1 & base2 <= altura1)
                {
                    rectangulo = 2;
                    girar = 1;
                }
            }
        }
        printf("%d %d", rectangulo, girar);
    }
}