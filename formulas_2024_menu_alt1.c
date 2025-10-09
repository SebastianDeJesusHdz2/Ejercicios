#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int meses;
  int anos;
} TEdades;

void operaciones();

// Operaciones aritmeticas
void aritmetica();
void suma(float num1, float num2);
void multiplicacion(float num1, float num2);
// Fin de operaciones aritmeticas
void aceleracion();
void trigonometria();
void geometria();
void factorial();
// Operaciones estadisticas
void estadistica();
void promedio(float cont[], int aux);
void moda(float cont[], int n);
// Fin de operaciones estadisticas

//------------Geometria 3D------------
void Geometria_3D();
void Geometria_menu();
void volumen_esfera();
void volumen_cono();
void volumen_cubo();
void volumen_piramide();
//------------Geometria 3D------------

//------------Bisiesto----------------
int desicion_bi(int year);
void bisiesto();
//------------Bisiesto----------------

//----Días para llegar a una fecha----
void fecha_actual(int *dia, int *mes, int *year);
void fecha();
void verificar_fecha(int dia, int mes, int year, int dia_fut, int mes_fut,
                     int year_fut);
//----Días para llegar a una fecha----
void temperatura();
void celciusKelvin(float num1);
void fahrenheitCelcius(float num1);
void kelvinCelcius(float num1);
//
void trianguloPer(float num1, float num2, float num3);
void rectanguloPer(float num1, float num2);
void cuadradoPer(float num1);
void geomatria2D();
//Operacion de edades
void edades();
//Fin de operacion de edades
void velocidad();
void resVel(float dist, float time);

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  printf("-_-Formulas 2024-_-\n\n");
  printf("|-|Integrantes del equipo|-|\n");
  printf("- HERNÁNDEZ HERNÁNDEZ SEBASTIÁN DE JESÚS\n");
  printf("- MAYORGA RÍOS JOSÉ GABRIEL\n");
  printf("- PÉREZ MARTÍNEZ GABRIEL\n");
  printf("- ROMERO TOLENTINO ESTEFANIA\n\n");
  operaciones();
}

void operaciones() {
  int ops;
  while (ops != 13) {
    printf("1. Aritmeticas\n");
    printf("2. Trigonometria\n");
    printf("3. Geometria 2D\n");
    printf("4. Geometria 3D\n");
    printf("5. Estadistica\n");
    printf("6. Factorial\n");
    printf("7. Velocidad\n");
    printf("8. Aceleracion\n");
    printf("9. Bisiesto\n");
    printf("10. Dias para llegar a una fecha\n");
    printf("11. Temperatura\n");
    printf("12. Edades\n");
    printf("13. Salir\n");
    printf("\n");
    printf("Que operacion desea hacer?: ");
    scanf("%d", &ops);
    switch (ops) {
    case 1:
      aritmetica();
      break;
    case 2:
      trigonometria();
      break;
    case 3:
      geomatria2D();
      break;
    case 4:
      Geometria_3D();
      break;
    case 5:
      estadistica();
      break;
    case 6:
      factorial();
      break;
    case 7:
      velocidad();
      break;
    case 8:
      aceleracion();
      break;
    case 9:
      bisiesto();
      break;
    case 10:
      fecha();
      break;
    case 11:
      temperatura();
      break;
    case 12:
      edades();
      break;
    case 13:
      printf("Saliendo....\n");
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
    printf("\n");
  }
}

// Operaciones de aritmetica
void aritmetica() {
  int opc;
  float num1, num2;
  while (opc != 3) {
    printf("\n");
    printf("1. Suma\n");
    printf("2. Multiplicación\n");
    printf("3. Salir\n");
    printf("Que operacion desea hacer?: ");
    scanf("%d", &opc);
    if (opc > 0 && opc < 3) {
      printf("Ingrese el primer numero: ");
      scanf("%f", &num1);
      printf("Ingrese el segundo numero: ");
      scanf("%f", &num2);
      printf("\n");
    }
    switch (opc) {
    case 1:
      suma(num1, num2);
      break;
    case 2:
      multiplicacion(num1, num2);
      break;
    case 3:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  }
}

void suma(float num1, float num2) {
  float rest;
  rest = num1 + num2;
  printf("La suma de %.2f y %.2f es: %.2f\n", num1, num2, rest);
}

void multiplicacion(float num1, float num2) {
  float rest;
  rest = num1 * num2;
  printf("La multiplicacion de %.2f y %.2f es: %.2f\n", num1, num2, rest);
}
// Fin de operaciones de aritmetica

void trigonometria() {
  int op;
  float operando, operador, res;
  printf("Que calculo trigonometrico quieres hacer?\n");
  printf("(1) Seno\n");
  printf("(2) CoSeno\n");
  printf("(3) Tangente\n");
  scanf(" %d", &op);
  if (op == 1) {
    printf("Dime el operando:\n");
    scanf("%f", &operando);
    printf("Dime el operador:\n");
    scanf("%f", &operador);
    res = sin(operador * operando);
    printf("El resultado del Seno es %f\n", res);
  } else if (op == 2) {
    printf("Dime el operando:\n");
    scanf("%f", &operando);
    printf("Dime el operador:\n");
    scanf("%f", &operador);
    res = cos(operador * operando);
    printf("El resultado del Coseno es %f\n", res);
  } else if (op == 3) {
    printf("Dime el operando:\n");
    scanf("%f", &operando);
    printf("Dime el operador:\n");
    scanf("%f", &operador);
    res = tan(operador * operando);
    printf("El resultado de la Tangente es %f\n", res);
  } else {
    printf("Opcion no valida\n");
  }
}

// Operaciones de estadistica
void estadistica() {
  int opc, num;
  float cont[100];
  while (opc != 3) {
    printf("\n");
    printf("1. Promedio\n");
    printf("2. Moda\n");
    printf("3. Salir\n");
    printf("Que operacion desea hacer?: ");
    scanf("%d", &opc);
    if (opc > 0 && opc < 3) {
      printf("Ingrese la cantidad de numeros a ingresar: ");
      scanf("%d", &num);
      printf("\n");
      for (int i = 0; i < num; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%f", &cont[i]);
      }
      printf("\n");
    }
    switch (opc) {
    case 1:
      promedio(cont, num);
      break;
    case 2:
      moda(cont, num);
      break;
    case 3:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  }
}

void promedio(float cont[], int aux) {
  float suma = 0, rest;
  for (int i = 0; i < aux; i++) {
    suma += cont[i];
  }
  rest = suma / aux;
  printf("El promedio es: %.2f\n", rest);
}

void moda(float cont[], int n) {
  int contM = 0;
  float moda = 0;
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (cont[j] == cont[i])
        count++;
    }
    if (count > contM) {
      contM = count;
      moda = cont[i];
    }
  }
  printf("La moda es: %.2f\n", moda);
}
// Fin de operaciones de estadistica

//Operaciones de factorial
void factorial() {
  int cont, n, res = 1;
  printf("Dime el numero que quieres sacar el factorial:\n");
  scanf("%d", &n);
  if (n == 0)
    res = 1;
  else {
    for (cont = n; cont > 0; cont--)
      res = res * cont;
    printf("El resultado de el factorial de %d es %d\n", n, res);
  }
}
//Fin de operaciones de factorial

//Operaciones de aceleracion
void aceleracion() {
  float res, tiempo, velocidad;
  printf("Dime el tiempo:\n");
  scanf("%f", &tiempo);
  printf("Dime la velocidad:\n");
  scanf("%f", &velocidad);
  res = velocidad / tiempo;
  printf("El resultado es %f\n", res);
}
//Fin de operaciones de aceleracion

// Operacion de edades
void edades() {
  TEdades edades[100];
  int num, Smeses = 0, Sanios = 0;
  int restM, restA;
  printf("\n");
  printf("Ingrese la cantidad de personas: ");
  scanf("%d", &num);
  printf("\n");
  for (int i = 0; i < num; i++) {
    printf("Ingrese la edad de la persona %d: \n", i + 1);
    printf("Anos: ");
    scanf("%d", &edades[i].anos);
    printf("Meses: ");
    scanf("%d", &edades[i].meses);
  }
  for (int i = 0; i < num; i++) {
    Smeses += edades[i].meses;
    Sanios += edades[i].anos;
  }
  Sanios += Smeses / 12;
  Smeses = Smeses % 12;
  restM = Smeses / num;
  restA = Sanios / num;
  printf("\n");
  printf("La edad promedio es: %d años y %d meses\n", restA, restM);
}
// Fin de operacion de edades

//-----------------------Mayorga ops---------------
//Operaciones de geometria 3D
void Geometria_menu() {
  printf("\n");
  printf("De que figura quiere calcular el Volumen? \n");
  printf( "(Para escojer el tipo de problema, escriba la letra correspondiente)\n");
  printf("A - Esfera\n");
  printf("B - Cono\n");
  printf("C - Piramide Cuadrada\n");
  printf("D - Cubo\n");
}

void Geometria_3D() {
  char option;
  Geometria_menu();
  printf("Opcion: ");
  scanf(" %c", &option);
  switch (option) {
  case 'A':
    volumen_esfera();
    break;
  case 'B':
    volumen_cono();
    break;
  case 'C':
    volumen_piramide();
    break;
  case 'D':
    volumen_cubo();
    break;
  default:
    break;
  }
}

void volumen_esfera() {
  float A;
  float result2;
  printf("A continuacion introduzca el valor del radio de la Esfera:\n");
  printf("Radio = ");
  scanf("%f", &A);
  result2 = (A * A * A) * 3.1416 * (4.0 / 3.0);
  printf("El Volumen de la Esfera es: ' %f '\n\n", result2);
}

void volumen_cono() {
  float A, B;
  float result2;
  printf("A continuacion introduzca el valor del radio de la base\n y despues "
         "la altura del Cono:\n");
  printf("Radio = ");
  scanf("%f", &A);
  printf("Altura = ");
  scanf("%f", &B);
  result2 = (1.0 / 3.0) * 3.14159 * (A * A) * B;
  printf("El Volumen del Cono es: ' %0.3f '\n\n", result2);
}

void volumen_piramide() {
  float A, B;
  float result2;
  printf("A continuacion introduzca el valor del la longitud de un lado de la "
         "base\n y despues la altura de la piramide:\n");
  printf("Longitud = ");
  scanf("%f", &A);
  printf("Altura = ");
  scanf("%f", &B);
  result2 = (1.0 / 3.0) * (A * A) * B;
  printf("El Volumen del piramide es: ' %0.3f '\n\n", result2);
}

void volumen_cubo() {
  float A, B;
  float result2;
  printf("A continuacion introduzca el valor de la longitud de una de las "
         "aristas del Cubo:\n");
  printf("Arista = ");
  scanf("%f", &A);
  result2 = (A * A * A);
  printf("El Volumen del Cubo es: ' %f '\n\n", result2);
}
//Fin de operaciones de geometria 3D
//-----------------------Mayorga ops---------------
//Operaciones de bisiesto
int desicion_bi(int year) {
  if (year % 400 == 0) {
    return 1;
  } else {
    if ((year % 4 == 0) && (year % 100 != 0)) {
      return 1;
    } else {
      return 0;
    }
  }
}

void bisiesto() {
  int year;
  printf("Por favor introduzca el anio:\n");
  scanf("%d", &year);
  if (desicion_bi(year) == 1) {
    printf("El anio %d es bisiesto\n", year);
  } else {
    printf("El anio %d no es bisiesto\n", year);
  }
}
//Fin de operaciones de bisiesto

//Operaciones de fecha
void fecha_actual(int *dia, int *mes, int *year) {
  int bandera = 0, bandera2 = 0;
  printf("Año: ");
  scanf("%d", year);
  do {
    printf("Mes: ");
    scanf("%d", mes);
    if (*mes > 0 && *mes <= 12) {
      bandera2 = 1;
    } else {
      printf("Mes invalido\n");
    }
  } while (bandera2 != 1);
  do {
    printf("Dia: ");
    scanf("%d", dia);
    if (*mes == 2) {
      if ((*year % 4 == 0 && *dia > 0 && *dia <= 29) ||
          (*year % 4 != 0 && *dia > 0 && *dia <= 28)) {
        bandera = 1;
      } else {
        printf("Dia Invalido\n");
      }
    } else if ((*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 ||
                *mes == 10 || *mes == 12) &&
               *dia > 0 && *dia <= 31) {
      bandera = 1;
    } else if (*dia > 0 && *dia <= 30) {
      bandera = 1;
    } else {
      printf("Dia Invalido\n");
    }
  } while (bandera != 1);
}

void fecha() {
  int dia_actual, mes_actual, year_actual;
  printf("Ingrese la Fecha Actual\n\n");
  fecha_actual(&dia_actual, &mes_actual, &year_actual);
  printf("Fecha actual: %d/%d/%d\n", dia_actual, mes_actual, year_actual);
  int dia_fut, mes_fut, year_fut;
  printf("Ingrese la Fecha Futura\n\n");
  fecha_actual(&dia_fut, &mes_fut, &year_fut);
  printf("Fecha actual: %d/%d/%d\n", dia_fut, mes_fut, year_fut);
  verificar_fecha(dia_actual, mes_actual, year_actual, dia_fut, mes_fut, year_fut);
}

void verificar_fecha(int dia, int mes, int year, int dia_fut, int mes_fut, int year_fut) {
  // Función para verificar la fecha futura.
  if (year_fut < year || (year_fut == year && mes_fut < mes) || (year_fut == year && mes_fut == mes && dia_fut < dia)) {
    printf("La fecha futura debe ser posterior a la fecha actual.\n");
    return;
  }
  // Obtener el número de días entre la fecha actual y la futura.
  int dias_totales = 0;
  while (!(dia == dia_fut && mes == mes_fut && year == year_fut)) {
    int dias_mes_actual = 31; // Por defecto, todos los meses tienen 31 días.
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
      dias_mes_actual =
          30; // Abril, junio, septiembre y noviembre tienen 30 días.
    } else if (mes == 2) {
      // Febrero tiene 28 días, 29 si es año bisiesto.
      dias_mes_actual = desicion_bi(year) ? 29 : 28;
    }
    if (dia == dias_mes_actual) {
      // Si es el último día del mes, avanza al primer día del siguiente mes.
      dia = 1;
      if (mes == 12) {
        // Si es diciembre, avanza al primer día de enero del próximo año.
        mes = 1;
        year++;
      } else {
        // Avanza al primer día del próximo mes.
        mes++;
      }
    } else {
      // Avanza al siguiente día dentro del mismo mes.
      dia++;
    }
    dias_totales++;
  }
  printf("Número de días entre la fecha actual y la futura: %d\n", dias_totales);
}
//Fin de operaciones de fecha
//-----------------------Gabriel ops---------------

//Fany ops
//Operaciones temperatura
void temperatura() {
  int opc;
  float num1;
  do {
    printf("\n");
    printf("1. kelvin a celcius \n");
    printf("2. fahrenheit a celcius \n");
    printf("3. celcius a kelvin\n");
    printf("4. Salir\n");
    printf("Que operacion desea hacer?: ");
    scanf("%d", &opc);
    if(opc > 0 && opc < 4) {
    switch (opc) {
      case 1:
  printf("kelvin a celcius\n");
        printf("Ingrese los grados kelvin: ");
        scanf("%f", &num1);
        printf("\n");
        kelvinCelcius(num1);
        break;
      case 2:
  printf("fahrenheit a celcius\n");
        printf("Ingrese los grados fahrenheit: ");
        scanf("%f", &num1);
        printf("\n");
        fahrenheitCelcius(num1);
        break;
      case 3:
  printf("celcius a kelvin\n");
  printf("Ingrese los grados celcius: ");
        scanf("%f", &num1);
        printf("\n");
        celciusKelvin(num1);
        break;
      case 4:
        printf("Saliendo...\n");
        break;
    }
  }
}while (opc != 4);
}

void kelvinCelcius(float num1) {
  float rest;
  rest = num1+273.15;
  printf("la convercion de %f kelvin a celcius es %f", num1, rest);
}

void fahrenheitCelcius(float num1) {
  float rest;
  rest = (5*(num1-32))/9;
  printf("la convercion de %f fahrenheit a celcius es %f", num1, rest);
}

void celciusKelvin(float num1) {
  float rest;
  rest = num1+273.15;
  printf("la convercion de %f celcius a Kelvin es %f", num1, rest);
}
//Fin de operaciones de temperatura

//Operaciones geometria 2D
void geomatria2D() {
  int opc;
  float num1, num2, num3;
  do {
    printf("\n");
    printf("Perimetro\n");
    printf("1. cuadrado\n");
    printf("2. rectangulo\n");
    printf("3. triandulo\n");
    printf("4. Salir\n");
    printf("Que operacion desea hacer?: ");
    scanf("%d", &opc);
    if(opc > 0 && opc < 4) {
    switch (opc) {
      case 1:
  printf("cuadrado\n");
        printf("Ingrese el valor de un lado: ");
        scanf("%f", &num1);
        printf("\n");
        cuadradoPer(num1);
        break;
      case 2:
  printf("rectangulo\n");
        printf("Ingrese el valor de la base: ");
        scanf("%f", &num1);
        printf("Ingrese el valor de la altura: ");
        scanf("%f", &num2);
        printf("\n");
        rectanguloPer(num1, num2);
        break;
      case 3:
  printf("triangulo\n");
        printf("Ingrese el valor del lado 1: ");
        scanf("%f", &num1);
        printf("Ingrese el valor del lado 2: ");
        scanf("%f", &num2);
  printf("Ingrese el valor del lado 3: ");
        scanf("%f", &num3);
        printf("\n");
        trianguloPer(num1, num2, num3);
        break;
      case 4:
        printf("Saliendo...\n");
        break;
    }
  }
}while (opc != 4);
}

void cuadradoPer(float num1) {
  float rest;
  rest = num1*4;
  printf("el perimetro de un cuadrado cuyo lado tiene un valor de %f es %f", num1, rest);
}

void rectanguloPer(float num1, float num2) {
  float rest;
  rest = num1 + num1 + num2 + num2;
  printf("El perimetro de un rectangulo con %f de base y %f de altura es: %f \n", num1, num2, rest);
}

void trianguloPer(float num1, float num2, float num3) {
  float rest;
  rest = num1 + num2 + num3;
  printf("El perimetro de un triangulo con %f de lado 1, %f de lado 2 y %f de lado 3  es: %f \n", num1, num2, num3, rest);
}
//Fin de operaciones de geometria 2D

//Operacion de velocidad
void velocidad() {
  float dist, time;
  printf("Calculando la velocidad\n");
  printf("ingrese la distancia en metros: ");
  scanf("%f",&dist);
  printf("ingrese el tiempo en segundos: ");
  scanf("%f",&time);
  resVel(dist, time);
}

void resVel(float dist, float time){
float result;
result=dist/time;
printf("un objeto que recorre %f metros en %f seg tiene una velocidad de %.2f\n", dist, time, result);
}
//Fin de velocidad