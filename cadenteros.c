#include <stdio.h>

int main()
{
    int n, m, rest;
    scanf("%d %d",&m, &n);
    printf("Salida \n");
    if (m<n) {
        while (m<=n) {
            rest = m;
            printf("%d ", m);
            m = rest + 1;
        }
    } else {
        while (n<=m) {
            rest = n;
            printf("%d ", n);
            n = rest + 1;
        }
    }
}