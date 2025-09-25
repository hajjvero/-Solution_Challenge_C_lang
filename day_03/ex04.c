#include <stdio.h>
#define N 10

int main(void)
{
    int a[N], i;

    printf("Entrez %d nombre :\n", N);
    for (i = 0; i < N; i++)
    {
        printf("N %d : ", i+1);
        scanf("%d", &a[i]);
    }

    printf("Dns l'order inverse :");
    // int count
    for (i = N; i >= 0; i--)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}