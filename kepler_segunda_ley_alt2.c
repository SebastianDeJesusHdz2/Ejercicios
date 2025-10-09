#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

void Astronomia();

int main(void) {
  Astronomia();
}

//Calcular la segunda ley de kepler para un cuerpo orbitando
void Astronomia() {
  double s_may, p_orb, rest, s_men;
  printf("-| Calculo de la Segunda ley de Kepler |-\n");
  printf("Valor del semieje mayor: \n");
  scanf("%lf", &s_may);
  printf("Periodo orbital: \n");
  scanf("%lf", &p_orb);
  s_men = s_may / 2.0;
  rest = (PI*s_may*s_men) / p_orb;
  printf("La tasa de cambio del area barrida por el radio vector es: %f UA^2/dia\n", rest);
}
/*
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double calculateAreaChange(double a, double b, double T) {
    double dA_dt = (PI * a * b) / T;
    return dA_dt;
}

int main() {
    double a, b, T;

    // Solicitar al usuario que introduzca el semieje mayor y el periodo orbital
    printf("Introduce el semieje mayor en UA: ");
    scanf("%lf", &a);

    printf("Introduce el periodo orbital en dias: ");
    scanf("%lf", &T);

    // Calcular el semieje menor
    b = a / 2.0;

    // Calcular la tasa de cambio del area barrida por el radio vector
    double dA_dt = calculateAreaChange(a, b, T);

    // Imprimir el resultado
    printf("La tasa de cambio del area barrida por el radio vector es: %f UA^2/dia\n", dA_dt);

    return 0;
}
*/