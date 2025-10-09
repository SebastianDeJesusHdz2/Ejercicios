#include <stdio.h>
#include <string.h>

void procesarCadena(char cadena[]) {
    int i, j, k;
    int longitud = strlen(cadena);
    int parentesisAbierto = 0;

    for (i = 0; i < longitud; i++) {
        if (cadena[i] == '(') {
            parentesisAbierto = 1;
        } else if (cadena[i] == ')') {
            parentesisAbierto = 0;
        } else if (cadena[i] == '*' && parentesisAbierto == 1) {
            cadena[i] = '+';
            for (j = i - 1; j >= 0; j--) {
                if (cadena[j] == '(') {
                    for (k = i + 1; k < longitud; k++) {
                        if (cadena[k] == ')') {
                            memmove(&cadena[j], &cadena[j + 1], k - j - 1);
                            longitud -= (k - j - 1);
                            cadena[longitud] = '\0';
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    char cadena[] = "a(a)*a";
    printf("Cadena original: %s\n", cadena);
    procesarCadena(cadena);
    printf("Cadena procesada: %s\n", cadena);
    return 0;
}
