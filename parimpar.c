#include <stdio.h>

int main()
{
    int n;
    float rest;
    scanf("%d", &n);
    rest = n % 2;
    if (rest==0) {
        printf("par");
    } else {
        printf("impar");
    }

}